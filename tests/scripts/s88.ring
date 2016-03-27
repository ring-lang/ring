main()

func main
x = "welcome"
letter(x)
see "first three letters : " + left(x,3) + nl
see "last three letters : " + right(x,3) + nl

SEE "Your name : " give cName
letter(cName)


func letter string
	for y = 1 to len(string)
		see string[y] + nl
	next

func left string,size
	cOut = ""
	for x = 1 to size
		cOut = cOut + string[x]
	next
	return cOut

func right string,size
	cOut = ""
	for x = len(string)-size+1 to len(string)
		cOut = cOut + string[x]
	next
	return cOut