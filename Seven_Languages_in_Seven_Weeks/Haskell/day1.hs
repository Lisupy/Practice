module Main where
	
	-- Prob 1
	-- How many different ways can you find to write allEven?
	allEven1 [] = []
	allEven1 (h:t) = if even h then h:allEven1 t else allEven1 t
	
	-- Prob 2
	-- Write a function that takes a list and returns the same list in reverse.
	myReverse [] = []
	myReverse (h:t) = (myReverse t) ++ [h]
	
	-- Prob 3
	-- Write a function that builds two-tuples with all possible combinations of two of the colors black, white, blue, yellow, and red. Note that you should include only one of (black, blue) and (blue, black).
	select2 s = [(a,b) | a <- s, b <- s, a < b]
	
	
	-- Prob 4
	--  Write a list comprehension to build a childhood multiplication table. The table would be a list of three-tuples where the first two are integers from 1¨C12 and the third is the product of the first two.
	prodTable = [(lhs, rhs, lhs * rhs) | lhs <- [1..12], rhs <- [1..12]]
	
	
	-- Prob 5 (p72 in CN)
	-- Solve the map-coloring problem (Section 4.2, Map Coloring, on page 101) using Haskell.
	colors = ["red", "green", "blue", "yellow"]
	mapColoring = [(tennessee, mississippi, alabama, georgia, florida) | 
	   tennessee <- colors, mississippi <- colors, alabama <- colors, georgia <- colors, florida <- colors,
	   tennessee /= mississippi, tennessee /= alabama, tennessee /= georgia, mississippi /= alabama,
	   alabama /= georgia, georgia /= florida, florida /= alabama]
	   