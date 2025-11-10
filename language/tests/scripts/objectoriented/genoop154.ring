cCode = "myo = new myclass 

myo {
	for t=1 to 1000
		i1 want1 window1
	next
}

class MyClass 
"

for t=1 to 1000
cCode += "
i"+t+"
want"+t+"
window"+t+"
"
next

for t=1 to 1000
cCode += "
func geti"+t+"
? :i"+t+"
func getwant"+t+"
? :want"+t+"
func getwindow"+t+"
? :window"+t+"
"
next

cCode +=`
func braceexpreval value 
func braceerror
`

write("oop154.ring",cCode)
