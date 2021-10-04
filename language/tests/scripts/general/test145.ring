# Author : Mansour Ayouni

? MyNumberQ(12).AddQ(4).AddQ(-8).MultiplyByQ(2).Value()

 
? MyNumberQ(12).AddQ(4)
	       .AddQ(-8)
	       .MultiplyByQ(2)
	       .Value()


func MyNumberQ(n)
	return new MyNumber(n)

class MyNumber
	@nValue
	def init(n)
		@nValue = n
	def Value()
		return @nValue
	def Add(n)
		@nValue + n
	def AddQ(n)
		This.Add(n)
		return This
	def MultiplyBy(n)
		@nValue * n
	
	def MultiplyByQ(n)
		This.MultiplyBy(n)
		return This