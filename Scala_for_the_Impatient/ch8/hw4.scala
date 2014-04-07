import collection.mutable.ArrayBuffer
abstract class Item{
  def price: Double
  def description: String
}
class SimpleItem(val price: Double, val description: String) extends Item

class Bundle extends Item{
  var items: ArrayBuffer[Item] = new ArrayBuffer[Item]()

  def addItem(item: Item){
    items += item
  }

  def price = items.map(_.price).foldLeft(0.0)(_ + _)
  def description = items.map(_.description).mkString("; ")
}

val a = new SimpleItem(0.1, "aItem")
val b = new SimpleItem(0.2, "bItem")
val c = new SimpleItem(0.3, "cItem")

println(a.description)

var D = new Bundle()

D.addItem(a)
D.addItem(b)
D.addItem(c)

println("-- D --")
println("price:", D.price)
println("desc:", D.description)



