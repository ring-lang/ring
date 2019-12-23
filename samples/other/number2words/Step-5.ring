// *** Step-5
// number to words 

// efective (netto) approximately 30 lines of code for an arbitrary number of words.
// currently limited by tsds ["vigintillion"] (can be traced)
//--
# Efektiv approximately >30 lines code for a randomly long number in words spend.
# currently limited by "vigintillion" (can be retraced)

# datum: 20.02.2018 

# Load Ring Libraries
    Load "stdlib.ring"

// beispiele:
pConvert("1234567")
pConvert("10000009") 	// zero-group: "000" not (not well solved yet)
pConvert("103010009")
pConvert("103000109")	// zero-group: "000" not (not well solved yet)
pConvert("103406789")
pConvert("103400789")
pConvert("103400009")
pConvert("123456789")
pConvert("123456789123456789123456")
pConvert("12345678912345678912345678912345678912345678912345678912345678")
pConvert("12300456789003456780123056")

//----------------------------------------------------------------------
Func pConvert(n)
	if len(n) < 63
		? "Input: "+n
		doGruppen(n) 
	else 
		? "Do you really have that much money? ;)"
	end
//end-pConvert	

//----------------------------------------------------------------------
func doWord(n)
	ones=["one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"]
	
	tens=["" , "twenty",  "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety"]
	
	// input test:						// possibly not kommplett
	// the zeros in the groups or whole null groups are not treated.
	//if n="000" see " Zero-Grp "+nl return end // a null group
	if n="00" return end
	if n="000" rtn = "zero" ok
	if number(n)< 20 and n!="000"		// 1-19	
		n=n*1							// convert to num 
		rtn = ones[n]					// ret value 
	elseif n < 100	and n!="000"		// 20-99
		n=n*1							// convert to num 
		x = n % 10						// for ones
		y = floor(n / 10)  				// for tens
		if x = 0 rtn = tens[y]
		else rtn = tens[y] +" "+ ones[x]  // whole tens
		end 
	elseif len(n) = 3 and n!="000"		// first place: hundreds
		z = right(n,2)
	 	h = (floor(n / 100)) *1			// Find out the hundreds
		rtn = ones[h] +" hundert "
		rtn = rtn + doWord(z)			// And.. (recursive deal)
	end //if
	return rtn							// ..pick up     
//? "doWord-rtn: "+rtn					// for debug only
//end-doWord()

//----------------------------------------------------------------------
func doGruppen(n)
	rtn = " "
	anz_gr = floor((len(n)+2)/3)    	// number of groups
	tsds = ["","thousand ", "million ", "billion ", "trillion ", "quadrillion ", "quintillion ", "sextillion", "septillion", "octillion", "nonillion", "decillion", "undecillion", "duodecillion", "tredecillion", "quattuordecillion", "sexdecillion", "septendecillion", "octodecillion", "novemdecillion", "vigintillion "]
	for x = 1 to anz_gr-1				// execute input
		gr = right(n,3)					// determine group
		n = left( n,len(n)-3 )			// generate new nr
		if gr = "" gr = n end			// if gr blank take: "n"
	  	rtn = doWord(gr) +" "+ tsds[x] + rtn
	next  //end-for
	rtn = doWord(n) +" "+ tsds[x] + rtn 
	? "In Worten: "+ rtn				// output
return rtn
//end	doGruppen
