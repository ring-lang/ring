#====================================================#
# Try Ring Online (Using RingQt for WebAssembly)
# 2024, Mahmoud Fayed 
#====================================================#

class SyntaxColors
	
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
	
	aStyleColors = []

	setStyleColors(:Black)
	
	func ApplySyntaxColors txtCode

		new RingCodeHighLighter( txtCode.document() ) {
			setColors(
				this.aStyleColors[:SyntaxKeywordsColor],
				this.aStyleColors[:SyntaxClassNamesColor],
				this.aStyleColors[:SyntaxCommentsColor],
				this.aStyleColors[:SyntaxLiteralsColor],
				this.aStyleColors[:SyntaxFunctionCallsColor]
			)
		}

	func setStyleColors cStyle 

		switch lower(cStyle) 
		on :Black 
			aStyleColors = [
				:LineNumbersAreaColor 		= new qcolor() { setrgb(255,255,255,255)},
				:LineNumbersAreaBackColor 	= new qcolor() { setrgb(0,0,0,255) 	},
				:ActiveLineBackColor 		= new qcolor() { setrgb(0,0,0,255) 	},
				:SyntaxKeywordsColor		= new qcolor() { setrgb(30,220,175,255) },
				:SyntaxClassNamesColor 		= new qcolor() { setrgb(166,226,46,255) },
				:SyntaxCommentsColor		= new qcolor() { setrgb(117,160,172,157)},
				:SyntaxLiteralsColor 		= new qcolor() { setrgb(230,191,77,255) },
				:SyntaxFunctionCallsColor 	= new qcolor() { setrgb(240,127,224,255)}
			]
		on :White 
			aStyleColors = [
				:LineNumbersAreaColor 		= colorBlack ,
				:LineNumbersAreaBackColor 	= colorCyan,
				:ActiveLineBackColor 		= colorCyan,
				:SyntaxKeywordsColor		= colordarkBlue,
				:SyntaxClassNamesColor 		= ColordarkMagenta,
				:SyntaxCommentsColor 		= ColorSilver,
				:SyntaxLiteralsColor 		= ColorDarkGreen,
				:SyntaxFunctionCallsColor 	= ColorBlue
			]
		on :Blue 
			aStyleColors = [
				:LineNumbersAreaColor 		= colorWhite,
				:LineNumbersAreaBackColor 	= colorDarkBlue,
				:ActiveLineBackColor 		= colorDarkBlue2,
				:SyntaxKeywordsColor		= colorWhite,
				:SyntaxClassNamesColor 		= colorWhite,
				:SyntaxCommentsColor 		= colorWhite,
				:SyntaxLiteralsColor 		= colorWhite,
				:SyntaxFunctionCallsColor 	= colorWhite
			]
		on :Modern
			aStyleColors = [
				:LineNumbersAreaColor 		= new qcolor() { setrgb(143,144,138,255) },
				:LineNumbersAreaBackColor 	= new qcolor() { setrgb(39,60,64,255) },
				:ActiveLineBackColor 		= new qcolor() { setrgb(39,110,114,255) },
				:SyntaxKeywordsColor		= new qcolor() { setrgb(80,187,177,255) },
				:SyntaxClassNamesColor 		= new qcolor() { setrgb(166,226,46,255) },
				:SyntaxCommentsColor 		= new qcolor() { setrgb(117,160,172,157) },
				:SyntaxLiteralsColor 		= new qcolor() { setrgb(230,191,77,255) },
				:SyntaxFunctionCallsColor 	= new qcolor() { setrgb(240,127,224,255) }
			]
		on :Windows 
			setStyleColors(:White)
		off 

	func styleFusionBlue oApp

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

	func styleModern oApp

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

	func style oApp,win,txtCode,cStyle 

		setStyleColors(cStyle) 
		ApplySyntaxColors(txtCode)  
		switch cStyle 
			on "Black" 
				oApp.styleFusionBlack() 
				win.show() 
				oApp.styleFusionBlack()
			on "White" 
				oApp.styleFusion() 
				win.show()				
				oApp.styleFusion()
			on "Blue"
				styleFusionBlue(oApp) 
				win.show()				
				styleFusionBlue(oApp)		
			on "Modern"
				styleModern(oApp) 
				win.show()				
				styleModern(oApp)
			on "Windows"
				oApp.styleWindows() 
				win.show()				
				oApp.styleWindows()				
		off
