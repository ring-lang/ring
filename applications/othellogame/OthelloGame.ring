# Author: Gal Zsolt, Bert Mariani
	load "stdlibcore.ring"
	load "lightguilib.ring"
	# Constants and Global Variables
		Size = 8
		Score = 0
		sumMoveBlack = 0
		sumMoveWhite = 0
		oPicBlack = new QPixmap(AppFile("black.png"))
		oPicWhite = new QPixmap(AppFile("white.png"))
		oPicEmpty = new QPixmap(AppFile("empty.jpg"))
		bWidth = 70
		bHeight = 70
		C_Spacing = 2
		C_ButtonEmptyStyle = " background-color: rgb(34,177,76); border-radius: 8px; "
		C_ButtonBlueStyle = "border-radius:6px;color:black; background-color: Cyan"
		C_ButtonYellowStyle = "border-radius:6px;color:black; background-color: Yellow"
		C_ButtonOrangeStyle = "border-radius:6px;color:black; background-color: Orange"
		C_ButtonGrayStyle = "border-radius:6px;color:black; background-color: rgb(213, 245, 227)"
		Button = newlist(Size+1,Size)
		LayoutButtonRow = list(Size+4)
		curColor = "B"
		otherColor = "W"
		FlagFlip = 0
		FlagSkipTurn = 0
		TransScript = list(1)
		MoveNumber = 1
		dArray = list(8)
		bArray = newList(8,8)
		oldArray = newList(8,8)
	# Create the GUI
		app = new qApp
		{
			win = new qWidget()
			{
				setWindowTitle("Othello Game")
				setWinIcon(self,AppFile("white.png"))
				setStyleSheet("background-color:White")
				reSize(800,600)
				winheight = win.height()
				fontSize = 8+(winheight/100)
				PlayScoreBlack = new QLabel(win)
				{
					setFont( new qFont("Cambria",fontSize,50,0))
					setstylesheet(C_ButtonBlueStyle)
					setalignment(Qt_AlignHCenter|Qt_AlignVCenter)
					settext("Black Score: 2")
				}
				PlayScoreWhite = new QLabel(win)
				{
					setFont( new qFont("Cambria",fontSize,50,0))
					setstylesheet(C_ButtonYellowStyle)
					setalignment(Qt_AlignHCenter|Qt_AlignVCenter)
					settext("White Score: 2")
				}
				NextMove = new QLabel(win)
				{
					setFont( new qFont("Cambria",fontSize,50,0))
					setstylesheet(C_ButtonOrangestyle)
					setalignment(Qt_AlignHCenter|Qt_AlignVCenter)
					settext("Next Move: Black ")
				}
				NewGame = new QPushButton(win)
				{
					setFont( new qFont("Cambria",fontSize,50,0))
					setstylesheet("background-color: rgb(215, 189, 226)")
					settext("New Game:")
					setclickevent("pStart()")
				}
				SkipTurn = new QPushButton(win)
				{
					setFont( new qFont("Cambria",fontSize,50,0))
					setstylesheet("background-color: rgb(215, 189, 226)")
					settext("Skip Turn:")
					setclickevent("pSkipTurn()")
				}
				StatusBar1 = new qstatusbar(win)
				{
					setstylesheet(C_ButtonBlueStyle)
					setFont( new qFont("Cambria",fontSize,50,0))
				}
				LayoutButtonMain = new QVBoxLayout()
				LayoutButtonMain.setSpacing(C_Spacing)
				LayoutButtonMain.setContentsmargins(0,0,0,0)
				TitleLet = list(9)
				Number = 64
				for Col = 1 to 9 step 1 { 
					Letter = hex2str(hex(Number))
					TitleLet[Col] = new qLabel(win)
					{
						setFont( new qFont("Cambria",fontSize,50,0))
						setAlignment(Qt_AlignHCenter|Qt_AlignVCenter)
						setStyleSheet("background-color: rgb(213, 245, 227)")
						setText(Letter)
					}
					Number++
				} 
				LayoutTitleRow = new QHBoxLayout()
				{
					setSpacing(C_Spacing)
					setContentsMargins(0,0,0,0)
				}
				for Col = 1 to 9 step 1 { 
					LayoutTitleRow.AddWidget(TitleLet[Col])
				} 
				LayoutButtonMain.AddLayout(LayoutTitleRow)
				TitleNum = list(9)
				for Col = 1 to 8 step 1 { 
					Letter = ""+Col
					TitleNum[Col] = new qLabel(win)
					{
						setFont( new qFont("Cambria",fontSize,50,0))
						setAlignment(Qt_AlignHCenter|Qt_AlignVCenter)
						setStyleSheet("background-color: rgb(213, 245, 227)")
						setText(Letter)
					}
					Number++
				} 
				for Row = 1 to Size step 1 { 
					LayoutButtonRow[Row] = new QHBoxLayout()
					{
						setSpacing(C_Spacing)
						setContentsmargins(0,0,0,0)
					}
					LayoutButtonRow[Row].AddWidget(TitleNum[Row])
					for Col = 1 to Size step 1 { 
						Button[Row][Col] = new QPushButton(win)
						{
							setClickEvent("pPlay("+string(Row)+","+string(Col)+")")
							setSizePolicy(1,1)
						}
						LayoutButtonRow[Row].AddWidget(Button[Row][Col])
					} 
					LayoutButtonMain.AddLayout(LayoutButtonRow[Row])
				} 
				LayoutDataRow = new QHBoxLayout()
				{
					setSpacing(C_Spacing)
					setContentsMargins(0,0,0,0)
				}
				LayoutDataRow.AddWidget(PlayScoreBlack)
				LayoutDataRow.AddWidget(PlayScoreWhite)
				LayoutDataRow.AddWidget(NextMove)
				LayoutButtonMain.AddLayout(LayoutDataRow)
				LayoutNewGameRow = new QHBoxLayout()
				{
					setSpacing(C_Spacing)
					setContentsMargins(0,0,0,0)
				}
				LayoutNewGameRow.AddWidget(NewGame)
				LayoutNewGameRow.AddWidget(SkipTurn)
				LayoutButtonMain.AddLayout(LayoutNewGameRow)
				LayoutButtonMain.AddWidget(StatusBar1)
				setLayout(LayoutButtonMain)
				pStart()
				show()
			}
			exec()
		}
	func pStart
		FlagSkipTurn = 1
		bArray = newList(8,8)
		for Row = 1 to Size step 1 { 
			for Col = 1 to Size step 1 { 
				bArray[Row][Col] = "E"
				Button[Row][Col] {
					setIcon(new QIcon(new QPixMap(AppFile("empty.jpg"))))
					setIconSize(new QSize(bWidth,bHeight))
				}
				Button[Row][Col] {
					setStyleSheet(C_ButtonEmptyStyle)
				}
				Button[Row][Col].setenabled(true)
				Button[Row][Col].blockSignals(false)
			} 
		} 
		Statusbar1.showMessage("Message:",0)
		curColor = "B"
		Score = 0
		MoveNumber = 1
		TransScript = list(1)
		NextMove.settext("Next Move: Black ")
		PlayScoreBlack.settext("Black Score: 2")
		PlayScoreWhite.settext("White Score: 2")
		Button[4][4] {
			setIcon(new QIcon(new QPixMap(AppFile("black.png"))))
			setIconSize(new QSize(bWidth,bHeight))
		}
		Button[5][5] {
			setIcon(new QIcon(new QPixMap(AppFile("black.png"))))
			setIconSize(new QSize(bWidth,bHeight))
		}
		Button[4][5] {
			setIcon(new QIcon(new QPixMap(AppFile("white.png"))))
			setIconSize(new QSize(bWidth,bHeight))
		}
		Button[5][4] {
			setIcon(new QIcon(new QPixMap(AppFile("white.png"))))
			setIconSize(new QSize(bWidth,bHeight))
		}
		Button[4][4].blockSignals(true)
		Button[4][5].blockSignals(true)
		Button[5][4].blockSignals(true)
		Button[5][5].blockSignals(true)
		bArray[4][4] = "B"
		bArray[5][5] = "B"
		bArray[4][5] = "W"
		bArray[5][4] = "W"
		return 
	func sumMove
		sumMoveBlack = 0
		sumMoveWhite = 0
		sumEmptyCells = 0
		for Row = 1 to Size step 1 { 
			for Col = 1 to Size step 1 { 
				if bArray[Row][Col] = "B" { 
					sumMoveBlack++
				} 
				if bArray[Row][Col] = "W" { 
					sumMoveWhite++
				} 
				if bArray[Row][Col] = "E" { 
					sumEmptyCells++
				} 
			} 
		} 
		if sumEmptyCells = 0 { 
			Msg = "Game Over."+nl+"No more squares left to Play."
			MsgBox(Msg)
			return 
		} 
		PlayScoreBlack.settext("Black Score: "+sumMoveBlack)
		PlayScoreWhite.settext("White Score: "+sumMoveWhite)
		return 
	func pPlay (Row,Col) { 
		RowPlayed = Row
		ColPlayed = Col
		ColorPlayed = curColor
		FlagSkipTurn = 0
		if curColor = "B" { 
			otherColor = "W"
			else
				otherColor = "B"
		} 
		if FlagSkipTurn = 1 { 
			FlagSkipTurn = 0
			return 
		} 
		see nl+"------------------------"+nl+nl
		see "CLICK Row-Col: "+ColorPlayed+" "+Row+"-"+Col+nl
		Letter = char(64+Col)
		if curColor = "B" { 
			MovePlayed = ""+MoveNumber+"-"+"B"+"-"+Row+"-"+Letter
			NextMove.setstylesheet(C_ButtonGrayStyle)
			NextMove.settext("Next Move: White ")
			else
				MovePlayed = ""+MoveNumber+"-"+"W"+"-"+Row+"-"+Letter
				NextMove.setstylesheet(C_ButtonOrangeStyle)
				NextMove.settext("Next Move: Black ")
		} 
		TranScript = Add(TransScript,MovePlayed)
		MoveNumber++
		see "TransScript: "+nl
		see TransScript
		see nl
		for h = 1 to Size step 1 { 
			for v = 1 to Size step 1 { 
				oldArray[h][v] = bArray[h][v]
			} 
		} 
		FlagFlip = 0
		Statusbar1.showMessage("Message:",0)
		if curColor = "B" { 
			bArray[Row][Col] = "B"
			Button[Row][Col] {
				setIcon( new qIcon( new qPixMap(AppFile("black.png"))))
				setIconSize( new qSize(bWidth,bHeight))
			}
			CheckDiagonals(Row,Col,curColor)
			elseif curColor = "W"
				bArray[Row][Col] = "W"
				Button[Row][Col] {
					setIcon( new qIcon( new qPixMap(AppFile("white.png"))))
					setIconSize( new qSize(bWidth,bHeight))
				}
				CheckDiagonals(Row,Col,curColor)
		} 
		see "FlagFlip: "+FlagFlip+nl
		if FlagFlip = 0 { 
			Msg = "Message: "+bArray[RowPlayed][ColPlayed]+" "+ColPlayed+"-"+RowPlayed+" Move INVALID. "+"No Flips Possible"
			Statusbar1.showMessage(Msg,0)
			for h = 1 to Size step 1 { 
				for v = 1 to Size step 1 { 
					bArray[h][v] = oldArray[h][v]
				} 
			} 
			see "ColorPlayed: "+curColor+" "+RowPlayed+"-"+ColPlayed+nl
			if curColor = "B" { 
				NextMove.setstylesheet(C_ButtonOrangestyle)
				NextMove.settext("Next Move: Black.... ")
			} 
			if curColor = "W" { 
				NextMove.setstylesheet(C_ButtonGrayStyle)
				NextMove.settext("Next Move: White.... ")
			} 
			Button[Row][Col] {
				setIcon( new qIcon( new qPixMap(AppFile("empty.jpg"))))
				setIconSize( new qSize(bWidth,bHeight))
			}
			Button[RowPlayed][ColPlayed].setenabled(true)
			return 
		} 
		Statusbar1.showMessage("Message:",0)
		see "Color bArray_____"+nl
		for Row = 1 to Size step 1 { 
			see nl+row+" "
			for Col = 1 to Size step 1 { 
				if bArray[Row][Col] = "W" { 
					see "W "
					if oldArray[Row][Col]! = bArray[Row][Col] { 
						if !isMobile() { 
							app.processevents()
							sleep(0.2)
						} 
					} 
					Button[Row][Col] {
						setIcon( new qIcon( new qPixMap(AppFile("white.png"))))
						setIconSize( new qSize(bWidth,bHeight))
					}
				} 
				if bArray[Row][Col] = "B" { 
					see "B "
					if oldArray[Row][Col]! = bArray[Row][Col] { 
						if !isMobile() { 
							app.processevents()
							sleep(0.2)
						} 
					} 
					Button[Row][Col] {
						setIcon( new qIcon( new qPixMap(AppFile("black.png"))))
						setIconSize( new qSize(bWidth,bHeight))
					}
				} 
				if bArray[Row][Col] = "E" { 
					see ". "
				} 
			} 
		} 
		see nl
		for h = 1 to Size step 1 { 
			for v = 1 to Size step 1 { 
				if bArray[h][v]! = "E" { 
					Button[h][v].blockSignals(true)
				} 
			} 
		} 
		curColor = otherColor
		sumMove()
		return 
	} 
	func CheckDiagonals (Row,Col,curColor) { 
		dArray = list(9)
		for Cell = 1 to 9 step 1 { 
			dArray[Cell] = "E"
		} 
		for Cell = 1 to 8 step 1 { 
			dArray[Cell] = bArray[Cell][Col]
		} 
		CheckFlips(Row,curColor)
		for Cell = 1 to 8 step 1 { 
			bArray[Cell][Col] = dArray[Cell]
		} 
		dArray = list(9)
		for Cell = 1 to 9 step 1 { 
			dArray[Cell] = "E"
		} 
		for Cell = 1 to 8 step 1 { 
			dArray[Cell] = bArray[ROW][Cell]
		} 
		CheckFlips(Col,curColor)
		for Cell = 1 to 8 step 1 { 
			bArray[Row][Cell] = dArray[Cell]
		} 
		dArray = list(9)
		for Cell = 1 to 9 step 1 { 
			dArray[Cell] = "E"
		} 
		Diff = Row-Col
		if Diff = 0 { 
			StartRow = 1
			StartCol = 1
		} 
		if Diff > 0 { 
			StartRow = Row-Col+1
			StartCol = 1
		} 
		if Diff < 0 { 
			StartRow = 1
			StartCol = Col-Row+1
		} 
		DRow = StartRow
		DCol = StartCol
		for Cell = 1 to 8 step 1 { 
			dArray[Cell] = bArray[DRow][DCol]
			DRow++
			DCol++
			if DRow > 8 OR DCol > 8 { 
				exit 1
			} 
		} 
		CheckFlips((Row-StartRow+1),curColor)
		DRow = StartRow
		DCol = StartCol
		for Cell = 1 to 8 step 1 { 
			bArray[DRow][DCol] = dArray[Cell]
			DRow++
			DCol++
			if DRow > 8 OR DCol > 8 { 
				exit 1
			} 
		} 
		dArray = list(9)
		for Cell = 1 to 9 step 1 { 
			dArray[Cell] = "E"
		} 
		Diff = Row-(9-Col)
		if Diff = 0 { 
			StartRow = 8
			StartCol = 1
		} 
		if Diff > 0 { 
			StartRow = 8
			StartCol = Col-(8-Row)
		} 
		if Diff < 0 { 
			StartRow = Col+(Row-1)
			StartCol = 1
		} 
		DRow = StartRow
		DCol = StartCol
		for Cell = 1 to 8 step 1 { 
			dArray[Cell] = bArray[DRow][DCol]
			DRow--
			DCol++
			if DRow < 1 OR DCol > 8 { 
				exit 1
			} 
		} 
		CheckFlips((Col-StartCol+1),curColor)
		DRow = StartRow
		DCol = StartCol
		for Cell = 1 to 8 step 1 { 
			bArray[DRow][DCol] = dArray[Cell]
			DRow--
			DCol++
			if DRow < 1 OR DCol > 8 { 
				exit 1
			} 
		} 
		return 
	} 
	func CheckFlips (cellClick,curColor) { 
		aFlip = list(9)
		aFlip[9] = "."
		FlipCell = 0
		otherColor = "E"
		if curColor = "B" { 
			otherColor = "W"
		} 
		if curColor = "W" { 
			otherColor = "B"
		} 
		FlagStart = 0
		for cell = 1 to 8 step 1 { 
			if dArray[cell] = curColor AND dArray[cell+1] = otherColor { 
				cellStart = cell
				FlagStart = 1
				elseif dArray[cell] = otherColor AND dArray[cell+1] = curColor
					cellEnd = cell+1
					if FlagStart = 1 AND ((cellStart = cellClick) OR (cellEnd = cellClick)) { 
						FlipStart = cellStart+1
						FlipEnd = cellEnd-1
						for n = (FlipStart) to (FlipEnd) step 1 { 
							aFlip[n] = 1
						} 
						FlagStart = 0
					} 
				elseif dArray[cell] = "E" AND FlagStart = 1
					FlagStart = 0
			} 
		} 
		for n = 1 to 9 step 1 { 
			if aFlip[n] = 1 { 
				FlagFlip = 1
				dArray[n] = curColor
			} 
		} 
		return 
	} 
	func msgBox (cText) { 
		mb = new qMessageBox(win)
		{
			setWindowTitle("Othello Game")
			setText(cText)
			setstylesheet(C_ButtonBlueStyle)
			setstandardButtons(QMessageBox_Discard|QMessageBox_OK)
			result = exec()
		}
		return 
	} 
	func pSkipTurn  { 
		FlagSkipTurn = 1
		if curColor = "B" { 
			MovePlayed = ""+MoveNumber+"-"+"B"+"-"+Row+"-"+Letter
			NextMove.setstylesheet(C_ButtonGrayStyle)
			NextMove.settext("Next Move: White ")
			curColor = "W"
			else
				MovePlayed = ""+MoveNumber+"-"+"W"+"-"+Row+"-"+Letter
				NextMove.setstylesheet(C_ButtonOrangeStyle)
				NextMove.settext("Next Move: Black ")
				curColor = "B"
		} 
		if curColor = "B" { 
			otherColor = "W"
			else
				otherColor = "B"
		} 
		MovePlayed = ""+MoveNumber+"-"+otherColor+"-Skipped-Move"
		TranScript = Add(TransScript,MovePlayed)
		MoveNumber++
		see "TransScript: "+nl
		see TransScript
		see nl
		return 
	} 
