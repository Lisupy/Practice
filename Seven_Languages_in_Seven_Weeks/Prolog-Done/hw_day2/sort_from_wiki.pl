/* sortcsj.pl    ԭʼ������Computer Science  J. Glenn Brookshear   */
/* sortcsj()�еĵڶ���������������õĽY����*/
/* �H��ʾ��������gprologʹ���߄t�ÃȽ�sort���^�� */
/* ��gprolog��֮���g����gplc --min-size sortcsj.pl��*/
/*   ���� sortcsj ������F����Y�� [2,9,18,18,25,33,66,77] */
 
q:- L=[33,18,2,77,18,66,9,25], (sortcsj(L,P), write(P), nl). 
 
sortcsj(L,S) :-  permutation(L,S), ordered(S).	/* L��ԭlist, S������õ�list, �˞�permutation�P�S(built-in) */
 
ordered([]).			/* ��empty listҕ������õ�list */
ordered([_|[]]).			/* ֻ��һԪ��֮listҕ������õ�list */
ordered([A|[B|T]]) :- A =< B, ordered([B|T]).	/* ��rule�s�����^���������ָǰ�Ԫ��С춻�����һ�Ԫ�� */
 
:- initialization(q).		/* ����q̎goals */