cStr1 = print2str("Hello, World!")
cStr2 = print2str(2022)
cStr3 = print2str("one\ntwo\nthree\n")
cStr4 = print2str("one\n\ttwo\n\t\tthree\n")
age = 6
cStr5 = print2str("Ring is #{age} years old!") 
cStr6 = print2str("I know that 2+2=#{2+2} and 3+3=#{3+3}")
? cStr1
? cStr2
? cStr3
? cStr4
? cStr5
? cStr6
happy()

func happy
	new myclass {x=10 y=20 z=30 test()}
	? :done

class myclass 
	name = "Ring"
	x y z 
	func test
		cStr1 = print2str("Language Name = #{name}\n")
		cStr2 = print2str("x=#{x}\ny=#{y}\nz=#{z}\n")
		? cStr1
		? cStr2