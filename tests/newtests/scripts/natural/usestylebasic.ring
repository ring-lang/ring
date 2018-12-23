loadsyntax "natural/stylebasicon.ring"

x = 10
while x > 0
	print "x = " + x + nl
	for t = 1 to 10
		if t = 3
			print "number three" + nl
		endif
	endfor	

x--
endwhile

loadsyntax "natural/stylebasicoff.ring"


see "done" + nl
