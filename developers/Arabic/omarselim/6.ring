 /*
xy()
x=1
?x

func xy {
	? "hello world"
	y=2
	?y
 
}

FUNC MAIN {
	ALIST =1:10
	ALIST1 =ALIST 
	ALIST[1]="ONE"
	?ALIST 
	?ALIST1



}
 */
? ADDD (3,5)

FUNC ADDD X,Y
	RETURN X*Y


FUNC MAIN
	WHILE TRUE 
		SEE"
		(1)HELLO 
		(2) ENDX() 
	" GIVE NOPTION
	SWITCH NOPTION 
	ON "1" HELLO()
	ON "2" ENDX()
	OTHER ? "WRONG"
	OFF
END 
? "THANKS"

FUNC HELLO()
	?"HELLO"
FUNC ENDX()
	EXIT
