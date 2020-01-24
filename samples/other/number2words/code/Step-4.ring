// *** step 4
// number to words (illions)

n = "1234567898"
//n = "1000067"


doGruppen(n)

func doGruppen(n)
	rtn = " "
	anz_gr = floor((len(n)+2)/3)    	// anzahl gruppen
	
	// group names - the "thousands"
	tsds = ["","thousand ", "million ", "billion ", "trillion ", "quadrillion ", "quintillion ", "sextillion",
    "septillion", "octillion", "nonillion", "decillion", "undecillion", "duodecillion", "tredecillion",
    "quattuordecillion", "sexdecillion", "septendecillion", "octodecillion", "novemdecillion", "vigintillion "]
	
	for x = 1 to anz_gr-1				// eingabe abarbeiten
		gr = right(n,3)					// gruppe ermittelln
		n = left( n,len(n)-3 )			// neue nr generieren
		if gr = "" gr = n end			// wenn gr leer "n" nehmen
	  	rtn = gr+" "+ tsds[x] + rtn
	next  //end-for
	
	rtn = n +" "+ tsds[x] + rtn 
	? "In Words: "+ rtn				// Ausgabe
return rtn
//end	doGruppen
