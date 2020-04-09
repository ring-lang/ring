/*
          Application        :Ring Lessons
          Author             :Islam Deraz
          Date               :2018.03.31
*/

func main 
	alist = 1:10
	? mypurefunction(alist)
	? alist


func mypurefunction alist	
	alist2 = alist		# Deep copy
	alist2[1] = "one"
	alist2[10] = "ten"
	return alist2
