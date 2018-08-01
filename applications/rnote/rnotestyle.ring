# The Ring Notepad Application (RNote)
# Author : Mahmoud Fayed <msfclipper@yahoo.com>

class RNoteStyle

	func pCheckCustomColors
		if True	# Switch to Use the Style or Not
			pSelectStyleColor(nDefaultStyle)
			LoadSettings()
		ok

	func pSetActiveLineColor
		textedit1.SetActiveLineColor(aStyleColors[:ActiveLineBackColor])

	func pSetStyleColor(nStyle)
		pSelectStyleColor(nStyle)
		RestoreSettings()
		pSetEditorColors()

	func pSelectStyleColor nStyle
		switch nStyle
		on 0 pStyleWindows()
		on 1 pStyleWhite()
		on 2 pStyleBlue()
		on 3 pStyleBlack()
		on 4 pStyleModern()
		on 5 pStyleModernBlack()
		on 6 pStyleModernBlack2()
		on 7 pStyleNotepadWhite()
		on 8 pStyleNotepadPurple()
		on 9 pStyleNotepadDarkBlue()
		on 10 pStyleNotepadBlack()
		on 11 pStyleArt()
		on 12 pStyleArt2()
		on 13 pStyleArt3()
		on 14 pStyleImage()
		on 15 pStyleImage2()
		off
		if nStyle >= 7 
			lKeywordsBold = False 
		else
			lKeywordsBold = True
		ok

	func pSelectStyleColor2 nStyle
		for oObj in [this.tree1,this.oFunctionsList,this.oClassesList,this.oOutputWindow] 
			oObj {
				setstylesheet("")
			}
		next
		if nStyle = STYLECOLOR_ART or nStyle = STYLECOLOR_ART2
			pStyleArt_AfterControls()
		but nStyle = STYLECOLOR_IMAGE 
			pStyleImage_AfterControls(1)
		but nStyle = STYLECOLOR_IMAGE2 
			pStyleImage_AfterControls(2)
		ok

	func pSetEditorColors
		textedit1.setLineNumbersAreaColor(aStyleColors[:LineNumbersAreaColor])
		textedit1.setLineNumbersAreaBackColor(aStyleColors[:LineNumbersAreaBackColor])
		new RingCodeHighLighter(textedit1.document() ) {
			if ismethod(self,:setkeywordsbold) 
				setKeywordsbold(this.lKeywordsBold)
			ok
			setColors(
				this.aStyleColors[:SyntaxKeywordsColor],
				this.aStyleColors[:SyntaxClassNamesColor],
				this.aStyleColors[:SyntaxCommentsColor],
				this.aStyleColors[:SyntaxLiteralsColor],
				this.aStyleColors[:SyntaxFunctionCallsColor]
			)
		}

	func pStyleBlue()
			nDefaultStyle  = STYLECOLOR_BLUE
			aCustomStyleColors = [
				:LineNumbersAreaColor 		= colorWhite ,
				:LineNumbersAreaBackColor 	= colordarkBlue,
				:ActiveLineBackColor 		= colordarkBlue,
				:SyntaxKeywordsColor		= colorWhite,
				:SyntaxClassNamesColor 		= ColorWhite,
				:SyntaxCommentsColor 		= ColorSilver,
				:SyntaxLiteralsColor 		= ColorCyan,
				:SyntaxFunctionCallsColor 	= ColorGreen
			]
			aStyleColors = aCustomStyleColors
			aTextColor = [255,255,255]
			aBackColor = [0,0,135]
			MyApp.StylefusionCustom(
				new qColor() { setrgb(0,0,128,255) },
				new qColor() { setrgb(255,255,255,255) },
				new qColor() { setrgb(0,0,128,255) },
				new qColor() { setrgb(0,0,128,255) },
				new qColor() { setrgb(255,255,255,255) },
				new qColor() { setrgb(255,255,255,255) },
				new qColor() { setrgb(255,255,255,255) },
				new qColor() { setrgb(0,0,128,255) },
				new qColor() { setrgb(255,255,255,255) },
				new qColor() { setrgb(255,0,0,255) },
				new qColor() { setrgb(142,45,197,255) },
				new qColor() { setrgb(0,0,128,255)}
			)

	func pStyleBlack()
			nDefaultStyle  = STYLECOLOR_BLACK
			MyApp.StyleFusionBlack()
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

	func pStyleWhite()
			nDefaultStyle  = STYLECOLOR_WHITE 
			MyApp.StyleFusion()
			pStyleWhiteColors()

	func pStyleWhiteColors
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

	func pStyleWindows
			nDefaultStyle  = STYLECOLOR_WINDOWS
			if isWindows()
				MyApp.StyleWindowsVista()
			else 
				MyApp.StyleWindows()
			ok
			pStyleWhiteColors()

	func pStyleModern()
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
			MyApp.StylefusionCustom(
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

	func pStyleModernBlack()
			nDefaultStyle  = STYLECOLOR_MODERNBLACK
			MyApp.StyleFusionBlack()
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

	func pStyleModernBlack2()
			nDefaultStyle  = STYLECOLOR_MODERNBLACK2
			MyApp.StyleFusionBlack()
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

	func pStyleNotepadWhite()
			nDefaultStyle  = STYLECOLOR_NOTEPADWHITE
			MyApp.StyleFusion()
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

	func pStyleNotepadPurple()
			nDefaultStyle  = STYLECOLOR_NOTEPADPURPLE
			MyApp.StyleFusion()
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

	func pStyleNotepadDarkBlue()
			nDefaultStyle  = STYLECOLOR_NOTEPADDARKBLUE
			MyApp.StyleFusion()
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

	func pStyleNotepadBlack()
			nDefaultStyle  = STYLECOLOR_NOTEPADBLACK
			MyApp.StyleFusion()
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


	func pStyleArt()
			nDefaultStyle  = STYLECOLOR_ART
			MyApp.StyleFusion()
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

	func pStyleArt2()
			nDefaultStyle  = STYLECOLOR_ART2
			MyApp.StyleFusion()
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

	func pStyleArt3()
			nDefaultStyle  = STYLECOLOR_ART3
			MyApp.StyleFusion()
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

	func pStyleImage()
			nDefaultStyle  = STYLECOLOR_IMAGE
			MyApp.StyleFusionBlack()
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

	func pStyleImage2()
			nDefaultStyle  = STYLECOLOR_IMAGE2
			MyApp.StyleFusion()
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


	func pStyleArt_AfterControls
		# Called After we have all of the Ring Notepad Window Controls
		for oObj in [this.tree1,this.oFunctionsList,this.oClassesList,this.oOutputWindow] 
			oObj {
				setstylesheet("background-color: rgba(230,230,230,255);")
			}
		next

	func pStyleImage_AfterControls nIndex
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

