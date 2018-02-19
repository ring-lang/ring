/*
          Application        :Variables (Lists)-Version3
          Author             :Islam Deraz
          Date               :2018.02.14
          Application Number :6
*/ 
#variable Types (string, number, list, object, c object)

alist= [

	:name    ="Hamza islam",
	:job     ="creative programmer",
	:country ="Egypt",
	:city	 ="Alex"
	]
? "size: " +len(alist)

for aitem in alist
	? aitem[1]
next

