object Cards extends Enumeration{
  val M = Value("♣")
  val T = Value("♠")
  val H = Value("♥")
  val F = Value("♦")
  val D = Value("123")
  def isRed(c: Value) = c == H || c == F
}

println(Cards.M)
println(Cards.D)
println(Cards.isRed(Cards.H))
