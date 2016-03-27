see "===============" + nl
see "first test " + nl

try
	see "hello world" + NL
	x = 1 / 0
	SEE "error in try catch implementation!" + NL
catch
	see "nice" + nl
done

see "good" + nl

see "===============" + nl
see "Second test" + nl

try
	see "hello world" + NL
	SEE "nice" + NL
	
catch
	SEE "error in try catch implementation!" + NL
done

see "good" + nl
see "===============" + nl