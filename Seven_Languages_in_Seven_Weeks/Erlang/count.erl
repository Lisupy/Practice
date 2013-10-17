-module(count).
-export([countTo10/1]).


countTo10(10)   -> io:fwrite("~B~n", [10]);
countTo10(N)    -> io:fwrite("~B, ", [N]), countTo10(N + 1).
