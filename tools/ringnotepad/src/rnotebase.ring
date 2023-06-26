# The Ring Notepad Application (RNote)
# Author : Mahmoud Fayed <msfclipper@yahoo.com>

class RNoteControllerBase from WindowsControllerParent 

	cActiveFileName 	= ""

	aTextColor 		= [0,0,0]
	aBackColor 		= [255,255,255]

	cFont 			= 'Consolas,16,-1,5,50,0,0,0,0,0'
	oTFont 			= new qfont("",0,0,0)
	lSetProjectFilesFont	= True

	cWebsite 		= "http://ring-lang.github.io/doc1.16/index.html"

	cCurrentDir 		= CurrentDir() + "/"	# The Ring Notepad Folder
	cStartUpFolder 		= exefolder() + "/../applications/"
	cRingEXE 		= exefilename()

	lShowProject 		= True
	lShowSourceCode 	= True
	lShowBrowser 		= True
	lShowFunctionsList 	= True
	lShowOutputWindow 	= True
	lShowClassesList 	= True
	lShowFormDesigner 	= True

	nTabSpaces 		= 8

	aBrowserLinks 		= [
		[T_RINGNOTEPAD_BROWSERLOCALHELP, "file:///"+substr(exefolder(),"\","/") + "../documents/build/html/index.html"],
		[T_RINGNOTEPAD_BROWSERRINGWEBSITE,"http://ring-lang.github.io"],
		[T_RINGNOTEPAD_BRWOSERRINGSAMPLES,"https://rosettacode.org/wiki/Category:Ring"],
		[T_RINGNOTEPAD_BROWSERRINGRESOURCES,"http://ring-lang.github.io/resources.html"],
		[T_RINGNOTEPAD_BROWSERRINGSOURCECODE,"https://github.com/ring-lang/ring"],
		[T_RINGNOTEPAD_BROWSERRINGTEAM,"http://ring-lang.github.io/team.html"]
	]

	# Define Colors
		colordarkBlue   	= new qcolor() { setrgb(0,0,128,255) }
		colordarkMagenta 	= new qcolor() { setrgb(128,0,128,255) }
		colorRed    		= new qcolor() { setrgb(255,000,000,255) }
		colorDarkGreen  	= new qcolor() { setrgb(000,128,000,255) }
		colorGreen	  	= new qcolor() { setrgb(000,255,000,255) }
		colorBlue   		= new qcolor() { setrgb(000,000,255,255) }
		colorCyan   		= new qcolor() { setrgb(000,255,255,255) }
		colorWhite  		= new qColor() { setrgb(255,255,255,255) }
		colorBlack  		= new qColor() { setrgb(0,0,0,255) }
		colorSilver 		= new qColor() { setrgb(128,128,128,255) }
		colorPurple 		= new qColor() { setrgb(128,0,128,255) }
		colordarkBlue2   	= new qcolor() { setrgb(0,0,100,255) }

	# Default Editor Style Colors
		aStyleColors = [
			:LineNumbersAreaColor 		= colorBlack ,
			:LineNumbersAreaBackColor 	= colorCyan,
			:ActiveLineBackColor 		= colorCyan,
			:SyntaxKeywordsColor		= colordarkBlue,
			:SyntaxClassNamesColor 		= ColordarkMagenta,
			:SyntaxCommentsColor 		= ColorRed,
			:SyntaxLiteralsColor 		= ColorDarkGreen,
			:SyntaxFunctionCallsColor 	= ColorBlue
		]

	# Default Style 
		STYLECOLOR_WINDOWS 			= 0
		STYLECOLOR_WHITE 			= 1
		STYLECOLOR_BLUE 			= 2
		STYLECOLOR_BLACK 			= 3
		STYLECOLOR_MODERN 			= 4
		STYLECOLOR_MODERNBLACK 			= 5
		STYLECOLOR_MODERNBLACK2 		= 6
		STYLECOLOR_NOTEPADWHITE 		= 7
		STYLECOLOR_NOTEPADPURPLE 		= 8
		STYLECOLOR_NOTEPADDARKBLUE 		= 9
		STYLECOLOR_NOTEPADBLACK 		= 10
		STYLECOLOR_ART		 		= 11
		STYLECOLOR_ART2		 		= 12
		STYLECOLOR_ART3		 		= 13
		STYLECOLOR_IMAGE	 		= 14
		STYLECOLOR_IMAGE2	 		= 15
		nDefaultStyle  				= STYLECOLOR_IMAGE2
		lKeywordsBold 				= True

	# Default Mode
		VIEWMODE_GENERAL 			= 1
		VIEWMODE_LEARNINGRING			= 2
		VIEWMODE_CODING				= 3
		VIEWMODE_CODING2			= 4
		VIEWMODE_CODING3			= 5
		VIEWMODE_GUIDEV				= 6
		VIEWMODE_WEBDEV				= 7
		VIEWMODE_TESTING			= 8
		VIEWMODE_COMMON				= 9
		nDefaultMode				= VIEWMODE_CODING2

	# Search and Replace 
		oSearch oSearchValue oSearchCase oSearchFilter oReplaceValue 	
		cSearchText	= NULL 
		cReplaceText	= NULL	

	# Ask to save before switching to another file 
		lAskToSave 	= false
		cTextHash	= sha256("")

	# Hash Table contains the File Name and the Line Number
	# Used to remember the current line when we switch between many files
		aFilesLines 	= []	

	# For Auto-Complete
		oAutoCompleteList  
		nAutoCompleteListSize 	= 0
		oACTimer=NULL			# Auto-Complete Timer 
		oCompleter=NULL 		# The completer object

	# Main Window 
		oApp oDesktop win1 oFilter aBtns tool1 menu1 status1
		tool2 oTxtMainFile
		Tree1 filestabs TextEdit1 
		oDockProjectFiles oDockSourceCode oDockWebBrowser 
		oDockFunctionsList oDockOutputWindow oDockClassesList oDockFormDesigner
		oWebBrowser oWebView  oWBText 
		oFile oFunctionsList oClassesList
		oOutputWindow oProcessEditbox oProcessText oProcess
	
	# Functions list & Classes List
		aFunctionsPos aClassesPos

	# Active Form 
		cFormFile = ""

	# Methods (For the Output Window)
		cGetProcessData = Method(:GetProcessData)

	# Web Applications 
		cWebApplicationFolder = ""

	# Settings 
		cSettingsFile 	= cCurrentDir + "ringnotepad.ini"

	# Editbox FullScreen Mode 
		lEditboxFullScreen = False 
		oFilterTextEdit 
		oTabsAndText
		oLayoutTabsText

	# Dialogs
		oFontDialog

	# Apperance menu 
		oCheckAction1 oCheckAction2 oCheckAction3 oCheckAction4
		oCheckAction5 oCheckAction6 oCheckAction7
