# Author: Mansour Ayouni
# Revised by Fayed (Expected results after recent updates)


func main 

	? "1. varptr"
	nTotal = 7
	try 
		x = varptr("ntotal", "int")
		? "   lower 'ntotal' -> ok"
	catch 
		? "   lower 'ntotal' -> ERROR"
	done 
	try 
		x = varptr("nTotal", "int")
		? "   cased 'nTotal' -> ok"
	catch 
		? "   cased 'nTotal' -> R6 Variable is required"
	done 

	? ""
	? "2. ring_state_findvar"
	st = ring_state_init()
	ring_state_runcode(st, "nCount = 42")
	Show("   lower 'ncount'", ring_state_findvar(st, "ncount"))
	Show("   cased 'nCount'", ring_state_findvar(st, "nCount"))

	? ""
	? "3. ring_state_setvar"
	ring_state_setvar(st, "ncount", 99)
	ring_state_runcode(st, "? '   lower -> ' + nCount")
	try 
		ring_state_setvar(st, "nCount", 123)
		? "   cased -> ok"
	catch 
		? "   cased -> R6 Variable is required"
	done 

	? ""
	? "4. ring_state_newvar"
	st2 = ring_state_init()
	ring_state_newvar(st2, "nYear")
	ring_state_setvar(st2, "nYear", 2026)
	Show("   findvar 'nYear'", ring_state_findvar(st2, "nYear"))
	Show("   findvar 'nyear'", ring_state_findvar(st2, "nyear"))
	ring_state_runcode(st2, "? '   [' + nYear + ']'")

	
func Show cLabel, p 

	if isnumber(p) and p = 0
		? cLabel+" -> NOT FOUND"
	else 
		? cLabel+" -> found"
	ok 
	