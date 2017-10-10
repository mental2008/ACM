{-# LANGUAGE NoMonomorphismRestriction #-}
--{-# OPTIONS_GHC -Wall #-}
-- 12:20 - 13:02

import Control.Monad
import Control.Applicative
import Data.Array
import Data.Ratio
import Data.List
import Data.Ord
import Data.Function
import qualified Data.Map as Map

main = flip replicateM_ run =<< readLn

type Rod = Int
data Gear = Gear { teeth :: Integer, rod :: Rod }
  deriving (Show)

{-
isFreeMoving :: [(Gear,Gear)] -> Bool
isFreeMoving = go Map.empty -- map: rod_id -> rotation speed
  where go _ []         = True
        go m ((a,b):xs) = case (Map.lookup (rod a) m, Map.lookup (rod b) m) of
                (Just aa,Just bb) -> aa / ratio == bb && go m xs -- check for conflicts
                (Just aa,_)       -> go (Map.insert (rod b) (aa / ratio) m) xs
                (_,Just bb)       -> go (Map.insert (rod a) (bb * ratio) m) xs
            where ratio = -teeth a % teeth b
-}

toRodRatio :: (Gear,Gear) -> (Rod,Rod,Rational)
toRodRatio (a,b) = (rod a, rod b, -teeth b % teeth a)


edgesortSymmetric :: Ord a => (d -> d) -> [(a,a,d)] -> [(a,[(a,d)])]
edgesortSymmetric invertData edges = edgesort $ map invertIfNeeded edges
  where invertIfNeeded (a,b,d)
              | a <  b = (a,b,d)
              | a == b = (a,b,d) -- error "selfloop"
              | a >  b = (b,a,invertData d)

-- postcondition:
--   - elements in increasing order of first a
--   - for all (a,[(b,d),..]) pairs, a < b
edgesort :: Ord a => [(a,a,d)] -> [(a,[(a,d)])]
edgesort = map simplify
         . groupBy ((==) `on` fst3)
         . sortBy (comparing fst3)
  where simplify xs@((a,_,_):_) = (a, map (\(_a,b,c) -> (b,c)) xs)

fst3 (a,_,_) = a


isFreeMoving :: [(Gear,Gear)] -> Bool
isFreeMoving = isFreeMoving2 . edgesortSymmetric recip . map toRodRatio

isFreeMoving2 :: [(Rod,[(Rod,Rational)])] -> Bool
isFreeMoving2 = go Map.empty -- map: rod_id -> rotation speed
  where go _ []           = True
        go m ((a,xxs):ys) = go' (Map.insert a aspeed m) xxs
           where aspeed = Map.findWithDefault 1.0 a m  -- 1.0 = start of new connected component
                 go' m []         = go m ys
                 go' m ((b,r):xs) = let bspeed = aspeed*r
                                    in case Map.lookup b m of
                                          Nothing              -> go' (Map.insert b bspeed m) xs
                                          Just bspeed'
                                           | bspeed' == bspeed -> go' m xs
                                           | otherwise         -> False -- conflict





lookupPair :: Array Int a -> (Int,Int) -> (a,a)
lookupPair ar (a,b) = (ar!a,ar!b)

lookupPairs :: [a] -> [(Int,Int)] -> [(a,a)]
lookupPairs xs = map (lookupPair $ listArray (0,length xs-1) xs)


readPair :: (Read a, Read b) => IO (a, b)
readPair = do 
        [a,b] <- words <$> getLine
        return $ (read a,read b)

readGear :: IO Gear
readGear = uncurry Gear <$> readPair

run :: IO ()
run = do
        [n_g,n_r,n_i] <- map read . words <$> getLine
        gears    <- replicateM n_g readGear
        meshings <- replicateM n_i readPair
        let theMeshings = lookupPairs gears meshings
        putStrLn (if isFreeMoving theMeshings then "ok" else "jammed")
