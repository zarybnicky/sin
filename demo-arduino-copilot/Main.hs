{-# OPTIONS_GHC -fno-warn-tabs #-}
{-# LANGUAGE DataKinds #-}
{-# LANGUAGE NoImplicitPrelude #-}
{-# LANGUAGE RebindableSyntax #-}

module Main where

import Copilot.Arduino.Uno
import qualified Copilot.Arduino.Library.Serial as Serial

main :: IO ()
main = arduino $ do
  Serial.baud 9600
  delay =: MilliSeconds (constant 1000)

  let redMain, greenMain, redAux, greenAux :: Array 6 Bool
      redMain   = array [False, True, True, True, True, True]
      greenMain = array [True, True, False, False, False, True]
      redAux    = array [True, True, True, False, True, True]
      greenAux  = array [False, False, True, True, True, False]

  let t :: Stream Word8
      t = [0] ++ (t + 1) `mod` constant 15

  let s = if t >= 0 && t < 3	then 0 else
          if t == 3		then 1 else
          if t == 4		then 2 else
          if t >= 5 && t < 13 	then 3 else
          if t == 13 		then 4 else 5

  pin3 =: constant redMain .!! s
  pin2 =: constant greenMain .!! s
  pin5 =: constant redAux .!! s
  pin4 =: constant greenAux .!! s

  Serial.device =:
    [ Serial.str "sec:"
    , Serial.show t
    , Serial.char '\n'
    ]
