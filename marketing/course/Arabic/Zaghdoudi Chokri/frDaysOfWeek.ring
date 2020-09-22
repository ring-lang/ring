/*
	Desc     Learning Ring Programming
	Aut      Zaghdoudi Chokri
	Date     22/09/2020
*/
load "stdlib.ring"

func main
	? copy("=",9)
	? getOneFrDayOfWeek("2020/09/22")
	? copy("=",9)
	see getAllFrDaysOfWeek("2000/09/07")
	? copy("=",9)
	? getAllFrDaysOfWeek("2000/09/07")[7]

func getAllFrDaysOfWeek cDate
	aJours = []
	for x=1 to 7
		cJour = left(cDate,9) + x
		switch dayofweek(cJour)
			on "monday"
				cJour = "lundi"
			on "tuesday"
				cJour = "mardi"
			on "wednesday"
				cJour = "mercredi"
			on "thursday"
				cJour = "jeudi"
			on "friday"
				cJour = "vendredi"
			on "saturday"
				cJour = "samedi"
			on "sunday"
				cJour = "dimanche"
			other
				cJour = "inconnue!!"
		off

		add(aJours,cJour)
	next
	
	return aJours

func getOneFrDayOfWeek cDate
	//date = lower(date)
	cJour = null
	switch dayofweek(cDate)
		on "monday"
			cJour = "lundi"
		on "tuesday"
			cJour = "mardi"
		on "wednesday"
			cJour = "mercredi"
		on "thursday"
			cJour = "jeudi"
		on "friday"
			cJour = "vendredi"
		on "saturday"
			cJour = "samedi"
		on "sunday"
			cJour = "dimanche"
		other
			cJour = "inconnue!!"
	off

	return cJour
