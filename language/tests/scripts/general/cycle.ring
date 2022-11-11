for t=1 to 2
	a = ["start"]
	b = [:a = ref(a), :c = "c"]
	a[:b] = ref(b)
	? "A Size: " + len(a)
	? a
	? "B Size: " + len(b)
	? b
	? copy("*",10)
next