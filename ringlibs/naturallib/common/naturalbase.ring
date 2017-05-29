# The Ring Natural Library
# 2017, Mahmoud Fayed <msfclipper@yahoo.com>

class NaturalProgram

	cLibraryPath = "../ringlibs/naturallib"

	func RunFile cFile
		cCode = '
		loadsyntax "#{libpath}/syntax/naturalsyntaxon.ring"
		Talk Natural {
			#{naturalcode}
		}
		loadsyntax "#{libpath}/syntax/naturalsyntaxoff.ring"
		'
		cCode = substr(cCode,"#{libpath}",cLibraryPath)
		cCode = substr(cCode,"#{naturalcode}",read(cFile))
		eval(cCode)

	func UseCommand cCommand
		cCode = `load "#{libpath}/command/natural_#{command}.ring"`
		cCode = substr(cCode,"#{libpath}",cLibraryPath)
		cCode = substr(cCode,"#{command}",cCommand)
		eval(cCode)
		mergemethods(:natural,:natural_ + cCommand)


class Natural from NaturalBase

class NaturalCommand

Class NaturalBase

	func BraceStart
		aMethods = methods(self)	
		for cMethod in aMethods {
			if left(cMethod,14) = "addattributes_" {
				eval(cMethod+"()")
			}
		}

	func BraceExprEval Value
		aMethods = methods(self)	
		for cMethod in aMethods {
			if left(cMethod,14) = "braceexpreval_" {
				if isNumber(Value) {
					eval(cMethod+"("+Value+")")
				elseif isString(Value) 
					eval(cMethod+"('"+Value+"')")
				}
			}
		}

	func BraceError
