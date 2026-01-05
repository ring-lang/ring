load "stdlibcore.ring"
load "naturallib.ring"

DefineNaturalCommand {
	startCache(:MyDSL)
	setPackageName("MyLanguage.Natural")
	syntaxIsKeywordExpressions([
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

MyLang = new NaturalLanguage {
	setLanguageName(:MyLanguage)
	setPackageName("MyLanguage.Natural")
	loadCommand(:MyDSL)
	setMaskKeywords(False)
	setMaskOperators(False)
}

MyLang.execute(`

	aLangs = [	[:name = "C",:year = 1972, :age = 2026-1972],
				[:name = "Python",:year = 1990, :age = 2026-1990],
				[:name = "Ring",:year = 2016,:age = 2026-2016]  ]

	for aLang in aLangs 
		Replace name with aLang[:Name]
		Replace year with aLang[:Year]
		Replace age  with aLang[:Age]
	next

`)
