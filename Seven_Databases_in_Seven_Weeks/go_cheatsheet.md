go����ʹ��
=========


#��
## ����������ܻ�򵥺ܶ�

# ����
## �հ�

## ����ֵ
  * �෵��ֵ���൱��tuple��
  * ��������ֵ���Ա�Octave

# ��������
```go
    var x, y, z int = 1, 2, 3
    c, python, java := true, false, "no!"
```
## ������
## `tuple`��ʽ�ĳ�ʼ��


# ����
```
const Pi = 3.14
const (
    Big   = 1 << 100
    Small = Big >> 99
)
```
## һ��`const`�Ͱ������ˣ�Ư��
    * `var`Ҳ������������

# forѭ��
```go
for i := 0; i < 10; i++ {
    sum += i
}
for sum < 1000 {
    sum += sum
}
```
## `for` ����`while`��,�е��
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
## ������ʽ

# if���
```go
if v := math.Pow(x, n); v < lim {
    return v
} else {
    fmt.Printf("%g >= %g\n", v, lim)
}
```
## `if`�����������������Ư��

# �ṹ��
```go
type Vertex struct {
    X, Y int
}
var (
    p = Vertex{1, 2}  // ����Ϊ Vertex
    q = &Vertex{1, 2} // ����Ϊ *Vertex
    r = Vertex{X: 1}  // Y:0 ��ʡ��
    s = Vertex{}      // X:0 �� Y:0
)
func main() {
    fmt.Println(p, q, r, s)
}
```
## ��Ȼ��ָ�롣��
## �Լ�`Println`����, C���Կ�������gdb��Ҳ��дto_string�ӿ���

# Slice������
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
## ͬ`struct`����ֱ��`Println`������Ư��
```go
package main

import "fmt"

func main() {
    p := []int{2, 3, 5, 7, 11, 13}
    fmt.Println("p ==", p)
    fmt.Println("p[1:4] ==", p[1:4])

    // ʡ���±����� 0 ��ʼ
    fmt.Println("p[:3] ==", p[:3])

    // ʡ���ϱ���� len(s) ����
    fmt.Println("p[4:] ==", p[4:])
}
```
## ��Ƭ�﷨ͬpython
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
## ��slice ����ֵ�� `nil`��������������е����
## `make`��䣬��û����

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
## �����
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
## ��ʼ���۸л���
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
## �޸ġ�����C++���ģ����ò��ײ��ࡣ�����õķ��������haskell��
## ˫��ֵ����ǱȽ�Ư���ļ���

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
## ֧���ַ�����Ư��
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
## ��֧�������ж�
## ��֪���Ƿ�֧��ģʽƥ�䣬��û����

# ����
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
## �﷨����
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
���Զ԰��е� ���� ���Ͷ������ⷽ����������������Խṹ�塣�����ܶ����������������ͻ�������Ͷ��巽����
## �ܡ����̡������
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
## ���������߿���Ϊ�������ͻ��������͵�ָ��

# �ӿ�
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

    a = f  // a MyFloat ʵ���� Abser
    a = &v // a *Vertex ʵ���� Abser
  //  a = v  // a Vertex, û��ʵ�� Abser

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
## �����Ӱɣ�Ӧ�ñ��麯���ͻص�����
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

    // os.Stdout ʵ���� Writer
    w = os.Stdout

    fmt.Fprintf(w, "hello, writer\n")
}
```
## ��ʽ�ӿڣ������ӻ�û������ôʹ�á����޸Ľӿ��������õ������Ǻ���

## ��������
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
## �����쳣��ʵ�����Ǵ���ӿ�`struct`
 * ���쳣�ÿ�[`Error`��`panic`��`defer`](http://www.yiibai.com/go/go_error_handle.html#go_error_handle "")

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
## Demo����

# ����
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
    c <- sum // �������� c
}

func main() {
    a := []int{7, 2, 8, -9, 4, 0}

    c := make(chan int)
    go sum(a[:len(a)/2], c)
    go sum(a[len(a)/2:], c)
    x, y := <-c, <-c // �� c �л�ȡ

    fmt.Println(x, y, x+y)
}
```
## channel��������������
  * �﷨�е����أ�����������רע���������֮һ������һ���Ƚϸߵĵ�λ
  * ���Զ�����󻺴泤�ȣ�Ҳ������������`c := make(chan int, 2)`

## `close`�̣߳�`range`chanel
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
## `select`��Ҳ�Ǳ��������ӵģ�
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
 * ������`default`


