# Functions
# الدوال

### ═══════════════════════════════════════════════════════════════════════════

Func toRad(deg)
    return deg * PI / 180.0

# دالة مساعدة: تُرجع النص حسب اللغة الحالية
# الاستخدام 1: T([EN, AR, FR])
# الاستخدام 2: T(aEN, aAR, aFR, nIndex)
Func T(aArr)
    return aArr[nLang]

Func TI(aEN, aAR, aFR, nIndex)
    if nLang = 1
        return aEN[nIndex]
    but nLang = 2
        return aAR[nIndex]
    else
        return aFR[nIndex]
    ok

# تبديل اللغة: EN → AR → FR → EN
Func ToggleLanguage()
    nLang++
    if nLang > 3 { nLang = 1 }
    ApplyLanguage()

# تحديث الساعة والتاريخ من إعدادات النظام
Func UpdateClock()
    # الوقت من النظام
    cTime = time()

    # التاريخ من النظام - Ring تُرجع "DD/MM/YYYY"
    cSysDate  = date()
    nSysDay   = number(left(cSysDate, 2))
    nSysMonth = number(substr(cSysDate, 4, 2))
    nSysYear  = number(right(cSysDate, 4))

    aMonthNamesEN = ["Jan","Feb","Mar","Apr","May","Jun",
                     "Jul","Aug","Sep","Oct","Nov","Dec"]
    aMonthNamesAR = ["يناير","فبراير","مارس","أبريل","مايو","يونيو",
                     "يوليو","أغسطس","سبتمبر","أكتوبر","نوفمبر","ديسمبر"]
    aMonthNamesFR = ["Jan","Fév","Mar","Avr","Mai","Jun",
                     "Jul","Aoû","Sep","Oct","Nov","Déc"]

    if nLang = 1
        cMonthN = aMonthNamesEN[nSysMonth]
    but nLang = 2
        cMonthN = aMonthNamesAR[nSysMonth]
    else
        cMonthN = aMonthNamesFR[nSysMonth]
    ok

    cDateStr = string(nSysDay) + " " + cMonthN + " " + string(nSysYear)
    lblClock.setText(cTime + "   " + cDateStr)

# تحديث الموقع الجغرافي من إدخال المستخدم
Func UpdateLocation()
    cCityName = txtLocation.text()
    
    # التحقق من صحة الإحداثيات
    if nLatitude < -90 or nLatitude > 90
        nLatitude = 27.87  # القيمة الافتراضية
    ok
    if nLongitude < -180 or nLongitude > 180
        nLongitude = -0.29  # القيمة الافتراضية
    ok
    
    cLatDir = "N"
    cLonDir = "E"
    nLat = nLatitude
    nLon = nLongitude
    if nLat < 0
        nLat = -nLat
        cLatDir = "S"
    ok
    if nLon < 0
        nLon = -nLon
        cLonDir = "W"
    ok
    lblCoords.setText("Lat: " + nLat + "° " + cLatDir + "  |  Lon: " + nLon + "° " + cLonDir)

# تطبيق اللغة على كل عناصر الواجهة
Func ApplyLanguage()
    win.setWindowTitle(T(LANG_TITLE))
    btnLang.setText(T(LANG_LANG_BTN))

    # عناوين الأقسام الثابتة
    lblTitlePanel.setText(T(LANG_CONTROL))
    lblDateInfo.setText(T(LANG_DATE_INFO))
    lblOrbitInfo.setText(T(LANG_ORBIT_INFO_H))
    lblMoonPhaseHd.setText(T(LANG_MOON_PHASE_H))
    lblSelSeason.setText(T(LANG_SEL_SEASON_H))
    lblNavigation.setText(T(LANG_NAV_H))
    lblControls.setText(T(LANG_CONTROLS_H))

    # أزرار التنقل
    btnPrevDay.setText(T(LANG_PREV_DAY))
    btnNextDay.setText(T(LANG_NEXT_DAY))
    btnPrevMonth.setText(T(LANG_PREV_MONTH))
    btnNextMonth.setText(T(LANG_NEXT_MONTH))

    # أزرار التحكم
    if bPaused
        btnPause.setText(T(LANG_RESUME))
    else
        btnPause.setText(T(LANG_PAUSE))
    ok
    btnReset.setText(T(LANG_RESET))

    if bShowDayNight
        btnDayNight.setText(T(LANG_DAY_NIGHT_ON))
    else
        btnDayNight.setText(T(LANG_DAY_NIGHT_OFF))
    ok

    if bShowOrbitInfo
        btnOrbitInfo.setText(T(LANG_ORBIT_ON))
    else
        btnOrbitInfo.setText(T(LANG_ORBIT_OFF))
    ok

    if nMoonSpeedFactor = 0.1
        btnMoonSpeed.setText(T(LANG_MOON_SLOW))
    but nMoonSpeedFactor = 0.5
        btnMoonSpeed.setText(T(LANG_MOON_MED))
    else
        btnMoonSpeed.setText(T(LANG_MOON_FAST))
    ok

    btnSpeed.setText(T(LANG_SPEED) + ": " + nSpeed + "x")

    # تحديث ComboBox الفصول
    cbSeason.clear()
    if nLang = 1
        cbSeason.addItem(SEASONS_EN[1], null)
        cbSeason.addItem(SEASONS_EN[2], null)
        cbSeason.addItem(SEASONS_EN[3], null)
        cbSeason.addItem(SEASONS_EN[4], null)
    but nLang = 2
        cbSeason.addItem(SEASONS_AR[1], null)
        cbSeason.addItem(SEASONS_AR[2], null)
        cbSeason.addItem(SEASONS_AR[3], null)
        cbSeason.addItem(SEASONS_AR[4], null)
    else
        cbSeason.addItem(SEASONS_FR[1], null)
        cbSeason.addItem(SEASONS_FR[2], null)
        cbSeason.addItem(SEASONS_FR[3], null)
        cbSeason.addItem(SEASONS_FR[4], null)
    ok
    cbSeason.setCurrentIndex(GetSeason(nDay) - 1)

    UpdateControlPanel()
    DrawScene()

# Calculate current season from day number
Func GetSeason(nDayNum)
    if nDayNum >= 355 or nDayNum < 80
        return SEASON_WINTER
    but nDayNum >= 80 and nDayNum < 172
        return SEASON_SPRING
    but nDayNum >= 172 and nDayNum < 264
        return SEASON_SUMMER
    else
        return SEASON_AUTUMN
    ok

# Get month from day number
Func GetMonth(nDayNum)
    nMonth = 1
    nDays = 0
    for i = 1 to 12
        if nDayNum <= nDays + MONTH_DAYS[i]
            nMonth = i
            exit
        ok
        nDays += MONTH_DAYS[i]
    next
    return nMonth

# Get day of month from day number
Func GetDayOfMonth(nDayNum)
    nMonth = GetMonth(nDayNum)
    nDays = 0
    for i = 1 to nMonth - 1
        nDays += MONTH_DAYS[i]
    next
    return nDayNum - nDays

# Update control panel labels
Func UpdateControlPanel()
    nM = GetMonth(nDay)
    nDayOfMonth = GetDayOfMonth(nDay)
    nSeason = GetSeason(nDay)

    # أسماء الأشهر حسب اللغة
    if nLang = 1
        cMonthName = MONTHS_EN[nM]
    but nLang = 2
        cMonthName = MONTHS_AR[nM]
    else
        cMonthName = MONTHS_FR[nM]
    ok

    # أسماء الفصول حسب اللغة
    if nLang = 1
        cSeasonName = SEASONS_EN[nSeason]
    but nLang = 2
        cSeasonName = SEASONS_AR[nSeason]
    else
        cSeasonName = SEASONS_FR[nSeason]
    ok

    lblDay.setText(T(LANG_DAY) + ": " + nDayOfMonth)
    lblMonth.setText(T(LANG_MONTH) + ": " + cMonthName)
    lblYear.setText(T(LANG_YEAR) + ": " + nYear)
    lblSeason.setText(T(LANG_SEASON_LBL) + ": " + cSeasonName)
    lblSunOrbit.setText(T(LANG_SUN_ORBIT) + ": " + nSunOrbit)
    lblMoonOrbit.setText(T(LANG_MOON_ORBIT) + ": " + nMoonOrbit)
    cbSeason.setCurrentIndex(nSeason - 1)

    CalculateMoonPhase()
    UpdateMoonPhaseLabels()

# Pause/Resume animation
Func TogglePause()
    bPaused = not bPaused
    if bPaused
        btnPause.setText(T(LANG_RESUME))
    else
        btnPause.setText(T(LANG_PAUSE))
    ok

# Reset to today's date
Func ResetToDay1()
    nDay       = 79
    nYear      = 2026
    nSunAngle  = (79.0 / 365.0) * 360.0
    nMoonAngle = 60.0
    nSpeed     = 0.25
    bPaused    = False
    btnPause.setText(T(LANG_PAUSE))
    btnSpeed.setText(T(LANG_SPEED) + ": " + nSpeed + "x")
    CalculatePositions()
    DrawScene()
    UpdateControlPanel()

# Toggle animation speed
Func ToggleSpeed()
    # السرعات: 0.1 → 0.25 → 0.5 → 1 → 2 → 5
    if nSpeed = 0.1
        nSpeed = 0.25
    but nSpeed = 0.25
        nSpeed = 0.5
    but nSpeed = 0.5
        nSpeed = 1
    but nSpeed = 1
        nSpeed = 2
    but nSpeed = 2
        nSpeed = 5
    else
        nSpeed = 0.1
    ok
    btnSpeed.setText(T(LANG_SPEED) + ": " + nSpeed + "x")

# Toggle day/night motion
Func ToggleDayNight()
    bShowDayNight = not bShowDayNight
    if bShowDayNight
        btnDayNight.setText(T(LANG_DAY_NIGHT_ON))
        btnDayNight.setStyleSheet("background-color: #2a5a2a; color: #ffffff;")
    else
        btnDayNight.setText(T(LANG_DAY_NIGHT_OFF))
        btnDayNight.setStyleSheet("background-color: #5a2a2a; color: #ffffff;")
    ok
    DrawScene()

# Toggle orbit information
Func ToggleOrbitInfo()
    bShowOrbitInfo = not bShowOrbitInfo
    if bShowOrbitInfo
        btnOrbitInfo.setText(T(LANG_ORBIT_ON))
        btnOrbitInfo.setStyleSheet("background-color: #2a5a2a; color: #ffffff;")
        lblSunOrbit.show()
        lblMoonOrbit.show()
    else
        btnOrbitInfo.setText(T(LANG_ORBIT_OFF))
        btnOrbitInfo.setStyleSheet("background-color: #5a2a2a; color: #ffffff;")
        lblSunOrbit.hide()
        lblMoonOrbit.hide()
    ok

# Toggle moon speed
Func ToggleMoonSpeed()
    if nMoonSpeedFactor = 0.1
        nMoonSpeedFactor = 0.5
        btnMoonSpeed.setText(T(LANG_MOON_MED))
        btnMoonSpeed.setStyleSheet("background-color: #5a5a2a; color: #ffffff;")
    but nMoonSpeedFactor = 0.5
        nMoonSpeedFactor = 1.0
        btnMoonSpeed.setText(T(LANG_MOON_FAST))
        btnMoonSpeed.setStyleSheet("background-color: #5a2a2a; color: #ffffff;")
    else
        nMoonSpeedFactor = 0.1
        btnMoonSpeed.setText(T(LANG_MOON_SLOW))
        btnMoonSpeed.setStyleSheet("background-color: #5a5a2a; color: #ffffff;")
    ok

# Calculate moon phase from hijri day
Func CalculateMoonPhase()
    # نحسب المرحلة من اليوم الهجري مباشرة
    # اليوم 1 = محاق (0%), اليوم 15 = بدر (50%), اليوم 29/30 = محاق (100%)
    aDate  = GetFullGregorianDate()
    jdn    = GregorianToJDN(aDate[1], aDate[2], aDate[3])
    aHijri = JDNToHijri(jdn)
    hDay   = aHijri[1]
    # تحويل اليوم الهجري (1-30) إلى نسبة مئوية (0-100)
    nMoonPhase = ((hDay - 1) / 29.5) * 100.0
    if nMoonPhase > 100 { nMoonPhase = 100 }

# ═══════════════════════════════════════════════════════════
# تحويل التاريخ الميلادي إلى هجري بدقة
# نقطة المرجع: 20 مارس 2026 = 1 رمضان 1447
# Julian Day Number لـ 20 مارس 2026 = 2461120
# ═══════════════════════════════════════════════════════════

# دالة مساعدة للقسمة الصحيحة
Func idiv(a, b)
    return floor(a / b)

# حساب Julian Day Number من تاريخ ميلادي
Func GregorianToJDN(gDay, gMonth, gYear)
    a   = idiv(14 - gMonth, 12)
    y   = gYear + 4800 - a
    m   = gMonth + 12 * a - 3
    jdn = gDay + idiv(153*m + 2, 5) + 365*y + idiv(y, 4) - idiv(y, 100) + idiv(y, 400) - 32045
    return jdn

# تحويل Julian Day Number إلى تاريخ هجري
Func JDNToHijri(jdn)
    l      = jdn - 1948440 + 10632
    n      = idiv(l - 1, 10631)
    l      = l - 10631 * n + 354
    j1     = idiv(10985 - l, 5316) * idiv(50*l, 17719)
    j2     = idiv(l, 5670) * idiv(43*l, 15238)
    j      = j1 + j2
    l      = l - idiv(30 - j, 15) * idiv(17719*j, 50) - idiv(j, 16) * idiv(15238*j, 43) + 29
    hMonth = idiv(24*l, 709)
    hDay   = l - idiv(709 * hMonth, 24)
    hYear  = 30 * n + j - 30
    return [hDay, hMonth, hYear]

# الحصول على التاريخ الميلادي الكامل من nDay و nYear
Func GetFullGregorianDate()
    nM = GetMonth(nDay)
    nD = GetDayOfMonth(nDay)
    return [nD, nM, nYear]

# تحديث labels التاريخ الهجري والمرحلة القمرية
Func UpdateMoonPhaseLabels()
    cPhaseName = GetMoonPhaseName(nMoonPhase)

    aDate  = GetFullGregorianDate()
    gDay   = aDate[1]
    gMonth = aDate[2]
    gYear  = aDate[3]

    jdn    = GregorianToJDN(gDay, gMonth, gYear)
    aHijri = JDNToHijri(jdn)
    hDay   = aHijri[1]
    hMonth = aHijri[2]
    hYear  = aHijri[3]

    # اسم الشهر الهجري حسب اللغة
    if nLang = 1
        cLunarMonth = LUNAR_MONTHS_EN[hMonth]
    but nLang = 2
        cLunarMonth = LUNAR_MONTHS_AR[hMonth]
    else
        cLunarMonth = LUNAR_MONTHS_FR[hMonth]
    ok

    nMoonDay = hDay

    lblMoonPhase.setText(T(LANG_PHASE) + ": " + cPhaseName)
    lblMoonDay.setText(T(LANG_LUNAR_DAY) + ": " + string(hDay))
    lblLunarMonth.setText(T(LANG_LUNAR_DATE) + ": " + string(hDay) + " " + cLunarMonth + " " + string(hYear) + " H")

# Get moon phase name from phase value
Func GetMoonPhaseName(nPhase)
    if nPhase < 5 or nPhase > 95
        return T(PHASE_NEW)
    but nPhase < 20
        return T(PHASE_WAX_CRES)
    but nPhase < 45
        return T(PHASE_FIRST_Q)
    but nPhase < 55
        return T(PHASE_FULL)
    but nPhase < 80
        return T(PHASE_LAST_Q)
    else
        return T(PHASE_WAN_CRES)
    ok

# رسم القمر بمراحله الواقعية
Func DrawMoonPhase(nX, nY, nPhase)
    nR = 22

    # جسم القمر الأساسي
    daVinci.setPen(new qPen() { setColor(new qColor() { setRgb(170,170,155,255) }) setWidth(1) })
    daVinci.setBrush(new qBrush() { setStyle(1) setColor(new qColor() { setRgb(218,218,200,255) }) })
    daVinci.drawEllipse(nX-nR, nY-nR, nR*2, nR*2)

    # تضاريس
    daVinci.setPen(penNone)
    daVinci.setBrush(new qBrush() { setStyle(1) setColor(new qColor() { setRgb(155,155,140,160) }) })
    daVinci.drawEllipse(nX-8, nY-10, 14, 12)
    daVinci.setBrush(new qBrush() { setStyle(1) setColor(new qColor() { setRgb(165,165,148,130) }) })
    daVinci.drawEllipse(nX+4, nY+4, 10, 8)
    daVinci.setBrush(new qBrush() { setStyle(1) setColor(new qColor() { setRgb(140,140,125,180) }) })
    daVinci.drawEllipse(nX+10, nY-8, 5, 5)
    daVinci.drawEllipse(nX-4,  nY+12, 4, 4)
    daVinci.drawEllipse(nX-16, nY-6,  3, 3)

    # === ظل المرحلة ===
    # nPhase: 0=محاق → 50=بدر → 100=محاق
    # اليوم الهجري 1 → nPhase=0 (محاق)
    # اليوم 15      → nPhase=47.5 (بدر)
    # اليوم 29      → nPhase=94.9 (محاق)

    daVinci.setPen(penNone)
    cSh = new qColor() { setRgb(5, 5, 20, 225) }
    bSh = new qBrush() { setStyle(1) setColor(cSh) }
    daVinci.setBrush(bSh)

    # تحويل nPhase إلى زاوية دورة (0=محاق, 180=بدر, 360=محاق)
    nCycleAngle = nPhase * 3.6   # 0 → 360

    if nCycleAngle < 10 or nCycleAngle > 350
        # محاق: كامل الظلام
        daVinci.drawEllipse(nX-nR, nY-nR, nR*2, nR*2)

    but nCycleAngle < 170
        # هلال متزايد (يوم 1-14):
        # النصف الأيسر دائماً مظلم
        daVinci.drawChord(nX-nR, nY-nR, nR*2, nR*2, 90*16, 180*16)
        # الشريط الأيمن يتقلص: عند nCycleAngle=0 الشريط=nR، عند 180 الشريط=0
        nW = nR * (1.0 - nCycleAngle/180.0)
        if nW > 0.5
            daVinci.drawChord(nX-nW, nY-nR, nW*2, nR*2, 270*16, 180*16)
        ok

    but nCycleAngle < 190
        # بدر (يوم 14-16): لا ظل

    else
        # هلال متناقص (يوم 16-29):
        # النصف الأيمن دائماً مظلم
        daVinci.drawChord(nX-nR, nY-nR, nR*2, nR*2, 270*16, 180*16)
        # الشريط الأيسر يتمدد: عند nCycleAngle=180 الشريط=0، عند 360 الشريط=nR
        nW = nR * ((nCycleAngle - 180.0) / 180.0)
        if nW > 0.5
            daVinci.drawChord(nX-nW, nY-nR, nW*2, nR*2, 90*16, 180*16)
        ok
    ok

    # حافة نهائية
    daVinci.setPen(new qPen() { setColor(new qColor() { setRgb(190,190,175,255) }) setWidth(1) })
    daVinci.setBrush(brushEmpty)
    daVinci.drawEllipse(nX-nR, nY-nR, nR*2, nR*2)

# Go to previous day
Func PrevDay()
    nDay -= 1
    if nDay < 1
        nDay = 365
        nYear -= 1
    ok
    nSunAngle = (nDay - 1.0) / 365.0 * 360.0
    CalculatePositions()
    DrawScene()
    UpdateControlPanel()

# Go to next day
Func NextDay()
    nDay += 1
    if nDay > 365
        nDay = 1
        nYear += 1
    ok
    nSunAngle = (nDay - 1.0) / 365.0 * 360.0
    CalculatePositions()
    DrawScene()
    UpdateControlPanel()

# Go to previous month
Func PrevMonth()
    nM = GetMonth(nDay)
    if nM = 1
        nDay = 335
        nYear -= 1
    else
        nDay -= MONTH_DAYS[nM - 1]
    ok
    if nDay < 1
        nDay = 1
    ok
    nSunAngle = (nDay - 1.0) / 365.0 * 360.0
    CalculatePositions()
    DrawScene()
    UpdateControlPanel()

# Go to next month
Func NextMonth()
    nM = GetMonth(nDay)
    if nM = 12
        nDay = 31
        nYear += 1
    else
        nDay += MONTH_DAYS[nM]
    ok
    if nDay > 365
        nDay = 365
    ok
    nSunAngle = (nDay - 1.0) / 365.0 * 360.0
    CalculatePositions()
    DrawScene()
    UpdateControlPanel()

# Set season from combo box
Func SetSeason(nIndex)
    nNewSeason = nIndex + 1
    if nNewSeason = SEASON_WINTER
        nDay = 1
    but nNewSeason = SEASON_SPRING
        nDay = 80
    but nNewSeason = SEASON_SUMMER
        nDay = 172
    else
        nDay = 264
    ok
    nSunAngle = (nDay - 1.0) / 365.0 * 360.0
    CalculatePositions()
    DrawScene()
    UpdateControlPanel()

Func CalculatePositions()
    nSunOrbit = SUN_ORBIT + 30 * sin(toRad((nDay - 172) * 360 / 365))
    nMoonOrbit = MOON_ORBIT + 20 * sin(toRad(nMoonAngle))

Func DrawScene()
    # End any previous painting session
    daVinci.endpaint()
    # Start new painting session
    daVinci.begin(MonaLisa)
    
    daVinci.setPen(penNone)
    daVinci.setBrush(new qBrush() { setStyle(1) setColor(colorBg) })
    daVinci.drawRect(0, 0, W, H)

    daVinci.setPen(penWhite)
    nLen = len(aStars)
    for i = 1 to nLen
        daVinci.drawPoint(aStars[i][1], aStars[i][2])
    next

    daVinci.setPen(penAntEdge)
    daVinci.setBrush(brushAntarct)
    daVinci.drawEllipse(CX-ER, CY-ER, ER*2, ER*2)

    nOR = ER - 22
    daVinci.setPen(penOcean)
    daVinci.setBrush(brushOcean)
    daVinci.drawEllipse(CX-nOR, CY-nOR, nOR*2, nOR*2)

    daVinci.setPen(penLand)
    daVinci.setBrush(brushLand)
    daVinci.drawEllipse(CX+28,  CY+8,   80, 112)
    daVinci.drawEllipse(CX+20,  CY-80,  64,  60)
    daVinci.drawEllipse(CX+68,  CY-100, 122, 90)
    daVinci.drawEllipse(CX-192, CY-92,  112, 102)
    daVinci.drawEllipse(CX-142, CY+38,  75,  112)
    daVinci.drawEllipse(CX+118, CY+68,  80,  62)

    daVinci.setPen(penGreenland)
    daVinci.setBrush(brushGreenland)
    daVinci.drawEllipse(CX-62, CY-140, 60, 72)

    daVinci.setPen(penArctic)
    daVinci.setBrush(brushArctic)
    daVinci.drawEllipse(CX-42, CY-42, 84, 84)

    daVinci.setPen(penNPole)
    daVinci.setBrush(brushNPole)
    daVinci.drawEllipse(CX-5, CY-5, 10, 10)

    nSX = CX + nSunOrbit * cos(toRad(nSunAngle))
    nSY = CY + nSunOrbit * sin(toRad(nSunAngle))

    # === منطقة الليل والنهار الواقعية ===
    if bShowDayNight
        daVinci.setPen(penNone)

        nOR = ER - 22

        # زاوية الشمس من مركز الأرض بالدرجات (Qt تقيس عكس عقارب الساعة)
        # في Ring/Qt: cos يُعطي الاتجاه الأفقي، sin يُعطي العمودي
        # زاوية الظل = عكس زاوية الشمس + 180
        # drawChord: startAngle و spanAngle بوحدة 1/16 درجة
        # startAngle = زاوية البداية من اليمين عكس عقارب الساعة
        # لكن Qt تعكس المحور Y لذا نعكس الإشارة

        nShadeStart = (-nSunAngle + 180 - 90) * 16
        
        # طبقة 1: الفجر/الغسق (أخف تعتيم - أوسع زاوية)
        c = new qColor() { setRgb(0, 5, 30, 30) }
        b = new qBrush() { setStyle(1) setColor(c) }
        daVinci.setBrush(b)
        daVinci.drawChord(CX-nOR, CY-nOR, nOR*2, nOR*2,
            nShadeStart - 20*16, 220 * 16)

        # طبقة 2
        c = new qColor() { setRgb(0, 3, 25, 60) }
        b = new qBrush() { setStyle(1) setColor(c) }
        daVinci.setBrush(b)
        daVinci.drawChord(CX-nOR, CY-nOR, nOR*2, nOR*2,
            nShadeStart - 10*16, 200 * 16)

        # طبقة 3: نصف الأرض بالضبط
        c = new qColor() { setRgb(0, 2, 20, 90) }
        b = new qBrush() { setStyle(1) setColor(c) }
        daVinci.setBrush(b)
        daVinci.drawChord(CX-nOR, CY-nOR, nOR*2, nOR*2,
            nShadeStart, 180 * 16)

        # طبقة 4: ظلام أعمق
        c = new qColor() { setRgb(0, 0, 15, 120) }
        b = new qBrush() { setStyle(1) setColor(c) }
        daVinci.setBrush(b)
        daVinci.drawChord(CX-nOR, CY-nOR, nOR*2, nOR*2,
            nShadeStart + 20*16, 140 * 16)

        # طبقة 5: وسط الليل
        c = new qColor() { setRgb(0, 0, 10, 150) }
        b = new qBrush() { setStyle(1) setColor(c) }
        daVinci.setBrush(b)
        daVinci.drawChord(CX-nOR, CY-nOR, nOR*2, nOR*2,
            nShadeStart + 45*16, 90 * 16)

        # هالة النهار من جهة الشمس
        c = new qColor() { setRgb(255, 240, 160, 22) }
        b = new qBrush() { setStyle(1) setColor(c) }
        daVinci.setBrush(b)
        daVinci.drawEllipse(nSX - 150, nSY - 150, 300, 300)

        c = new qColor() { setRgb(255, 245, 180, 32) }
        b = new qBrush() { setStyle(1) setColor(c) }
        daVinci.setBrush(b)
        daVinci.drawEllipse(nSX - 90, nSY - 90, 180, 180)

    ok

    daVinci.setBrush(brushEmpty)
    daVinci.setPen(penOrbitSun)
    daVinci.drawEllipse(CX-nSunOrbit, CY-nSunOrbit, nSunOrbit*2, nSunOrbit*2)
    daVinci.setPen(penOrbitMoon)
    daVinci.drawEllipse(CX-nMoonOrbit, CY-nMoonOrbit, nMoonOrbit*2, nMoonOrbit*2)

    nMX = CX + nMoonOrbit * cos(toRad(nMoonAngle))
    nMY = CY + nMoonOrbit * sin(toRad(nMoonAngle))

    # Check for eclipse alignment
    nAngleDiff = fabs(nSunAngle - nMoonAngle)
    if nAngleDiff < 5 or nAngleDiff > 355
        # Eclipse effect - draw dark halo
        daVinci.setPen(penNone)
        eclipseBrush = new qBrush()
        eclipseBrush.setStyle(1)
        eclipseBrushColor = new qColor() { setRgb(50, 0, 50, 150) }
        eclipseBrush.setColor(eclipseBrushColor)
        daVinci.setBrush(eclipseBrush)
        daVinci.drawEllipse(CX-200, CY-200, 400, 400)
        
        # Draw eclipse text
        eclipseFont = new qFont("DejaVu Sans", 18, 75, True)
        daVinci.setFont(eclipseFont)
        
        eclipsePen = new qPen()
        eclipsePenColor = new qColor() { setRgb(255, 200, 50, 255) }
        eclipsePen.setColor(eclipsePenColor)
        eclipsePen.setWidth(2)
        daVinci.setPen(eclipsePen)
        aEclipse = ["ECLIPSE!", "كسوف!", "ÉCLIPSE!"]
        daVinci.drawText(CX-80, CY-250, aEclipse[nLang])
    ok

    daVinci.setPen(penNone)
    daVinci.setBrush(brushMoonGlow)
    daVinci.drawEllipse(nMX-30, nMY-30, 60, 60)

    # رسم القمر بمرحلته الواقعية
    DrawMoonPhase(nMX, nMY, nMoonPhase)

    daVinci.setPen(penNone)
    daVinci.setBrush(brushSunGlow1)
    daVinci.drawEllipse(nSX-42, nSY-42, 84, 84)
    daVinci.setBrush(brushSunGlow2)
    daVinci.drawEllipse(nSX-26, nSY-26, 52, 52)

    daVinci.setPen(penSunEdge)
    daVinci.setBrush(brushSunBody)
    daVinci.drawEllipse(nSX-17, nSY-17, 34, 34)

    daVinci.setPen(penSunRay)
    for i = 0 to 7
        nA  = toRad(i * 45 + nSunAngle * 0.5)
        nX1 = nSX + 20 * cos(nA)
        nY1 = nSY + 20 * sin(nA)
        nX2 = nSX + 46 * cos(nA)
        nY2 = nSY + 46 * sin(nA)
        daVinci.drawLine(nX1, nY1, nX2, nY2)
    next

    daVinci.setFont(fontLabel)
    daVinci.setPen(penSunLbl)
    daVinci.drawText(nSX-12, nSY+36, TI(MAP_LABELS_EN, MAP_LABELS_AR, MAP_LABELS_FR, 10))

    daVinci.drawText(nMX-14, nMY+32, TI(MAP_LABELS_EN, MAP_LABELS_AR, MAP_LABELS_FR, 11))

    daVinci.setFont(fontLabel)
    daVinci.setPen(penNPoleLbl)
    daVinci.drawText(CX+8, CY+5, TI(MAP_LABELS_EN, MAP_LABELS_AR, MAP_LABELS_FR, 1))

    daVinci.setPen(penAntLbl)
    daVinci.drawText(CX-ER+5, CY-ER+15, TI(MAP_LABELS_EN, MAP_LABELS_AR, MAP_LABELS_FR, 2))

    daVinci.setPen(penContLbl)
    daVinci.drawText(CX+42,  CY+62,  TI(MAP_LABELS_EN, MAP_LABELS_AR, MAP_LABELS_FR, 3))
    daVinci.drawText(CX+32,  CY-52,  TI(MAP_LABELS_EN, MAP_LABELS_AR, MAP_LABELS_FR, 4))
    daVinci.drawText(CX+88,  CY-58,  TI(MAP_LABELS_EN, MAP_LABELS_AR, MAP_LABELS_FR, 5))
    daVinci.drawText(CX-168, CY-42,  TI(MAP_LABELS_EN, MAP_LABELS_AR, MAP_LABELS_FR, 6))
    daVinci.drawText(CX-118, CY+92,  TI(MAP_LABELS_EN, MAP_LABELS_AR, MAP_LABELS_FR, 7))
    daVinci.drawText(CX+138, CY+98,  TI(MAP_LABELS_EN, MAP_LABELS_AR, MAP_LABELS_FR, 8))
    daVinci.drawText(CX-52,  CY-108, TI(MAP_LABELS_EN, MAP_LABELS_AR, MAP_LABELS_FR, 9))

    daVinci.setFont(fontTitle)
    daVinci.setPen(penTitleTxt)
    daVinci.drawText(CX-180, CY+ER+28, TI(FOOTER_EN, FOOTER_AR, FOOTER_FR, 1))

    daVinci.setFont(fontSub)
    daVinci.setPen(penSubTxt)
    daVinci.drawText(CX-180, CY+ER+48, TI(FOOTER_EN, FOOTER_AR, FOOTER_FR, 2))

    daVinci.endpaint()
    Canvas.setPixMap(MonaLisa)
    myApp.processEvents()

Func animate()
    nCurW = win.width()
    nCurH = win.height()
    if nCurW != nLastWinW or nCurH != nLastWinH
        nLastWinW = nCurW
        nLastWinH = nCurH
        ResizeLayout()
    ok

    # تحديث الساعة دائماً حتى عند الإيقاف
    UpdateClock()

    if not bPaused
        nSunAngle += (360.0 / 365.0) * nSpeed

        # عند اكتمال دورة شمسية → سنة جديدة
        if nSunAngle >= 360
            nSunAngle -= 360
            nYear += 1
        ok
        if nSunAngle < 0
            nSunAngle += 360
            nYear -= 1
        ok

        # احسب nDay من nSunAngle مباشرة (1-365)
        nDay = floor(nSunAngle / 360.0 * 365.0) + 1
        if nDay < 1   { nDay = 1   }
        if nDay > 365 { nDay = 365 }

        nMoonAngle += (360.0 / 29.5) * nMoonSpeedFactor * nSpeed
        if nMoonAngle >= 360 { nMoonAngle -= 360 }
        if nMoonAngle < 0    { nMoonAngle += 360 }

        CalculatePositions()
        DrawScene()
        UpdateControlPanel()
    ok

Func ResizeLayout()
    # الحصول على حجم النافذة الحالي
    nWinW = win.width()
    nWinH = win.height()

    # عرض لوحة التحكم ثابت = 300
    nPanelW = 300

    # حجم Canvas = باقي العرض × كامل الارتفاع
    nCanvasW = nWinW - nPanelW
    nCanvasH = nWinH

    # تحديث Canvas
    Canvas.setGeometry(0, 0, nCanvasW, nCanvasH)

    # تحديث ControlPanel
    ControlPanel.setGeometry(nCanvasW, 0, nPanelW, nWinH)

    # تحديث ثوابت الرسم
    W  = nCanvasW
    H  = nCanvasH
    CX = nCanvasW / 2
    CY = nCanvasH / 2

    # نصف قطر الأرض = 90% من نصف أصغر بُعد
    nMinDim = nCanvasW
    if nCanvasH < nCanvasW { nMinDim = nCanvasH }
    ER = (nMinDim / 2) * 0.90

    # إعادة بناء الـ pixmap بالحجم الجديد
    daVinci.endpaint()
    MonaLisa = new qPixMap2(nCanvasW, nCanvasH)
    daVinci  = new qPainter()
    daVinci.begin(MonaLisa)
    Canvas.setPixMap(MonaLisa)

    DrawScene()
