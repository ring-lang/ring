// *** Step-1 
// number to words 
// test for: numbers 1-19 

/*
wir fangen klein an und schauen mal wie wir einfache 2er zahlen, die mit eins anfangen (1-19) 
in worte umwandeln.
dazu brauchen wir die zahlen-namen. diese erfassen wir in einem array (oder liste). diese benennen wir als "ones".
--
we start small and have a look at how we pay simple 2s starting with one (1-19)
to convert into words.
we need the number names for this. We capture these in an array (or list). We call these "ones".
*/

// units:
ones=["one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"]

n = "12"					// input as string (the number can be any length)
? "input: "+ n				// for control only

if number(n) > 19			// test input
	? "Incorrect input!"	// message
else
	? ones[number(n)]		// ones-element nr: 12 output: twelve
ok

/* 
gut.. der anfang ist die hälfte des ganzen. :D
gehen wir weiter.
--
well .. the beginning is half of the whole. :D
lets move on.
*/

//end *** part-01

