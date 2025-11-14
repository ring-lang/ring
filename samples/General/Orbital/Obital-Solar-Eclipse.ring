# Solar Eclipse Predictor using Meeus Algorithms
# Predicts Solar Eclipse and Type: Total, Annular, Hybred, Partial
# For Year 2022-2026
#
# Author: Bert Mariani + Claude AI - Meeus Tables and Calculations
# Date..: 2025-10-12
#
#   TOTAL SOLAR ECLIPSE - Occurs when the Moon is close enough to Earth( near perigee) 
#   that its apparent size is larger than the Sun's, 
#   AND the Moon passes directly between Earth and Sun (low gamma value). 
#   The Moon doesn't have to be exactly at perigee.
#   
#   ANNULAR SOLAR ECLIPSE - Occurs when the Moon is farther from Earth (near apogee)
#   so its apparent size is smaller than the Sun's,
#   AND the Moon passes directly between Earth and Sun (low gamma value). 
#   The Moon doesn't have to be exactly at apogee.
#   
#   PARTIAL SOLAR ECLIPSE - Occurs when the alignment is NOT direct - 
#   the Moon passes above or below the centerline (high gamma value), 
#   so only part of the Sun is covered as seen from Earth.
#   
#   HYBRID ECLIPSE - A rare case where the eclipse appears annular at some locations 
#   and total at others due to Earth's curvature.
# =================================================

load "stdlibcore.ring"

# Constants
PI = 3.14159265358979323846

# ===================================
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
    
    A  = floor(year / 100)
    B  = 2 - A + floor(A / 4)
    jd = floor(365.25 * (year + 4716)) + floor(30.6001 * (month + 1)) + day + B - 1524.5
    
    return jd

# ===================================
func new_moon_k(year)
    return (year - 2000.0) * 12.3685

# ===================================
func mean_new_moon(k)
    T  = k / 1236.85
    T2 = T  * T
    T3 = T2 * T
    T4 = T3 * T
    
    jde = 2451550.09766 + 29.530588861 * k + 
          0.00015437    * T2 - 
          0.000000150   * T3 + 
          0.00000000073 * T4
          
    return jde

# ===================================
func sun_anomaly(k, T)
    angle = 2.5534 + 29.10535670 * k - 
            0.0000014  * T * T - 
            0.00000011 * T * T * T
    
    return normalize_angle(angle)

# ===================================
func moon_anomaly(k, T)
    T2 = T  * T
    T3 = T2 * T
    T4 = T3 * T
    angle = 201.5643 + 385.81693528 * k + 
            0.0107582   * T2 + 
            0.00001238  * T3 - 
            0.000000058 * T4
    
    return normalize_angle(angle)

# ===================================
func moon_argument(k, T)
    T2 = T  * T
    T3 = T2 * T
    T4 = T3 * T
    angle = 160.7108 + 390.67050284 * k - 
            0.0016118   * T2 - 
            0.00000227  * T3 + 
            0.000000011 * T4
    return normalize_angle(angle)

# ===================================
func moon_node(k, T)
    T2 = T  * T
    T3 = T2 * T
    angle = 124.7746 - 1.56375588 * k + 
            0.0020672  * T2 + 
            0.00000215 * T3
    
    return normalize_angle(angle)

# ===================================
func calculate_eclipse(k)
    T  = k / 1236.85
    T2 = T * T
    T3 = T2 * T
    
    JDE = mean_new_moon(k)
    
    M     = deg2rad(sun_anomaly(k, T))
    Mp    = deg2rad(moon_anomaly(k, T))
    F     = deg2rad(moon_argument(k, T))
    Omega = deg2rad(moon_node(k, T))
    
    E = 1.0 - 0.002516 * T - 0.0000074 * T2
    
    #--- Check if Moon is near a node (F near 0° or 180°)
    F_deg       = moon_argument(k, T)
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
                 0.17241 * E * sin(M) +
                 0.01608 * sin(2.0 * Mp) +
                 0.01039 * sin(2.0 * F) +
                 0.00739 * E * sin(Mp - M) -
                 0.00514 * E * sin(Mp + M) +
                 0.00208 * E * E * sin(2.0 * M) -
                 0.00111 * sin(Mp - 2.0 * F) -
                 0.00057 * sin(Mp + 2.0 * F) +
                 0.00056 * E * sin(2.0 * Mp + M) -
                 0.00042 * sin(3.0 * Mp) +
                 0.00042 * E * sin(M + 2.0 * F) +
                 0.00038 * E * sin(M - 2.0 * F) -
                 0.00024 * E * sin(2.0 * Mp - M) -
                 0.00017 * sin(Omega) -
                 0.00007 * sin(Mp + 2.0 * M) +
                 0.00004 * sin(2.0 * Mp - 2.0 * F) +
                 0.00004 * sin(3.0 * M) +
                 0.00003 * sin(Mp + M - 2.0 * F) +
                 0.00003 * sin(2.0 * Mp + 2.0 * F) -
                 0.00003 * sin(Mp + M + 2.0 * F) +
                 0.00003 * sin(Mp - M + 2.0 * F) -
                 0.00002 * sin(Mp - M - 2.0 * F) -
                 0.00002 * sin(3.0 * Mp + M) +
                 0.00002 * sin(4.0 * Mp)
    
    JDE += correction
    
    #--- Calculate P, Q, W for gamma (intermediate values)
    P = 0.2070 * E * sin(M) +
        0.0024 * E * sin(2.0 * M) -
        0.0392 * sin(Mp) +
        0.0116 * sin(2.0 * Mp) -
        0.0073 * E * sin(Mp + M) +
        0.0067 * E * sin(Mp - M) +
        0.0118 * sin(2.0 * F)
    
    Q = 5.2207 -
        0.0048 * E * cos(M) +
        0.0020 * E * cos(2.0 * M) -
        0.3299 * cos(Mp) -
        0.0060 * E * cos(Mp + M) +
        0.0041 * E * cos(Mp - M)
    
    W = fabs(cos(F))
    
    #--- Calculate gamma (least distance from shadow axis to Earth center)
    gamma = (P * cos(F) + Q * sin(F)) * (1.0 - 0.0048 * W)
    
    # Calculate u (radius of Moon's umbral cone in fundamental plane)
    u = 0.0059 +
        0.0046 * E * cos(M) -
        0.0182 * cos(Mp) +
        0.0004 * cos(2.0 * Mp) -
        0.0005 * cos(M + Mp)
    
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
            w = 0.00464 * sqrt(1.0 - gamma * gamma)
            
            if u < w
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
    z = floor(jde + 0.5)
    f = (jde + 0.5) - z
    
    alpha = floor((z - 1867216.25) / 36524.25)
    a = z + 1 + alpha - floor(alpha / 4.0)
    
    b = a + 1524
    c = floor((b - 122.1) / 365.25)
    d = floor(365.25 * c)
    e = floor((b - d) / 30.6001)
    
    day = floor(b - d - floor(30.6001 * e))
    
    if e < 14
        month = floor(e - 1)
    else
        month = floor(e - 13)
    ok
    
    if month > 2
        year = floor(c - 4716)
    else
        year = floor(c - 4715)
    ok
    
    day_fraction = f
    hour   = floor(day_fraction * 24)
    minute = floor((day_fraction * 24 - hour) * 60)
    
    return [year, month, day, hour, minute]


# ===================================
func print_nasa_table()
    see nl
    see "=============================================" + nl
    see "NASA SOLAR ECLIPSE DATA (2022-2026)" + nl
    see "=============================================" + nl
    see nl
    
    see "2022:" + nl
    see "  Apr 30, 2022  20:42:36  - Partial" + nl
    see "  Oct 25, 2022  11:01:19  - Partial" + nl
    see nl
    
    see "2023:" + nl
    see "  Apr 20, 2023  04:17:55  - Hybrid (Total/Annular)" + nl
    see "  Oct 14, 2023  18:00:40  - Annular" + nl
    see nl
    
    see "2024:" + nl
    see "  Apr 08, 2024  18:18:29  - Total" + nl
    see "  Oct 02, 2024  18:46:13  - Annular" + nl
    see nl
    
    see "2025:" + nl
    see "  Mar 29, 2025  10:48:36  - Partial" + nl
    see "  Sep 21, 2025  19:43:04  - Partial" + nl
    see nl
    
    see "2026:" + nl
    see "  Feb 17, 2026  12:13:05  - Annular" + nl
    see "  Aug 12, 2026  17:47:05  - Total" + nl
    see nl
    
    see "Total: 10 solar eclipses" + nl
    see "=============================================" + nl
    see nl

# ===================================
func main()
    see "=============================================" + nl
    see "SOLAR ECLIPSE PREDICTOR (2022-2026)" + nl
    see "Using Jean Meeus Astronomical Algorithms" + nl
    see "=============================================" + nl
    see nl
    
    start_year = 2022
    end_year   = 2026
    
    k_start = floor(new_moon_k(start_year))
    k_end   = ceil(new_moon_k(end_year + 1))
    eclipse_count = 0
     
 
    OldYear = -5000
    See"              Date:         Time:      Type:     Mag:  Gamma:  u-value:"+nl 
    
    for k = k_start to k_end
        result       = calculate_eclipse(k)
        has_eclipse  = result[1]
        jde          = result[2]
        eclipse_type = result[3]
        gamma        = result[4]
        magnitude    = result[5]
        u_val        = result[6]
        
        if has_eclipse = 1
            date_result = jde_to_date(jde)
            year        = date_result[1]
            month       = date_result[2]
            day         = date_result[3]
            hour        = date_result[4]
            minute      = date_result[5]
            


            if year >= start_year and year <= end_year
                eclipse_count += 1
                
                if eclipse_count < 10
                   sEclipse_count = "0" + eclipse_count  // string 09
                else 
                   sEclipse_count  = "" + eclipse_count
                ok   
                
                if year > OldYear
                   See nl
                ok
                
                see "Eclipse #" + sEclipse_count + ":"
                
                see "  "  + year + "-"  +                      // Year
                    right("0" + string(month), 2)  + "-" +     // Month 
                    right("0" + string(day), 2)    + " at " +  // Day
                    right("0" + string(hour), 2)   + ":" +     // Hour
                    right("0" + string(minute), 2) + " UTC"    // Minute
                    
                see "  "  + eclipse_type              // Type: "    
                see "  "  + magnitude                 // Magnitude:

                if gamma > 0
                   gamma = " "+ gamma                 // Alignment
                ok
                see "  "  + gamma                     // Gamma: "  

                if u_val > 0
                   u_val = " "+ u_val                 // Alignment
                ok
                
                see "  "  + u_val                     // u-value: " 
                see nl
                
                OldYear = Year
            ok
        ok
    next
    
    see nl+"---------------------------------------------" + nl
    see "Total solar eclipses predicted: " + eclipse_count + nl
    see "=============================================" + nl
    
    print_nasa_table()


# ===================================
#   NASA 
#   https://eclipse.gsfc.nasa.gov/SEdecade/SEdecade2021.html
/*

DATE            TIME            TYPE        MAGNITUDE
2022 Apr 30 20:42:36    Partial     0.640   
2022 Oct 25 11:01:19    Partial     0.862   

2023 Apr 20 04:17:55    Hybrid      1.013   
2023 Oct 14 18:00:40    Annular     0.952   

2024 Apr 08 18:18:29    Total       1.057   
2024 Oct 02 18:46:13    Annular     0.933   

2025 Mar 29 10:48:36    Partial     0.938   
2025 Sep 21 19:43:04    Partial     0.855   

2026 Feb 17 12:13:05    Annular     0.963   
2026 Aug 12 17:47:05    Total       1.039   

2027 Feb 06 16:00:47    Annular     0.928   
2027 Aug 02 10:07:49    Total       1.079   

2028 Jan 26 15:08:58    Annular     0.921   
2028 Jul 22 02:56:39    Total       1.056   

2029 Jan 14 17:13:47    Partial     0.871   
2029 Jun 12 04:06:13    Partial     0.458   
2029 Jul 11 15:37:18    Partial     0.230   
2029 Dec 05 15:03:57    Partial     0.891   

2030 Jun 01 06:29:13    Annular     0.944   
2030 Nov 25 06:51:37    Total       1.047   


