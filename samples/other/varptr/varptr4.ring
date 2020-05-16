? "Sample about using setPointer() and getPointer() functions"
? copy("=",50)
pointer = NULLPOINTER()
? pointer
? "Type: " + type(pointer)
? "Value: " + Upper(hex(getpointer(pointer)))
? copy("=",50)
name = "ring"
pointer = varptr(:name,"char *")
? pointer
? "Type: " + type(pointer)
? "Value: " + Upper(hex(getpointer(pointer)))
? copy("=",50)
setpointer(pointer, getpointer(pointer) + 1 )
? "After Update"
? "Value: " + Upper(hex(getpointer(pointer)))
? copy("=",50)