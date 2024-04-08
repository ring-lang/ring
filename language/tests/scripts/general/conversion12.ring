# When we compare between number and a string 
# If we found the number --> Then we ignore Space, Tab, \n, \r after that number
# We consider "" to be like Zero but we don't do that for Space, Tab, \n and \r
# Note: if 0 -> False while if " " -> True 

? 1 =  "1  x"			# 0
? 1 = "1     "			# 1
? 0 = ""			# 1
? 0 = "       0        "	# 1	
? 1 = "       1       "		# 1
? 0 = "000000"			# 1
? 0 = "00000   			

"				# 1
? 1 = "       1 			



"				# 1

? 0 = " "			# 0 

if 0
	? :what
else
	? :good
ok

if ""
	? :what
else
	? :good
ok

if " "
	? :good
else
	? :what
ok

