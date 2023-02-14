aList = list(3)

? "Assign values!"
first()  = :one
second() = :two
third()  = :three

? "Print values!"
first()
second()
third()

func first
	if aList[1]=0 aList[1]=[] return aList[1] ok 
	? aList[1]

func second
	if aList[2]=0 aList[2]=[] return aList[2] ok 
	? aList[2]

func third  
	if aList[3]=0 aList[3]=[] return aList[3] ok 
	? aList[3]
