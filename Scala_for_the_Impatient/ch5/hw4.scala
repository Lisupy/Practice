class Time(hours: Int, minutes: Int){
	val mins = hours * 60 + minutes
	def before(other: Time): Boolean = mins < other.mins
	
}

val Ta = new Time(0, 1)
val tb = new Time(1, 2)
println(Ta.before(tb))
