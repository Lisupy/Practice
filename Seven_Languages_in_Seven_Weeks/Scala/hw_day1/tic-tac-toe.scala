class TicTacToe{
    var grid = Array(
				Array('.', '.', '.'),
				Array('.', '.', '.'),
				Array('.', '.', '.')
			   )
    def show(){
        for (s <- grid){
            println(("" /: s) { (a, b) => a + b })
        }        
    }
    def win(ch: Char):Boolean = {
      for {
		x <- Range(0, 3)
		y <- Range(0, 3)
        dx <- Range(0, 2)
	    dy <- Range(0, 2) 
		if (dx != 0 || dy != 0) 
	  }{
          if ({
            for (i <- Range(0, 3)){
              val tx = x + dx * i 
              val ty = y + dy * i
              if (tx >= 3 || ty >= 3){
                return false
              }
              if (grid(tx)(ty) != ch){
                return false
              }
            } 
            return true
          }){
			return true
		  }
        }      
      return false
    }
    def place(x : Int, y : Int, ch: Char) : Boolean = {
	  if (x < 0 || x > 2 || y < 0 || y > 3) return false
	  if (grid(x)(y) != '.') return false
	  grid(x)(y) = ch 
	  true;
	}
}

//while (true){
var game = new TicTacToe

for (i <- Range(0, 9) if (!game.win('o') && !game.win('x'))){
	val player = if (i % 2 == 0) 1 else 2
	val ch = if (player == 1) 'x' else 'o'
	game.show()
	println(s"Player $player:")
	val Array(x, y) = Console.readLine.split(" ").map(_.toInt)
	println(x)
	println(y)
	game.place(x, y, ch)
	if (game.win(ch)){
		game.show()
		println(s"Player $player Win!")
	}
}		

if (!game.win('o') && !game.win('x')){
	game.show();
	print("Tie!");
}
  
