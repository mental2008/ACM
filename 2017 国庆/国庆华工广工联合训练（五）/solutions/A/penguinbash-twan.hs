{-# LANGUAGE NoMonomorphismRestriction #-}
{-# OPTIONS_GHC -fno-warn-type-defaults #-}

import Data.List
import Data.Ord
import Control.Monad

-----------------------------------------------------------------------------
-- Specification
-----------------------------------------------------------------------------

g = 9.81 -- m/s^2
m = 3 -- kg
dv_mine = 10 -- m/s
dx_mine = 2 -- m
dvx_mine = 4 -- m/s
score_spike = -100 -- m
friction = 5 -- (m/s)/m

warningEpsilon = 1e-5

start_x = (0,1) -- m
start_v = 25  -- m/s

-- solve: dv_mine*t + -1/2g*t^2 == 0
--        dv_mine == 1/2g*t
--        2*dv_mine/g == t
t_mine = 2*dv_mine/g


{-# SPECIALIZE withinEps :: Double -> Double -> Bool #-}
withinEps :: (Ord a, Floating a) => a -> a -> Bool
withinEps a b = a-warningEpsilon < b && b < a+warningEpsilon

-----------------------------------------------------------------------------
-- Input
-----------------------------------------------------------------------------

data Obstacle a = Mine { position :: a } | Spike { position :: a }
    deriving (Eq,Ord,Show)

instance Read a => Read (Obstacle a) where
    readsPrec _ xs = [(op (read a),"")]
       where [a,b] = words xs
             op | b == "spike" = Spike
                | b == "mine"  = Mine
                | otherwise    = error $ "Parse error: " ++ b

readInput :: Read a => IO [Obstacle a]
readInput = flip replicateM readLn =<< readLn

-----------------------------------------------------------------------------
-- Solution
-----------------------------------------------------------------------------

type Vector a = (a,a)
data FlatState a = FS { x,v :: !a }
   deriving (Show)

{-# SPECIALIZE landingPoint :: Vector Double -> Vector Double -> Double #-}
landingPoint :: (Ord a, Floating a) => Vector a -> Vector a -> a
landingPoint x0@(x,y) v0@(vx,vy)
   -- y + vy*t -1/2g*t^2 == 0
   | withinEps (y + vy*t -1/2*g*t^2) 0
   = x + vx * t
   | otherwise = error $ "abc formule fail: land at " ++ show (y + vy*t -1/2*g*t^2) ++ " after " ++ show t ++ "   (a,b,c)=" ++ show (a,b,c)
  where a = -1/2 * g
        b = vy
        c = y
        t = (-b - sqrt (b^2 - 4*a*c)) / (2 * a) -- note: minus sign because a < 0

cosSinV :: Floating a => a -> a -> Vector a
cosSinV v deg = (v * cos rad, v * sin rad)
  where rad = deg * pi / 180

firstLandingPoint :: (Ord a, Floating a) => a -> FlatState a
firstLandingPoint deg = FS (landingPoint x0 v0) vx
  where x0 = start_x
        v0@(vx,_) = cosSinV start_v deg

simulateFriction :: Floating a => FlatState a -> a
simulateFriction (FS x v) = x + v / friction

simulateFrictionUpTo :: (Ord a, Floating a) => a -> FlatState a -> Either (FlatState a) a
simulateFrictionUpTo bound (FS x v)
    | withinEps end bound = error "too close before obstacle"
    | end < bound = Right end
    | otherwise   = Left (FS bound (v - (bound-x)*friction))
  where end = x + v / friction

{-
simulate1 :: (Ord a, Floating a) => (Obstacle a) -> FlatState a -> FlatState a
simulate1 obs fs@(FS x _)
    | withinEps (position obs) x = error "too close after obstacle"
    | position obs < x           = fs
    | otherwise                  = case simulateFrictionUpTo (position obs) fs of
                                      Right a -> a
                                      Left (FS x' v') -> case obs of
                                                     Mine  _ -> FS (x' + t_mine * v') v'
                                                     Spike _ -> FS score_spike 0 -- die
-}

{-# SPECIALIZE simulate1 :: (Obstacle Double) -> FlatState Double -> FlatState Double #-}
simulate1 :: (Ord a, Floating a) => (Obstacle a) -> FlatState a -> FlatState a
simulate1 obs fs@(FS x v)
    | withinEps (position obs) x   = error $ "too close after obstacle   " ++ show (position obs, x)
    | withinEps (position obs) end = error $ "too close before obstacle  " ++ show (position obs, x)
    | position obs < x             = fs -- obstacle before x
    | position obs > end           = FS end 0 -- stop sliding before obstacle
    | otherwise                    = case obs of
                                        Spike _ -> FS score_spike 0 -- die
                                        Mine  _ -> minehop (FS x' v')
                                               where x' = position obs; v' = v - (x'-x)*friction
  where end = x + v / friction

minehop :: (Ord a, Floating a) => FlatState a -> FlatState a
--minehop (FS x v) = FS (x + t_mine * v) v
minehop (FS x v) = FS (x + dx_mine) (v + dvx_mine)

ssimulate :: (Ord a, Floating a) => [Obstacle a] -> FlatState a -> [FlatState a]
ssimulate obss f = scanl (flip simulate1) f obss

{-# SPECIALIZE simulate :: [Obstacle Double] -> FlatState Double -> Double #-}
simulate :: (Ord a, Floating a) => [Obstacle a] -> FlatState a -> a
simulate obss f = simulateFriction $ foldl' (flip simulate1) f obss
{-
simulate []         fs          = simulateFriction fs
simulate (obs:obss) fs@(FS x _)
    | withinEps (position obs) x = error "too close after obstacle"
    | position obs < x          = simulate obss fs
    | otherwise                 = case simulateFrictionUpTo (position obs) fs of
                                      Right a -> a
                                      Left (FS x' v') -> case obs of
                                                     Mine  _ -> simulate obss (FS (x' + t_mine * v') v')
                                                     Spike _ -> score_spike -- die
-}

simulate' :: (Ord a, Floating a) => [Obstacle a] -> a -> a
simulate' obs deg = simulate obs $ firstLandingPoint deg

ssimulate' :: (Ord a, Floating a) => [Obstacle a] -> a -> [FlatState a]
ssimulate' obs deg = ssimulate obs $ firstLandingPoint deg


{-# SPECIALIZE solve :: [Obstacle Double] -> (Integer,Integer) #-}
solve :: (Ord a, Floating a, RealFrac a) => [Obstacle a] -> (Integer,Integer)
solve obs = (\(a,b)->(a,-b))
          $ maximum [ (roundScore score, -deg) | deg <- [-90..90]
                    , let score = simulate' obs' (fromInteger deg)
                    ]
  where obs' = sortBy (comparing position) obs
        safeRound x  | round (x - warningEpsilon) /= roundScore (x + warningEpsilon)
                                 = error $ "score too close to an integer: " ++ show x
                     | otherwise = round x
        roundScore x | x < 0     = round x
                     | otherwise = round (x * 100)

-----------------------------------------------------------------------------
-- Keep a log
-----------------------------------------------------------------------------

data EventLog a
   = FirstLanding (FlatState a) (EventLog a)
   | Stop
   | Die
   | Glide     (FlatState a) (EventLog a)
   | FlyOver   (Obstacle a)  (EventLog a)
   | MineHopTo (FlatState a) (EventLog a)

instance Show a => Show (EventLog a) where
   showsPrec _ (FirstLanding a e) = showString "land at    " . shows a . showString "\n" . shows e
   showsPrec _ Stop               = showString "stop by friction"
   showsPrec _ Die                = showString "die on a spike"
   showsPrec _ (Glide        a e) = showString "glide to   " . shows a . showString "\n" . shows e
   showsPrec _ (FlyOver      o e) = showString "fly over   " . shows o . showString "\n" . shows e
   showsPrec _ (MineHopTo    a e) = showString "minehop to " . shows a . showString "\n" . shows e

simulate2 :: (Ord a, Floating a) => [Obstacle a] -> a -> EventLog a
simulate2 o deg = FirstLanding land (go o land)
 where
    land = firstLandingPoint deg
    go []            (FS x v) = Glide (FS end 0) Stop where end = x + v / friction
    go (obs:obss) fs@(FS x v)
         | withinEps (position obs) x   = error "too close after obstacle"
         | withinEps (position obs) end = error "too close before obstacle"
         | position obs < x             = FlyOver obs $ go obss fs -- obstacle before x
         | position obs > end           = Glide (FS end 0) Stop -- stop sliding before obstacle
         | otherwise                    = Glide fs' $ case obs of
                                             Spike _ -> Die
                                             Mine  _ -> let fs'' = minehop fs'
                                                        in MineHopTo fs'' (go obss fs'')
       where end = x + v / friction
             x' = position obs
             v' = v - (x'-x)*friction
             fs' = FS x' v'

-----------------------------------------------------------------------------
-- Main
-----------------------------------------------------------------------------

printResult (a,b) = putStrLn $ show a ++ " " ++ show b
run  = printResult . solve =<< readInput
main = flip replicateM_ run =<< readLn

-----------------------------------------------------------------------------
-- Testing
-----------------------------------------------------------------------------

ex1 = [Spike 64.7]
ex2 = [Mine 63.9, Spike 64.7]

ex3 = map read
     ["28.218620511529323 mine","78.24139336818904 mine","128.25397254493026 mine","178.25635804175297 mine","228.24854985865719 mine","278.2305479956429 mine","328.2023524527104 mine","378.16396322985963 mine","428.1153803270907 mine","478.05660374440356 mine"]

ex4 = map read
     ["0.04465061 mine","1.73148527 mine","3.31638309 mine","4.79934417 mine","6.18036840 mine","7.45945587 mine","8.63660655 mine","9.71182040 mine","10.68509748 mine","11.55643774 mine","12.32584121 mine","12.99330788 mine","13.55883771 mine","14.02243075 mine","14.38408700 mine","14.64380641 mine"]
