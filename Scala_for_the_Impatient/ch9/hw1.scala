import scala.io.Source
val source = Source.fromFile("hw1.scala", "UTF-8")

source.getLines.toArray.reverse.map(println)
source.close
