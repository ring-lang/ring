# The Ring Notepad Application (RNote)
# Author : Mahmoud Fayed <msfclipper@yahoo.com>

class RNoteStyle

	func CheckCustomColors
		if True	# Switch to Use the Style or Not
			SelectStyleColor(nDefaultStyle)
			LoadSettings()
		ok

	func SetActiveLineColor
		textedit1.SetActiveLineColor(aStyleColors[:ActiveLineBackColor])

	func SetStyleColor(nStyle)
		SelectStyleColor(nStyle)
		RestoreSettings()
		SetEditorColors()

	func SelectStyleColor nStyle
		switch nStyle
		on 0 StyleWindows()
		on 1 StyleWhite()
		on 2 StyleBlue()
		on 3 StyleBlack()
		on 4 StyleModern()
		on 5 StyleModernBlack()
		on 6 StyleModernBlack2()
		on 7 StyleNotepadWhite()
		on 8 StyleNotepadPurple()
		on 9 StyleNotepadDarkBlue()
		on 10 StyleNotepadBlack()
		on 11 StyleArt()
		on 12 StyleArt2()
		on 13 StyleArt3()
		on 14 StyleImage()
		on 15 StyleImage2()
		off
		if nStyle >= 7 
			lKeywordsBold = False 
		else
			lKeywordsBold = True
		ok

	func SelectStyleColor2 nStyle
		for oObj in [this.tree1,this.oFunctionsList,this.oClassesList,this.oOutputWindow] 
			oObj {
				setstylesheet("")
			}
		next
		if nStyle = STYLECOLOR_ART or nStyle = STYLECOLOR_ART2
			StyleArt_AfterControls()
		but nStyle = STYLECOLOR_IMAGE 
			StyleImage_AfterControls(1)
		but nStyle = STYLECOLOR_IMAGE2 
			StyleImage_AfterControls(2)
		ok

	func SetEditorColors
		textedit1.setLineNumbersAreaColor(aStyleColors[:LineNumbersAreaColor])
		textedit1.setLineNumbersAreaBackColor(aStyleColors[:LineNumbersAreaBackColor])
		ApplySyntaxColors()

	func StyleBlue()
			nDefaultStyle  = STYLECOLOR_BLUE
			aCustomStyleColors = [
				:LineNumbersAreaColor 		= colorWhite,
				:LineNumbersAreaBackColor 	= colorDarkBlue,
				:ActiveLineBackColor 		= colorDarkBlue2,
				:SyntaxKeywordsColor		= colorWhite,
				:SyntaxClassNamesColor 		= colorWhite,
				:SyntaxCommentsColor 		= colorWhite,
				:SyntaxLiteralsColor 		= colorWhite,
				:SyntaxFunctionCallsColor 	= colorWhite
			]
			aStyleColors = aCustomStyleColors
			aTextColor = [255,255,255]
			aBackColor = [0,0,167]
			oApp.StylefusionCustom(
				new qColor() { setrgb(0,0,167,255) },
				new qColor() { setrgb(255,255,255,255) },
				new qColor() { setrgb(0,0,167,255) },
				new qColor() { setrgb(0,0,167,255) },
				new qColor() { setrgb(255,255,255,255) },
				new qColor() { setrgb(255,255,255,255) },
				new qColor() { setrgb(255,255,255,255) },
				new qColor() { setrgb(0,0,167,255) },
				new qColor() { setrgb(255,255,255,255) },
				new qColor() { setrgb(255,0,0,255) },
				new qColor() { setrgb(0,0,132,255) },
				new qColor() { setrgb(255,255,255,255)}
			)

	func StyleBlack()
			nDefaultStyle  = STYLECOLOR_BLACK
			oApp.StyleFusionBlack()
			aCustomStyleColors = [
				:LineNumbersAreaColor 		= colorWhite ,
				:LineNumbersAreaBackColor 	= colorBlack,
				:ActiveLineBackColor 		= colorBlack,
				:SyntaxKeywordsColor		= colorWhite,
				:SyntaxClassNamesColor 		= ColorWhite,
				:SyntaxCommentsColor 		= ColorSilver,
				:SyntaxLiteralsColor 		= ColorCyan,
				:SyntaxFunctionCallsColor 	= ColorGreen
			]
			aStyleColors = aCustomStyleColors
			aTextColor = [255,255,255]
			aBackColor = [0,0,0]

	func StyleWhite()
			nDefaultStyle  = STYLECOLOR_WHITE 
			oApp.StyleFusion()
			StyleWhiteColors()

	func StyleWhiteColors
			aCustomStyleColors = [
				:LineNumbersAreaColor 		= colorBlack ,
				:LineNumbersAreaBackColor 	= colorCyan,
				:ActiveLineBackColor 		= colorCyan,
				:SyntaxKeywordsColor		= colordarkBlue,
				:SyntaxClassNamesColor 		= ColordarkMagenta,
				:SyntaxCommentsColor 		= ColorSilver,
				:SyntaxLiteralsColor 		= ColorDarkGreen,
				:SyntaxFunctionCallsColor 	= ColorBlue
			]
			aStyleColors = aCustomStyleColors
			aTextColor = [0,0,0]
			aBackColor = [255,255,255]

	func StyleWindows
			nDefaultStyle  = STYLECOLOR_WINDOWS
			if isWindows()
				oApp.StyleWindowsVista()
			else 
				oApp.StyleWindows()
			ok
			StyleWhiteColors()

	func StyleModern()
			nDefaultStyle  = STYLECOLOR_MODERN
			aCustomStyleColors = [
				:LineNumbersAreaColor 		= new qcolor() { setrgb(143,144,138,255) },
				:LineNumbersAreaBackColor 	= new qcolor() { setrgb(39,60,64,255) },
				:ActiveLineBackColor 		= new qcolor() { setrgb(39,110,114,255) },
				:SyntaxKeywordsColor		= new qcolor() { setrgb(80,187,177,255) },
				:SyntaxClassNamesColor 		= new qcolor() { setrgb(166,226,46,255) },
				:SyntaxCommentsColor 		= new qcolor() { setrgb(117,160,172,157) },
				:SyntaxLiteralsColor 		= new qcolor() { setrgb(230,191,77,255) },
				:SyntaxFunctionCallsColor 	= new qcolor() { setrgb(240,127,224,255) }
			]
			aStyleColors = aCustomStyleColors
			aTextColor = [248,248,242]
			aBackColor = [39,60,64]
			oApp.StylefusionCustom(
				new qColor() { setrgb(39,60,64,255) 	},
				new qColor() { setrgb(255,255,255,255) 	},
				new qColor() { setrgb(39,60,64,255) 	},
				new qColor() { setrgb(39,60,64,255) 	},
				new qColor() { setrgb(255,255,255,255) 	},
				new qColor() { setrgb(255,255,255,255) 	},
				new qColor() { setrgb(255,255,255,255) 	},
				new qColor() { setrgb(39,60,64,255) 	},
				new qColor() { setrgb(255,255,255,255) 	},
				new qColor() { setrgb(255,0,0,255) 	},
				new qColor() { setrgb(142,45,197,255) 	},
				new qColor() { setrgb(39,60,64,255)	}
			)

	func StyleModernBlack()
			nDefaultStyle  = STYLECOLOR_MODERNBLACK
			oApp.StyleFusionBlack()
			aCustomStyleColors = [
				:LineNumbersAreaColor 		= new qcolor() { setrgb(255,255,255,255)},
				:LineNumbersAreaBackColor 	= new qcolor() { setrgb(0,0,0,255) 	},
				:ActiveLineBackColor 		= new qcolor() { setrgb(0,0,0,255) 	},
				:SyntaxKeywordsColor		= new qcolor() { setrgb(30,220,175,255) },
				:SyntaxClassNamesColor 		= new qcolor() { setrgb(166,226,46,255) },
				:SyntaxCommentsColor		= new qcolor() { setrgb(117,160,172,157)},
				:SyntaxLiteralsColor 		= new qcolor() { setrgb(230,191,77,255) },
				:SyntaxFunctionCallsColor 	= new qcolor() { setrgb(240,127,224,255)}
			]
			aStyleColors = aCustomStyleColors
			aTextColor = [255,255,255]
			aBackColor = [33,33,33]

	func StyleModernBlack2()
			nDefaultStyle  = STYLECOLOR_MODERNBLACK2
			oApp.StyleFusionBlack()
			aCustomStyleColors = [
				:LineNumbersAreaColor 		= new qcolor() { setrgb(255,255,255,255)},
				:LineNumbersAreaBackColor 	= new qcolor() { setrgb(0,0,0,255) 	},
				:ActiveLineBackColor 		= new qcolor() { setrgb(33,33,33,255) 	},
				:SyntaxKeywordsColor		= new qcolor() { setrgb(30,220,175,255) },
				:SyntaxClassNamesColor 		= new qcolor() { setrgb(166,226,46,255) },
				:SyntaxCommentsColor		= new qcolor() { setrgb(117,160,172,157)},
				:SyntaxLiteralsColor 		= new qcolor() { setrgb(230,191,77,255) },
				:SyntaxFunctionCallsColor 	= new qcolor() { setrgb(240,127,224,255)}
			]
			aStyleColors = aCustomStyleColors
			aTextColor = [255,255,255]
			aBackColor = [0,0,0]

	func StyleNotepadWhite()
			nDefaultStyle  = STYLECOLOR_NOTEPADWHITE
			oApp.StyleFusion()
			aCustomStyleColors = [
				:LineNumbersAreaColor 		= colorBlack ,
				:LineNumbersAreaBackColor 	= colorWhite,
				:ActiveLineBackColor 		= colorWhite,
				:SyntaxKeywordsColor		= colorBlack,
				:SyntaxClassNamesColor 		= ColorBlack,
				:SyntaxCommentsColor 		= ColorBlack,
				:SyntaxLiteralsColor 		= ColorBlack,
				:SyntaxFunctionCallsColor 	= ColorBlack
			]
			aStyleColors = aCustomStyleColors
			aTextColor = [0,0,0]
			aBackColor = [255,255,255]

	func StyleNotepadPurple()
			nDefaultStyle  = STYLECOLOR_NOTEPADPURPLE
			oApp.StyleFusion()
			aCustomStyleColors = [
				:LineNumbersAreaColor 		= colorWhite ,
				:LineNumbersAreaBackColor 	= colorPurple,
				:ActiveLineBackColor 		= colorPurple,
				:SyntaxKeywordsColor		= colorWhite,
				:SyntaxClassNamesColor 		= ColorWhite,
				:SyntaxCommentsColor 		= ColorWhite,
				:SyntaxLiteralsColor 		= ColorWhite,
				:SyntaxFunctionCallsColor 	= ColorWhite
			]
			aStyleColors = aCustomStyleColors
			aTextColor = [255,255,255]
			aBackColor = [128,0,128]

	func StyleNotepadDarkBlue()
			nDefaultStyle  = STYLECOLOR_NOTEPADDARKBLUE
			oApp.StyleFusion()
			aCustomStyleColors = [
				:LineNumbersAreaColor 		= colorWhite ,
				:LineNumbersAreaBackColor 	= colordarkBlue,
				:ActiveLineBackColor 		= colordarkBlue,
				:SyntaxKeywordsColor		= colorWhite,
				:SyntaxClassNamesColor 		= ColorWhite,
				:SyntaxCommentsColor 		= ColorWhite,
				:SyntaxLiteralsColor 		= ColorWhite,
				:SyntaxFunctionCallsColor 	= ColorWhite
			]
			aStyleColors = aCustomStyleColors
			aTextColor = [255,255,255]
			aBackColor = [0,0,128]

	func StyleNotepadBlack()
			nDefaultStyle  = STYLECOLOR_NOTEPADBLACK
			oApp.StyleFusion()
			aCustomStyleColors = [
				:LineNumbersAreaColor 		= colorWhite ,
				:LineNumbersAreaBackColor 	= colorBlack,
				:ActiveLineBackColor 		= colorBlack,
				:SyntaxKeywordsColor		= colorWhite,
				:SyntaxClassNamesColor 		= ColorWhite,
				:SyntaxCommentsColor 		= ColorWhite,
				:SyntaxLiteralsColor 		= ColorWhite,
				:SyntaxFunctionCallsColor 	= ColorWhite
			]
			aStyleColors = aCustomStyleColors
			aTextColor = [255,255,255]
			aBackColor = [0,0,0]


	func StyleArt()
			nDefaultStyle  = STYLECOLOR_ART
			oApp.StyleFusion()
			aCustomStyleColors = [
				:LineNumbersAreaColor 		= new qcolor() { setrgb(255,255,255,255)},
				:LineNumbersAreaBackColor 	= new qcolor() { setrgb(50,50,42,255) 	},
				:ActiveLineBackColor 		= new qcolor() { setrgb(50,50,42,255) 	},
				:SyntaxKeywordsColor		= new qcolor() { setrgb(30,220,175,255) },
				:SyntaxClassNamesColor 		= new qcolor() { setrgb(166,226,46,255) },
				:SyntaxCommentsColor		= new qcolor() { setrgb(117,160,172,157)},
				:SyntaxLiteralsColor 		= new qcolor() { setrgb(230,191,77,255) },
				:SyntaxFunctionCallsColor 	= new qcolor() { setrgb(240,127,224,255)}
			]
			aStyleColors = aCustomStyleColors
			aTextColor = [255,255,255]
			aBackColor = [39,40,34]

	func StyleArt2()
			nDefaultStyle  = STYLECOLOR_ART2
			oApp.StyleFusion()
			aCustomStyleColors = [
				:LineNumbersAreaColor 		= new qcolor() { setrgb(255,255,255,255)},
				:LineNumbersAreaBackColor 	= new qcolor() { setrgb(0,0,0,255) 	},
				:ActiveLineBackColor 		= new qcolor() { setrgb(0,0,0,255) 	},
				:SyntaxKeywordsColor		= new qcolor() { setrgb(30,220,175,255) },
				:SyntaxClassNamesColor 		= new qcolor() { setrgb(166,226,46,255) },
				:SyntaxCommentsColor		= new qcolor() { setrgb(117,160,172,157)},
				:SyntaxLiteralsColor 		= new qcolor() { setrgb(230,191,77,255) },
				:SyntaxFunctionCallsColor 	= new qcolor() { setrgb(240,127,224,255)}
			]
			aStyleColors = aCustomStyleColors
			aTextColor = [255,255,255]
			aBackColor = [11,11,11]

	func StyleArt3()
			nDefaultStyle  = STYLECOLOR_ART3
			oApp.StyleFusion()
			aCustomStyleColors = [
				:LineNumbersAreaColor 		= new qcolor() { setrgb(255,255,255,255)},
				:LineNumbersAreaBackColor 	= new qcolor() { setrgb(0,0,0,255) 	},
				:ActiveLineBackColor 		= new qcolor() { setrgb(0,0,0,255) 	},
				:SyntaxKeywordsColor		= new qcolor() { setrgb(30,220,175,255) },
				:SyntaxClassNamesColor 		= new qcolor() { setrgb(166,226,46,255) },
				:SyntaxCommentsColor		= new qcolor() { setrgb(117,160,172,157)},
				:SyntaxLiteralsColor 		= new qcolor() { setrgb(230,191,77,255) },
				:SyntaxFunctionCallsColor 	= new qcolor() { setrgb(240,127,224,255)}
			]
			aStyleColors = aCustomStyleColors
			aTextColor = [255,255,255]
			aBackColor = [17,36,53]

	func StyleImage()
			nDefaultStyle  = STYLECOLOR_IMAGE
			oApp.StyleFusionBlack()
			aCustomStyleColors = [
				:LineNumbersAreaColor 		= new qcolor() { setrgb(255,255,255,255)},
				:LineNumbersAreaBackColor 	= new qcolor() { setrgb(0,0,0,255) 	},
				:ActiveLineBackColor 		= new qcolor() { setrgb(0,0,0,255) 	},
				:SyntaxKeywordsColor		= new qcolor() { setrgb(30,220,175,255) },
				:SyntaxClassNamesColor 		= new qcolor() { setrgb(166,226,46,255) },
				:SyntaxCommentsColor		= new qcolor() { setrgb(117,160,172,157)},
				:SyntaxLiteralsColor 		= new qcolor() { setrgb(230,191,77,255) },
				:SyntaxFunctionCallsColor 	= new qcolor() { setrgb(240,127,224,255)}
			]
			aStyleColors = aCustomStyleColors
			aTextColor = [255,255,255]
			aBackColor = [11,11,11]

	func StyleImage2()
			nDefaultStyle  = STYLECOLOR_IMAGE2
			oApp.StyleFusion()
			aCustomStyleColors = [
				:LineNumbersAreaColor 		= new qcolor() { setrgb(255,255,255,255)},
				:LineNumbersAreaBackColor 	= new qcolor() { setrgb(0,0,0,255) 	},
				:ActiveLineBackColor 		= new qcolor() { setrgb(0,0,0,255) 	},
				:SyntaxKeywordsColor		= new qcolor() { setrgb(30,220,175,255) },
				:SyntaxClassNamesColor 		= new qcolor() { setrgb(166,226,46,255) },
				:SyntaxCommentsColor		= new qcolor() { setrgb(117,160,172,157)},
				:SyntaxLiteralsColor 		= new qcolor() { setrgb(230,191,77,255) },
				:SyntaxFunctionCallsColor 	= new qcolor() { setrgb(240,127,224,255)}
			]
			aStyleColors = aCustomStyleColors
			aTextColor = [255,255,255]
			aBackColor = [11,11,11]


	func StyleArt_AfterControls
		# Called After we have all of the Ring Notepad Window Controls
		for oObj in [this.tree1,this.oFunctionsList,this.oClassesList,this.oOutputWindow] 
			oObj {
				setstylesheet("background-color: rgba(230,230,230,255);")
			}
		next

	func StyleImage_AfterControls nIndex
		# Called After we have all of the Ring Notepad Window Controls
		if nIndex = 1
			cBackImage = cCurrentDir + "image/back.jpg"
			cBackImage = substr(cBackImage,"\","/")
			for oObj in [this.tree1,this.oFunctionsList,this.oClassesList,this.oOutputWindow] 
				oObj {
					setstylesheet("color:white;background-image: url('" + cBackImage + "');")
				}
			next
			textedit1.setstylesheet("color:white;background-image: url('" + cBackImage + "');")
		else 
			cBackImage = cCurrentDir + "image/back2.jpg"
			cBackImage = substr(cBackImage,"\","/")
			textedit1.setstylesheet("color:white;background-image: url('" + cBackImage + "');")
			textedit1.verticalscrollbar().setStyleSheet("color:black;")
			textedit1.horizontalscrollbar().setStyleSheet("color:black;")
		ok

