load "typehints.ring"

see sum(3,4) + nl ;
see sayHello("Mahmoud");

int func sum(int x,int y) {
	return x+y ;
}

string func sayHello(string name) {
	return "Hello " + name ;
}
