Changeringkeyword New talk
changeringkeyword And _and
changeringkeyword Or _or
changeringkeyword To _to
changeringkeyword from _from
changeringkeyword in _in
changeringkeyword if _if
changeringkeyword but _but
changeringkeyword for _for
changeringkeyword see _see
changeringoperator ,  _,
changeringoperator .  _.
changeringoperator !  _!
changeringoperator *  _*
changeringoperator :  _:
changeringoperator -  _-
changeringoperator (  _(
changeringoperator )  _)

Talk Natural {

	Welcome to the Ring programming language!
	What you are reading now is not comments, I swear!

	After many years of programming I decided to think different about programming and solve the
	problems in a better way. We are writing commands or code and the Ring language is reading
	it to understand us! Sure, What you are seeing now is just ***part of the code - Not the Complete Program***
	You have to write little things before and after this part to be able to run it!

	It is the natural part of our code where we can write in English, Arabic or any Natural Language 
	Then we will tell the computer through the Ring language what must happens! in a way that we can scale 
	for large frameworks and programs.

	Just imagine what will happens to the world of programming once we create many powerful
	frameworks using the Ring language that uses this way (Natural Programming).

	For example When we say Hello to the Machine, It can reply! and when we
	say count from 1 to 5 it will understand us, Also if we said count from 5 to 1 it will
	understand us too! You can see the Output window!

	This Goal is not new, but the Ring language comes with an innovative solution to this problem. 	
	
}


changeringkeyword _And and
changeringkeyword _Or or
changeringkeyword _To to
changeringoperator _, ,
changeringoperator _. .
changeringoperator  _! !
changeringoperator  _* *
#changeringkeyword _from from
changeringkeyword _in in
changeringoperator  _: :
changeringkeyword _if if
changeringkeyword _for for
changeringkeyword _but but
changeringkeyword _see see
changeringoperator _- -
changeringoperator _( (
changeringoperator _) )

class natural	 count hello  from              
	func BraceError
	func GetHello   see  "Hello, Mahmoud!" +nl  +nl
	func Getcount ;  nCmd = 1    func getfrom ; nCmd = 2
	func BraceExprEval nValue
		if isNumber(nValue)		{
			nExpr++     aExpr + nValue
			if nExpr = 2 {
				if aExpr[1] > aExpr[2]  { nStep = -1 else nStep = 1}
				if nTime = 0 { see nl+"The Numbers!" + nl nTime++ 
				else see nl + "I will count Again!" +nl }
				for x = aExpr[1] to aExpr[2]  step nStep { see Nl+x+nl }
				aExpr = []   	nExpr = 0
			}
		}
	private nCmd = 0  nExpr = 0   aExpr = []  nTime = 0
