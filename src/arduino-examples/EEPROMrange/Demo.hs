{-# LANGUAGE RebindableSyntax #-}

module Examples.EEPROMrange.Demo where

import Copilot.Arduino.Uno
import qualified Copilot.Arduino.Library.EEPROMex as EEPROM
import qualified Copilot.Arduino.Library.Serial as Serial
import System.Environment

-- Change this to use a smaller part of the EEPROM.
sz :: Word16
sz = sizeOfEEPROM

main :: IO ()
main = do
	z <- lookupEnv "ZERO"
	arduino $ case z of
		Just "y" -> mainZero
		_ -> mainReal

-- Zero out the EEPROM, in preparation for mainReal.
mainZero :: Sketch ()
mainZero = do
	EEPROM.maxAllowedWrites sz

	range <- EEPROM.allocRange sz :: Sketch (EEPROM.Range Word8)
	range =: EEPROM.sweepRange 0 (constant (0 :: Word8))
	
	Serial.baud 9600
	Serial.device =: [ Serial.str "EEPROM zeroing started" ]
		@: firstIteration

mainReal :: Sketch ()
mainReal = do
	EEPROM.maxAllowedWrites (sz * 10)
	range <- EEPROM.allocRange sz :: Sketch (EEPROM.Range ADC)
	v <- input' a1 ([10, 20..] :: [ADC])
	range =: EEPROM.sweepRange 0 v @: frequency 3
	oldv <- input' (EEPROM.scanRange range 1) [11..] :: Sketch (Behavior ADC)
	led =: frequency 3
	Serial.device =:
		[ Serial.str "a1:"
		, Serial.show v
		, Serial.str " old EEPROM value:"
		, Serial.show oldv
		, Serial.char '\n'
		]
	delay =: MilliSeconds (constant 10000)
	Serial.baud 9600
