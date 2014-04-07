class Point(val x: Double, val y: Double)

class LabeledPoint(val label: String, x: Double, y: Double) extends Point(x, y)

abstract class Shape{
  def centerPoint: Point
}

class Rectangle(val p1: Point, val p2: Point) extends Shape{
  def centerPoint: Point = new Point((p1.x+p2.x)/2, (p1.y+p2.y)/2)
}
class Circle(val center:Point, val R: Point) extends Shape{
  def centerPoint: Point = center
}
