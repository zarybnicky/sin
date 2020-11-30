{-# LANGUAGE DataKinds #-}
{-# LANGUAGE LambdaCase #-}
{-# LANGUAGE NoImplicitPrelude #-}
{-# LANGUAGE RebindableSyntax #-}

module Main where

import Language.Copilot
import Copilot.Compile.C99 (compile)

main :: IO ()
main = reify spec >>= compile "demo-copilot"

spec :: Spec
spec = do
  trigger "play" true
    [ arg (constant notes .!! idx)
    , arg (constant durations .!! idx * 150)
    ]
  trigger "writeOut" true [arg (constant durations .!! idx * 150)]

idx :: Stream Word32
idx = [0] ++ (idx + 1) `mod` constant 51

notes :: Array 51 Word32
notes = array $ toPitch <$>
  [ E, E, E,  E, E, E,  E, G, C, D,  E,  F, F, F, F
  , F, E, E, E, E,  E, D, D, E,  D, G,  E, E, E,  E, E, E
  , E, G, C, D,  E,  F, F, F, F,  F, E, E, E, E,  G, G, F, D,  C
  ]
durations :: Array 51 Word32
durations = array
  [ 2, 2, 4,  2, 2, 4,  2, 2, 3, 1,  8,  2, 2, 3, 1
  , 2, 2, 2, 1, 1,  2, 2, 2, 2,  4, 4,  2, 2, 4,  2, 2, 4
  , 2, 2, 3, 1,  8,  2, 2, 2, 2,  2, 2, 2, 1, 1,  2, 2, 2, 2,  8
  ]

data Note = C | D | E | F | G | A | B

toPitch :: Note -> Word32
toPitch = \case
  C -> 131
  D -> 147
  E -> 165
  F -> 175
  G -> 196
  A -> 220
  B -> 247
