
module Main where

	import Data.Char (digitToInt)
	import Prelude
	-- Prob 1
	-- Write a sort that takes a list and returns a sorted list.

	myInsert [] e = [e]
	myInsert (h:t) e = if (e < h) then e:h:t else h:(myInsert t e)
	mySort [] = []
	mySort (h:t) = myInsert (mySort t) h
	
	-- Prob 2
	-- Write a sort that takes a list and a function that compares its two arguments and then returns a sorted list.
	myInsertBy less [] e = [e]
	myInsertBy less (h:t) e = if (less h e) then h:(myInsertBy less t e) else e:h:t
	mySortBy less [] = []
	mySortBy less (h:t) = myInsertBy less (mySortBy less t) h
	
	-- Prob 3
	-- Write a Haskell function to convert a string to a number. The string should be in the form of $2,345,678.99 and can possibly have leading zeros.
	myDigitToNum c = (fromInteger (toInteger (digitToInt c))) 
	myConvert ""	  acc = acc
	myConvert ('$':t) acc = myConvert t 0
	myConvert (',':t) acc = myConvert t acc	
	myConvert ('.':t) acc = acc + (myConvertFloat t 0.1)
	myConvert (h:t)   acc = myConvert t (acc * 10 +  (myDigitToNum h))
	myConvertFloat (h:t) base = (myConvertFloat t (base * 0.1)) +   (myDigitToNum h) * base
	myConvertFloat ""    base = 0
	myConvert2 = (`myConvert` 0)
	
	-- Prob 4
	-- Write a function that takes an argument x and returns a lazy sequence that has every third number, starting with x. Then, write a function that includes every fifth number, beginning with y. Combine these functions through composition to return every eighth number, beginning with x + y
	myEvery3 start = start:(myEvery3 (start + 3))
	myEvery5 start = [start, (start + 5) ..]
	myEvery8 x y= zipWith (+) (myEvery3 x) (myEvery5 y)
	
	-- Prob 5
	-- Use a partially applied function to define a function that will return half of a number and another that will append \n to the end of any string.
	myHalf = (/ 2)
	myLine = (++ "\n")