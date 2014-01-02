val data = List("abc", "def", "ghi")
println(data)
val total = data.foldLeft(0) ( _ + _.length)
println(total)

println(List[String]().foldLeft(0) (_ + _.length))