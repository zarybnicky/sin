{-# LANGUAGE RebindableSyntax #-}
{-# LANGUAGE DataKinds #-}
{-# LANGUAGE FlexibleContexts #-}

module Examples.SerialPort.Demo where

import Copilot.Arduino.Uno
import qualified Copilot.Arduino.Library.Serial as Serial
import qualified Copilot.Arduino.Library.Serial.XBee as XBee
import Control.Monad

-- Should it use the onboard serial port?
useSerial :: Bool
useSerial = True

-- Should it use the XBee wireless serial port?
-- (it can use more than one serial port at the same time.)
useXBee :: Bool
useXBee = True

userIsTyping :: Behavior Int8 -> Behavior Bool
userIsTyping userinput = userinput /= constant Serial.noInput

getSerial :: Input o Int8 => Bool -> o -> Sketch (Behavior Int8)
getSerial True i = input' i (repeat Serial.noInput)
getSerial False _ = return (constant Serial.noInput)

main :: IO ()
main = arduino $ do
	when useSerial $ Serial.baud 9600
	when useXBee $ XBee.configure pin2 pin3 (XBee.Baud 9600)

	-- Measure the an analog input, and display it to the
	-- serial port. This is a handy demo because with nothing connected
	-- to a0, just moving your hand close to the arduino will probably
	-- cause some noise to be read.
	n <- input' a0 [1, 50, 11, 99, 120] :: Sketch (Behavior ADC)
	c <- input' millis [20, 60, 80, 100] :: Sketch (Behavior Word32)
	let msg = 
		[ Serial.str "analog input:"
		, Serial.showFormatted n Serial.HEX
		, Serial.str " millis:"
		, Serial.show c
		, Serial.char '\n'
		]
	when useSerial $ Serial.device =: msg
	when useXBee $ XBee.device =: msg

	-- Light the led whenever the user types on the serial port.
	userinput <- getSerial useSerial Serial.device
	userinputxbee <- getSerial useXBee XBee.device
	led =: userIsTyping userinput || userIsTyping userinputxbee

	delay =: MilliSeconds (constant 100)
