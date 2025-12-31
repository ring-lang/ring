# Author: Bert Mariani 
# Date..: 2025-12-31

# Day Length Calculator at Latitude 45°N
# Calculates the length of daylight for any day of the year
# Uses Spherical Trigonometry

    #--- Solar declination formula (Cooper's equation)
    #--- δ = 23.45° × sin(360/365 × (284 + N))
    #---    
    #--- Length of Day
    #--- cosH      = -tan(latRad) * tan(declRad)
    #--- Hours     = acos(cosH)  
    #--- dayLength = (2.0 * Hours * 180.0 / 3.14159265359) / 15.0

# ===========================================

load "stdlibcore.ring"
load "guilib.ring"


# --- Chart Draw ---------
qpainter_antialiasing = 1
qt_solidpattern = 1
qt_dotline = 1


aSumTotal = ["","",""]
Datalen   = 12

# ---------------------------

latitude = 45.0   // Montreal Milano Venice 

cLatitude =  67
cCity     = "City"    

CityLatitude = [["City",45],
                ["Montreal",45],
                ["Berlin",52],
                ["Cairo",30],
                ["Copenhagen",55],
                ["Frankfurt",50],
                ["Helenski",60],
                ["Houston",30],
                ["Instanbul",41],
                ["Johannesburg",-23],
                ["LasVegas",36],
                ["Lisbon",38],
                ["London",51],
                ["Madrid",40],
                ["Mecca",21],
                ["Mexico",19],
                ["Milano",45],
                ["Moscow",56],
                ["Mumbai",19],
                ["Munich",48],
                ["Naples",41],
                ["NewYork",41],
                ["Oslo",60],
				["Panama",9],
                ["Paris",49],
                ["Reykjavik",64],
                ["Rio",-22],
                ["Riyadh",25],
                ["Rome",42],
                ["SanPailo",-23],
                ["Stockholm",59],
                ["Sydney",-34],
                ["Tokyo",36],
                ["Tunis",37],
                ["Venice",45],
                ["Vienna",48],
                ["Zurich",47]
               ]


comboLatitude   = null
comboCity       = null
txtCityLatitude = null 
txtLatitude     = null
 
deg2Rad = (3.14159265359 / 180.0)
rad2Deg = (180.0 / 3.14159265359)


# ====================================================
# ====================================================
###-------------------------------
### Define Colours, Pens, Brushes

colorRed     = new qcolor() { setrgb(255,000,000,255) }
colorGreen   = new qcolor() { setrgb(000,255,000,255) }  
colorBlue    = new qcolor() { setrgb(000,000,255,255) }
colorYellow  = new qcolor() { setrgb(255,255,000,255) }  
colorWhite   = new qcolor() { setrgb(255,255,255,255) }  
colorBlack   = new qcolor() { setrgb(000,000,000,255) }
colorGray    = new qcolor() { setrgb(128,128,128,255) }  
colorMagenta = new qcolor() { setrgb(000,255,255,016) }  
colorAqua    = new qcolor() { setrgb(000,255,255,255) }  
colorGrid    = new QColor() { setRGB(192,192,192,255) }
colorBack    = new QColor() { setRGB(192,192,192,255) }
colorBlue1   = new qcolor() { setrgb(000,000,128,255) }

penGreen    = new qpen() { setcolor(colorGreen)   setwidth(2) }
penRed      = new qpen() { setcolor(colorRed)     setwidth(2) }
penBlue     = new qpen() { setcolor(colorBlue)    setwidth(2) }  
penYellow   = new qpen() { setcolor(colorYellow)  setwidth(2) } 
penWhite    = new qpen() { setcolor(colorWhite)   setwidth(2) }
penBlack    = new qpen() { setcolor(colorBlack)   setwidth(1) }
penGray     = new qpen() { setcolor(colorGray)    setwidth(1) }
penMagenta  = new qpen() { setcolor(colorMagenta) setwidth(1) }
penAqua     = new qpen() { setcolor(colorAqua)    setwidth(1) }
penGrid     = new qpen() { setcolor(colorGrid)    setwidth(1) }
penBack     = new qpen() { setcolor(colorBack)    setwidth(1) }
penBlue1    = new qpen() { setcolor(colorBlue)   setwidth(1) }

brushRed     = new qbrush() { setstyle(1)  setcolor (colorRed)}      
brushGreen   = new qbrush() { setstyle(1)  setcolor (colorGreen)}    
brushBlue    = new qbrush() { setstyle(1)  setcolor (colorBlue)}     
brushYellow  = new qbrush() { setstyle(1)  setcolor (colorYellow)} 
brushWhite   = new qbrush() { setstyle(1)  setcolor (colorWhite)}
brushBlack   = new qbrush() { setstyle(1)  setcolor (colorBlack)}  
brushGray    = new qbrush() { setstyle(1)  setcolor (colorGray)}     
brushMagenta = new qbrush() { setstyle(1)  setcolor (colorMagenta)}  
brushAqua    = new qbrush() { setstyle(1)  setcolor (colorAqua)} 
brushBack    = new qbrush() { setstyle(1)  setcolor (colorWhite)}  // Background
brushBlue1   = new qbrush() { setstyle(1)  setcolor (colorBlue1)}


brushEmpty   = new qbrush() { setstyle(0)  setcolor (colorYellow)} 

// There are 19 predefined QColor objects: 
// white, black, red, darkRed, green, darkGreen, blue, darkBlue, cyan, darkCyan, 
// magenta, darkMagenta, yellow, darkYellow, gray, darkGray, lightGray, color0 

# ====================================================
# ====================================================

# --------------------------

# Global Data Containers
aGlobalCurves = [[], []]

# Global Objects
win           = null
oChartWidget  = null
txtLog        = null

btnRun        = null
btnExport     = null
btnBrowse     = null
txtTickerFile = null
App           = null


# -------------------------------
# Constants for Styling

C_STYLE_DARK = "
QWidget {
        background-color: #2b2b2b;
        color: #000000 ;             // #ffffff;
        font-family: 'Segoe UI', sans-serif;
        font-size: 14px;
    }
    QPushButton {
        background-color: #007acc;
        border: none;
        padding: 8px 16px;
        border-radius: 4px;
        color: white;
        font-weight: bold;
    }
    QPushButton:hover {
        background-color: #005999;
    }
    QPushButton:pressed {
        background-color: #004080;
    }
    QLineEdit, QComboBox {
        background-color: #3c3c3c;
        border: 1px solid #555;
        padding: 4px;
        border-radius: 3px;
        color: white;
    }
    QFrame {
        border: 1px solid #555;
        border-radius: 5px;
        margin-top: 10px;
        padding: 5px;
        background-color: #333;
    }
    QLabel {
        font-weight: bold;
        color: #cccccc;
    }
"

# =====================================
# =====================================
# oFont = new qFont( "Vivaldi", 12.0, 0)
# setFont(oFont


Func main
    App = new QApp
        
    win = new QWidget() {
        setWinIcon(self,"appicon.png")
        setWindowTitle("Length of Day at Latidude and Date")
        resize(1400, 800)
        setStyleSheet(C_STYLE_DARK)
        

        # --- Layouts ---
        mainLayout     = new QVBoxLayout()
        controlsLayout = new QHBoxLayout()
        contentLayout  = new QHBoxLayout()

        # --- Controls Section ---
        groupControls = new QFrame( win,0) {
            setFrameShape(QFrame_StyledPanel)
            
            # Main layout for the frame (Vertical to hold Title + Controls)
            frameLayout = new QVBoxLayout() {
                
                # Title
                lblTitle = new QLabel( win) {
                    setText("Configuration")
                    setStyleSheet("color: #007acc; font-weight: bold;")
                }
                addWidget(lblTitle)

                # Controls Layout (Horizontal)
                controlsLayoutInner = new QHBoxLayout() {
                                      
                    
                     # Label latitude  : Add Global -- txtLatitude = null 
                     addWidget(new QLabel(win){setText("Latitude:")})   
                     txtLatitude = new QLineEdit(win){setText("45")}    
                     addWidget(txtLatitude)    

                    # Run Latitude -- Calc Length of Day Button
                    btnCalcLatitude = new QPushButton(win){setText("Calc-Latitude")}
                    btnCalcLatitude.setStyleSheet("background-color: yellow;")
                    btnCalcLatitude.setClickEvent("CalcLatitude()")
                    addWidget(btnCalcLatitude)                   
                    
                    
                    # ----------------------
                
                    # City Name
                    addWidget(new QLabel(win){setText("City:")})
                    comboCity = new QComboBox(win){
                            // alist = ["City","Montreal","Milano","Venice"]
                            for x in CityLatitude additem(x[1],0) next
                        }
                    addWidget(comboCity)   
                    
                    
                     # Label City-Latitude  
                     addWidget(new QLabel(win){setText("City & Latitude:")})   
                     txtCityLatitude = new QLineEdit(win){setText("45")}    
                     addWidget(txtCityLatitude) 
                    
 
                    # -----------------------

                    # Run Calc Length of Day Button
                    btnQuotes = new QPushButton(win){setText("Calc-DayLength")}
                    btnQuotes.setStyleSheet("background-color: yellow;")
                    btnQuotes.setClickEvent("CalcDayLength()")
                    addWidget(btnQuotes)
                    
                    # PrintYear Button
                    btnPrintYear = new QPushButton(win){setText("Print-Year")}
                    btnPrintYear.setStyleSheet("background-color: lightGray;")
                    btnPrintYear.setClickEvent("PrintYear()")
                    addWidget(btnPrintYear)                 
                    

                    # DrawYear Button
                    btnDrawYear = new QPushButton(win){setText("Draw-Year")}
                    btnDrawYear.setStyleSheet("background-color: cyan;")
                    btnDrawYear.setClickEvent("DrawYear()")
                    addWidget(btnDrawYear)
                    
                    //-------------------
                    //------------------                


                }
                addLayout(controlsLayoutInner)
            }
            setLayout(frameLayout)
        }

        # --- CONTENT SECTION ---
        
        # LEFT: DATA/LOG
        groupData = new QFrame(win,0) {
            setFrameShape(QFrame_StyledPanel)
            frameLayout = new QVBoxLayout() {
                lblTitle = new QLabel(win) {
                    setText("Calculation Log")
                    setStyleSheet("color: #007acc; font-weight: bold;")
                    
                }
                addWidget(lblTitle)

                txtLog = new QTextEdit(win){setReadOnly(true)setText("Ready to start...")}
                addWidget(txtLog)
            }
            setLayout(frameLayout)
        }

        # RIGHT: CHART AREA
        groupChart = new QFrame(win, 0) {
            setFrameShape(QFrame_StyledPanel)
            frameLayout = new QVBoxLayout() {
                lblTitle = new QLabel(win) {
                    setText("Chart Day Length at Latitude")
                    setStyleSheet("color: #007acc; font-weight: bold;")
                    setMaximumHeight(40)
                }
                addWidget(lblTitle)

                oChartWidget = new StockChart( win)
                addWidget(oChartWidget)
            }
            setLayout(frameLayout)
        }

        # Add widgets to layouts
        controlsLayout.addWidget(groupControls)
        
        contentLayout.addWidget(groupData)
        contentLayout.addWidget(groupChart)
        contentLayout.setStretch(0, 1)         # Log   takes 1 part    1/3 of Window
        contentLayout.setStretch(1, 2)         # Chart takes 2 parts   2/3 of Window

        mainLayout.addLayout(controlsLayout)
        mainLayout.addLayout(contentLayout)

        setLayout(mainLayout)
        show()
    }

    App.exec()
 
    exec()
    
    
# =================================================================
# =================================================================
# Use Latitude:  Force comboCity to "City"
    
Func CalcLatitude()

    cLatitude = txtLatitude.text()
    comboCity.setCurrentText("City") 
	
    CalcDayLength()  ### ===>>>
	DrawYear()       ### ===>>>

Return

# =================================================================
# =================================================================
# setFont(new qFont("Courier",20,100,0))
# START HERE: Main program

Func CalcDayLength()

    cLatitude = txtLatitude.text()
    cCity     = comboCity.currentText()
 
    if cCity != "City" 
       index     = Find(CityLatitude, cCity,1 )      
       cLatitude = CityLatitude[index][2]
       
       See "cCity: "+ CityLatitude[index][1] +" Latitude: "+ CityLatitude[index][2] +nl
          
       txtLog.append(' ')
       txtLog.append('============================================ ' )
       txtLog.append("cCity: "+ CityLatitude[index][1] +" Latitude: "+ CityLatitude[index][2])
       txtLog.append(" ")
    
    ok
    
    txtCityLatitude.setText(""+cLatitude +"  "+ cCity )
        txtLatitude.setText(""+cLatitude )
    latitude = cLatitude 


    see "============================================" + nl
    see "Day Length Calculator at: "+ latitude +" deg Latitude" +" City: "+ cCity + nl
    see "============================================" + nl + nl
    
    txtLog.append('============================================ ' )
    txtLog.append('Day Length Calculator at: '+ latitude +' deg Latitude ' )
    txtLog.append('============================================ ' )


    #--- Special days of the year
    winterSolstice = 355  # December 21  (approximately day 355)
    springEquinox  =  80  # March 21     (approximately day  80)
    summerSolstice = 172  # June 21      (approximately day 172)
    autumnEquinox  = 266  # September 23 (approximately day 266)

    # -----------------------------------------------
    #--- Calculate for special astronomical events


    # -----------------------------------------------
    # --- TODAY


    dayNum = Julian()
    dayLen = calculateDayLength(latitude, dayNum)
        hm = hoursToHM(dayLen)
    
    see "Today: "+ Date() +"  dayNum: "+ dayNum +nl
    see "  Day length: " + hm[1] + " hours " + hm[2] + " minutes" 
    see "  Decimal: " + substr(string(dayLen), 1, 5) + " hours" + nl + nl
    see "--------------------------------------------" + nl +nl
    
    txtLog.append(' ')
    txtLog.append('Today: '+ Date() +'  dayNum: '+ dayNum  )
    txtLog.append('  Day length: ' + hm[1] + ' hours ' + hm[2] + ' minutes')
    txtLog.append('  Decimal: ' + substr(string(dayLen), 1, 5) + ' hours')
    txtLog.append('-------------------------------------------- ')

    # -----------------------------------------------   

    see "Special Astronomical Events:" + nl +nl

    # -----------------------------------------------
    # --- Winter Solstice

    dayLen = calculateDayLength(latitude, winterSolstice)
        hm = hoursToHM(dayLen)
    
    see "Winter Solstice (Dec 21, Day " + winterSolstice + ")" + nl
    see "  Day length: " + hm[1] + " hours " + hm[2] + " minutes" 
    see "  Decimal: " + substr(string(dayLen), 1, 5) + " hours" + nl + nl
    
    
    txtLog.append("Winter Solstice (Dec 21, Day " + winterSolstice + ")" )
    txtLog.append("  Day length: " + hm[1] + " hours " + hm[2] + " minutes" )
    txtLog.append("  Decimal: " + substr(string(dayLen), 1, 5) + " hours" )
    txtLog.append('-------------------------------------------- ')

    # -----------------------------------------------
    # --- Spring Equinox

    dayLen = calculateDayLength(latitude, springEquinox)
        hm = hoursToHM(dayLen)
    
    see "Spring Equinox (Mar 21, Day " + springEquinox + ")" + nl
    see "  Day length: " + hm[1] + " hours " + hm[2] + " minutes" 
    see "  Decimal: " + substr(string(dayLen), 1, 5) + " hours" + nl + nl
    
    txtLog.append("Spring Equinox (Mar 21, Day " + springEquinox + ")" )
    txtLog.append("  Day length: " + hm[1] + " hours " + hm[2] + " minutes" )
    txtLog.append("  Decimal: " + substr(string(dayLen), 1, 5) + " hours" )
    txtLog.append('-------------------------------------------- ')

    # -----------------------------------------------
    # --- Summer Solstice

    dayLen = calculateDayLength(latitude, summerSolstice)
        hm = hoursToHM(dayLen)
    
    see "Summer Solstice (Jun 21, Day " + summerSolstice + ")" + nl
    see "  Day length: " + hm[1] + " hours " + hm[2] + " minutes" 
    see "  Decimal: " + substr(string(dayLen), 1, 5) + " hours" + nl + nl
    
    txtLog.append("Summer Solstice (Jun 21, Day " + summerSolstice + ")" )
    txtLog.append("  Day length: " + hm[1] + " hours " + hm[2] + " minutes" )
    txtLog.append("  Decimal: " + substr(string(dayLen), 1, 5) + " hours" )
    txtLog.append('-------------------------------------------- ')
    

    # -----------------------------------------------
    # --- Autumn Equinox

    dayLen = calculateDayLength(latitude, autumnEquinox)
        hm = hoursToHM(dayLen)
    
    See "Autumn Equinox (Sep 23, Day " + autumnEquinox + ")" + nl
    See "  Day length: " + hm[1] + " hours " + hm[2] + " minutes" 
    See "  Decimal: " + substr(string(dayLen), 1, 5) + " hours" + nl + nl
    
    txtLog.append("Autumn Equinox (Sep 23, Day " + autumnEquinox + ")" )
    txtLog.append("  Day length: " + hm[1] + " hours " + hm[2] + " minutes" )
    txtLog.append("  Decimal: " + substr(string(dayLen), 1, 5) + " hours" )
    txtLog.append('-------------------------------------------- ')
    
    

    # -----------------------------------------------
    # --- Sample calculations throughout the year

    see "============================================" + nl
    see "Sample Day Lengths Throughout the Year:" + nl
    see "--------------------------------------------" + nl
    
    txtLog.append("============================================" )
    txtLog.append("Sample Day Lengths Throughout the Year:" )
    txtLog.append("--------------------------------------------" )
    txtLog.append(" ")
    

    sampleDays = [1, 32, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335]
    monthNames = ["Jan 1", "Feb 1", "Mar 1", "Apr 1", "May 1", "Jun 1", 
                  "Jul 1", "Aug 1", "Sep 1", "Oct 1", "Nov 1", "Dec 1"]
    
    for i = 1 to len(sampleDays)
        dayNum = sampleDays[i]
        dayLen = calculateDayLength(latitude, dayNum)
            hm = hoursToHM(dayLen)
            
    
                if dayNum < 10   dayNum = "00"+ dayNum
            elseif dayNum < 100  dayNum =  "0"+ dayNum ok
            
                if hm[1]  < 10   hm[1]  = "0"+ hm[1] ok
                if hm[2]  < 10   hm[2]  = "0"+ hm[2] ok     
            
    
        
            see monthNames[i] + " (Day " + dayNum + "):  " + 
            hm[1] + "h " + hm[2] + "m  (" + 
            substr(string(dayLen), 1, 5) + " hours)" + nl
            
            
        txtLog.append( monthNames[i] + " (Day " + dayNum + "):  " + hm[1] + "h " + hm[2] + "m  (" + substr(string(dayLen), 1, 5) + " hours)" )
            
            
    next

    see nl + "============================================" + nl
	
	DrawYear()  ### ===>>>


#=====================================================
#=====================================================
# Function to calculate solar declination angle

Func solarDeclination(dayNum)

    #--- Solar declination formula (Cooper's equation)
    #--- δ = 23.45° × sin(360/365 × (284 + N))
    
    angle       = (360.0 / 365.0) * (284 + dayNum)
    angleRad    = angle * (deg2Rad)
    declination = 23.45 * sin(angleRad)
    
    return declination

#=====================================================
# Function to calculate day length in hours

Func calculateDayLength(latitude, dayNum)

    #--- Get solar declination for this day
    
    decl = solarDeclination(dayNum)
    
    #--- Convert to radians
    
    latRad  = latitude * (deg2Rad)
    declRad = decl * (deg2Rad)
    
    #--- Calculate hour angle at sunrise/sunset
    #--- cos(H) = -tan(φ) × tan(δ)
    
    cosH = -tan(latRad) * tan(declRad)
    
    #--- Check for polar day/night (shouldn't happen at 45°N)
    
    if cosH > 1
        return 0   # Polar night
    but cosH < -1
        return 24  # Polar day
    ok
    
    #--- Hour angle in radians
    
    H = acos(cosH)
    
    #--- Day length in hours = 2 × H / 15°
    #--- (H is in radians, convert to degrees then to hours)
    
    dayLength = (2.0 * H * rad2Deg) / 15.0
    
    return dayLength
    
#=====================================================
# Function to convert decimal hours to hours and minutes

Func hoursToHM(decimalHours)

    hours   = floor(decimalHours)
    minutes = floor((decimalHours - hours) * 60)
    
    return [hours, minutes]
    
# ===================================================
# Function Today's Date() to  Julian Number

Func Julian()

    mon    = [31,28,31,30,31,30,31,31,30,31,30,31]
    julian = 0
    
    aDay  = split( Date(), "/" )
    day   = aDay[1]     month = aDay[2]     year  = aDay[3]
    

    for i = 1 to month-1
        julian += mon[i]
    next
        julian += day

 
    return julian
    

#=====================================================
#=====================================================
# Day: 352  Dec 18, 2025  dayLen: 8.58 Len: 8 hr 34 mi

Func PrintYear()

    aOldMonth = ["Ele", "32", "1901" ]

    aDate = split( Date(), "/" )
    year  = aDate[3]


for dayNum = 1 to 365

    cDate = DayNumberToDate(dayNum, year)  // ===>>> 364 = Dec 30, 2025
    
    aMonth = split( cDate, " ") 
    if aMonth[1] != aOldMonth[1]     // Space Line  
        See " "+ nl
        txtLog.append(" ")  
    ok
    
    # ---------------------------------------------
    
    dayLen = calculateDayLength(latitude, dayNum)
        hm = hoursToHM(dayLen)
        
    #-----------------------------------------------
    
    see "Day: "+ dayNum  +"  "+ cDate  +"  dayLen: "+ dayLen  +" Len: " + hm[1] + " hr " + hm[2] + " mi" +nl    
    txtLog.append("Day: "+ dayNum  +"  "+ cDate +"  dayLen: "+ dayLen   +"  Len: " + hm[1] + " hr " + hm[2] + " mi")
    
    
    
    aOldMonth = aMonth
    
next        

return

#=====================================================
#=====================================================
# dayLen: 8.58

Func DrawYear()

    aDaylen = []

    for dayNum = 1 to 365    
        dayLen = calculateDayLength(latitude, dayNum)
        Add( aDayLen, dayLen)       
    next
        
    
    //--- Rotate aDayLen by 80 days. Start March 21 Aries -----

    aAries = list(365)
    k = 80
    
    j = 1
    for k = 80 to 365              // >>>  80 - 365
        aAries[j] = aDayLen[k]     // <<<   1 - 285      
        j++     
    next

    
    j = 286
    for k = 1 to 80                // >>>     1 to  80
        aAries[j] = aDayLen[k]     // <<<   285 to 365  
        j++
    next
    
    
See nl+"======================="+nl 

    
    oChartWidget.setData(aAries)   // Use Azzeddine Chart

return

#=====================================================
#=====================================================
# 364 = Dec 30, 2025

Func DayNumberToDate(dayNum, year)

    #--- Days in each month (non-leap year)
    daysInMonth = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
    monthNames = ["Jan", "Feb", "Mar", "Apr", "May", "Jun",
                  "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"]
    
    #--- Check if leap year
    isLeap = (year % 4 = 0 and year % 100 != 0) or (year % 400 = 0)
    if isLeap
        daysInMonth[2] = 29
    ok
    
    #--- Validate day number
    maxDays = 365
    if isLeap maxDays = 366 ok
    
    if dayNum < 1 or dayNum > maxDays
        return "Error: Day number must be between 1 and " + maxDays
    ok
    
    #--- Find the month and day
    month = 1
    remainingDays = dayNum
    
    for i = 1 to 12
        if remainingDays <= daysInMonth[i]
            month = i
            day = remainingDays
            exit
        ok
        remainingDays = remainingDays - daysInMonth[i]
    next
    
    #--- Format the date
    dateStr = monthNames[month] + " " + day + ", " + year
    
return dateStr
end




#=====================================================
#=====================================================

// ======================================================================

CLASS StockChart from QLabel
    
    aPortfolioData = []
    aQQQData       = []
    
    Func Init(parent)
        super.init(parent)
        return this

    Func SetData(aDayLen)
        
        aSumTotal[1]  = aDayLen   // Use existing code 
        aSumTotal[2]  = aDayLen 
        aSumTotal[3]  = aDayLen 
    
            
        aNbr           = aSumTotal[1]
        aQQQData       = aSumTotal[2]
        aPortfolioData = aSumTotal[3]
        
        Draw()        // ===>>> DRAW
        
    # ================================= 
    Func Draw
        #--- Capture dimensions and data locally to avoid scope issues inside QPainter block
        w = this.width()
        h = this.height()

        aQ    = aQQQData
        aPort = aPortfolioData
        
        if w < 10 or h < 10 return ok
        
        p1 = new qpicture()
        
        p = new qpainter() {
            begin(p1)
            setRenderHint(QPainter_Antialiasing, true)
            
            #--- Background
            fillRect(0, 0, w, h, brushBack)
            
            if len(aPort) < 2
                setPen(penBlack) 
                drawText(10, 20, "No Data to Display")
                endpaint()
            else
                //--- Padding on Left and Right before Chart Grid
                pad = 40      
                
                #--- Find Min/Max
                minVal =  1000
                maxVal = -1000
                
                    for v in aPort          
                        if v < minVal minVal = v ok
                        if v > maxVal maxVal = v ok
                    next
                    curAPort = aSumTotal[3][len(aSumTotal[3])]
                
        
                    for v in aQ 
                        if v < minVal minVal = v ok
                        if v > maxVal maxVal = v ok
                    next
                    curAQQQ = aSumTotal[2][len(aSumTotal[2])] 
                    
                    
                    #--- FIX so Shortest Day Not Zero ----
                    minVal = 0
                    # ------------------------------------
                    
                    curARatio = (curAPort -1) / (curAQQQ -1)
                
                              
                range = maxVal - minVal
                if range = 0 range = 1 ok
                
                #-- Draw Grid (Detailed)
                setPen(penGrid)
                
                #--- Horizontal lines =  Price -----
                nSteps = 10                               // 12 
                
                value = maxVal / nSteps
                for i = 0 to nSteps
                    y = pad + (i * (h - 2*pad) / nSteps)
                    drawLine(pad, y, w - pad, y)
                    
                    //--- Put Percent Multiplier on Left ---
                    setPen(penBlack)
                    nbr = maxVal -( value * i)      
                    drawText(pad-30, y, ""+nbr) 
                    setPen(penGrid)
                    
                next
                
                #--- Vertical lines = Time -----
                nSteps = 12                            // <<<=== 12 for 2yr
                Offset =  DataLen % nSteps             // Mod = 4
                Months = (DataLen - Offset) / nSteps   // 64 -4 /  12 = 5
                
                // See "Vert: Datalen: "+ Datalen +" nSteps: "+ nSteps +" Offset: "+ Offset +" Months: "+  Months +nl
                
                for i = 0 to nSteps                           
                    x = pad + (i * (w - 2*pad) / nSteps)
                    drawLine(x, pad, x, h - pad)
                    
                    //--- Put MONTH NUMBERS on Bottom ---
                    setPen(penBlack)
                //  drawText(x, y+10, ""+ ((nSteps - i )* Months))    // Reverse 0 6 12 18 ... 60 54 48
                    drawText(x, y+10, ""+ (( i )* Months))    // Reverse 0 6 12 18 ... 60 54 48
                    setPen(penGrid)
                    
                next

                #--- Draw Axes -----
                setPen(penBlue1) 
                drawLine(pad, pad,     pad,     h - pad)
                drawLine(pad, h - pad, w - pad, h - pad)
                
                # #--- Zero Line -----
                # y1 = h - pad - (1.0 - minVal) * (h - 2*pad) / range
                # if y1 >= pad and y1 <= h - pad
                #     setPen(penBlue1)  
                #     drawLine(pad, y1, w - pad, y1)
                #     
                #     drawText(pad+10, y1-2, "1.00") 
                #     drawText( w/2 , y+30, "Months")
                # ok
                
                #--- Draw QQQ (Red) -----
                setPen(penRed)  
                nCount = len(aQ)
                for i = 1 to nCount - 1
                    x1 = pad + (i - 1) * (w - 2*pad) / (nCount - 1)
                    y1 = h - pad - (aQ[i] - minVal) * (h - 2*pad) / range
                    
                    x2 = pad + (i) * (w - 2*pad) / (nCount - 1)
                    y2 = h - pad - (aQ[i+1] - minVal) * (h - 2*pad) / range
                    
                    drawLine(x1, y1, x2, y2)
                next
                
                #--- Draw Portfolio (Blue) -----
                setPen(penBlue) 
                nCount = len(aPort)
                for i = 1 to nCount - 1
                    x1 = pad + (i - 1) * (w - 2*pad) / (nCount - 1)
                    y1 = h - pad - (aPort[i] - minVal) * (h - 2*pad) / range
                    
                    x2 = pad + (i) * (w - 2*pad) / (nCount - 1)
                    y2 = h - pad - (aPort[i+1] - minVal) * (h - 2*pad) / range
                    
                    drawLine(x1, y1, x2, y2)
                next
                
                #--- Legend -----
                setPen(penBlack)  
                drawText(pad +10, 10, "--- Length of Day: Start Mar 21 : Aries ")
                drawText(pad +10, 30, "--- Latitude:  "+ latitude ) 
                drawText(pad +10, 50, "--- City:  "+ cCity )
                
                endpaint()
            ok
        }
        
        setPicture(p1)
        show()
        
# ============================  


