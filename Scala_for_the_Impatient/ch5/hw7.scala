class Person(name:String){
	val firstName = name.split(' ')(0)
	val lastName = name.split(' ')(1)
}

val p = new Person("Fred Smith")
println(p.firstName)
println(p.lastName)
//println(p.name)
//p.firstName = "abc"