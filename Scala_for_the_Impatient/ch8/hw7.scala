import java.awt.Rectangle

class Square(x: Int, y: Int, L: Int) extends Rectangle(x, y, L, L){
  def this(L: Int){
    this(0, 0, L)
  }
  def this(){
    this(0)
  }
}
val a: Rectangle = new Square()
println(a)
val b = new Square(1, 2, 3)
println(b)
