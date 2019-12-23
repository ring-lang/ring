// *** Step-4
// number to words 
// thousands & milions

/*
dazu brauchen wir eine weitere liste. die liste der namen fuer die dreier gruppen - die "tausender" (tsds).
--
For this we need another list. the list of names for the three groups - the "thousands" (tsds).
*/

n = "1234567898"
//n = "1000067"


doGruppen(n)

func doGruppen(n)
	rtn = " "
	anz_gr = floor((len(n)+2)/3)    	// anzahl gruppen
	
	// group names - the "thousands"
	tsds = ["","thousand ", "million ", "billion ", "trillion ", "quadrillion ", "quintillion ", "sextillion", "septillion", "octillion", "nonillion", "decillion", "undecillion", "duodecillion", "tredecillion", "quattuordecillion", "sexdecillion", "septendecillion", "octodecillion", "novemdecillion", "vigintillion "]
	
	for x = 1 to anz_gr-1				// eingabe abarbeiten
		gr = right(n,3)					// gruppe ermittelln
		n = left( n,len(n)-3 )			// neue nr generieren
		if gr = "" gr = n end			// wenn gr leer "n" nehmen
	  	rtn = gr+" "+ tsds[x] + rtn
	next  //end-for
	
	rtn = n +" "+ tsds[x] + rtn 
	? "In Worten: "+ rtn				// Ausgabe
return rtn
//end	doGruppen

/*
die sache scheint gelaufen. jetzt muessen wir nur noch alle teile, die wir bis jetzt erstellt und einzel erfolgreich getestet haben, zsammenfügen. dies tuen wir im nächsten schritt.

--
The thing seems to have gone. now we only have to assemble all the parts that we have created and successfully tested individually. We do this in the next step.
*/
