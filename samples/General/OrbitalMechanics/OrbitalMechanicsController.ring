# Form/Window Controller - Source Code File
//=====================================================
//
// Author: Bert Mariani
// Date:   2022-Oct-25
//
//=====================================================


load "OrbitalMechanicsView.ring"

import System.GUI

if IsMainSourceFile() {
   new App {
      StyleFusion()
      openWindow(:OrbitalMechanicsController)
      exec()
   }
}


class OrbitalMechanicsController from windowsControllerParent

   oView = new OrbitalMechanicsView


//==========================================================
// Author: Bert Mariani
// Date:   2022-Oct-25
//
// https://map.gsfc.nasa.gov/ContentMedia/lagrange.pdf  Lagrange.pdf  // Document()
//
// G     = 6.67384 * (10^^-11) * m^^3 / (kg * s^^2)  // Gravity constant
// R1    = 149597871               // Sun-Earth  km =  AU
// M1    = 1.98855 * (10^^30)      // Sun-mass   kg
// M2    = 5.97219 * (10^^24)      // Earth-mass kg
// r1    = 1496525                 // L1 from Earth 1496525
//
// C     = 449                     // Baycenter km from center of Sun to Earth
// T     = 365.21                  // Rotation of Earth days

//===========================================================
// Fill in Table defined in oView. Not column 1 (Need for Mass calculations)


Populate =[[1.9891*(10^^30), "Sun",     "1.9891^30",           0, 1, 2, 3, 4, 5],
           [5.9736*(10^^24), "Earth",   "5.9736^24",   149597871, 1481013, 1510944, 149597933, 74798486, 129555557 ],
           [7.3476*(10^^22), "Moon",    "7.3476^22",      384400, 1, 2, 3, 4, 5],
           [3.3000*(10^^23), "Mercury", "3.3000^23",    57894376, 1, 2, 3, 4, 5],
           [4.8700*(10^^24), "Venus",   "4.8700^24",   108159261, 1, 2, 3, 4, 5],
           [6.4170*(10^^23), "Mars",    "6.4170^23",   227987155, 1, 2, 3, 4, 5],
           [9.1000*(10^^20), "Ceres",   "9.1000^20",   413937309, 1, 2, 3, 4, 5],
           [1.8981*(10^^27), "Jupiter", "1.8981^27",   778547200, 1, 2, 3, 4, 5],
           [5.6830*(10^^26), "Saturn",  "5.6830^26",  1433446800, 1, 2, 3, 4, 5],
           [8.6810*(10^^25), "Uranus",  "8.6810^25",  2872428721, 1, 2, 3, 4, 5],
           [1.0200*(10^^26), "Neptune", "1.0200^26",  4494967230, 1, 2, 3, 4, 5],
           [1.2000*(10^^22), "Pluto",   "1.2000^22",  5913603841, 1, 2, 3, 4, 5],
           [1.6700*(10^^22), "Eris",    "1.6700^22", 10166372117, 1, 2, 3, 4, 5],
           [6.0000*(10^^21), "Sedna",   "6.0000^21", 77576967964, 1, 2, 3, 4, 5]
          ]

for v = 1 to len(Populate)
   for h = 1 to 9
       Body = Populate[v][h]
       if h = 1  Body = "-" ok

      item1 = new qTableWidgetItem(""+Body)  // need alpha ("H"+X+"-Y"+Y)
      oView.TableWidget1.setitem(v,h,item1)
   next
next

//==========================================================
// Calculate L1-L5 for all Planets

decimals(0)

M1   = 1.98855 * (10^^30)             // Sun-Mass
for v = 2 to len(Populate)

   Planet   = oView.TableWidget1.item(v,2).text()    // Planet
   Mass     = Populate[v][1]                         // Mass value from column 1
   Distance = oView.TableWidget1.item(v,4).text()    // Distance

   if Planet = "Moon"   Mass = 5.9736*(10^^24)  ok   // Earth-Mass to Moon

   M2   = Mass                   // Planet kg
   R1   = Distance               // Sun-to-Planet km
   P1   = Planet                 // Planet Name
   Size = M1 / M2                // Ratio of Sun / Planet

   See "Planet "+Planet +" R1: "+R1 +" M1: "+ M1 +" M2: "+ M2 +" Size: "+ Size +nl

   //===================================
   // Calculate the Lagrange Point L1-L5

    LV = CalcPlanet(R1, M1, M2 )         // return [L1,L2,L3,L4,L5]

   //===================================
   // Fill in the Table with Results

   i = 1
   for h = 5 to 9
      if i <= 3
              Body = ""+ LV[i]       // L1,L2,L3
      elseif i = 4
              Body = ""+ LV[i][1]    // L4,L5 have 2 values. Calc Triangle 60 degrees
      else
              Body = ""+ LV[i][2]
      ok
      i++

      item1 = new qTableWidgetItem(Body)        // 1-5 [L1,L2,L3,L4,L5]
      oView.TableWidget1.setitem(v,h,item1)
   next
next


//===================================================================
// https://map.gsfc.nasa.gov/ContentMedia/lagrange.pdf  Lagrange.pdf

Func CalcPlanet(R1, M1, M2 )

   L1   = CalcL1( R1, M1, M2 )
   L2   = CalcL2( R1, M1, M2 )
   L3   = CalcL3( R1, M1, M2 )
   L4   = CalcL4( R1, M1, M2 )
   L5   = CalcL5( R1, M1, M2 )
   //     ProofL4(R1, L4[1]  )          // Prove angle 60 degrees for L4 and L5

    See "R1:  "+ R1 +nl +
   "L1:  "+ L1 +nl +
   "L2:  "+ L2 +nl +
   "L3:  "+ L3 +nl +
   "L4x: "+ L4[1] +" L4y:  "+ L4[2] +nl +
   "L5x: "+ L5[1] +" L5y: "+  L5[2] +nl+nl

return   [L1,L2,L3,L4,L5]

//==================================================
// Calculate L1 to L5 Functions

Func CalcL1( R1, M1, M2)
   a  = M2/(3*M1)                             // Ratio Planet to Sun
   r2 = R1 * ( 1 - ( a ^^ (1/3) ) ) / 100
   //See " L1 R1: "+ R1 +nl // +" Sun..: "+ M1 +nl +" Earth: "+ M2 +nl
   //See " L1-r2:   "+ r2 +nl+nl
return r2

//-----------------------

Func CalcL2( R1, M1, M2)
   a  = M2/(3*M1)
   r2 = R1 * ( 1 + ( a ^^ (1/3) ) ) / 100
   //See " L2 R1: "+ R1 +nl // +" Sun..: "+ M1 +nl +" Earth: "+ M2 +nl
   //See " L2-r2:   "+ r2 +nl+nl
return r2

//-----------------------

Func CalcL3( R1, M1, M2)
   a  = M2/(3*M1)
   r2 = R1 * ( 1 + ( a * (5/12) ) )
   //See " L3 R1: "+ R1 +nl // +" Sun..: "+ M1 +nl +" Earth: "+ M2 +nl
   //See " L3-r2: "+ r2 +nl+nl
return r2

//-----------------------

Func CalcL4( R1, M1, M2)
   r2 = (R1/2) * ( (M1-M2)/(M1+M2) )              // cos
   s2 = ( (3^^(1/2)) / 2 ) * R1                   // sin
   //See " L4 R1:   "+ R1 +nl // +" Sun..: "+ M1 +nl +" Earth: "+ M2 +nl
   //See " L4-r2-x:  "+ r2 +nl
   //See " L4-s2-y: "+ s2 +nl+nl
   
   ProofL4(R1, r2  )                              // Prove angle 60 degrees
return [r2,s2]

//-----------------------

Func CalcL5( R1, M1, M2)
   r2 = (R1/2) * ( (M1-M2)/(M1+M2) )              // cos
   s2 = ( -(3^^(1/2)) / 2 ) * R1        // sin
   //See " L5 R1:    "+ R1 +nl // +" Sun..: "+ M1 +nl +" Earth: "+ M2 +nl
   //See " L5-r2-x:   "+ r2 +nl
   //See " L5-s2-y: "+ s2 +nl+nl
return [r2,s2]

//-----------------------

//=====================================================================================
// R1-hypotenuse: 149,597,871  r1-x-horizontal: 74,798,486   s1-y-vertical: 129,555,557
// Angle A-C-B = 60 degrees
//       A           A
//      /|          /|\
//     / |         / | \
//    /__|        /__|__\
//   C    B     Sun     Earth

Func ProofL4(R1,r2)
   decimals(4)
   radian = 57.296   // radian in degrees

   t1  = r2/R1       // y/h
   rad = asin(t1)
   deg = rad * radian
   ang = 90 - deg
   See "L4 Proof Angle A-C-B: R1: "+ R1 +" r2: "+ r2 +" aSin("+ t1 +") Rad: "+ rad  +" degA: "+ deg +" => degC "+ ang +" degB: 90" +nl+nl
        decimals(0)
return



//============================================
//============================================
// Data - varies between reference sites
//
// Planet  =[
//  [AU,        DistAU,        km,                 kg ],
//  [Sun,       0,              0,   1.9891 * (10^^30)],
//  [Earth,     1.000,   149597871,  5.9736 * (10^^24)],
//  [Moon,      0.00257,    384400,  7.3476 * (10^^22)],
//  [Jupiter,   5.203,   778357723, 18.981 * (10^^26)],
//  [Mercury,   0.387,    57894376,  3.3   * (10^^23)],
//  [Venus,     0.723,   108159261,  4.87  * (10^^24)],
//  [Mars,      1.524,   227987155,  6.417 * (10^^23)],
//  [Saturn,    9.582,  1433446800,  5.683 * (10^^26)],
//  [Uranus,   19.201,  2872428721,  8.681 * (10^^25)],
//  [Neptune,  30.047,  4494967230,  1.02  * (10^^26)],
//  [Ceres,     2.767,   413937309,  9.1   * (10^^20)],
//  [Pluto,    39.530,  5913603841,  1.2   * (10^^22)],
//  [Eris,     67.958, 10166372117,  1.67  * (10^^22)],
//  [Sedna,   518.570, 77576967964,  6.0   * (10^^21)]
// ]


////==========================================================
// Lagrangian points in Solar System: x10^9 m
// Body pair       Semimajor   L1        1−L1/SMA(%)  L2      L2/SMA−1(%)  L3        1+L3/SMA(%)
//                 axis-SMA
// Earth–Moon         0.3844      0.32639  15.09       0.4489  16.78         −0.38168 0.7084
// Sun–Mercury       57.909      57.689   0.3806      58.13   0.3815        −57.909   0.000009683
// Sun–Venus        108.21      107.2     0.9315     109.22   0.9373       −108.21    0.0001428
// Sun–Earth        149.6       148.11    0.997      151.1    1.004        −149.6     0.0001752
// Sun–Mars         227.94      226.86    0.4748     229.03   0.4763       −227.94    0.00001882
// Sun–Jupiter      778.34      726.45    6.667      832.65   6.978        −777.91    0.05563
// Sun–Saturn      1426.7      1362.5     4.496      1492.8   4.635       −1426.4     0.01667
// Sun–Uranus      2870.7      2801.1     2.421      2941.3   2.461       −2870.6     0.002546
// Sun–Neptune     4498.4      4383.4     2.557      4615.4   2.602       −4498.3     0.003004
//
//==========================================================
