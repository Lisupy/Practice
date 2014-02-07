
class Person(var age: Int = 0){
	def age_(a: Int) = age = if (a < 0) 0 else a
}

val pa = new Person(3)
pa.age_(-1)
println(pa.age)