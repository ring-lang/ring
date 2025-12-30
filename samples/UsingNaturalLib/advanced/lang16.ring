load "stdlibcore.ring"
load "naturallib.ring"

DefineNaturalCommand {
	startCache(:MyDSL)
	setPackage("MyLanguage.Natural")
	SyntaxIsKeywordExpressionExpression([
		:Keyword = "@", 
		:Function = func {
			?  "Command: @ x,y" 
			?  "Position: (" + Expr(1) + "," + Expr(2) + ")"
		}
	])

	endCache()
}

MyLang = New NaturalLanguage {
	SetLanguageName(:MyLanguage)
	SetPackageName("MyLanguage.Natural")
	loadCommand(:MyDSL)
}

new MyLanguage {

	@10,10
	@15,10
	@20,20
	@x,y
	@x,100
	@100,x
 
	? copy("=",20)

	@ 10,10
	@ 15,10
	@ 20,20
	@ x,y
	@ x,100
	@ 100,x

	? copy("=",20)
	x = 100
	y = 200
	@ x,y

	x = 1000				# x is a variable defined in this scope 
	y = 2000
	@x,y					# We don't use a space between @ and x

	@m,n					# m,n are variables (not defined)

}
