// *** Step-3
// number to words 
// test three-digit numbers (1-999) with a function and recursion.

/*
Jetzt können wir Zahlen von 1 bis 99 in Worten ausgeben. Um eine komplette Gruppe von 3 Ziffern auszuwerten, benötigen wir noch eine kleine Erweiterung - die Hunderten. Wie funktioniert das? Einfach. Die erste Zahl eines Drillings ist immer eine Zahl von Hunderten:
    ...
     elseif len (n) = 3 // erster platz: hunderte
      z = rechts (n, 2)
h = (Etage (n / 100)) * 1 // Ermittle die Hunderte mit Math-Func .: Etage ()
      rtn = ones [h] + "hunderd"
      rtn = rtn + doWord (z) // und .. (Rekursion)
    ...

Die "Hunderte" werden in jeder Gruppe benötigt. es gibt nicht nur hundert als solche, sondern auch hunderttausend oder hunderttausend Millionen, sondern auch hunderttausend Milliarden. Unser Programm sollte so lange konvertieren können, wie Sie möchten. Dafür benötigen wir eine rekursive (selbstaufrufende) Funktion. 

Hier ist sie: doWord()
--
Now we can output numbers from 1 to 99 in words. In order to evaluate a complete group of 3 digits, we need a small extension - the hundreds. How does this work? Simple. The first number of a triplet is always a number of hundreds:
...
elseif len (n) = 3 // first place: hundreds
z = right (n, 2)
h = (Floor (n / 100)) * 1 // Find the hundreds with Math-Func.: Floor ()
rtn = ones [h] + "hunderd"
rtn = rtn + doWord (z) // and .. (recursion)
...

The "hundreds" are needed in each group. there are not only a hundred as such, but also a hundred thousand or a hundred thousand million,
but also a hundred thousand billion. Our program should be able to convert as long as you want. For this we need a recursive (self-calling) function.

Here it is: doWord ()
*/

load "stdlib.ring"				// need for string func.

n = "101"						// input
? "input: "+ n					// show input
? doWord(n)						// print the result in words

// -----------------------------------------------------------------------
func doWord(n)					// recursive (self-calling) function.
	ones=["one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"]
	
	tens=["" , "twenty",  "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety"]
	
	// the zeros in the groups or whole null groups are not treated.
	
	if n="000" see " Zero-Grp "+nl return end 	// a null group
	if n="00" return end
	if number(n)< 20 					// 1-19	
		n = number(n)					// convert to num
		rtn = ones[n]					// ret value 
	elseif n < 100						// 20-99
		n=n*1							// convert to num (another possib.)
		x = n % 10						// for ones
		y = floor(n / 10)  				// for tens
		if x = 0 rtn = tens[y]
		else rtn = tens[y] +" "+ ones[x]  // whole tens
		end 
	elseif len(n) = 3					// first place: hundreds
		z = right(n,2)
	 	h = (floor(n / 100)) *1			// Find out the hundreds
		rtn = ones[h] +" hunderd "
		rtn = rtn + doWord(z)			// And.. (Recursion)
	end //if
	return rtn							// pick up     
//? "doWord-rtn: "+rtn					// debug
//end-doWord()


/* 
Die hauptpart Logik ist fast gelöst. Jetzt brauchen wir nur noch eine schleife welche
Die eingegebene Nummer in drei Gruppen entsprechend den Gruppennamen unterteilt.

im naechsten schritt werden wir fuer die gruppenbildung eine funktion benoetigen:
die Gruppen Benennung.
--
The main part of the logic is almost solved. Now we just need a loop which The number entered is divided into three groups according to the group names.

In the next step we will need a function for group formation:
The Groups naming.
*/

//end *** part-03

