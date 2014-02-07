val in = new java.util.Scanner(new java.io.File("myfile.txt"))

val stat = scala.collection.mutable.Map[String, Int]()
//val stat = new scala.collection.mutable.HashMap[String, Int]
while (in.hasNext()) {
	val w = in.next()
	stat(w) = stat.getOrElse(w, 0) + 1
}
for ((k, v) <- stat) println(k, v)