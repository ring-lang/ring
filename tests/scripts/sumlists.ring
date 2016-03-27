see sum ([1,2,3],[4,5,6])

func sum x,y
	t = []
	if len(x) != len(y) raise("Error arrays length is not equal!") ok
	for i = 1 to len(x)
		t + (x[i] + y[i])
	next
	return t