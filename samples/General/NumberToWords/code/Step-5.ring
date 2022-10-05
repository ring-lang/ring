// *** Step-5 ***
// Number to Words 
// assembled jew
// effective (cost) approximately 30 lines of code for an arbitrary number of words.
// currently limited by tsds ["vigintillion"] (can be traced)
// Datum: 20.02.2018 (Revised: 23.12.2019)
// Author: Nestor Kuka 
// Against readers: Bert Mariani
//---

// The net effect: Approximately 30 lines code are used to convert a randomly long number into words.
// The limit is set to "Vigintillion" (Can be increased)

# Load Ring Libraries
Load "stdlib.ring"

// Examples:
pConvert("1234567")

pConvert("10000009")    // zero-group: "000" not (Not well solved yet)
pConvert("123000456")
pConvert("103010009")
pConvert("103000109")   // zero-group: "000" not (Not well solved yet)
pConvert("103406789")

pConvert("103400789")
pConvert("103400009")
pConvert("123456789")
pConvert("123000009123000789123456")
pConvert("12345678912345678912345678912345678912345678912345678912345678")
pConvert("12300456789003456780123056")


//  123,456,789   9%3 = 0
//   12,345,678   8%3 = 2
//    1,234,567   7%3 = 1
//----------------------------------------------------------------------

Func pConvert(n)


   // Add commas to the number for readability
   size      = len(n)
   offset    = size % 3
   alphaNum  = ""+ n
   betaNum   = ""
   
   for i = 1 to size
      betaNum = betaNum + alphaNum[i]
         if i % 3 = offset  AND  i < size
               betaNum = betaNum + "," 
         ok    
   next
   
   //-------------------

   
   if len(n) < 63
      ? "Input...: "+ betaNum
      doGroup(n)                    // ===>>> CALL
   else 
      ? "Do you really have that much money? ;)"
   end                   // end-pConvert  
   
return

//----------------------------------------------------------------------

Func doWord(n)

   Ones = ["one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"]
   Tens = ["" , "twenty",  "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety"]

   // Input test:                /                    // Possibly not complete
   // The zeros in the groups or whole null groups are not treated.
   // if n = "000" See "Zero-Group "+nl return end    // A null group
   
   if n =  "00" return end
   if n = "000" 	rtn = "zero" 	ok		// Zero thousand ?!?!
   
   if number(n) < 20 and n != "000"    // 1..19 
      n   = n*1                        // Convert to number 
      rtn = Ones[n]                    // Return value 
      
   elseif n < 100 and n != "000"       // 20..99
      n = n*1                          // Convert to number 
      x = n % 10                       // For Ones
      y = floor(n / 10)                // For Tens
      
      if x = 0  rtn = Tens[y]
      else rtn = tens[y] +" "+ ones[x] // Whole Tens
      end 
      
   elseif len(n) = 3 and n != "000"    // First place: Hundreds
      z   =  right(n, 2)
      h   = (floor(n / 100)) *1        // Find out the Hundreds
      rtn = Ones[h] +" hundred "
      rtn = rtn + doWord(z)            // And.. (Recursive call)  ===>>>
   end                                 // End if
   
return rtn                             // Return to Caller   
   
// ? "doWord-rtn: "+rtn                // For debug only
// end-doWord()

//----------------------------------------------------------------------

Func doGroup(n)

   rtn     = " "
   doGroup = floor((len(n) +2) / 3)    // Number of groups
   Tsds    = ["","thousand ", "million ", "billion ", "trillion ", "quadrillion ", "quintillion ", "sextillion ", "septillion ", "octillion ", "nonillion ", "decillion ", "undecillion ", "duodecillion ", "tredecillion ", "quattuordecillion ", "sexdecillion ", "septendecillion ", "octodecillion ", "novemdecillion ", "vigintillion "]
   
   for x = 1 to doGroup -1             // Handle input
      gr = right(n, 3)                 // Determine group
      n  = left( n,len(n)-3 )          // Generate new number
      
      if gr = "" gr = n end            // If gr is blank, use "n"
		OldRtn = rtn     
		
		rtn = doWord(gr)						// ===>>> CALL
		
			if rtn != "zero"					// Handle "zero" units
				rtn =  rtn +" "+ Tsds[x] + OldRtn 
			else
				rtn =  OldRtn 					// Ignore when "zero" thousand
			ok
			
   next                                //end-for
   oldRtn = rtn
	
   rtn = doWord(n) +" "+ Tsds[x] + OldRtn 
	
	
	
   ? "In Words: "+ rtn                 // Output
   ? " "

return rtn
//end doGroup
