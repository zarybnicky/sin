{- A simple line-following robot.
 -
 - This is not the most efficient or best way to implement it
 - (it compiles to around 500 lines of C code), but
 - it is a good example of building up a Sketch by combining
 - simpler Sketches.
 -}

{-# LANGUAGE RebindableSyntax #-}

module Examples.Robot.Demo where

import Copilot.Arduino.Uno
import qualified Copilot.Arduino.Library.Serial.XBee as XBee

main :: IO ()
main = arduino $ do
	XBee.configure pin2 pin3 (XBee.Baud 9600)
	emergencystop <- input pin4
	if emergencystop
		then stop
		else do
			ll <- leftLineSensed
			rl <- rightLineSensed
			if ll && rl
				then stop
				else if ll
					then turnLeft
					else if rl
						then turnRight
						else goForward

stop :: Sketch ()
stop = do
	led =: true
	XBee.device =: [XBee.str "stopped\n"]
	rightWheelMotor true (constant 0)
	leftWheelMotor true (constant 0)

goForward :: Sketch ()
goForward = do
	led =: false
	XBee.device =: [XBee.str "forward\n"]
	leftWheelMotor true (constant 255)
	rightWheelMotor true (constant 255)

turnLeft :: Sketch ()
turnLeft = do
	led =: blinking
	XBee.device =: [XBee.str "turn left\n"]
	rightWheelMotor true (constant 128)
	leftWheelMotor false (constant 128)

turnRight :: Sketch ()
turnRight = do
	led =: blinking
	XBee.device =: [XBee.str "turn right\n"]
	rightWheelMotor false (constant 128)
	leftWheelMotor true (constant 128)

leftLineSensed :: Sketch (Behavior Bool)
leftLineSensed = lineSensed a1 "left"

rightLineSensed :: Sketch (Behavior Bool)
rightLineSensed = lineSensed a2 "right"

lineSensed :: IsAnalogInputPin t => Pin t -> [Char] -> Sketch (Stream Bool)
lineSensed pin desc = do
	v <- input pin :: Sketch (Behavior ADC)
	XBee.device =: 
		[ XBee.str (desc <> " line sensor:")
		, XBee.show v
		, XBee.char '\n'
		]
	return (v > 50)

leftWheelMotor :: Behavior Bool -> Behavior Word8 -> Sketch ()
leftWheelMotor = wheelMotor pin5 pin6

rightWheelMotor :: Behavior Bool -> Behavior Word8 -> Sketch ()
rightWheelMotor = wheelMotor pin9 pin10

wheelMotor
	:: (IsPWMPin t1, IsPWMPin t2)
	=> Pin t1 -- ^ pin to drive motor forward
	-> Pin t2 -- ^ pin to drive motor backward
	-> Behavior Bool -- ^ True when driving forward
	-> Behavior Word8 -- ^ How hard to drive the motor.
	-> Sketch ()
wheelMotor forwardpin backwardpin forward power = do
	forwardpin =: pwm (if forward then power else constant 0)
	backwardpin =: pwm (if forward then constant 0 else power)
