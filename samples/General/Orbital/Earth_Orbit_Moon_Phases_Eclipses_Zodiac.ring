# Earth's Elliptical Orbit with Zodiac Signs, and Moon Orbit with Solar and Lunar Eclipses
# Bert Mariani --- with Claude AI
# 17-March-2026
#
# Ring Language  -  lightguilib / qPainter / qPixmap2
#
# GEOMETRY  (astronomically correct):
#   - Major axis VERTICAL:  Cancer(top/Jun21-Aphelion) <-> Capricorn(bottom/Dec22-Perihelion)
#   - Sun at BOTTOM focus  (near Capricorn / perihelion / ~Jan 3)
#   - Aries 0 deg = RIGHT (3 o'clock), counter-clockwise orbit
#   - x = CX + B*cos(lon)   y = CY - A*sin(lon)
#
# TODAY'S DATE:
#   - Get month/day from Ring date()
#   - Convert to day-of-year, then to ecliptic longitude from Aries 0 deg
#   - Vernal equinox Mar 21 = day 80 = lon 0 deg
#   - lon = (dayOfYear - 80) * 360 / 365.25
#
# Painter = daVinci       Pixmap = MonaLisa

load "stdlibcore.ring"
load "lightguilib.ring"

### ── Constants ──────────────────────────────────────────────────────────────

W  = 1880   # fits 1920px screen with borders
H  = 1020   # fits 1080px screen minus taskbar and title bar
CX = 450
CY = 490

A  = 320          # semi-major (vertical)
B  = 316          # semi-minor — e=0.157, C≈50px, Sun clearly below centre
C  = sqrt(A*A - B*B)

SUN_X    = CX
SUN_Y    = CY + C     # Sun at bottom focus (perihelion side)
FOCUS2_X = CX
FOCUS2_Y = CY - C     # empty focus at top  (aphelion side)

PI = 3.14159265358979
RAD = PI / 180.0

### ── Test date override — set to "" for today's real date ───────────────────
TEST_DATE = ""    ### "DD/MM/YYYY"  e.g. "01/04/2026" or "" for today

### Eclipse calculation constants (from SolarMain-LunarMain-Eclipse-1.ring)
SYNODIC_MONTH            = 29.530588853
MOON_INCLINATION_DEG     = 5.145396
BASE_UMBRA_AT_MEAN_DEG   = 0.7275
SOLAR_ANGULAR_RADIUS_DEG = 0.2666
PENUMBRA_EXTRA_DEG       = 0.2666
EARTH_RADIUS_KM          = 6371.0
MEAN_MOON_DIST_ER        = 60.36
MEAN_MOON_ANG_RADIUS_DEG = 0.259

# Days in each month (non-leap)
aDaysInMonth = [31,28,31,30,31,30,31,31,30,31,30,31]

aZodiac = [
    [ "Aries",          0,  "Ar",  "Mar 21" ],
    [ "Taurus",        30,  "Ta",  "Apr 20" ],
    [ "Gemini",        60,  "Ge",  "May 21" ],
    [ "Cancer",        90,  "Cn",  "Jun 21" ],
    [ "Leo",          120,  "Le",  "Jul 23" ],
    [ "Virgo",        150,  "Vi",  "Aug 23" ],
    [ "Libra",        180,  "Li",  "Sep 23" ],
    [ "Scorpio",      210,  "Sc",  "Oct 23" ],
    [ "Sagittarius",  240,  "Sg",  "Nov 22" ],
    [ "Capricorn",    270,  "Cp",  "Dec 22" ],
    [ "Aquarius",     300,  "Aq",  "Jan 20" ],
    [ "Pisces",       330,  "Pi",  "Feb 19" ]
]

### ── Globals ─────────────────────────────────────────────────────────────────

MonaLisa    = null
daVinci     = null
Canvas      = null
DateInput   = null   ### Date input field widget
DateInputReady = 0   ### Set to 1 once DateInput widget is created
myApp       = null
win         = null

todayLon    = 0       # ecliptic longitude for today (calculated below)
todayStr    = ""      # "Month Day Year" string
todayDeg    = ""      # longitude as string e.g. "356.2 deg"
todayZodiac = ""      # which zodiac sign

moonAngle   = 0       # Moon's orbital angle around Earth (deg, CCW from right)
moonPhase   = 0       # Moon phase 0..1 (0=New, 0.25=First Qtr, 0.5=Full, 0.75=Last Qtr)
moonPhaseNm = ""      # Phase name string

### ── Eclipse data — filled dynamically by CalcEclipses() at startup ─────────
aSolarEcl = []   # [year, month, day, hour, min, type_short]
aLunarEcl = []   # [year, month, day, hour, min, type_short]

### Month name lookup
aMonthName3 = ["Jan","Feb","Mar","Apr","May","Jun",
               "Jul","Aug","Sep","Oct","Nov","Dec"]
anomPhase   = 0       # Anomalistic month phase 0..1 (0=Perigee, 0.5=Apogee)
anomDaysAgo = 0       # Days since last perigee
anomNm      = ""      # "Perigee" / "Apogee" / "Waxing" / "Waning"
dracPhase   = 0       # Draconic month phase 0..1 (0=Asc Node, 0.5=Desc Node)
dracNm      = ""      # node name string
moonIncDeg  = 5.14    # Moon orbital inclination to ecliptic (degrees, fixed)

### ── Colours ────────────────────────────────────────────────────────────────

colorBgDark  = new qColor() { setRgb(  5,   5,  20, 255) }
colorWhite   = new qColor() { setRgb(255, 255, 255, 255) }
colorBlue    = new qColor() { setRgb( 22,  90, 210, 255) }
colorSkyBlue = new qColor() { setRgb( 65, 145, 255, 215) }
colorGold    = new qColor() { setRgb(255, 190,  15, 255) }
colorYellow  = new qColor() { setRgb(255, 215,  55, 255) }
colorViolet  = new qColor() { setRgb(200, 192, 255, 230) }
colorGreen   = new qColor() { setRgb(135, 208, 135, 200) }
colorRingVio = new qColor() { setRgb(155, 135, 210, 140) }
colorInner   = new qColor() { setRgb( 95,  85, 145,  85) }
colorTick    = new qColor() { setRgb(220, 210, 255, 240) }
colorSector  = new qColor() { setRgb( 90,  90, 150,  65) }
colorEarthLb = new qColor() { setRgb(135, 190, 255, 255) }
colorSunLbl  = new qColor() { setRgb(255, 222,  90, 255) }
colorFocus   = new qColor() { setRgb(125, 115, 185, 155) }
colorTitle   = new qColor() { setRgb(220, 210, 255, 255) }
colorSub     = new qColor() { setRgb(195, 195, 235, 240) }
colorSpring  = new qColor() { setRgb(  0, 255, 100, 255) }
colorSummer  = new qColor() { setRgb(255, 215,  45, 255) }
colorAutumn  = new qColor() { setRgb(255, 135,  35, 255) }
colorWinter  = new qColor() { setRgb( 70, 195, 255, 255) }
colorPeri    = new qColor() { setRgb(255, 100, 100, 255) }
colorAph     = new qColor() { setRgb(100, 200, 255, 255) }
colorToday   = new qColor() { setRgb(255, 255,   0, 255) }  # bright yellow
colorAngle   = new qColor() { setRgb(255, 210,  50, 220) }  # amber angle line
colorMoonOrb = new qColor() { setRgb(180, 180, 220, 100) }  # Moon orbit ring
colorMoonLit = new qColor() { setRgb(240, 240, 250, 255) }  # Moon lit side
colorMoonDrk = new qColor() { setRgb( 35,  35,  55, 255) }  # Moon dark side
colorMoonLbl = new qColor() { setRgb(225, 225, 250, 255) }  # Moon label

### ── Insert panel colours ───────────────────────────────────────────────────
colorPanel   = new qColor() { setRgb(  8,  10,  30, 230) }  # panel background
colorPanBdr  = new qColor() { setRgb(110, 100, 170, 200) }  # panel border
colorPanTtl  = new qColor() { setRgb(235, 225, 255, 255) }  # panel title
colorPanSub  = new qColor() { setRgb(195, 195, 235, 240) }  # panel subtitle
colorPerigee = new qColor() { setRgb(255,  90,  90, 255) }  # Perigee (red)
colorApogee  = new qColor() { setRgb( 90, 200, 255, 255) }  # Apogee  (cyan)
colorAscNode = new qColor() { setRgb( 80, 255, 140, 255) }  # Ascending node (green)
colorDscNode = new qColor() { setRgb(255, 165,  50, 255) }  # Descending node (orange)
colorEclip   = new qColor() { setRgb( 60, 130, 255, 180) }  # Ecliptic plane line
colorMoonPth = new qColor() { setRgb(200, 180, 255, 200) }  # Moon path
colorMoonPos = new qColor() { setRgb(235, 235, 248, 255) }  # Moon position dot
colorSolarTot= new qColor() { setRgb(255, 200,  40, 255) }  # Total solar eclipse
colorSolarAnn= new qColor() { setRgb(255, 140,  30, 255) }  # Annular solar eclipse
colorSolarPar= new qColor() { setRgb(255, 230, 140, 240) }  # Partial solar eclipse
colorLunarTot= new qColor() { setRgb(255, 110, 100, 255) }  # Total lunar eclipse
colorLunarPar= new qColor() { setRgb(240, 155, 120, 255) }  # Partial lunar eclipse
colorLunarPen= new qColor() { setRgb(220, 195, 170, 255) }  # Penumbral lunar eclipse
colorToday2  = new qColor() { setRgb( 80, 255, 160, 255) }  # Today marker (green)
colorIncLine = new qColor() { setRgb(255, 210,  50, 220) }  # Inclination angle

### ── Pens ───────────────────────────────────────────────────────────────────

penNone    = new qPen() { setStyle(0) }
penSkyBlue = new qPen() { setColor(colorSkyBlue)  setWidth(2) }
penRingVio = new qPen() { setColor(colorRingVio)  setWidth(1) }
penInner   = new qPen() { setColor(colorInner)    setWidth(1) }
penTick    = new qPen() { setColor(colorTick)     setWidth(2) }
penSector  = new qPen() { setColor(colorSector)   setWidth(1)  setStyle(2) }
penWhite   = new qPen() { setColor(colorWhite)    setWidth(1) }
penFocus   = new qPen() { setColor(colorFocus)    setWidth(1) }
penGold    = new qPen() { setColor(colorYellow)   setWidth(1) }
penViolet  = new qPen() { setColor(colorViolet)   setWidth(1) }
penGreen   = new qPen() { setColor(colorGreen)    setWidth(1) }
penSunLbl  = new qPen() { setColor(colorSunLbl)   setWidth(1) }
penEarthLb = new qPen() { setColor(colorEarthLb)  setWidth(1) }
penTitle   = new qPen() { setColor(colorTitle)    setWidth(1) }
penSub     = new qPen() { setColor(colorSub)      setWidth(1) }
penSpring  = new qPen() { setColor(colorSpring)   setWidth(2) }
penSummer  = new qPen() { setColor(colorSummer)   setWidth(2) }
penAutumn  = new qPen() { setColor(colorAutumn)   setWidth(2) }
penWinter  = new qPen() { setColor(colorWinter)   setWidth(2) }
penPeri    = new qPen() { setColor(colorPeri)     setWidth(2) }
penAph     = new qPen() { setColor(colorAph)      setWidth(2) }
penMajAxis = new qPen() { setColor(colorFocus)    setWidth(1)  setStyle(2) }
penToday   = new qPen() { setColor(colorToday)    setWidth(2) }
penAngle   = new qPen() { setColor(colorAngle)    setWidth(2) }
penMoonOrb = new qPen() { setColor(colorMoonOrb)  setWidth(1)  setStyle(2) }
penMoonLit = new qPen() { setColor(colorMoonLit)  setWidth(1) }
penMoonLbl = new qPen() { setColor(colorMoonLbl)  setWidth(1) }
penPanBdr  = new qPen() { setColor(colorPanBdr)   setWidth(1) }
penPanTtl  = new qPen() { setColor(colorPanTtl)   setWidth(1) }
penPanSub  = new qPen() { setColor(colorPanSub)   setWidth(1) }
penPanLbl  = new qPen() { setColor(colorMoonLbl)  setWidth(1) }
penPanSml  = new qPen() { setColor(colorPanSub)   setWidth(1) }
penPerigee = new qPen() { setColor(colorPerigee)  setWidth(2) }
penApogee  = new qPen() { setColor(colorApogee)   setWidth(2) }
penAscNode = new qPen() { setColor(colorAscNode)  setWidth(2) }
penDscNode = new qPen() { setColor(colorDscNode)  setWidth(2) }
penEclip   = new qPen() { setColor(colorEclip)    setWidth(2) }
penMoonPth = new qPen() { setColor(colorMoonPth)  setWidth(1)  setStyle(2) }
penMoonPos = new qPen() { setColor(colorMoonPos)   setWidth(1) }
penSolarTot= new qPen() { setColor(colorSolarTot)  setWidth(2) }
penSolarAnn= new qPen() { setColor(colorSolarAnn)  setWidth(2) }
penSolarPar= new qPen() { setColor(colorSolarPar)  setWidth(1) }
penLunarTot= new qPen() { setColor(colorLunarTot)  setWidth(2) }
penLunarPar= new qPen() { setColor(colorLunarPar)  setWidth(1) }
penLunarPen= new qPen() { setColor(colorLunarPen)  setWidth(1) }
penToday2  = new qPen() { setColor(colorToday2)    setWidth(2) }
penIncLine = new qPen() { setColor(colorIncLine)  setWidth(2) }

### ── Brushes ────────────────────────────────────────────────────────────────

brushEmpty  = new qBrush() { setStyle(0) }
brushBlue   = new qBrush() { setStyle(1)  setColor(colorBlue)    }
brushGold   = new qBrush() { setStyle(1)  setColor(colorGold)    }
brushSpring = new qBrush() { setStyle(1)  setColor(colorSpring)  }
brushSummer = new qBrush() { setStyle(1)  setColor(colorSummer)  }
brushAutumn = new qBrush() { setStyle(1)  setColor(colorAutumn)  }
brushWinter = new qBrush() { setStyle(1)  setColor(colorWinter)  }
brushPeri   = new qBrush() { setStyle(1)  setColor(colorPeri)    }
brushAph    = new qBrush() { setStyle(1)  setColor(colorAph)     }
brushToday  = new qBrush() { setStyle(1)  setColor(colorToday)   }
brushMoonLit= new qBrush() { setStyle(1)  setColor(colorMoonLit) }
brushMoonDrk= new qBrush() { setStyle(1)  setColor(colorMoonDrk) }
brushPanel  = new qBrush() { setStyle(1)  setColor(colorPanel)   }
brushPerigee= new qBrush() { setStyle(1)  setColor(colorPerigee) }
brushApogee = new qBrush() { setStyle(1)  setColor(colorApogee)  }
brushAscNode= new qBrush() { setStyle(1)  setColor(colorAscNode) }
brushDscNode= new qBrush() { setStyle(1)  setColor(colorDscNode) }
brushMoonPos= new qBrush() { setStyle(1)  setColor(colorMoonPos)  }
brushSolTot = new qBrush() { setStyle(1)  setColor(colorSolarTot) }
brushSolAnn = new qBrush() { setStyle(1)  setColor(colorSolarAnn) }
brushSolPar = new qBrush() { setStyle(1)  setColor(colorSolarPar) }
brushLunTot = new qBrush() { setStyle(1)  setColor(colorLunarTot) }
brushLunPar = new qBrush() { setStyle(1)  setColor(colorLunarPar) }
brushLunPen = new qBrush() { setStyle(1)  setColor(colorLunarPen) }
brushToday2 = new qBrush() { setStyle(1)  setColor(colorToday2)   }

### ── Fonts ──────────────────────────────────────────────────────────────────

fontGlyph  = new qFont("DejaVu Sans", 11, 75, False)
fontName   = new qFont("DejaVu Sans",  8, 50, False)
fontDate   = new qFont("DejaVu Sans",  7, 50, True)
fontLabel  = new qFont("DejaVu Sans",  9, 75, False)
fontSmall  = new qFont("DejaVu Sans",  8, 50, False)
fontAngle  = new qFont("DejaVu Sans", 10, 75, False)
fontTitle  = new qFont("DejaVu Serif",14, 75, False)
fontSub    = new qFont("DejaVu Sans",  8, 50, True)
fontToday  = new qFont("DejaVu Sans",  9, 75, False)
fontMoon   = new qFont("DejaVu Sans",  8, 50, False)
fontPanTtl = new qFont("DejaVu Serif",11, 75, False)
fontPanSub = new qFont("DejaVu Sans",  9, 75, False)
fontPanLbl = new qFont("DejaVu Sans",  9, 50, False)
fontPanSml = new qFont("DejaVu Sans",  8, 50, False)

### ── Calculate today's ecliptic longitude ───────────────────────────────────

CalcTodayLon()
CalcMoon()
CalcInserts()

### ── qApp ───────────────────────────────────────────────────────────────────

myApp = new qApp
{
    win = new qWidget()
    {
        if TEST_DATE != ""
            setWindowTitle("Earth Elliptical Orbit - Zodiac + Moon + Eclipses  [ " + todayStr + " ]  *** TEST DATE ***")
        else
            setWindowTitle("Earth Elliptical Orbit - Zodiac + Moon + Eclipses  [ " + todayStr + " ]")
        ok
        setGeometry(50, 30, W, H)

        Canvas = new qLabel(win)
        {
            MonaLisa = new qPixMap2(W, H)

            daVinci = new qPainter()
            {
                begin(MonaLisa)
            }

            setPixMap(MonaLisa)
            setGeometry(0, 0, W, H)
        }

        ### ── Date input field — below the Today/Moon header lines ─────────
        lblDate = new qLabel(win)
        {
            setText("Date DD/MM/YYYY:")
            setGeometry(8, 78, 120, 14)
            setStyleSheet("color: #9890C0; background: transparent; font-size: 7px;")
        }

        DateInput = new qLineEdit(win)
        {
            if TEST_DATE != ""
                setText(TEST_DATE)
            else
                setText(date())
            ok
            setGeometry(8, 92, 118, 22)
            setStyleSheet("background: #FFFFC0; color: #1A1020; border: 1px solid #A0A040; font-size: 10px; padding: 2px;")
            setReturnPressedEvent("OnDateEntered()")
        }

        btnGo = new qPushButton(win)
        {
            setText("Go")
            setGeometry(130, 92, 34, 22)
            setStyleSheet("background: #00C8C0; color: #001820; border: 1px solid #008880; font-size: 9px; font-weight: bold;")
            setClickEvent("OnDateEntered()")
        }

        btnToday = new qPushButton(win)
        {
            setText("Today")
            setGeometry(168, 92, 48, 22)
            setStyleSheet("background: #00A8A8; color: #001820; border: 1px solid #006868; font-size: 9px; font-weight: bold;")
            setClickEvent("OnTodayClicked()")
        }

        DateInputReady = 1   ### widgets now ready — GetDate() can use DateInput

        show()
    }

    DrawScene()

    exec()
}

### ═══════════════════════════════════════════════════════════════════════════
### GetDate — returns DateInput field value if set, otherwise today's real date
### ═══════════════════════════════════════════════════════════════════════════

Func GetDate()
    if DateInputReady = 1
        txt = DateInput.text()
        txt = trim(txt)
        if len(txt) = 10 and substr(txt,3,1) = "/" and substr(txt,6,1) = "/"
            return txt
        ok
    ok
    if TEST_DATE != ""
        return TEST_DATE
    ok
    return date()

### ═══════════════════════════════════════════════════════════════════════════
### OnDateEntered — called when user presses Enter or clicks Go
### ═══════════════════════════════════════════════════════════════════════════

Func OnDateEntered()
    txt = trim(DateInput.text())
    ### Validate DD/MM/YYYY
    if len(txt) = 10 and substr(txt,3,1) = "/" and substr(txt,6,1) = "/"
        TEST_DATE = txt
        aSolarEcl = []
        aLunarEcl = []
        CalcTodayLon()
        CalcMoon()
        CalcInserts()
        daVinci.begin(MonaLisa)
        DrawScene()
        win.setWindowTitle("Earth Elliptical Orbit - Zodiac + Moon + Eclipses  [ " + todayStr + " ]  *** TEST DATE ***")
    else
        DateInput.setText(date())
    ok

### ═══════════════════════════════════════════════════════════════════════════
### OnTodayClicked — revert to today's real date
### ═══════════════════════════════════════════════════════════════════════════

Func OnTodayClicked()
    TEST_DATE = ""
    aSolarEcl = []
    aLunarEcl = []
    DateInput.setText(date())
    CalcTodayLon()
    CalcMoon()
    CalcInserts()
    daVinci.begin(MonaLisa)
    DrawScene()
    win.setWindowTitle("Earth Elliptical Orbit - Zodiac + Moon + Eclipses  [ " + todayStr + " ]")

### ═══════════════════════════════════════════════════════════════════════════
### CalcTodayLon
### Get today's date from Ring, convert to ecliptic longitude (deg)
### Vernal equinox = Mar 21 = day 80 = lon 0 deg
### lon increases CCW: +1 deg per day  (360/365.25)
### ═══════════════════════════════════════════════════════════════════════════

Func CalcTodayLon()

    ### Ring date() returns  "DD/MM/YYYY"
    d = GetDate()
    aMonthName = ["Jan","Feb","Mar","Apr","May","Jun",
                  "Jul","Aug","Sep","Oct","Nov","Dec"]

    dayPart   = 0 + left(d, 2)
    monthPart = 0 + substr(d, 4, 2)
    yearPart  = 0 + right(d, 4)

    todayStr  = aMonthName[monthPart] + " " + dayPart + "  " + yearPart

    ### Day of year (1 = Jan 1)
    dayOfYear = 0
    for mo = 1 to monthPart - 1
        dayOfYear += aDaysInMonth[mo]
    next
    ### Leap year correction
    if monthPart > 2
        if (yearPart % 4 = 0 AND yearPart % 100 != 0) OR (yearPart % 400 = 0)
            dayOfYear++
        ok
    ok
    dayOfYear += dayPart

    ### Vernal equinox = Mar 21 = day 80
    ### lon = (dayOfYear - 80) * 360 / 365.25
    lon = (dayOfYear - 80) * 360 / 365.25

    ### Normalise to 0..360
    while lon < 0
        lon += 360
    end
    while lon >= 360
        lon -= 360
    end

    todayLon = lon

    ### Round to 1 decimal
    lonRounded = floor(lon * 10 + 0.5) / 10
    todayDeg   = "" + lonRounded + " deg"

    ### Which zodiac sign?
    signIdx = floor(lon / 30) + 1
    if signIdx > 12  signIdx = 1  ok
    todayZodiac = aZodiac[signIdx][1]

return

### ═══════════════════════════════════════════════════════════════════════════
### CalcMoon
### Calculate Moon orbital angle and phase from today's date
### Reference new moon: Jan 6 2000 (JD 2451549.5), synodic period = 29.53059 days
### ═══════════════════════════════════════════════════════════════════════════

Func CalcMoon()

    d = GetDate()
    dayPart   = 0 + left(d, 2)
    monthPart = 0 + substr(d, 4, 2)
    yearPart  = 0 + right(d, 4)

    ### Julian Day Number (simple formula)
    jdn_a = floor((14 - monthPart) / 12)
    jdn_y = yearPart + 4800 - jdn_a
    jdn_m = monthPart + 12 * jdn_a - 3
    jdn = dayPart + floor((153*jdn_m + 2)/5) + 365*jdn_y + floor(jdn_y/4) - floor(jdn_y/100) + floor(jdn_y/400) - 32045

    ### Days since known new moon: Jan 6 2000 = JD 2451550
    daysSinceNew = jdn - 2451550

    ### Synodic period
    syno = 29.53059

    ### Phase 0..1
    phase = (daysSinceNew % syno) / syno
    if phase < 0  phase += 1  ok

    moonPhase = phase

    ### Moon orbital angle (CCW from right = East of Earth)
    ### New moon ~ same direction as Sun from Earth (angle = 0 relative to Sun)
    ### Full moon ~ opposite side
    ### We use: Moon angle from right = Earth ecliptic lon + 180 - phase*360
    ### Simplified: moonAngle = (todayLon + 180) - phase * 360   (mod 360)
    ### But simpler: just use phase*360 offset from anti-Sun direction
    ### Moon at phase=0 (new) is toward Sun, phase=0.5 (full) is away from Sun
    ### Sun direction from Earth = todayLon + 180 (opposite of Earth's heliocentric lon)
    sunDir = todayLon + 180
    if sunDir >= 360  sunDir -= 360  ok
    ### Waxing Moon moves EAST of Sun (CCW on diagram) = angle increases from sunDir
    moonAngle = sunDir + phase * 360
    while moonAngle < 0    moonAngle += 360  end
    while moonAngle >= 360 moonAngle -= 360  end

    ### Phase name
    if phase < 0.03 OR phase >= 0.97
        moonPhaseNm = "New Moon"
    elseif phase < 0.22
        moonPhaseNm = "Waxing Crescent"
    elseif phase < 0.28
        moonPhaseNm = "First Quarter"
    elseif phase < 0.47
        moonPhaseNm = "Waxing Gibbous"
    elseif phase < 0.53
        moonPhaseNm = "Full Moon"
    elseif phase < 0.72
        moonPhaseNm = "Waning Gibbous"
    elseif phase < 0.78
        moonPhaseNm = "Last Quarter"
    else
        moonPhaseNm = "Waning Crescent"
    ok

return

### ═══════════════════════════════════════════════════════════════════════════
### DrawMoon  —  Moon orbit ring + Moon body with phase shading around Earth
### ═══════════════════════════════════════════════════════════════════════════

Func DrawMoon(EX, EY)

    MOON_ORBIT_R = 52    # Moon orbit radius around Earth (screen pixels)
    MOON_R       = 7     # Moon body radius

    ### ── Moon orbit ring (dashed circle around Earth) ───────────────────────
    daVinci.setPen(penMoonOrb)
    daVinci.setBrush(brushEmpty)
    daVinci.drawEllipse(EX - MOON_ORBIT_R, EY - MOON_ORBIT_R,
                        2 * MOON_ORBIT_R,  2 * MOON_ORBIT_R)

    ### ── Moon position on orbit ─────────────────────────────────────────────
    moonAngRad = moonAngle * PI / 180
    MX = EX + MOON_ORBIT_R * cos(moonAngRad)
    MY = EY - MOON_ORBIT_R * sin(moonAngRad)

    ### ── Moon glow ──────────────────────────────────────────────────────────
    daVinci.setPen(penNone)
    cMoonGlow = new qColor() { setRgb(200, 200, 240, 40) }
    bMoonGlow = new qBrush() { setStyle(1)  setColor(cMoonGlow) }
    daVinci.setBrush(bMoonGlow)
    daVinci.drawEllipse(MX - MOON_R - 4, MY - MOON_R - 4,
                        2*(MOON_R+4),     2*(MOON_R+4))

    ### ── Moon body (dark base) ──────────────────────────────────────────────
    daVinci.setPen(penMoonLit)
    daVinci.setBrush(brushMoonDrk)
    daVinci.drawEllipse(MX - MOON_R, MY - MOON_R, 2*MOON_R, 2*MOON_R)

    ### ── Phase shading — lit crescent/gibbous overlay ───────────────────────
    ### The lit fraction depends on phase.
    ### phase 0 = New (fully dark), 0.5 = Full (fully lit)
    ### We draw a lit semicircle, then overlay a dark ellipse scaled by terminator
    ###
    ### Lit side direction: Moon is lit from Sun direction
    ### Sun direction angle from Moon's perspective = moonAngle + 180
    sunFromMoon = moonAngle + 180
    if sunFromMoon >= 360  sunFromMoon -= 360  ok

    ### Phase illumination fraction 0..1 where 0=new, 1=full, then back
    ### illum = (1 - cos(phase * 2 * PI)) / 2
    illum = (1.0 - cos(moonPhase * 2 * PI)) / 2.0

    ### Draw lit portion: fill entire moon white, then mask dark side
    daVinci.setPen(penNone)
    daVinci.setBrush(brushMoonLit)
    daVinci.drawEllipse(MX - MOON_R, MY - MOON_R, 2*MOON_R, 2*MOON_R)

    ### Overlay dark crescent: terminator ellipse scaled by (1 - 2*illum)
    ### termX = cos(sunFromMoon) controls which side is lit
    terminatorScale = fabs(1.0 - 2.0 * illum)
    cDark = new qColor() { setRgb(35, 35, 55, 255) }
    bDark = new qBrush() { setStyle(1)  setColor(cDark) }
    daVinci.setBrush(bDark)

    sunAngRad = sunFromMoon * PI / 180
    ### We draw the dark half-ellipse by drawing a compressed ellipse
    ### on the shadow side. Width = MOON_R * terminatorScale, height = MOON_R
    darkW = floor(MOON_R * terminatorScale)

    ### Determine which side is dark (opposite to Sun)
    if illum <= 0.5
        ### Waxing (New → Full): moon is mostly dark, lit crescent on Sun side
        ### Start fully dark
        daVinci.drawEllipse(MX - MOON_R, MY - MOON_R, 2*MOON_R, 2*MOON_R)
        ### Draw lit half-disc on Sun side
        cLitHalf = new qColor() { setRgb(240, 240, 250, 255) }
        bLitHalf = new qBrush() { setStyle(1)  setColor(cLitHalf) }
        daVinci.setBrush(bLitHalf)
        ### Lit semicircle centred on Sun side (approximate with ellipse offset)
        daVinci.drawEllipse(MX - MOON_R, MY - MOON_R, 2*MOON_R, 2*MOON_R)
        ### Re-overlay dark crescent on anti-sun side using compressed ellipse
        daVinci.setBrush(bDark)
        daVinci.drawEllipse(MX - MOON_R, MY - MOON_R, 2*MOON_R, 2*MOON_R)
        ### Finally draw terminator lit strip (compressed ellipse on sun side)
        cLit2 = new qColor() { setRgb(240, 240, 250, 255) }
        bLit2 = new qBrush() { setStyle(1)  setColor(cLit2) }
        daVinci.setBrush(bLit2)
        daVinci.drawEllipse(MX - darkW, MY - MOON_R, 2*darkW, 2*MOON_R)
    else
        ### Waning: lit more than half — dark is a thin crescent on sun side
        cLitFull = new qColor() { setRgb(240, 240, 250, 255) }
        bLitFull = new qBrush() { setStyle(1)  setColor(cLitFull) }
        daVinci.setBrush(bLitFull)
        daVinci.drawEllipse(MX - MOON_R, MY - MOON_R, 2*MOON_R, 2*MOON_R)
        daVinci.setBrush(bDark)
        daVinci.drawEllipse(MX - darkW, MY - MOON_R, 2*darkW, 2*MOON_R)
    ok

    ### ── Moon orbit line from Earth to Moon ─────────────────────────────────
    cOrbitLine = new qColor() { setRgb(150, 150, 200, 80) }
    pOrbitLine = new qPen()   { setColor(cOrbitLine)  setWidth(1)  setStyle(2) }
    daVinci.setPen(pOrbitLine)
    daVinci.drawLine(EX, EY, MX, MY)

    ### ── Moon label ─────────────────────────────────────────────────────────
    daVinci.setFont(fontMoon)
    daVinci.setPen(penMoonLbl)

    ### Offset label away from Moon body
    cosM = cos(moonAngRad)
    sinM = sin(moonAngRad)
    if cosM >= 0
        mlx = MX + 10
    else
        mlx = MX - 68
    ok
    if sinM >= 0
        mly = MY - 10
    else
        mly = MY + 18
    ok

    daVinci.drawText(mlx, mly,      "Moon")
    daVinci.drawText(mlx, mly + 11, moonPhaseNm)

return

### ═══════════════════════════════════════════════════════════════════════════
### CalcInserts
### Compute anomalistic phase (perigee/apogee) and draconic phase (nodes)
### Reference epochs (J2000 = JD 2451545.0):
###   Perigee epoch  : Jan 4 2000 = JD 2451547  (approx)
###   Asc Node epoch : Jan 1 2000 = JD 2451545  (approx)
### Anomalistic month : 27.55455 days
### Draconic   month  : 27.21222 days
### ═══════════════════════════════════════════════════════════════════════════

Func CalcInserts()

    d = GetDate()
    dayPart   = 0 + left(d, 2)
    monthPart = 0 + substr(d, 4, 2)
    yearPart  = 0 + right(d, 4)

    ### JDN
    a2  = floor((14 - monthPart) / 12)
    y2  = yearPart + 4800 - a2
    m2  = monthPart + 12 * a2 - 3
    jdn = dayPart + floor((153*m2+2)/5) + 365*y2 + floor(y2/4) - floor(y2/100) + floor(y2/400) - 32045

    ### ── Anomalistic month (Perigee → Apogee → Perigee) ────────────────────
    ### Known perigee: Jan 4 2000 = JD 2451547 (Moon closest to Earth)
    anomPeriod = 27.55455
    daysSincePeri = jdn - 2451547
    anomPhase = (daysSincePeri % anomPeriod) / anomPeriod
    if anomPhase < 0  anomPhase += 1  ok

    ### Days into current anomalistic cycle
    anomDaysAgo = anomPhase * anomPeriod

    if anomPhase < 0.04 OR anomPhase >= 0.96
        anomNm = "At Perigee"
    elseif anomPhase < 0.46
        anomNm = "Waxing (→ Apogee)"
    elseif anomPhase < 0.54
        anomNm = "At Apogee"
    else
        anomNm = "Waning (→ Perigee)"
    ok

    ### ── Draconic month (Ascending Node cycle) ──────────────────────────────
    ### Known ascending node crossing: Jan 1 2000 = JD 2451545
    dracPeriod = 27.21222
    daysSinceNode = jdn - 2451545
    dracPhase = (daysSinceNode % dracPeriod) / dracPeriod
    if dracPhase < 0  dracPhase += 1  ok

    if dracPhase < 0.04 OR dracPhase >= 0.96
        dracNm = "At Ascending Node ☊"
    elseif dracPhase < 0.46
        dracNm = "North of Ecliptic"
    elseif dracPhase < 0.54
        dracNm = "At Descending Node ☋"
    else
        dracNm = "South of Ecliptic"
    ok

return

### ═══════════════════════════════════════════════════════════════════════════
### DrawInserts  —  three side-panel diagrams
### Panel layout (right of main 900px canvas):
###   PX = 920  (left edge of panel column)
###   PW = 680  (panel width)
###   Insert 1 (Anomalistic): Y  80 .. 390
###   Insert 2 (Draconic)   : Y 410 .. 660
###   Insert 3 (Inclination): Y 680 .. 960
### ═══════════════════════════════════════════════════════════════════════════

Func DrawInserts()

    DrawInsertAnomalistic()
    DrawInsertDraconic()
    DrawInsertInclination()
    DrawInsertSidereal()
    DrawInsertSynodic()
    DrawInsertEclipses()

return

### ─────────────────────────────────────────────────────────────────────────
### INSERT 1 — Anomalistic Month: Perigee / Apogee
### Moon orbits Earth in an ellipse; Perigee = closest, Apogee = farthest
### Anomalistic period = 27.55455 days
### ─────────────────────────────────────────────────────────────────────────

Func DrawInsertAnomalistic()

    PX = 918   PY = 12   PW = 700   PH = 240

    daVinci.setPen(penPanBdr)
    daVinci.setBrush(brushPanel)
    daVinci.drawRect(PX, PY, PW, PH)

    daVinci.setFont(fontPanTtl)
    daVinci.setPen(penPanTtl)
    daVinci.drawText(PX+12, PY+22, "Anomalistic Month  —  Perigee & Apogee")

    daVinci.setFont(fontPanSub)
    daVinci.setPen(penPanSub)
    daVinci.drawText(PX+12, PY+40, "Period: 27.55455 days   (Moon orbit ellipse around Earth)")

    cDiv = new qColor() { setRgb(90, 80, 150, 140) }
    pDiv = new qPen() { setColor(cDiv)  setWidth(1) }
    daVinci.setPen(pDiv)
    daVinci.drawLine(PX+10, PY+46, PX+PW-10, PY+46)

    ### ── Ellipse: exaggerated eccentricity (e=0.40) so Perigee/Earth visually separate
    ### Real Moon e≈0.055 is too subtle at this scale — we exaggerate for clarity
    ECX = PX + 260
    ECY = PY + 130    # centred in 240px panel
    EA  = 110         # larger ellipse
    ecc = 0.40
    EC  = EA * ecc
    EB  = floor(sqrt(EA*EA - EC*EC))

    ### Earth at RIGHT focus
    ETX = ECX + EC    # ≈ ECX+62
    ETY = ECY

    ### Perigee = right tip of ellipse  (closest to Earth)
    periX = ECX + EA
    periY = ECY
    ### Apogee  = left tip of ellipse  (farthest from Earth)
    apoX = ECX - EA
    apoY = ECY

    ### Draw orbit ellipse
    daVinci.setPen(penMoonPth)
    daVinci.setBrush(brushEmpty)
    daVinci.drawEllipse(ECX-EA, ECY-EB, 2*EA, 2*EB)

    ### Major axis dashed line
    pAxis = new qPen() { setColor(colorFocus)  setWidth(1)  setStyle(2) }
    daVinci.setPen(pAxis)
    daVinci.drawLine(apoX-8, ECY, periX+8, ECY)

    ### Apogee marker — label ABOVE left tip
    daVinci.setPen(penApogee)
    daVinci.setBrush(brushApogee)
    daVinci.drawEllipse(apoX-6, apoY-6, 12, 12)
    daVinci.setFont(fontPanLbl)
    daVinci.setPen(penApogee)
    daVinci.drawText(apoX-16, apoY-22, "Apogee")
    daVinci.setFont(fontPanSml)
    daVinci.drawText(apoX-22, apoY-11, "~406,700 km")
    daVinci.drawText(apoX-16, apoY+17, "phase = 0.5")

    ### Perigee marker — label ABOVE right tip, shifted right of Earth
    daVinci.setPen(penPerigee)
    daVinci.setBrush(brushPerigee)
    daVinci.drawEllipse(periX-6, periY-6, 12, 12)
    daVinci.setFont(fontPanLbl)
    daVinci.setPen(penPerigee)
    daVinci.drawText(periX+10, periY-22, "Perigee")
    daVinci.setFont(fontPanSml)
    daVinci.drawText(periX+10, periY-10, "~356,500 km")
    daVinci.drawText(periX+10, periY+17, "phase = 0.0")

    ### Earth glow + body — at focus, clearly separate from Perigee tip
    daVinci.setPen(penNone)
    for gr = 18 to 7 step -3
        ga = 20 + (18-gr)*10
        cEG = new qColor() { setRgb(45, 105, 255, ga) }
        bEG = new qBrush() { setStyle(1)  setColor(cEG) }
        daVinci.setBrush(bEG)
        daVinci.drawEllipse(ETX-gr, ETY-gr, 2*gr, 2*gr)
    next
    daVinci.setPen(penToday)
    daVinci.setBrush(brushBlue)
    daVinci.drawEllipse(ETX-9, ETY-9, 18, 18)
    daVinci.setFont(fontPanLbl)
    daVinci.setPen(penEarthLb)
    daVinci.drawText(ETX-14, ETY-22, "Earth")   # ABOVE dot

    ### Empty focus marker — left focus
    pFoc = new qPen() { setColor(colorFocus)  setWidth(1) }
    daVinci.setPen(pFoc)
    daVinci.setBrush(brushEmpty)
    eFocX = ECX - EC
    daVinci.drawEllipse(eFocX-3, ECY-3, 6, 6)
    daVinci.setFont(fontPanSml)
    daVinci.setPen(pFoc)
    daVinci.drawText(eFocX-22, ECY+14, "empty focus")

    ### ── Moon position ───────────────────────────────────────────────────────
    ### CCW as seen from north pole: Perigee(right)→TOP→Apogee(left)→BOTTOM→Perigee
    moonAnoRad = anomPhase * 2 * PI
    moonAnoX = ECX + EA * cos(moonAnoRad)
    moonAnoY = ECY - EB * sin(moonAnoRad)

    daVinci.setPen(penNone)
    cMG2 = new qColor() { setRgb(200, 200, 240, 50) }
    bMG2 = new qBrush() { setStyle(1)  setColor(cMG2) }
    daVinci.setBrush(bMG2)
    daVinci.drawEllipse(moonAnoX-13, moonAnoY-13, 26, 26)
    daVinci.setPen(penMoonPos)
    daVinci.setBrush(brushMoonPos)
    daVinci.drawEllipse(moonAnoX-7, moonAnoY-7, 14, 14)

    pEMLine = new qPen() { setColor(colorMoonLbl)  setWidth(1)  setStyle(2) }
    daVinci.setPen(pEMLine)
    daVinci.drawLine(ETX, ETY, moonAnoX, moonAnoY)

    daVinci.setFont(fontPanLbl)
    daVinci.setPen(penMoonLbl)
    if moonAnoX >= ECX
        daVinci.drawText(moonAnoX+12, moonAnoY-4, "Moon")
        daVinci.drawText(moonAnoX+12, moonAnoY+9, anomNm)
    else
        daVinci.drawText(moonAnoX-82, moonAnoY-4, "Moon")
        daVinci.drawText(moonAnoX-82, moonAnoY+9, anomNm)
    ok

    ### ── Info box — pinned to far right screen edge ─────────────────────────
    IBW = 195
    IX  = PX + PW - IBW - 10
    IY  = PY + 22
    cIBox = new qColor() { setRgb(15, 18, 50, 210) }
    bIBox = new qBrush() { setStyle(1)  setColor(cIBox) }
    pIBox = new qPen() { setColor(colorPanBdr)  setWidth(1) }
    daVinci.setPen(pIBox)
    daVinci.setBrush(bIBox)
    daVinci.drawRect(IX-8, IY-14, IBW, 162)

    daVinci.setFont(fontPanSub)
    daVinci.setPen(penPanTtl)
    daVinci.drawText(IX, IY,      "Today's Status:")
    daVinci.setFont(fontPanSml)
    daVinci.setPen(penPanSub)
    anomPct = floor(anomPhase * 1000 + 0.5) / 10
    anomDay = floor(anomPhase * 27.55455 * 10 + 0.5) / 10
    daVinci.drawText(IX, IY+14,  "Phase: " + anomPct + "%")
    daVinci.drawText(IX, IY+26,  "Day:   " + anomDay + " / 27.6")
    daVinci.drawText(IX, IY+38,  anomNm)
    daVinci.drawText(IX, IY+54,  "Perigee: ~356,500 km")
    daVinci.drawText(IX, IY+66,  "Apogee:  ~406,700 km")
    daVinci.drawText(IX, IY+78,  "Mean:    ~384,400 km")
    daVinci.drawText(IX, IY+90,  "Eccent:  ~0.0549")
    daVinci.drawText(IX, IY+102, "Period: 27.55455 d")
    cNote = new qColor() { setRgb(110, 110, 155, 170) }
    pNote = new qPen() { setColor(cNote)  setWidth(1) }
    daVinci.setPen(pNote)
    daVinci.drawText(IX, IY+118, "* eccent. exaggerated")
    daVinci.drawText(IX, IY+129, "  for visual clarity")

return

### ─────────────────────────────────────────────────────────────────────────
### INSERT 2 — Draconic Month: Ascending / Descending Nodes
### Moon orbit is tilted 5.14° to ecliptic; crosses ecliptic at nodes
### Draconic period = 27.21222 days
### ─────────────────────────────────────────────────────────────────────────

Func DrawInsertDraconic()

    PX = 918   PY = 260   PW = 700   PH = 200

    daVinci.setPen(penPanBdr)
    daVinci.setBrush(brushPanel)
    daVinci.drawRect(PX, PY, PW, PH)

    daVinci.setFont(fontPanTtl)
    daVinci.setPen(penPanTtl)
    daVinci.drawText(PX+12, PY+22, "Draconic Month  —  Ascending & Descending Nodes")

    daVinci.setFont(fontPanSub)
    daVinci.setPen(penPanSub)
    daVinci.drawText(PX+12, PY+40, "Period: 27.21222 days   (Moon crosses ecliptic plane)")

    cDiv2 = new qColor() { setRgb(90, 80, 150, 140) }
    pDiv2 = new qPen() { setColor(cDiv2)  setWidth(1) }
    daVinci.setPen(pDiv2)
    daVinci.drawLine(PX+10, PY+46, PX+PW-10, PY+46)

    ### ── Orbit diagram ───────────────────────────────────────────────────────
    DCX = PX + 260
    DCY = PY + 112
    DA  = 145
    DB  = 40
    TILT_PX = 20

    ### Ecliptic reference line (wider than orbit for context)
    daVinci.setPen(penEclip)
    daVinci.drawLine(DCX-DA-15, DCY, DCX+DA+15, DCY)
    daVinci.setFont(fontPanSml)
    daVinci.setPen(penEclip)
    daVinci.drawText(DCX-DA-55, DCY+4, "Ecliptic")

    ### Moon orbit ellipse — solid above ecliptic, dashed below
    pOrbitSolid = new qPen() { setColor(colorMoonPth)  setWidth(2)  setStyle(1) }
    pOrbitDash  = new qPen() { setColor(colorMoonPth)  setWidth(1)  setStyle(2) }
    steps = 120
    prevX = 0   prevY = 0
    for s = 0 to steps
        ang2 = s * 2 * PI / steps
        ox = DCX + DA * cos(ang2)
        oy = DCY - DB * sin(ang2) - TILT_PX * sin(ang2)
        if s > 0
            if sin(ang2 - PI/steps) > 0
                daVinci.setPen(pOrbitSolid)  # above ecliptic = solid
            else
                daVinci.setPen(pOrbitDash)   # below ecliptic = dashed
            ok
            daVinci.drawLine(prevX, prevY, ox, oy)
        ok
        prevX = ox   prevY = oy
    next

    ### Earth at centre
    daVinci.setPen(penNone)
    for gr2 = 16 to 6 step -3
        ga2 = 20 + (16-gr2)*14
        cEG2 = new qColor() { setRgb(45, 105, 255, ga2) }
        bEG2 = new qBrush() { setStyle(1)  setColor(cEG2) }
        daVinci.setBrush(bEG2)
        daVinci.drawEllipse(DCX-gr2, DCY-gr2, 2*gr2, 2*gr2)
    next
    daVinci.setPen(penToday)
    daVinci.setBrush(brushBlue)
    daVinci.drawEllipse(DCX-8, DCY-8, 16, 16)
    daVinci.setFont(fontPanLbl)
    daVinci.setPen(penEarthLb)
    daVinci.drawText(DCX-12, DCY-22, "Earth")   # label ABOVE

    ### Ascending node (☊) — right side — label ABOVE to avoid right clip
    ANX = DCX + DA
    ANY = DCY
    daVinci.setPen(penAscNode)
    daVinci.setBrush(brushAscNode)
    daVinci.drawEllipse(ANX-7, ANY-7, 14, 14)
    daVinci.setFont(fontPanSub)
    daVinci.setPen(penAscNode)
    daVinci.drawText(ANX-50, ANY-28, "Ascending Node ☊")
    daVinci.setFont(fontPanSml)
    daVinci.drawText(ANX-44, ANY-17, "crosses ecliptic  ▲ NORTH")

    ### Descending node (☋) — left side, label ABOVE the node
    DNX = DCX - DA
    DNY = DCY
    daVinci.setPen(penDscNode)
    daVinci.setBrush(brushDscNode)
    daVinci.drawEllipse(DNX-7, DNY-7, 14, 14)
    daVinci.setFont(fontPanSub)
    daVinci.setPen(penDscNode)
    daVinci.drawText(DNX-14, DNY-30, "Descending Node ☋")
    daVinci.setFont(fontPanSml)
    daVinci.setPen(penDscNode)
    daVinci.drawText(DNX-14, DNY-18, "crosses ecliptic  ▼ SOUTH")

    ### North/South labels
    daVinci.setFont(fontPanSml)
    cNorth = new qColor() { setRgb(180, 230, 255, 200) }
    pNorth = new qPen() { setColor(cNorth)  setWidth(1) }
    daVinci.setPen(pNorth)
    daVinci.drawText(DCX-18, DCY - DB - TILT_PX - 6,  "North of Ecliptic")
    cSouth = new qColor() { setRgb(255, 200, 150, 200) }
    pSouth = new qPen() { setColor(cSouth)  setWidth(1) }
    daVinci.setPen(pSouth)
    daVinci.drawText(DCX-18, DCY + DB + TILT_PX + 14, "South of Ecliptic")

    ### ── Moon position on draconic orbit ────────────────────────────────────
    ### CCW astronomical with correct N/S: phase=0.25=North(above), phase=0.75=South(below)
    moonDracRad = dracPhase * 2 * PI
    moonDracX = DCX + DA * cos(moonDracRad)
    moonDracY = DCY - DB * sin(moonDracRad) - TILT_PX * sin(moonDracRad)

    daVinci.setPen(penNone)
    cMG3 = new qColor() { setRgb(200, 200, 240, 50) }
    bMG3 = new qBrush() { setStyle(1)  setColor(cMG3) }
    daVinci.setBrush(bMG3)
    daVinci.drawEllipse(moonDracX-12, moonDracY-12, 24, 24)
    daVinci.setPen(penMoonPos)
    daVinci.setBrush(brushMoonPos)
    daVinci.drawEllipse(moonDracX-7, moonDracY-7, 14, 14)

    pEML2 = new qPen() { setColor(colorMoonLbl)  setWidth(1)  setStyle(2) }
    daVinci.setPen(pEML2)
    daVinci.drawLine(DCX, DCY, moonDracX, moonDracY)

    ### Moon label — avoid overlapping nodes by checking x position
    daVinci.setFont(fontPanLbl)
    daVinci.setPen(penMoonLbl)
    distFromCentre = moonDracX - DCX
    if distFromCentre >= 0
        ### Right side — but avoid Asc Node label area
        if moonDracX > DCX + DA - 20
            daVinci.drawText(moonDracX-20, moonDracY-22, "Moon")
            daVinci.drawText(moonDracX-20, moonDracY-10, dracNm)
        else
            daVinci.drawText(moonDracX+12, moonDracY-4,  "Moon")
            daVinci.drawText(moonDracX+12, moonDracY+9,  dracNm)
        ok
    else
        ### Left side — label above to avoid Desc Node label
        if moonDracX < DCX - DA + 20
            daVinci.drawText(moonDracX-18, moonDracY+16, "Moon")
            daVinci.drawText(moonDracX-18, moonDracY+28, dracNm)
        else
            daVinci.drawText(moonDracX-82, moonDracY-4,  "Moon")
            daVinci.drawText(moonDracX-82, moonDracY+9,  dracNm)
        ok
    ok

    ### ── Info box — pinned to far right screen edge ────────────────────────
    IBW2 = 195
    IX2  = PX + PW - IBW2 - 10
    IY2  = PY + 22
    cIBox2 = new qColor() { setRgb(15, 18, 50, 210) }
    bIBox2 = new qBrush() { setStyle(1)  setColor(cIBox2) }
    pIBox2 = new qPen() { setColor(colorPanBdr)  setWidth(1) }
    daVinci.setPen(pIBox2)
    daVinci.setBrush(bIBox2)
    daVinci.drawRect(IX2-8, IY2-14, IBW2, 120)

    daVinci.setFont(fontPanSub)
    daVinci.setPen(penPanTtl)
    daVinci.drawText(IX2, IY2,     "Today's Status:")
    daVinci.setFont(fontPanSml)
    daVinci.setPen(penPanSub)
    dracPct = floor(dracPhase * 1000 + 0.5) / 10
    dracDay = floor(dracPhase * 27.21222 * 10 + 0.5) / 10
    daVinci.drawText(IX2, IY2+14, "Phase: " + dracPct + "%")
    daVinci.drawText(IX2, IY2+26, "Day:   " + dracDay + " / 27.2")
    daVinci.drawText(IX2, IY2+38, dracNm)
    daVinci.drawText(IX2, IY2+54, "Eclipse near nodes")
    daVinci.drawText(IX2, IY2+66, "at New/Full Moon")
    daVinci.drawText(IX2, IY2+78, "Node prec: 18.6 yr CW")
    daVinci.drawText(IX2, IY2+90, "Period: 27.21222 d")

return

### ─────────────────────────────────────────────────────────────────────────
### INSERT 3 — Moon Inclination to Ecliptic (5.14°)
### Side-view cross-section showing the tilt angle
### ─────────────────────────────────────────────────────────────────────────

Func DrawInsertInclination()

    PX = 918   PY = 468   PW = 700   PH = 155

    daVinci.setPen(penPanBdr)
    daVinci.setBrush(brushPanel)
    daVinci.drawRect(PX, PY, PW, PH)

    daVinci.setFont(fontPanTtl)
    daVinci.setPen(penPanTtl)
    daVinci.drawText(PX+12, PY+22, "Moon's Orbital Inclination to Ecliptic Plane")

    daVinci.setFont(fontPanSub)
    daVinci.setPen(penPanSub)
    daVinci.drawText(PX+12, PY+40, "Inclination: 5.14°  (relative to ecliptic — slowly precesses)")

    cDiv3 = new qColor() { setRgb(90, 80, 150, 140) }
    pDiv3 = new qPen() { setColor(cDiv3)  setWidth(1) }
    daVinci.setPen(pDiv3)
    daVinci.drawLine(PX+10, PY+46, PX+PW-10, PY+46)

    ### ── Side-view diagram — left portion ──────────────────────────────────
    ICX = PX + 255
    ICY = PY + 82    # centred in 155px panel
    IHW = 130

    INCL_DEG      = 5.14    # true inclination — used for labels & Moon lat calc
    INCL_DEG_DRAW = 25.0    # exaggerated for visual clarity
    INCL_RAD      = INCL_DEG_DRAW * PI / 180   # all drawing uses this

    ### Ecliptic plane
    daVinci.setPen(penEclip)
    daVinci.drawLine(ICX - IHW, ICY, ICX + IHW, ICY)
    daVinci.setFont(fontPanSml)
    daVinci.setPen(penEclip)
    daVinci.drawText(ICX - IHW - 52, ICY + 4, "Ecliptic Plane")

    ### Celestial equator — dashed, offset below ecliptic
    CEQ_OFFSET = 28
    pCelEq = new qPen() { setColor(colorSkyBlue)  setWidth(1)  setStyle(2) }
    daVinci.setPen(pCelEq)
    daVinci.drawLine(ICX - IHW, ICY + CEQ_OFFSET, ICX + IHW, ICY + CEQ_OFFSET)
    daVinci.setFont(fontPanSml)
    cCelEq = new qColor() { setRgb(65, 145, 255, 180) }
    pCelEqL = new qPen() { setColor(cCelEq)  setWidth(1) }
    daVinci.setPen(pCelEqL)
    daVinci.drawText(ICX - IHW - 52, ICY + CEQ_OFFSET + 12, "Cel. Equator")
    daVinci.drawText(ICX - IHW - 52, ICY + CEQ_OFFSET + 22, "(23.44°)")

    ### Moon orbital plane — tilted line, shorter
    IML = 130
    moonPlaneX1 = ICX - IML * cos(INCL_RAD)
    moonPlaneY1 = ICY + IML * sin(INCL_RAD)
    moonPlaneX2 = ICX + IML * cos(INCL_RAD)
    moonPlaneY2 = ICY - IML * sin(INCL_RAD)

    pMoonPlane = new qPen() { setColor(colorMoonPth)  setWidth(2)  setStyle(1) }
    daVinci.setPen(pMoonPlane)
    daVinci.drawLine(moonPlaneX1, moonPlaneY1, moonPlaneX2, moonPlaneY2)
    ### Label BELOW the right end of the line
    daVinci.setFont(fontPanSml)
    daVinci.setPen(penMoonLbl)
    daVinci.drawText(moonPlaneX2 - 65, moonPlaneY2 + 10, "Moon's Orbital Plane")

    ### Earth at centre
    daVinci.setPen(penNone)
    for gr3 = 16 to 6 step -3
        ga3 = 20 + (16-gr3)*14
        cEG3 = new qColor() { setRgb(45, 105, 255, ga3) }
        bEG3 = new qBrush() { setStyle(1)  setColor(cEG3) }
        daVinci.setBrush(bEG3)
        daVinci.drawEllipse(ICX-gr3, ICY-gr3, 2*gr3, 2*gr3)
    next
    daVinci.setPen(penToday)
    daVinci.setBrush(brushBlue)
    daVinci.drawEllipse(ICX-9, ICY-9, 18, 18)
    daVinci.setFont(fontPanLbl)
    daVinci.setPen(penEarthLb)
    daVinci.drawText(ICX+14, ICY+28, "Earth")   # further below dot, clear of Moon

    ### Angle arc — drawn at exaggerated angle, labelled with true 5.14°
    arcR2 = 52
    arcSteps2 = 60
    pArcAngle = new qPen() { setColor(colorIncLine)  setWidth(2) }
    daVinci.setPen(pArcAngle)
    prevAX2 = ICX + arcR2   prevAY2 = ICY
    for s2 = 1 to arcSteps2
        arcFrac = s2 / arcSteps2
        arcA = arcFrac * INCL_RAD
        curAX2 = ICX + arcR2 * cos(arcA)
        curAY2 = ICY - arcR2 * sin(arcA)
        daVinci.drawLine(prevAX2, prevAY2, curAX2, curAY2)
        prevAX2 = curAX2   prevAY2 = curAY2
    next
    ### Label shows TRUE angle (not the exaggerated drawing angle)
    midArcX = ICX + (arcR2 + 14) * cos(INCL_RAD / 2)
    midArcY = ICY - (arcR2 + 14) * sin(INCL_RAD / 2)
    daVinci.setFont(fontPanSub)
    daVinci.setPen(penIncLine)
    daVinci.drawText(midArcX, midArcY - 2, "5.14°")
    ### Exaggeration note below arc
    daVinci.setFont(fontPanSml)
    cNote2 = new qColor() { setRgb(120, 120, 160, 170) }
    pNote2 = new qPen() { setColor(cNote2)  setWidth(1) }
    daVinci.setPen(pNote2)
    daVinci.drawText(ICX + arcR2 + 18, ICY + 14, "(angle exaggerated)")

    ### Node marker
    daVinci.setPen(penAscNode)
    daVinci.setBrush(brushAscNode)
    daVinci.drawEllipse(ICX - 6, ICY - 6, 12, 12)

    ### North/South end labels
    daVinci.setFont(fontPanSml)
    pNL = new qPen() { setColor(colorAscNode)  setWidth(1) }
    daVinci.setPen(pNL)
    daVinci.drawText(moonPlaneX2 + 4, moonPlaneY2 + 4, "▲ North")
    pSL = new qPen() { setColor(colorDscNode)  setWidth(1) }
    daVinci.setPen(pSL)
    daVinci.drawText(moonPlaneX1 - 52, moonPlaneY1 - 4, "▼ South")

    ### ── Moon position ON the orbital plane line ────────────────────────────
    ### The Moon sits ON the tilted line. Its latitude determines how far
    ### along the line from centre: d = latFrac × IML
    ### latFrac = sin(dracAngle): +1=max north (right end), -1=max south (left end)

    dracAngle = dracPhase * 2 * PI
    latFrac   = sin(dracAngle)   # -0.905 at phase=0.82 → south

    ### Position on the line at distance d from centre
    d   = latFrac * IML
    MIX = ICX + d * cos(INCL_RAD)
    MIY = ICY - d * sin(INCL_RAD)

    ### Vertical dashed line from Moon straight down to ecliptic level
    moonEclipX = MIX        # same X — drop vertically to ecliptic
    moonEclipY = ICY
    pLatLine = new qPen() { setColor(colorIncLine)  setWidth(1)  setStyle(2) }
    daVinci.setPen(pLatLine)
    daVinci.drawLine(MIX, MIY, moonEclipX, moonEclipY)

    ### Small cross tick on ecliptic at foot of drop line
    pTick = new qPen() { setColor(colorIncLine)  setWidth(2) }
    daVinci.setPen(pTick)
    daVinci.drawLine(moonEclipX-5, moonEclipY-5, moonEclipX+5, moonEclipY+5)
    daVinci.drawLine(moonEclipX-5, moonEclipY+5, moonEclipX+5, moonEclipY-5)

    ### Moon glow
    IMONR = 11    # Moon radius — larger for visibility
    daVinci.setPen(penNone)
    for igr = IMONR+6 to IMONR+1 step -1
        iga = 18 + (IMONR+6-igr)*12
        cIMG = new qColor() { setRgb(200, 200, 240, iga) }
        bIMG = new qBrush() { setStyle(1)  setColor(cIMG) }
        daVinci.setBrush(bIMG)
        daVinci.drawEllipse(MIX-igr, MIY-igr, 2*igr, 2*igr)
    next

    ### Moon body with phase shading (same 3-layer technique)
    ### Sun direction: fixed rightward in this panel (angle 0)
    iSunCos = 1.0   iSunSin = 0.0
    iTermSc = cos(moonPhase * PI)
    iTW2    = IMONR * fabs(iTermSc)

    ### Layer 1: dark base
    cIMDrk = new qColor() { setRgb(28, 28, 48, 255) }
    bIMDrk = new qBrush() { setStyle(1)  setColor(cIMDrk) }
    daVinci.setPen(penNone)
    daVinci.setBrush(bIMDrk)
    daVinci.drawEllipse(MIX-IMONR, MIY-IMONR, 2*IMONR, 2*IMONR)

    ### Layer 2: lit half (sun right → offset right by IMONR)
    cIMLit = new qColor() { setRgb(235, 235, 248, 255) }
    bIMLit = new qBrush() { setStyle(1)  setColor(cIMLit) }
    daVinci.setBrush(bIMLit)
    daVinci.drawEllipse(MIX, MIY-IMONR, 2*IMONR, 2*IMONR)

    ### Layer 3: terminator
    if iTermSc >= 0
        cIMTrm = new qColor() { setRgb(28, 28, 48, 255) }
    else
        cIMTrm = new qColor() { setRgb(235, 235, 248, 255) }
    ok
    bIMTrm = new qBrush() { setStyle(1)  setColor(cIMTrm) }
    daVinci.setBrush(bIMTrm)
    daVinci.drawEllipse(MIX-iTW2, MIY-IMONR, 2*iTW2, 2*IMONR)

    ### Moon outline
    cIMOut = new qColor() { setRgb(150, 150, 185, 180) }
    pIMOut = new qPen() { setColor(cIMOut)  setWidth(1) }
    daVinci.setPen(pIMOut)
    daVinci.setBrush(brushEmpty)
    daVinci.drawEllipse(MIX-IMONR, MIY-IMONR, 2*IMONR, 2*IMONR)

    ### Moon label — above if north of ecliptic, below if south
    daVinci.setFont(fontPanSml)
    daVinci.setPen(penMoonLbl)
    moonLatDeg2 = sin(dracAngle) * INCL_DEG
    moonLatRnd2 = floor(moonLatDeg2 * 10 + 0.5) / 10
    if moonLatRnd2 >= 0
        latTag = "+" + moonLatRnd2 + "°"
        daVinci.drawText(MIX - 10, MIY - IMONR - 16, "Moon")
        daVinci.setPen(penIncLine)
        daVinci.drawText(MIX - 10, MIY - IMONR - 5,  latTag)
    else
        latTag = "" + moonLatRnd2 + "°"
        daVinci.drawText(MIX - 10, MIY + IMONR + 12, "Moon")
        daVinci.setPen(penIncLine)
        daVinci.drawText(MIX - 10, MIY + IMONR + 22, latTag)
    ok

    ### ── Info box — right side of panel ─────────────────────────────────────
    IX3 = PX + PW - 195 - 10   IY3 = PY + 22
    cIBox3 = new qColor() { setRgb(15, 18, 50, 180) }
    bIBox3 = new qBrush() { setStyle(1)  setColor(cIBox3) }
    pIBox3 = new qPen() { setColor(colorPanBdr)  setWidth(1) }
    daVinci.setPen(pIBox3)
    daVinci.setBrush(bIBox3)
    daVinci.drawRect(IX3-8, IY3-14, 211, 120)

    daVinci.setFont(fontPanSub)
    daVinci.setPen(penPanTtl)
    daVinci.drawText(IX3, IY3,    "Key Facts:")
    daVinci.setFont(fontPanSml)
    daVinci.setPen(penPanSub)
    daVinci.drawText(IX3, IY3+14, "Inclination: 5.14° to Ecliptic")
    daVinci.drawText(IX3, IY3+26, "Moon wobbles ±5.14° ecliptic")
    daVinci.drawText(IX3, IY3+38, "Nodes precess 18.6yr CW")
    daVinci.drawText(IX3, IY3+50, "→ eclipse Saros cycle")
    daVinci.drawText(IX3, IY3+62, "Ecliptic tilt 23.44° cel.eq")

    ### Today's Moon ecliptic latitude
    moonLatDeg = sin(dracAngle) * INCL_DEG
    moonLatRnd = floor(moonLatDeg * 10 + 0.5) / 10
    if moonLatRnd >= 0
        moonLatStr = "+" + moonLatRnd + "°  N"
    else
        moonLatStr = "" + moonLatRnd + "°  S"
    ok
    daVinci.setFont(fontPanSub)
    daVinci.setPen(penMoonLbl)
    daVinci.drawText(IX3, IY3+78, "Moon latitude:")
    daVinci.setPen(penIncLine)
    daVinci.drawText(IX3, IY3+92, moonLatStr)
    daVinci.setFont(fontPanSml)
    daVinci.setPen(penPanSml)
    if moonLatRnd >= 0
        daVinci.drawText(IX3, IY3+104, "North of ecliptic")
    else
        daVinci.drawText(IX3, IY3+104, "South of ecliptic")
    ok

return

### ═══════════════════════════════════════════════════════════════════════════
### DrawInsertSidereal  —  Sidereal Month: Moon orbit relative to fixed stars
### Period: 27.32166 days  (shorter than Synodic because Earth hasn't moved yet)
### ═══════════════════════════════════════════════════════════════════════════

Func DrawInsertSidereal()

    PX = 918   PY = 631   PW = 700   PH = 155

    ### Panel background + border
    cPanBg = new qColor() { setRgb(8, 10, 30, 220) }
    bPanBg = new qBrush() { setStyle(1)  setColor(cPanBg) }
    daVinci.setBrush(bPanBg)
    daVinci.setPen(penPanBdr)
    daVinci.drawRect(PX, PY, PW, PH)

    ### Title
    daVinci.setFont(fontPanTtl)
    daVinci.setPen(penPanTtl)
    daVinci.drawText(PX+12, PY+18, "Sidereal Month  —  Moon orbit vs Fixed Stars")
    daVinci.setFont(fontPanSub)
    daVinci.setPen(penPanSub)
    daVinci.drawText(PX+12, PY+32, "Period: 27.32166 days   (Moon returns to same star position)")

    ### ── Calculate sidereal phase ────────────────────────────────────────────
    ### Sidereal period = 27.32166 days
    ### Reference: known Moon at star reference Jan 1 2000 JD=2451545
    siderealPeriod = 27.32166
    d0s = GetDate()
    dayParts  = 0 + left(d0s, 2)
    monParts  = 0 + substr(d0s, 4, 2)
    yearParts = 0 + right(d0s, 4)
    jdn_as = floor((14 - monParts) / 12)
    jdn_ys = yearParts + 4800 - jdn_as
    jdn_ms = monParts + 12 * jdn_as - 3
    jdnS = dayParts + floor((153*jdn_ms+2)/5) + 365*jdn_ys + floor(jdn_ys/4) - floor(jdn_ys/100) + floor(jdn_ys/400) - 32045
    daysSinceRef = jdnS - 2451545
    siderealPhase = (daysSinceRef % siderealPeriod) / siderealPeriod
    if siderealPhase < 0   siderealPhase += 1   ok
    siderealDay = floor(siderealPhase * siderealPeriod * 10 + 0.5) / 10

    ### ── Diagram: Earth at centre, Moon orbiting CCW, star reference ─────────
    SCX = PX + 230   SCY = PY + 82   SR = 60   # orbit circle

    ### Star reference line (fixed direction in space — points to Aries star)
    cStar = new qColor() { setRgb(180, 160, 255, 120) }
    pStar = new qPen() { setColor(cStar)  setWidth(1)  setStyle(2) }
    daVinci.setPen(pStar)
    daVinci.drawLine(SCX, SCY, SCX + SR + 30, SCY)
    daVinci.setFont(fontPanSml)
    daVinci.drawText(SCX + SR + 8, SCY - 4, "★ Star ref")

    ### Orbit circle (dashed)
    pOrbitS = new qPen() { setColor(new qColor() { setRgb(120, 120, 180, 140) })  setWidth(1)  setStyle(2) }
    daVinci.setPen(pOrbitS)
    daVinci.setBrush(brushEmpty)
    daVinci.drawEllipse(SCX-SR, SCY-SR, 2*SR, 2*SR)

    ### Earth at centre
    cEarthS = new qColor() { setRgb(45, 105, 255, 255) }
    pEarthS = new qPen() { setColor(cEarthS)  setWidth(2) }
    bEarthS = new qBrush() { setStyle(1)  setColor(cEarthS) }
    daVinci.setPen(pEarthS)
    daVinci.setBrush(bEarthS)
    daVinci.drawEllipse(SCX-6, SCY-6, 12, 12)
    daVinci.setFont(fontPanSml)
    daVinci.setPen(penPanSub)
    daVinci.drawText(SCX+9, SCY+4, "Earth")

    ### Moon position on orbit
    sidAngRad = siderealPhase * 2 * PI
    moonSX = SCX + SR * cos(sidAngRad)
    moonSY = SCY - SR * sin(sidAngRad)

    ### Line from Earth to Moon
    cMoonLineS = new qColor() { setRgb(200, 200, 255, 100) }
    pMoonLineS = new qPen() { setColor(cMoonLineS)  setWidth(1)  setStyle(2) }
    daVinci.setPen(pMoonLineS)
    daVinci.drawLine(SCX, SCY, moonSX, moonSY)

    ### Moon dot
    pMoonS = new qPen() { setColor(new qColor() { setRgb(220, 220, 255, 255) })  setWidth(2) }
    bMoonS = new qBrush() { setStyle(1)  setColor(new qColor() { setRgb(200, 200, 240, 255) }) }
    daVinci.setPen(pMoonS)
    daVinci.setBrush(bMoonS)
    daVinci.drawEllipse(moonSX-8, moonSY-8, 16, 16)

    ### Moon label
    daVinci.setFont(fontPanSml)
    daVinci.setPen(penPanSub)
    if moonSX >= SCX
        daVinci.drawText(moonSX+10, moonSY-4, "Moon")
        daVinci.drawText(moonSX+10, moonSY+7, "Sidereal")
    else
        daVinci.drawText(moonSX-68, moonSY-4, "Moon")
        daVinci.drawText(moonSX-68, moonSY+7, "Sidereal")
    ok

    ### Arc showing phase swept from star reference
    arcStepS = floor(siderealPhase * 360) + 1
    if arcStepS > 359   arcStepS = 359   ok
    arcRS = 28
    cArcS = new qColor() { setRgb(160, 140, 255, 160) }
    pArcS = new qPen() { setColor(cArcS)  setWidth(2) }
    daVinci.setPen(pArcS)
    prevSAX = SCX + arcRS
    prevSAY = SCY
    for stepS = 1 to arcStepS
        stepAngS = stepS * PI / 180
        curSAX = SCX + arcRS * cos(stepAngS)
        curSAY = SCY - arcRS * sin(stepAngS)
        daVinci.drawLine(prevSAX, prevSAY, curSAX, curSAY)
        prevSAX = curSAX
        prevSAY = curSAY
    next

    ### ── Info box ────────────────────────────────────────────────────────────
    SIW = 195   SIX = PX + PW - SIW - 10   SIY = PY + 22
    cSIBg = new qColor() { setRgb(15, 18, 50, 210) }
    bSIBg = new qBrush() { setStyle(1)  setColor(cSIBg) }
    daVinci.setBrush(bSIBg)
    daVinci.setPen(penPanBdr)
    daVinci.drawRect(SIX-8, SIY-14, SIW, 148)

    daVinci.setFont(fontPanLbl)
    daVinci.setPen(penPanTtl)
    daVinci.drawText(SIX, SIY, "Today's Status:")
    daVinci.setFont(fontPanSml)
    daVinci.setPen(penPanSub)
    sidPct = floor(siderealPhase * 1000 + 0.5) / 10
    daVinci.drawText(SIX, SIY+16, "Phase: " + sidPct + "%")
    daVinci.drawText(SIX, SIY+30, "Day:   " + siderealDay + " / 27.32")

    ### Phase name
    sidNm = ""
    if siderealPhase < 0.04 OR siderealPhase >= 0.96
        sidNm = "At Star Reference"
    elseif siderealPhase < 0.25
        sidNm = "0° → 90°  (Q1)"
    elseif siderealPhase < 0.50
        sidNm = "90° → 180° (Q2)"
    elseif siderealPhase < 0.75
        sidNm = "180° → 270° (Q3)"
    else
        sidNm = "270° → 360° (Q4)"
    ok
    daVinci.drawText(SIX, SIY+44, sidNm)

    daVinci.drawText(SIX, SIY+62, "Angle: " + floor(siderealPhase*3600+0.5)/10 + "°")

    cYellowS = new qColor() { setRgb(255, 220, 80, 200) }
    pYellowS = new qPen() { setColor(cYellowS)  setWidth(1) }
    daVinci.setPen(pYellowS)
    daVinci.drawText(SIX, SIY+80, "Sidereal < Synodic:")
    daVinci.setPen(penPanSub)
    daVinci.drawText(SIX, SIY+94,  "27.32 vs 29.53 days")
    daVinci.drawText(SIX, SIY+108, "Extra 2.21 days for")
    daVinci.drawText(SIX, SIY+122, "Moon to re-align Sun")

return

### ═══════════════════════════════════════════════════════════════════════════
### DrawInsertSynodic  —  Synodic Month: Moon phase cycle relative to Sun
### Period: 29.53059 days  (New Moon → Full Moon → New Moon)
### ═══════════════════════════════════════════════════════════════════════════

Func DrawInsertSynodic()

    PX = 918   PY = 794   PW = 700   PH = 190

    ### Panel background + border
    cPanBg2 = new qColor() { setRgb(8, 10, 30, 220) }
    bPanBg2 = new qBrush() { setStyle(1)  setColor(cPanBg2) }
    daVinci.setBrush(bPanBg2)
    daVinci.setPen(penPanBdr)
    daVinci.drawRect(PX, PY, PW, PH)

    ### Title
    daVinci.setFont(fontPanTtl)
    daVinci.setPen(penPanTtl)
    daVinci.drawText(PX+12, PY+18, "Synodic Month  —  Moon phase cycle vs Sun")
    daVinci.setFont(fontPanSub)
    daVinci.setPen(penPanSub)
    daVinci.drawText(PX+12, PY+32, "Period: 29.53059 days   (New Moon → Full Moon → New Moon)")

    ### Use moonPhase (already calculated) for synodic phase
    synoPhase = moonPhase
    synoDay   = floor(synoPhase * 29.53059 * 10 + 0.5) / 10

    ### ── Diagram: Sun at left, Earth at centre, Moon orbiting ───────────────
    YCX = PX + 230   YCY = PY + 100   YR = 72   # Moon orbit radius

    ### Sun (fixed reference direction — left side)
    sunSynoX = PX + 60   sunSynoY = YCY
    cSunSy = new qColor() { setRgb(255, 215, 0, 255) }
    pSunSy = new qPen() { setColor(cSunSy)  setWidth(2) }
    bSunSy = new qBrush() { setStyle(1)  setColor(cSunSy) }
    daVinci.setPen(pSunSy)
    daVinci.setBrush(bSunSy)
    daVinci.drawEllipse(sunSynoX-14, sunSynoY-14, 28, 28)
    daVinci.setFont(fontPanSml)
    daVinci.setPen(pSunSy)
    daVinci.drawText(sunSynoX-8, sunSynoY+28, "Sun")

    ### Sun direction line (Earth → Sun direction)
    cSunDir = new qColor() { setRgb(255, 215, 0, 80) }
    pSunDir = new qPen() { setColor(cSunDir)  setWidth(1)  setStyle(2) }
    daVinci.setPen(pSunDir)
    daVinci.drawLine(YCX, YCY, sunSynoX+14, sunSynoY)

    ### Orbit circle
    pOrbitY = new qPen() { setColor(new qColor() { setRgb(120, 120, 180, 140) })  setWidth(1)  setStyle(2) }
    daVinci.setPen(pOrbitY)
    daVinci.setBrush(brushEmpty)
    daVinci.drawEllipse(YCX-YR, YCY-YR, 2*YR, 2*YR)

    ### Earth at centre
    cEarthY = new qColor() { setRgb(45, 105, 255, 255) }
    pEarthY = new qPen() { setColor(cEarthY)  setWidth(2) }
    bEarthY = new qBrush() { setStyle(1)  setColor(cEarthY) }
    daVinci.setPen(pEarthY)
    daVinci.setBrush(bEarthY)
    daVinci.drawEllipse(YCX-6, YCY-6, 12, 12)
    daVinci.setFont(fontPanSml)
    daVinci.setPen(penPanSub)
    daVinci.drawText(YCX+9, YCY+4, "Earth")

    ### Phase labels at key positions (New/Full/Quarter)
    daVinci.setFont(fontPanSml)
    cPhaseLbl = new qColor() { setRgb(160, 160, 200, 160) }
    pPhaseLbl = new qPen() { setColor(cPhaseLbl)  setWidth(1) }
    daVinci.setPen(pPhaseLbl)
    ### New Moon = left (toward Sun, phase=0) → sunDir = left = 180°
    daVinci.drawText(YCX - YR - 32, YCY + 4, "New")
    ### Full Moon = right (away from Sun, phase=0.5) → 0°
    daVinci.drawText(YCX + YR + 6,  YCY + 4, "Full")
    ### Q1 = top (phase=0.25) → 90°
    daVinci.drawText(YCX - 12, YCY - YR - 8, "Q1")
    ### Q3 = bottom (phase=0.75) → 270°
    daVinci.drawText(YCX - 12, YCY + YR + 12, "Q3")

    ### Moon position: New Moon is toward Sun (left = 180°), moves CCW
    ### phase=0 → angle=180° (left, toward Sun)
    ### phase=0.5 → angle=0° (right, away from Sun = Full Moon)
    moonSynoAngRad = (synoPhase + 0.5) * 2 * PI
    moonYX = YCX + YR * cos(moonSynoAngRad)
    moonYY = YCY - YR * sin(moonSynoAngRad)

    ### Line Earth → Moon
    cMoonLineY = new qColor() { setRgb(200, 200, 255, 100) }
    pMoonLineY = new qPen() { setColor(cMoonLineY)  setWidth(1)  setStyle(2) }
    daVinci.setPen(pMoonLineY)
    daVinci.drawLine(YCX, YCY, moonYX, moonYY)

    ### Moon dot with phase shading
    pMoonY = new qPen() { setColor(new qColor() { setRgb(220, 220, 255, 255) })  setWidth(2) }
    bMoonY = new qBrush() { setStyle(1)  setColor(new qColor() { setRgb(200, 200, 240, 255) }) }
    daVinci.setPen(pMoonY)
    daVinci.setBrush(bMoonY)
    daVinci.drawEllipse(moonYX-8, moonYY-8, 16, 16)

    ### Moon label
    daVinci.setFont(fontPanSml)
    daVinci.setPen(penPanSub)
    if moonYX >= YCX
        daVinci.drawText(moonYX+10, moonYY-4, "Moon")
        daVinci.drawText(moonYX+10, moonYY+7, moonPhaseNm)
    else
        daVinci.drawText(moonYX-72, moonYY-4, "Moon")
        daVinci.drawText(moonYX-72, moonYY+7, moonPhaseNm)
    ok

    ### ── Info box ────────────────────────────────────────────────────────────
    YIW = 195   YIX = PX + PW - YIW - 10   YIY = PY + 22
    cYIBg = new qColor() { setRgb(15, 18, 50, 210) }
    bYIBg = new qBrush() { setStyle(1)  setColor(cYIBg) }
    daVinci.setBrush(bYIBg)
    daVinci.setPen(penPanBdr)
    daVinci.drawRect(YIX-8, YIY-14, YIW, 148)

    daVinci.setFont(fontPanLbl)
    daVinci.setPen(penPanTtl)
    daVinci.drawText(YIX, YIY, "Today's Status:")
    daVinci.setFont(fontPanSml)
    daVinci.setPen(penPanSub)
    synoPct = floor(synoPhase * 1000 + 0.5) / 10
    daVinci.drawText(YIX, YIY+16, "Phase: " + synoPct + "%")
    daVinci.drawText(YIX, YIY+30, "Day:   " + synoDay + " / 29.53")
    daVinci.drawText(YIX, YIY+44, moonPhaseNm)

    cYellowY = new qColor() { setRgb(255, 220, 80, 200) }
    pYellowY = new qPen() { setColor(cYellowY)  setWidth(1) }
    daVinci.setPen(pYellowY)
    daVinci.drawText(YIX, YIY+62, "Synodic > Sidereal:")
    daVinci.setPen(penPanSub)
    daVinci.drawText(YIX, YIY+76,  "29.53 vs 27.32 days")
    daVinci.drawText(YIX, YIY+90,  "Earth moves ~30°/month")
    daVinci.drawText(YIX, YIY+104, "Moon needs +2.21 days")
    daVinci.drawText(YIX, YIY+118, "to re-align with Sun")

return
### Combined panel at bottom of right column
### Layout: two columns side by side — Solar left, Lunar right
### Each event row: coloured icon + date + type + time UTC
### Today marker shows which eclipses are past/future
### ═══════════════════════════════════════════════════════════════════════════

Func DrawInsertEclipses()

    PX = 1628   PY = 12   PW = 240   PH = 996

    ### Panel background + border
    daVinci.setPen(penPanBdr)
    daVinci.setBrush(brushPanel)
    daVinci.drawRect(PX, PY, PW, PH)

    ### Title
    daVinci.setFont(fontPanTtl)
    daVinci.setPen(penPanTtl)
    daVinci.drawText(PX+12, PY+20, "Solar & Lunar Eclipses")
    daVinci.setFont(fontPanSub)
    daVinci.setPen(penPanSub)
    d2 = GetDate()
    curYr2 = 0 + right(d2, 4)
    daVinci.drawText(PX+12, PY+36, "" + (curYr2-1) + "  ·  " + curYr2 + "  ·  " + (curYr2+1))

    daVinci.setFont(fontPanSml)
    daVinci.setPen(penPanSub)
    daVinci.drawText(PX+12, PY+50, "Meeus algorithm  ·  UTC  ·  ☀ Solar  ☾ Lunar")

    ### Divider
    cDivE = new qColor() { setRgb(90, 80, 150, 140) }
    pDivE = new qPen() { setColor(cDivE)  setWidth(1) }
    daVinci.setPen(pDivE)
    daVinci.drawLine(PX+10, PY+56, PX+PW-10, PY+56)

    ### ── Column headers — Solar top, Lunar bottom ───────────────────────────
    SX = PX + 18    # single column X
    LX = PX + 18    # same X — stacked layout

    ### Solar header
    daVinci.setFont(fontPanSub)
    daVinci.setPen(penSolarTot)
    daVinci.drawText(SX, PY+70, "☀  SOLAR ECLIPSES")
    daVinci.setFont(fontPanSml)
    daVinci.setPen(penPanSub)
    daVinci.drawText(SX, PY+83, "Date              Type          UTC")
    pHdrLine = new qPen() { setColor(colorPanSub)  setWidth(1) }
    daVinci.setPen(pHdrLine)
    daVinci.drawLine(SX, PY+86, PX+PW-18, PY+86)

    ### Horizontal divider between solar and lunar sections
    pSecDiv = new qPen() { setColor(colorPanBdr)  setWidth(1) }

    ### ── Get today's JDN for past/future comparison ──────────────────────────
    d = GetDate()
    todayDay   = 0 + left(d, 2)
    todayMonth = 0 + substr(d, 4, 2)
    todayYear  = 0 + right(d, 4)
    todayInt   = todayYear * 10000 + todayMonth * 100 + todayDay

    ### ── Solar Eclipse rows ──────────────────────────────────────────────────
    ROW_H = 58
    Y0    = PY + 94

    for i = 1 to len(aSolarEcl)
        rec   = aSolarEcl[i]
        eYear = rec[1]   eMon = rec[2]   eDay = rec[3]
        eHour = rec[4]   eMin = rec[5]
        eShort= rec[6]

        rowY   = Y0 + (i-1) * ROW_H
        eclInt = eYear * 10000 + eMon * 100 + eDay
        isPast = (eclInt < todayInt)

        if eShort = "Total"
            ePen   = penSolarTot
            eBrush = brushSolTot
        elseif eShort = "Annular"
            ePen   = penSolarAnn
            eBrush = brushSolAnn
        else
            ePen   = penSolarPar
            eBrush = brushSolPar
        ok

        if isPast
            cDim = new qColor() { setRgb(200, 185, 140, 230) }
            pDim = new qPen() { setColor(cDim)  setWidth(1) }
            bDim = new qBrush() { setStyle(1)  setColor(cDim) }
            ePen   = pDim
            eBrush = bDim
        ok

        ### Year separator line
        if i > 1
            if aSolarEcl[i][1] != aSolarEcl[i-1][1]
                daVinci.setPen(pSecDiv)
                daVinci.drawLine(SX, rowY-8, PX+PW-18, rowY-8)
                daVinci.setFont(fontPanSml)
                cYr = new qColor() { setRgb(190, 180, 230, 220) }
                pYr = new qPen() { setColor(cYr)  setWidth(1) }
                daVinci.setPen(pYr)
                daVinci.drawText(PX+PW-80, rowY-2, "── " + eYear)
            ok
        else
            daVinci.setFont(fontPanSml)
            cYr0 = new qColor() { setRgb(190, 180, 230, 220) }
            pYr0 = new qPen() { setColor(cYr0)  setWidth(1) }
            daVinci.setPen(pYr0)
            daVinci.drawText(PX+PW-80, rowY-2, "── " + eYear)
        ok

        ### Icon
        daVinci.setPen(ePen)
        daVinci.setBrush(eBrush)
        daVinci.drawEllipse(SX, rowY+6, 18, 18)

        ### Today marker
        if eclInt = todayInt
            daVinci.setPen(penToday2)
            daVinci.setBrush(brushEmpty)
            daVinci.drawEllipse(SX-4, rowY+2, 26, 26)
        ok

        ### Date + type + time
        pSolTxt = new qPen() { setColor(new qColor() { setRgb(255, 245, 210, 255) })  setWidth(1) }
        daVinci.setFont(fontPanLbl)
        if isPast
            daVinci.setPen(ePen)
        else
            daVinci.setPen(pSolTxt)
        ok
        sDate = aMonthName3[eMon] + " " + right("0"+eDay,2) + "  " + eYear
        daVinci.drawText(SX+26, rowY+14, sDate)
        daVinci.setFont(fontPanSub)
        daVinci.setPen(ePen)
        daVinci.drawText(SX+26, rowY+28, eShort + " Solar Eclipse")
        daVinci.setFont(fontPanSml)
        if isPast
            daVinci.setPen(ePen)
        else
            daVinci.setPen(pSolTxt)
        ok
        sTime = right("0"+eHour,2) + ":" + right("0"+eMin,2) + " UTC"
        daVinci.drawText(SX+26, rowY+40, sTime)

    next

    ### ── Section divider between Solar and Lunar ────────────────────────────
    SDIV_Y = Y0 + len(aSolarEcl) * ROW_H + 8
    daVinci.setPen(pSecDiv)
    daVinci.drawLine(SX, SDIV_Y, PX+PW-18, SDIV_Y)

    ### Lunar header
    daVinci.setFont(fontPanSub)
    daVinci.setPen(penLunarTot)
    daVinci.drawText(LX, SDIV_Y+16, "☾  LUNAR ECLIPSES")
    daVinci.setFont(fontPanSml)
    daVinci.setPen(penPanSub)
    daVinci.drawText(LX, SDIV_Y+30, "Date              Type          UTC")
    daVinci.setPen(pHdrLine)
    daVinci.drawLine(LX, SDIV_Y+33, PX+PW-18, SDIV_Y+33)

    ### ── Lunar Eclipse rows (bottom half) ───────────────────────────────────
    LY0 = SDIV_Y + 40

    for i = 1 to len(aLunarEcl)
        rec   = aLunarEcl[i]
        eYear = rec[1]   eMon = rec[2]   eDay = rec[3]
        eHour = rec[4]   eMin = rec[5]
        eShort= rec[6]

        rowY   = LY0 + (i-1) * ROW_H
        eclInt = eYear * 10000 + eMon * 100 + eDay
        isPast = (eclInt < todayInt)

        if eShort = "Total"
            ePen   = penLunarTot
            eBrush = brushLunTot
        elseif eShort = "Partial"
            ePen   = penLunarPar
            eBrush = brushLunPar
        else
            ePen   = penLunarPen
            eBrush = brushLunPen
        ok

        if isPast
            cDim2 = new qColor() { setRgb(230, 170, 160, 230) }
            pDim2 = new qPen() { setColor(cDim2)  setWidth(1) }
            bDim2 = new qBrush() { setStyle(1)  setColor(cDim2) }
            ePen   = pDim2
            eBrush = bDim2
        ok

        ### Year separator
        if i > 1
            if aLunarEcl[i][1] != aLunarEcl[i-1][1]
                daVinci.setPen(pSecDiv)
                daVinci.drawLine(LX, rowY-8, PX+PW-18, rowY-8)
                daVinci.setFont(fontPanSml)
                cYr2 = new qColor() { setRgb(190, 180, 230, 220) }
                pYr2 = new qPen() { setColor(cYr2)  setWidth(1) }
                daVinci.setPen(pYr2)
                daVinci.drawText(PX+PW-80, rowY-2, "── " + eYear)
            ok
        else
            daVinci.setFont(fontPanSml)
            cYr02 = new qColor() { setRgb(190, 180, 230, 220) }
            pYr02 = new qPen() { setColor(cYr02)  setWidth(1) }
            daVinci.setPen(pYr02)
            daVinci.drawText(PX+PW-80, LY0-2, "── " + eYear)
        ok

        ### Icon
        daVinci.setPen(ePen)
        daVinci.setBrush(eBrush)
        daVinci.drawEllipse(LX, rowY+6, 18, 18)

        if eclInt = todayInt
            daVinci.setPen(penToday2)
            daVinci.setBrush(brushEmpty)
            daVinci.drawEllipse(LX-4, rowY+2, 26, 26)
        ok

        daVinci.setFont(fontPanLbl)
        ### Use bright pen for text, ePen only for icon colour
        pLunTxt = new qPen() { setColor(new qColor() { setRgb(235, 215, 210, 255) })  setWidth(1) }
        if isPast
            daVinci.setPen(ePen)
        else
            daVinci.setPen(pLunTxt)
        ok
        sDate2 = aMonthName3[eMon] + " " + right("0"+eDay,2) + "  " + eYear
        daVinci.drawText(LX+26, rowY+14, sDate2)
        daVinci.setFont(fontPanSub)
        daVinci.setPen(ePen)
        daVinci.drawText(LX+26, rowY+28, eShort + " Lunar Eclipse")
        daVinci.setFont(fontPanSml)
        if isPast
            daVinci.setPen(ePen)
        else
            daVinci.setPen(pLunTxt)
        ok
        sTime2 = right("0"+eHour,2) + ":" + right("0"+eMin,2) + " UTC"
        daVinci.drawText(LX+26, rowY+40, sTime2)

    next

    ### ── Legend at bottom — 2 rows for narrow panel ────────────────────────
    LGY = PY + PH - 42
    daVinci.setFont(fontPanSml)

    ### Row 1: Solar
    daVinci.setPen(penSolarTot)
    daVinci.setBrush(brushSolTot)
    daVinci.drawEllipse(SX, LGY-3, 9, 9)
    daVinci.setPen(penPanSub)
    daVinci.drawText(SX+12, LGY+4, "Total")

    daVinci.setPen(penSolarAnn)
    daVinci.setBrush(brushSolAnn)
    daVinci.drawEllipse(SX+58, LGY-3, 9, 9)
    daVinci.setPen(penPanSub)
    daVinci.drawText(SX+70, LGY+4, "Annular")

    daVinci.setPen(penSolarPar)
    daVinci.setBrush(brushSolPar)
    daVinci.drawEllipse(SX+132, LGY-3, 9, 9)
    daVinci.setPen(penPanSub)
    daVinci.drawText(SX+144, LGY+4, "Partial ☀")

    ### Row 2: Lunar
    daVinci.setPen(penLunarTot)
    daVinci.setBrush(brushLunTot)
    daVinci.drawEllipse(SX, LGY+13, 9, 9)
    daVinci.setPen(penPanSub)
    daVinci.drawText(SX+12, LGY+20, "Total")

    daVinci.setPen(penLunarPar)
    daVinci.setBrush(brushLunPar)
    daVinci.drawEllipse(SX+58, LGY+13, 9, 9)
    daVinci.setPen(penPanSub)
    daVinci.drawText(SX+70, LGY+20, "Partial")

    daVinci.setPen(penLunarPen)
    daVinci.setBrush(brushLunPen)
    daVinci.drawEllipse(SX+132, LGY+13, 9, 9)
    daVinci.setPen(penPanSub)
    daVinci.drawText(SX+144, LGY+20, "Penumbra ☾")

    cPastNote = new qColor() { setRgb(170, 170, 210, 200) }
    pPastNote = new qPen() { setColor(cPastNote)  setWidth(1) }
    daVinci.setPen(pPastNote)
    daVinci.drawText(SX, LGY+34, "dimmed=past  ○=today")

return

### ═══════════════════════════════════════════════════════════════════════════
### CalcEclipses — wrapper that calls SolarMain/LunarMain logic and fills arrays
### Uses functions from SolarMain-LunarMain-Eclipse-1.ring (verbatim)
### ═══════════════════════════════════════════════════════════════════════════

Func CalcEclipses()
    d0 = GetDate()
    curYr = 0 + right(d0, 4)
    start_year = curYr - 1
    end_year   = curYr + 1
    aSolarEcl = []
    aLunarEcl = []

    ### ── Solar eclipses ─────────────────────────────────────────────────────
    ks = floor(new_moon_k(start_year))
    ke = ceil(new_moon_k(end_year + 1))
    for ek = ks to ke
        res = calculate_eclipse(ek)
        if res[1] = 1
            dr = jde_to_date(res[2])
            ey=dr[1]  em=dr[2]  ed=dr[3]  eh=dr[4]  emi=dr[5]
            if ey >= start_year and ey <= end_year
                et = res[3]
                es = "Partial"
                if et = "Total..."   es = "Total"    ok
                if et = "Annular."   es = "Annular"  ok
                if et = "Hybrid.."   es = "Hybrid"   ok
                aSolarEcl + [ey, em, ed, eh, emi, es]
            ok
        ok
    next

    ### ── Lunar eclipses ─────────────────────────────────────────────────────
    jd_lo = JulianDay(start_year, 1, 1)
    jd_hi = JulianDay(end_year, 12, 31)
    for ly = start_year to end_year
        for lm = 1 to 12
            lseed = fullMoon(ly, lm)
            lfull = RefineFullMoonBisection(lseed)
            if lfull >= jd_lo and lfull <= jd_hi
                llatDeg = fabs(MoonLatitudeDeg(lfull))
                ldistER = MoonDistanceEarthRadii(lfull)
                llunarR = MEAN_MOON_ANG_RADIUS_DEG * (MEAN_MOON_DIST_ER / ldistER)
                lumbraD = BASE_UMBRA_AT_MEAN_DEG   * (MEAN_MOON_DIST_ER / ldistER)
                lpenumD = lumbraD + PENUMBRA_EXTRA_DEG
                letype = ""
                if llatDeg + llunarR <= lumbraD
                    letype = "Total"
                elseif llatDeg - llunarR < lumbraD
                    letype = "Partial"
                elseif llatDeg - llunarR < lpenumD
                    letype = "Penumbra"
                ok
                if letype != ""
                    ldr = jde_to_date(lfull)
                    aLunarEcl + [ldr[1], ldr[2], ldr[3], ldr[4], ldr[5], letype]
                ok
            ok
        next
    next
return

Func LonToXY(lon)
    ang = lon * PI / 180
    x   = CX + B * cos(ang)
    y   = CY - A * sin(ang)
    return [x, y]

### ═══════════════════════════════════════════════════════════════════════════
### DrawScene
### ═══════════════════════════════════════════════════════════════════════════

Func DrawScene()

    ### Calculate eclipse data once on first draw
    if len(aSolarEcl) = 0
        CalcEclipses()
    ok

    ### Background
    MonaLisa.fill(colorBgDark)

    ### Stars (deterministic LCG)
    seed = 137
    for i = 1 to 240
        seed = (seed * 1664525 + 1013904223) % 4294967296
        sx = seed % W
        seed = (seed * 1664525 + 1013904223) % 4294967296
        sy = seed % H
        seed = (seed * 1664525 + 1013904223) % 4294967296
        br = 80 + (seed % 175)
        cStar = new qColor() { setRgb(br, br, br, 190) }
        pStar = new qPen()   { setColor(cStar)  setWidth(1) }
        daVinci.setPen(pStar)
        daVinci.drawPoint(sx, sy)
    next

    ### ── Sector lines (faint dividers) ─────────────────────────────────────
    daVinci.setPen(penSector)
    for i = 0 to 11
        pt = LonToXY(i * 30)
        daVinci.drawLine(CX, CY, pt[1], pt[2])
    next

    ### ── Outer zodiac ring ──────────────────────────────────────────────────
    RING_R  = 415
    daVinci.setPen(penRingVio)
    daVinci.setBrush(brushEmpty)
    daVinci.drawEllipse(CX-RING_R,  CY-RING_R,  2*RING_R,  2*RING_R)

    ### ── Tick marks ─────────────────────────────────────────────────────────
    daVinci.setPen(penTick)
    for i = 0 to 11
        ang = i * 30 * PI / 180
        x1 = CX + (RING_R-13) * cos(ang)
        y1 = CY - (RING_R-13) * sin(ang)
        x2 = CX + (RING_R+13) * cos(ang)
        y2 = CY - (RING_R+13) * sin(ang)
        daVinci.drawLine(x1, y1, x2, y2)
    next

    ### ── Zodiac labels ───────────────────────────────────────────────────────
    GLYPH_R = 396
    NAME_R  = 369
    DATE_R  = 349

    for i = 1 to 12
        midLon = (i-1)*30 + 15
        ang    = midLon * PI / 180
        gx = CX + GLYPH_R * cos(ang)
        gy = CY - GLYPH_R * sin(ang)
        nx = CX + NAME_R  * cos(ang)
        ny = CY - NAME_R  * sin(ang)
        dx = CX + DATE_R  * cos(ang)
        dy = CY - DATE_R  * sin(ang)

        daVinci.setFont(fontGlyph)
        daVinci.setPen(penGold)
        daVinci.drawText(gx-10, gy+5, aZodiac[i][3])

        daVinci.setFont(fontName)
        daVinci.setPen(penViolet)
        daVinci.drawText(nx-22, ny+4, aZodiac[i][1])

        daVinci.setFont(fontDate)
        daVinci.setPen(penGreen)
        daVinci.drawText(dx-18, dy+4, aZodiac[i][4])
    next

    ### ── Orbit ellipse (yellow/gold) ──────────────────────────────────────────
    daVinci.setPen(penSummer)
    daVinci.setBrush(brushEmpty)
    daVinci.drawEllipse(CX-B, CY-A, 2*B, 2*A)

    ### ── Equinox / Solstice / Perihelion / Aphelion markers ─────────────────
    aSpecial = [
        [   0, "Vernal Equinox",   "Aries  Mar 21",      penSpring, brushSpring ],
        [  90, "Aphelion ~Jul 4",  "Cancer Jun 21",      penAph,    brushAph    ],
        [ 180, "Autumnal Equinox", "Libra  Sep 23",      penAutumn, brushAutumn ],
        [ 270, "Perihelion ~Jan 3","Capricorn Dec 22",   penPeri,   brushPeri   ]
    ]

    ### ── Aphelion label — ABOVE the top of the yellow circle ───────────────
    daVinci.setFont(fontSmall)
    daVinci.setPen(penAph)
    daVinci.drawText(CX - 50, CY - A - 18, "Aphelion ~Jul 4")
    daVinci.drawText(CX - 50, CY - A - 6,  "Cancer Jun 21")

    ### ── Perihelion label — BELOW the bottom of the yellow circle ───────────
    daVinci.setPen(penPeri)
    daVinci.drawText(CX - 50, CY + A + 8,  "Perihelion ~Jan 3")
    daVinci.drawText(CX - 50, CY + A + 20, "Capricorn Dec 22")

    for item in aSpecial
        pt  = LonToXY(item[1])
        spx = pt[1]   spy = pt[2]
        daVinci.setPen(item[4])
        daVinci.setBrush(item[5])
        daVinci.drawEllipse(spx-7, spy-7, 14, 14)
        daVinci.setFont(fontSmall)
        daVinci.setPen(item[4])
        sang = item[1] * PI / 180

        ### Only draw labels for Vernal/Autumnal — Aphelion/Perihelion done above
        if item[1] > 85 and item[1] < 95
            ### Aphelion: label already drawn above
        elseif item[1] > 265 and item[1] < 275
            ### Perihelion: label already drawn above
        elseif cos(sang) > 0
            ### Vernal Equinox (right): label to LEFT of dot, above the line
            daVinci.drawText(spx-115, spy-20, item[2])
            daVinci.drawText(spx-115, spy-8,  item[3])
        else
            ### Autumnal Equinox (left): label just right of dot
            daVinci.drawText(spx+14, spy-2,  item[2])
            daVinci.drawText(spx+14, spy+10, item[3])
        ok
    next

    ### ── Sun at BOTTOM focus ─────────────────────────────────────────────────
    daVinci.setPen(penNone)
    for sunR = 34 to 14 step -4
        aS = 10 + (34-sunR)*4
        cCorona = new qColor() { setRgb(255, 190, 35, aS) }
        bCorona = new qBrush() { setStyle(1)  setColor(cCorona) }
        daVinci.setBrush(bCorona)
        daVinci.drawEllipse(SUN_X-sunR, SUN_Y-sunR, 2*sunR, 2*sunR)
    next
    daVinci.setPen(penSunLbl)
    daVinci.setBrush(brushGold)
    daVinci.drawEllipse(SUN_X-13, SUN_Y-13, 26, 26)
    daVinci.setFont(fontLabel)
    daVinci.setPen(penSunLbl)
    daVinci.drawText(SUN_X-10, SUN_Y+32, "Sun")

    ### ── Empty focus at TOP ─────────────────────────────────────────────────
    daVinci.setPen(penFocus)
    daVinci.setBrush(brushEmpty)
    daVinci.drawEllipse(FOCUS2_X-4, FOCUS2_Y-4, 8, 8)
    daVinci.setFont(fontSmall)
    daVinci.setPen(penFocus)
    daVinci.drawText(FOCUS2_X+10, FOCUS2_Y+5, "empty focus")

    ### ══════════════════════════════════════════════════════════════════════
    ### TODAY'S EARTH POSITION
    ### ══════════════════════════════════════════════════════════════════════

    pt = LonToXY(todayLon)
    EX = pt[1]
    EY = pt[2]

    ### ── Angle line from CENTRE (CX,CY) to Earth position ──────────────────
    ### Draw line from centre to slightly beyond Earth
    angRad  = todayLon * PI / 180
    lineEndX = CX + (B + 40) * cos(angRad)
    lineEndY = CY - (A + 40) * sin(angRad)

    daVinci.setPen(penAngle)
    daVinci.drawLine(CX, CY, lineEndX, lineEndY)

    ### ── Reference arc from Aries (0 deg) to today's angle ─────────────────
    arcRad = 90     # smaller radius — less intrusive
    cArcCol = new qColor() { setRgb(255, 210, 50, 180) }
    penArc = new qPen() { setColor(cArcCol)  setWidth(1)  setStyle(2) }
    daVinci.setPen(penArc)

    ### Determine arc direction (always CCW = increasing angle)
    arcSteps = floor(todayLon) + 1
    if arcSteps < 1  arcSteps = 1  ok

    prevAX = CX + arcRad   # start at Aries = 0 deg = right
    prevAY = CY
    for step = 1 to arcSteps
        stepAng = step * PI / 180
        curAX   = CX + arcRad * cos(stepAng)
        curAY   = CY - arcRad * sin(stepAng)
        daVinci.drawLine(prevAX, prevAY, curAX, curAY)
        prevAX  = curAX
        prevAY  = curAY
    next

    ### ── Angle value label near arc midpoint ────────────────────────────────
    ### For todayLon near 360°, midpoint is near 180° = left side of diagram
    ### Place label to the left of centre, clear of the Sun and angle line
    midAngRad = (todayLon / 2) * PI / 180
    lblR      = arcRad + 36
    lblX      = CX + lblR * cos(midAngRad)
    lblY      = CY - lblR * sin(midAngRad)
    ### Push label further left if it falls near horizontal centreline
    if lblX > CX - 80 and lblX < CX + 80
        lblX = CX - 160
    ok
    daVinci.setFont(fontAngle)
    cAngLbl = new qColor() { setRgb(255, 220, 80, 230) }
    pAngLbl = new qPen() { setColor(cAngLbl)  setWidth(1) }
    daVinci.setPen(pAngLbl)
    daVinci.drawText(lblX - 18, lblY + 4, todayDeg)

    ### ── "0 deg / Aries" reference tick on the angle arc ───────────────────
    penRef = new qPen() { setColor(colorSpring)  setWidth(2) }
    daVinci.setPen(penRef)
    daVinci.drawLine(CX + arcRad - 10, CY, CX + arcRad + 10, CY)

    ### ── Earth glow ─────────────────────────────────────────────────────────
    daVinci.setPen(penNone)
    for earthR = 26 to 8 step -3
        aG = 25 + (26-earthR)*10
        cGlow = new qColor() { setRgb(45, 105, 255, aG) }
        bGlow = new qBrush() { setStyle(1)  setColor(cGlow) }
        daVinci.setBrush(bGlow)
        daVinci.drawEllipse(EX-earthR, EY-earthR, 2*earthR, 2*earthR)
    next

    ### ── Earth body ─────────────────────────────────────────────────────────
    daVinci.setPen(penToday)
    daVinci.setBrush(brushBlue)
    daVinci.drawEllipse(EX-11, EY-11, 22, 22)

    ### ── Moon orbit around Earth ────────────────────────────────────────────
    DrawMoon(EX, EY)

    ### ── Earth labels — offset intelligently by quadrant ────────────────────
    angRad  = todayLon * PI / 180
    cosA    = cos(angRad)
    sinA    = sin(angRad)

    # Offset label to avoid overlapping the Earth dot
    if cosA >= 0
        lx = EX + 16
    else
        lx = EX - 90
    ok
    if sinA >= 0
        ly = EY - 28
    else
        ly = EY + 16
    ok

    daVinci.setFont(fontToday)
    daVinci.setPen(penToday)
    daVinci.drawText(lx, ly,      "Earth")

    daVinci.setFont(fontSmall)
    daVinci.setPen(penEarthLb)
    daVinci.drawText(lx, ly + 13, todayStr)

    cAngLbl2 = new qColor() { setRgb(255, 220, 80, 220) }
    pAngLbl2 = new qPen() { setColor(cAngLbl2)  setWidth(1) }
    daVinci.setPen(pAngLbl2)
    daVinci.drawText(lx, ly + 25, todayDeg)

    daVinci.setPen(penGold)
    daVinci.drawText(lx, ly + 37, todayZodiac)

    ### ── Title ──────────────────────────────────────────────────────────────
    daVinci.setFont(fontTitle)
    daVinci.setPen(penTitle)
    daVinci.drawText(20, 30, "Earth's Elliptical Orbit  -  Zodiac  +  Moon Orbit")

    daVinci.setFont(fontSub)
    daVinci.setPen(penSub)
    daVinci.drawText(20, 50, "Today: " + todayStr +
        "   Lon: " + todayDeg +
        "   Sign: " + todayZodiac +
        "   |   Aries 0 deg = Mar 21 (right)  CCW")

    daVinci.setPen(penMoonLbl)
    moonPct = floor(moonPhase * 1000 + 0.5) / 10
    daVinci.drawText(20, 66, "Moon: " + moonPhaseNm +
        "   Phase: " + moonPct + "%"  +
        "   Orbit angle: " + floor(moonAngle * 10 + 0.5) / 10 + " deg")

    ### ── Right-panel inserts ─────────────────────────────────────────────────
    ### Vertical divider between main canvas and insert panel
    cDivV = new qColor() { setRgb(90, 80, 150, 160) }
    pDivV = new qPen() { setColor(cDivV)  setWidth(1) }
    daVinci.setPen(pDivV)
    daVinci.drawLine(910, 10, 910, H-10)

    DrawInserts()

    ### ── Finish ──────────────────────────────────────────────────────────────
    daVinci.endpaint()
    Canvas.setPixMap(MonaLisa)
    myApp.processEvents()

return

### ═══════════════════════════════════════════════════════════════════════════
### Eclipse calculation functions — from SolarMain-LunarMain-Eclipse-1.ring
### These functions are called by CalcEclipses() above
### ═══════════════════════════════════════════════════════════════════════════

func deg2rad(deg)
    return deg * PI / 180.0

# ===================================
func normalize_angle(angle)
    while angle < 0
        angle += 360.0
    end
    
    while angle >= 360.0
        angle -= 360.0
    end
    
    return angle

# ===================================
func julian_day(year, month, day)
    if month  <= 2
        year  -= 1
        month += 12
    ok
    
    jd_alpha  = floor(year / 100)
    jd_beta  = 2 - jd_alpha + floor(jd_alpha / 4)
    jd = floor(365.25 * (year + 4716)) + floor(30.6001 * (month + 1)) + day + jd_beta - 1524.5
    
    return jd

# ===================================
func new_moon_k(year)
    return (year - 2000.0) * 12.3685

# ===================================
func mean_new_moon(fm_k)
    ecl_tau  = fm_k / 1236.85
    ecl_T2 = ecl_tau  * ecl_tau
    ecl_T3 = ecl_T2 * ecl_tau
    ecl_T4 = ecl_T3 * ecl_tau
    
    jde = 2451550.09766 + 29.530588861 * fm_k + 
          0.00015437    * ecl_T2 - 
          0.000000150   * ecl_T3 + 
          0.00000000073 * ecl_T4
          
    return jde

# ===================================
func sun_anomaly(fm_k, ecl_tau)
    angle = 2.5534 + 29.10535670 * fm_k - 
            0.0000014  * ecl_tau * ecl_tau - 
            0.00000011 * ecl_tau * ecl_tau * ecl_tau
    
    return normalize_angle(angle)

# ===================================
func moon_anomaly(fm_k, ecl_tau)
    ecl_T2 = ecl_tau  * ecl_tau
    ecl_T3 = ecl_T2 * ecl_tau
    ecl_T4 = ecl_T3 * ecl_tau
    angle = 201.5643 + 385.81693528 * fm_k + 
            0.0107582   * ecl_T2 + 
            0.00001238  * ecl_T3 - 
            0.000000058 * ecl_T4
    
    return normalize_angle(angle)

# ===================================
func moon_argument(fm_k, ecl_tau)
    ecl_T2 = ecl_tau  * ecl_tau
    ecl_T3 = ecl_T2 * ecl_tau
    ecl_T4 = ecl_T3 * ecl_tau
    angle = 160.7108 + 390.67050284 * fm_k - 
            0.0016118   * ecl_T2 - 
            0.00000227  * ecl_T3 + 
            0.000000011 * ecl_T4
    return normalize_angle(angle)

# ===================================
func moon_node(fm_k, ecl_tau)
    ecl_T2 = ecl_tau  * ecl_tau
    ecl_T3 = ecl_T2 * ecl_tau
    angle = 124.7746 - 1.56375588 * fm_k + 
            0.0020672  * ecl_T2 + 
            0.00000215 * ecl_T3
    
    return normalize_angle(angle)

# ===================================
func calculate_eclipse(fm_k)
    ecl_tau  = fm_k / 1236.85
    ecl_T2 = ecl_tau * ecl_tau
    ecl_T3 = ecl_T2 * ecl_tau
    
    JDE = mean_new_moon(fm_k)
    
    ecl_manom     = deg2rad(sun_anomaly(fm_k, ecl_tau))
    Mp    = deg2rad(moon_anomaly(fm_k, ecl_tau))
    ecl_farg     = deg2rad(moon_argument(fm_k, ecl_tau))
    Omega = deg2rad(moon_node(fm_k, ecl_tau))
    
    ecl_ecc = 1.0 - 0.002516 * ecl_tau - 0.0000074 * ecl_T2
    
    #--- Check if Moon is near a node (F near 0° or 180°)
    F_deg       = moon_argument(fm_k, ecl_tau)
    F_node_dist = fabs(F_deg)
    
    if F_node_dist > 180
        F_node_dist = 360 - F_node_dist
    ok
    
    if F_node_dist > 90
        F_node_dist = 180 - F_node_dist
    ok
    
    if F_node_dist > 15.5
        return [0, JDE, "", 0, 0, 0]
    ok
    
    # Time correction
    correction = -0.4072 * sin(Mp) +
                 0.17241 * ecl_ecc * sin(ecl_manom) +
                 0.01608 * sin(2.0 * Mp) +
                 0.01039 * sin(2.0 * ecl_farg) +
                 0.00739 * ecl_ecc * sin(Mp - ecl_manom) -
                 0.00514 * ecl_ecc * sin(Mp + ecl_manom) +
                 0.00208 * ecl_ecc * ecl_ecc * sin(2.0 * ecl_manom) -
                 0.00111 * sin(Mp - 2.0 * ecl_farg) -
                 0.00057 * sin(Mp + 2.0 * ecl_farg) +
                 0.00056 * ecl_ecc * sin(2.0 * Mp + ecl_manom) -
                 0.00042 * sin(3.0 * Mp) +
                 0.00042 * ecl_ecc * sin(ecl_manom + 2.0 * ecl_farg) +
                 0.00038 * ecl_ecc * sin(ecl_manom - 2.0 * ecl_farg) -
                 0.00024 * ecl_ecc * sin(2.0 * Mp - ecl_manom) -
                 0.00017 * sin(Omega) -
                 0.00007 * sin(Mp + 2.0 * ecl_manom) +
                 0.00004 * sin(2.0 * Mp - 2.0 * ecl_farg) +
                 0.00004 * sin(3.0 * ecl_manom) +
                 0.00003 * sin(Mp + ecl_manom - 2.0 * ecl_farg) +
                 0.00003 * sin(2.0 * Mp + 2.0 * ecl_farg) -
                 0.00003 * sin(Mp + ecl_manom + 2.0 * ecl_farg) +
                 0.00003 * sin(Mp - ecl_manom + 2.0 * ecl_farg) -
                 0.00002 * sin(Mp - ecl_manom - 2.0 * ecl_farg) -
                 0.00002 * sin(3.0 * Mp + ecl_manom) +
                 0.00002 * sin(4.0 * Mp)
    
    JDE += correction
    
    #--- Calculate P, Q, W for gamma (intermediate values)
    ecl_pgam = 0.2070 * ecl_ecc * sin(ecl_manom) +
        0.0024 * ecl_ecc * sin(2.0 * ecl_manom) -
        0.0392 * sin(Mp) +
        0.0116 * sin(2.0 * Mp) -
        0.0073 * ecl_ecc * sin(Mp + ecl_manom) +
        0.0067 * ecl_ecc * sin(Mp - ecl_manom) +
        0.0118 * sin(2.0 * ecl_farg)
    
    ecl_qgam = 5.2207 -
        0.0048 * ecl_ecc * cos(ecl_manom) +
        0.0020 * ecl_ecc * cos(2.0 * ecl_manom) -
        0.3299 * cos(Mp) -
        0.0060 * ecl_ecc * cos(Mp + ecl_manom) +
        0.0041 * ecl_ecc * cos(Mp - ecl_manom)
    
    ecl_wval = fabs(cos(ecl_farg))
    
    #--- Calculate gamma (least distance from shadow axis to Earth center)
    gamma = (ecl_pgam * cos(ecl_farg) + ecl_qgam * sin(ecl_farg)) * (1.0 - 0.0048 * ecl_wval)
    
    # Calculate u (radius of Moon's umbral cone in fundamental plane)
    u = 0.0059 +
        0.0046 * ecl_ecc * cos(ecl_manom) -
        0.0182 * cos(Mp) +
        0.0004 * cos(2.0 * Mp) -
        0.0005 * cos(ecl_manom + Mp)
    
    abs_gamma = fabs(gamma)
    
    #--- Check if any type of eclipse is visible
    #--- If |gamma| > 1.5433 + u, no eclipse is visible from Earth
    threshold = 1.5433 + u
    
    if abs_gamma > threshold
        return [0, JDE, "", gamma, 0, u]
    ok
    
    #--- Calculate Moon/Sun diameter ratio
    #--- This is used for classification and for magnitude of central eclipses
    diameter_ratio = (1.5433 + u - abs_gamma) / (0.5461 + 2.0 * u)
    
    if diameter_ratio <= 0
        return [0, JDE, "", gamma, 0, u]
    ok
    
    #--- ECLIPSE TYPE CLASSIFICATION (Meeus Algorithm)
    #--- Following the standard Bessel method
    #
    #--- Classification rules:
    #--- 1. If 0.9972 <= |gamma| <= 1.5433 + u → Partial (non-central)
    #--- 2. If |gamma| < 0.9972 → Central eclipse, then:
    #---    - If u < 0 → Total (umbra reaches Earth)
    #---    - If u > 0.0047 → Annular (umbra doesn't reach Earth)
    #---    - If 0 <= u <= 0.0047 → Hybrid or Annular
    
    eclipse_type = ""
    magnitude    = 0.0
    
    #--- Check if eclipse is non-central (partial)
    if abs_gamma >= 0.9972 and abs_gamma <= threshold
        eclipse_type = "Partial."
        
        #--- For partial eclipses, magnitude is the fraction of diameter covered
        #--- This needs to be calculated differently from diameter_ratio
        #--- Using approximation: magnitude ≈ (1.5433 + u - |gamma|) / (1.5433 + u + 0.5461)
        magnitude = (1.5433 + u - abs_gamma) / (1.5433 + u + 0.5461)
    
    elseif abs_gamma < 0.9972
        #--- Central eclipse - classify by u value
        #--- For central eclipses, magnitude = Moon diameter / Sun diameter
        magnitude = diameter_ratio
        
        if u < 0
            eclipse_type = "Total..."
        
        elseif u > 0.0047
            eclipse_type = "Annular."
        else
            #--- Between 0 and 0.0047 - could be Hybrid or Annular
            #--- Additional test: w = 0.00464 * sqrt(1 - gamma²)
            ecl_w = 0.00464 * sqrt(1.0 - gamma * gamma)
            
            if u < ecl_w
                eclipse_type = "Hybrid.."
            else
                eclipse_type = "Annular."
            ok
        ok
    else
        #--- Should not reach here if threshold check is correct
        eclipse_type = "Partial."
        magnitude    = (1.5433 + u - abs_gamma) / (1.5433 + u + 0.5461)
    ok
    
    return [1, JDE, eclipse_type, gamma, magnitude, u]

# ===================================
func jde_to_date(jde)
    jd_z = floor(jde + 0.5)
    jd_f = (jde + 0.5) - jd_z
    
    alpha = floor((jd_z - 1867216.25) / 36524.25)
    jd_a = jd_z + 1 + alpha - floor(alpha / 4.0)
    
    jd_b = jd_a + 1524
    jd_c = floor((jd_b - 122.1) / 365.25)
    jd_d = floor(365.25 * jd_c)
    jd_e = floor((jd_b - jd_d) / 30.6001)
    
    day = floor(jd_b - jd_d - floor(30.6001 * jd_e))
    
    if jd_e < 14
        month = floor(jd_e - 1)
    else
        month = floor(jd_e - 13)
    ok
    
    if month > 2
        year = floor(jd_c - 4716)
    else
        year = floor(jd_c - 4715)
    ok
    
    day_fraction = jd_f
    hour   = floor(day_fraction * 24)
    minute = floor((day_fraction * 24 - hour) * 60)
    
    return [year, month, day, hour, minute]


# ===================================
func DegRange(x)
    while x < 0
        x = x + 360
    end
    while x >= 360
        x = x - 360
    end
    return x
end

# =================================
func NormalizeSeparation(jd_a,jd_b)
    sep = fabs(DegRange(jd_a - jd_b))
    if sep > 180
        sep = 360 - sep
    ok
    return sep
ok

# =================================
# ---------- Time / Calendar ----------
func JulianDay(y,m,jd_d)
    yy = y
    mm = m
    if mm <= 2
        yy = yy - 1
        mm = mm + 12
    ok
    jd_alpha = floor(yy/100)
    jd_beta = 2 - jd_alpha + floor(jd_alpha/4)
    jd = floor(365.25*(yy + 4716)) + floor(30.6001*(mm + 1)) + jd_d + jd_beta - 1524.5
    return jd
ok

# =================================
func CalendarDate(jd)
    jd_zval = floor(jd + 0.5)
    ecl_farg = (jd + 0.5) - jd_zval
    if jd_zval < 2299161
        jd_alpha = jd_zval
    else
        alpha = floor((jd_zval - 1867216.25)/36524.25)
        jd_alpha = jd_zval + 1 + alpha - floor(alpha/4)
    ok
    jd_beta = jd_alpha + 1524
    jd_cent = floor((jd_beta - 122.1)/365.25)
    jd_delta = floor(365.25 * jd_cent)
    ecl_ecc = floor((jd_beta - jd_delta)/30.6001)
    dayf = jd_beta - jd_delta - floor(30.6001*ecl_ecc) + ecl_farg
    
    if ecl_ecc < 14
        month = ecl_ecc - 1
    else
        month = ecl_ecc - 13
    ok
    if month > 2
        year = jd_cent - 4716
    else
        year = jd_cent - 4715
    ok

    dayInt  = floor(dayf)
    hourf   = (dayf - dayInt) * 24
    hour    = floor(hourf)
    minutef = (hourf - hour) * 60
    minute  = floor(minutef)
    second  = floor((minutef - minute) * 60 + 0.5)

    smonth  = right("0" + string(month), 2)
    sday    = right("0" + string(dayInt), 2)
    shour   = right("0" + string(hour), 2)
    sminute = right("0" + string(minute), 2)
    ssecond = right("0" + string(second), 2)

    return string(year) + "-" + smonth + "-" + sday + " " + shour + ":" + sminute + ":" + ssecond
ok

# =================================
# ---------- Solar & Lunar (approx) ----------
func SunLongitude(jd)
    ecl_tau  = (jd - 2451545.0)/36525.0
    L0 = 280.46646 + 36000.76983*ecl_tau + 0.0003032*ecl_tau*ecl_tau
    ecl_manom  = 357.52911 + 35999.05029*ecl_tau - 0.0001537*ecl_tau*ecl_tau
    L0 = DegRange(L0)
    ecl_manom  = DegRange(ecl_manom)
    jd_cent  = (1.914602 - 0.004817*ecl_tau - 0.000014*ecl_tau*ecl_tau)*sin(ecl_manom*RAD) +
         (0.019993 - 0.000101*ecl_tau)*sin(2*ecl_manom*RAD) +
         0.000289*sin(3*ecl_manom*RAD)
    lon = L0 + jd_cent
    return DegRange(lon)

# =================================
func MoonLongitude(jd)
    ecl_tau  = (jd - 2451545.0)/36525.0
    L0 = 218.3164477 + 481267.88123421*ecl_tau - 0.0015786*ecl_tau*ecl_tau
    ecl_manom  = 134.9633964 + 477198.8675055*ecl_tau + 0.0087414*ecl_tau*ecl_tau
    jd_delta  = 297.8501921 + 445267.1114034*ecl_tau - 0.0018819*ecl_tau*ecl_tau
    lon = L0 + 6.289 * sin(ecl_manom*RAD) +
                 -1.274 * sin((2*jd_delta - ecl_manom) * RAD) +
                  0.658 * sin(2*jd_delta * RAD) +
                  0.214 * sin(2*ecl_manom * RAD) +
                 -0.11  * sin(jd_delta * RAD)
    return DegRange(lon)

# =================================
func MoonNodeLongitude(jd)
    ecl_tau = (jd - 2451545.0)/36525.0
    ecl_node = 125.04452 - 1934.136261*ecl_tau + 0.0020708*ecl_tau*ecl_tau
    return DegRange(ecl_node)

# =================================
func MoonDistanceEarthRadii(jd)
    ecl_tau   = (jd - 2451545.0)/36525.0
    M_m = 134.9633964 + 477198.8675055*ecl_tau + 0.0087414*ecl_tau*ecl_tau
    ecc = 0.0549
    jd_a   = MEAN_MOON_DIST_ER
    bsect_r   = jd_a * (1 - ecc * cos(M_m * RAD))
    return bsect_r

# =================================
func MoonDistanceKm(jd)
    return MoonDistanceEarthRadii(jd) * EARTH_RADIUS_KM

# =================================
func SunMoonSignedDiffDeg(jd)
    sun  = SunLongitude(jd)
    moon = MoonLongitude(jd)
    diff = DegRange(moon - sun)
    if diff > 180
        diff = diff - 360
    ok
    val = diff - 180
    if val < -180
        val = val + 360
    ok
    if val > 180
        val = val - 360
    ok
    return val
ok

# =================================
func IsOppositionDeg(jd)
    return fabs(SunMoonSignedDiffDeg(jd))

# =================================
# ---------- Refinement routines ----------
func RefineFullMoonBisection(initialJD)
    left   = initialJD - 2.0
    right  = initialJD + 2.0
    fLeft  = SunMoonSignedDiffDeg(left)
    fRight = SunMoonSignedDiffDeg(right)

    tries  = 0
    while fLeft * fRight > 0 and tries < 20
        left   = left - 1.0
        right  = right + 1.0
        fLeft  = SunMoonSignedDiffDeg(left)
        fRight = SunMoonSignedDiffDeg(right)
        tries  = tries + 1
    end

    if fLeft * fRight > 0
        bsect_l = initialJD - 2.0
        bsect_r = initialJD + 2.0
        iter = 0
        while (bsect_r - bsect_l) > 0.00001 and iter < 80
            c1 = bsect_l + (bsect_r - bsect_l) * 0.382
            c2 = bsect_l + (bsect_r - bsect_l) * 0.618
            if IsOppositionDeg(c1) < IsOppositionDeg(c2)
                bsect_r = c2
            else
                bsect_l = c1
            ok
            iter = iter + 1
        end
        return (bsect_l + bsect_r) / 2.0
    ok

    tol = 0.00001
    iter = 0
    while (right - left) > tol and iter < 100
        mid  = (left + right) / 2.0
        fmid = SunMoonSignedDiffDeg(mid)
        
        if fLeft * fmid <= 0
            right  = mid
            fRight = fmid
        else
            left = mid
            fLeft = fmid
        ok
        iter = iter + 1
    end
    return (left + right) / 2.0

# =================================
func MoonLatitudeDeg(jd)
    moonLon = MoonLongitude(jd)
    nodeLon = MoonNodeLongitude(jd)
    along   = DegRange(moonLon - nodeLon)
    if along > 180
        along = along - 360
    ok
    return MOON_INCLINATION_DEG * sin(along * RAD)

# =================================
# ---------- Meeus mean-phase initial estimate for full moon ----------
func fullMoon(year, month)
    ecl_year  = (year + (month - 0.5) / 12.0) - 2000.0
    fm_k  = floor(ecl_year * 12.3685)
    kp = fm_k + 0.5
    ecl_tau  = kp / 1236.85
    jde = 2451550.09765 + 29.530588853 * kp + 0.0001337 * ecl_tau * ecl_tau - 0.000000150 * ecl_tau * ecl_tau * ecl_tau + 0.00000000073 * ecl_tau * ecl_tau * ecl_tau * ecl_tau
    return jde

# =================================

# --- Output CSV ---
func RefineGreatestEclipse(initialJD)
    bsect_l    = initialJD - 0.5
    bsect_r    = initialJD + 0.5
    tol  = 0.00001
    iter = 0
    while (bsect_r - bsect_l) > tol and iter < 80
        c1 = bsect_l + (bsect_r - bsect_l) * 0.382
        c2 = bsect_l + (bsect_r - bsect_l) * 0.618
        if fabs(MoonLatitudeDeg(c1)) < fabs(MoonLatitudeDeg(c2))
            bsect_r = c2
        else
            bsect_l = c1
        ok
        iter = iter + 1
    end
    return (bsect_l + bsect_r) / 2.0

# =========================================

