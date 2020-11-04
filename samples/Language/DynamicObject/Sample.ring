# Mohammad Hamdy Ghanem
# 04/11/2020

load "dynobj.ring"

Color = defObj([
	:R,
	:G, 
	:B, 
	:ToString = func(){
		return "(" + R + ", " + G + ", " + B + ")"
	}
])

Colors = defObj([ 
      :Red = NewObj(Color){R = 255 G = 0 B = 0},
      :Green = NewObj(Color){R = 0 G = 255 B = 0},
      :Blue = NewObj(Color){R = 0 G = 0 B = 255},
      :Black = NewObj(Color){R = 0 G = 0 B = 0},
      :White = NewObj(Color){R = 255 G = 255 B = 255},
      :Print = func() {
          For C in Attributes(self)
             ? C + " = " + GetAttribute(Self, C).ToString()
          Next
      }
    ]) 

r = Colors.Red
? "Red.R = " + r.R
? colors.Print()
