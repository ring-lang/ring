# The Ring Natural Library
# 2017-2025, Mahmoud Fayed <msfclipper@yahoo.com>

class NaturalLanguage

	cLanguageName = ""
	setLanguageName(:Natural)
	cCommandsPath = "../libraries/naturallib/command"
	cPackageName = ""
	cOperators = ""
	oLangObj = NULL
	cBeforeRun = ""
	cAfterRun = ""
	cStartKeywordsWith = "_"
	lMaskOperators = True

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
			eval("oLangObj = new " + cLanguageName)
		}
		if ! cBeforeRun {
			cBeforeRun = `
			changeringkeyword again 		_again
			changeringkeyword and  			_and
			changeringkeyword but 			_but
			changeringkeyword bye 			_bye
			changeringkeyword call 			_call
			changeringkeyword case 			_case
			changeringkeyword catch 		_catch
			changeringkeyword class 		_class
			changeringkeyword def 			_def
			changeringkeyword do 			_do
			changeringkeyword done 			_done
			changeringkeyword else 			_else
			changeringkeyword elseif 		_elseif
			changeringkeyword end 			_end
			changeringkeyword exit 			_exit
			changeringkeyword for 			_for
			changeringkeyword from 			_from
			changeringkeyword func 			_func
			changeringkeyword get 			_get
			changeringkeyword give 			_give
			changeringkeyword if 			_if
			changeringkeyword import 		_import
			changeringkeyword in 			_in
			changeringkeyword load 			_load
			changeringkeyword loop 			_loop
			changeringkeyword new 			_new
			changeringkeyword next 			_next
			changeringkeyword not 			_not
			changeringkeyword off 			_off
			changeringkeyword ok 			_ok
			changeringkeyword on 			_on
			changeringkeyword or 			_or
			changeringkeyword other 		_other
			changeringkeyword package 		_package
			changeringkeyword private 		_private
			changeringkeyword put 			_put
			changeringkeyword return 		_return
			changeringkeyword see 			_see
			changeringkeyword step 			_step
			changeringkeyword switch 		_switch
			changeringkeyword to 			_to
			changeringkeyword try 			_try
			changeringkeyword while 		_while
			`

			if lMaskOperators {
			cBeforeRun += `
			changeringoperator +			_+
			changeringoperator -			_-
			changeringoperator *			_*
			changeringoperator /			_/
			changeringoperator %			_%
			changeringoperator =			_=
			changeringoperator !			_!
			changeringoperator <			_<
			changeringoperator >			_>
			changeringoperator &			_&
			changeringoperator |			_|
			changeringoperator ^			_^
			changeringoperator ~			_~
			changeringoperator :			_:
			changeringoperator [			_[
			changeringoperator ]			_]
			changeringoperator (			_(
			changeringoperator )			_)
			changeringoperator .			_.
			changeringoperator ,			_,
			changeringoperator { 			_{
			changeringoperator } 			_}
			`
			}
		}
		if ! cAfterRun {
			cAfterRun  = `
			changeringkeyword _again 		again
			changeringkeyword _and  		and
			changeringkeyword _but 			but
			changeringkeyword _bye 			bye
			changeringkeyword _call 		call
			changeringkeyword _case 		case
			changeringkeyword _catch 		catch
			changeringkeyword _class 		class
			changeringkeyword _def 			def
			changeringkeyword _do 			do
			changeringkeyword _done 		done
			changeringkeyword _else 		else
			changeringkeyword _elseif 		elseif
			changeringkeyword _end 			end
			changeringkeyword _exit 		exit
			changeringkeyword _for 			for
			changeringkeyword _from 		from
			changeringkeyword _func 		func
			changeringkeyword _get 			get
			changeringkeyword _give 		give
			changeringkeyword _if 			if
			changeringkeyword _import 		import
			changeringkeyword _in 			in
			changeringkeyword _load 		load
			changeringkeyword _loop 		loop
			changeringkeyword _new 			new
			changeringkeyword _next 		next
			changeringkeyword _not 			not
			changeringkeyword _off 			off
			changeringkeyword _ok 			ok
			changeringkeyword _on 			on
			changeringkeyword _or 			or
			changeringkeyword _other 		other
			changeringkeyword _package 		package
			changeringkeyword _private 		private
			changeringkeyword _put 			put
			changeringkeyword _return 		return
			changeringkeyword _see 			see
			changeringkeyword _step 		step
			changeringkeyword _switch 		switch
			changeringkeyword _to 			to
			changeringkeyword _try 			try
			changeringkeyword _while 		while
			`
			if lMaskOperators {
			cAfterRun += `
			changeringoperator _+			+
			changeringoperator _-			-
			changeringoperator _*			*
			changeringoperator _/			/
			changeringoperator _%			%
			changeringoperator _=			=
			changeringoperator _!			!
			changeringoperator _<			<
			changeringoperator _>			>
			changeringoperator _&			&
			changeringoperator _|			|
			changeringoperator _^			^
			changeringoperator _~			~
			changeringoperator _:			:
			changeringoperator _[			[
			changeringoperator _]			]
			changeringoperator _(			(
			changeringoperator _)			)
			changeringoperator _.			.
			changeringoperator _,			,
			changeringoperator _{ 			{
			changeringoperator _} 			}
			`
			}
		}
		if cStartKeywordsWith != "_" {
			cBeforeRun = substr(cBeforeRun,"_",cStartKeywordsWith)
			cAfterRun = substr(cAfterRun,"_",cStartKeywordsWith)
		}

	func prepareCode cString 
		prepareLanguage()
		cString = CheckOperators(cString)
		cCode = 'oLangObj {'+nl+
			cBeforeRun+nl+
			cString+nl+
			cAfterRun+nl+'}'
		return cCode 

	func RunString cString
		eval(prepareCode(cString))

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
		cCommand = substr(cCommand," ","")
		cCommandFile = cCommandsPath+"/"+cCommand+".ring"
		if not fexists(cCommandFile) and not fexists(exefolder()+cCommandFile) {
			raise("Error (NaturalLib) : Can't open the command file : " + cCommandFile)
		}
		cCode = `load "#{commandfile}"`
		cCode = substr(cCode,"#{commandfile}",cCommandFile)
		eval(cCode)
		loadCommand(cCommand)

	func loadCommand cCommand 
		cCommand = substr(cCommand," ","")
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

	func setBeforeRun cCode 
		cBeforeRun = cCode 

	func setAfterRun cCode 
		cAfterRun = cCode

	func setStartKeywordsWith cStart 
		cStartKeywordsWith = cStart

	func setMaskOperators lMask	
		lMaskOperators = lMask

	func getBeforeRun  
		return cBeforeRun

	func getAfterRun  
		return cAfterRun

	func getStartKeywordsWith  
		return cStartKeywordsWith

	func getMaskOperators 	
		return lMaskOperators


	private 

		cLibraryPath = "../libraries/naturallib"		
