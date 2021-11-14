// *** Step-6 ***
// Numbers to Words

// s: with graphic UI  (n2w-Gr)

// effective (cost) approximately 30 lines of code for an arbitrary number of words.
// currently limited by tsds ["vigintillion"] (can be traced)
// File: C:\ring\Ring17\RingSamples\src\n2w03c.ring
// Datum: 20.02.2018 (Revised: 23.12.2019)
// Author: Nestor Kuka 
// Against readers: Bert Mariani  (BM)

// ---

// The net effect: Approximately 30 lines code are used to convert a randomly long number into words.
// The limit is set to "Vigintillion" (Can be increased)


import System.GUI
// Load Ring Libraries
   Load "guilib.ring"
   Load "stdlib.ring"

MyApp = New qApp {
   win1 = new qWidget() {
            setwindowtitle("Convert Digits to Words.")
            setGeometry(200,100,440,480)  // Pos Left/top - Right/bottom
          
         label1 = new qLabel(win1) {                   
            settext("Input: ")
            setGeometry(10,10,350,30)
            setalignment(Qt_AlignLeft)
         }

         label1 = new qLabel(win1) {
            settext("Output in Words: ")
            setGeometry(10,80,420,30)
            setalignment(Qt_AlignLeft)
         }
             
         label2 = new textedit(win1) {
            setstylesheet("color:#0055ff;background-color:white;")
            oFont = new qfont("",0,0,0)
            oFont.fromstring("Arial")
            setfont(oFont)
            oFont.delete()
            setText("Output ...")
            setGeometry(10,100,420,300)
         }
         
         btn1 = new qpushbutton(win1) {
               setGeometry(10,420,110,37)
               settext("Convert")
               setclickevent("pConvert()")
         }
         
         btn2 = new qpushbutton(win1) {
               setGeometry(150,420,110,37)
               settext("Close")
               setclickevent("pClose()")
         }
         
         lineedit1 = new qlineedit(win1) {
               setGeometry(10,30,420,30)
         }
         
         show()
     }
     exec()
}

//----------------------------------------------------------------------------------------
//                                 F u n c t i o n s:
//----------------------------------------------------------------------------------------

Func pConvert
   n = lineedit1.text() 		// Get Input
	
	n = substr(n,",","") 		// Replace any commas in n string input (BM)
   
   if len(n) < 63
      label2.settext(doGroup(n) )
   else label2.settext("Do you really have that much money?") 
   end

//----------------------------------------------------------------------------------------

Func pClose
        MyApp.quit()

//----------------------------------------------------------------------------------------

Func doWord(n)

   Ones = ["one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"]
   Tens = ["" , "twenty",  "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety"]

   // Input test:                	    // Possibly not complete
   // The zeros in the groups or whole null groups are not treated.
   // if n = "000" See "Zero-Group "+nl return end    // A null group
   
   if n =  "00" return end
   if n = "000"   rtn = "zero"   ok    // Zero thousand ?!?!
   
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

//end doWord()

//----------------------------------------------------------------------------------------

Func doGroup(n)                      	// Groups

   rtn     = " "
   doGroup = floor((len(n) +2) / 3)    // Number of groups
   Tsds    = ["","thousand "+nl, "million "+nl, "billion "+nl, "trillion "+nl, "quadrillion "+nl, "quintillion "+nl, "sextillion "+nl, "septillion "+nl, "octillion "+nl, "nonillion "+nl, "decillion "+nl, "undecillion "+nl, "duodecillion "+nl, "tredecillion "+nl, "quattuordecillion "+nl, "sexdecillion "+nl, "septendecillion "+nl, "octodecillion "+nl, "novemdecillion "+nl, "vigintillion "+nl]
     
   for x = 1 to doGroup -1             // Handle input
      gr = right(n, 3)                 // Determine group
      n  = left( n,len(n)-3 )          // Generate new number
      
      if gr = ""   gr = n   end        // If gr is blank, use "n"
      OldRtn = rtn     
      
      rtn = doWord(gr)                 // ===>>> CALL  (BM)
      
         if rtn != "zero"              // Handle "zero" units
            rtn =  rtn +" "+ Tsds[x] + OldRtn 
         else
            rtn =  OldRtn              // Ignore when "zero" thousand
         ok
         
   next                                //end-for
   oldRtn = rtn
   
   rtn = doWord(n) +" "+ Tsds[x] + OldRtn 
   

return rtn

// End doGroup()
//-----------------------------------------------------------------------------  end pgm
