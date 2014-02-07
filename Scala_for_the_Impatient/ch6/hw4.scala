class Point(val x: Int, val y: Int){
  override def toString: String = "x = " + x + ", " + "y = " + y
}
object Point {
  def apply(x: Int, y: Int) = new Point(x, y)
}

val a = Point(1, 2)
println(a)
