aList = 1:10
? refcount(aList)
ref1 = ref(aList)
? refcount(aList)
ref(aList)		# This set lNewRef to 1
ref(aList)
? refcount(aList)
? refcount(ref1)
ref1 = NULL		# will this be like ref(ref1)=NULL which does nothing
			# OR Ring will be smart and set lNewRef to 0
			# And treat this as normal assignment
? "before"
? ref1
? "after"
? refcount(aList)
? refcount(ref1)
? copy("*",10)
? aList