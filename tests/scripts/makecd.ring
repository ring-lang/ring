db = []

func main
	add(db,makecd ("Roses", "Kathy Mattea" ,7, true))
	add(db,makecd ("Fly" ,"Dixie Chicks", 8, true))
	add(db,makecd ("Home" ,"Dixie Chicks", 9, true))
	dumpdb()

func makecd title,artist,rating,ripped
	return [title,artist,rating,ripped]

func dumpdb 
	for cd in db
		see "Title  : " + cd[1] + nl + 
			"Artist : " + cd[2] + nl + 
			"Rating : " + cd[3] + nl + 
			"Ripped : " + cd[4] + nl
	next