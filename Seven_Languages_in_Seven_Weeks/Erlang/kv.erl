-module(kv).
-export([find/2]).

find([],               _)   -> null;
find([{Key, Val} | _], Key) -> Val;
find([_ | Tail],       Key) -> find(Tail, Key).
