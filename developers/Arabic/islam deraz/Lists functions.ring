/*
          Application        :Lists functions
          Author             :Islam Deraz
          Date               :2018.02.14
          Application Number :10
*/ 
#variable Types (string, number, list, object, c object)

alist = 1:10			# 10 items
? alist
del(alist,5)
? alist

alist + "Egypt"			# 10
alist + "KSA"
alist + "France"

? "Egypt position: " + find(alist,"Egypt")

alist = [
	["Ahmed"   , 100],	
	["Mohamed" , 200],
	["Hamza"   , 300],
	["Ibrahim" , 400]
]

? alist[find(alist,"Ahmed",1)][2]
