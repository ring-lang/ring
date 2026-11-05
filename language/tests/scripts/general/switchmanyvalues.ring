for t=0 to 10
	checkday(t)
next

func checkDay nDay

	switch nDay
	on 1,2,3,4,5
		? "Work"
	on 6, 7
		? "Vacation"
	other
		? "Error"
	off