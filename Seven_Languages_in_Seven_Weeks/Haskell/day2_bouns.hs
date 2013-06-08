module Main where
	-- Prob 1 
	-- Write a function to determine the greatest common denominator of two integers.
	import Data.Ratio
	myGCD a b = if (a `mod` b == 0) then b else (myGCD b (a `mod` b))
	
	-- Prob 2
	-- Create a lazy sequence of prime numbers.
	isPrime n = length (filter (\x -> n `mod` x == 0) [1 .. n]) == 2
	myPrimes = [x | x <- [1..] , isPrime x]
	
	-- Prob 3
	-- Break a long string into individual lines at proper word boundaries.
	
	-- Prob 4
	-- Add line numbers to the previous exercise.	
	
	-- Prob 5
	-- To the above exercise, add functions to left, right, and fully justify the text with spaces (making both margins straight).
	
	