abstract class UnitConversion{
  def apply(n: Int): Int
}
object InchesToCentimeters extends UnitConversion{
  override def apply(n: Int) = n * 10
}
object GallonsToLiters extends UnitConversion{
  override def apply(n: Int) = n * 20
}
object MilesToKilometers extends UnitConversion{
  override def apply(n: Int) = n * 30
}

println(InchesToCentimeters(3))
val a: UnitConversion = GallonsToLiters

println(a(3))

