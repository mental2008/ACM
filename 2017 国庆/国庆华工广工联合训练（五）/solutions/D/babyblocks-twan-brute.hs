import Control.Monad
import Control.Applicative
import Data.List
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


-- Which function to use?

solve :: Ord a => [a] -> Integer
solve = solve_brute_force

solve_old :: Ord a => [a] -> [a] -> Integer
solve_old l g
  | sort l == sort g = solve g
  | otherwise        = (-1) -- alphabet doesn't match word


-- Main function

run = do
    a <- getLine
    print (solve a)

main = flip replicateM run =<< readLn
