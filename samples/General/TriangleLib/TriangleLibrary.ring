// Triangle Libray with 5 Functions 
// Solve Triangles for missing Angles and Sides
//
// Bert Mariani  2024-11-12
// Returns Array with ANGLES aA aB aC and SIDES sA sB sC
//
// aTri = TriangleAAS(35,62, 7)  Angle Angle Side
// aTri = TriangleASA(76, 9,34)  Angle Side  Angle
// aTri = TriangleSAS( 5,49, 7)  Side  Angle Side
// aTri = TriangleSSA( 8,13,31)  Side  Side  Angle
// aTri = TriangleSSS( 8, 6, 7)  Side  Side  Side
//
// Note Ring sin() uses Radians
//      Functions convert Degrees to Radians for Calculation
//      Then the Angles are converted back to Degrees
// 
//      TriangleAAA with 3 Angles can NOT be solved 
//-------------------------------------------------

load "stdlibcore.ring"

decimals(4)
PI = 3.14159

   // Testing ...
   
    aTri = TriangleAAS(35,62,7)
    See "aTriAAS: "+ aTri[1] +" "+ aTri[2] +" "+ aTri[3] +" "+ aTri[4] +" "+ aTri[5] +" "+ aTri[6] +nl
    See "Verify aTriAAS: 35  83  62  4.55  7.87  7  "+nl+nl

    aTri = TriangleASA(76,9,34)
    See "aTriASA: "+ aTri[1] +" "+ aTri[2] +" "+ aTri[3] +" "+ aTri[4] +" "+ aTri[5] +" "+ aTri[6] +nl
    See "Verify aTriASA: 76  34  70  9.29  5.36  9  "+nl+nl
    
    aTri = TriangleSAS(5,49,7)
    See "aTriSAS: "+ aTri[1] +" "+ aTri[2] +" "+ aTri[3] +" "+ aTri[4] +" "+ aTri[5] +" "+ aTri[6] +nl 
    See "Verify aTriSAS: 49  45.4  85.6  5.30  5  7  "+nl+nl    

    aTri = TriangleSSA(8,13,31)
    See "aTriSSA: "+ aTri[1] +" "+ aTri[2] +" "+ aTri[3] +" "+ aTri[4] +" "+ aTri[5] +" "+ aTri[6] +nl  
    See "Verify aTriSSA: 92.181  31 56.8  15.2  8  13  "+nl+nl
    
    aTri = TriangleSSS(8,6,7)
    See "aTriSSS: "+ aTri[1] +" "+ aTri[2] +" "+ aTri[3] +" "+ aTri[4] +" "+ aTri[5] +" "+ aTri[6] +nl
    See "Verify aTriSSS: 75.7 46.6 57.9  8  6  7  "+nl+nl


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
//----------------------------------------------------------

Func TriangleAAS(aA,aC,sC)

    // TWO ANGLES AND A SIDE NOT BETWEEN
    // Change Angle to Rad for sin
    // In this triangle we know:.
    // aA = 35  aC = 62   sC =  7   

    aB = 180 - aA - aC                  // Have 2 angles in degrees
    
    arA = aA  * PI/180
    arC = aC  * PI/180
    sA  = (sin(arA)) * (sC/sin(arC))    // Use RAD: 
    
    arB = aB  * PI/180
    sB  = (sin(arB)) * (sC/sin(arC))    // Use RAD: 
 
    adA = aA                            // Angle degree
    adB = aB
    adC = aC
    
    //See "Triangle: "+adA +" adB: "+adB +" adC: "+adC +" sA: "+sA +" sB: "+sB +" sC:"+sC +nl
    
    aAngleSide = list(6)
    aAngleSide[1] = adA
    aAngleSide[2] = adB
    aAngleSide[3] = adc
    aAngleSide[4] = sA
    aAngleSide[5] = sB
    aAngleSide[6] = sC
    
Return aAngleSide   

//==============================================
//==============================================
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
//--------------------------------

Func TriangleASA(aA,sC,aB)

    // TWO ANGLES AND A SIDE BETWEEN
    // Change Angle Degree to Radian for Sin
    // In this triangle we know:.
    // aA = 76  sC = 9  aB = 9

    aC = 180 - aA - aB                  // Have 2 angles  
    
    arA = aA  * PI/180 
    arC = aC  * PI/180 
    sA  = (sin(arA)) * (sC/sin(arC))        // Use RAD: 
    
    arB = aB  * PI/180
    sB  = (sin(arB)) * (sC/sin(arC))        // Use RAD: 

    adA = aA                            // Angle degree
    adB = aB 
    adC = aC 
    
    //See "Triangle: "+adA +" adB: "+adB +" adC: "+adC +" sA: "+sA +" sB: "+sB +" sC:"+sC +nl
    
    aAngleSide = list(6)
    aAngleSide[1] = adA
    aAngleSide[2] = adB
    aAngleSide[3] = adc
    aAngleSide[4] = sA
    aAngleSide[5] = sB
    aAngleSide[6] = sC
    
Return aAngleSide   


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
//------------------------------------------------------------------

Func TriangleSAS(sb,aA,sC)

    // Two Sides and an Angle between
    // Change Angle to Rad for sin
    // In this triangle we know:.
    // aA = 49  sB = 5  aC = 7
    
    
    arA = aA  * PI/180    
    sA  = ( (sb^^2) + (sC^^2) - 2*sB*sC*cos(arA) )^^(1/2)   

    arB = (sin(arA) * sB) / sA          // Use Rad
    adB = asin(arB) * 180/PI            // Use Rad

    adA = aA    
    adC = 180 - adA  - adB
    
    //See "Triangle: "+adA +" adB: "+adB +" adC: "+adC +" sA: "+sA +" sB: "+sB +" sC:"+sC +nl
    
    aAngleSide = list(6)
    aAngleSide[1] = adA
    aAngleSide[2] = adB
    aAngleSide[3] = adc
    aAngleSide[4] = sA
    aAngleSide[5] = sB
    aAngleSide[6] = sC
    
Return aAngleSide   

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
//--------------------------------


Func TriangleSSA(sb,sC,aB)

    // TWO SIDES AND AN ANGLE NOT BETWEEN
    // Change Angle to Rad for sin
    // In this triangle we know:.
    // aB = 31  sB = 8  aC = 13
    
    arB = aB  * PI/180    
    arC = (sC * sin(arB))/sB
    adC = asin(arC) * 180/PI           // Use Rad
    
    adA = 180 - aB - adC               // Have 2 angles degrees
    
    arA = adA  * PI/180                // Rad
    sA = (sin(arA) * sB ) / sin(arB)
    
    adB = aB
    
    //See "Triangle: "+adA +" adB: "+adB +" adC: "+adC +" sA: "+sA +" sB: "+sB +" sC:"+sC +nl
    
    aAngleSide = list(6)
    aAngleSide[1] = adA
    aAngleSide[2] = adB
    aAngleSide[3] = adc
    aAngleSide[4] = sA
    aAngleSide[5] = sB
    aAngleSide[6] = sC
    
Return aAngleSide   


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
//--------------------------------

Func TriangleSSS(sA,sB,sC)

    // HAVE THREE SIDES. FIND THE MISSING ANGLES
    // Change Angle to Rad for sin
    // In this triangle we know:.
    // sA = 8  sB = 6  sC = 7
    
     vA  = ( sB^^2 + sC^^2 - sA^^2)  / (2*sB*sC)
    arA  = acos(vA)           // Use Rad
    adA  = arA * 180/PI       // Convert to Degrees

     vB  = ( sC^^2 + sA^^2 - sB^^2 ) / (2*sC*sA)
    arB  = acos(vB)           // Use Rad
    adB  = arB * 180/PI       // Convert to Degrees

     vC  = ( sA^^2 + sB^^2 - sC^^2 ) / (2*sA*sB)
    arC  = acos(vC)           // Use Rad
    adC  = arC * 180/PI       // Convert to Degrees
     
    //See "Triangle: "+adA +" adB: "+adB +" adC: "+adC +" sA: "+sA +" sB: "+sB +" sC:"+sC +nl
    
    aAngleSide = list(6)
    aAngleSide[1] = adA
    aAngleSide[2] = adB
    aAngleSide[3] = adc
    aAngleSide[4] = sA
    aAngleSide[5] = sB
    aAngleSide[6] = sC
    
Return aAngleSide   

//==============================================
//==============================================
/*
OUTPUT Testing
aTriAAS: 35 83 62 4.5473 7.8689 7
Verify aTriAAS: 35  83  62  4.55  7.87  7

aTriASA: 76 34 70 9.2931 5.3557 9
Verify aTriASA: 76  34  70  9.29  5.36  9

aTriSAS: 49 45.4117 85.5883 5.2987 5 7
Verify aTriSAS: 49  45.4  85.6  5.30  5  7

aTriSSA: 92.1820 31 56.8180 15.5216 8 13
Verify aTriSSA: 92.181  31 56.8  15.2  8  13

aTriSSS: 75.5226 46.5675 57.9101 8 6 7
Verify aTriSSS: 75.7 46.6 57.9  8  6  7
*/
###==========================================================================
###==========================================================================