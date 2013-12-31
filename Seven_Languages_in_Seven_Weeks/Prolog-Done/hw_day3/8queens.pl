
diag([], _).
diag([HEAD|TAIL], P) :-
    HEAD \= P,
    P2 is P + 1,
    diag(TAIL, P2).

all_diag([]).
all_diag([HEAD|TAIL]) :-
    P is HEAD + 1,
    diag(TAIL, P),
    all_diag(TAIL).
 
diag2([], _).
diag2([HEAD|TAIL], P) :-
    HEAD \= P,
    P2 is P - 1,
    diag2(TAIL, P2).

all_diag2([]).
all_diag2([HEAD|TAIL]) :-
    P is HEAD - 1,
    diag2(TAIL, P),
    all_diag2(TAIL).

queens(QS) :-
    permutation([1, 2, 3, 4, 5, 6, 7, 8], QS),
    all_diag(QS),
    all_diag2(QS).
    