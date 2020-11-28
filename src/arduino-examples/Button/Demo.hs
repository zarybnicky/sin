{-# LANGUAGE RebindableSyntax #-}

module Examples.Button.Demo where

import Copilot.Arduino.Uno

longer_and_longer :: Stream Word32
longer_and_longer = counter true $ counter true false `mod` 64 == 0

counter :: Stream Bool -> Stream Bool -> Stream Word32
counter inc reset = cnt
   where
	cnt = if reset
		then 0
		else if inc
			then z + 1
			else z
	z = [0] ++ cnt

main :: IO ()
main = arduino $ do
	buttonpressed <- input' pin12 [False, False, False, True, True]
	led =: buttonpressed || blinking
	delay =: MilliSeconds (longer_and_longer * 2)
