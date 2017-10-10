{-# LANGUAGE NoMonomorphismRestriction #-}
import Control.Monad
import Control.Applicative
import Data.List
import Data.Array
import qualified Data.Map as Map


-- From Data.List
permutations'            :: [a] -> [[a]]
permutations' xs0        =  xs0 : perms xs0 []
  where
    perms []     _  = []
    perms (t:ts) is = foldr interleave (perms ts (t:is)) (permutations' is)
      where interleave    xs     r = let (_,zs) = interleave' id xs r in zs
            interleave' _ []     r = (ts, r)
            interleave' f (y:ys) r = let (us,zs) = interleave' (f . (y:)) ys r
                                     in  (y:us, f (t:y:us) : zs)

-- brute force : try all permutations
-- note: if letters can occur more than once we also need a nub

sortNub :: Ord a => [a] -> [a]
sortNub = map head . group . sort

solve_brute_force :: Ord a => [a] -> Integer
solve_brute_force goal = maybe (-1) toInteger . findIndex (== goal) . sortNub . permutations' $ goal

solveB = solve_brute_force

-- Smarter : using factorials

facts :: Array Integer Integer
facts = listArray (0,50) [ product [1..n] | n <- [0..50] ]
factorial n = facts ! n

multinomial ns = factorial (sum ns) `div` product (map factorial ns)

numPermutations :: Map.Map a Integer -> Integer
numPermutations = multinomial . Map.elems

numSmaller :: Ord a => a -> Map.Map a Integer -> Integer
numSmaller x = sum . Map.elems . fst . Map.split x

smaller :: Ord a => a -> Map.Map a Integer -> [(a,Integer)]
smaller x = Map.toList . fst . Map.split x

-- "dba" -> [2,1,0]
positions :: Ord a => [a] -> [Integer]
positions xs = map (table Map.!) xs
  where table = Map.fromList (zip (nub $ sort xs) [0..])

solve_smart :: Ord a => [a] -> Integer
solve_smart = fst . solve_smart'

solve_smart' :: Ord a => [a] -> (Integer, Map.Map a Integer)
solve_smart' []     = (0,Map.empty)
solve_smart' (x:xs) = let (steps,after) = solve_smart' xs
                      in (steps + sum (smallerPerms x after)
                         ,Map.insertWith (+) x 1 after)

smallerPerms x after
    = [ numPermutations afterWithX
      | (w,_) <- smaller x after
      , let afterWithX = Map.insertWith (+) w (-1)
                       $ Map.insertWith (+) x 1
                       $ after
      ]

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
    let ans = solve a
    when (length a > 20) $ error $ "Input too large " ++ show a
    when (ans >= 2^63) $ error $ "Answer too large " ++ show ans ++ " for " ++ show a
    print ans

main = flip replicateM run =<< readLn
