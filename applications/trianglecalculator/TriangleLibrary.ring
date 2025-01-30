// Triangle Libray with 5 Functions 
// Solve Triangles for missing Angles and Sides - etc 22 Values
//
// Bert Mariani  2024-11-12
// Returns Array with ANGLES aA aB aC and SIDES sA sB sC etc
//
// Function:
// aTri = TriangleAAS(35,62, 7)  Angle Angle Side  aA,aC,sC  TWO Agnles and a Side NOT BETWEEN
// aTri = TriangleASA(76, 9,34)  Angle Side  Angle aA,sC,aB  TWO Angles and ONE Side BETWEEN
// aTri = TriangleSAS( 5,49, 7)  Side  Angle Side  sb,aA,sC  TWO Sides and ONE Angle BETWEEN
// aTri = TriangleSSA( 8,13,31)  Side  Side  Angle sb,sC,aB  TWO Sides and ONE angle NOT BETWEEN
// aTri = TriangleSSS( 8, 6, 7)  Side  Side  Side  sA,sB,sC  THREE Sides Find the MISSING ANGLES
//        TrianglePrintData(aAngleSide)                      Print Data Array Return
//        TriangleAAA()                                      THREE Angles and ZERO Sides can NOT be Solved 
//-------------------------------------------------

load "stdlibcore.ring"

decimals(5)
PI         = 3.14159265
aAngleSide = list(32)                   // GLOBAL for IN 6 --> OUT 32 Values
TriMsg     = "Trangle Library Msg:                   "  // For Angle / Side = 0 invalid


//==============================================
//==============================================
// TWO ANGLES AND A SIDE NOT BETWEEN
//         aC=62
//         /\
//   sB=? /   \
//       /      \  sA=?
//      /         \
//   aA=35--------aB=?
//         sC=7
//--------------------------------
// Degree to Radian to Degree
// arA = aA  * PI/180      // Rad aA: 35 arA: 0.6109 adA: 35     
// arB = aB  * PI/180      // Rad aB: 83 arB: 1.4486 adB: 83
// arC = aC  * PI/180      // Rad aC: 62 arC: 1.0821 adC: 62.0000
//                      
// adA = arA * 180/PI      // Deg
// adB = arB * 180/PI      // Deg
// adC = arC * 180/PI      // Deg
//-------------------------------
// To solve an AAS triangle
// Use the three angles add to 180° to find the other angle
// Then The Law of Sines to find each of the other two sides.
//
// TWO ANGLES AND A SIDE NOT BETWEEN
//----------------------------------------------------------

Func TriangleAAS(aA,aC,sC)

    if !(isnumber(aA))  0+ aA  See "Convert to Number aA: "+aA +nl  ok
	if !(isnumber(aC))  0+ aC  See "Convert to Number aC: "+aC +nl  ok
    if !(isnumber(sC))  0+ sC  See "Convert to Number sC: "+sC +nl  ok
	
	if aA = 0  See "TriAAS Invalid Angle-A: 0" +nl  return 1 ok
	if aC = 0  See "TriAAS Invalid Angle-C: 0" +nl  return 1 ok
	if sC = 0  See "TriAAS Invalid Side-C: 0"  +nl  return 1 ok

    aB = 180 - aA - aC                  // Have 2 angles in degrees
    
    arA = aA  * PI/180
    arC = aC  * PI/180
    sA  = (sin(arA)) * (sC/sin(arC))    // Use RAD: 
      
    arB = aB  * PI/180
    sB  = (sin(arB)) * (sC/sin(arC))    // Use RAD:     
 
    adA = aA                            // Angle degree
    adB = aB
    adC = aC  
      
    aAngleSide[1] = adA
    aAngleSide[2] = adB
    aAngleSide[3] = adc
    aAngleSide[4] = sA
    aAngleSide[5] = sB
    aAngleSide[6] = sC
    
    TriangleMoreValues( aAngleSide)  // 6 values + 16 more
    
Return  aAngleSide                   // 22 values

//================================================
//================================================

// TWO ANGLES AND A SIDE BETWEEN
//         aC=?
//         /\
//   sB=9 /   \
//       /      \  sA=?
//      /         \
//   aA=76---------aB=?
//         sC=9
//-------------------------
// To solve an ASA Triangle
// Find the third angle using the three angles add to 180°
// Then use The Law of Sines to find each of the other two sides.
//
// TWO ANGLES AND A SIDE BETWEEN
//--------------------------------

Func TriangleASA(aA,sC,aB)

	if !(isnumber(aA))  0+ aA  See "Convert to Number aA: "+aA +nl  ok
	if !(isnumber(sC))  0+ sC  See "Convert to Number sC: "+sC +nl  ok
    if !(isnumber(aB))  0+ aB  See "Convert to Number aB: "+aB +nl  ok

	if aA = 0  TriMsg = "Tri-ASA: Invalid Angle-A: 0"   See TriMsg +nl  return 1 ok
	if sC = 0  TriMsg = "Tri-ASA: Invalid Side-C: 0"    See TriMsg +nl  return 1 ok
	if aB = 0  TriMsg = "Tri-ASA: Invalid Angle-B: 0"   See TriMsg +nl  return 1 ok

    aC = 180 - aA - aB                  // Have 2 angles  
    
    arA = aA  * PI/180 
    arC = aC  * PI/180 
    sA  = (sin(arA)) * (sC/sin(arC))        // Use RAD: 
    
    arB = aB  * PI/180
    sB  = (sin(arB)) * (sC/sin(arC))        // Use RAD: 

    adA = aA                            // Angle degree
    adB = aB 
    adC = aC 
         
    aAngleSide[1] = adA
    aAngleSide[2] = adB
    aAngleSide[3] = adc
    aAngleSide[4] = sA
    aAngleSide[5] = sB
    aAngleSide[6] = sC
    
    TriangleMoreValues( aAngleSide)  // 6 values + 16 more
    
Return  aAngleSide                   // 22 values 


//==============================================
//===============================================
// Two Sides and an Angle between
//         aC=?
//         /\
//   sB=5 /   \
//       /      \  sA=?
//      /         \
//   aA=49--------aB=?
//         sC=7
//-------------------------
// To solve an SAS triangle
// Use The Law of Cosines to calculate the unknown side,
// Then use The Law of Sines to find the smaller of the other two angles,
// And then use the three angles add to 180° to find the last angle.
//
// Two Sides and an Angle between
//------------------------------------------------------------------

Func TriangleSAS(sB,aA,sC)

    if !(isnumber(sB))  0+ sB  See "Convert to Number sB: "+sB +nl  ok
	if !(isnumber(aA))  0+ aA  See "Convert to Number aA: "+aA +nl  ok
    if !(isnumber(sC))  0+ sC  See "Convert to Number sC: "+sC +nl  ok

	if sB = 0  TriMsg = "Tri-SAS: Invalid Side-B: 0"   See TriMsg +nl  return 1 ok
	if aA = 0  TriMsg = "Tri-SAS: Invalid Angle-A: 0"  See TriMsg +nl  return 1 ok
	if sC = 0  TriMsg = "Tri-SAS: Invalid Side-C: 0"   See TriMsg +nl  return 1 ok		
	
   
    arA = aA  * PI/180    
    sA  = ( (sb^^2) + (sC^^2) - 2*sB*sC*cos(arA) )^^(1/2)   

    arB = (sin(arA) * sB) / sA          // Use Rad
    adB = asin(arB) * 180/PI            // Use Rad

    adA = aA    
    adC = 180 - adA  - adB
         
    aAngleSide[1] = adA
    aAngleSide[2] = adB
    aAngleSide[3] = adc
    aAngleSide[4] = sA
    aAngleSide[5] = sB
    aAngleSide[6] = sC
    
    TriangleMoreValues( aAngleSide)  // 6 values + 16 more
    
Return  aAngleSide                   // 22 values   

//==============================================
//==============================================
// TWO SIDES AND AN ANGLE NOT BETWEEN
//         aC=?
//         /\
//   sB=8 /   \
//       /      \  sA=?
//      /         \
//   aA=?--------aB=31
//         sC=18
//-------------------------
// To solve an SSA triangle
// Use The Law of Sines first to calculate one of the other two angles
// Then use the three angles add to 180° to find the other angle
// Finally use The Law of Sines again to find the unknown side
//
// TWO SIDES AND AN ANGLE NOT BETWEEN
//--------------------------------


Func TriangleSSA(sB,sC,aB)

    if !(isnumber(sB))  0+ sB  See "Convert to Number sB: "+sB +nl  ok
	if !(isnumber(sC))  0+ sC  See "Convert to Number sC: "+sC +nl  ok
    if !(isnumber(aB))  0+ aB  See "Convert to Number aB: "+aB +nl  ok
	
	if sB = 0  TriMsg = "Tri-SSA: Invalid Side-B: 0"   See TriMsg +nl  return 1 ok
	if sC = 0  TriMsg = "Tri-SSA: Invalid Side-C: 0"   See TriMsg +nl  return 1 ok
	if aB = 0  TriMsg = "Tri-SSA: Invalid Angle-B: 0"  See TriMsg +nl  return 1 ok	
   
    arB = aB  * PI/180    
    arC = (sC * sin(arB))/sB
    adC = asin(arC) * 180/PI           // Use Rad
    
    adA = 180 - aB - adC               // Have 2 angles degrees
    
    arA = adA  * PI/180                // Rad
    sA = (sin(arA) * sB ) / sin(arB)
    
    adB = aB
    
      
    aAngleSide[1] = adA
    aAngleSide[2] = adB
    aAngleSide[3] = adc
    aAngleSide[4] = sA
    aAngleSide[5] = sB
    aAngleSide[6] = sC
    
    TriangleMoreValues( aAngleSide)  // 6 values + 16 more
    
Return  aAngleSide                   // 22 values

//==============================================
//==============================================
// HAVE THREE SIDES, WANT TO FIND THE MISSING ANGLES.
//         aC=?
//         /\
//   sB=6 /   \
//       /      \  sA=8
//      /         \
//   aA=?--------aB=?
//         sC=7
//-------------------------
// To solve an SSS triangle:
// Use The Law of Cosines first to calculate one of the angles
// Then use The Law of Cosines again to find another angle
// And finally use angles of a triangle add to 180° to find the last angle.
//
// HAVE THREE SIDES. FIND THE MISSING ANGLES
//--------------------------------

Func TriangleSSS(sA,sB,sC)

    if !(isnumber(sA))  0+ sA  See "Convert to Number sA: "+sA +nl  ok
	if !(isnumber(sB))  0+ sB  See "Convert to Number sB: "+sB +nl  ok
    if !(isnumber(sC))  0+ sC  See "Convert to Number sC: "+sC +nl  ok
	
	if sA = 0  TriMsg = "Tri-SSS: Invalid Side-A: 0"  See TriMsg +nl  return 1 ok
	if sB = 0  TriMsg = "Tri-SSS: Invalid Side-B: 0"  See TriMsg +nl  return 1 ok
	if sC = 0  TriMsg = "Tri-SSS: Invalid Side-C: 0"  See TriMsg +nl  return 1 ok

    sA2 = sA^^2   sB2 = sB^^2   sC2 = sC^^2         // Simplify the Look

     vA  = ( sB2 + sC2 - sA2)  / (2*sB*sC)          // Vertex
    arA  = acos(vA)                                 // Use Rad
    adA  = arA * 180/PI                             // Convert to Degrees

     vB  = ( sC2 + sA2 - sB2 ) / (2*sC*sA)
    arB  = acos(vB)                                 // Use Rad
    adB  = arB * 180/PI                             // Convert to Degrees

     vC  = ( sA2 + sB2 - sC2 ) / (2*sA*sB)
    arC  = acos(vC)                                 // Use Rad
    adC  = arC * 180/PI                             // Convert to Degrees
     
    aAngleSide[1] = adA
    aAngleSide[2] = adB
    aAngleSide[3] = adc
	
    aAngleSide[4] = sA
    aAngleSide[5] = sB
    aAngleSide[6] = sC
	
    Area       = sB * sC * sin(arA) / 2       // Area
    Perimeter  = sA + sB + sC                 // Perimeter
    SemiPeri   = Perimeter / 2                // SemiPerimeter	
	
   
    TriangleMoreValues( aAngleSide)  // 6 values + 16 more
    
Return  aAngleSide                   // 22 values

//==========================================
//==========================================
// THREE ANGLES - Can NOT be Solved. Needs a Side' Use side  sC  BETWEEN the angles aA and aB
//--------------------------------

//Func TriangleAAA(aA,aB,aC)
Func TriangleAAA(aA,aB,aC,sC)  

	if !(isnumber(aA))  0+ aA  See "Convert to Number aA: "+aA +nl  ok
	if !(isnumber(aB))  0+ aB  See "Convert to Number aB: "+aB +nl  ok
    if !(isnumber(aC))  0+ aC  See "Convert to Number aC: "+aC +nl  ok

	if aA = 0  TriMsg = "Tri-AAA: Invalid Angle-A: 0"   See TriMsg +nl  return 1 ok
	if aB = 0  TriMsg = "Tri-AAA: Invalid Angle-B: 0"   See TriMsg +nl  return 1 ok
	if aC = 0  TriMsg = "Tri-AAA: Invalid Angle-C: 0"   See TriMsg +nl  return 1 ok
	
See "Tri-AAA: aA:"+aA +" aB:"+aB +" aC:"+ac +" Tot:"+ (aA+aB+aC) +nl
	
	if ( (aA + aB + aC) != 180 )
	   TriMsg = "Tri-AAA: aA+aB+aC != 180 deg"   See TriMsg +nl
	   return 1
	ok

    sideC = sC  // Use a Fixed Length sideC
	
    TriangleASA(aA,sideC,aB)
         
    // aAngleSide[1] = adA
    // aAngleSide[2] = adB
    // aAngleSide[3] = adc
    // aAngleSide[4] = sA
    // aAngleSide[5] = sB
    // aAngleSide[6] = sC
    
    TriangleMoreValues( aAngleSide)  // 6 values + 16 more
    
Return  aAngleSide                   // 30 values 


//==============================================
    
//=====================================
//=====================================


Func TriangleMoreValues( aAngleSide)

    adA   =  aAngleSide[1]   // Angles Degree - Numeric
    adB   =  aAngleSide[2]
    adC   =  aAngleSide[3]
			 
    sA    =  aAngleSide[4]   // Sides Lenght - Numeric
    sB    =  aAngleSide[5]
    sC    =  aAngleSide[6]

    if !(isnumber(adA))  0+ adA  See "Convert to Number adA: "+adA +nl  ok
	if !(isnumber(adB))  0+ adB  See "Convert to Number adB: "+adB +nl  ok
    if !(isnumber(aDc))  0+ adC  See "Convert to Number adC: "+adC +nl  ok	
	
    if !(isnumber(sA))   0+ sA   See "Convert to Number sA: "+sA +nl  ok
	if !(isnumber(sB))   0+ sB   See "Convert to Number sB: "+sB +nl  ok
    if !(isnumber(sC))   0+ sC   See "Convert to Number sC: "+sC +nl  ok	

    //--------------------------
	
    arA   = adA  * PI/180                // Deg To Rad
    arB   = adB  * PI/180               
    arC   = adC  * PI/180               

    //--------------------------
	
    Area       = sb * sc * sin(arA) / 2       // Area
    Perimeter  = sa + sb + sc                 // Perimeter
    SemiPeri   = Perimeter / 2                // SemiPerimeter
 

    //--------------------------
	
    hA    = (2 * Area) / sA              // Height A
    hB    = (2 * Area) / sB              // Height B
    hC    = (2 * Area) / sC              // Height C

    //--------------------------
    // • Median of Side a ( ma )
    //  Side 60   60^2  = 3600 ,  x2  =  7200 
    //  1/2 sqrt(7200 + 7200 - 3600 ) = 103.92 / 2 = 51.96152
    
    mA2   = ( (2 * (sb^^2)) + (2 * (sc^^2)) - (sa^^2))        // Median mA
	mA    = (mA2^^(1/2)) / 2
	
	
    mB2   = ( (2 * (sa^^2)) + (2 * (sc^^2)) - (sb^^2))         // Median mA
	mB    = mB2^^(1/2) / 2

    mC2   = ( (2 * (sa^^2)) + (2 * (sb^^2)) - (sc^^2))         // Median mA
	mC    = (mC2^^(1/2)) / 2	
	
	
	//See "Meridian: sa: "+sa +" MA2: "+ ma2 +" mA: "+mA  +" MB2: "+ mb2 +" Mb: "+mb +" MC2: "+ mc2 +" Mc: "+mc +nl

	//--------------------------------------------------
	// • ANGLE BISECTOR of Side a
    //   2 × b × c × Cos(A/2) / (b + c)
	
	tA = (2*sB*sC * cos(arA/2) ) / (sB + sC)  // Angle Bisector of aA	
	tB = (2*sA*sC * cos(arB/2) ) / (sA + sC)
	tC = (2*sA*sB * cos(arC/2) ) / (sA + sB)	
	
    //See "Bisector: A,B,C: "+ta +" "+tB +" "+tC +nl	
	
 	//--------------------------------------------------
	// SOLVE THE INRADIUS iR and the CIRCUMRADIUS cR
	
    iR   = Area / SemiPeri             // InRadius
    cR   = (sA   / (sin(arA)) ) / 2    // CircumRadius 2R = sA/(sin(arA))  sB/ (sin(arB))  sC/ (sin(arC))


	//--------------------------------------------------
	// VERTEX of C
    // Centroid of INSIDE CIRCLE
	
    aX =  0  aY = 0                     // origin
    bX = sC  bY = 0                     // Base sideC:   0-------7
    cX = sB*cos(arA)                    // Polar to Cartesian
    cY = sB*sin(arA)                    // Cartesian coordinates:  x = r*cosθ | y = r*sinθ 
	
	//See "A Cartesian-Vertex-C C[x,y]: "+ cX +" - "+ Cy +nl
	
	VAx = aX    VAy = aY                // Vertex Points V(x,y) of Point A,B,C Co-Ordinates
	VBx = bX    VBy = bY
	VCx = cX    VCy = cY
    
    //OIx = (aX + bX + cX)  / 3            // InRadius Sum X-Coord /3
    //OIy = (aY + bY + cY)  / 3            //          Sum Y-Coord /3
  
    // [ ax1 + bx2 +cx3    ay1 + by2 + cy3  ]
    //     a+b+c               a+b+c
    //  
    // [ sA*aX + sB*bX +sC*cX    sA*aY + sB*bY + sC*cY  ]
    //     sA+sB+sC                 sA+sB+sC
    //	 
	 
	OIx = (sA*aX + sB*bX +sC*cX ) / (sA+sB+sC)
	OIy = (sA*aY + sB*bY + sC*cY) / (sA+sB+sC)

    
    //=============================================================
    // CIRCUMCENTRE OF OUTSIDE CIRCLE WHOSE 
	// https://www.cuemath.com/geometry/CIRCUMCENTER/
	// 
	// O(x,_) = ( x1sin2A + x2sin2B + x3sin2C ) / ( sin2A + sin2B +sin2C )
	// O(_,y) = ( y1sin2A + y2sin2B + y3sin2C ) / ( sin2A + sin2B +sin2C )
	      
	OCxT  =      (aX*sin(2*arA)) +	(bX*sin(2*arB))  + ( cX*sin(2*arC))
	OCxB  =         (sin(2*arA)) +     (sin(2*arB))  +     (sin(2*arC))
		
	OCyT   =      (aY*sin(2*arA)) +	(bY*sin(2*arB))  + ( cY*sin(2*arC))
	OCyB   =         (sin(2*arA)) +	   (sin(2*arB))  +     (sin(2*arC))
	
	OCx = OCxT / OCxB
	OCy = OCyT / OCyB
	
	//See "B Cartesian-Vertex-C OCxy[x,y]: "+ OCx +" - "+ OCy +nl
   
   //===============================================
   //===============================================

    aAngleSide[1]  = adA     // Angles
    aAngleSide[2]  = adB
    aAngleSide[3]  = adc
    
    aAngleSide[4]  = sA      // Sides
    aAngleSide[5]  = sB
    aAngleSide[6]  = sC
	
    aAngleSide[7]  = VAx     // Vertex - Co-Ordinates
    aAngleSide[8]  = VAy
    aAngleSide[9]  = VBx
    aAngleSide[10] = VBy
    aAngleSide[11] = VCx
    aAngleSide[12] = VCy	
	
    
    aAngleSide[13] = Area           // Area
    aAngleSide[14] = Perimeter      // Perimeter
    aAngleSide[15] = SemiPeri       // Semi-Perimeter
    
    aAngleSide[16] = hA      // Heigh
    aAngleSide[17] = hB
    aAngleSide[18] = hC
    
    aAngleSide[19] = mA      // Median
    aAngleSide[20] = mB
    aAngleSide[21] = mC
	
    aAngleSide[22] = tA      //Angle BiSector
    aAngleSide[23] = tB
    aAngleSide[24] = tC
	
    
    aAngleSide[25] = iR      // Radius: Centroid Inner Circle Radies
	aAngleSide[27] = OIx     // Co-Ord: Centroid Inner Circle Center P(x,y)
    aAngleSide[28] = OIy 
	
    aAngleSide[26] = cR      // Radius: CircumCircle Outer Circle Radius
    aAngleSide[29] = OCx     // Co-Ord: CircumCircle Outer Circle Center P(x,y)
    aAngleSide[30] = OCy 
	
    aAngleSide[31] = " "     //AP   // CircumCircle Outer Circle Radius
    
    // TrianglePrintData(aAngleSide)

Return  aAngleSide           // IN 6 values ->  OUT 28 values

//==============================================
//==============================================
// PRINT DATA array

Func TrianglePrintData(aAngleSide)

  adA =  aAngleSide[1]        // Angles
  adB =  aAngleSide[2]        
  adc =  aAngleSide[3]        
		                      
  sA  =  aAngleSide[4]        // Sides
  sB  =  aAngleSide[5]        
  sC  =  aAngleSide[6]        
		                      
  VAx =  aAngleSide[7]        // Co-Ordinates
  VAy =  aAngleSide[8]        
  VBx =  aAngleSide[9]        
  VBy =  aAngleSide[10]       
  VCx =  aAngleSide[11]       
  VCy =  aAngleSide[12]       
	                          
                              
  Area      =  aAngleSide[13]      // Area
  Perimeter =  aAngleSide[14]       // Perimeter
  SemiPeri  =  aAngleSide[15]       // Semi-Perimeter
	                          
  hA  =  aAngleSide[16]       // Heigh
  hB  =  aAngleSide[17]       
  hC  =  aAngleSide[18]       
	                          
  mA  =  aAngleSide[19]       // Median
  mB  =  aAngleSide[20]       
  mC  =  aAngleSide[21]     

  tA  =  aAngleSide[22]        //Angle BiSector
  tB  =  aAngleSide[23]  
  tC  =  aAngleSide[24]  
	                          
  iR  =  aAngleSide[25]       // Inner Circle Radies
  OIx =  aAngleSide[26]       // Inner Circle Center P(x,y)
  OIy =  aAngleSide[27] 
  
  cR  =  aAngleSide[28]       // Outer Circle Radius	                          
  OCx =  aAngleSide[29]       // Outer Circle Center P(x,y)
  OCy =  aAngleSide[30]  
  
  AP  =  aAngleSide[31]       // Outer Circle Radius
	
    
    See nl+"Angles:   aA: "+adA +" aB: "+adB +" aC: "+adC +nl
    See "Sides:    sA: "+sA  +" sB: "+sB  +" sC: "+sC  +nl  
	See "Vertex:     : A("+VAx +","+VAy +")"  +" B("+VBx +","+VBy +")"  +" C("+VCx +","+VCy +")"   +nl   
	
    See "Area:   Area: "+area +" Perimeter: "+P +" SemiPerimeter: "+S +nl
    See "CircumRadius: "+cR +nl                 // array[17]
	
    See "Height:   hA: "+hA +" hB: "+hB +" hC: "+hC +nl
    See "Median:   mA: "+mA +" mB: "+mB +" mC: "+mC +nl
	See "BiSector: tA: "+tA +" tB: "+tB +" tC: "+tC +nl
	
    See "CentInRadius: "+iR +nl  
    See "Centroid:     Point("+OIX +"," +OIY +")" +nl
	
    See "CircumCenter: Point("+OCX +"," +OCY +")" +nl
    See "CircumRadius: "+AP +nl
    See nl+"============================="+nl+nl


Return

//==============================================
//==============================================
//==============================================
//==============================================


###==========================================================================
###==========================================================================
/*

//========================================================================

https://www.endmemo.com/geometry/triangle.php

https://www.calculator.io/triangle-calculator/

https://www.thinkcalculator.com/planegeometry/ultratriangle.php

https://www.inchcalculator.com/triangle-calculator/

https://www.calculator.net/triangle-calculator.html



//==================================
https://www.calculator.net/triangle-calculator.html?vc=&vx=60&vy=60&va=&vz=60&vb=&angleunits=d&x=Calculate

Equilateral Triangle
Side a = 60
Side b = 60
Side c = 60

Angle ∠A = 60° = 1.0472 rad = π/3
Angle ∠B = 60° = 1.0472 rad = π/3
Angle ∠C = 60° = 1.0472 rad = π/3

C=60°
B=60°
A=60°
b=60
a=60
c=60

Area = 1,558.84573
Perimeter p = 180
Semiperimeter s = 90

Height ha = 51.96152 
Height hb = 51.96152
Height hc = 51.96152

Median ma = 51.96152 
Median mb = 51.96152
Median mc = 51.96152

Inradius r = 17.32051 
Circumradius R = 34.64102 

Vertex coordinates: A[0, 0] B[60, 0] C[30, 51.96152]
Centroid: [30, 17.32051]
Inscribed Circle Center: [30, 17.32051]
Circumscribed Circle Center: [30, 17.32051]

==============================

The coordinates of the in-centre whose vertices are
  A(x1,y1) B(x2,y2)  C(x3,y3)

[ ax1 + bx2 +cx3    ay1 + by2 + cy3  ]
     a+b+c               a+b+c

A(-36,7)  B (20,7)  C(0,-8)

                 C-Bx        C-By
a = BC  = sqrt[ (0-20)^2 + (-8-7)^2  ] = sqrt(400+225)    = sqrt(625) = 25
  
                 C-Ax        B-Ay
b = AC  = sqrt[ (0+36)^2 + (-8-7)^2  ] = sqrt(1296 + 225) = sqrt(1521) = 39

                 B-Ax         B-Ay
c = AB  = sqrt[ (20--36)^2 + (7-7)^2 ] = sqrt(56^2)                    = 56

------------
Coordinates are

[ ax1 + bx2 +cx3    ay1 + by2 + cy3  ]
     a+b+c               a+b+c

 [ 25*(-36) + 39*20) + 56*0    25*7 + 39*7 + 56*(-8) ]
        25+39+56                    25+39+56
		
		
      -900 + 788 +0               175 + 273 - 448	
	       120                         120
		   
		 -120                           0
          120                          120

       X= -1		                   Y=0

================
Co-ord InRAdius Circle
  
    // [ ax1 + bx2 +cx3    ay1 + by2 + cy3  ]
    //     a+b+c               a+b+c
    //  
    // [ sA*aX + sB*bX +sC*cX    sA*aY + sB*bY + sC*cY  ]
    //     sA+sB+sC                 sA+sB+sC
    //	 
	 
	OIx = (sA*aX + sB*bX +sC*cX ) / (sA+sB+sC)
	OIy = (sA*aY + sB*bY + sC*cY) / (sA+sB+sC) 

*/

