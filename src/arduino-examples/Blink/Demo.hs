{-# LANGUAGE RebindableSyntax #-}

module Examples.Blink.Demo where

import Copilot.Arduino

main :: IO ()
main = arduino $ do
	led =: blinking
	delay =: MilliSeconds (constant 100)
