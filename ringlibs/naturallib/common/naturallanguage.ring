# The Ring Natural Library
# 2017, Mahmoud Fayed <msfclipper@yahoo.com>

class NaturalLanguage

	cLibraryPath = "../ringlibs/naturallib"
	cLanguageName = ""
	setLanguageName(:Natural)

	func SetLanguageName cName
		if cLanguageName != cName {
			cLanguageName = cName
			cCode = "class #{langname} from NaturalBase"
			cCode = substr(cCode,"#{langname}",cLanguageName)
			eval(cCode)
		}

	func RunFile cFile
		if not fexists(cFile) {
			raise("Error (NaturalLib-1) : Can't open the file :"+cFile)
		}
		cCode = '
		loadsyntax "#{libpath}/syntax/naturalsyntaxon.ring"
		Talk #{langname} {
			#{naturalcode}
		}
		loadsyntax "#{libpath}/syntax/naturalsyntaxoff.ring"
		'
		cCode = substr(cCode,"#{libpath}",cLibraryPath)
		cCode = substr(cCode,"#{langname}",cLanguageName)
		cCode = substr(cCode,"#{naturalcode}",read(cFile))
		eval(cCode)

	func UseCommand cCommand
		cCode = `load "#{libpath}/command/natural_#{command}.ring"`
		cCode = substr(cCode,"#{libpath}",cLibraryPath)
		cCode = substr(cCode,"#{command}",cCommand)
		eval(cCode)
		mergemethods(cLanguageName,cCommand)

class NaturalCommand
