{-# LANGUAGE RebindableSyntax #-}

module Examples.EEPROM.Demo where

import Copilot.Arduino.Uno
import qualified Copilot.Arduino.Library.EEPROMex as EEPROM
import qualified Copilot.Arduino.Library.Serial as Serial
import System.Environment
import qualified Prelude

main :: IO ()
main = do
	z <- lookupEnv "ZERO"
	arduino $ case z of
		Just "y" -> mainZero
		_ -> mainReal

-- Zero out the EEPROM, in preparation for mainReal.
mainZero :: Sketch ()
mainZero = do
	EEPROM.maxAllowedWrites 10

	(_, eepromloc) <- EEPROM.alloc' (20 :: ADC)
	eepromloc =: constant (0 :: ADC) @: firstIteration

	(_, uptimeloc) <- EEPROM.alloc' (0 :: Word32)
	uptimeloc =: constant (0 :: Word32) @: firstIteration

	Serial.baud 9600
	Serial.device =: [ Serial.str "EEPROM zeroed" ] @: firstIteration

mainReal :: Sketch ()
mainReal = do
	-- Store the maximum value read from a1 in the EEPROM.
	-- There are only 1024 possible values, so this can only possibly
	-- write new values that many times, so no delay is needed in this
	-- program. Just in case though, limit the total number of writes:
	EEPROM.maxAllowedWrites 2048
	(bootval, eepromloc) <- EEPROM.alloc' (20 :: ADC)
	currval <- input' a1 [10, 11, 25, 100, 99, 0, 0, 0, 0, 0]
	let maxval = if currval > bootval then currval else bootval
	-- Note that using maxBound here means it will never write
	-- on the first iteration, even if a1 is then larger than bootval.
	-- Any better way to write this that avoids the problem?
	let newmax = currval > ([maxBound] ++ maxval)
	eepromloc =: currval @: newmax

	-- Store the maximum MilliSeconds this program has been left running
	-- in the EEPROM too.
	(bootuptime, uptimeloc) <- EEPROM.alloc' (0 :: Word32)
	uptime <- input' millis (dummyclockinput [1, 1, 1, 2, 2, 2, 3, 3, 3])
	-- micros overflows after ~70 minutes; detect that and use it to
	-- trigger a periodic write of the uptime to EEPROM.
	hourlyish <- microsOverFlowed
	let maxuptime = if uptime > bootuptime then uptime else bootuptime
	uptimeloc =: maxuptime @: hourlyish
	
	Serial.baud 9600
	Serial.device =:
		[ Serial.str "max a1 seen: "
		-- This is not quite right, because maxval resets to
		-- bootval when this is displayed at hourlyish.
		-- Interpreting shows the problem:
		--    --              (3)             (20,3)
		-- How to fix this?
		, Serial.show maxval
		, Serial.str " max uptime: "
		, Serial.show maxuptime
		, Serial.char '\n'
		]
		@: (firstIteration || newmax || hourlyish)

microsOverFlowed :: Sketch (Behavior Bool)
microsOverFlowed = do
	t <- input' micros (dummyclockinput [1, 2, 3])
	let oldt = [0] ++ t
	return (t < oldt)

dummyclockinput :: [Word32] -> [Word32]
dummyclockinput = Prelude.cycle
