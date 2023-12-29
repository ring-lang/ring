# This example about mixing the next features 
#
# (1) Assignment
# (2) A unique feature in Ring
#     called (Using objects during definition) where the new object is stored directly in the variable
#     so we can use it (pass it as parameter to init() method OR access it through code inside braces)
#     This feature is common in RingQt samples
# (3) Comparing values 
#
# Special Thanks to Ilir Liburn who helped me to notice some problems related to this feature
# Which lead to this test program to explain the feature correctly and fix the discovered problems

p1 = new point
p2 = new point
p1 = p1 = p1		# 1 (True) --- The same object
? p1

p1 = new point
p2 = new point
p2 = p1 = p2		# 0 (False) --- Two different objects
? p2

? copy("=",20)

p1 = new point 
p1 = p1 = new point	# 0 (False) --- Two different objects
? p1

p1 = new point 		# This will be a surprise to you if you don't know about using objects during definition
p1 = new point = p1	# 1 (True) --- new point is stored directly in (p1) then we compare it to (p1)
? p1

p1 = new point 
p1 = (p1 = new point)	# 0 (False) --- Two different objects
? p1

p1 = new point 
p1 = (new point = p1)	# 0 (False) --- Two different objects
? p1

? copy("=",20)

p1 = 0
p1 = p1 = new point	# 0 (False) --- Two different values
? p1

p1 = 0			# This will be a surprise to you if you don't know about using objects during definition
p1 = new point = p1	# 1 (True) --- new point is stored directly in (p1) then we compare it to (p1)
? p1

p1 = 0
p1 = (p1 = new point)	# 0 (False) --- Two different values
? p1

p1 = 0
p1 = (new point = p1)	# 0 (False) --- Two different values
? p1

? copy("=",20)
p1 = 0
p1 = new point(p1) = p1	# The parameter (p1) will be the new object
? p1

p1 = 0
p1 = new point { 
	analysis(p1) # The parameter (p1) will be the new object
} = p1	
? p1


class point x y z

	func init para
		analysis(para)
		return self

	func analysis para
		? Type(para)