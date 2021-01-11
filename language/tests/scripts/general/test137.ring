# This test is based on Ring Code written by Mohammad Hamdy Ghanem in 04/11/2020

_Dynamic_Class_id = 1

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

? Colors.White
? type(Colors.White)
? Attributes(Colors.WHite)

oo = Colors.WHite
? oo.R
? "white.R = " + Colors.White.R 

func defObj(lstAttrs)
    _class = "o = new DynamicClass_" + _Dynamic_Class_id + nl + 
				  "Class DynamicClass_" + _Dynamic_Class_id + nl + "end" 
 
    eval(_class)
	 for attr in lstAttrs
      if isList(attr)   
        if isstring(attr[2]) and isFunction(attr[2])
           AddMethod(o, attr[1], attr[2])
        else
		     AddAttribute(o, attr[1])
           SetAttribute(o, attr[1], attr[2])
        end
      else
		  AddAttribute(o, attr)
      end
    next
    _Dynamic_Class_id += 1
    return o
end


func NewObj(obj)
    if not IsObject(obj) return Null end

    eval("o = new " + className(obj))

	 for attr in Attributes(obj)        
		  AddAttribute(o, attr)
    next

	 for m in Methods(obj)        
		  AddAttribute(o, m)
    next

    return o
end
