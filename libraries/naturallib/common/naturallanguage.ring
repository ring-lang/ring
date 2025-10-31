# The Ring Natural Library
# 2017-2025, Mahmoud Fayed <msfclipper@yahoo.com>

class NaturalLanguage

	cLanguageName = ""
	setLanguageName(:Natural)
	cCommandsPath = "../libraries/naturallib/command"
	cPackageName = ""
	cOperators = ""
	oLangObj = NULL

	func SetLanguageName cName
		if cLanguageName != cName {
			cLanguageName = cName
			cCode = "class #{langname} from NaturalBase"+nl
			cCode = substr(cCode,"#{langname}",cLanguageName)
			eval(cCode)
			mergemethods(cLanguageName,:NaturalBaseMethods)
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

	func prepareLanguage
		if ! oLangObj {
			oLangObj = new from cLanguageName
		}

	func RunString cString
		prepareLanguage()
		cCode = '
		oLangObj {
			loadsyntax "#{libpath}/syntax/naturalsyntaxon.ring"
			CHANGERINGOPERATOR { _{
			CHANGERINGOPERATOR } _}
			#{naturalcode}
			CHANGERINGOPERATOR _{ {
			CHANGERINGOPERATOR _} }
			loadsyntax "#{libpath}/syntax/naturalsyntaxoff.ring"
		}
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
		loadCommand(cCommand)

	func loadCommand cCommand 
		cSourceClassName = cCommand
		if not cPackageName = NULL {
			cSourceClassName = lower(cPackageName+"."+ cCommand)
		}
		oObject = new from cSourceClassName
		if oObject.lSyntaxIsKeyword {
			addMethod(oObject,"Get"+cCommand,oObject.fFunc)
		else
			addMethod(oObject,"BraceExecute_"+cCommand,oObject.fFunc)
		}
		mergemethods(cLanguageName,cSourceClassName)


	func SetOperators Operators
		cOperators = Operators

	private 

		cLibraryPath = "../libraries/naturallib"		
