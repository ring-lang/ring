/*
          Application        :Substr()
          Author             :Islam Deraz
          Date               :2018.02.14
          Application Number :9
*/ 
#variable Types (string, number, list, object, c object)

cstring= "Welcome to the Ring programming language (ring)"
? cstring

? substr(cstring,16,4)			# get number of characters
? substr(cstring,"Ring")		# get position of substring
? substr(cstring,"Ring","**Ring**")	# Replace substring  
? substr(cstring,"Ring","**Ring**",true)
