load "guilib.ring"

new qApp
{
	see "Test Regular Expressions" + nl

	exp = new qregularexpression() {
		setPattern("\d\d \w+")
		see pattern() + nl
		match = match("33 one",0,0,0)
		see match.hasmatch() + nl
		match = match("3 one",0,0,0)
		see match.hasmatch() + nl
		match = match("welcome 11 one",0,0,0)
		see match.hasmatch() + nl
		matched = match.captured(0)
		see matched + nl
	}
	exp = new qregularexpression() {
		setPattern("^(\d\d)/(\d\d)/(\d\d\d\d)$")
		see pattern() + nl
		match = match("08/12/1985",0,0,0)
		see match.hasmatch() + nl
		day = match.captured(1)
		month = match.captured(2)
		year = match.captured(3)
		see day + nl + month + nl + year + nl
		see  "(" + match.capturedStart(1) + "," + match.capturedEnd(1)+ ")" + nl
		see  "(" + match.capturedStart(2) + "," + match.capturedEnd(2)+ ")" + nl
		see  "(" + match.capturedStart(3) + "," + match.capturedEnd(3)+ ")" + nl
	}

}
