load "stdlibcore.ring"
load "naturallib.ring"

func main 

	defineDSL()
	testDSL()

func defineDSL 

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
	
	new NaturalLanguage {
		setLanguageName(:MyLanguage)
		setPackageName("MyLanguage.Natural")
		loadCommand(:MyDSL)
	}

func testDSL

	# Define aLangs as local variable 

	aLangs = [	[:name = "C",:year = 1972, :age = 2026-1972],
				[:name = "Python",:year = 1990, :age = 2026-1990],
				[:name = "Ring",:year = 2016,:age = 2026-2016]  ]

	# Using our DSL object inside braces enables sharing the local scope

	new MyLanguage {

		for aLang in aLangs 
			Replace name with aLang[:Name]
			Replace year with aLang[:Year]
			Replace age  with aLang[:Age]
		next

	}
