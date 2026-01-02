load "stdlibcore.ring"
load "naturallib.ring"

DefineNaturalCommand {
	startCache(:MyDSL)
	setPackageName("MyLanguage.Natural")
	SyntaxIsKeywordExpressions([
		:keyword = "replace", 
		:Function = func {
			if ! ( isIdentifier(2) && lower(Expr(2)) = :with ) {
				? "WITH keyword is missing!"
				return 
			}
			? Expr(1) + " ===> " + Expr(3)
		}
	],3)

	endCache()
}

MyLang = New NaturalLanguage {
	SetPackageName("MyLanguage.Natural")
	SetLanguageName(:MyLanguage)
	loadCommand(:MyDSL)
}

new MyLanguage {

	# replace <identifier> WITH <value>

	Replace name with "C"
	Replace year with 1972
	Replace age  with 2025-1972

	Replace name with "Python"
	Replace year with 1990
	Replace age  with 2025-1990

}
