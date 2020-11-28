{- Controlling a hot water heater.
 -
 - This shows how additional types can be used to eg, keep track of units
 - of measurement, while using the Copilot DSL.
 -}

{-# LANGUAGE RebindableSyntax #-}
{-# LANGUAGE EmptyDataDecls #-}

module Examples.WaterHeater.Demo where

import Copilot.Arduino.Uno
import Data.List.NonEmpty (NonEmpty(..))
import qualified Data.List.NonEmpty as L

-- For use as phantom types in TypedBehavior
data PSI
data Celsius

maxSafePSI :: TypedBehavior PSI Float
maxSafePSI = TypedBehavior (constant 45)

maxWaterTemp :: TypedBehavior Celsius Float
maxWaterTemp = TypedBehavior (constant 35)

warmWaterTemp :: TypedBehavior Celsius Float
warmWaterTemp = TypedBehavior (constant 30)

isSafeTemp :: TypedBehavior Celsius Float -> Behavior Bool
isSafeTemp t = liftB2 (<) t maxWaterTemp

isSafePSI :: TypedBehavior PSI Float -> Behavior Bool
isSafePSI p = liftB2 (<) p maxSafePSI

-- Avoid explosions and scalding water.
isSafeToHeat :: TypedBehavior PSI Float -> NonEmpty (TypedBehavior Celsius Float) -> Behavior Bool
isSafeToHeat p cs = foldl (&&) (isSafePSI p) (L.map isSafeTemp cs)

-- Convert a raw value read from an ADC into a temperature in Celsius.
--
-- Assumes the ADC value is 0 at 0F, and 1024 at 200F.
adcToCelsius :: Behavior ADC -> TypedBehavior Celsius Float
adcToCelsius v = TypedBehavior $ v' * (constant 200 / constant 1024)
  where
	v' :: Behavior Float
	v' = unsafeCast v

-- Convert a raw value read from an ADC into a PSI.
--
-- Assumes the ADCI value is 0 at 0 PSI, and 1024 at 150 PSI.
adcToPSI :: Behavior ADC -> TypedBehavior PSI Float
adcToPSI v = TypedBehavior $ v' * (constant 150 / constant 1024)
  where
	v' :: Behavior Float
	v' = unsafeCast v

main :: IO ()
main = arduino $ do
	uppertemp <- adcToCelsius <$> input a1
	lowertemp <- adcToCelsius <$> input a2
	pressure <- adcToPSI <$> input a3
	let upperheatingelement = pin4
	let lowerheatingelement = pin5
	whenB (isSafeToHeat pressure (uppertemp :| [lowertemp])) $ do
		-- Run the upper heating element if the upper water temp is
		-- low, to provide hot water on demand. Run the lower
		-- heating element only when the upper is off.
		let runupper = liftB2 (<) uppertemp warmWaterTemp
		upperheatingelement =: runupper
		lowerheatingelement =: not runupper
	delay =: MilliSeconds 1000
