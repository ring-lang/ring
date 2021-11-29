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
	ckey=""			# 16 bytes
	for x=0 to 15
		ckey += char(x)
	next

	civ=""			
	for x=1 to 8
		civ += char(x)
	next
cstr = encrypt(cstr,ckey,civ)
? "Cipher text : " + cstr
? "Plain  text : " + decrypt(cstr,ckey,civ)
