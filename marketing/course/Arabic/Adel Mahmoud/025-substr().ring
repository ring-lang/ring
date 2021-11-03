/*
**	Application		:Substr()
**	Author			:Adel Mahmoud
**	Date			:2018.01.29
*/

#=========================================================
#                   
cString = "Welcome to my first Ring program in ring language."
? cString

? substr(cString,"Ring")			# Get Position of substring
? substr(cString,21,4)				# Get Number of Characters
? substr(cString,"Ring","***RING***")		# Replace substring (Case Sensitive)
? substr(cString,"Ring","***RING***",True)	# Replace (Not Case Sensitive)

#
#=========================================================


