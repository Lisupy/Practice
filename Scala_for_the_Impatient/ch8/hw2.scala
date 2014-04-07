class BankAccount(initialBalance: Double) {
  private var balance = initialBalance
  def deposit(amount: Double) = { balance += amount; balance }
  def withdraw(amount: Double) = { balance -= amount; balance }
}

class CheckingAccount(initialBalance: Double) extends BankAccount(initialBalance) {
  override def deposit(amount: Double) = {
    super.deposit(amount)
    super.withdraw(1)
  }
  override def withdraw(amount: Double) = {
    super.withdraw(amount)
    super.withdraw(1)
  }
}

class SavingsAccount(initialBalance: Double) extends BankAccount(initialBalance) {
  var freenum = 3
  def earnMonthlyInterest() = { 
    freenum = 3
    super.deposit(1)
  }
  override def deposit(amount: Double) = {
    if (freenum == 0){ 
      super.withdraw(1)
    }else{
      freenum -= 1
    }
    super.deposit(amount)
  }
  override def withdraw(amount: Double) = {
    if (freenum == 0){
      super.withdraw(1)
    }else{
      freenum -= 1
    }
    super.withdraw(amount)
  }
}
var ba = new SavingsAccount(1000)
for (i <- 1 to 5){
  println(ba.deposit(100))
}

println("earnMonthlyInterest")
ba.earnMonthlyInterest()
for (i <- 1 to 5){
  println(ba.withdraw(100))
}





