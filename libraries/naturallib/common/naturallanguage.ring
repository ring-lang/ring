# The Ring Natural Library
# 2017, Mahmoud Fayed <msfclipper@yahoo.com>

class NaturalLanguage

	cLanguageName = ""
	setLanguageName(:Natural)
	cCommandsPath = "../libraries/naturallib/command"
	cPackageName = ""
	cOperators = ""

	func SetLanguageName cName
		if cLanguageName != cName {
			cLanguageName = cName
			cCode = "class #{langname} from NaturalBase"
			cCode = substr(cCode,"#{langname}",cLanguageName)
			eval(cCode)
		}

	func SetCommandsPath cPath
		cPath = substr(cPath,CurrentDir()+"/","")
		cCommandsPath = cPath

	func SetPackageName cName
		cPackageName = cName

	func RunFile cFile
		if not fexists(cFile) {
			raise("Error (NaturalLib-1) : Can't open the file :"+cFile)
		}
		cCode = read(cFile)
		cCode = CheckOperators(cCode)
		RunString(cCode)

	func RunString cString
		cCode = '
		loadsyntax "#{libpath}/syntax/naturalsyntaxon.ring"
		Talk #{langname} {
			CHANGERINGOPERATOR { _{
			CHANGERINGOPERATOR } _}
			#{naturalcode}
			CHANGERINGOPERATOR _{ {
			CHANGERINGOPERATOR _} }
		}
		loadsyntax "#{libpath}/syntax/naturalsyntaxoff.ring"
		'
		cCode = substr(cCode,"#{libpath}",cLibraryPath)
		cCode = substr(cCode,"#{langname}",cLanguageName)
		cCode = substr(cCode,"#{naturalcode}",cString)
		cCode = CheckOperators(cCode)
		eval(cCode)

	func Execute cString
		runstring(cString)

	func CheckOperators cCode 
		if len(cOperators) > 0 {
			for cLetter in cOperators {
				cCode = substr(cCode,cLetter, " " + cLetter + " ")
			}
		}
		return cCode

	func UseCommand cCommand
		cCommandFile = cCommandsPath+"/"+cCommand+".ring"
		if not fexists(cCommandFile) and not fexists(exefolder()+cCommandFile) {
			raise("Error (NaturalLib) : Can't open the command file : " + cCommandFile)
		}
		cCode = `load "#{commandfile}"`
		cCode = substr(cCode,"#{commandfile}",cCommandFile)
		eval(cCode)
		if not cPackageName = NULL {
			cCode = "import " + cPackageName 
			eval(cCode)
		}
		mergemethods(cLanguageName,cCommand)

	func SetOperators Operators
		cOperators = Operators

	private 

		cLibraryPath = "../libraries/naturallib"		
