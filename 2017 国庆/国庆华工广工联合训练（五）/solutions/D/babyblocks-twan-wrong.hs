{-# LANGUAGE NoMonomorphismRestriction #-}
import Control.Monad
import Control.Applicative
import Data.List
import qualified Data.Map as Map


-- brute force : try all permutations
-- note: if letters can occur more than once we also need a nub

sortNub :: Ord a => [a] -> [a]
sortNub = map head . group . sort

solve_brute_force :: Ord a => [a] -> Integer
solve_brute_force goal = maybe (-1) toInteger . findIndex (== goal) . sortNub . permutations $ goal

solveB = solve_brute_force

-- Smarter : using factorials

factorial n = product [1..n]

multinomial ns = factorial (sum ns) `div` product (map factorial ns)

numPermutations :: Map.Map a Integer -> Integer
numPermutations = multinomial . Map.elems

numSmaller :: Ord a => a -> Map.Map a Integer -> Integer
numSmaller x = sum . Map.elems . fst . Map.split x

-- "dba" -> [2,1,0]
positions :: Ord a => [a] -> [Integer]
positions xs = map (table Map.!) xs
  where table = Map.fromList (zip (nub $ sort xs) [0..])

solve_smart :: Ord a => [a] -> Integer
solve_smart = fst . solve_smart'

solve_smart' :: Ord a => [a] -> (Integer, Map.Map a Integer)
solve_smart' []     = (0,Map.empty)
solve_smart' (x:xs) = let (steps,after) = solve_smart' xs
                      in (steps + numSmaller x after * numPermutations after
                         ,Map.insertWith (+) x 1 after)


-- Which function to use?

solve :: Ord a => [a] -> Integer
solve = solve_smart

solve_old :: Ord a => [a] -> [a] -> Integer
solve_old l g
  | sort l == sort g = solve g
  | otherwise        = (-1) -- alphabet doesn't match word


-- Main function

run = do
    a <- getLine
    print (solve a)

main = flip replicateM run =<< readLn
