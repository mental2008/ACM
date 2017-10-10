{-# LANGUAGE NoMonomorphismRestriction #-}
--{-# OPTIONS_GHC -Wall #-}
-- 12:20 - 13:02

import Control.Monad
import Control.Monad.State.Strict
import Control.Applicative
import Data.Array
import Data.Ratio
import Data.List
import Data.Ord
import Data.Maybe
import Data.Function
import Data.Tree
import Data.Graph
import qualified Data.Map as Map
import qualified Data.Set as Set

-----------------------------------------------------------------------------
-- Utility
-----------------------------------------------------------------------------

-- | 'Concatenate' a list of @ShowS@s
catShows :: [ShowS] -> ShowS
catShows = foldr (.) id

-- | Show a list by applying a function to each element
showListWith :: (a -> ShowS) -> [a] -> ShowS
showListWith f = catShows . map f

-----------------------------------------------------------------------------
-- Types
-----------------------------------------------------------------------------

type Rod = Int
type Teeth = Int

minTeeth=1
maxTeeth=99

data Gear = Gear { teeth :: Teeth, rod :: Rod }
  deriving (Show)

-----------------------------------------------------------------------------
-- Speeds
-----------------------------------------------------------------------------

-- rotation speed, relative to 1
data Speed = Speed { factors :: Map.Map Teeth Int, forward :: Bool }
   deriving (Eq,Ord)

instance Show Speed where
   showsPrec _ (Speed f d)
       = showString (if d then "+" else "-")
       . catShows [ shows x . showString "[" . shows n . showString "]"  | (x,n) <- Map.toList f, n /= 0 ]

oneSpeed :: Speed
oneSpeed = Speed
    { factors = Map.fromList [(x,0) | x <- [minTeeth..maxTeeth]]
    , forward = True
    }

gearSpeed :: Speed -> Teeth -> Teeth -> Speed
gearSpeed (Speed f d) t1 t2 = Speed
    { factors = Map.insertWith (+) t1 (-1)
              $ Map.insertWith (+) t2 1
              $ f
    , forward = not d
    }

-----------------------------------------------------------------------------
-- Connected components / topological sort
-----------------------------------------------------------------------------

{-
type Graph a = Map.Map a [a]

rodGraph :: [(a,a)] -> Map.Map a Int
rodGraph = undefined

bfs :: Graph a -> Forest a
bfs gr = go Set.empty (Map.keys gr) 0
  where go seen []     = []
        go seen (k:ks)
          | k `Set.member` seen = go ks seen
            Nothing -> go ks =<< goFrom m k
            Just _  -> go ks m
        goFrom m k = case Map.lookup k m of
            Just _  -> return ()
            Nothing -> do
                    i <- get
                    put $! i+1
                    let m' = Map.insert k i m
                    foldM goFrom m' next
               where next = Map.findWithDefault [] k gr

topSort :: Graph a -> Map.Map a Int
topSort gr = fst $ go (Map.keys gr) Map.empty 0
  where go [] m i = m
        go (k:ks) m = case Map.lookup k m of
            Nothing -> go ks =<< goFrom m k
            Just _  -> go ks m
        goFrom m k = case Map.lookup k m of
            Just _  -> return ()
            Nothing -> do
                    i <- get
                    put $! i+1
                    let m' = Map.insert k i m
                    foldM goFrom m' next
               where next = Map.findWithDefault [] k gr
-}
rodGraph :: Int -> [(Gear,Gear)] -> Graph
rodGraph n_r gears = buildG (0,n_r-1) $ concat [[(rod a, rod b),(rod b, rod a)] | (a,b) <- gears]

rodOrder :: Int -> [(Gear,Gear)] -> Map.Map Rod Int
rodOrder n_r gears = toLookup $ topSort $ rodGraph n_r gears
  where toLookup xs = Map.fromList $ zip xs [0..]

-----------------------------------------------------------------------------
-- Solution
-----------------------------------------------------------------------------

-- sort such that for all pairs (i,j): rod i <= rod j
sortMeshings :: Int -> [(Gear,Gear)] -> [(Gear,Gear)]
sortMeshings n_r gears = sortBy (comparing (rodPos . fst)) . map swapIfNeeded $ gears
  where swapIfNeeded (a,b) | rodPos a <= rodPos b = (a,b)
                           | otherwise            = (b,a)
        order = rodOrder n_r gears
        rodPos x = order Map.! rod x

isFreeMoving :: Int -> [(Gear,Gear)] -> Bool
isFreeMoving n_r = isJust . gearSpeeds n_r

gearSpeeds :: Int -> [(Gear,Gear)] -> Maybe (Map.Map Rod Speed)
gearSpeeds n_r = foldM applyGears (Map.empty) . sortMeshings n_r

applyGears :: Map.Map Rod Speed -> (Gear,Gear) -> Maybe (Map.Map Rod Speed)
applyGears speeds (a,b)
 -- | rod b < rod a = error "bork"
  | rod a == rod b = error "intermeshing with a single rod"
  | otherwise = case speedOfRodB of
                  Nothing -> Just $ Map.insert (rod b) speedOfRodB' speeds'
                  Just s
                    | s == speedOfRodB' -> Just speeds' -- matches previous speed
                    | otherwise         -> Nothing      -- conflict
 where
    speedOfRodA  = Map.findWithDefault oneSpeed (rod a) speeds
    speeds'      = Map.insert (rod a) speedOfRodA speeds -- if it wasn't already there
    speedOfRodB  = Map.lookup (rod b) speeds' -- current
    speedOfRodB' = gearSpeed speedOfRodA (teeth a) (teeth b) -- computed

-----------------------------------------------------------------------------
-- Input
-----------------------------------------------------------------------------

readPair :: (Read a, Read b) => IO (a, b)
readPair = do 
        [a,b] <- words <$> getLine
        return $ (read a,read b)

{-
readGear :: IO Gear
readGear = do 
        [[a],b] <- words <$> getLine
        return $ Gear a (read b)
-}
readGear :: IO Gear
readGear = do 
        [a,b] <- words <$> getLine
        return $ Gear (read a) (read b)

-- make a list of meshings
lookupPair :: Array Int a -> (Int,Int) -> (a,a)
lookupPair ar (a,b) = (ar!a,ar!b)

lookupPairs :: [a] -> [(Int,Int)] -> [(a,a)]
lookupPairs xs = map (lookupPair $ listArray (0,length xs-1) xs)


-----------------------------------------------------------------------------
-- Main program
-----------------------------------------------------------------------------

run :: Bool -> IO ()
run verbose = do
        [n_g,n_r,n_i] <- map read . words <$> getLine
        when verbose $ putStrLn ""
        when verbose $ print [n_g,n_r,n_i]
        gears    <- replicateM n_g readGear
        when verbose $ print gears
        meshings <- replicateM n_i readPair
        when verbose $ print meshings
        let theMeshings = lookupPairs gears meshings
        when verbose $ print (gearSpeeds n_r theMeshings)
        putStrLn (if isFreeMoving n_r theMeshings then "ok" else "jammed")

main = flip replicateM_ (run False) =<< readLn
