my_partition([], _, [], []).
my_partition([Head|Tail], P, [Head|Tail1], Tail2) :-
    Head < P,
    my_partition(Tail, P, Tail1, Tail2).
my_partition([Head|Tail], P, Tail1, [Head|Tail2]) :-
    Head >= P,
    my_partition(Tail, P, Tail1, Tail2).    

    
my_sort([], []).
my_sort([Head], [Head]).
my_sort([Head|Tail], What) :-
    my_partition(Tail, Head, P1, P2),
    my_sort(P1, SP1),
    my_sort(P2, SP2),
    append(SP1, [Head], TMP),
    append(TMP, SP2, What).