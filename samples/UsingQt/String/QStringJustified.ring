load "guilib.ring"

o1 = new QString2()
o1.append("Ring")

oChar = new QChar(61)
? o1.leftJustified(20,oChar,False)
? o1.rightJustified(20,oChar,False)