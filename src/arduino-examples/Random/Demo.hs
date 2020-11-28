{-# LANGUAGE RebindableSyntax #-}

module Examples.Random.Demo where

import Copilot.Arduino.Uno
import Copilot.Arduino.Library.Random

main :: IO ()
main = arduino $ do
	if firstIteration
		then randomSeedPin a0
		else do
			n <- input (random 10) :: Sketch (Behavior Word32)
			led =: (n >= 5)
