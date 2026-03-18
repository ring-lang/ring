# Earth's Elliptical Orbit with Zodiac Signs
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

W  = 900
H  = 960
CX = 450
CY = 480

A  = 320          # semi-major (vertical)
B  = 310          # semi-minor (horizontal)
C  = sqrt(A*A - B*B)

SUN_X    = CX
SUN_Y    = CY + C     # Sun at bottom focus (perihelion side)
FOCUS2_X = CX
FOCUS2_Y = CY - C     # empty focus at top  (aphelion side)

PI = 3.14159265358979

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
myApp       = null
win         = null

todayLon    = 0       # ecliptic longitude for today (calculated below)
todayStr    = ""      # "Month Day Year" string
todayDeg    = ""      # longitude as string e.g. "356.2 deg"
todayZodiac = ""      # which zodiac sign

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
colorTick    = new qColor() { setRgb(195, 180, 238, 210) }
colorSector  = new qColor() { setRgb( 90,  90, 150,  65) }
colorEarthLb = new qColor() { setRgb(135, 190, 255, 255) }
colorSunLbl  = new qColor() { setRgb(255, 222,  90, 255) }
colorFocus   = new qColor() { setRgb(125, 115, 185, 155) }
colorTitle   = new qColor() { setRgb(220, 210, 255, 255) }
colorSub     = new qColor() { setRgb(158, 158, 202, 200) }
colorSpring  = new qColor() { setRgb(  0, 255, 100, 255) }
colorSummer  = new qColor() { setRgb(255, 215,  45, 255) }
colorAutumn  = new qColor() { setRgb(255, 135,  35, 255) }
colorWinter  = new qColor() { setRgb( 70, 195, 255, 255) }
colorPeri    = new qColor() { setRgb(255, 100, 100, 255) }
colorAph     = new qColor() { setRgb(100, 200, 255, 255) }
colorToday   = new qColor() { setRgb(255, 255,   0, 255) }  # bright yellow
colorAngle   = new qColor() { setRgb(255, 200,  50, 255) }  # amber angle line

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

### ── Fonts ──────────────────────────────────────────────────────────────────

fontGlyph  = new qFont("DejaVu Sans", 11, 75, False)
fontName   = new qFont("DejaVu Sans",  8, 50, False)
fontDate   = new qFont("DejaVu Sans",  7, 50, True)
fontLabel  = new qFont("DejaVu Sans",  9, 75, False)
fontSmall  = new qFont("DejaVu Sans",  7, 50, True)
fontAngle  = new qFont("DejaVu Sans", 10, 75, False)
fontTitle  = new qFont("DejaVu Serif",14, 75, False)
fontSub    = new qFont("DejaVu Sans",  8, 50, True)
fontToday  = new qFont("DejaVu Sans",  9, 75, False)

### ── Calculate today's ecliptic longitude ───────────────────────────────────

CalcTodayLon()

### ── qApp ───────────────────────────────────────────────────────────────────

myApp = new qApp
{
    win = new qWidget()
    {
        setWindowTitle("Earth Elliptical Orbit - Zodiac Constellations  [ " + todayStr + " ]")
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

        show()
    }

    DrawScene()

    exec()
}

### ═══════════════════════════════════════════════════════════════════════════
### CalcTodayLon
### Get today's date from Ring, convert to ecliptic longitude (deg)
### Vernal equinox = Mar 21 = day 80 = lon 0 deg
### lon increases CCW: +1 deg per day  (360/365.25)
### ═══════════════════════════════════════════════════════════════════════════

Func CalcTodayLon()

    ### Ring date() returns  "DD/MM/YYYY"
    d = date()
    aMonthName = ["Jan","Feb","Mar","Apr","May","Jun",
                  "Jul","Aug","Sep","Oct","Nov","Dec"]

    dayPart   = 0 + left(d, 2)
    monthPart = 0 + substr(d, 4, 2)
    yearPart  = 0 + right(d, 4)

    todayStr  = aMonthName[monthPart] + " " + dayPart + "  " + yearPart

    ### Day of year (1 = Jan 1)
    dayOfYear = 0
    for m = 1 to monthPart - 1
        dayOfYear += aDaysInMonth[m]
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
### LonToXY  —  ecliptic longitude -> screen (x, y) on the orbit ellipse
### ═══════════════════════════════════════════════════════════════════════════

Func LonToXY(lon)
    ang = lon * PI / 180
    x   = CX + B * cos(ang)
    y   = CY - A * sin(ang)
    return [x, y]

### ═══════════════════════════════════════════════════════════════════════════
### DrawScene
### ═══════════════════════════════════════════════════════════════════════════

Func DrawScene()

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

    ### ── Axes ────────────────────────────────────────────────────────────────
    daVinci.setPen(penMajAxis)
    daVinci.setBrush(brushEmpty)
    daVinci.drawLine(CX, CY-A-30, CX, CY+A+30)      # vertical major axis
    daVinci.drawLine(CX-B-30, CY, CX+B+30, CY)      # horizontal minor axis

    ### ── Sector lines ────────────────────────────────────────────────────────
    daVinci.setPen(penSector)
    for i = 0 to 11
        pt = LonToXY(i * 30)
        daVinci.drawLine(CX, CY, pt[1], pt[2])
    next

    ### ── Outer zodiac ring ──────────────────────────────────────────────────
    RING_R  = 415
    INNER_R = 335
    daVinci.setPen(penRingVio)
    daVinci.setBrush(brushEmpty)
    daVinci.drawEllipse(CX-RING_R,  CY-RING_R,  2*RING_R,  2*RING_R)
    daVinci.setPen(penInner)
    daVinci.drawEllipse(CX-INNER_R, CY-INNER_R, 2*INNER_R, 2*INNER_R)

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

    ### ── Orbit ellipse ───────────────────────────────────────────────────────
    daVinci.setPen(penSkyBlue)
    daVinci.setBrush(brushEmpty)
    daVinci.drawEllipse(CX-B, CY-A, 2*B, 2*A)

    ### ── Equinox / Solstice / Perihelion / Aphelion markers ─────────────────
    aSpecial = [
        [   0, "Vernal Equinox",   "Aries  Mar 21",      penSpring, brushSpring ],
        [  90, "Aphelion ~Jul 4",  "Cancer Jun 21",      penAph,    brushAph    ],
        [ 180, "Autumnal Equinox", "Libra  Sep 23",      penAutumn, brushAutumn ],
        [ 270, "Perihelion ~Jan 3","Capricorn Dec 22",   penPeri,   brushPeri   ]
    ]

    for item in aSpecial
        pt  = LonToXY(item[1])
        px  = pt[1]   py = pt[2]
        daVinci.setPen(item[4])
        daVinci.setBrush(item[5])
        daVinci.drawEllipse(px-7, py-7, 14, 14)
        daVinci.setFont(fontSmall)
        daVinci.setPen(item[4])
        ang = item[1] * PI / 180
        if cos(ang) >= 0
            daVinci.drawText(px+12,  py-2,  item[2])
            daVinci.drawText(px+12,  py+10, item[3])
        else
            daVinci.drawText(px-112, py-2,  item[2])
            daVinci.drawText(px-112, py+10, item[3])
        ok
    next

    ### ── Perihelion / Aphelion axis end labels ───────────────────────────────
    daVinci.setFont(fontSmall)
    daVinci.setPen(penPeri)
    daVinci.drawText(CX+6, CY+A+20, "Perihelion  ~Jan 3")
    daVinci.setPen(penAph)
    daVinci.drawText(CX+6, CY-A-10, "Aphelion  ~Jul 4")

    ### ── Sun at BOTTOM focus ─────────────────────────────────────────────────
    daVinci.setPen(penNone)
    for r = 34 to 14 step -4
        aS = 10 + (34-r)*4
        cCorona = new qColor() { setRgb(255, 190, 35, aS) }
        bCorona = new qBrush() { setStyle(1)  setColor(cCorona) }
        daVinci.setBrush(bCorona)
        daVinci.drawEllipse(SUN_X-r, SUN_Y-r, 2*r, 2*r)
    next
    daVinci.setPen(penSunLbl)
    daVinci.setBrush(brushGold)
    daVinci.drawEllipse(SUN_X-13, SUN_Y-13, 26, 26)
    daVinci.setFont(fontLabel)
    daVinci.setPen(penSunLbl)
    daVinci.drawText(SUN_X-10, SUN_Y+26, "Sun")

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
    ### Draw arc along inner zodiac ring showing the swept angle
    arcRad = 120     # radius of the angle arc
    penArc = new qPen() { setColor(colorAngle)  setWidth(1)  setStyle(2) }
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
    midAngRad = (todayLon / 2) * PI / 180
    lblR      = arcRad + 22
    lblX      = CX + lblR * cos(midAngRad)
    lblY      = CY - lblR * sin(midAngRad)
    daVinci.setFont(fontAngle)
    daVinci.setPen(penAngle)
    daVinci.drawText(lblX - 18, lblY + 4, todayDeg)

    ### ── "0 deg / Aries" reference tick on the angle arc ───────────────────
    penRef = new qPen() { setColor(colorSpring)  setWidth(2) }
    daVinci.setPen(penRef)
    daVinci.drawLine(CX + arcRad - 10, CY, CX + arcRad + 10, CY)

    ### ── Earth glow ─────────────────────────────────────────────────────────
    daVinci.setPen(penNone)
    for r = 26 to 8 step -3
        aG = 25 + (26-r)*10
        cGlow = new qColor() { setRgb(45, 105, 255, aG) }
        bGlow = new qBrush() { setStyle(1)  setColor(cGlow) }
        daVinci.setBrush(bGlow)
        daVinci.drawEllipse(EX-r, EY-r, 2*r, 2*r)
    next

    ### ── Earth body ─────────────────────────────────────────────────────────
    daVinci.setPen(penToday)
    daVinci.setBrush(brushBlue)
    daVinci.drawEllipse(EX-11, EY-11, 22, 22)

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

    daVinci.setPen(penAngle)
    daVinci.drawText(lx, ly + 25, todayDeg)

    daVinci.setPen(penGold)
    daVinci.drawText(lx, ly + 37, todayZodiac)

    ### ── Title ──────────────────────────────────────────────────────────────
    daVinci.setFont(fontTitle)
    daVinci.setPen(penTitle)
    daVinci.drawText(20, 30, "Earth's Elliptical Orbit  -  Zodiac Constellations")

    daVinci.setFont(fontSub)
    daVinci.setPen(penSub)
    daVinci.drawText(20, 50, "Today: " + todayStr +
        "   Lon: " + todayDeg +
        "   Sign: " + todayZodiac +
        "   |   Aries 0 deg = Mar 21 (right)  CCW")

    ### ── Finish ──────────────────────────────────────────────────────────────
    daVinci.endpaint()
    Canvas.setPixMap(MonaLisa)
    myApp.processEvents()

return
