fact(1, 1).
fact(N, What) :-
    N > 1, 
    N1 is N - 1,
    fact(N1, What1),
    What is N * What1.