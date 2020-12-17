load "weblib.ring"
load "stdlib.ring"

func isFound(elName)
	found = false
	for x in aPageVars
		if find(x,elName)
			found = true
			exit
		ok
	next
	return found
