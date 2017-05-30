# The Ring Natural Library
# 2017, Mahmoud Fayed <msfclipper@yahoo.com>

class NaturalLanguage

	cLanguageName = ""
	setLanguageName(:Natural)
	cCommandsPath = "../ringlibs/naturallib/command"
	cPackageName = ""

	func SetLanguageName cName
		if cLanguageName != cName {
			cLanguageName = cName
			cCode = "class #{langname} from NaturalBase"
			cCode = substr(cCode,"#{langname}",cLanguageName)
			eval(cCode)
		}

	func SetCommandsPath cPath
		cCommandsPath = cPath

	func SetPackageName cName
		cPackageName = cName

	func RunFile cFile
		if not fexists(cFile) {
			raise("Error (NaturalLib-1) : Can't open the file :"+cFile)
		}
		RunString(read(cFile))

	func RunString cString
		cCode = '
		loadsyntax "#{libpath}/syntax/naturalsyntaxon.ring"
		Talk #{langname} {
			#{naturalcode}
		}
		loadsyntax "#{libpath}/syntax/naturalsyntaxoff.ring"
		'
		cCode = substr(cCode,"#{libpath}",cLibraryPath)
		cCode = substr(cCode,"#{langname}",cLanguageName)
		cCode = substr(cCode,"#{naturalcode}",cString)
		eval(cCode)

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

	private 

		cLibraryPath = "../ringlibs/naturallib"		
