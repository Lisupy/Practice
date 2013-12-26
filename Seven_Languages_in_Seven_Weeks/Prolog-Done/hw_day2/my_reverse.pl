my_reverse([], []).
my_reverse([Head|Tail], What) :-
    my_reverse(Tail, RTail),
    append(RTail, [Head], What).