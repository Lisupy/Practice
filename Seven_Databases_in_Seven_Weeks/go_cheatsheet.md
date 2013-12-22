go戳的痛点
=========


#包
## 链接问题可能会简单很多

# 函数
## 闭包

## 返回值
  * 多返回值，相当于tuple？
  * 命名返回值，对比Octave

# 变量声明
```go
    var x, y, z int = 1, 2, 3
    c, python, java := true, false, "no!"
```
## 短声明
## `tuple`方式的初始化


# 常量
```
const Pi = 3.14
const (
    Big   = 1 << 100
    Small = Big >> 99
)
```
## 一个`const`就包起来了，漂亮
    * `var`也可以声明变量

# for循环
```go
for i := 0; i < 10; i++ {
    sum += i
}
for sum < 1000 {
    sum += sum
}
```
## `for` 当做`while`用,有点丑
```go
package main

import "fmt"

var pow = []int{1, 2, 4, 8, 16, 32, 64, 128}

func main() {
    for i, v := range pow {
        fmt.Printf("2**%d = %d\n", i, v)
    }
}
```
```go
package main

import "fmt"

func main() {
    pow := make([]int, 10)
    for i := range pow {
        pow[i] = 1 << uint(i)
    }
    for _, value := range pow {
        fmt.Printf("%d\n", value)
    }
}
```
## 迭代方式

# if语句
```go
if v := math.Pow(x, n); v < lim {
    return v
} else {
    fmt.Printf("%g >= %g\n", v, lim)
}
```
## `if`里面可以声明变量，漂亮

# 结构体
```go
type Vertex struct {
    X, Y int
}
var (
    p = Vertex{1, 2}  // 类型为 Vertex
    q = &Vertex{1, 2} // 类型为 *Vertex
    r = Vertex{X: 1}  // Y:0 被省略
    s = Vertex{}      // X:0 和 Y:0
)
func main() {
    fmt.Println(p, q, r, s)
}
```
## 居然有指针。。
## 自己`Println`出来, C语言可以少用gdb，也少写to_string接口了

# Slice和数组
```go
package main

import "fmt"

func main() {
    p := []int{2, 3, 5, 7, 11, 13}
    fmt.Println("p ==", p)

    for i := 0; i < len(p); i++ {
        fmt.Printf("p[%d] == %d\n",
            i, p[i])
    }
}
```
## 同`struct`可以直接`Println`出来，漂亮
```go
package main

import "fmt"

func main() {
    p := []int{2, 3, 5, 7, 11, 13}
    fmt.Println("p ==", p)
    fmt.Println("p[1:4] ==", p[1:4])

    // 省略下标代表从 0 开始
    fmt.Println("p[:3] ==", p[:3])

    // 省略上标代表到 len(s) 结束
    fmt.Println("p[4:] ==", p[4:])
}
```
## 切片语法同python
```go
package main

import "fmt"

func main() {
    var z []int
    fmt.Println(z, len(z), cap(z))
    if z == nil {
        fmt.Println("nil!")
    }
}
```
## 空slice 的零值是 `nil`，觉得这个定义有点多余
## `make`语句，还没看到

# Map
```
package main

import "fmt"

type Vertex struct {
    Lat, Long float64
}

var m map[string]Vertex

func main() {
    m = make(map[string]Vertex)
    m["Bell Labs"] = Vertex{
        40.68433, -74.39967,
    }
    fmt.Println(m["Bell Labs"])
}
```
## 定义丑
```
package main

import "fmt"

type Vertex struct {
    Lat, Long float64
}

var m = map[string]Vertex{
    "Bell Labs": Vertex{
        40.68433, -74.39967,
    },
    "Google": Vertex{
        37.42202, -122.08408,
    },
}

var m2 = map[string]Vertex{
    "Bell Labs": {40.68433, -74.39967},
    "Google":    {37.42202, -122.08408},
}

func main() {
    fmt.Println(m)
}
```
## 初始化观感还行
```
package main

import "fmt"

func main() {
    m := make(map[string]int)

    m["Answer"] = 42
    fmt.Println("The value:", m["Answer"])

    m["Answer"] = 48
    fmt.Println("The value:", m["Answer"])

    delete(m, "Answer")
    fmt.Println("The value:", m["Answer"])

    v, ok := m["Answer"]
    fmt.Println("The value:", v, "Present?", ok)
}
```
## 修改。不是C++风格的，觉得不伦不类。但往好的方向想就是haskell。
## 双赋值检测是比较漂亮的技术

# Switch
```go
package main

import (
    "fmt"
    "runtime"
)

func main() {
    fmt.Print("Go runs on ")
    switch os := runtime.GOOS; os {
    case "darwin":
        fmt.Println("OS X.")
    case "linux":
        fmt.Println("Linux.")
    default:
        // freebsd, openbsd,
        // plan9, windows...
        fmt.Printf("%s.", os)
    }
}
```
## 支持字符串，漂亮
```
package main

import (
    "fmt"
    "time"
)

func main() {
    t := time.Now()
    switch {
    case t.Hour() < 12:
        fmt.Println("Good morning!")
    case t.Hour() < 17:
        fmt.Println("Good afternoon.")
    default:
        fmt.Println("Good evening.")
    }
}
```
## 还支持条件判断
## 不知道是否支持模式匹配，还没看到

# 方法
```go
package main

import (
    "fmt"
    "math"
)

type Vertex struct {
    X, Y float64
}

func (v *Vertex) Abs() float64 {
    return math.Sqrt(v.X*v.X + v.Y*v.Y)
}

func main() {
    v := &Vertex{3, 4}
    fmt.Println(v.Abs())
}
```
## 语法奇葩
```go
package main

import (
    "fmt"
    "math"
)

type MyFloat float64

func (f MyFloat) Abs() float64 {
    if f < 0 {
        return float64(-f)
    }
    return float64(f)
}

func main() {
    f := MyFloat(-math.Sqrt2)
    fmt.Println(f.Abs())
}
```
可以对包中的 任意 类型定义任意方法，而不仅仅是针对结构体。但不能对来自其他包的类型或基础类型定义方法。
## 很“工程”的设计
```go
package main

import (
    "fmt"
    "math"
)

type Vertex struct {
    X, Y float64
}

func (v *Vertex) Scale(f float64) {
    v.X = v.X * f
    v.Y = v.Y * f
}

func (v Vertex) Scale(f float64) {
    v.X = v.X * f
    v.Y = v.Y * f
}

func (v *Vertex) Abs() float64 {
    return math.Sqrt(v.X*v.X + v.Y*v.Y)
}

func main() {
    v := &Vertex{3, 4}
    v.Scale(5)
    fmt.Println(v, v.Abs())
}
```
## 方法接收者可以为命名类型或命名类型的指针

# 接口
```
package main

import (
    "fmt"
    "math"
)

type Abser interface {
    Abs() float64
}

func main() {
    var a Abser
    f := MyFloat(-math.Sqrt2)
    v := Vertex{3, 4}

    a = f  // a MyFloat 实现了 Abser
    a = &v // a *Vertex 实现了 Abser
  //  a = v  // a Vertex, 没有实现 Abser

    fmt.Println(a.Abs())
}

type MyFloat float64

func (f MyFloat) Abs() float64 {
    if f < 0 {
        return float64(-f)
    }
    return float64(f)
}

type Vertex struct {
    X, Y float64
}

func (v *Vertex) Abs() float64 {
    return math.Sqrt(v.X*v.X + v.Y*v.Y)
}
```
## 看例子吧，应该比虚函数和回调好用
```
package main

import (
    "fmt"
    "os"
)

type Reader interface {
    Read(b []byte) (n int, err error)
}

type Writer interface {
    Write(b []byte) (n int, err error)
}

type ReadWriter interface {
    Reader
    Writer
}

func main() {
    var w Writer

    // os.Stdout 实现了 Writer
    w = os.Stdout

    fmt.Fprintf(w, "hello, writer\n")
}
```
## 隐式接口，但例子还没看出怎么使用。但修改接口声明不用到处改是好事

## 错误类型
```
package main

import (
    "fmt"
    "time"
)

type MyError struct {
    When time.Time
    What string
}

func (e *MyError) Error() string {
    return fmt.Sprintf("at %v, %s",
        e.When, e.What)
}

func run() error {
    return &MyError{
        time.Now(),
        "it didn't work",
    }
}

func main() {
    if err := run(); err != nil {
        fmt.Println(err)
    }
}
```
## 类似异常，实际上是错误接口`struct`
 * 比异常好看[`Error`，`panic`，`defer`](http://www.yiibai.com/go/go_error_handle.html#go_error_handle "")

# HTTP
```go
package main

import (
    "fmt"
    "net/http"
)

type Hello struct{}

func (h Hello) ServeHTTP(
    w http.ResponseWriter,
    r *http.Request) {
    fmt.Fprint(w, "Hello!")
}

func main() {
    var h Hello
    http.Handle("/string", String("I'm a frayed knot."))
    http.Handle("/struct", &Struct{"Hello", ":", "Gophers!"})
    http.ListenAndServe("localhost:4000", h)
}
```
## Demo而已

# 并发
```go
package main

import (
    "fmt"
    "time"
)

func say(s string) {
    for i := 0; i < 5; i++ {
        time.Sleep(100 * time.Millisecond)
        fmt.Println(s)
    }
}

func main() {
    go say("world")
    say("hello")
}
```
## goroutine
```
package main

import "fmt"

func sum(a []int, c chan int) {
    sum := 0
    for _, v := range a {
        sum += v
    }
    c <- sum // 将和送入 c
}

func main() {
    a := []int{7, 2, 8, -9, 4, 0}

    c := make(chan int)
    go sum(a[:len(a)/2], c)
    go sum(a[len(a)/2:], c)
    x, y := <-c, <-c // 从 c 中获取

    fmt.Println(x, y, x+y)
}
```
## channel，避免造轮子了
  * 语法有点奇特，可能是语言专注解决的问题之一，给了一个比较高的地位
  * 可以定义最大缓存长度（也能制造死锁）`c := make(chan int, 2)`

## `close`线程，`range`chanel
```
package main

import (
    "fmt"
)

func fibonacci(n int, c chan int) {
    x, y := 0, 1
    for i := 0; i < n; i++ {
        c <- x
        x, y = y, x+y
    }
    close(c)
}

func main() {
    c := make(chan int, 10)
    go fibonacci(cap(c), c)
    for i := range c {
        fmt.Println(i)
    }
}
```
## `select`，也是避免造轮子的？
```
package main

import (
    "fmt"
    "time"
)

func main() {
    tick := time.Tick(100 * time.Millisecond)
    boom := time.After(500 * time.Millisecond)
    for {
        select {
        case <-tick:
            fmt.Println("tick.")
        case <-boom:
            fmt.Println("BOOM!")
            return
        default:
            fmt.Println("    .")
            time.Sleep(50 * time.Millisecond)
        }
    }
}
```
 * 可以有`default`


