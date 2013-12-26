valid(List) :-
    fd_all_different(List).

allValid([]).
allValid([Head | Tail]) :-
    valid(Head),
    allValid(Tail).
    
sudoku9(Puzzle, Solution) :-
    Solution = Puzzle,
    Puzzle =[V11, V12, V13, V14, V15, V16, V17, V18, V19,
             V21, V22, V23, V24, V25, V26, V27, V28, V29,
             V31, V32, V33, V34, V35, V36, V37, V38, V39,
             V41, V42, V43, V44, V45, V46, V47, V48, V49,
             V51, V52, V53, V54, V55, V56, V57, V58, V59,
             V61, V62, V63, V64, V65, V66, V67, V68, V69,
             V71, V72, V73, V74, V75, V76, V77, V78, V79,
             V81, V82, V83, V84, V85, V86, V87, V88, V89,
             V91, V92, V93, V94, V95, V96, V97, V98, V99],
             
    fd_domain(Solution, 1, 9),
    Row1 = [V11, V12, V13, V14, V15, V16, V17, V18, V19],
    Row2 = [V21, V22, V23, V24, V25, V26, V27, V28, V29],
    Row3 = [V31, V32, V33, V34, V35, V36, V37, V38, V39],
    Row4 = [V41, V42, V43, V44, V45, V46, V47, V48, V49],
    Row5 = [V51, V52, V53, V54, V55, V56, V57, V58, V59],
    Row6 = [V61, V62, V63, V64, V65, V66, V67, V68, V69],
    Row7 = [V71, V72, V73, V74, V75, V76, V77, V78, V79],
    Row8 = [V81, V82, V83, V84, V85, V86, V87, V88, V89],
    Row9 = [V91, V92, V93, V94, V95, V96, V97, V98, V99],
    
    Col1 = [V11, V21, V31, V41, V51, V61, V71, V81, V91],
    Col2 = [V12, V22, V32, V42, V52, V62, V72, V82, V92],
    Col3 = [V13, V23, V33, V43, V53, V63, V73, V83, V93],
    Col4 = [V14, V24, V34, V44, V54, V64, V74, V84, V94],
    Col5 = [V15, V25, V35, V45, V55, V65, V75, V85, V95],
    Col6 = [V16, V26, V36, V46, V56, V66, V76, V86, V96],
    Col7 = [V17, V27, V37, V47, V57, V67, V77, V87, V97],
    Col8 = [V18, V28, V38, V48, V58, V68, V78, V88, V98],
    Col9 = [V19, V29, V39, V49, V59, V69, V79, V89, V99],
    
    Square1 = [V11, V12, V13, V21, V22, V23, V31, V32, V33],
    Square2 = [V14, V15, V16, V24, V25, V26, V34, V35, V36],
    Square3 = [V17, V18, V19, V27, V28, V29, V37, V38, V39],
    Square4 = [V41, V42, V43, V51, V52, V53, V61, V62, V63],
    Square5 = [V44, V45, V46, V54, V55, V56, V64, V65, V66],
    Square6 = [V47, V48, V49, V57, V58, V59, V67, V68, V69],
    Square7 = [V71, V72, V73, V81, V82, V83, V91, V92, V93],
    Square8 = [V74, V75, V76, V84, V85, V86, V94, V95, V96],
    Square9 = [V77, V78, V79, V87, V88, V89, V97, V98, V99],
    All_Row = [Row1, Row2, Row3, Row4, Row5, Row6, Row7, Row8, Row9],
    All_Col = [Col1, Col2, Col3, Col4, Col5, Col6, Col7, Col8, Col9],
    All_Square = [Square1, Square2, Square3, Square4, Square5, Square6, Square7, Square8, Square9],
    allValid(All_Row), allValid(All_Col), allValid(All_Square),
    fd_labeling(Solution),
    sudoku_print(All_Row).

sudoku_print([]).
sudoku_print([Head|Tail]) :-
    write(Head),
    write('\n'),
    sudoku_print(Tail).
/*
consult('E:/darrenhp/Notes/Seven_Languages_in_Seven_Weeks/Prolog/hw_day3/sudoku9.pl').
*/
main :- 
  sudoku9([
    _,_,5,3,_,_,_,_,_,
    8,_,_,_,_,_,_,2,_,
    _,7,_,_,1,_,5,_,_,
    4,_,_,_,_,5,3,_,_,
    _,1,_,_,7,_,_,_,6,
    _,_,3,2,_,_,_,8,_,
    _,6,_,5,_,_,_,_,9,
    _,_,4,_,_,_,_,3,_,
    _,_,_,_,_,9,7,_,_
  ],Solution).