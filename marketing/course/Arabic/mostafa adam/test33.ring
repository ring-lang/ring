/*
	name	:	Darsh Adam
	Lesson	:	test33.ring
	Date 	:	16/12/2017
*/
		// if , For , While 

#=====================================================
	/* Condition ----> True \ False */
#=====================================================

alist = [:one, :two, :three]

for iitem in alist 

	? iitem 
	switch iitem
	case :one		iitem = 1
	case :two 		iitem = 2
	case :three		iitem = 3
	else  			iitem = 0
	end
end
	? alist

#=====================================================

alist = [:one, :two, :three]

for iitem in alist {

	? iitem 
	switch iitem { 
	case :one		iitem = 1
	case :two 		iitem = 2
	case :three		iitem = 3
	else  			iitem = 0
	}
}
	? alist

#=================End Of Lesson===================#

#=================End Of Program==================#
