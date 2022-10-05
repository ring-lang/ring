load "..\aString.ring"
a = 1
Test(a)
? "a = " + a

b = "abcd"
Test(b)
? "b = " + b

c = [4, 3, 2]
Test(c)
? "-------List:------" 
? c
? "-------"
d = new aString("abcd")
Test(d)
? "d = " + d.Text


func Test(x)
  x = x + 1
