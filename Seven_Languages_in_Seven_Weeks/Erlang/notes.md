# Day1 #


* Erlang�Ĺٷ���վ   
   * http://www.erlang.org/
* Erlang������Ĺٷ��ĵ�
   * http://www.erlang.org/doc.html
* Erlang OTP��Ĺٷ��ĵ�
    * http://www.erlang.org/doc/

* дһ���������õݹ鷵���ַ����еĵ�����
```erlang
-module(word_count).
-export([count/1]).
count([])           -> 1;
count([$   | Tail]) -> count(Tail) + 1;                                                                                      
count([_   | Tail]) -> count(Tail).
```

* дһ���������õݹ鼼����10�ĺ���
```erlang
-module(count).
-export([countTo10/1]).
countTo10(10)   -> io:fwrite("~B~n", [10]);
countTo10(N)    -> io:fwrite("~B, ", [N]), countTo10(N + 1). 
```

* дһ���������ڸ�������Ϊ`{error, Message}`��`Success`�������£�����ƥ���ӡ��`"Success"`�� `"error: message"`
```erlang
-module('echo').
-export([echo/1]).
echo(success)   -> io:fwrite("Success~n");
echo([error, Message])  -> io:fwrite("error: ~s~n", [Message]). 
```


# Day2 #
* ���ǰ�����-ֵ���б���`[{erlang, "a functional language"}, {ruby, "an 00 language"}]`��дһ�������������б�ͼ�Ϊ���������ظü���Ӧ��ֵ��

```erlang
-module(kv).
-export([find/2]).
find([],               _)   -> null;
find([{Key, Val} | _], Key) -> Val;
find([_ | Tail],       Key) -> find(Tail, Key). 
```

* ��������`[{item quantity price}, ...}]`�Ĺ����б�дһ���б��������������`[{item total_price}, ...]`����Ʒ�б�

```erlang
-module(shopping_cart).
-export([calc/1]).
calc(ShopingCart) -> [{Item, Quantity * Price} || {Item, Quantity, Price} <- ShopingCart]. 
```

* ��ȡһ����СΪ9���б��Ԫ�飬��ʾ�����壨tic-tac-toe�������̡���ʤ���Ѷ����򷵻�ʤ�ߣ�x��o��������û�п��ߵ����ţ��򷵻�cat������������ûӮ���򷵻�no_winner��

```erlang
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
```

# Day 3 #
* �����ڽ�����ֹʱ��������OTP����
http://www.erlang.org/doc/design_principles/sup_princ.html#id71306

* �����򵥵�OTP���������ĵ�
http://www.erlang.org/doc/design_principles/gen_server_concepts.html

* ����translate_service����������ֹʱ������

* ���Doctor������ֹ��ʹ����������

* дһ������Doctor�������ļ��������������ĳ����������ֹ����������

* ����һ��������OTP�����������԰���Ϣ��¼���ļ��С�

* ��translate_service���������С�