a = [[ref(a),ref(a),3],[4,5,6]]
? a
b = ref(a[1])	# Get Weak references to References inside a[1]  
		# And a Strong reference to the First item in a
? b     
? refcount(a)

b[1] = NULL
? refcount(a)

b[2] = NULL
? refcount(a)

? "============="
? a
? "============="
b = NULL
? a
? "============="
? len(a)
? len(a[1])
? type(a[1][1])
? type(a[1][2])
? type(a[1][3])