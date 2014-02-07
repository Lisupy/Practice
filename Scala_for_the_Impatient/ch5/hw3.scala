class Time(private val hours: Int, private val minutes: Int){
	def before(other: Time): Boolean = 
		if (hours != other.hours) return hours < other.hours
		else return minutes < other.minutes
	
}

val Ta = new Time(0, 1)
val tb = new Time(1, 2)
println(Ta.before(tb))