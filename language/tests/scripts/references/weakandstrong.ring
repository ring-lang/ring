a = [[ref(a),ref(a),3],[4,5,6]]
? a
b = ref(a[1])	# Get Weak references to References inside a[1]  
? b     
b = NULL
? a
c = a[1]	# Get Strong references to References inside a[1]  
? c
c = NULL
? a
? :done