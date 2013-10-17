-module(roulette).
-export([loop/0]).

loop() ->
  receive
    3 -> io:format("bang.~n"), exit({roulette, die, erlang:time()});
    _ -> io:format("click~n"), loop()
  end.
