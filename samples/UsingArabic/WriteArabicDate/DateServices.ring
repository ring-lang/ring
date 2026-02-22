#"═════════════════════════════════════════════════════════════════════════════════════" 
#"	Programming language :Ring                                                     "
#"	Application 	     : Date Services Program                                   "
#"	Author 	             : Mohammed Saber                                          "
#"	Date 	             : 18/2/2026  &   1/9/1447                                 "
#"═════════════════════════════════════════════════════════════════════════════════════"
#"                         1-  Load Libraries                                          "
#"═════════════════════════════════════════════════════════════════════════════════════"
load "guilib.ring"
load "stdlib.ring"
#"═════════════════════════════════════════════════════════════════════════════════════"
#"                         2-  Variables                                               "
#"═════════════════════════════════════════════════════════════════════════════════════"
#                           Hijri Years Array 
#                     from 1/1/1350   to 30/12/1500  Hijri
#                     from 18/5/1931  to 16/11/2077  Gregorian 
#"═════════════════════════════════════════════════════════════════════════════════════"
hijriYears = [2350,2726,3412,3498,1461,694,2359,1179,2635,2853,2900,2922,
1389,1197,2645,3365,3730,3785,1748,2794,1387,1195,1685,2889,2980,2994,1461,
698,2395,1195,1365,1714,1753,748,2414,1198,2646,3370,3413,1450,2741,1211,
603,2347,2709,2890,2981,1450,2741,1366,2710,3402,3749,1874,1769,874,2733,
1365,2725,2898,2985,1460,2490,1243,605,1325,2725,2772,2794,1389,1213,573,
2333,2709,2890,2906,1389,694,2363,1179,1621,1705,1876,2922,1388,2733,1365,
2857,2962,2985,1492,2778,1370,2731,1429,1865,1892,2986,1461,694,2646,3370,
3413,1450,1877,858,2397,1179,2637,3366,3411,1450,2733,1206,2647,1319,2709,
2890,2901,876,2478,1206,2710,2890,3493,1490,1497,732,2413,1197,1621,1746,
2921,884,2486,1239,683,1355,1701,1874,2921,1387,685,2381,3221,3402,3749,
1738,2773,1366,3223]

#"═════════════════════════════════════════════════════════════════════════════════════"
#                         Arabic Days Names Array
#"═════════════════════════════════════════════════════════════════════════════════════"
daysOfWeek = ["الأحد", "الاثنين", "الثلاثاء", "الأربعاء", "الخميس", "الجمعة", "السبت"]
#"═════════════════════════════════════════════════════════════════════════════════════"
#                         Hijri Months Names Array
#"═════════════════════════════════════════════════════════════════════════════════════"
hMonthNames = ["محرم", "صفر", "ربيع الأول", "ربيع الآخر", "جمادى الأولى", "جمادى الآخرة", "رجب", "شعبان", "رمضان", "شوال", "ذو القعدة", "ذو الحجة"]
#"═════════════════════════════════════════════════════════════════════════════════════"
#                         Gregorian Months Names Array
#"═════════════════════════════════════════════════════════════════════════════════════"
gMonthNames = ["يناير", "فبراير", "مارس", "أبريل", "مايو", "يونيو", "يوليو", "أغسطس","سبتمبر", "أكتوبر", "نوفمبر", "ديسمبر"]
#"═════════════════════════════════════════════════════════════════════════════════════"
#                         ComboBoxes Itemes Arrays
#"═════════════════════════════════════════════════════════════════════════════════════"
hYears  = []; for y = 1350 to 1500 add(hYears, string(y))next
gDays   = []; for d = 1 to 31 add(gDays, string(d)) next
hDays   = []; for d = 1 to 30 add(hDays, string(d)) next
gYears  = []; for y = 1931 to 2077 add(gYears, string(y)) next
ghMonth = []; for y = 1 to 12 add(ghMonth, string(y)) next
adGDays = []; for f = 0 to 365 add(adGDays, string(f)) next
adMonth = []; for g = 0 to 12 add(adMonth, string(g)) next
adYears = []; for h = 0 to 50 add(adYears, string(h)) next
adHDays = []; for K = 0 to 360 add(adHDays, string(K)) next
aComboSizes =[];aComboTypes =[];aComboButtons =[];aComboLists = [];aComboFuncs = []

#"═════════════════════════════════════════════════════════════════════════════════════"
#                      Hijri Calendar Variables
#              position , width , height , colors , fonts
#"═════════════════════════════════════════════════════════════════════════════════════"
nCalendarX = 10                # Calendar X Position
nCalendarY = 90                # Calendar Y Position
cellWidth = 60                 # Cell Width
cellHeight = 50                # Cell Height
headerHeight = 25              # Header Height (Sun,Mon,Tue...)
hijriTitleColor = "#008000"    # Hijri Title Text Color
gregCurrColor = "#0000FF"      # Current Gregorian Title Text Color
gregOtherColor = "#FF0000"     # Current Gregorian Title Text Color
cellBgColor = "#FFFFFF"        # Cell Background Color
emptyCellBgColor = "#FFFFFF"   # Empty Cell Background Color
todayColor = "#B5E71D"         # Current Today Background Color
headerBgColor = "#179672"      # Header Background Color
cellHijriTextColor = "#008000" # Hijri Date Text Cell Color
cellGregTextColor = "#0000FF"  # Current Gregorian Date Text Cell Color
cellGregText2Color = "#FF0000" # Other Gregorian Date Text Cell Color
headerTextColor = "white"      # Header Text Cell Color
aGridLines = []                # Border Cell Draw Array
borderColor = "#006400"        # Border Color
nBorderWidth = 1               # Border Width
separatorColor = "#000000"     # Separator Color (/)
separatorSpacing = 1           # Separator Spacing
separatorFontSize = 20         # Separator Font Size
headerFontFamily = "Arial"     # Header Font Family
headerFontSize = 16            # Header Font Size
headerFontWeight = "bold"      # Header Font Weight
titleFontFamily = loadFont("Changa.ttf")
titleFontSize = 15             # Title Font Size
titleFontWeight = "bold"       # Title Font Weight
cellFontFamily = "Arial"       # Cell Font Family
cellFontSize = 18              # Hijri Date Text Cell Font Size
cellGregFontSize = 15          # Gregorian Date Text Cell Font Size
cellFontWeight = "bold"        # Cell Font Weight

#"═════════════════════════════════════════════════════════════════════════════════════"
#    Get Current Hijri Date Variables from already Function Defenition
#"═════════════════════════════════════════════════════════════════════════════════════"

nDiffToday = GetJD(number(TimeList()[19]), number(TimeList()[10]), number(TimeList()[6])) - 2426479.5
hToday     = DiffToHijri(nDiffToday, hijriYears)

currCalday     = hToday[1]      # get current hijri day date
currCalMonth   = hToday[2]      # get current hijri month date
currCalYear    = hToday[3]      # get current hijri year date

realTodayDay   = hToday[1]      # get current hijri day caledar
realTodayMonth = hToday[2]      # get current hijri month caledar
realTodayYear  = hToday[3]      # get current hijri year caledar
selectedYear = 0; selectedMonth = 0; selectedDay = 0

#"═════════════════════════════════════════════════════════════════════════════════════"
#"                         3-  Creat Form                                              "
#"═════════════════════════════════════════════════════════════════════════════════════"

app = new qApp {
	win = new qWidget() {
        	setWindowTitle("برنامج خدمات التاريخ")
		setWinIcon(win,"icon1.png") 
        	setFixedSize(1100, 650)
		Desktop = new qDesktopWidget()
		NScreenWidth  = Desktop.width()
		NScreenHeight = Desktop.height()
		NewX = (NScreenWidth - 1100) / 2
		NewY = (NScreenHeight - 650-50) / 2
		move(NewX, NewY)
#"═════════════════════════════════════════════════════════════════════════════════════"
#"                         4-  Creat Elements                                          "
#"═════════════════════════════════════════════════════════════════════════════════════"
#"═════════════════════════════════════════════════════════════════════════════════════"
#                      form main background
#"═════════════════════════════════════════════════════════════════════════════════════"
        MainBackground = new QLabel(win) {
		move(0, 0)  resize(1100, 650)
            	setPixmap( new QPixmap("green.png") )
            	setScaledContents(True)
        }
#"═════════════════════════════════════════════════════════════════════════════════════"
#                    form header Title and Icon
#"═════════════════════════════════════════════════════════════════════════════════════"
        headerTitle = new QLabel(win) {
		move(880, 43)  resize(140, 50)
            	setText("خدمات التاريخ")
           	styleLabel(self,16,"bold","white","#transparent","0px 0px 8px 0px","1.5px","solid","transparent","8px",loadFont("Changa.ttf"))
        }
       headerIcon = new QLabel(win) {
		move(850, 49)  resize(30, 30)
            	setPixmap( new QPixmap("icon1.png") )
            	setScaledContents(True)
        }
#"═════════════════════════════════════════════════════════════════════════════════════"
#                   form header Current Date
#"═════════════════════════════════════════════════════════════════════════════════════"
         headerCurrentDate = new qLabel(win) {
		move(80, 48)  resize(400, 40)
          	setText(TimeList()[6]+" / "+TimeList()[10]+" / "+TimeList()[19]+ " م " +"  "+string(GregToHijri(number(TimeList()[6]), number(TimeList()[10]), number(TimeList()[19]), hijriYears)))
		styleLabel(self,12,"bold","white","transparent","0px 28px 8px 0px","0px","solid","yellow","8px",loadFont("Changa.ttf"))
           	setAlignment(Qt_AlignHCenter | Qt_AlignVCenter)
        }
#"═════════════════════════════════════════════════════════════════════════════════════"
#                          Hijri Calendar 
#"═════════════════════════════════════════════════════════════════════════════════════"
	HijriCaledar = new qGroupBox(win) {
		setTitle(" التقويم الهجري ")
		move(55, 110)  resize(440, 470)
		setStyleSheet("QGroupBox {font-family: " + loadFont("Changa.ttf") + "; font-size: 15px; font-weight: bold; color: white; border: 2px solid #006400; border-radius: 8px; margin-top: 16px; background-color: transparent; }" +
		"QGroupBox::title {subcontrol-origin: margin;min-width: 90px;min-height: 15px;left: 175px; padding: 0px 0px 2px 0px; background-color: #179672; border-radius: 5px; }")
#---------------------------------------------------------------------------------------
	lblMonthYearTitle = new qLabel(HijriCaledar) {
		move(40, 30)  resize(360, 60)		
		setStyleSheet("font-family:" + titleFontFamily + "; font-size:" + string(titleFontSize) + "px; font-weight:" + titleFontWeight + ";")
		setAlignment(Qt_AlignHCenter | Qt_AlignVCenter)
	}
#---------------------------------------------------------------------------------------        
        SearchMonthComboBox= createcombobox(HijriCaledar, 130, 25, 5, currCalMonth-1, 12, hMonthNames, loadFont("Changa.ttf"), "bold", "white", "#006400", "#006400", "white", "UpdateMonth()")
        SearchMonthComboBox.move(300, 25)        
#---------------------------------------------------------------------------------------
        SearchYearComboBox= createcombobox(HijriCaledar, 130, 25, 5, currCalYear-1350, 12, hYears, loadFont("Changa.ttf"), "bold", "white", "#006400", "#006400", "white", "UpdateYear()")
        SearchYearComboBox.move(10, 25)
#---------------------------------------------------------------------------------------
	btnPrev = new qPushButton(HijriCaledar) {
		move(10, 53)  resize(35, 35)
		setText("◀")
		setupButton(self, 30, "normal", "white", "#179672", "#00CE00","0px 0px 0px 0px", "1px", "solid", "#00FFFF", "4px", 
		loadFont("Changa.ttf"), "", "navigateCalendar(-1)")
	}
#---------------------------------------------------------------------------------------
	btnNext = new qPushButton(HijriCaledar) {
		move(395, 53)  resize(35, 35)
		setText("▶")
		setupButton(self, 30, "normal", "white", "#179672", "#00CE00","0px 0px 0px 0px", "1px", "solid", "#00FFFF", "4px", 
		loadFont("Changa.ttf"), "", "navigateCalendar(1)")
	}
#---------------------------------------------------------------------------------------
	gridCalendar = new qTableWidget(HijriCaledar) {
		move(10, 90)  resize(420, 400)    
		setEditTriggers(QAbstractItemView_NoEditTriggers)
		setShowGrid(false)
		setSelectionMode(QAbstractItemView_NoSelection)
		horizontalHeader().hide()
		verticalHeader().hide()
		horizontalHeader().setSectionResizeMode(1)
		setHorizontalScrollBarPolicy(1)
		setVerticalScrollBarPolicy(1)
	}
#---------------------------------------------------------------------------------------
	back2Today = new qPushButton(HijriCaledar) {
		setText("العودة للتاريخ الحالي")
		move(120, 420)  resize(200, 40)
		setupButton(self, 16, "bold", "white", "#179672", "#00CE00","0px 0px 5px 0px", "1px", "solid", "#00FFFF", "10px", 
		loadFont("Changa.ttf"), "", "backToday()")
	}
    } # end HijriCaledar GroupBox

#"═════════════════════════════════════════════════════════════════════════════════════"
#                        Hijri Month Images
#"═════════════════════════════════════════════════════════════════════════════════════"	
        Hijri_Images = new QLabel(win) {
		move(510, 112)  resize(300, 470)
		Hijri_Images.setPixmap(new QPixmap(string(currCalMonth) + ".png"))
		styleLabel(self,16,"bold","white","#transparent","3px 3px 3px 3px","2px","solid","#006400","8px",loadFont("Changa.ttf"))        
            	setScaledContents(True)
        }

#"═════════════════════════════════════════════════════════════════════════════════════"
#                        Buttons Menu
#"═════════════════════════════════════════════════════════════════════════════════════"
	Gregorian_2_Hijri_btn = new qPushButton(win) {
		setGeometry(840, 115, 200, 40)
		setText("    تحويل التاريخ الميلادي")
		setupButton(self, 16, "bold", "white", "#179672", "#00CE00","0px 0px 5px 0px", "2px", "solid", "#00FFFF", "10px", 
		loadFont("Changa.ttf"), "icon1.png", "showCovnertG2H()")
	}
#---------------------------------------------------------------------------------------
	Hijri_2_Gregorian_btn = new qPushButton(win) {
		setGeometry(840, 165, 200, 40)
		setText("      تحويل التاريخ الهجري")
		setupButton(self, 16, "bold", "white", "#179672", "#00CE00","0px 0px 5px 0px", "2px", "solid", "#00FFFF", "10px", 
		loadFont("Changa.ttf"), "icon1.png", "showCovnertH2G()")
	}
#---------------------------------------------------------------------------------------
	Gregorian_Age = new qPushButton(win) {
		setGeometry(840, 215, 200, 40)
		setText("   حساب العمر بالميلادي")
		setupButton(self, 16, "bold", "white", "#179672", "#00CE00","0px 0px 5px 0px", "2px", "solid", "#00FFFF", "10px", 
		loadFont("Changa.ttf"), "icon1.png", "showGregorianAge()")
	}
#---------------------------------------------------------------------------------------
	Hijri_Age = new qPushButton(win) {
		setGeometry(840, 265, 200, 40)
		setText("     حساب العمر بالهجري")
		setupButton(self, 16, "bold", "white", "#179672", "#00CE00","0px 0px 5px 0px", "2px", "solid", "#00FFFF", "10px", 
		loadFont("Changa.ttf"), "icon1.png", "showHijriAge()")
	}
#---------------------------------------------------------------------------------------
	Gregorian_Period = new qPushButton(win) {
		setGeometry(840, 315, 200, 40)
		setText("    حساب فترة بالميلادي")
		setupButton(self, 16, "bold", "white", "#179672", "#00CE00","0px 0px 5px 0px", "2px", "solid", "#00FFFF", "10px", 
		loadFont("Changa.ttf"), "icon1.png", "showGregorianPeriod()")
	}
#---------------------------------------------------------------------------------------
	Hijri_Period = new qPushButton(win) {
		setGeometry(840, 365, 200, 40)
		setText("       حساب فترة بالهجري")
		setupButton(self, 16, "bold", "white", "#179672", "#00CE00","0px 0px 5px 0px", "2px", "solid", "#00FFFF", "10px", 
		loadFont("Changa.ttf"), "icon1.png", "showHijriPeriod()")
	}
#---------------------------------------------------------------------------------------
	Gregorian_Add = new qPushButton(win) {
		setGeometry(840, 415, 200, 40)
		setText("       إضافة لتاريخ ميلادي")
		setupButton(self, 16, "bold", "white", "#179672", "#00CE00","0px 0px 5px 0px", "2px", "solid", "#00FFFF", "10px", 
		loadFont("Changa.ttf"), "icon1.png", "showGregorianAdd()")
	}
#---------------------------------------------------------------------------------------
	Hijri_Add = new qPushButton(win) {
		setGeometry(840, 465, 200, 40)
		setText("           إضافة لتاريخ هجري")
		setupButton(self, 16, "bold", "white", "#179672", "#00CE00","0px 0px 5px 0px", "2px", "solid", "#00FFFF", "10px", 
		loadFont("Changa.ttf"), "icon1.png", "showHijriAdd()")
	}
#---------------------------------------------------------------------------------------
	Reamaining = new qPushButton(win) {
		setGeometry(840, 515, 200, 40)
		setText(" المتبقي على المناسبات")
		setupButton(self, 16, "bold", "white", "#179672", "#00CE00","0px 0px 5px 0px", "2px", "solid", "#00FFFF", "10px", 
		loadFont("Changa.ttf"), "icon1.png", "showReamaining()")
	}
#"═════════════════════════════════════════════════════════════════════════════════════"
#                         Current Time 
#"═════════════════════════════════════════════════════════════════════════════════════"
	Current_Time = new qGroupBox(win) {
		move(863, 557)  resize(400, 100)
		setStyleSheet("QGroupBox {font-family: " + loadFont("Changa.ttf") + "; font-size: 15px; font-weight: bold; color: white; border: 0px solid #006400; border-radius: 8px; margin-top: 0px; background-color: transparent; }" +
		"QGroupBox::title {subcontrol-origin: margin;min-width: 0px;min-height: 15px;left: 0px; padding: 0px 0px 0px 0px; background-color: #179672; border-radius: 5px; }")
#---------------------------------------------------------------------------------------
		lblTime = new qLabel(Current_Time) {
		setGeometry(5, 5, 300, 40)
		styleLabel(self,16,"bold","#179672","transparent","0px 28px 8px 0px","0px","solid","transparent","8px",loadFont("Changa.ttf"))
		}
#---------------------------------------------------------------------------------------
		lblStatus = new qLabel(Current_Time) {
		setGeometry(100, 5, 300, 40)
		styleLabel(self,16,"bold","#179672","transparent","0px 28px 8px 0px","0px","solid","yellow","8px",loadFont("Changa.ttf"))
		}
#---------------------------------------------------------------------------------------
		new qTimer(win) {
		setInterval(1000)
		settimeoutEvent("updateClock12()")
		start()
	}
   } # end Current_Time GroupBox
#"═════════════════════════════════════════════════════════════════════════════════════"
#                        Vertical Line 
#"═════════════════════════════════════════════════════════════════════════════════════"
	line1 = new qLabel(win) {
		move(830, 88)resize(5, 514)
		setStyleSheet("background-color: #179672;")
	}
#"═════════════════════════════════════════════════════════════════════════════════════"
#               Gregorian to Hijri Date Converter Elements                  
#"═════════════════════════════════════════════════════════════════════════════════════"
	Gregorian_2_Hijri = new qGroupBox(win) {
		setTitle(" تحويل التاريخ الميلادي ")
		move(510, 110)  resize(300, 470)
		setStyleSheet("QGroupBox {font-family: " + loadFont("Changa.ttf") + "; font-size: 15px; font-weight: bold; color: white; border: 2px solid #006400; border-radius: 8px; margin-top: 16px; background-color: transparent; }" +
		"QGroupBox::title {subcontrol-origin: margin;min-width: 150px;min-height: 15px;left: 70px; padding: 0px 0px 2px 0px; background-color: #179672; border-radius: 5px; }")
#---------------------------------------------------------------------------------------
	Gregorian_2_Hijri_Label = new qLabel(Gregorian_2_Hijri) {
		move(0,35)resize(300,40)
		setText( "اليوم" + copy(" ", 20) + "الشهر" + copy(" ", 20) + "السنة" )
		styleLabel(self,12,"bold","#008000","transparent","0px 0px 0px 0px","0px","solid","#000099","8px",loadFont("Changa.ttf"))
		setAlignment(Qt_AlignHCenter | Qt_AlignVCenter)
		}
#---------------------------------------------------------------------------------------
	Gregorian_2_Hijri_Day_ComboBox = createcombobox(Gregorian_2_Hijri, 80, 25, 5, 17, 12, gDays, loadFont("Changa.ttf"), "bold", "white", "#006400", "#006400", "white", "showCovnertG2H()")
        Gregorian_2_Hijri_Day_ComboBox.move(210, 75)
#--------------------------------------------------------------------------------------- 
	Gregorian_2_Hijri_Month_ComboBox = createcombobox(Gregorian_2_Hijri, 80, 25, 5, 4, 12, ghMonth, loadFont("Changa.ttf"), "bold", "white", "#006400", "#006400", "white", "showCovnertG2H()")
        Gregorian_2_Hijri_Month_ComboBox.move(110, 75)
#---------------------------------------------------------------------------------------
	Gregorian_2_Hijri_Year_ComboBox = createcombobox(Gregorian_2_Hijri, 80, 25, 5, 0, 12, gYears, loadFont("Changa.ttf"), "bold", "white", "#006400", "#006400", "white", "showCovnertG2H()")
        Gregorian_2_Hijri_Year_ComboBox.move(10, 75)
#---------------------------------------------------------------------------------------
	Gregorian2HijriResult = new qLabel(Gregorian_2_Hijri) {
		move(10, 255)  resize(280, 200)
		setWordWrap(true)		
		styleLabel(self,13,"bold","white","#179672","0px 0px 0px 0px","1.5px","solid","#00FFFF","8px",loadFont("Changa.ttf"))
		setAlignment(Qt_AlignHCenter | Qt_AlignVCenter)	
	}
   } # end Gregorian_2_Hijri GroupBox

#"═════════════════════════════════════════════════════════════════════════════════════"
#               Hijri to Gregorian Date Converter Elements                  
#"═════════════════════════════════════════════════════════════════════════════════════"
	Hijri_2_Gregorian = new qGroupBox(win) {
		setTitle(" تحويل التاريخ الهجري ")
		move(510, 110)  resize(300, 470)
		setStyleSheet("QGroupBox {font-family: " + loadFont("Changa.ttf") + "; font-size: 15px; font-weight: bold; color: white; border: 2px solid #006400; border-radius: 8px; margin-top: 16px; background-color: transparent; }" +
		"QGroupBox::title {subcontrol-origin: margin;min-width: 150px;min-height: 15px;left: 70px; padding: 0px 0px 2px 0px; background-color: #179672; border-radius: 5px; }")
#---------------------------------------------------------------------------------------
	Hijri_2_Gregorian_Label = new qLabel(Hijri_2_Gregorian) {
		move(0,35)resize(300,40)
		setText( "اليوم" + copy(" ", 20) + "الشهر" + copy(" ", 20) + "السنة" )
		styleLabel(self,12,"bold","#008000","transparent","0px 0px 0px 0px","0px","solid","#000099","8px",loadFont("Changa.ttf"))
		setAlignment(Qt_AlignHCenter | Qt_AlignVCenter)
		}
#---------------------------------------------------------------------------------------
	Hijri_2_Gregorian_Day_ComboBox = createcombobox(Hijri_2_Gregorian, 80, 25, 5, 0, 12, hDays, loadFont("Changa.ttf"), "bold", "white", "#006400", "#006400", "white", "showCovnertH2G()")
        Hijri_2_Gregorian_Day_ComboBox.move(210, 75)
#---------------------------------------------------------------------------------------
	Hijri_2_Gregorian_Month_ComboBox = createcombobox(Hijri_2_Gregorian, 80, 25, 5, 0, 12, ghMonth, loadFont("Changa.ttf"), "bold", "white", "#006400", "#006400", "white", "showCovnertH2G()")
        Hijri_2_Gregorian_Month_ComboBox.move(110, 75)
#---------------------------------------------------------------------------------------
	Hijri_2_Gregorian_Year_ComboBox = createcombobox(Hijri_2_Gregorian, 80, 25, 5, 0, 12, hYears, loadFont("Changa.ttf"), "bold", "white", "#006400", "#006400", "white", "showCovnertH2G()")
        Hijri_2_Gregorian_Year_ComboBox.move(10, 75)
#---------------------------------------------------------------------------------------
	Hijri_2_GregorianResult = new qLabel(Hijri_2_Gregorian) {
		move(10, 255)  resize(280, 200)
		setWordWrap(true)		
		styleLabel(self,13,"bold","white","#179672","0px 0px 0px 0px","1.5px","solid","#00FFFF","8px",loadFont("Changa.ttf"))
		setAlignment(Qt_AlignHCenter | Qt_AlignVCenter)	
	}
    }    # end Hijri_2_Gregorian GroupBox

#"═════════════════════════════════════════════════════════════════════════════════════"
#               Gregorian Age Calculator Elements                  
#"═════════════════════════════════════════════════════════════════════════════════════"
	Gregorian_Age_Calculator = new qGroupBox(win) {
		setTitle(" حساب العمر بالميلادي ")
		move(510, 110)  resize(300, 470)
		setStyleSheet("QGroupBox {font-family: " + loadFont("Changa.ttf") + "; font-size: 15px; font-weight: bold; color: white; border: 2px solid #006400; border-radius: 8px; margin-top: 16px; background-color: transparent; }" +
		"QGroupBox::title {subcontrol-origin: margin;min-width: 150px;min-height: 15px;left: 70px; padding: 0px 0px 2px 0px; background-color: #179672; border-radius: 5px; }")
#---------------------------------------------------------------------------------------
	Gregorian_Age_Calculator_Label = new qLabel(Gregorian_Age_Calculator) {
		move(0,35)resize(300,40)
		setText( "اليوم" + copy(" ", 20) + "الشهر" + copy(" ", 20) + "السنة" )
		styleLabel(self,12,"bold","#008000","transparent","0px 0px 0px 0px","0px","solid","#000099","8px",loadFont("Changa.ttf"))
		setAlignment(Qt_AlignHCenter | Qt_AlignVCenter)
		}
#---------------------------------------------------------------------------------------
	Gregorian_Age_Day_ComboBox = createcombobox(Gregorian_Age_Calculator, 80, 25, 5, 7, 12, gDays, loadFont("Changa.ttf"), "bold", "white", "#006400", "#006400", "white", "showGregorianAge()")
        Gregorian_Age_Day_ComboBox.move(210, 75)
#--------------------------------------------------------------------------------------- 
	Gregorian_Age_Month_ComboBox = createcombobox(Gregorian_Age_Calculator, 80, 25, 5, 5, 12, ghMonth, loadFont("Changa.ttf"), "bold", "white", "#006400", "#006400", "white", "showGregorianAge()")
        Gregorian_Age_Month_ComboBox.move(110, 75)
#---------------------------------------------------------------------------------------
	Gregorian_Age_Year_ComboBox = createcombobox(Gregorian_Age_Calculator, 80, 25, 5,(1977-1931), 12, gYears, loadFont("Changa.ttf"), "bold", "white", "#006400", "#006400", "white", "showGregorianAge()")
        Gregorian_Age_Year_ComboBox.move(10, 75)
#---------------------------------------------------------------------------------------
	Gregorian_AgeResult = new qLabel(Gregorian_Age_Calculator) {
		move(10, 255)  resize(280, 200)
		setWordWrap(true)		
		styleLabel(self,13,"bold","white","#179672","0px 0px 0px 0px","1.5px","solid","#00FFFF","8px",loadFont("Changa.ttf"))
		setAlignment(Qt_AlignHCenter | Qt_AlignVCenter)	
	}
    } # end Gregorian_Age_Calculator GroupBox

#"═════════════════════════════════════════════════════════════════════════════════════"
#               Hijri Age Calculator Elements                  
#"═════════════════════════════════════════════════════════════════════════════════════"
	Hijri_Age_Calculator = new qGroupBox(win) {
		setTitle(" حساب العمر بالهجري ")
		move(510, 110)  resize(300, 470)
		setStyleSheet("QGroupBox {font-family: " + loadFont("Changa.ttf") + "; font-size: 15px; font-weight: bold; color: white; border: 2px solid #006400; border-radius: 8px; margin-top: 16px; background-color: transparent; }" +
		"QGroupBox::title {subcontrol-origin: margin;min-width: 150px;min-height: 15px;left: 70px; padding: 0px 0px 2px 0px; background-color: #179672; border-radius: 5px; }")
#---------------------------------------------------------------------------------------
	Hijri_Age_Calculator_Label = new qLabel(Hijri_Age_Calculator) {
		move(0,35)resize(300,40)
		setText( "اليوم" + copy(" ", 20) + "الشهر" + copy(" ", 20) + "السنة" )
		styleLabel(self,12,"bold","#008000","transparent","0px 0px 0px 0px","0px","solid","#000099","8px",loadFont("Changa.ttf"))
		setAlignment(Qt_AlignHCenter | Qt_AlignVCenter)
		}
#---------------------------------------------------------------------------------------
	Hijri_Age_Day_ComboBox = createcombobox(Hijri_Age_Calculator, 80, 25, 5, 20, 12, hDays, loadFont("Changa.ttf"), "bold", "white", "#006400", "#006400", "white", "showHijriAge()")
        Hijri_Age_Day_ComboBox.move(210, 75)
#--------------------------------------------------------------------------------------- 
	Hijri_Age_Month_ComboBox = createcombobox(Hijri_Age_Calculator, 80, 25, 5, 5, 12, ghMonth, loadFont("Changa.ttf"), "bold", "white", "#006400", "#006400", "white", "showHijriAge()")
        Hijri_Age_Month_ComboBox.move(110, 75)
#---------------------------------------------------------------------------------------
	Hijri_Age_Year_ComboBox = createcombobox(Hijri_Age_Calculator, 80, 25, 5,(1397-1350), 12, hYears, loadFont("Changa.ttf"), "bold", "white", "#006400", "#006400", "white", "showHijriAge()")
        Hijri_Age_Year_ComboBox.move(10, 75)
#---------------------------------------------------------------------------------------
	Hijri_AgeResult = new qLabel(Hijri_Age_Calculator) {
		move(10, 255)  resize(280, 200)
		setWordWrap(true)		
		styleLabel(self,13,"bold","white","#179672","0px 0px 0px 0px","1.5px","solid","#00FFFF","8px",loadFont("Changa.ttf"))
		setAlignment(Qt_AlignHCenter | Qt_AlignVCenter)	
	}
    }  # end Hijri_Age_Calculator GroupBox

#"═════════════════════════════════════════════════════════════════════════════════════"
#               Gregorian Period Calculator Elements                  
#"═════════════════════════════════════════════════════════════════════════════════════"
	Gregorian_Period_Calculator = new qGroupBox(win) {
		setTitle(" حساب فترة بالميلادي ")
		move(510, 110)  resize(300, 470)
		setStyleSheet("QGroupBox {font-family: " + loadFont("Changa.ttf") + "; font-size: 15px; font-weight: bold; color: white; border: 2px solid #006400; border-radius: 8px; margin-top: 16px; background-color: transparent; }" +
		"QGroupBox::title {subcontrol-origin: margin;min-width: 150px;min-height: 15px;left: 70px; padding: 0px 0px 2px 0px; background-color: #179672; border-radius: 5px; }")
#---------------------------------------------------------------------------------------
	Gregorian_Period_Calculator_Label = new qLabel(Gregorian_Period_Calculator) {
		move(0,35)resize(300,40)
		setText( "اليوم" + copy(" ", 20) + "الشهر" + copy(" ", 20) + "السنة" )
		styleLabel(self,12,"bold","#008000","transparent","0px 0px 0px 0px","0px","solid","#000099","8px",loadFont("Changa.ttf"))
		setAlignment(Qt_AlignHCenter | Qt_AlignVCenter)
		}
#---------------------------------------------------------------------------------------
	Gregorian_Period1_Day_ComboBox = createcombobox(Gregorian_Period_Calculator, 80, 25, 3, 0, 12, gDays, loadFont("Changa.ttf"), "bold", "white", "#006400", "#006400", "white", "showGregorianPeriod()")
        Gregorian_Period1_Day_ComboBox.move(210, 75)
#---------------------------------------------------------------------------------------
	Gregorian_Period1_Month_ComboBox = createcombobox(Gregorian_Period_Calculator, 80, 25, 3, 0, 12, ghMonth, loadFont("Changa.ttf"), "bold", "white", "#006400", "#006400", "white","showGregorianPeriod()")
        Gregorian_Period1_Month_ComboBox.move(110, 75)
#---------------------------------------------------------------------------------------
	Gregorian_Period1_Year_ComboBox = createcombobox(Gregorian_Period_Calculator, 80, 25, 3,(2000-1931), 12, gYears, loadFont("Changa.ttf"), "bold", "white", "#006400", "#006400", "white","showGregorianPeriod()")
        Gregorian_Period1_Year_ComboBox.move(10, 75)
#---------------------------------------------------------------------------------------
	Gregorian_Period2_Day_ComboBox = createcombobox(Gregorian_Period_Calculator, 80, 25, 3, number(TimeList()[6])-1, 12, gDays, loadFont("Changa.ttf"), "bold", "white", "#006400", "#006400", "white","showGregorianPeriod()")
        Gregorian_Period2_Day_ComboBox.move(210, 188)
#---------------------------------------------------------------------------------------
	Gregorian_Period2_Month_ComboBox = createcombobox(Gregorian_Period_Calculator, 80, 25, 3, number(TimeList()[10])-1, 12, ghMonth, loadFont("Changa.ttf"), "bold", "white", "#006400", "#006400", "white","showGregorianPeriod()")
        Gregorian_Period2_Month_ComboBox.move(110, 188)
#---------------------------------------------------------------------------------------
	Gregorian_Period2_Year_ComboBox = createcombobox(Gregorian_Period_Calculator, 80, 25, 3,(number(TimeList()[19])-1931), 12, gYears, loadFont("Changa.ttf"), "bold", "white", "#006400", "#006400", "white","showGregorianPeriod()")
        Gregorian_Period2_Year_ComboBox.move(10, 188)
#---------------------------------------------------------------------------------------
	Gregorian_PeriodResult = new qLabel(Gregorian_Period_Calculator) {
		move(10, 307)  resize(280, 150)
		setWordWrap(true)		
		styleLabel(self,13,"bold","white","#179672","0px 0px 0px 0px","1.5px","solid","#00FFFF","8px",loadFont("Changa.ttf"))
		setAlignment(Qt_AlignHCenter | Qt_AlignVCenter)	
	}
    }  # end Gregorian Period Calculator GroupBox

#"═════════════════════════════════════════════════════════════════════════════════════"
#               Hijri Period Calculator Elements                  
#"═════════════════════════════════════════════════════════════════════════════════════"
	Hijri_Period_Calculator = new qGroupBox(win) {
		setTitle(" حساب فترة بالهجري ")
		move(510, 110)  resize(300, 470)
		setStyleSheet("QGroupBox {font-family: " + loadFont("Changa.ttf") + "; font-size: 15px; font-weight: bold; color: white; border: 2px solid #006400; border-radius: 8px; margin-top: 16px; background-color: transparent; }" +
		"QGroupBox::title {subcontrol-origin: margin;min-width: 150px;min-height: 15px;left: 70px; padding: 0px 0px 2px 0px; background-color: #179672; border-radius: 5px; }")
#---------------------------------------------------------------------------------------
	Hijri_Period_Calculator_Label = new qLabel(Hijri_Period_Calculator) {
		move(0,35)resize(300,40)
		setText( "اليوم" + copy(" ", 20) + "الشهر" + copy(" ", 20) + "السنة" )
		styleLabel(self,12,"bold","#008000","transparent","0px 0px 0px 0px","0px","solid","#000099","8px",loadFont("Changa.ttf"))
		setAlignment(Qt_AlignHCenter | Qt_AlignVCenter)	
		}
#---------------------------------------------------------------------------------------
	Hijri_Period1_Day_ComboBox = createcombobox(Hijri_Period_Calculator, 80, 25, 3, 0, 12, hDays, loadFont("Changa.ttf"), "bold", "white", "#006400", "#006400", "white", "showHijriPeriod()")
        Hijri_Period1_Day_ComboBox.move(210, 75)
#--------------------------------------------------------------------------------------- 
	Hijri_Period1_Month_ComboBox = createcombobox(Hijri_Period_Calculator, 80, 25, 3, 0, 12, ghMonth, loadFont("Changa.ttf"), "bold", "white", "#006400", "#006400", "white","showHijriPeriod()")
        Hijri_Period1_Month_ComboBox.move(110, 75)
#---------------------------------------------------------------------------------------
	Hijri_Period1_Year_ComboBox = createcombobox(Hijri_Period_Calculator, 80, 25, 3,(1400-1350), 12, hYears, loadFont("Changa.ttf"), "bold", "white", "#006400", "#006400", "white","showHijriPeriod()")
        Hijri_Period1_Year_ComboBox.move(10, 75)
#---------------------------------------------------------------------------------------
	Hijri_Period2_Day_ComboBox = createcombobox(Hijri_Period_Calculator, 80, 25, 3, currCalday-1, 12, hDays, loadFont("Changa.ttf"), "bold", "white", "#006400", "#006400", "white","showHijriPeriod()")
        Hijri_Period2_Day_ComboBox.move(210, 188)
#--------------------------------------------------------------------------------------- 
	Hijri_Period2_Month_ComboBox = createcombobox(Hijri_Period_Calculator, 80, 25, 3, currCalMonth-1, 12, ghMonth, loadFont("Changa.ttf"), "bold", "white", "#006400", "#006400", "white","showHijriPeriod()")
        Hijri_Period2_Month_ComboBox.move(110, 188)
#---------------------------------------------------------------------------------------
	Hijri_Period2_Year_ComboBox = createcombobox(Hijri_Period_Calculator, 80, 25, 3,(currCalYear-1350), 12, hYears, loadFont("Changa.ttf"), "bold", "white", "#006400", "#006400", "white","showHijriPeriod()")
        Hijri_Period2_Year_ComboBox.move(10, 188)
#---------------------------------------------------------------------------------------
	Hijri_PeriodResult = new qLabel(Hijri_Period_Calculator) {
		move(10, 307)  resize(280, 150)
		setWordWrap(true)		
		styleLabel(self,13,"bold","white","#179672","0px 0px 0px 0px","1.5px","solid","#00FFFF","8px",loadFont("Changa.ttf"))
		setAlignment(Qt_AlignHCenter | Qt_AlignVCenter)		
	}
    }  # end Hijri_Period_Calculator GroupBox


#"═════════════════════════════════════════════════════════════════════════════════════"
#               Add Period To Gregorian Elements                  
#"═════════════════════════════════════════════════════════════════════════════════════"
	Gregorian_Add = new qGroupBox(win) {
		setTitle(" إضافة لتاريخ ميلادي ")
		move(510, 110)  resize(300, 470)
		setStyleSheet("QGroupBox {font-family: " + loadFont("Changa.ttf") + "; font-size: 15px; font-weight: bold; color: white; border: 2px solid #006400; border-radius: 8px; margin-top: 16px; background-color: transparent; }" +
		"QGroupBox::title {subcontrol-origin: margin;min-width: 150px;min-height: 15px;left: 70px; padding: 0px 0px 2px 0px; background-color: #179672; border-radius: 5px; }")
                  
#---------------------------------------------------------------------------------------	
	Gregorian_Add_Label = new qLabel(Gregorian_Add) {
		move(0,35)resize(300,40)
		setText( "اليوم" + copy(" ", 20) + "الشهر" + copy(" ", 20) + "السنة" )
		styleLabel(self,12,"bold","#008000","transparent","0px 0px 0px 0px","0px","solid","#000099","8px",loadFont("Changa.ttf"))
		setAlignment(Qt_AlignHCenter | Qt_AlignVCenter)
		}
#---------------------------------------------------------------------------------------
	Gregorian_Date_Day_ComboBox = createcombobox(Gregorian_Add, 80, 25, 3, 0, 12, gDays, loadFont("Changa.ttf"), "bold", "white", "#006400", "#006400", "white", "showGregorianAdd()")
        Gregorian_Date_Day_ComboBox.move(210, 75)
#--------------------------------------------------------------------------------------- 
	Gregorian_Date_Month_ComboBox = createcombobox(Gregorian_Add, 80, 25, 3, 0, 12, ghMonth, loadFont("Changa.ttf"), "bold", "white", "#006400", "#006400", "white","showGregorianAdd()")
        Gregorian_Date_Month_ComboBox.move(110, 75)
#-----------------------------------------------------------------
	Gregorian_Date_Year_ComboBox = createcombobox(Gregorian_Add, 80, 25, 3,(2000-1931), 12, gYears, loadFont("Changa.ttf"), "bold", "white", "#006400", "#006400", "white","showGregorianAdd()")
        Gregorian_Date_Year_ComboBox.move(10, 75)
#---------------------------------------------------------------------------------------
	Gregorian_Add_Day_ComboBox = createcombobox(Gregorian_Add, 80, 25, 3, 0, 12, adGDays, loadFont("Changa.ttf"), "bold", "white", "#006400", "#006400", "white","showGregorianAdd()")
        Gregorian_Add_Day_ComboBox.move(210, 188)
#--------------------------------------------------------------------------------------- 
	Gregorian_Add_Month_ComboBox = createcombobox(Gregorian_Add, 80, 25, 3, 0, 12, adMonth, loadFont("Changa.ttf"), "bold", "white", "#006400", "#006400", "white","showGregorianAdd()")
        Gregorian_Add_Month_ComboBox.move(110, 188)
#---------------------------------------------------------------------------------------
	Gregorian_Add_Year_ComboBox = createcombobox(Gregorian_Add, 80, 25, 3, 0, 12, adYears, loadFont("Changa.ttf"), "bold", "white", "#006400", "#006400", "white","showGregorianAdd()")
        Gregorian_Add_Year_ComboBox.move(10, 188)
#---------------------------------------------------------------------------------------
	Gregorian_AddResult = new qLabel(Gregorian_Add) {
		move(10, 307)  resize(280, 150)
		setWordWrap(true)		
		styleLabel(self,13,"bold","white","#179672","0px 0px 0px 0px","1.5px","solid","#00FFFF","8px",loadFont("Changa.ttf"))
		setAlignment(Qt_AlignHCenter | Qt_AlignVCenter)	
	}
    }  # end Gregorian_Add GroupBox

#"═════════════════════════════════════════════════════════════════════════════════════"
#               Add Period To Hijri Elements                  
#"═════════════════════════════════════════════════════════════════════════════════════"
	Hijri_Add = new qGroupBox(win) {
		setTitle(" الإضافة لتاريخ هجري ")
		move(510, 110)  resize(300, 470)
		setStyleSheet("QGroupBox {font-family: " + loadFont("Changa.ttf") + "; font-size: 15px; font-weight: bold; color: white; border: 2px solid #006400; border-radius: 8px; margin-top: 16px; background-color: transparent; }" +
		"QGroupBox::title {subcontrol-origin: margin;min-width: 150px;min-height: 15px;left: 70px; padding: 0px 0px 2px 0px; background-color: #179672; border-radius: 5px; }")
#---------------------------------------------------------------------------------------
	Hijri_Add_Label = new qLabel(Hijri_Add) {
		move(0,35)resize(300,40)
		setText( "اليوم" + copy(" ", 20) + "الشهر" + copy(" ", 20) + "السنة" )
		styleLabel(self,12,"bold","#008000","transparent","0px 0px 0px 0px","0px","solid","#000099","8px",loadFont("Changa.ttf"))
		setAlignment(Qt_AlignHCenter | Qt_AlignVCenter)
		}
#---------------------------------------------------------------------------------------
	Hijri_Date_Day_ComboBox = createcombobox(Hijri_Add, 80, 25, 3, 0, 12, hDays, loadFont("Changa.ttf"), "bold", "white", "#006400", "#006400", "white", "showHijriAdd()")
        Hijri_Date_Day_ComboBox.move(210, 75)
#--------------------------------------------------------------------------------------- 
	Hijri_Date_Month_ComboBox = createcombobox(Hijri_Add, 80, 25, 3, 0, 12, ghMonth, loadFont("Changa.ttf"), "bold", "white", "#006400", "#006400", "white","showHijriAdd()")
        Hijri_Date_Month_ComboBox.move(110, 75)
#---------------------------------------------------------------------------------------
	Hijri_Date_Year_ComboBox = createcombobox(Hijri_Add, 80, 25, 3,(1400-1350), 12, hYears, loadFont("Changa.ttf"), "bold", "white", "#006400", "#006400", "white","showHijriAdd()")
        Hijri_Date_Year_ComboBox.move(10, 75)
#---------------------------------------------------------------------------------------
	Hijri_Add_Day_ComboBox = createcombobox(Hijri_Add, 80, 25, 3, 0, 12, adHDays, loadFont("Changa.ttf"), "bold", "white", "#006400", "#006400", "white","showHijriAdd()")
        Hijri_Add_Day_ComboBox.move(210, 188)
#--------------------------------------------------------------------------------------- 
	Hijri_Add_Month_ComboBox = createcombobox(Hijri_Add, 80, 25, 3, 0, 12, adMonth, loadFont("Changa.ttf"), "bold", "white", "#006400", "#006400", "white","showHijriAdd()")
        Hijri_Add_Month_ComboBox.move(110, 188)
#---------------------------------------------------------------------------------------
	Hijri_Add_Year_ComboBox = createcombobox(Hijri_Add, 80, 25, 3,0, 12, adYears, loadFont("Changa.ttf"), "bold", "white", "#006400", "#006400", "white","showHijriAdd()")
        Hijri_Add_Year_ComboBox.move(10, 188)
#---------------------------------------------------------------------------------------
	Hijri_AddResult = new qLabel(Hijri_Add) {
		move(10, 307)  resize(280, 150)
		setWordWrap(true)		
		styleLabel(self,13,"bold","white","#179672","0px 0px 0px 0px","1.5px","solid","#00FFFF","8px",loadFont("Changa.ttf"))
		setAlignment(Qt_AlignHCenter | Qt_AlignVCenter)	
	}
    }  # end Hijri_Add GroupBox

#"═════════════════════════════════════════════════════════════════════════════════════"
#               Reamaining Days Elements                  
#"═════════════════════════════════════════════════════════════════════════════════════"
	ReamainingDays = new qGroupBox(win) {
		setTitle(" المتبقي على المناسبات ")
		move(510, 110)  resize(300, 470)
		setStyleSheet("QGroupBox {font-family: " + loadFont("Changa.ttf") + "; font-size: 15px; font-weight: bold; color: white; border: 2px solid #006400; border-radius: 8px; margin-top: 16px; background-color: transparent; }" +
		"QGroupBox::title {subcontrol-origin: margin;min-width: 150px;min-height: 15px;left: 70px; padding: 0px 0px 2px 0px; background-color: #179672; border-radius: 5px; }")
#---------------------------------------------------------------------------------------
	Reamainin_Gregorian_Year_Result = new qLabel(ReamainingDays) {
		move(5,50)resize(300,80)
		styleLabel(self,12,"bold","blue","transparent","0px 0px 0px 0px","0px","solid","blue","8px",loadFont("Changa.ttf"))
		setAlignment(Qt_AlignHCenter | Qt_AlignVCenter)
	}
#---------------------------------------------------------------------------------------
	Reamainin_Hijri_Year_Result = new qLabel(ReamainingDays) {
		move(5,140)resize(300,80)
		styleLabel(self,12,"bold","blue","transparent","0px 0px 0px 0px","0px","solid","blue","8px",loadFont("Changa.ttf"))
		setAlignment(Qt_AlignHCenter | Qt_AlignVCenter)
	}
#---------------------------------------------------------------------------------------
	Reamainin_Ramadan_Result = new qLabel(ReamainingDays) {
		move(5,230)resize(300,80)
		styleLabel(self,12,"bold","blue","transparent","0px 0px 0px 0px","0px","solid","blue","8px",loadFont("Changa.ttf"))
		setAlignment(Qt_AlignHCenter | Qt_AlignVCenter)
	}
#---------------------------------------------------------------------------------------
	Reamainin_Eid_ELfeter_Result = new qLabel(ReamainingDays) {
		move(5,320)resize(300,80)
		styleLabel(self,12,"bold","blue","transparent","0px 8px 0px 0px","0px","solid","blue","8px",loadFont("Changa.ttf"))
		setAlignment(Qt_AlignHCenter | Qt_AlignVCenter)
	}
#---------------------------------------------------------------------------------------
	Reamainin_Eid_ELadha_Result = new qLabel(ReamainingDays) {
		move(0,410)resize(300,80)
		styleLabel(self,12,"bold","blue","transparent","0px 2px 0px 0px","0px","solid","blue","8px",loadFont("Changa.ttf"))
		setAlignment(Qt_AlignHCenter | Qt_AlignVCenter)
	}
    } # end ReamainingDays GroupBox

#"═════════════════════════════════════════════════════════════════════════════════════"
#                           Designed By                  
#"═════════════════════════════════════════════════════════════════════════════════════"
	DesignedBy = new qLabel(win) {
		setGeometry(300, 575, 450, 40)
		setText("Designed By : Mohammed Saber")
		styleLabel(self,12,"bold","#179672","transparent","0px 28px 8px 0px","0px","solid","transparent","8px",loadFont("COPRGTB.ttf"))
		setAlignment(Qt_AlignHCenter | Qt_AlignVCenter)
	}

#"═════════════════════════════════════════════════════════════════════════════════════"
#                           On Form Load                  
#"═════════════════════════════════════════════════════════════════════════════════════"

drawHijriCalendar()      # draw Hijri Calendar


#"═════════════════════════════════════════════════════════════════════════════════════"
#                           Show Window                  
#"═════════════════════════════════════════════════════════════════════════════════════"

show()}

#"═════════════════════════════════════════════════════════════════════════════════════"
#                           Start Program                
#"═════════════════════════════════════════════════════════════════════════════════════"

exec()}


#"═════════════════════════════════════════════════════════════════════════════════════"
#"                         5-  Function                                                "
#"═════════════════════════════════════════════════════════════════════════════════════"

#"═════════════════════════════════════════════════════════════════════════════════════"
#"                     Load local Font  Function                                       "
#"═════════════════════════════════════════════════════════════════════════════════════"

func loadFont fontFile
oFontDB = new QFontDatabase()
fontId = oFontDB.addApplicationFont(fontFile)
if fontId = -1 return "Arial" ok
families = oFontDB.applicationFontFamilies(fontId)
if families.count() < 1 return "Arial" ok
return families.at(0)
end

#"═════════════════════════════════════════════════════════════════════════════════════"
#"                     Label Style Function                                            "
#"═════════════════════════════════════════════════════════════════════════════════════"

func styleLabel oLabel, fontSize, fontWeight, textColor, bgColor, padding, bWidth, bStyle, bColor, bRadius, fontName
oFont = new QFont(fontName, 0, 0, 0)
oFont.setPointSize(fontSize)
oFont.setBold( (fontWeight = "bold") )
oLabel.setFont(oFont)
css = "QLabel { " +"color: " + textColor + "; " +"background-color: " + bgColor + "; " +"padding: " + padding + "; " +"border-width: " + bWidth + "; " +"border-style: " + bStyle + "; " +"border-color: " + bColor + "; " +"border-radius: " + bRadius + "; " +"}"
oLabel.setStyleSheet(css)
end

#"═════════════════════════════════════════════════════════════════════════════════════"
#"                        Button Style Function                                        "
#"═════════════════════════════════════════════════════════════════════════════════════"

func setupButton oBtn, fontSize, fontWeight, textColor, bgColor, hoverColor, padding, bWidth, bStyle, bColor, bRadius, fontName, iconPath, clickFunc

 css = "QPushButton { " +"background-color: " + bgColor + "; " + "color: " + textColor + "; " + "font-size: " + fontSize + "px; " + "font-weight: " + fontWeight + "; " +"border-radius: " + bRadius + "; " + "border: " + bWidth + " " + bStyle + " " + bColor + "; " +"font-family: '" + fontName + "'; " + "padding: " + padding + "; " + "}" +"QPushButton:hover { " +"background-color: " + hoverColor + "; " +"}"     
    oBtn.setStyleSheet(css)
    if iconPath != "" setBtnImage(oBtn, iconPath) ok
    if clickFunc != "" oBtn.setClickEvent(clickFunc) ok

end

#"═════════════════════════════════════════════════════════════════════════════════════"
#"                    ComboBox Creator Function                                        "
#"═════════════════════════════════════════════════════════════════════════════════════"

func createcombobox oParent, nWidth, nHeight, nVisible, nDef, fontSize, aList, fontName, fontWeight, bgColor, borderColor, textColor, listBg, cFuncName
    
    nID = len(aComboButtons) + 1    
    oFont = new qFont(fontName, fontSize, 0, 0)
    if fontWeight = "bold" oFont.setBold(True) ok
   
    oBtn = new qPushButton(oParent) {
        setGeometry(0, 0, nWidth, nHeight)
        setText(aList[nDef + 1])
        setFont(oFont)
        setStyleSheet("QPushButton { background-color: "+bgColor+"; border: 1px solid "+borderColor+"; border-radius: 4px; text-align: center; color: "+textColor+"; padding-right: 10px; } QPushButton::menu-indicator { width: 0; height: 0; }")
        setClickEvent("toggleCombo(" + nID + ")")
    }
    
    oArrow = new qLabel(oBtn) {
        setGeometry(nWidth - 18, 0, 20, nHeight)
        setText("▼")
        setStyleSheet("color: "+textColor+"; background: transparent; font-size: 11pt;")
        setAttribute(76, True)
    }
    
    oArrowBtn = new qPushButton(oBtn) {
        setGeometry(nWidth - 18, 0, 20, nHeight)
        setStyleSheet("background-color: transparent; border: none;")
        setClickEvent("toggleCombo(" + nID + ")")
    }
    
    oList = new qListWidget(win) {
        hide()
        setHorizontalScrollBarPolicy(1)
        setLayoutDirection(0)
        setFont(oFont)
        setStyleSheet("QListWidget { border: 1px solid "+borderColor+"; background: "+listBg+"; outline: 0; color: "+textColor+"; } QListWidget::item { height: 28px; padding: 0 5px; } QListWidget::item:selected { background: "+borderColor+"; color: white; }")
        for x in aList addItem(x) next
        for i = 0 to count()-1 item(i).setTextAlignment(Qt_AlignHCenter | Qt_AlignVCenter) next
        setItemClickedEvent("selectItem(" + nID + ")")
    }
    
    add(aComboButtons, oBtn)
    add(aComboLists, oList)
    add(aComboSizes, [nWidth, nVisible, nHeight])
    add(aComboFuncs, cFuncName)
    
    return oBtn
end


#"═════════════════════════════════════════════════════════════════════════════════════"
#"                   ComboBox Dropdowen List Function                                  "
#"═════════════════════════════════════════════════════════════════════════════════════"

func toggleCombo nID
    if nID < 1 or nID > len(aComboButtons) return ok
    
    oBtn = aComboButtons[nID]
    oList = aComboLists[nID]
    nWidth = aComboSizes[nID][1]
    nVisible = aComboSizes[nID][2]
    nBtnHeight = aComboSizes[nID][3]
    
    for i = 1 to len(aComboLists)
        if i != nID and aComboLists[i].isVisible()
            aComboLists[i].hide()
        ok
    next
    
    if oList.isVisible()
        oList.hide()
        return
    ok

    nX = oBtn.x()
    nY = oBtn.y() + nBtnHeight
    oParent = oBtn.parentwidget()
    if not isnull(oParent) and oParent != win
        nX += oParent.x()
        nY += oParent.y()
    ok
    
    nItemHeight = 28
    nCount = oList.count()
    nItems = nVisible
    if nItems > nCount nItems = nCount ok
    nHeight = nItems * nItemHeight + 4
    
    oList.move(nX, nY)
    oList.resize(nWidth, nHeight)
    oList.show()
    oList.raise()
end

#"═════════════════════════════════════════════════════════════════════════════════════"
#"                   ComboBox Select Item Function                                     "
#"═════════════════════════════════════════════════════════════════════════════════════"

func selectItem nID
    if nID < 1 or nID > len(aComboButtons) return ok
    
    oBtn = aComboButtons[nID]
    oList = aComboLists[nID]
    nRow = oList.currentRow()
    cFuncName = aComboFuncs[nID]
    
    if nRow >= 0
        cSelectedText = oList.item(nRow).text()
        oBtn.setText(cSelectedText)
        oList.hide()
     
        if cFuncName != ""
            eval(cFuncName + "()")
        ok
    ok
end


#"═════════════════════════════════════════════════════════════════════════════════════"
#"                    Hijri Calendar Function                                          "
#"═════════════════════════════════════════════════════════════════════════════════════"

func drawHijriCalendar
    
    frameLabel = NULL

    if not isobject(gridCalendar) return ok

    total = 0
    for i = 1350 to currCalYear - 1
        mask = hijriYears[i - 1349]
        for mon = 1 to 12
            total += 29 + ((mask >> (12 - mon)) & 1)
        next
    next
    mask = hijriYears[currCalYear - 1349]
    for mon = 1 to currCalMonth - 1
        total += 29 + ((mask >> (12 - mon)) & 1)
    next
    offset = total + (1 - 1)

    gD = 18 gM = 5 gY = 1931 rem = offset
    while rem > 0
        if gM = 2
            mDays = 28 + ((gY % 4 = 0 and gY % 100 != 0) or (gY % 400 = 0))
        but gM=4 or gM=6 or gM=9 or gM=11
            mDays = 30
        else
            mDays = 31
        ok

        can = mDays - gD
        if rem > can
            rem -= (can + 1)
            gD = 1
            gM++
            if gM > 12
                gM = 1
                gY++
            ok
        else
            gD += rem
            rem = 0
        ok
    end

    firstGDay = gD
    firstGMonth = gM
    firstGYear = gY

    startCol = (offset + 1) % 7

    mask = hijriYears[currCalYear - 1349]
    daysInMonth = 29 + ((mask >> (12 - currCalMonth)) & 1)

    lastDayOffset = offset + daysInMonth - 1

    gD = 18 gM = 5 gY = 1931 rem = lastDayOffset
    while rem > 0
        if gM = 2
            mDays = 28 + ((gY % 4 = 0 and gY % 100 != 0) or (gY % 400 = 0))
        but gM=4 or gM=6 or gM=9 or gM=11
            mDays = 30
        else
            mDays = 31
        ok

        can = mDays - gD
        if rem > can
            rem -= (can + 1)
            gD = 1
            gM++
            if gM > 12
                gM = 1
                gY++
            ok
        else
            gD += rem
            rem = 0
        ok
    end

    lastGMonth = gM
    lastGYear = gY

    midDayOffset = offset + 14

    gD = 18 gM = 5 gY = 1931 rem = midDayOffset
    while rem > 0
        if gM = 2
            mDays = 28 + ((gY % 4 = 0 and gY % 100 != 0) or (gY % 400 = 0))
        but gM=4 or gM=6 or gM=9 or gM=11
            mDays = 30
        else
            mDays = 31
        ok

        can = mDays - gD
        if rem > can
            rem -= (can + 1)
            gD = 1
            gM++
            if gM > 12
                gM = 1
                gY++
            ok
        else
            gD += rem
            rem = 0
        ok
    end

    mainGMonth = gM
    mainGYear = gY

    hijriTitle = "<font color='" + hijriTitleColor + "' style='font-family:" + titleFontFamily + "; font-size:" + string(titleFontSize) + "px; font-weight:" + titleFontWeight + ";'><b>" + hMonthNames[currCalMonth] + " " + string(currCalYear) + " هـ</b></font>"

    if firstGMonth = lastGMonth and firstGYear = lastGYear
        if firstGYear = mainGYear and firstGMonth = mainGMonth
            gregTitle = "<font color='" + gregCurrColor + "' style='font-family:" + titleFontFamily + "; font-size:" + string(titleFontSize-2) + "px; font-weight:" + titleFontWeight + ";'><b>" + gMonthNames[firstGMonth] + " " + string(firstGYear) + "</b></font>"
        else
            gregTitle = "<font color='" + gregOtherColor + "' style='font-family:" + titleFontFamily + "; font-size:" + string(titleFontSize-2) + "px; font-weight:" + titleFontWeight + ";'><b>" + gMonthNames[firstGMonth] + " " + string(firstGYear) + "</b></font>"
        ok
    else
        if firstGYear = mainGYear and firstGMonth = mainGMonth
            firstPart = "<font color='" + gregCurrColor + "'><b>" + gMonthNames[firstGMonth] + " " + string(firstGYear) + "</b></font>"
        else
            firstPart = "<font color='" + gregOtherColor + "'><b>" + gMonthNames[firstGMonth] + " " + string(firstGYear) + "</b></font>"
        ok
        
        if lastGYear = mainGYear and lastGMonth = mainGMonth
            lastPart = "<font color='" + gregCurrColor + "'><b>" + gMonthNames[lastGMonth] + " " + string(lastGYear) + "</b></font>"
        else
            lastPart = "<font color='" + gregOtherColor + "'><b>" + gMonthNames[lastGMonth] + " " + string(lastGYear) + "</b></font>"
        ok
        
        gregTitle = firstPart + " <font color='" + separatorColor + "'>/</font> " + lastPart
    ok

    if isobject(lblMonthYearTitle)
        lblMonthYearTitle.setText("<html><center>" + hijriTitle + "<br>" + gregTitle + "</center></html>")
    ok

    numRows = 7
    tableWidth = 7 * cellWidth
    tableHeight = headerHeight + (6 * cellHeight)

    gridCalendar.clearContents()
    gridCalendar.setRowCount(numRows)
    gridCalendar.setColumnCount(7)
    gridCalendar.resize(tableWidth, tableHeight)
    gridCalendar.horizontalHeader().hide()
    gridCalendar.verticalHeader().hide()

    for col = 0 to 6
        gridCalendar.setColumnWidth(col, cellWidth)
    next

    gridCalendar.setRowHeight(0, headerHeight)
    for row = 1 to 6
        gridCalendar.setRowHeight(row, cellHeight)
    next

    if isobject(frameLabel)
        frameLabel.hide()
        frameLabel = NULL
    ok

    for i = 1 to len(aGridLines)
        if isobject(aGridLines[i])
            aGridLines[i].hide()
            aGridLines[i] = NULL
        ok
    next
    aGridLines = []

    nFixedX = gridCalendar.x()
    nFixedY = gridCalendar.y()
    nFrameX = nFixedX + HijriCaledar.x()
    nFrameY = nFixedY + HijriCaledar.y()

    frameLabel = new qLabel(win) {
        move(nFrameX, nFrameY)
        resize(tableWidth, tableHeight)
        setStyleSheet("background: transparent; border: " + nBorderWidth + "px solid " + borderColor + ";")
        setAttribute(76, True)
        show()
    }
    add(aGridLines, frameLabel)

    dayNames = ["Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"]
    for col = 0 to 6
        dayName = dayNames[col + 1]
        lblHeader = new qLabel(win) {
            setAlignment(Qt_AlignHCenter | Qt_AlignVCenter)
            styleStr = "background-color:" + headerBgColor + "; color:" + headerTextColor + "; font-family:" + headerFontFamily + "; font-size:" + string(headerFontSize) + "px; font-weight:" + headerFontWeight + "; border: none;"
            setStyleSheet(styleStr)
            setText(dayName)
        }
        gridCalendar.setCellWidget(0, col, lblHeader)
    next

    for day = 1 to daysInMonth
        pos = startCol + day - 1
        row = floor(pos / 7) + 1
        col = pos % 7

        if row <= 6

            dayOffset = offset + day - 1
            gD = 18 gM = 5 gY = 1931 rem = dayOffset
            while rem > 0
                if gM = 2
                    mDays = 28 + ((gY % 4 = 0 and gY % 100 != 0) or (gY % 400 = 0))
                but gM=4 or gM=6 or gM=9 or gM=11
                    mDays = 30
                else
                    mDays = 31
                ok

                can = mDays - gD
                if rem > can
                    rem -= (can + 1)
                    gD = 1
                    gM++
                    if gM > 12
                        gM = 1
                        gY++
                    ok
                else
                    gD += rem
                    rem = 0
                ok
            end

            gDay = gD
            gMonth = gM
            gYear = gY

            isToday = (currCalYear = realTodayYear) and (currCalMonth = realTodayMonth) and (day = realTodayDay)
            isSelected = (selectedYear != 0) and (currCalYear = selectedYear) and (currCalMonth = selectedMonth) and (day = selectedDay)

            if gYear = mainGYear and gMonth = mainGMonth
                gregTextColor = cellGregTextColor
            else
                gregTextColor = cellGregText2Color
            ok

            hijriPart = "<span style='color:" + cellHijriTextColor + "; font-size:" + string(cellFontSize) + "px; font-weight:" + cellFontWeight + "; font-family:" + cellFontFamily + ";'>" + string(day) + "</span>"
            gregPart = "<span style='color:" + gregTextColor + "; font-size:" + string(cellGregFontSize) + "px; font-weight:" + cellFontWeight + "; font-family:" + cellFontFamily + ";'>" + string(gDay) + "</span>"

            spacingStr = ""
            for i = 1 to separatorSpacing
                spacingStr = spacingStr + "&nbsp;"
            next

            separatorPart = "<span style='color:" + separatorColor + "; font-size:" + string(separatorFontSize) + "px; font-weight:" + cellFontWeight + "; font-family:" + cellFontFamily + ";'>" + spacingStr + "/" + spacingStr + "</span>"

            cellContent = hijriPart + separatorPart + gregPart

            lbl = new qLabel(win) {
                setAlignment(Qt_AlignRight | Qt_AlignVCenter)
                setWordWrap(true)
                setText("<html><div style='text-align:center;'>" + cellContent + "</div></html>")
            }

            styleStr = ""
            if isToday
                styleStr += "background-color:" + todayColor + "; font-weight: bold;"
            else
                styleStr += "background-color:" + cellBgColor + ";"
            ok
            styleStr += " border: none;"

            lbl.setStyleSheet(styleStr)
            gridCalendar.setCellWidget(row, col, lbl)
        ok
    next

    for col = 0 to (startCol - 1)
        emptyLbl = new qLabel(win) {
            setAlignment(Qt_AlignRight | Qt_AlignVCenter)
            setText("")
            setStyleSheet("background-color:" + emptyCellBgColor + "; border: none;")
        }
        gridCalendar.setCellWidget(1, col, emptyLbl)
    next

    lastPos = startCol + daysInMonth - 1
    lastRow = floor(lastPos / 7) + 1
    lastCol = lastPos % 7

    for col = (lastCol + 1) to 6
        if lastRow < numRows
            emptyLbl = new qLabel(win) {
                setAlignment(Qt_AlignRight | Qt_AlignVCenter)
                setText("")
                setStyleSheet("background-color:" + emptyCellBgColor + "; border: none;")
            }
            gridCalendar.setCellWidget(lastRow, col, emptyLbl)
        ok
    next

    for row = (lastRow + 1) to (numRows - 1)
        for col = 0 to 6
            emptyLbl = new qLabel(win) {
                setAlignment(Qt_AlignRight | Qt_AlignVCenter)
                setText("")
                setStyleSheet("background-color:" + emptyCellBgColor + "; border: none;")
            }
            gridCalendar.setCellWidget(row, col, emptyLbl)
        next
    next

    for col = 1 to 6
        nLineX = nFrameX + (col * cellWidth)
        nLineY = nFrameY
        nLineHeight = tableHeight

        vLine = new qLabel(win) {
            setGeometry(nLineX, nLineY, nBorderWidth, nLineHeight)
            setStyleSheet("background-color: " + borderColor + "; border: none;")
            setAttribute(76, True)
            show()
        }
        add(aGridLines, vLine)
    next

    nFirstHLineY = nFrameY + headerHeight
    hLine1 = new qLabel(win) {
        setGeometry(nFrameX, nFirstHLineY, tableWidth, nBorderWidth)
        setStyleSheet("background-color: " + borderColor + "; border: none;")
        setAttribute(76, True)
        show()
    }
    add(aGridLines, hLine1)

    for row = 1 to 5
        nLineY = nFrameY + headerHeight + (row * cellHeight)
        hLine = new qLabel(win) {
            setGeometry(nFrameX, nLineY, tableWidth, nBorderWidth)
            setStyleSheet("background-color: " + borderColor + "; border: none;")
            setAttribute(76, True)
            show()
        }
        add(aGridLines, hLine)
    next

   SearchMonthComboBox.setText(hMonthNames[currCalMonth])      
   SearchYearComboBox.setText(string(currCalYear))

        Hijri_Images.show()
        imageName = string(currCalMonth) + ".png"
        Hijri_Images.setPixmap(new QPixmap(imageName))
        Hijri_2_Gregorian.hide()
        Gregorian_2_Hijri.hide()
        Gregorian_Age_Calculator.hide()
        Gregorian_Period_Calculator.hide()
        Hijri_Age_Calculator.hide()
        Hijri_Period_Calculator.hide()
        Gregorian_Add.hide()
        Hijri_Add.hide()
        ReamainingDays.hide()
    
end

#"═════════════════════════════════════════════════════════════════════════════════════"
#"              Search Month ComboBox Hijri Calendar Function                          "
#"═════════════════════════════════════════════════════════════════════════════════════"

func UpdateMonth

    cMonthName = SearchMonthComboBox.text()
    currCalMonth = 1
    
    for i = 1 to len(hMonthNames)
        if hMonthNames[i] = cMonthName
            currCalMonth = i
            exit
        ok
    next

    drawHijriCalendar()
     SearchMonthComboBox.setText(hMonthNames[currCalMonth])      
     SearchYearComboBox.setText(string(currCalYear))
end

#"═════════════════════════════════════════════════════════════════════════════════════"
#"              Search Year ComboBox Hijri Calendar Function                           "
#"═════════════════════════════════════════════════════════════════════════════════════"

func UpdateYear
    currCalYear = number(trim(SearchYearComboBox.text()))
    drawHijriCalendar()    
    SearchMonthComboBox.setText(hMonthNames[currCalMonth])      
    SearchYearComboBox.setText(string(currCalYear))
    
end

#"═════════════════════════════════════════════════════════════════════════════════════"
#"              Navigation Buttons Hijri Calendar Function                             "
#"═════════════════════════════════════════════════════════════════════════════════════"

func navigateCalendar direction
    newMonth = currCalMonth + direction
    newYear = currCalYear
    
    if newMonth > 12
        newMonth = 1
        newYear = newYear + 1
    elseif newMonth < 1
        newMonth = 12
        newYear = newYear - 1
    ok
    
    if newYear < 1350 or newYear > 1500
        return false
    ok
    
    currCalMonth = newMonth
    currCalYear = newYear
    
    drawHijriCalendar()
    SearchMonthComboBox.setText(hMonthNames[currCalMonth])      
    SearchYearComboBox.setText(string(currCalYear))
    
    return true
end

#"═════════════════════════════════════════════════════════════════════════════════════"
#"        Back to Current Hijri today Button Hijri Calendar Function                   "
#"═════════════════════════════════════════════════════════════════════════════════════"

func backToday
    
   cY = number(TimeList()[19]) 
   cM = number(TimeList()[10]) 
   cD = number(TimeList()[6])

   nDiffToday = GetJD(cY, cM, cD) - 2426479.5
   hToday     = DiffToHijri(nDiffToday, hijriYears)

   currCalMonth   = hToday[2]
   currCalYear    = hToday[3]

   realTodayDay   = hToday[1]
   realTodayMonth = hToday[2]
   realTodayYear  = hToday[3]
   selectedYear = 0; selectedMonth = 0; selectedDay = 0
    
    drawHijriCalendar()
    SearchMonthComboBox.setText(hMonthNames[currCalMonth])      
    SearchYearComboBox.setText(string(currCalYear))
    
    return true
end

#"═════════════════════════════════════════════════════════════════════════════════════"
#"                         Clock Function                                              "
#"═════════════════════════════════════════════════════════════════════════════════════"

func updateClock12
   tList = timeList()
   h24 = 0 + tList[7]
   m = 0 + tList[11]
   s = 0 + tList[13]

   if h24 >= 12 ampm = "PM" else ampm = "AM" ok
   if h24 = 0 h12 = 12 elseif h24 > 12 h12 = h24 - 12 else h12 = h24 ok

   cTime = right("0" + string(h12), 2) + ":" +
   right("0" + string(m), 2) + ":" +
   right("0" + string(s), 2)

   lblTime.setText(cTime)
   lblStatus.setText(ampm)
end

#"═════════════════════════════════════════════════════════════════════════════════════"
#"        Gregorian to Hijri Date Converter Button Function                            "
#"═════════════════════════════════════════════════════════════════════════════════════"

func showCovnertG2H
   Hijri_Images.hide()
   Hijri_2_Gregorian.hide()
   Gregorian_Age_Calculator.hide()
   Hijri_Age_Calculator.hide()
   Gregorian_Period_Calculator.hide()
   Hijri_Period_Calculator.hide()
   Hijri_Add.hide()
   ReamainingDays.hide()
   Gregorian_2_Hijri.show()
   Gregorian2HijriResult.settext(string(GregToHijri(number(trim(Gregorian_2_Hijri_Day_ComboBox.text())), number(trim(Gregorian_2_Hijri_Month_ComboBox.text())),  number(trim(Gregorian_2_Hijri_Year_ComboBox.text())), hijriYears)))

end

#"═════════════════════════════════════════════════════════════════════════════════════"
#"          Hijri to Gregorian Date Converter Button Function                          "
#"═════════════════════════════════════════════════════════════════════════════════════"

func showCovnertH2G
   Hijri_Images.hide()
   Gregorian_2_Hijri.hide()
   Gregorian_Age_Calculator.hide()
   Hijri_Age_Calculator.hide()
   Gregorian_Period_Calculator.hide()
   Hijri_Period_Calculator.hide()
   Hijri_Add.hide()
   ReamainingDays.hide()
   Hijri_2_Gregorian.show()
   Hijri_2_GregorianResult.settext(string(HijriToGreg(number(trim(Hijri_2_Gregorian_Day_ComboBox.text())), number(trim(Hijri_2_Gregorian_Month_ComboBox.text())), number(trim(Hijri_2_Gregorian_Year_ComboBox.text())), hijriYears)))

end

#"═════════════════════════════════════════════════════════════════════════════════════"
#"          Gregorian Age Calculator Button Function                                   "
#"═════════════════════════════════════════════════════════════════════════════════════"

func showGregorianAge
   Hijri_Images.hide()
   Hijri_2_Gregorian.hide()
   Gregorian_2_Hijri.hide()
   Hijri_Age_Calculator.hide()
   Gregorian_Period_Calculator.hide()
   Hijri_Period_Calculator.hide()
   Hijri_Add.hide()
   ReamainingDays.hide()
   Gregorian_Age_Calculator.show()
   Gregorian_AgeResult.settext(string(MyAgeGreg(number(trim(Gregorian_Age_Day_ComboBox.text())), number(trim(Gregorian_Age_Month_ComboBox.text())), number(trim(Gregorian_Age_Year_ComboBox.text())), hijriYears)))
end

#"═════════════════════════════════════════════════════════════════════════════════════"
#"          Hijri Age Calculator Button Function                                       "
#"═════════════════════════════════════════════════════════════════════════════════════"

func showHijriAge
   Hijri_Images.hide()
   Hijri_2_Gregorian.hide()
   Gregorian_2_Hijri.hide()
   Gregorian_Age_Calculator.hide()
   Gregorian_Period_Calculator.hide()
   Hijri_Period_Calculator.hide()
   Hijri_Add.hide()
   ReamainingDays.hide()
   Hijri_Age_Calculator.show()
   Hijri_AgeResult.settext(string(MyAgeHijri(number(trim(Hijri_Age_Day_ComboBox.text())), number(trim(Hijri_Age_Month_ComboBox.text())),  number(trim(Hijri_Age_Year_ComboBox.text())), hijriYears)))

end

#"═════════════════════════════════════════════════════════════════════════════════════"
#"          Gregorian Period Calculator Button Function                                "
#"═════════════════════════════════════════════════════════════════════════════════════"

func showGregorianPeriod
   Hijri_Images.hide()
   Hijri_2_Gregorian.hide()
   Gregorian_2_Hijri.hide()
   Hijri_Age_Calculator.hide()
   Gregorian_Age_Calculator.hide()
   Hijri_Period_Calculator.hide()
   Hijri_Add.hide()
   ReamainingDays.hide()
   Gregorian_Period_Calculator.show()
   Gregorian_PeriodResult.settext(string(DiffGreg(number(trim(Gregorian_Period1_Day_ComboBox.text())), number(trim(Gregorian_Period1_Month_ComboBox.text())), number(trim(Gregorian_Period1_Year_ComboBox.text())), number(trim(Gregorian_Period2_Day_ComboBox.text())), number(trim(Gregorian_Period2_Month_ComboBox.text())), number(trim(Gregorian_Period2_Year_ComboBox.text())), hijriYears)))
end

#"═════════════════════════════════════════════════════════════════════════════════════"
#"              Hijri Period Calculator Button Function                                "
#"═════════════════════════════════════════════════════════════════════════════════════"

func showHijriPeriod
   Hijri_Images.hide()
   Hijri_2_Gregorian.hide()
   Gregorian_2_Hijri.hide()
   Gregorian_Age_Calculator.hide()
   Gregorian_Period_Calculator.hide()
   Hijri_Age_Calculator.hide()
   Hijri_Add.hide()
   ReamainingDays.hide()
   Gregorian_Add.hide()
   Hijri_Period_Calculator.show()
   Hijri_PeriodResult.settext(string(DiffHijri(number(trim(Hijri_Period1_Day_ComboBox.text())), number(trim(Hijri_Period1_Month_ComboBox.text())), number(trim(Hijri_Period1_Year_ComboBox.text())), number(trim(Hijri_Period2_Day_ComboBox.text())), number(trim(Hijri_Period2_Month_ComboBox.text())), number(trim(Hijri_Period2_Year_ComboBox.text())), hijriYears)))
end

#"═════════════════════════════════════════════════════════════════════════════════════"
#"              Add Period To Gregorian Button Function                                "
#"═════════════════════════════════════════════════════════════════════════════════════"

func showGregorianAdd
   Hijri_Images.hide()
   Hijri_2_Gregorian.hide()
   Gregorian_2_Hijri.hide()
   Gregorian_Age_Calculator.hide()
   Gregorian_Period_Calculator.hide()
   Hijri_Age_Calculator.hide()
   Hijri_Period_Calculator.hide()
   Hijri_Add.hide()
   ReamainingDays.hide()
   Gregorian_Add.show()
   Gregorian_AddResult.settext(string(AddToGreg(number(trim(Gregorian_Date_Day_ComboBox.text())), number(trim(Gregorian_Date_Month_ComboBox.text())), number(trim(Gregorian_Date_Year_ComboBox.text())), number(trim(Gregorian_Add_Day_ComboBox.text())), number(trim(Gregorian_Add_Month_ComboBox.text())), number(trim(Gregorian_Add_Year_ComboBox.text())), hijriYears)))

end

#"═════════════════════════════════════════════════════════════════════════════════════"
#"              Add Period To Hijri Button Function                                    "
#"═════════════════════════════════════════════════════════════════════════════════════"

func showHijriAdd
   Hijri_Images.hide()
   Hijri_2_Gregorian.hide()
   Gregorian_2_Hijri.hide()
   Gregorian_Age_Calculator.hide()
   Gregorian_Period_Calculator.hide()
   Hijri_Age_Calculator.hide()
   Hijri_Period_Calculator.hide()
   Gregorian_Add.hide()
   ReamainingDays.hide()
   Hijri_Add.show()
   Hijri_AddResult.settext(string(AddToHijri(number(trim(Hijri_Date_Day_ComboBox.text())), number(trim(Hijri_Date_Month_ComboBox.text())), number(trim(Hijri_Date_Year_ComboBox.text())), number(trim(Hijri_Add_Day_ComboBox.text())), number(trim(Hijri_Add_Month_ComboBox.text())), number(trim(Hijri_Add_Year_ComboBox.text())), hijriYears)))
end

#"═════════════════════════════════════════════════════════════════════════════════════"
#"                 show Reamaining Button Function                                     "
#"═════════════════════════════════════════════════════════════════════════════════════"

func showReamaining
   Hijri_Images.hide()
   Hijri_2_Gregorian.hide()
   Gregorian_2_Hijri.hide()
   Gregorian_Age_Calculator.hide()
   Gregorian_Period_Calculator.hide()
   Hijri_Age_Calculator.hide()
   Hijri_Period_Calculator.hide()
   Gregorian_Add.hide()
   Hijri_Add.hide()
   ReamainingDays.show()
  CalculateRemaining(hijriYears)

end

#"═════════════════════════════════════════════════════════════════════════════════════"
#"             Gregorian to Hijri Date Converter Function                              "
#"═════════════════════════════════════════════════════════════════════════════════════"

func GregToHijri d, m, y, aList
   
    if y < 1931 or y > 2077
        return "خطأ: السنة " + string(y) + " خارج النطاق (1931-2077)"
    ok
  
    if m < 1 or m > 12
        return "خطأ: الشهر (" + string(m) + ") غير موجود"
    ok
   
    maxG = 31
    if m = 2
        if (y % 4 = 0 and y % 100 != 0) or (y % 400 = 0) 
            maxG = 29 
        else 
            maxG = 28 
        ok
    elseif m = 4 or m = 6 or m = 9 or m = 11
        maxG = 30
    ok
    
    if d < 1 or d > maxG
        return "خطأ: يوم " + string(d) + " غير موجود لأن شهر (" + string(m) + ") في سنة " + string(y) + " هو " + string(maxG) + " يوماً فقط"
    ok

    if y = 1931 and (m < 5 or (m = 5 and d < 18))
        return "خطأ: التاريخ قبل بداية النطاق المدعوم ( 1931/5/18 )"
    ok

    jd = GetJD(y, m, d)
    nDiff = jd - 2426479.5
    hL = DiffToHijri(nDiff, aList)
    
    if hL[3] = 9999 or hL[3] > 1500
        return "خطأ: التاريخ الناتج يتجاوز النطاق المدعوم"+nl+"30 / 12 / 1500  هـ"
    ok

    return GetDayName(nDiff) + "  " + string(hL[1]) + " / " + string(hL[2]) + " / " + string(hL[3]) + " هـ"
end

#"═════════════════════════════════════════════════════════════════════════════════════"
#"             Hijri to Gregorian Date Converter Function                              "
#"═════════════════════════════════════════════════════════════════════════════════════"

func HijriToGreg d, m, y, aList
   
    if y < 1350 or y > 1500
        return "خطأ: السنة " + string(y) + " هـ خارج النطاق (1350-1500)"
    ok
    if m < 1 or m > 12
        return "خطأ: الشهر الهجري (" + string(m) + ") غير موجود"
    ok
    
    mask = aList[y - 1349]
    maxH = 29
    if (mask >> (12 - m)) & 1 maxH = 30 ok
    
    if d < 1 or d > maxH
        return "خطأ: يوم " + string(d) + " غير موجود لأن شهر (" + string(m) + ") في سنة " + string(y) + " هـ هو " + string(maxH) + " يوماً"
    ok

    nDays = HijriToDays(d, m, y, aList)
    nJD = 2426479.5 + nDays
    aG = JDToGreg(nJD)
    return GetDayName(nDays) + "  " + string(aG[1]) + " / " + string(aG[2]) + " / " + string(aG[3]) + " م"
end

#"═════════════════════════════════════════════════════════════════════════════════════"
#"             Gregorian Age Calculator Function                                       "
#"═════════════════════════════════════════════════════════════════════════════════════"

func MyAgeGreg d, m, y, aList
 
    cY = number(TimeList()[19]) 
    cM = number(TimeList()[10]) 
    cD = number(TimeList()[6])

    if y > cY or (y = cY and m > cM) or (y = cY and m = cM and d > cD)
        return "خطأ: التاريخ المدخل في المستقبل! "+nl+"( تاريخ اليوم : " + string(cD)+" / "+string(cM)+" / "+string(cY) + " )"
    ok

    if y < 1931 or y > 2077 return "خطأ: السنة خارج النطاق" ok
    maxG = 31
    if m = 2
        if (y % 4 = 0 and y % 100 != 0) or (y % 400 = 0) maxG = 29 else maxG = 28 ok
    elseif m = 4 or m = 6 or m = 9 or m = 11 maxG = 30 ok
    if d < 1 or d > maxG 
        return "خطأ: يوم " + string(d) + " غير موجود لأن شهر (" + string(m) + ") في سنة " + string(y) + " هو " + string(maxG) + " يوماً فقط"
    ok

    return CalculatePeriod(d, m, y, cD, cM, cY, "G", aList)
end


#"═════════════════════════════════════════════════════════════════════════════════════"
#"             Hijri Age Calculator Function                                           "
#"═════════════════════════════════════════════════════════════════════════════════════"

func MyAgeHijri d, m, y, aList
    
    cY = number(TimeList()[19]) cM = number(TimeList()[10]) cD = number(TimeList()[6])
    nDiffToday = GetJD(cY, cM, cD) - 2426479.5
    hToday = DiffToHijri(nDiffToday, aList)

    if y > hToday[3] or (y = hToday[3] and m > hToday[2]) or (y = hToday[3] and m = hToday[2] and d > hToday[1])
        return "خطأ: التاريخ المدخل في المستقبل!"+nl+"( تاريخ اليوم : " + string(hToday[1])+" / "+string(hToday[2])+" / "+string(hToday[3]) + " )"   
    ok

    if y < 1350 or y > 1500 return "خطأ: السنة خارج النطاق" ok
    mask = aList[y - 1349]
    maxH = 29 if (mask >> (12 - m)) & 1 maxH = 30 ok
    if d < 1 or d > maxH return "خطأ: يوم " + string(d) + " غير موجود لأن شهر (" + string(m) + ") في سنة " + string(y) + " هو " + string(maxH) + " يوماً فقط" ok
                         
    return CalculatePeriod(d, m, y, hToday[1], hToday[2], hToday[3], "H", aList)

end


#"═════════════════════════════════════════════════════════════════════════════════════"
#"             Gregorian Period Calculator Function                                    "
#"═════════════════════════════════════════════════════════════════════════════════════"

func DiffGreg d1, m1, y1, d2, m2, y2, aList
    
    err1 = ""
    if y1 < 1931 or y1 > 2077 
        err1 = "خطأ التاريخ (1): السنة خارج النطاق (1931-2077)"
    elseif m1 < 1 or m1 > 12
        err1 = "خطأ التاريخ (1): الشهر (" + string(m1) + ") غير موجود"
    else
        maxG1 = 31
        if m1=2 
            if (y1%4=0 and y1%100!=0) or (y1%400=0) maxG1=29 else maxG1=28 ok
        elseif m1=4 or m1=6 or m1=9 or m1=11 maxG1=30 ok
        if d1 < 1 or d1 > maxG1
            err1 = "خطأ التاريخ (1) لأن شهر " + string(m1) + " في سنة " + string(y1) + " به " + string(maxG1) + " يوم"
        ok
    ok

    err2 = ""
    if y2 < 1931 or y2 > 2077 
        err2 = "خطأ التاريخ (2): السنة خارج النطاق (1931-2077)"
    elseif m2 < 1 or m2 > 12
        err2 = "خطأ التاريخ (2): الشهر (" + string(m2) + ") غير موجود"
    else
        maxG2 = 31
        if m2=2 
            if (y2%4=0 and y2%100!=0) or (y2%400=0) maxG2=29 else maxG2=28 ok
        elseif m2=4 or m2=6 or m2=9 or m2=11 maxG2=30 ok
        if d2 < 1 or d2 > maxG2
            err2 = "خطأ التاريخ (2) لأن شهر " + string(m2) + " في سنة " + string(y2) + " به " + string(maxG2) + " يوم"
        ok
    ok

    if err1 != "" and err2 != "" return err1 + nl + err2 ok
    if err1 != "" return err1 ok
    if err2 != "" return err2 ok

    return CalculatePeriod(d1, m1, y1, d2, m2, y2, "G", aList)
end


#"═════════════════════════════════════════════════════════════════════════════════════"
#"                 Hijri Period Calculator Function                                    "
#"═════════════════════════════════════════════════════════════════════════════════════"

func DiffHijri d1, m1, y1, d2, m2, y2, aList
   
    err1 = ""
    if y1 < 1350 or y1 > 1500 
        err1 = "خطأ التاريخ (1): السنة خارج النطاق (1350-1500)"
    elseif m1 < 1 or m1 > 12 
        err1 = "خطأ التاريخ (1): الشهر (" + string(m1) + ") غير موجود"
    else
        mask1 = aList[y1 - 1349]
        maxH1 = 29 if (mask1 >> (12 - m1)) & 1 maxH1 = 30 ok
        if d1 < 1 or d1 > maxH1
            err1 = "خطأ التاريخ (1) لأن شهر " + string(m1) + " في سنة " + string(y1) + " هـ به " + string(maxH1) + " يوم"
        ok
    ok

    err2 = ""
    if y2 < 1350 or y2 > 1500 
        err2 = "خطأ التاريخ (2): السنة خارج النطاق (1350-1500)"
    elseif m2 < 1 or m2 > 12 
        err2 = "خطأ التاريخ (2): الشهر (" + string(m2) + ") غير موجود"
    else
        mask2 = aList[y2 - 1349]
        maxH2 = 29 if (mask2 >> (12 - m2)) & 1 maxH2 = 30 ok
        if d2 < 1 or d2 > maxH2
            err2 = "خطأ التاريخ (2) لأن شهر " + string(m2) + " في سنة " + string(y2) + " هـ به " + string(maxH2) + " يوم"
        ok
    ok

    if err1 != "" and err2 != "" return err1 + nl + err2 ok
    if err1 != "" return err1 ok
    if err2 != "" return err2 ok

    return CalculatePeriod(d1, m1, y1, d2, m2, y2, "H", aList)
end


#"═════════════════════════════════════════════════════════════════════════════════════"
#"                 Add Period To Gregorian Function                                    "
#"═════════════════════════════════════════════════════════════════════════════════════"

func AddToGreg d, m, y, nAddD, nAddM, nAddY, aList
   
    if y < 1931 or y > 2077 return "خطأ: التاريخ الأساسي خارج النطاق" ok
    maxG = 31
    if m=2 if (y%4=0 and y%100!=0) or (y%400=0) maxG=29 else maxG=28 ok
    elseif m=4 or m=6 or m=9 or m=11 maxG=30 ok
    if d < 1 or d > maxG return "خطأ: يوم " + string(d) + " غير موجود لأن شهر (" + string(m) + ") في سنة " + string(y) + " هو " + string(maxG) + " يوماً فقط" ok

    y += nAddY
    m += nAddM
    while m > 12 m -= 12 y++ end
    if y > 2077 or y < 1931 return "خطأ: التاريخ الناتج خارج النطاق "+nl+" 1931 - 2077" ok

    nJD = GetJD(y, m, d) + nAddD
    aF = JDToGreg(nJD)
    
    if aF[3] > 2077 or aF[3] < 1931 return "خطأ: التاريخ الناتج خارج النطاق" ok

    return GetDayName(nJD - 2426479.5) + "  " + string(aF[1]) + " / " + string(aF[2]) + " / " + string(aF[3]) + " م"
end


#"═════════════════════════════════════════════════════════════════════════════════════"
#"                 Add Period To Hijri Function                                        "
#"═════════════════════════════════════════════════════════════════════════════════════"

func AddToHijri d, m, y, nAddD, nAddM, nAddY, aList
  
    if y < 1350 or y > 1500 return "خطأ: التاريخ الهجري الأساسي خارج النطاق" ok
    maskBase = aList[y - 1349]
    maxH = 29 if (maskBase >> (12 - m)) & 1 maxH = 30 ok
    if d < 1 or d > maxH return "خطأ: يوم " + string(d) + " غير موجود لأن شهر (" + string(m) + ") في سنة " + string(y) + " هـ هو " + string(maxH) + " يوماً" ok
    y += nAddY
    m += nAddM
    while m > 12 m -= 12 y++ end
    
    if y > 1500 or y < 1350 return "خطأ: التاريخ الناتج خارج النطاق "+nl+" 1350 - 1500" ok

    nTotal = HijriToDays(d, m, y, aList) + nAddD
    hL = DiffToHijri(nTotal, aList)

    if hL[3] = 9999 or hL[3] > 1500 or hL[3] < 1350
        return "خطأ: التاريخ الناتج خارج النطاق "+nl+" 1350 - 1500"
    ok

    return GetDayName(nTotal) + "  " + string(hL[1]) + " / " + string(hL[2]) + " / " + string(hL[3]) + " هـ"
end


#"═════════════════════════════════════════════════════════════════════════════════════"
#"                    show Reamaining Function                                         "
#"═════════════════════════════════════════════════════════════════════════════════════"

func CalculateRemaining aList
    cY = number(TimeList()[19]) cM = number(TimeList()[10]) cD = number(TimeList()[6])
    nTodayJD = GetJD(cY, cM, cD)
    nDiffToday = nTodayJD - 2426479.5 
    hToday = DiffToHijri(nDiffToday, aList)
    hD = hToday[1] hM = hToday[2] hY = hToday[3]

    targetGY = cY + 1
    daysG = GetJD(targetGY, 1, 1) - nTodayJD
    Reamainin_Gregorian_Year_Result.settext("المتبقي على عام  " + string(targetGY) + " هو  " + string(floor(daysG)) + " يوم  " +nl+"وهو يساوي   " + CalculatePeriod(cD, cM, cY, 1, 1, targetGY, "G", aList) + " " +nl+ copy("ـــ", 20)) # طباعة النتيجة

    targetHY = hY + 1 
    if targetHY <= 1500
        daysH = HijriToDays(1, 1, targetHY, aList) - nDiffToday

	Reamainin_Hijri_Year_Result.settext("المتبقي على عام  " + string(targetHY) + " هو  " + string(floor(daysH)) + " يوم  " +nl+"وهو يساوي   " + CalculatePeriod(hD, hM, hY, 1, 1, targetHY, "H", aList) + " " +nl+ copy("ـــ", 20))
	ok

    ramadanYear = hY if hM > 9 or (hM = 9 and hD >= 1) ramadanYear++ ok
    daysR = HijriToDays(1, 9, ramadanYear, aList) - nDiffToday

	Reamainin_Ramadan_Result.settext("المتبقي على رمضان  " + string(ramadanYear) + " هو  " + string(floor(daysR)) + " يوم  " +nl+"وهو يساوي   " + CalculatePeriod(hD, hM, hY, 1, 9, ramadanYear, "H", aList) + " " +nl+ copy("ـــ", 20))
    
    fitrYear = hY if hM > 10 or (hM = 10 and hD >= 1) fitrYear++ ok 
    daysF = HijriToDays(1, 10, fitrYear, aList) - nDiffToday
	Reamainin_Eid_ELfeter_Result.settext("المتبقي على عيد الفطر " + string(fitrYear) + " هو  " + string(floor(daysF)) + " يوم  " +nl+"وهو يساوي   " + CalculatePeriod(hD, hM, hY, 1, 10, fitrYear, "H", aList) + " " +nl+ copy("ـــ", 20))
     
    adhaYear = hY if hM > 12 or (hM = 12 and hD >= 10) adhaYear++ ok
    daysA = HijriToDays(10, 12, adhaYear, aList) - nDiffToday
	Reamainin_Eid_ELadha_Result.settext("المتبقي على عيد الأضحى " + string(adhaYear) + " هو " + string(floor(daysA)) + " يوم  " +nl+"وهو يساوي   " + CalculatePeriod(hD, hM, hY, 10, 12, adhaYear, "H", aList) + " " +nl+ copy("ـــ", 20))
end
  
#"═════════════════════════════════════════════════════════════════════════════════════"
#"                    Calculator Function                                              "
#"═════════════════════════════════════════════════════════════════════════════════════"

func CalculatePeriod d1, m1, y1, d2, m2, y2, mode, aList
    
    if y1 > y2 or (y1 = y2 and m1 > m2) or (y1 = y2 and m1 = m2 and d1 > d2)
    
        tempY = y1 y1 = y2 y2 = tempY
     
        tempM = m1 m1 = m2 m2 = tempM
       
        tempD = d1 d1 = d2 d2 = tempD
    ok

    aY = y2 - y1 
    aM = m2 - m1 
    aD = d2 - d1

    if aD < 0
        pM = m2 - 1 
        pY = y2 
        if pM = 0 pM = 12 pY-- ok
        
        if mode = "G"
            aGM = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
            if (pY%4=0 and pY%100!=0) or (pY%400=0) aGM[2]=29 ok
            aD += aGM[pM]
        else
            mask = aList[pY - 1349]
            nMD = 29 if (mask >> (12 - pM)) & 1 nMD = 30 ok
            aD += nMD
        ok
        aM--
    ok

    if aM < 0
        aM += 12
        aY--
    ok

    res = ""
    if aY > 0 
        res += string(aY) + " سنة"
    ok
    
    if aM > 0 
        if res != "" res += " و " ok
        res += string(aM) + " شهر"
    ok
    
    if aD > 0 
        if res != "" res += " و " ok
        res += string(aD) + " يوم"
    ok
    
    if res = "" res = "نفس التاريخ" ok
    
    return res
end

#"═════════════════════════════════════════════════════════════════════════════════════"
#"                    Julian Day Function                                              "
#"═════════════════════════════════════════════════════════════════════════════════════"

func GetJD y, m, d 
    if m <= 2 y -= 1 m += 12 ok
    A = floor(y/100) B = 2 - A + floor(A/4)
    return floor(365.25*(y + 4716)) + floor(30.6001*(m + 1)) + d + B - 1524.5
end

#"═════════════════════════════════════════════════════════════════════════════════════"
#"                   Convert Julian Day to Date Function                               "
#"═════════════════════════════════════════════════════════════════════════════════════"

func JDToGreg jd
    z = floor(jd + 0.5) f = (jd + 0.5) - z
    if z < 2299161 A = z else alpha = floor((z - 1867216.25) / 36524.25) A = z + 1 + alpha - floor(alpha / 4) ok
    B = A + 1524 C = floor((B - 122.1) / 365.25) D = floor(365.25 * C) E = floor((B - D) / 30.6001)
    day = B - D - floor(30.6001 * E) + f 
    if E < 14 month = E - 1 else month = E - 13 ok
    if month > 2 year = C - 4716 else year = C - 4715 ok 
    return [floor(day), month, year] 
end

#"═════════════════════════════════════════════════════════════════════════════════════"
#"                Convert Hijri Date to Days Function                                  "
#"═════════════════════════════════════════════════════════════════════════════════════"

func HijriToDays d, m, y, aList 
    nTotal = 0 
    for iY = 1350 to y - 1 
        mask = aList[iY - 1349] 
        for iM = 1 to 12 if (mask >> (12 - iM)) & 1 nTotal += 30 else nTotal += 29 ok next 
    next
    mask = aList[y - 1349]
    for iM = 1 to m - 1 if (mask >> (12 - iM)) & 1 nTotal += 30 else nTotal += 29 ok next
    return nTotal + (d - 1)
end

#"═════════════════════════════════════════════════════════════════════════════════════"
#"                Convert Days to Hijri Date Function                                  "
#"═════════════════════════════════════════════════════════════════════════════════════"

func DiffToHijri nDiff, aList 
    nHYear = 1350 nHMonth = 1 nHDay = 1 + nDiff 
    nMaxIndex = len(aList)

    while true 
        nIdx = nHYear - 1349
        
        if nIdx > nMaxIndex
            return [0, 0, 9999] 
        ok

        mask = aList[nIdx] 
        nMD = 29 if (mask >> (12 - nHMonth)) & 1 nMD = 30 ok 
        
        if nHDay <= nMD exit ok 
        
        nHDay -= nMD nHMonth++ 
        if nHMonth > 12 nHMonth = 1 nHYear++ ok 
    end
    return [floor(nHDay), nHMonth, nHYear]
end

#"═════════════════════════════════════════════════════════════════════════════════════"
#"                Week Days Names Function                                             "
#"═════════════════════════════════════════════════════════════════════════════════════"

func GetDayName nOffset
    aNames = ["الإثنين", "الثلاثاء", "الأربعاء", "الخميس", "الجمعة", "السبت", "الأحد"] # مصفوفة أسماء الأيام
    idx = (1 + (floor(nOffset) % 7))
    while idx > 7 idx -= 7 end while idx < 1 idx += 7 end
    return aNames[idx]
end
