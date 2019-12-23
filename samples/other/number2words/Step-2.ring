// *** Step-2
// number to words
// test two-digit numbers (1-99)

/*
was ist noetig um zahlen groesser als 19 zu umwandeln? 
wir brauchen eine weitere namen liste, die "tens" (ganze zahlen) die wir mit den "ones" kombinieren werden.
--
what is needed to pay more than 19 to convert?
we need another name list, the "tens" (whole numbers) that we will combine with the "ones".
*/

load "stdlib.ring"						// need for string func.

// units:
ones=["one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"]

// tens:	(whole numbers)
tens=["" , "twenty",  "thirty", "fourty", "fifty", "sixty", "seventy", "eighty", "ninety"]

n = "29"
? "len(n): "+len(n)						// n: is string
? "first digit: "+n[1]					// first digit
? "second digit: "+n[2]					// second digit
? "input: "+ n

if number(n) > 99						// test 
	? "Incorrect input!"				// message
end

if number(n[1]) > 1 and number(n[2]) > 0
		? tens[number(n[1])] +"-"+ ones[number(n[2])]
	elseif number(n[2]) = 0
		? tens[number(n[1])]
end

/* 
prima.. das haut ja! :)
mit den hier entwickelten zwei teilen ist die ganze logik beinahe geloest.
im naechsten schritt werden wir fuer die gruppenbildung eine funktion benoetigen:
dir "Hunderter" benennung.
-- 
great.. that works.. yeah! :)
with the two parts developed here, the whole logic is almost solved.
in the next step we will need a function for group formation:
the "Hundreds" term.
*/

//end *** part-02

