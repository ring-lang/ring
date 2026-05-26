/*
**  cr_weather.ring - Weather System
**  Code Rooms 3D
**  6 weather types: Clear, Cloudy, Rain, Storm, Snow, Fog
*/

func w_initPositions
    for i = 1 to WS_MAX
        wsX[i] = GetRandomValue(0, SCREEN_W)
        wsY[i] = GetRandomValue(10, SCREEN_H)
    next
    for i = 1 to WF_MAX
        wfX[i] = GetRandomValue(-200, SCREEN_W + 200) * 1.0
        wfY[i] = GetRandomValue(200, SCREEN_H - 100) * 1.0
    next

func w_setWeather wtype
    currentWeather = wtype
    // Clear old clouds/drops
    for i = 1 to WC_MAX  wcActive[i] = 0  next
    wcCount = 0
    for i = 1 to WD_MAX  wdActive[i] = 0  next
    for i = 1 to WL_MAX  wlActive[i] = 0  next

    if wtype = W_CLEAR
        wWindSpeed = 5.0
        w_spawnClouds(3, 0.1)
        wDayTime = 0.35
    ok
    if wtype = W_CLOUDY
        wWindSpeed = 25.0
        w_spawnClouds(12, 0.2)
        wDayTime = 0.4
    ok
    if wtype = W_RAIN
        wWindSpeed = 50.0
        w_spawnClouds(20, 0.7)
        wDayTime = 0.38
    ok
    if wtype = W_STORM
        wWindSpeed = 100.0
        w_spawnClouds(20, 0.85)
        wDayTime = 0.32
    ok
    if wtype = W_SNOW
        wWindSpeed = 15.0
        w_spawnClouds(10, 0.3)
        wDayTime = 0.36
    ok
    if wtype = W_FOG
        wWindSpeed = 8.0
        w_spawnClouds(6, 0.3)
        wDayTime = 0.33
    ok

func w_spawnClouds count, darkness
    for c = 1 to count
        w_addCloud(GetRandomValue(0, SCREEN_W), GetRandomValue(30, 180), darkness)
    next

func w_addCloud x, y, darkness
    for i = 1 to WC_MAX
        if wcActive[i] = 0
            wcActive[i] = 1
            wcX[i] = x * 1.0
            wcY[i] = y * 1.0
            wcW[i] = GetRandomValue(100, 250) * 1.0
            wcH[i] = GetRandomValue(30, 60) * 1.0
            wcAlpha[i] = GetRandomValue(140, 220)
            wcSpeed[i] = GetRandomValue(8, 30) * 1.0
            wcDark[i] = darkness
            wcCount++
            return
        ok
    next

// =============================================================
// Weather Update
// =============================================================

func w_update dt
    if dt > 0.05 dt = 0.05 ok
    wAnimTime += dt
    wDayTime += 0.003 * dt
    if wDayTime > 1.0 wDayTime -= 1.0 ok

    // Update clouds
    for i = 1 to WC_MAX
        if wcActive[i] = 0 loop ok
        wcX[i] += (wWindSpeed * wWindDir + wcSpeed[i] * 0.3) * dt
        wcY[i] += sin(wAnimTime * 0.3 + i) * 2 * dt
        if wcX[i] > SCREEN_W + wcW[i]  wcX[i] = -wcW[i]  ok
        if wcX[i] < -wcW[i] - 100  wcX[i] = SCREEN_W + wcW[i]  ok
    next

    // Spawn rain
    if currentWeather = W_RAIN or currentWeather = W_STORM
        spawnRate = 12
        if currentWeather = W_STORM spawnRate = 22 ok
        for s = 1 to spawnRate
            for i = 1 to WD_MAX
                if wdActive[i] = 0
                    wdActive[i] = 1
                    wdX[i] = GetRandomValue(-50, SCREEN_W + 50) * 1.0
                    wdY[i] = GetRandomValue(-20, 50) * 1.0
                    wdVX[i] = wWindSpeed * wWindDir * 0.6
                    wdVY[i] = GetRandomValue(350, 550) * 1.0
                    wdSize[i] = GetRandomValue(8, 20) * 1.0
                    wdAlpha[i] = GetRandomValue(120, 200)
                    exit
                ok
            next
        next
    ok

    // Spawn snow
    if currentWeather = W_SNOW
        for s = 1 to 8
            for i = 1 to WD_MAX
                if wdActive[i] = 0
                    wdActive[i] = 1
                    wdX[i] = GetRandomValue(-20, SCREEN_W + 20) * 1.0
                    wdY[i] = GetRandomValue(-30, 10) * 1.0
                    wdVX[i] = wWindSpeed * wWindDir * 0.3 + GetRandomValue(-20, 20)
                    wdVY[i] = GetRandomValue(30, 80) * 1.0
                    wdSize[i] = GetRandomValue(15, 35) / 10.0
                    wdAlpha[i] = GetRandomValue(160, 240)
                    exit
                ok
            next
        next
    ok

    // Update drops
    for i = 1 to WD_MAX
        if wdActive[i] = 0 loop ok
        wdX[i] += wdVX[i] * dt
        wdY[i] += wdVY[i] * dt
        if currentWeather = W_SNOW
            wdX[i] += sin(wAnimTime * 2 + i * 0.5) * 15 * dt
        ok
        if wdY[i] > SCREEN_H  wdActive[i] = 0  ok
        if wdX[i] < -100 or wdX[i] > SCREEN_W + 100  wdActive[i] = 0  ok
    next

    // Lightning in storms
    if currentWeather = W_STORM
        if GetRandomValue(1, 200) = 1
            w_triggerLightning()
        ok
    ok

    // Update lightning
    for i = 1 to WL_MAX
        if wlActive[i] = 0 loop ok
        wlTimer[i] -= dt
        if wlTimer[i] <= 0  wlActive[i] = 0  ok
    next

    // Flash decay
    if wFlashAlpha > 0
        wFlashAlpha -= 400 * dt
        if wFlashAlpha < 0 wFlashAlpha = 0 ok
    ok

    // Update fog
    for i = 1 to WF_MAX
        wfX[i] += (wWindSpeed * wWindDir * 0.2 + wfSpeed[i]) * dt
        if wfX[i] > SCREEN_W + wfW[i]  wfX[i] = -wfW[i]  ok
        if wfX[i] < -wfW[i] - 100  wfX[i] = SCREEN_W + 50  ok
    next

func w_triggerLightning
    for i = 1 to WL_MAX
        if wlActive[i] = 0
            wlActive[i] = 1
            wlX[i] = GetRandomValue(100, SCREEN_W - 100) * 1.0
            wlTimer[i] = 0.3
            wlSegX[i] = []
            wlSegY[i] = []
            sx = wlX[i]
            sy = GetRandomValue(40, 100) * 1.0
            add(wlSegX[i], sx)
            add(wlSegY[i], sy)
            while sy < SCREEN_H * 0.7
                sx += GetRandomValue(-25, 25)
                sy += GetRandomValue(15, 40)
                add(wlSegX[i], sx)
                add(wlSegY[i], sy)
                if GetRandomValue(1, 5) = 1
                    bsx = sx + GetRandomValue(-40, 40)
                    bsy = sy + GetRandomValue(20, 50)
                    add(wlSegX[i], bsx)
                    add(wlSegY[i], bsy)
                    add(wlSegX[i], sx)
                    add(wlSegY[i], sy)
                ok
            end
            wFlashAlpha = 180
            return
        ok
    next

// =============================================================
// Weather Drawing
// =============================================================

func w_drawSky
    PI2 = 3.14159265
    dayBright = sin(wDayTime * PI2)
    if dayBright < 0 dayBright = 0 ok

    darkFactor = 1.0
    if currentWeather = W_RAIN darkFactor = 0.5 ok
    if currentWeather = W_STORM darkFactor = 0.3 ok
    if currentWeather = W_CLOUDY darkFactor = 0.7 ok
    if currentWeather = W_FOG darkFactor = 0.6 ok
    dayBright *= darkFactor

    dawnDusk = 0.0
    if wDayTime > 0.2 and wDayTime < 0.35
        dawnDusk = 1.0 - fabs(wDayTime - 0.275) / 0.075
    ok
    if wDayTime > 0.65 and wDayTime < 0.8
        dawnDusk = 1.0 - fabs(wDayTime - 0.725) / 0.075
    ok
    if dawnDusk < 0 dawnDusk = 0 ok
    if dawnDusk > 1 dawnDusk = 1 ok

    // Sky gradient
    skyH = floor(SCREEN_H * 0.55)
    bands = 15
    bandH = floor(skyH / bands)
    for b = 0 to bands - 1
        f = b * 1.0 / bands
        r = floor(8 + dayBright * 100 + dawnDusk * 150 * (1 - f))
        g = floor(10 + dayBright * 140 - dawnDusk * 30)
        b2 = floor(35 + dayBright * 120 - dawnDusk * 80 * f)
        if currentWeather = W_SNOW
            r += 20  g += 20  b2 += 30
        ok
        if r > 255 r = 255 ok  if g > 255 g = 255 ok  if b2 > 255 b2 = 255 ok
        if r < 0 r = 0 ok  if g < 0 g = 0 ok  if b2 < 0 b2 = 0 ok
        DrawRectangle(0, b * bandH, SCREEN_W, bandH + 1, RAYLIBColor(r, g, b2, 255))
    next

    // Lower half - ground/horizon fade
    gR = floor(20 + dayBright * 30)
    gG = floor(25 + dayBright * 40)
    gB = floor(35 + dayBright * 50)
    DrawRectangle(0, skyH, SCREEN_W, SCREEN_H - skyH, RAYLIBColor(gR, gG, gB, 255))

func w_drawStars
    PI2 = 3.14159265
    nightFactor = 1.0 - sin(wDayTime * PI2)
    if nightFactor < 0 nightFactor = 0 ok
    if nightFactor < 0.3 return ok

    for i = 1 to WS_MAX
        twinkle = sin(wAnimTime * 3 + wsPhase[i])
        bright = floor(wsBright[i] * nightFactor * (0.6 + twinkle * 0.4))
        if bright > 255 bright = 255 ok
        if bright < 10 loop ok
        DrawCircle(wsX[i], wsY[i], 1, RAYLIBColor(255, 255, 240, bright))
    next

func w_drawCelestial
    PI2 = 3.14159265
    skyH = floor(SCREEN_H * 0.55)
    dayBright = sin(wDayTime * PI2)
    if dayBright < 0 dayBright = 0 ok

    if dayBright > 0.05
        // Sun
        sunX = floor(SCREEN_W * wDayTime)
        sunAngle = wDayTime * PI2
        sunY = floor(skyH - sin(sunAngle) * (skyH - 30))
        sunR = 18 + floor(dayBright * 12)
        DrawCircle(sunX, sunY, sunR + 20, RAYLIBColor(255, 230, 100, floor(dayBright * 25)))
        DrawCircle(sunX, sunY, sunR + 10, RAYLIBColor(255, 240, 150, floor(dayBright * 50)))
        DrawCircle(sunX, sunY, sunR, RAYLIBColor(255, 245, 180, floor(dayBright * 200)))
        // Sun rays
        if dayBright > 0.4 and currentWeather = W_CLEAR
            for ray = 0 to 7
                angle = ray * PI2 / 8 + wAnimTime * 0.1
                rx = sunX + floor(cos(angle) * (sunR + 25))
                ry = sunY + floor(sin(angle) * (sunR + 25))
                rx2 = sunX + floor(cos(angle) * (sunR + 40 + sin(wAnimTime + ray) * 8))
                ry2 = sunY + floor(sin(angle) * (sunR + 40 + sin(wAnimTime + ray) * 8))
                DrawLine(rx, ry, rx2, ry2, RAYLIBColor(255, 240, 150, floor(dayBright * 50)))
            next
        ok
    else
        // Moon
        nightFactor = 1.0 - sin(wDayTime * PI2)
        if nightFactor > 0.3
            moonX = floor(SCREEN_W * (1.0 - wDayTime))
            moonAngle = (1.0 - wDayTime) * PI2
            moonY = floor(skyH - sin(moonAngle) * (skyH - 50))
            DrawCircle(moonX, moonY, 20, RAYLIBColor(200, 210, 240, floor(nightFactor * 20)))
            DrawCircle(moonX, moonY, 14, RAYLIBColor(220, 225, 245, floor(nightFactor * 170)))
            DrawCircle(moonX + 4, moonY - 2, 11, RAYLIBColor(20, 25, 50, floor(nightFactor * 150)))
        ok
    ok

func w_drawClouds
    PI2 = 3.14159265
    dayBright = sin(wDayTime * PI2)
    if dayBright < 0 dayBright = 0 ok

    for i = 1 to WC_MAX
        if wcActive[i] = 0 loop ok
        cx = wcX[i]
        cy = wcY[i]
        cw = wcW[i]
        ch = wcH[i]
        dark = wcDark[i]

        br = floor(200 + dayBright * 55)
        bg = floor(200 + dayBright * 55)
        bb = floor(210 + dayBright * 45)
        br = floor(br * (1.0 - dark * 0.6))
        bg = floor(bg * (1.0 - dark * 0.6))
        bb = floor(bb * (1.0 - dark * 0.5))
        al = wcAlpha[i]

        // Cloud body: overlapping circles
        for b = 0 to 4
            bx = cx - cw/2 + b * cw / 5 + sin(b * 1.5) * cw * 0.1
            by = cy + sin(b * 2.2 + 0.5) * ch * 0.2
            bRadius = ch * 0.5 + sin(b * 1.8) * ch * 0.2
            if bRadius < 8 bRadius = 8 ok
            DrawCircle(floor(bx), floor(by), floor(bRadius), RAYLIBColor(br, bg, bb, al))
        next
        // Flat bottom fill
        DrawRectangle(floor(cx - cw/2 + ch * 0.3), floor(cy), floor(cw - ch * 0.6), floor(ch * 0.3), RAYLIBColor(br - 10, bg - 10, bb - 5, al))
    next

func w_drawDrops
    for i = 1 to WD_MAX
        if wdActive[i] = 0 loop ok
        dpx = floor(wdX[i])
        dpy = floor(wdY[i])

        if currentWeather = W_RAIN or currentWeather = W_STORM
            sz = floor(wdSize[i])
            al = wdAlpha[i]
            endX = dpx + floor(wdVX[i] * 0.03)
            endY = dpy + sz
            // Draw two lines for thicker rain streaks
            DrawLine(dpx, dpy, endX, endY, RAYLIBColor(170, 195, 230, al))
            DrawLine(dpx+1, dpy, endX+1, endY, RAYLIBColor(190, 210, 240, floor(al * 0.6)))
        ok

        if currentWeather = W_SNOW
            sz = wdSize[i] * 1.5
            al = wdAlpha[i]
            DrawCircle(dpx, dpy, floor(sz), RAYLIBColor(240, 245, 255, al))
            if sz > 2
                DrawCircle(dpx, dpy, floor(sz * 0.5), RAYLIBColor(255, 255, 255, floor(al * 0.6)))
            ok
        ok
    next

func w_drawLightning
    for i = 1 to WL_MAX
        if wlActive[i] = 0 loop ok
        segLen = len(wlSegX[i])
        if segLen < 2 loop ok
        lifeRatio = wlTimer[i] / 0.3
        alpha = floor(lifeRatio * 255)
        if alpha > 255 alpha = 255 ok
        if alpha < 0 loop ok
        for s = 2 to segLen
            x1 = wlSegX[i][s-1]  y1 = wlSegY[i][s-1]
            x2 = wlSegX[i][s]    y2 = wlSegY[i][s]
            DrawLine(floor(x1)-2, floor(y1), floor(x2)-2, floor(y2), RAYLIBColor(150, 150, 255, floor(alpha*0.2)))
            DrawLine(floor(x1)+2, floor(y1), floor(x2)+2, floor(y2), RAYLIBColor(150, 150, 255, floor(alpha*0.2)))
            DrawLine(floor(x1), floor(y1), floor(x2), floor(y2), RAYLIBColor(230, 230, 255, alpha))
            DrawLine(floor(x1)+1, floor(y1), floor(x2)+1, floor(y2), RAYLIBColor(255, 255, 255, alpha))
        next
    next

func w_drawFog
    for i = 1 to WF_MAX
        fx = floor(wfX[i])
        fy = floor(wfY[i])
        fw = floor(wfW[i])
        fh = 40 + floor(sin(i * 0.7 + wAnimTime * 0.2) * 15)
        al = wfAlpha[i] + floor(sin(wAnimTime * 0.5 + i * 0.3) * 15)
        if al > 120 al = 120 ok
        if al < 10 al = 10 ok
        DrawRectangle(fx, fy, fw, fh, RAYLIBColor(180, 185, 195, al))
        DrawRectangle(fx + 20, fy - 10, floor(fw * 0.7), floor(fh * 0.6), RAYLIBColor(190, 195, 200, floor(al * 0.6)))
    next
    DrawRectangle(0, floor(SCREEN_H * 0.4), SCREEN_W, floor(SCREEN_H * 0.6), RAYLIBColor(170, 175, 185, 50))
