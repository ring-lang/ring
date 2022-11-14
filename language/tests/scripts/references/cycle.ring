for t=1 to 2
	a = ["start"]
	b = [:a = ref(a), :c = "c"]
	a[:b] = ref(b)
	? "A Size: " + len(a)
	? "B Size: " + len(b)
	? a[:b][:c]
	? b[:a][1]
	? copy("*",10)
next