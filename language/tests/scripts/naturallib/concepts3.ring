load "stdlibcore.ring"
load "naturallib.ring"

DefineNaturalCommand {
	startCache(:MyDSL)
	setPackageName("MyLanguage.Natural")
	SyntaxIsKeywordExpressions([
		:keyword = "replace", 
		:Function = func {
			? Expr(1) + " ===> " + Expr(2)
		}
	],2)

	// Ignore the WITH keyword 
	SyntaxIskeyword([
		:keyword = "with", 
		:Function = func {
			return :NLNV
		}
	])

	endCache()
}

MyLang = New NaturalLanguage {
	SetPackageName("MyLanguage.Natural")
	SetLanguageName(:MyLanguage)
	loadCommand(:MyDSL)
}

new MyLanguage {

	# replace <identifier> [WITH] <value>

	# Using WITH
	Replace name with "Ring"
	Replace year with 2016
	Replace age  with 10

	Replace name with "Python"
	Replace year with 1990
	Replace age  with 35

	# Without using WITH
	Replace name "C"
	Replace year 1972
	Replace age  53

}
