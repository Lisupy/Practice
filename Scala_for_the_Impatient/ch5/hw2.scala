class BankAccount(private var balance: Int){
	def deposit(money: Int) { balance += money }
	def withdraw(money: Int) { balance -= money }
	def money = balance
}

var ba = new BankAccount(0)
println(ba.money)
ba.deposit(1)
println(ba.money)
