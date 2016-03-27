#c = "abcdefghijklmnopqrstuvwxyz" printasci(c) c = upper(c) printasci(c)
#func printasci c for x = 1 to len(c) see c[x] + " " see asci(c[x]) see nl next

c = "abcdefghijklmnopqrstuvwxyz" 
printasci(c) 
c = upper(c) 
printasci(c)
func printasci c 
	for x = 1 to len(c) 
		see c[x] + " " 
		n = asci(c[x])
		see n
		see " " + char(n)
		see nl 
	next
