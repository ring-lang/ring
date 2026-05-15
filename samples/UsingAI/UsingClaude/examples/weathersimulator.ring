/*
**  Weather Simulator - RingRayLib
**  ==================================
**  Clouds, rain, lightning, wind, snow, sun & moon.
**  Watch a living sky unfold over a landscape!
**
**  Controls:
**    1-6              - Weather presets
**    W                - Cycle wind strength
**    C                - Add cloud at random position
**    L                - Trigger lightning bolt
**    T                - Toggle day/night cycle speed
**    D                - Toggle debug info
**    Space / P        - Pause / Resume
**    +/-              - Simulation speed
**    R                - Reset
**    ESC              - Exit
**
**  Presets:
**    1. Clear Day     2. Cloudy
**    3. Rain          4. Thunderstorm
**    5. Snow          6. Fog
*/

load "raylib.ring"

// =============================================================
// Constants
// =============================================================

SCREEN_W = 1024
SCREEN_H = 700
TOOLBAR_H = 48
CANVAS_H = SCREEN_H - TOOLBAR_H

PI = 3.14159265

// Ground level
GROUND_Y = 520
WATER_Y  = 540
HORIZON  = 480

// =============================================================
// Weather Types
// =============================================================

WEATHER_CLEAR   = 1
WEATHER_CLOUDY  = 2
WEATHER_RAIN    = 3
WEATHER_STORM   = 4
WEATHER_SNOW    = 5
WEATHER_FOG     = 6
WEATHER_COUNT   = 6
weatherNames = ["Clear Day", "Cloudy", "Rain", "Thunderstorm", "Snow", "Fog"]

// Wind levels
WIND_CALM    = 1
WIND_LIGHT   = 2
WIND_MODERATE = 3
WIND_STRONG  = 4
WIND_COUNT   = 4
windNames = ["Calm", "Light", "Moderate", "Strong"]
windSpeeds = [5.0, 30.0, 70.0, 140.0]

// =============================================================
// State
// =============================================================

currentWeather = WEATHER_CLEAR
currentWind = WIND_CALM
windSpeed = 5.0
windDir = 1.0       // 1 = right, -1 = left

paused = false
simSpeed = 1.0
animTime = 0.0
debugView = false

// Day/night cycle
dayTime = 0.3       // 0.0 = midnight, 0.5 = noon, 1.0 = midnight
dayCycleSpeed = 1   // 1=slow, 2=medium, 3=fast
daySpeeds = [0.005, 0.02, 0.08]
DAY_COUNT = 3
dayNames = ["Slow", "Medium", "Fast"]

// =============================================================
// Clouds
// =============================================================

MAX_CLOUDS = 25
cloudX = list(MAX_CLOUDS)
cloudY = list(MAX_CLOUDS)
cloudW = list(MAX_CLOUDS)
cloudH = list(MAX_CLOUDS)
cloudAlpha = list(MAX_CLOUDS)
cloudActive = list(MAX_CLOUDS)
cloudSpeed = list(MAX_CLOUDS)
cloudDark = list(MAX_CLOUDS)     // darkness for rain clouds
numClouds = 0

for i = 1 to MAX_CLOUDS
    cloudActive[i] = 0
next

// =============================================================
// Rain / Snow Particles
// =============================================================

MAX_DROPS = 600
dropX = list(MAX_DROPS)
dropY = list(MAX_DROPS)
dropVX = list(MAX_DROPS)
dropVY = list(MAX_DROPS)
dropActive = list(MAX_DROPS)
dropSize = list(MAX_DROPS)
dropAlpha = list(MAX_DROPS)

for i = 1 to MAX_DROPS
    dropActive[i] = 0
next

// =============================================================
// Lightning
// =============================================================

MAX_BOLTS = 5
boltActive = list(MAX_BOLTS)
boltX = list(MAX_BOLTS)
boltTimer = list(MAX_BOLTS)
boltSegX = []    // list of segment lists
boltSegY = []

for i = 1 to MAX_BOLTS
    boltActive[i] = 0
    add(boltSegX, [])
    add(boltSegY, [])
next

flashAlpha = 0.0    // screen flash

// =============================================================
// Fog particles
// =============================================================

MAX_FOG = 40
fogX = list(MAX_FOG)
fogY = list(MAX_FOG)
fogW = list(MAX_FOG)
fogAlpha = list(MAX_FOG)
fogSpeed = list(MAX_FOG)

for i = 1 to MAX_FOG
    fogX[i] = GetRandomValue(-200, SCREEN_W + 200) * 1.0
    fogY[i] = GetRandomValue(HORIZON - 100, GROUND_Y) * 1.0
    fogW[i] = GetRandomValue(150, 400) * 1.0
    fogAlpha[i] = GetRandomValue(30, 80)
    fogSpeed[i] = GetRandomValue(5, 25) * 1.0
next

// =============================================================
// Stars
// =============================================================

MAX_STARS = 100
starX = list(MAX_STARS)
starY = list(MAX_STARS)
starBright = list(MAX_STARS)
starPhase = list(MAX_STARS)

for i = 1 to MAX_STARS
    starX[i] = GetRandomValue(0, SCREEN_W)
    starY[i] = GetRandomValue(10, HORIZON - 20)
    starBright[i] = GetRandomValue(100, 255)
    starPhase[i] = GetRandomValue(0, 628) / 100.0
next

// =============================================================
// Splashes (rain hitting ground)
// =============================================================

MAX_SPLASH = 80
splashX = list(MAX_SPLASH)
splashY = list(MAX_SPLASH)
splashTimer = list(MAX_SPLASH)
splashActive = list(MAX_SPLASH)

for i = 1 to MAX_SPLASH
    splashActive[i] = 0
next

// Toolbar
hoverBtn = 0
BTN_Y = SCREEN_H - 46
BTN_H = 36
BTN_GAP = 4

// =============================================================
// Main
// =============================================================

InitWindow(SCREEN_W, SCREEN_H, "Weather Simulator - RingRayLib")
SetTargetFPS(60)
SetExitKey(0)

ws_setWeather(WEATHER_CLEAR)

while !WindowShouldClose()
    ws_update()
    BeginDrawing()
        ws_draw()
    EndDrawing()
end

CloseWindow()

// =============================================================
// Set Weather Preset
// =============================================================

func ws_setWeather type
    currentWeather = type

    if type = WEATHER_CLEAR
        currentWind = WIND_CALM
        ws_clearClouds()
        ws_spawnClouds(3, 0.1)
    ok
    if type = WEATHER_CLOUDY
        currentWind = WIND_LIGHT
        ws_clearClouds()
        ws_spawnClouds(12, 0.2)
    ok
    if type = WEATHER_RAIN
        currentWind = WIND_MODERATE
        ws_clearClouds()
        ws_spawnClouds(15, 0.6)
    ok
    if type = WEATHER_STORM
        currentWind = WIND_STRONG
        ws_clearClouds()
        ws_spawnClouds(18, 0.8)
    ok
    if type = WEATHER_SNOW
        currentWind = WIND_LIGHT
        ws_clearClouds()
        ws_spawnClouds(12, 0.3)
    ok
    if type = WEATHER_FOG
        currentWind = WIND_CALM
        ws_clearClouds()
        ws_spawnClouds(8, 0.3)
    ok

    windSpeed = windSpeeds[currentWind]

func ws_clearClouds
    for i = 1 to MAX_CLOUDS
        cloudActive[i] = 0
    next
    numClouds = 0
    for i = 1 to MAX_DROPS
        dropActive[i] = 0
    next

func ws_spawnClouds count, darkness
    for c = 1 to count
        ws_addCloud(GetRandomValue(0, SCREEN_W), GetRandomValue(40, 200), darkness)
    next

func ws_addCloud x, y, darkness
    for i = 1 to MAX_CLOUDS
        if cloudActive[i] = 0
            cloudActive[i] = 1
            cloudX[i] = x * 1.0
            cloudY[i] = y * 1.0
            cloudW[i] = GetRandomValue(100, 250) * 1.0
            cloudH[i] = GetRandomValue(30, 60) * 1.0
            cloudAlpha[i] = GetRandomValue(140, 220)
            cloudSpeed[i] = GetRandomValue(8, 30) * 1.0
            cloudDark[i] = darkness
            numClouds++
            return
        ok
    next

// =============================================================
// Update
// =============================================================

func ws_update
    dt = GetFrameTime()
    if dt > 0.05 dt = 0.05 ok

    if IsKeyPressed(KEY_ESCAPE)
        CloseWindow()
        shutdown(0)
    ok

    // Presets
    if IsKeyPressed(KEY_ONE)   ws_setWeather(WEATHER_CLEAR) ok
    if IsKeyPressed(KEY_TWO)   ws_setWeather(WEATHER_CLOUDY) ok
    if IsKeyPressed(KEY_THREE) ws_setWeather(WEATHER_RAIN) ok
    if IsKeyPressed(KEY_FOUR)  ws_setWeather(WEATHER_STORM) ok
    if IsKeyPressed(KEY_FIVE)  ws_setWeather(WEATHER_SNOW) ok
    if IsKeyPressed(KEY_SIX)   ws_setWeather(WEATHER_FOG) ok

    if IsKeyPressed(KEY_W)
        currentWind++
        if currentWind > WIND_COUNT currentWind = 1 ok
        windSpeed = windSpeeds[currentWind]
    ok

    if IsKeyPressed(KEY_C)
        ws_addCloud(GetRandomValue(0, SCREEN_W), GetRandomValue(40, 180), 0.3)
    ok

    if IsKeyPressed(KEY_L) ws_triggerLightning() ok

    if IsKeyPressed(KEY_T)
        dayCycleSpeed++
        if dayCycleSpeed > DAY_COUNT dayCycleSpeed = 1 ok
    ok

    if IsKeyPressed(KEY_D) debugView = !debugView ok

    if IsKeyPressed(KEY_SPACE) or IsKeyPressed(KEY_P) paused = !paused ok

    if IsKeyPressed(KEY_EQUAL) or IsKeyPressed(KEY_KP_ADD)
        simSpeed *= 1.5
        if simSpeed > 5.0 simSpeed = 5.0 ok
    ok
    if IsKeyPressed(KEY_MINUS) or IsKeyPressed(KEY_KP_SUBTRACT)
        simSpeed /= 1.5
        if simSpeed < 0.25 simSpeed = 0.25 ok
    ok

    if IsKeyPressed(KEY_R)
        ws_setWeather(WEATHER_CLEAR)
        dayTime = 0.3
    ok

    if IsMouseButtonPressed(MOUSE_LEFT_BUTTON)
        ws_handleToolbar(GetMouseX(), GetMouseY())
    ok

    if paused return ok

    sDt = dt * simSpeed
    animTime += sDt

    // Day cycle
    dayTime += daySpeeds[dayCycleSpeed] * sDt
    if dayTime > 1.0 dayTime -= 1.0 ok

    // Update systems
    ws_updateClouds(sDt)
    ws_updateDrops(sDt)
    ws_updateLightning(sDt)
    ws_updateSplashes(sDt)
    ws_updateFog(sDt)

    // Spawn rain/snow
    if currentWeather = WEATHER_RAIN or currentWeather = WEATHER_STORM
        ws_spawnRain(sDt)
    ok
    if currentWeather = WEATHER_SNOW
        ws_spawnSnow(sDt)
    ok

    // Auto lightning in storms
    if currentWeather = WEATHER_STORM
        if GetRandomValue(1, 180) = 1
            ws_triggerLightning()
        ok
    ok

    // Flash decay
    if flashAlpha > 0
        flashAlpha -= 400 * sDt
        if flashAlpha < 0 flashAlpha = 0 ok
    ok

// =============================================================
// Update Clouds
// =============================================================

func ws_updateClouds dt
    for i = 1 to MAX_CLOUDS
        if cloudActive[i] = 0 loop ok
        cloudX[i] += (windSpeed * windDir + cloudSpeed[i] * 0.3) * dt
        // Gentle vertical drift
        cloudY[i] += sin(animTime * 0.3 + i) * 2 * dt

        // Wrap around
        if cloudX[i] > SCREEN_W + cloudW[i]
            cloudX[i] = -cloudW[i]
        ok
        if cloudX[i] < -cloudW[i] - 100
            cloudX[i] = SCREEN_W + cloudW[i]
        ok
    next

// =============================================================
// Spawn Rain
// =============================================================

func ws_spawnRain dt
    spawnRate = 8
    if currentWeather = WEATHER_STORM spawnRate = 16 ok

    for s = 1 to spawnRate
        for i = 1 to MAX_DROPS
            if dropActive[i] = 0
                dropActive[i] = 1
                dropX[i] = GetRandomValue(-50, SCREEN_W + 50) * 1.0
                dropY[i] = GetRandomValue(-20, 50) * 1.0
                dropVX[i] = windSpeed * windDir * 0.6
                dropVY[i] = GetRandomValue(350, 550) * 1.0
                dropSize[i] = GetRandomValue(8, 20) * 1.0
                dropAlpha[i] = GetRandomValue(120, 200)
                exit
            ok
        next
    next

// =============================================================
// Spawn Snow
// =============================================================

func ws_spawnSnow dt
    for s = 1 to 5
        for i = 1 to MAX_DROPS
            if dropActive[i] = 0
                dropActive[i] = 1
                dropX[i] = GetRandomValue(-20, SCREEN_W + 20) * 1.0
                dropY[i] = GetRandomValue(-30, 10) * 1.0
                dropVX[i] = windSpeed * windDir * 0.3 + GetRandomValue(-20, 20)
                dropVY[i] = GetRandomValue(30, 80) * 1.0
                dropSize[i] = GetRandomValue(15, 35) / 10.0
                dropAlpha[i] = GetRandomValue(160, 240)
                exit
            ok
        next
    next

// =============================================================
// Update Drops
// =============================================================

func ws_updateDrops dt
    for i = 1 to MAX_DROPS
        if dropActive[i] = 0 loop ok

        dropX[i] += dropVX[i] * dt
        dropY[i] += dropVY[i] * dt

        // Snow: gentle sway
        if currentWeather = WEATHER_SNOW
            dropX[i] += sin(animTime * 2 + i * 0.5) * 15 * dt
        ok

        // Hit ground
        if dropY[i] > GROUND_Y
            dropActive[i] = 0
            // Splash for rain
            if currentWeather = WEATHER_RAIN or currentWeather = WEATHER_STORM
                ws_addSplash(dropX[i], GROUND_Y)
            ok
        ok

        // Off screen
        if dropX[i] < -100 or dropX[i] > SCREEN_W + 100
            dropActive[i] = 0
        ok
    next

// =============================================================
// Splashes
// =============================================================

func ws_addSplash x, y
    for i = 1 to MAX_SPLASH
        if splashActive[i] = 0
            splashActive[i] = 1
            splashX[i] = x
            splashY[i] = y
            splashTimer[i] = 0.3
            return
        ok
    next

func ws_updateSplashes dt
    for i = 1 to MAX_SPLASH
        if splashActive[i] = 0 loop ok
        splashTimer[i] -= dt
        if splashTimer[i] <= 0
            splashActive[i] = 0
        ok
    next

// =============================================================
// Lightning
// =============================================================

func ws_triggerLightning
    for i = 1 to MAX_BOLTS
        if boltActive[i] = 0
            boltActive[i] = 1
            boltX[i] = GetRandomValue(100, SCREEN_W - 100) * 1.0
            boltTimer[i] = 0.3

            // Generate bolt segments
            boltSegX[i] = []
            boltSegY[i] = []
            sx = boltX[i]
            sy = GetRandomValue(60, 120) * 1.0
            add(boltSegX[i], sx)
            add(boltSegY[i], sy)

            while sy < GROUND_Y
                sx += GetRandomValue(-25, 25)
                sy += GetRandomValue(15, 40)
                add(boltSegX[i], sx)
                add(boltSegY[i], sy)

                // Branch chance
                if GetRandomValue(1, 5) = 1
                    bsx = sx + GetRandomValue(-40, 40)
                    bsy = sy + GetRandomValue(20, 50)
                    add(boltSegX[i], bsx)
                    add(boltSegY[i], bsy)
                    add(boltSegX[i], sx)
                    add(boltSegY[i], sy)
                ok
            end

            flashAlpha = 200
            return
        ok
    next

func ws_updateLightning dt
    for i = 1 to MAX_BOLTS
        if boltActive[i] = 0 loop ok
        boltTimer[i] -= dt
        if boltTimer[i] <= 0
            boltActive[i] = 0
        ok
    next

// =============================================================
// Fog
// =============================================================

func ws_updateFog dt
    for i = 1 to MAX_FOG
        fogX[i] += (windSpeed * windDir * 0.2 + fogSpeed[i]) * dt
        if fogX[i] > SCREEN_W + fogW[i]
            fogX[i] = -fogW[i]
        ok
        if fogX[i] < -fogW[i] - 100
            fogX[i] = SCREEN_W + 50
        ok
    next

// =============================================================
// Draw
// =============================================================

func ws_draw
    // Sky gradient
    ws_drawSky()

    // Stars (night)
    ws_drawStars()

    // Sun or Moon
    ws_drawCelestial()

    // Mountains / landscape
    ws_drawLandscape()

    // Clouds (behind rain)
    ws_drawClouds()

    // Rain / Snow
    ws_drawDrops()

    // Lightning
    ws_drawLightning()

    // Splashes
    ws_drawSplashes()

    // Fog
    if currentWeather = WEATHER_FOG
        ws_drawFog()
    ok

    // Lightning flash overlay
    if flashAlpha > 0
        fa = floor(flashAlpha)
        if fa > 255 fa = 255 ok
        DrawRectangle(0, 0, SCREEN_W, CANVAS_H, RAYLIBColor(255, 255, 240, fa))
    ok

    // Wind streaks
    if currentWind >= WIND_MODERATE
        ws_drawWindStreaks()
    ok

    // HUD
    ws_drawHUD()

    // Toolbar
    ws_drawToolbar()

// =============================================================
// Draw Sky
// =============================================================

func ws_drawSky
    // dayTime: 0=midnight, 0.25=dawn, 0.5=noon, 0.75=dusk
    sunAngle = dayTime * PI * 2 - PI / 2

    // Sky brightness based on time
    dayBright = sin(dayTime * PI)
    if dayBright < 0 dayBright = 0 ok

    // Storm/cloud darkening
    darkFactor = 1.0
    if currentWeather = WEATHER_RAIN darkFactor = 0.5 ok
    if currentWeather = WEATHER_STORM darkFactor = 0.3 ok
    if currentWeather = WEATHER_CLOUDY darkFactor = 0.7 ok
    if currentWeather = WEATHER_FOG darkFactor = 0.6 ok

    dayBright *= darkFactor

    // Sky colors
    // Night: dark blue, Day: light blue, Dawn/dusk: orange tint
    dawnDusk = 0.0
    if dayTime > 0.2 and dayTime < 0.35
        dawnDusk = 1.0 - fabs(dayTime - 0.275) / 0.075
    ok
    if dayTime > 0.65 and dayTime < 0.8
        dawnDusk = 1.0 - fabs(dayTime - 0.725) / 0.075
    ok
    if dawnDusk < 0 dawnDusk = 0 ok
    if dawnDusk > 1 dawnDusk = 1 ok

    // Draw gradient (bands)
    bands = 20
    bandH = floor(HORIZON / bands)
    for b = 0 to bands - 1
        f = b * 1.0 / bands

        // Base night color
        r = floor(8 + dayBright * 100 + dawnDusk * 150 * (1 - f))
        g = floor(10 + dayBright * 140 - dawnDusk * 30)
        b2 = floor(35 + dayBright * 120 - dawnDusk * 80 * f)

        // Snow: slightly brighter sky
        if currentWeather = WEATHER_SNOW
            r += 20  g += 20  b2 += 30
        ok

        if r > 255 r = 255 ok  if g > 255 g = 255 ok  if b2 > 255 b2 = 255 ok
        if r < 0 r = 0 ok  if g < 0 g = 0 ok  if b2 < 0 b2 = 0 ok

        DrawRectangle(0, b * bandH, SCREEN_W, bandH + 1, RAYLIBColor(r, g, b2, 255))
    next

    // Below horizon to ground
    gndR = floor(20 + dayBright * 40)
    gndG = floor(35 + dayBright * 60)
    gndB = floor(15 + dayBright * 25)
    DrawRectangle(0, HORIZON, SCREEN_W, CANVAS_H - HORIZON, RAYLIBColor(gndR, gndG, gndB, 255))

// =============================================================
// Draw Stars
// =============================================================

func ws_drawStars
    nightFactor = 1.0 - sin(dayTime * PI)
    if nightFactor < 0 nightFactor = 0 ok
    if nightFactor < 0.3 return ok

    for i = 1 to MAX_STARS
        twinkle = sin(animTime * 3 + starPhase[i])
        bright = floor(starBright[i] * nightFactor * (0.6 + twinkle * 0.4))
        if bright > 255 bright = 255 ok
        if bright < 10 loop ok
        DrawCircle(starX[i], starY[i], 1, RAYLIBColor(255, 255, 240, bright))
    next

// =============================================================
// Draw Celestial (Sun / Moon)
// =============================================================

func ws_drawCelestial
    // Sun arc
    sunAngle = dayTime * PI   // 0=horizon east, PI/2=zenith, PI=horizon west
    sunX = floor(SCREEN_W * dayTime)
    sunY = floor(HORIZON - sin(sunAngle) * (HORIZON - 30))

    dayBright = sin(dayTime * PI)
    if dayBright < 0 dayBright = 0 ok

    if dayBright > 0.05
        // Sun
        sunR = 20 + floor(dayBright * 15)
        // Glow
        DrawCircle(sunX, sunY, sunR + 20, RAYLIBColor(255, 230, 100, floor(dayBright * 30)))
        DrawCircle(sunX, sunY, sunR + 10, RAYLIBColor(255, 240, 150, floor(dayBright * 60)))
        DrawCircle(sunX, sunY, sunR, RAYLIBColor(255, 245, 180, floor(dayBright * 220)))

        // Rays
        if dayBright > 0.4 and currentWeather = WEATHER_CLEAR
            for ray = 0 to 7
                angle = ray * PI / 4 + animTime * 0.1
                rx = sunX + cos(angle) * (sunR + 25)
                ry = sunY + sin(angle) * (sunR + 25)
                rx2 = sunX + cos(angle) * (sunR + 40 + sin(animTime + ray) * 8)
                ry2 = sunY + sin(angle) * (sunR + 40 + sin(animTime + ray) * 8)
                DrawLine(floor(rx), floor(ry), floor(rx2), floor(ry2), RAYLIBColor(255, 240, 150, floor(dayBright * 60)))
            next
        ok
    else
        // Moon
        nightFactor = 1.0 - sin(dayTime * PI)
        if nightFactor > 0.3
            moonAngle = (1.0 - dayTime) * PI
            moonX = floor(SCREEN_W * (1.0 - dayTime))
            moonY = floor(HORIZON - sin(moonAngle) * (HORIZON - 60))

            // Glow
            DrawCircle(moonX, moonY, 22, RAYLIBColor(200, 210, 240, floor(nightFactor * 20)))
            DrawCircle(moonX, moonY, 15, RAYLIBColor(220, 225, 245, floor(nightFactor * 180)))
            // Crescent shadow
            DrawCircle(moonX + 4, moonY - 2, 12, RAYLIBColor(20, 25, 50, floor(nightFactor * 160)))
        ok
    ok

// =============================================================
// Draw Landscape
// =============================================================

func ws_drawLandscape
    dayBright = sin(dayTime * PI)
    if dayBright < 0 dayBright = 0 ok
    bf = dayBright

    // Mountains (background)
    for x = 0 to SCREEN_W step 3
        mh1 = sin(x * 0.008) * 40 + sin(x * 0.015 + 2) * 25 + sin(x * 0.003) * 30
        my = HORIZON - mh1 - 20
        h = floor(HORIZON - my)
        mr = floor(40 + bf * 40)
        mg = floor(50 + bf * 50)
        mb = floor(45 + bf * 55)
        DrawRectangle(x, floor(my), 4, h, RAYLIBColor(mr, mg, mb, 255))
    next

    // Hills (foreground)
    for x = 0 to SCREEN_W step 2
        hh = sin(x * 0.012 + 1) * 30 + sin(x * 0.025) * 15
        hy = GROUND_Y - hh - 10
        h = floor(GROUND_Y - hy)
        hr = floor(30 + bf * 50)
        hg = floor(55 + bf * 80)
        hb = floor(20 + bf * 30)
        if currentWeather = WEATHER_SNOW
            // Snow on hills
            hr = floor(180 + bf * 60)
            hg = floor(185 + bf * 60)
            hb = floor(190 + bf * 60)
        ok
        DrawRectangle(x, floor(hy), 3, h + 2, RAYLIBColor(hr, hg, hb, 255))
    next

    // Ground
    gr = floor(35 + bf * 35)  gg = floor(60 + bf * 60)  gb = floor(25 + bf * 20)
    if currentWeather = WEATHER_SNOW
        gr = floor(170 + bf * 60)  gg = floor(175 + bf * 60)  gb = floor(180 + bf * 60)
    ok
    DrawRectangle(0, GROUND_Y, SCREEN_W, CANVAS_H - GROUND_Y, RAYLIBColor(gr, gg, gb, 255))

    // Water puddles (rain)
    if currentWeather = WEATHER_RAIN or currentWeather = WEATHER_STORM
        for px = 0 to SCREEN_W step 120
            pw = 40 + floor(sin(px * 0.05) * 20)
            py = GROUND_Y + 8 + floor(sin(px * 0.03) * 5)
            ripple = floor(fabs(sin(animTime * 3 + px * 0.02)) * 20) + 30
            DrawRectangle(px, py, pw, 4, RAYLIBColor(60, 80, 120, ripple))
        next
    ok

    // Trees
    ws_drawTree(150, GROUND_Y - 5, bf)
    ws_drawTree(400, GROUND_Y - 8, bf)
    ws_drawTree(650, GROUND_Y - 3, bf)
    ws_drawTree(850, GROUND_Y - 6, bf)

func ws_drawTree tx, ty, bf
    // Trunk
    DrawRectangle(tx - 3, ty - 35, 6, 38, RAYLIBColor(floor(60 + bf*30), floor(40 + bf*20), floor(20 + bf*10), 255))
    // Wind sway
    sway = sin(animTime * 1.5 + tx * 0.01) * windSpeed * 0.05
    // Canopy circles
    lr = floor(25 + bf * 50)
    lg = floor(70 + bf * 90)
    lb = floor(20 + bf * 25)
    if currentWeather = WEATHER_SNOW
        lr = floor(160 + bf * 60)  lg = floor(175 + bf * 60)  lb = floor(180 + bf * 60)
    ok
    DrawCircle(tx + floor(sway), ty - 45, 18, RAYLIBColor(lr, lg, lb, 220))
    DrawCircle(tx - 10 + floor(sway), ty - 38, 14, RAYLIBColor(lr - 10, lg - 5, lb, 200))
    DrawCircle(tx + 10 + floor(sway), ty - 38, 14, RAYLIBColor(lr + 5, lg + 5, lb, 200))

// =============================================================
// Draw Clouds
// =============================================================

func ws_drawClouds
    for i = 1 to MAX_CLOUDS
        if cloudActive[i] = 0 loop ok

        cx = cloudX[i]
        cy = cloudY[i]
        cw = cloudW[i]
        ch = cloudH[i]
        dark = cloudDark[i]

        // Cloud brightness
        dayBright = sin(dayTime * PI)
        if dayBright < 0 dayBright = 0 ok

        br = floor(200 + dayBright * 55)
        bg = floor(200 + dayBright * 55)
        bb = floor(210 + dayBright * 45)

        // Darken for rain
        br = floor(br * (1.0 - dark * 0.6))
        bg = floor(bg * (1.0 - dark * 0.6))
        bb = floor(bb * (1.0 - dark * 0.5))

        al = cloudAlpha[i]

        // Cloud body: overlapping ellipses (circles)
        numBlobs = 5
        for b = 0 to numBlobs - 1
            bx = cx - cw/2 + b * cw / numBlobs + sin(b * 1.5) * cw * 0.1
            by = cy + sin(b * 2.2 + 0.5) * ch * 0.2
            bRadius = ch * 0.5 + sin(b * 1.8) * ch * 0.2
            if bRadius < 8 bRadius = 8 ok
            DrawCircle(floor(bx), floor(by), floor(bRadius), RAYLIBColor(br, bg, bb, al))
        next

        // Bottom flat fill
        DrawRectangle(floor(cx - cw/2 + ch * 0.3), floor(cy), floor(cw - ch * 0.6), floor(ch * 0.3), RAYLIBColor(br - 10, bg - 10, bb - 5, al))
    next

// =============================================================
// Draw Drops (Rain / Snow)
// =============================================================

func ws_drawDrops
    for i = 1 to MAX_DROPS
        if dropActive[i] = 0 loop ok

        px = floor(dropX[i])
        py = floor(dropY[i])

        if currentWeather = WEATHER_RAIN or currentWeather = WEATHER_STORM
            // Rain streak
            sz = floor(dropSize[i])
            al = dropAlpha[i]
            endX = px + floor(dropVX[i] * 0.02)
            endY = py + sz
            DrawLine(px, py, endX, endY, RAYLIBColor(180, 200, 230, al))
        ok

        if currentWeather = WEATHER_SNOW
            // Snowflake
            sz = dropSize[i]
            al = dropAlpha[i]
            DrawCircle(px, py, floor(sz), RAYLIBColor(240, 245, 255, al))
            if sz > 2
                DrawCircle(px, py, floor(sz * 0.5), RAYLIBColor(255, 255, 255, floor(al * 0.5)))
            ok
        ok
    next

// =============================================================
// Draw Lightning
// =============================================================

func ws_drawLightning
    for i = 1 to MAX_BOLTS
        if boltActive[i] = 0 loop ok
        if len(boltSegX[i]) < 2 loop ok

        lifeRatio = boltTimer[i] / 0.3
        alpha = floor(lifeRatio * 255)
        if alpha > 255 alpha = 255 ok
        if alpha < 0 loop ok

        // Glow
        for s = 2 to len(boltSegX[i])
            x1 = boltSegX[i][s-1]
            y1 = boltSegY[i][s-1]
            x2 = boltSegX[i][s]
            y2 = boltSegY[i][s]

            // Thick glow
            DrawLine(floor(x1)-2, floor(y1), floor(x2)-2, floor(y2), RAYLIBColor(150, 150, 255, floor(alpha*0.2)))
            DrawLine(floor(x1)+2, floor(y1), floor(x2)+2, floor(y2), RAYLIBColor(150, 150, 255, floor(alpha*0.2)))
            // Core
            DrawLine(floor(x1), floor(y1), floor(x2), floor(y2), RAYLIBColor(230, 230, 255, alpha))
            DrawLine(floor(x1)+1, floor(y1), floor(x2)+1, floor(y2), RAYLIBColor(255, 255, 255, alpha))
        next
    next

// =============================================================
// Draw Splashes
// =============================================================

func ws_drawSplashes
    for i = 1 to MAX_SPLASH
        if splashActive[i] = 0 loop ok
        t = 1.0 - splashTimer[i] / 0.3
        r = floor(3 + t * 8)
        alpha = floor((1.0 - t) * 120)
        DrawCircleLines(floor(splashX[i]), floor(splashY[i]), r, RAYLIBColor(180, 200, 230, alpha))
    next

// =============================================================
// Draw Fog
// =============================================================

func ws_drawFog
    for i = 1 to MAX_FOG
        fx = floor(fogX[i])
        fy = floor(fogY[i])
        fw = floor(fogW[i])
        fh = 40 + floor(sin(i * 0.7 + animTime * 0.2) * 15)
        al = fogAlpha[i] + floor(sin(animTime * 0.5 + i * 0.3) * 15)
        if al > 120 al = 120 ok
        if al < 10 al = 10 ok

        // Fog blob: wide transparent rectangle with soft edges
        DrawRectangle(fx, fy, fw, fh, RAYLIBColor(180, 185, 195, al))
        DrawRectangle(fx + 20, fy - 10, floor(fw * 0.7), floor(fh * 0.6), RAYLIBColor(190, 195, 200, floor(al * 0.6)))
    next

    // Global fog overlay
    DrawRectangle(0, HORIZON - 40, SCREEN_W, CANVAS_H - HORIZON + 80, RAYLIBColor(170, 175, 185, 60))

// =============================================================
// Draw Wind Streaks
// =============================================================

func ws_drawWindStreaks
    numStreaks = floor(windSpeed / 20)
    for s = 0 to numStreaks
        sx = floor((animTime * windSpeed * 3 + s * 137) % (SCREEN_W + 200)) - 100
        sy = GetRandomValue(50, GROUND_Y - 20)
        sw = floor(windSpeed * 0.4) + 10
        alpha = floor(fabs(sin(animTime * 2 + s * 1.1)) * 30)
        DrawLine(sx, sy, sx + floor(sw * windDir), sy, RAYLIBColor(200, 210, 230, alpha))
    next

// =============================================================
// HUD
// =============================================================

func ws_drawHUD
    DrawRectangle(0, 0, SCREEN_W, 26, RAYLIBColor(0, 0, 0, 160))
    DrawText("Weather Simulator", 10, 4, 16, RAYLIBColor(255, 215, 0, 220))

    wTxt = "Weather: " + weatherNames[currentWeather]
    DrawText(wTxt, 190, 6, 13, RAYLIBColor(100, 200, 255, 200))

    wnTxt = "Wind: " + windNames[currentWind]
    DrawText(wnTxt, 380, 6, 13, RAYLIBColor(200, 200, 180, 180))

    // Time of day
    hour = floor(dayTime * 24)
    minute = floor((dayTime * 24 - hour) * 60)
    if hour > 23 hour = 23 ok
    hStr = string(hour)
    if hour < 10 hStr = "0" + hStr ok
    mStr = string(minute)
    if minute < 10 mStr = "0" + mStr ok
    timeTxt = "Time: " + hStr + ":" + mStr
    DrawText(timeTxt, 510, 6, 13, RAYLIBColor(200, 200, 150, 200))

    dsTxt = "Cycle: " + dayNames[dayCycleSpeed]
    DrawText(dsTxt, 620, 6, 13, RAYLIBColor(180, 180, 200, 180))

    spdTxt = "" + string(floor(simSpeed * 100)) + "%"
    DrawText(spdTxt, 730, 6, 13, RAYLIBColor(180, 200, 200, 160))

    if paused
        DrawText("PAUSED", 800, 6, 14, RAYLIBColor(255, 100, 100, 240))
    ok

    if debugView
        dropCount = 0
        for i = 1 to MAX_DROPS
            if dropActive[i] = 1 dropCount++ ok
        next
        dbgTxt = "Drops:" + string(dropCount) + " Clouds:" + string(numClouds)
        DrawText(dbgTxt, 880, 6, 11, RAYLIBColor(255, 200, 100, 180))
    ok

    fpsTxt = "" + string(GetFPS()) + " FPS"
    DrawText(fpsTxt, SCREEN_W - 60, SCREEN_H - 14, 12, RAYLIBColor(100, 200, 100, 120))

// =============================================================
// Toolbar
// =============================================================

func ws_drawToolbar
    DrawRectangle(0, SCREEN_H - TOOLBAR_H, SCREEN_W, TOOLBAR_H, RAYLIBColor(22, 24, 32, 255))
    DrawRectangle(0, SCREEN_H - TOOLBAR_H, SCREEN_W, 2, RAYLIBColor(60, 60, 100, 200))

    mx = GetMouseX()  my = GetMouseY()
    hoverBtn = 0

    bx = BTN_GAP

    // Weather presets
    presetColors = [
        RAYLIBColor(80, 130, 180, 255),
        RAYLIBColor(100, 100, 110, 255),
        RAYLIBColor(60, 80, 120, 255),
        RAYLIBColor(80, 50, 100, 255),
        RAYLIBColor(140, 150, 160, 255),
        RAYLIBColor(100, 105, 110, 255)
    ]

    for i = 1 to WEATHER_COUNT
        col = presetColors[i]
        if currentWeather = i col = RAYLIBColor(200, 190, 60, 255) ok
        bx = ws_drawBtn(weatherNames[i], bx, i, col, mx, my)
        bx += 3
    next

    bx += BTN_GAP
    DrawRectangle(bx, BTN_Y+4, 2, BTN_H-8, RAYLIBColor(60, 60, 100, 150))
    bx += BTN_GAP + 2

    bx = ws_drawBtn("Wind[W]", bx, 10, RAYLIBColor(80, 80, 100, 255), mx, my)
    bx += BTN_GAP
    bx = ws_drawBtn("Bolt[L]", bx, 11, RAYLIBColor(120, 100, 40, 255), mx, my)
    bx += BTN_GAP
    bx = ws_drawBtn("Cloud[C]", bx, 12, RAYLIBColor(80, 80, 90, 255), mx, my)
    bx += BTN_GAP
    bx = ws_drawBtn("Cycle[T]", bx, 13, RAYLIBColor(100, 80, 60, 255), mx, my)

func ws_drawBtn label, bx, btnId, baseCol, mx, my
    tw = MeasureText(label, 11) + 12
    if tw < 36 tw = 36 ok

    isHover = (mx >= bx and mx <= bx + tw and my >= BTN_Y and my <= BTN_Y + BTN_H)

    if isHover
        hoverBtn = btnId
        DrawRectangle(bx, BTN_Y, tw, BTN_H, RAYLIBColor(255, 225, 100, 240))
        DrawRectangleLines(bx, BTN_Y, tw, BTN_H, RAYLIBColor(200, 180, 60, 255))
        lw = MeasureText(label, 11)
        DrawText(label, bx + (tw-lw)/2, BTN_Y+13, 11, RAYLIBColor(20, 15, 10, 255))
    else
        DrawRectangle(bx, BTN_Y, tw, BTN_H, baseCol)
        DrawRectangleLines(bx, BTN_Y, tw, BTN_H, RAYLIBColor(255, 255, 255, 30))
        lw = MeasureText(label, 11)
        DrawText(label, bx + (tw-lw)/2, BTN_Y+13, 11, WHITE)
    ok

    return bx + tw

// =============================================================
// Toolbar Click
// =============================================================

func ws_handleToolbar mx, my
    if hoverBtn >= 1 and hoverBtn <= WEATHER_COUNT
        ws_setWeather(hoverBtn)
        return
    ok
    if hoverBtn = 10
        currentWind++
        if currentWind > WIND_COUNT currentWind = 1 ok
        windSpeed = windSpeeds[currentWind]
        return
    ok
    if hoverBtn = 11 ws_triggerLightning() return ok
    if hoverBtn = 12
        ws_addCloud(GetRandomValue(0, SCREEN_W), GetRandomValue(40, 180), 0.3)
        return
    ok
    if hoverBtn = 13
        dayCycleSpeed++
        if dayCycleSpeed > DAY_COUNT dayCycleSpeed = 1 ok
        return
    ok
