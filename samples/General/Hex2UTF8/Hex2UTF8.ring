// UTF-8 is a specific scheme for mapping a sequence of 1-4 bytes to a number 
// from 0x000000 to 0x10FFFF:
// 
// 00000000 -- 0000007F: 	0xxxxxxx
// 00000080 -- 000007FF: 	110xxxxx 10xxxxxx
// 00000800 -- 0000FFFF: 	1110xxxx 10xxxxxx 10xxxxxx
// 00010000 -- 001FFFFF: 	11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
// The x's are bits to be extracted from the sequence 
// and glued together to form the final number.
//


//========================================
// Globals 
	RangeA = "0000007F"  // Less than  < A < B < C < D
	RangeB = "000007FF"
	RangeC = "0000FFFF"
	RangeD = "001FFFFF"
	
	MaskA = "0xxxxxxx"
	MaskB = "110xxxxx10xxxxxx"
	MaskC = "1110xxxx10xxxxxx10xxxxxx"
	MaskD = "11110xxx10xxxxxx10xxxxxx10xxxxxx"

###========================================

load "guilib.ring"
load "stdlib.ring"

New qapp
{
   win =  new qwidget()
    {
        setwindowtitle("UniCode UTF--8 ... Segoe UI Font " )
        setgeometry(100, 100, 800, 400)
        ###-------------------------------
        ### Font Type and Size
		  ### oFont = new qfont("Ariel",20,0,0)

        oFont = new qfont("Segoe UI",20,0,0)
        setfont(oFont)
        
        ###-------------------------------
        ### Draw Label and lineEdit
         
           yPos = 30 yHeight = 40
           label1  = new qlabel(win)    { setGeometry(  40,  yPos, 120, yHeight)  setText("Lang") }
        lineEdit1  = new qlineedit(win) { setGeometry( 160,  yPos, 520, yHeight)  setText("Glyph")  }
         
        ###-------------------------------             
        Test()

        show()
    }

    exec()
}

//============================================

Func Test()

   TestA = "41"		// A  41 HexNbr 
	TestB = "a3"		// £  c2 a3
	TestC = "0141"		// Ł  c5 81
	TestD = "2654"    // K  e2 99 94
	TestE = "1d665"	// p  f0 9d 99 a5
	TestF = "200041"  // exceeds limit
	
	TestG =  65       // A
	TestH =  9812     // Black King

	###-------------------------------
	
	See "Hex = "+ TestA +" UTF "+ Hex2Utf(TestA)  +nl 
	See "Hex = "+ TestB +" UTF "+ Hex2Utf(TestB)  +nl
	See "Hex = "+ TestC +" UTF "+ Hex2Utf(TestC)  +nl
	See "Hex = "+ TestD +" UTF "+ Hex2Utf(TestD)  +nl
	See "Hex = "+ TestE +" UTF "+ Hex2Utf(TestE)  +nl
	See "Hex = "+ TestF +" UTF "+ Hex2Utf(TestF)  +nl
	See nl
	
	See "Dec = "+ TestH +" UTF "+ Dec2Utf(TestG)  +nl
	See "Dec = "+ TestF +" UTF "+ Dec2Utf(TestH)  +nl
	See "Dec = 9831 "   +" UTF "+ Dec2Utf(9831)	+nl				// Cards - White Clubs e299a7
	See nl
	
	See "Bin = 1010100011" +" UTF "+ Bin2Hex("1010100011") +nl	// 2A3
	See nl
	 
	###-------------------------------
	
   hexNbr   = ""+ 2654		// Chess Black King
   startNbr = dec(hexNbr)  

   strPlain = ""
   for i = startNbr to (startNbr + 20 -1)       // Print a page 256 characters
		HexNbr = hex(i)
		UTF8   = Hex2Utf(HexNbr)
		
		See "Dec: "+ i +" Hex "+ HexNbr +" Utf8 "+ UTF8  +nl	// print conversion
 	
		strPlain = strPlain + hex2str(UTF8)  		// UTF-8 Code  hex2str("E2999E")  Append
   next

   lineEdit1.setText(strPlain)						// Write to GUI
   See "strPlain: "+ strPlain +nl					// Print to DOS
	
	###-------------------------------
	
return

###============================================
###============================================
###============================================


###============================================
### Covert Decimal to UTF8
### Ex.    Dec2Utf(9812)

Func Dec2Utf(DecNbr)

	HexNbr = Hex(DecNbr)
	UtfHex = Hex2Utf(HexNbr)
	
return UtfHex

###============================================
### Convert Hex to UTF8
### Ex.     Hex2Utf("2654")  
### Note:   In quotes if direct value

Func Hex2Utf(HexNbr)

	DecNbr = Dec(HexNbr)              // A3
	BinNbr = BinaryDigits(DecNbr)     // 1010 0011
	BinLen = len(BinNbr)              // 8

	###-------------------------------
	### 00000000 -- 0000007F: 	0xxxxxxx 
	   
	if (Dec(HexNbr) <= Dec("7F"))		// RangeA = "0000007F" = 7 bits
  	
	   for i = 1 to (8 - BinLen)  	// Fill Left Side with missing 0's
			BinNbr = "0" + BinNbr
	   next
	
     //MaskA = "0xxxxxxx"
	   Mask   =  MaskA
		UtfBin = "00000000"
      k = 8									// Rightmost BinNbr bit
		
	   for i = 8 to 1 step -1
			if Mask[i]  != "x"
	       	UtfBin[i] = Mask[i]		// Mask
			else
				UtfBin[i] = BinNbr[k]   
            k--  
			ok
	   next

	###-------------------------------
	###  00000080 -- 000007FF: 	110xxxxx 10xxxxxx

	elseif  Dec(HexNbr) <= Dec("7FF")	// RangeB = "000007FF" = 11 bits

	   for i = 1 to (16 - BinLen)
			BinNbr = "0" + BinNbr
	   next
	
    //MaskB  = "110x xxxx 10xxx xxx"   // 11-x
	   Mask   =  MaskB
		UtfBin = "0000000000000000"
		
      k = 16                           // Rightmost BinNbr bit
	   for i = 16 to 1 step -1
			if Mask[i]  != "x" 
	       	UtfBin[i] = Mask[i]			// Mask
			else
				UtfBin[i] = BinNbr[k]  
            k--   
			ok
	   next

	###-------------------------------
	### 00000800 -- 0000FFFF: 	1110xxxx 10xxxxxx 10xxxxxx
	    
	elseif  Dec(HexNbr) <= Dec("FFFF")		// RangeC = "0000FFFF" = 16 bits

	   for i = 1 to (24 - BinLen)
			BinNbr = "0" + BinNbr
	   next
	
    //MaskC  = "1110xxxx10xxxxxx10xxxxxx"	// 24 bits
	   Mask   = MaskC
		UtfBin = "000000000000000000000000"
		k = 24
	   for i = 24 to 1  step -1
			if Mask[i]  != "x" 
	       	UtfBin[i] = Mask[i]				// Mask
			else
				UtfBin[i] = BinNbr[k]   
            k--  
			ok
	   next

	###-------------------------------
	### 00010000 -- 001FFFFF: 	11110xxx 10xxxxxx 10xxxxxx 10xxxxxx

	elseif  Dec(HexNbr) <= Dec("1FFFFF")				// RangeD = '001FFFFF"  26 bits

	   for i = 1 to (32 - BinLen)
			BinNbr = "0" + BinNbr
	   next
	
    //MaskD  = "11110xxx10xxxxxx10xxxxxx10xxxxxx"  // 32 bits
	   Mask   = MaskD
		UtfBin = "00000000000000000000000000000000"
      k = 32
		
	   for i = 32 to 1  step -1
			if Mask[i]  != "x" 
	       	UtfBin[i] = Mask[i]
			else
				UtfBin[i] = BinNbr[k]     					// mask
            k--
			ok
	   next

	//-----------------------------

	elseif  Dec(HexNbr) > Dec("1FFFFF") 
		return "00"								// Exceeds Hex Value 
		
	//-----------------------------
   ok
	
   UtfHex = Bin2Hex(UtfBin)					// Convert 1's 0's to  "e2999a4"

	return UtfHex


###============================================
### Convert Binary to Hex
### Ex:     Bin2Hex("111000001001001010000001")
### Note:   In quotes if direct value
#
# Utf:     41 01000001
# Utf:   0141 1100000110000001
# Utf:   1241 111000001001001010000001
# Utf: 123441 11110000100100101011010010000001

Func Bin2Hex(BinString)

	BinLen     = len(BinString)		// 1's and 0's
	
	Boundary   = BinLen % 4         	// CHECK: Need 4 bit boundaries
	if Boundary != 0
		for j = 1 to Boundary
			BinString = "0"+ BinString
		next
	ok
	
	BinLen     = len(BinString)		// i's and 0's
	Hex4Bits   = ""						// 4 Bits at a tile
   HexLetters = ""						// Hex Char 0..9A..F
	
	for i = 1 to BinLen  step 4
		Hex4Bits = ""
		for k = 0 to 3
			Hex4Bits = Hex4Bits + BinString[i+k]
      next			
		   HexChar    = Hex2Char(Hex4Bits)
			HexLetters = HexLetters + HexChar		// Lookup 4 Bits to Hex Char
	next
	

return HexLetters

###=============================================
### Convert 4 bits to Hex Char
### Send 1100 returns C

Func Hex2Char(Hex4Bits)

	x = Hex4Bits
        switch x
        on "0000"  x = "0"
        on "0001"  x = "1"
        on "0010"  x = "2"
        on "0011"  x = "3"
        on "0100"  x = "4"
        on "0101"  x = "5"
        on "0110"  x = "6"
        on "0111"  x = "7"
        on "1000"  x = "8"
        on "1001"  x = "9"
        on "1010"  x = "a"
        on "1011"  x = "b"
        on "1100"  x = "c"
        on "1101"  x = "d"
        on "1110"  x = "e"
	     on "1111"  x = "f"
        off

return x

###=============================================
