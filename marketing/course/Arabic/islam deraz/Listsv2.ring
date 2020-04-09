/*
          Application        :Variables (Lists)-Version2
          Author             :Islam Deraz
          Date               :2018.02.14
          Application Number :5
*/ 
#variable Types (string, number, list, object, c object)

alist= [

	:name    ="Hamza islam",
	:job     ="creative programmer",
	:country ="Egypt",
	:city	 ="Alex"
	]

? alist[:name]
? alist[:job]

if alist[:city]=NULL alist[:city]= "Cairo" end

? alist[:city]

