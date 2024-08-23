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

	For example When we say Hello to the Machine, It can reply! and when we
	say count from 1 to 5 it will understand us, Also if we said count from 5 to 1 it will
	understand us too! You can see the Output window!

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
