# Day1 #


* Erlang的官方网站   
   * http://www.erlang.org/
* Erlang函数库的官方文档
   * http://www.erlang.org/doc.html
* Erlang OTP库的官方文档
    * http://www.erlang.org/doc/

* 写一个函数，用递归返回字符串中的单词数
```erlang
-module(word_count).
-export([count/1]).
count([])           -> 1;
count([$   | Tail]) -> count(Tail) + 1;                                                                                      
count([_   | Tail]) -> count(Tail).
```

* 写一个函数，用递归技数到10的函数
```erlang
-module(count).
-export([countTo10/1]).
countTo10(10)   -> io:fwrite("~B~n", [10]);
countTo10(N)    -> io:fwrite("~B, ", [N]), countTo10(N + 1). 
```

* 写一个函数，在给定输入为`{error, Message}`或`Success`的条件下，利用匹配打印出`"Success"`或 `"error: message"`
```erlang
-module('echo').
-export([echo/1]).
echo(success)   -> io:fwrite("Success~n");
echo([error, Message])  -> io:fwrite("error: ~s~n", [Message]). 
```


# Day2 #
* 考虑包含键-值的列表，如`[{erlang, "a functional language"}, {ruby, "an 00 language"}]`。写一个函数，接受列表和键为参数，返回该键对应的值。

```erlang
-module(kv).
-export([find/2]).
find([],               _)   -> null;
find([{Key, Val} | _], Key) -> Val;
find([_ | Tail],       Key) -> find(Tail, Key). 
```

* 考虑形如`[{item quantity price}, ...}]`的购物列表。写一个列表解析，构建形如`[{item total_price}, ...]`的商品列表。

```erlang
-module(shopping_cart).
-export([calc/1]).
calc(ShopingCart) -> [{Item, Quantity * Price} || {Item, Quantity, Price} <- ShopingCart]. 
```

* 读取一个大小为9的列表或元组，表示井字棋（tic-tac-toe）的棋盘。若胜负已定，则返回胜者（x或o）；若再没有可走的棋着，则返回cat；若两方都还没赢，则返回no_winner。

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
* 可以在进程终止时重启它的OTP服务
http://www.erlang.org/doc/design_principles/sup_princ.html#id71306

* 构建简单的OTP服务器的文档
http://www.erlang.org/doc/design_principles/gen_server_concepts.html

* 监视translate_service，并在它终止时重启它

* 如果Doctor进程终止，使其重启自身

* 写一个监视Doctor监视器的监视器。如果其中某个监视器终止，则重启它

* 创建一个基本的OTP服务器，可以吧消息记录到文件中。

* 让translate_service跨网络运行。