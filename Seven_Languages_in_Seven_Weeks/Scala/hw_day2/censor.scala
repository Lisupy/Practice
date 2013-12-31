
trait Censor {
	val curseWords: Map[String, String]
	def replace(s: String): String = {
		val list = s.split(' ')
		val nl = list.map( w => curseWords.getOrElse(w, w))
		nl.mkString(" ")
	}
}

class C1 extends Censor{
	override val curseWords = Map("Pucky" -> "Shoot", "Beans" -> "Darn")
}
object C2 extends Censor{
	override val curseWords = Map("Hello" -> "Fuck")
}

class C3(override val curseWords: Map[String, String]) extends Censor
//val c3 = new C3( scala.io.Source.fromFile("file.txt").getLines().map(_.split(' ')).toMap)
for (s <- scala.io.Source.fromFile("data.txt").getLines.map(_.split(' ')))
	for (t <- s)
		println(t)
val sentence = "Pucky, Hello World, Beans"
println( (new C1).replace(sentence))
println( C2.replace(sentence))
//println( c3.replace(sentence))