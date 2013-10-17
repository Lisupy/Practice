-module('echo').
-export([echo/1]).

echo(success)   -> io:fwrite("Success~n");
echo([error, Message])  -> io:fwrite("error: ~s~n", [Message]).
