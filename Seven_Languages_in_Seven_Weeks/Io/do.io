"====Day-1" println
# 对1+1求值，然后对1+"one"求值。Io是强类型还是弱类型？用代码证实你的答案。

1 + 1 println
//1 + "one" 这个异常了
"Io is strong type" println

# 0是true还是false？空字符串是true还是false？ nil是ture还是false？用代码证实你的答案
if (false) then ("false is true" println) else ("false is false" println)
if (0) then ("0 is true" println) else ("0 is false" println)

if ("") then ("\"\" is true" println) else ("\"\" is false" println)

if (nil) then ("nil is true" println) else ("nil is false" println)

# 如何知道某个原型都支持哪些槽？
B := Object clone
B t := "c"
a := B clone

"a's type is:" println
a type println
"B slotNames is :"
B slotNames print
"for each:" println
B slotNames foreach(print)
"" println
"a type slotNames is:" 
a type slotNames print
"for each:" println
a type slotNames foreach(print)
"" println

# =(等号)、:=(冒号等号)、::=(冒号冒号等号)之间有何区别？你会在什么情况下使用它们
//http://www.iolanguage.net/2012/02/10.html
//赋值操作（IO Language的赋值）：
//Io有三个赋值符号，分别是::=、:=、=，这三个赋值符号的//具体区别是：
//
//1、::= 用于创建对象、赋值；
//2、:= 用于创建对象、赋值；
//3、= 仅用于对已经存在的变量进行update赋值，如果对象还不存在，则会产生异常。

#做
# 从文件中运行Io程序
	//io do.io
# 给定槽的名称，执行该槽中的代码
a := Object clone
a p := method("a_pr" println)
a p()

"====Day-2" println
# 斐波那契数
fib_loop := method(n,(a := 1; b := 1; for(i,3,n,(c := a;a := a+b; b := c));a))
for (i, 1, 20, ("fib(" print; i print; ")=" print; fib_loop(i) println))
fib_recursive := method(n,if(n<=2,1,fib_recursive(n-1)+fib_recursive(n-2)))
for (i, 1, 20, ("fib(" print; i print; ")=" print; fib_recursive(i) println))

#在分母为0的情况下，如何让运算符/返回0？
"Change the '/' Operator:" println
//默认可能返回0，所以改为返回"KKK"
Number div := Number getSlot("/")
Number / := method(b, if (b == 0, "KKK", div(b)) )
//OperatorTable setSlot("/",)
(1/0) println
(1/2) println
#写一个程序，把二维数组中的所有数相加
"Sum two-dimensional array:" println
llsum := method(ll,(ll map(sum) sum))
ll := list(list(1,2,3), list(4,5,6), list(7,8,9))
llsum(ll) println

#对列表增加一个名为myAverage的槽
List myAverage := method(self average)
list(1,2,3,4,5) myAverage println

//http://iota.flowsnake.org/exceptions.html
NaN := Exception clone
List myAverage2 := method(
    s := 0; 
    self foreach(i, if (i type == "Number", s := s+i,NaN raise("NaN") ));
    //self foreach(i, if (i type == "Number", s := s+i,Exception raise("NaNExp") ));
    s / (self size))
list(1,2,3,4,5) myAverage2 println
try(
  list(1,2,3,4,"5") myAverage2 println
) catch(Exception, "Exception" println) catch(NaN, "NaN" println)

#二维列表Matrix原型
Matrix := List clone
Matrix dim := method(x,y, (self value := list(); 
						for (i,1,x, 
							(self value push(list()); 
							 for(j,1,y, self value at(i-1) append(nil))))))
Matrix set := method(x,y,val, self value at(x-1) atPut(y-1,val))
Matrix get := method(x,y, self value at(x-1) at(y-1)) 
D := Matrix clone
D dim(3,4)
D set(1,2,"a")
D get(1,2) println
D get(1,3) println

#Matrix方法
"Matrix revert:" println
Matrix revert := method(D := Matrix clone;
					x := self value at(0) size;
					y := self value size;
 					D dim(x, y);
					for (i,1,x, for(j,1,y, D set(i,j,self get(j,i))));
					D)
newD := D revert
newD get(2,1) println

#Matrix的文件输入输出
"File IO:" println
f := File with("Matrix.txt") remove openForUpdating
D value foreach(l, f write(l join(","), "\n") ) 
f close

D := Object clone
f := File with("Matrix.txt") 
ary := f readLines map(split)
D := Matrix clone
D dim(ary size, ary at(0) size)
D self := ary
D self println
#猜数游戏


