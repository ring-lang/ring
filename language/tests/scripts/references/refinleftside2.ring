for t=1 to 10
	tmp = new Temp { data="test" }
	tmp2 = ref(tmp)
	ref(tmp) = [1,2,3]
	tmp { 
		data="test2-"+t 
	}
	? tmp.data
next
? :done

class temp
	data