# Full Moon Prediction using Meeus Accurate Calculations
# Author: Bert Mariani + Claude with Meeus algorithms
# Date..: 2025-11-01

# --- Constants ---
PI  = 3.141592653589793
RAD = PI / 180.0

# --- DEBUG Flag ---
DEBUG = 0    # set to 1 for debug messages, 0 for results-only

# =================================
# =================================

# --- Start --- Set Start and End Year ---
func main
    see "Start main()" + nl
    MyMain(2022, 2028)        // <<<=== YEARS 
    SaveFullMoonsToCSV(2022, 2030, "fullmoons.csv")
end

# =================================
# =================================
# ---------- Main scan ----------
func MyMain(y1, y2)
    see "Full Moon Prediction (Meeus Enhanced) from " + y1 + " to " + y2 + nl
    see "JD, Date" + nl

    for year = y1 to y2
        for month = 1 to 12
            seed   = fullMoonMeeus(year, month)
            fullJD = RefineFullMoonBisection(seed)

            if fullJD < JulianDay(y1, 1, 1) or fullJD > JulianDay(y2, 12, 31)
                continue
            end

            dateStr = CalendarDate(fullJD)
            
            if DEBUG = 1
                see "DEBUG: fullJD=" + string(fullJD) + " date=" + dateStr + nl
            end
            
            see string(fullJD) + ", " + dateStr + nl
        next
    next
end

# =================================
# =================================
# ---------- Utilities ----------
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
# ---------- Time / Calendar ----------
func JulianDay(y,m,d)
    yy = y
    mm = m
    if mm <= 2
        yy = yy - 1
        mm = mm + 12
    end
    A = floor(yy/100)
    B = 2 - A + floor(A/4)
    jd = floor(365.25*(yy + 4716)) + floor(30.6001*(mm + 1)) + d + B - 1524.5

    return jd
end

# =================================
func CalendarDate(jd)
    Z = floor(jd + 0.5)
    F = (jd + 0.5) - Z
    if Z < 2299161
        A = Z
    else
        alpha = floor((Z - 1867216.25)/36524.25)
        A = Z + 1 + alpha - floor(alpha/4)
    end
    B = A + 1524
    C = floor((B - 122.1)/365.25)
    D = floor(365.25 * C)
    E = floor((B - D)/30.6001)
    dayf = B - D - floor(30.6001*E) + F
    
    if E < 14
        month = E - 1
    else
        month = E - 13
    end
    if month > 2
        year = C - 4716
    else
        year = C - 4715
    end

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
end

# =================================
# ---------- Enhanced Meeus Solar Calculation ----------
func SunLongitudeMeeus(jd)
    T  = (jd - 2451545.0)/36525.0
    
    # Mean longitude of the Sun
    L0 = 280.46646 + 36000.76983*T + 0.0003032*T*T
    
    # Mean anomaly of the Sun
    M  = 357.52911 + 35999.05029*T - 0.0001537*T*T
    L0 = DegRange(L0)
    M  = DegRange(M)
    
    # Equation of center (more terms)
    C  = (1.914602 - 0.004817*T - 0.000014*T*T)*sin(M*RAD) +
         (0.019993 - 0.000101*T)*sin(2*M*RAD) +
         0.000289*sin(3*M*RAD)
    
    # True longitude
    lon = L0 + C
    
    # Nutation in longitude (simplified)
    omega = 125.04 - 1934.136*T
    nutation = -0.00569 - 0.00478*sin(omega*RAD)
    
    lon = lon + nutation
    return DegRange(lon)
end

# =================================
# ---------- Enhanced Meeus Lunar Calculation ----------
func MoonLongitudeMeeus(jd)
    T  = (jd - 2451545.0)/36525.0
    
    # Mean longitude of the Moon
    L_prime = 218.3164477 + 481267.88123421*T - 0.0015786*T*T + T*T*T/538841.0 - T*T*T*T/65194000.0
    
    # Mean elongation of the Moon
    D = 297.8501921 + 445267.1114034*T - 0.0018819*T*T + T*T*T/545868.0 - T*T*T*T/113065000.0
    
    # Mean anomaly of the Sun
    M = 357.5291092 + 35999.0502909*T - 0.0001536*T*T + T*T*T/24490000.0
    
    # Mean anomaly of the Moon
    M_prime = 134.9633964 + 477198.8675055*T + 0.0087414*T*T + T*T*T/69699.0 - T*T*T*T/14712000.0
    
    # Argument of latitude
    F = 93.2720950 + 483202.0175233*T - 0.0036539*T*T - T*T*T/3526000.0 + T*T*T*T/863310000.0
    
    L_prime = DegRange(L_prime)
    D = DegRange(D)
    M = DegRange(M)
    M_prime = DegRange(M_prime)
    F = DegRange(F)
    
    # Main periodic terms (Meeus Table 47.A - major terms)
    lon = L_prime
    lon = lon + 6.288774 * sin(M_prime*RAD)
    lon = lon + 1.274027 * sin((2*D - M_prime)*RAD)
    lon = lon + 0.658314 * sin(2*D*RAD)
    lon = lon + 0.213618 * sin(2*M_prime*RAD)
    lon = lon - 0.185116 * sin(M*RAD)
    lon = lon - 0.114332 * sin(2*F*RAD)
    lon = lon + 0.058793 * sin((2*D - 2*M_prime)*RAD)
    lon = lon + 0.057066 * sin((2*D - M - M_prime)*RAD)
    lon = lon + 0.053322 * sin((2*D + M_prime)*RAD)
    lon = lon + 0.045758 * sin((2*D - M)*RAD)
    lon = lon - 0.040923 * sin((M - M_prime)*RAD)
    lon = lon - 0.034720 * sin(D*RAD)
    lon = lon - 0.030383 * sin((M + M_prime)*RAD)
    lon = lon + 0.015327 * sin((2*D - 2*F)*RAD)
    lon = lon - 0.012528 * sin((2*F + M_prime)*RAD)
    lon = lon + 0.010980 * sin((2*F - M_prime)*RAD)
    lon = lon + 0.010675 * sin((4*D - M_prime)*RAD)
    lon = lon + 0.010034 * sin(3*M_prime*RAD)
    lon = lon + 0.008548 * sin((4*D - 2*M_prime)*RAD)
    lon = lon - 0.007888 * sin((2*D + M - M_prime)*RAD)
    lon = lon - 0.006766 * sin((2*D + M)*RAD)
    lon = lon - 0.005163 * sin((D - M_prime)*RAD)
    
    return DegRange(lon)
end

# =================================
func SunMoonSignedDiffDeg(jd)
    sun  = SunLongitudeMeeus(jd)
    moon = MoonLongitudeMeeus(jd)
    diff = DegRange(moon - sun)
    if diff > 180
        diff = diff - 360
    end
    val = diff - 180
    if val < -180
        val = val + 360
    end
    if val > 180
        val = val - 360
    end
    return val
end

# =================================
func IsOppositionDeg(jd)
    return fabs(SunMoonSignedDiffDeg(jd))
end

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
        l = initialJD - 2.0
        r = initialJD + 2.0
        iter = 0
        while (r - l) > 0.00001 and iter < 80
            c1 = l + (r - l) * 0.382
            c2 = l + (r - l) * 0.618
            if IsOppositionDeg(c1) < IsOppositionDeg(c2)
                r = c2
            else
                l = c1
            end
            iter = iter + 1
        end
        return (l + r) / 2.0
    end

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
        end
        iter = iter + 1
    end
    return (left + right) / 2.0
end

# =================================
# ---------- Enhanced Meeus Full Moon Calculation ----------
func fullMoonMeeus(year, month)
    # Calculate k (Meeus Chapter 49)
    Y  = year + (month - 0.5) / 12.0
    k  = floor((Y - 2000) * 12.3685)
    
    # For full moon, add 0.5
    k = k + 0.5
    
    T = k / 1236.85
    T2 = T * T
    T3 = T2 * T
    T4 = T3 * T
    
    # Mean phase (JDE)
    JDE = 2451550.09766 + 29.530588861 * k + 0.00015437 * T2 - 0.000000150 * T3 + 0.00000000073 * T4
    
    # Sun's mean anomaly
    M = 2.5534 + 29.10535670 * k - 0.0000014 * T2 - 0.00000011 * T3
    M = DegRange(M)
    
    # Moon's mean anomaly
    M_prime = 201.5643 + 385.81693528 * k + 0.0107582 * T2 + 0.00001238 * T3 - 0.000000058 * T4
    M_prime = DegRange(M_prime)
    
    # Moon's argument of latitude
    F = 160.7108 + 390.67050284 * k - 0.0016118 * T2 - 0.00000227 * T3 + 0.000000011 * T4
    F = DegRange(F)
    
    # Longitude of ascending node
    omega = 124.7746 - 1.56375588 * k + 0.0020672 * T2 + 0.00000215 * T3
    omega = DegRange(omega)
    
    # Planetary arguments
    A1  = 299.77 +  0.107408 * k - 0.009173 * T2
    A2  = 251.88 +  0.016321 * k
    A3  = 251.83 + 26.651886 * k
    A4  = 349.42 + 36.412478 * k
    A5  =  84.66 + 18.206239 * k
    A6  = 141.74 + 53.303771 * k
    A7  = 207.14 +  2.453732 * k
    A8  = 154.84 +  7.306860 * k
    A9  =  34.52 + 27.261239 * k
    A10 = 207.19 +  0.121824 * k
    A11 = 291.34 +  1.844379 * k
    A12 = 161.72 + 24.198154 * k
    A13 = 239.56 + 25.513099 * k
    A14 = 331.55 +  3.592518 * k
    
    # Corrections for full moon
    correction = -0.40614 * sin(M_prime*RAD)
    correction = correction + 0.17302 * sin(M*RAD)
    correction = correction + 0.01614 * sin(2*M_prime*RAD)
    correction = correction + 0.01043 * sin(2*F*RAD)
    correction = correction + 0.00734 * sin((M_prime - M)*RAD)
    correction = correction - 0.00515 * sin((M_prime + M)*RAD)
    correction = correction + 0.00209 * sin(2*M*RAD)
    correction = correction - 0.00111 * sin((M_prime - 2*F)*RAD)
    correction = correction - 0.00057 * sin((M_prime + 2*F)*RAD)
    correction = correction + 0.00056 * sin((2*M_prime + M)*RAD)
    correction = correction - 0.00042 * sin(3*M_prime*RAD)
    correction = correction + 0.00042 * sin((M + 2*F)*RAD)
    correction = correction + 0.00038 * sin((M - 2*F)*RAD)
    correction = correction - 0.00024 * sin((2*M_prime - M)*RAD)
    correction = correction - 0.00017 * sin(omega*RAD)
    correction = correction - 0.00007 * sin((M_prime + 2*M)*RAD)
    correction = correction + 0.00004 * sin((2*M_prime - 2*F)*RAD)
    correction = correction + 0.00004 * sin(3*M*RAD)
    correction = correction + 0.00003 * sin((M_prime + M - 2*F)*RAD)
    correction = correction + 0.00003 * sin((2*M_prime + 2*F)*RAD)
    correction = correction - 0.00003 * sin((M_prime + M + 2*F)*RAD)
    correction = correction + 0.00003 * sin((M_prime - M + 2*F)*RAD)
    correction = correction - 0.00002 * sin((M_prime - M - 2*F)*RAD)
    correction = correction - 0.00002 * sin((3*M_prime + M)*RAD)
    correction = correction + 0.00002 * sin(4*M_prime*RAD)
    
    JDE = JDE + correction
    
    # Additional planetary corrections
    JDE = JDE + 0.000325 * sin(A1*RAD)
    JDE = JDE + 0.000165 * sin(A2*RAD)
    JDE = JDE + 0.000164 * sin(A3*RAD)
    JDE = JDE + 0.000126 * sin(A4*RAD)
    JDE = JDE + 0.000110 * sin(A5*RAD)
    JDE = JDE + 0.000062 * sin(A6*RAD)
    JDE = JDE + 0.000060 * sin(A7*RAD)
    JDE = JDE + 0.000056 * sin(A8*RAD)
    JDE = JDE + 0.000047 * sin(A9*RAD)
    JDE = JDE + 0.000042 * sin(A10*RAD)
    JDE = JDE + 0.000040 * sin(A11*RAD)
    JDE = JDE + 0.000037 * sin(A12*RAD)
    JDE = JDE + 0.000035 * sin(A13*RAD)
    JDE = JDE + 0.000023 * sin(A14*RAD)
    
    return JDE
end

# =================================
# --- Output CSV ---
func SaveFullMoonsToCSV(y1, y2, filename)
    fh = fopen(filename, "w")
    if fh = NULL
        see "Error opening file!" + nl
        return
    end

    fwrite(fh, "JD, Date" + nl)

    for year = y1 to y2
        for month = 1 to 12
            seed   = fullMoonMeeus(year, month)
            fullJD = RefineFullMoonBisection(seed)

            if fullJD < JulianDay(y1, 1, 1) or fullJD > JulianDay(y2, 12, 31)
                continue
            end

            dateStr = CalendarDate(fullJD)
            line = string(fullJD) + ", " + dateStr + nl
            fwrite(fh, line)
        next
    next

    fclose(fh)
    see "Saved to " + filename + nl
end



////////////////////////////////////
/*

Complete Comparison Table: 
RingCode vs NASA/AstroPixels Data (2022-2028)           
            
2022 Full Moons         
            
Ring Code   NASA/Espenak (UTC)  Difference  Status
2022-01-17 23:53    2022-01-17 23:49    +4 min  ✅
2022-02-16 17:00    2022-02-16 16:57    +3 min  ✅
2022-03-18  7:19    2022-03-18  7:17    +2 min  ✅
2022-04-16 18:54    2022-04-16 18:55    -0 min  ✅
2022-05-16  4:12    2022-05-16  4:14    -1 min  ✅
2022-06-14 11:49    2022-06-14 11:52    -2 min  ✅
2022-07-13 18:36    2022-07-13 18:37    -1 min  ✅
2022-08-12  1:35    2022-08-12  1:36    -1 min  ✅
2022-09-10 10:00    2022-09-10  9:59    +2 min  ✅
2022-10-09 20:58    2022-10-09 20:55    +3 min  ✅
2022-11-08 11:07    2022-11-08 11:02    +5 min  ✅
2022-12-08  4:12    2022-12-08  4:08    +5 min  ✅
            
2023 Full Moons         
            
RingCode    NASA/Espenak (UTC)  Difference  Status
2023-01-06 23:11    2023-01-06 23:08    +3 min  ✅
2023-03-07 12:40    2023-03-07 12:40    +1 min  ✅
2023-04-06  4:33    2023-04-06  4:34    -1 min  ✅
2023-05-05 17:32    2023-05-05 17:34    -1 min  ✅
2023-06-04  3:41    2023-06-04  3:42    -1 min  ✅
2023-07-03 11:39    2023-07-03 11:39    +1 min  ✅
2023-08-01 18:34    2023-08-01 18:32    +2 min  ✅
2023-08-31  1:40    2023-08-31  1:35    +5 min  ✅
2023-09-29 10:02    2023-09-29  9:58    +5 min  ✅
2023-10-28 20:28    2023-10-28 20:24    +5 min  ✅
2023-11-27  9:19    2023-11-27  9:16    +3 min  ✅
2023-12-27  0:33    2023-12-27  0:33    +1 min  ✅
            
2024 Full Moons         
            
RingCode    NASA/Espenak (UTC)  Difference  Status
2024-01-25 17:52    2024-01-25 17:54    -2 min  ✅
2024-02-24 12:28    2024-02-24 12:30    -2 min  ✅
2024-03-25  7:00    2024-03-25  7:00    +0 min  ✅
2024-04-23 23:51    2024-04-23 23:49    +2 min  ✅
2024-05-23 13:57    2024-05-23 13:53    +4 min  ✅
2024-06-22  1:11    2024-06-22  1:08    +4 min  ✅
2024-07-21 10:20    2024-07-21 10:17    +4 min  ✅
2024-08-19 18:29    2024-08-19 18:26    +3 min  ✅
2024-09-18  2:38    2024-09-18  2:34    +4 min  ✅
2024-10-17 11:29    2024-10-17 11:26    +3 min  ✅
2024-11-15 21:29    2024-11-15 21:28    +2 min  ✅
2024-12-15  9:01    2024-12-15  9:02    -0 min  ✅
            
2025 Full Moons         
            
RingCode    NASA/Espenak (UTC)  Difference  Status
2025-01-13 22:27    2025-01-13 22:27    +0 min  ✅
2025-02-12 13:55    2025-02-12 13:53    +2 min  ✅
2025-03-14  6:57    2025-03-14  6:54    +3 min  ✅
2025-04-13  0:25    2025-04-13  0:22    +4 min  ✅
2025-05-12 17:01    2025-05-12 16:55    +6 min  ✅
2025-06-11  7:49    2025-06-11  7:43    +6 min  ✅
2025-07-10 20:39    2025-07-10 20:36    +3 min  ✅
2025-08-09  7:54    2025-08-09  7:54    +0 min  ✅
2025-09-07 18:07    2025-09-07 18:08    -1 min  ✅
2025-11-05 13:21    2025-11-05 13:19    +2 min  ✅
2025-12-04 23:16    2025-12-04 23:14    +2 min  ✅
            
2026 Full Moons         
            
RingCode    NASA/Espenak (UTC)  Difference  Status
2026-01-03 10:05    2026-01-03 10:03    +2 min  ✅
2026-02-01 22:13    2026-02-01 22:09    +4 min  ✅
2026-03-03 11:43    2026-03-03 11:38    +5 min  ✅
2026-04-02  2:16    2026-04-02  2:12    +5 min  ✅
2026-05-01 17:25    2026-05-01 17:23    +2 min  ✅
2026-05-31  8:45    2026-05-31  8:45    +1 min  ✅
2026-06-29 23:57    2026-06-29 23:57    +0 min  ✅
2026-07-29 14:35    2026-07-29 14:36    -0 min  ✅
2026-08-28  4:17    2026-08-28  4:17    +0 min  ✅
2026-09-26 16:48    2026-09-26 16:49    -0 min  ✅
2026-10-26  4:14    2026-10-26  4:12    +2 min  ✅
2026-11-24 14:58    2026-11-24 14:53    +6 min  ✅
2026-12-24  1:33    2026-12-24  1:28    +5 min  ✅
            
2027 Full Moons         
            
RingCode    NASA/Espenak (UTC)  Difference  Status
2027-01-22 12:19    2027-01-22 12:17    +3 min  ✅
2027-02-20 23:24    2027-02-20 23:23    +1 min  ✅
2027-03-22 10:44    2027-03-22 10:43    +2 min  ✅
2027-04-20 22:28    2027-04-20 22:27    +1 min  ✅
2027-05-20 10:57    2027-05-20 10:59    -1 min  ✅
2027-06-19  0:42    2027-06-19  0:44    -2 min  ✅
2027-07-18 15:45    2027-07-18 15:45    +0 min  ✅
2027-08-17  7:32    2027-08-17  7:28    +4 min  ✅
2027-09-15 23:08    2027-09-15 23:03    +5 min  ✅
2027-10-15 13:50    2027-10-15 13:47    +4 min  ✅
2027-11-14  3:29    2027-11-14  3:27    +3 min  ✅
2027-12-13 16:12    2027-12-13 16:09    +3 min  ✅
            
2028 Full Moons         
            
RingCode    NASA/Espenak (UTC)  Difference  Status
2028-01-12 4:04 2028-01-12 4:03 +2 min  ✅
2028-02-10 15:01    2028-02-10 15:04    -2 min  ✅
2028-03-11  1:02    2028-03-11  1:05    -2 min  ✅
2028-04-09 10:25    2028-04-09 10:26    -0 min  ✅
2028-05-08 19:50    2028-05-08 19:48    +3 min  ✅
2028-06-07  6:11    2028-06-07  6:03    +9 min  ⚠️
2028-08-05  8:13    2028-08-05  8:11    +3 min  ✅
2028-09-03 23:52    2028-09-03 23:47    +6 min  ✅
2028-10-03 16:29    2028-10-03 16:25    +5 min  ✅
2028-11-02  9:19    2028-11-02  9:18    +1 min  ✅
2028-12-02  1:39    2028-12-02  1:41    -2 min  ✅
