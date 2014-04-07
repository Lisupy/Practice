

package object random{
  import scala.math._
  val a = 1664525
  val b = 1013904223
  val n = 32
  var seed = 0
  def setSeed(_s :Int) {
    seed = _s
  }
  def nextInt: Int = {
    val s = (seed * a + b) % pow(2, n).toInt
    setSeed(s)
    s
  }
  def nextDouble: Double = {
    val s = (seed * a + b) % pow(2, n)
    setSeed(s.toInt)
    s
  }
}

// 命令行执行
//$ scalac hw2.scala
//$ scala Test
object Test extends App{
  println(random.nextDouble)
  println(random.nextDouble)
  println(random.nextInt)
  println(random.nextInt)
}
