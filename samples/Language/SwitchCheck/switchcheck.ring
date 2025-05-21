for x=0 to 16
	switch x
		on 0
			? :zero
		on check([1,2,3,4,5],x)
			? :low
		on check([6,7,8,9,10],x)
			? :high
		on check(11:15,x)
			? :extra
		on 16
			? :last
	off
next

func check(a1,value)
	if find(a1,value) return value ok
	return NULL