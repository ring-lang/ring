# This test program is written by Ilir Liburn

lst = [[1,2,3,4]]
for l in lst step 1
	for i in l step 2
		while len(l) > 0
			? "len > 0"
			while i > 1
				i = 1
				? "exit 2"
				exit 2				
			end
			? "exit 1"
			exit 1
		end
	next
next
? "done..."