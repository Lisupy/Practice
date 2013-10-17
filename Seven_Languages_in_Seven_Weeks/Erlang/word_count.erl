-module(word_count).
-export([count/1]).


count([])           -> 1;
count([$   | Tail]) -> count(Tail) + 1;
count([_   | Tail]) -> count(Tail).
