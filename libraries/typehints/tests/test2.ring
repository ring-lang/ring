load "typehints.ring"

int 	sum = sum(3,4)
string 	msg = sayHello("Mahmoud")

see "Sum = " + sum + nl + msg + nl


int func sum(int x,int y) {
	return x+y ;
}

string func sayHello(string name) {
	return "Hello " + name ;
}
