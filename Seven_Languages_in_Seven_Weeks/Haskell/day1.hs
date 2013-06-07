module Main where
	allEven1 [] = []
	allEven1 (h:t) = if even h then h:allEven1 t else allEven1 t
	
	myReverse [] = []
	myReverse (h:t) = (myReverse t) ++ [h]
	
	select2 s = [(a,b) | a <- s, b <- s, a < b]
	
	prodTable = [(lhs, rhs, lhs * rhs) | lhs <- [1..12], rhs <- [1..12]]
	
	
-- map coloring problem on p72
	colors = ["red", "green", "blue", "yellow"]
	mapColoring = [(tennessee, mississippi, alabama, georgia, florida) | 
	   tennessee <- colors, mississippi <- colors, alabama <- colors, georgia <- colors, florida <- colors,
	   tennessee /= mississippi, tennessee /= alabama, tennessee /= georgia, mississippi /= alabama,
	   alabama /= georgia, georgia /= florida, florida /= alabama]
	   