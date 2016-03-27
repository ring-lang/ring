#load "test2.nova"
#load "s6.nova"
#load "s5.nova"

y = 1225.12

# this is a comment

oStudent = new student 
oStudent.name = "mahmoud"
oStudent.main() # Another comment is here

x = 3+4*5+str(oStudent.SayHello("how are you
i hope that
you are fine","man"))

see x

func str x 
	return "" + x

class human
	id = 1

class person
	job = "programmer"
	func show
		see "welcome !" + nl

class student from human 	# class student is started here
	name = "no name"
	oPerson = new person
	func main
		see "hello world" 
		t = 1
		while true
			for x = 1 to (t*10)
				see x 
				if (x = 3)   
					see "this is number three" + x
				but x = 4
					see "four"
				but x = 5
					see "five"
				else
					see "nice"
					exit 2
				ok
			next
		end
		sayhello("Hello "," My Friend " )
		oPerson.show()
	return
	func sayhello cMsg,cText
		see cMsg + cText
	return
endclass