-module(tic_tac_toe).
-export([whowin/1]).

chr(X) -> 
  case X of
    $x -> x;
    $o -> o;
    _  -> cat
  end.

whowin([P0, P1, P2, P3, P4, P5, P6, P7, P8]) ->
  if
    (P0 == P1) and (P1 == P2) -> chr(P0);
    (P3 == P4) and (P4 == P5) -> chr(P3);
    (P6 == P7) and (P7 == P8) -> chr(P6);
    (P0 == P3) and (P3 == P6) -> chr(P0);
    (P1 == P4) and (P4 == P7) -> chr(P1);
    (P2 == P5) and (P5 == P8) -> chr(P2);
    (P0 == P4) and (P4 == P8) -> chr(P0);
    (P2 == P4) and (P4 == P6) -> chr(P2);
    true                      -> cat
  end.

