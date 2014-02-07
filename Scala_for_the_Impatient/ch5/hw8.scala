class Car(val maker: String, val model: String, year: Int = -1){
	var number: String = ""
	def this(maker: String, model: String, number: String){
		this(maker, model)
		this.number = number
	}
	def this(maker: String, model: String, year: Int, number: String){
		this(maker, model, year)
		this.number = number
	}
}
	