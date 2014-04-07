import scala.io.Source

val file = "hw2.txt"
val source = Source.fromFile("hw2.txt", "UTF-8")
val tokens = source.mkString.split("\\S+")
tokens.foreach(a => println(a.toString))
for (i <- tokens) println(i)
