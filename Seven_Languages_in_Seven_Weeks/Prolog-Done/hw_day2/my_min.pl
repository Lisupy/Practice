min2(N, N, N).
min2(N1, N2, N1) :-
    N2 > N1.
min2(N1, N2, N2) :-
    N1 > N2.
    
my_min([Head], Head).
my_min([Head | Tail], Min) :-
    my_min(Tail, TailMin),
    min2(Head, TailMin, Min).