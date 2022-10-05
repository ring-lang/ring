/*
	name	:	Darsh Adam
	Lesson	:	دروس رينج
	Date 	:	23/12/2017
*/

#=====================================================
			# Ring Lessons 
#=====================================================


load "openssllib.ring"

? "Enter String : " give cstr
	list=0:15		# list [1,2,3...15]
	ckey=""			# 16 bytes
	for x in list
		ckey += char(x)
	next

	list=1:8		# list [1,2,3...8]
	civ=""			
	for x in list
		civ += char(x)
	next
cstr = encrypt(cstr,ckey,civ)
? "Cipher text : " + cstr
? "Plain  text : " + decrypt(cstr,ckey,civ)



