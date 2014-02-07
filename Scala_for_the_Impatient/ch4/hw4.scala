val in = new java.util.Scanner(new java.io.File("myfile.txt"))

var stat = scala.collection.immutable.SortedMap[String, Int]()
while (in.hasNext()) {
	val w = in.next()
	stat = (stat - w) + (w -> (stat.getOrElse(w, 0) + 1))
}
for ((k, v) <- stat) println(k, v)