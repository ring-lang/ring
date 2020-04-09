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
ckey="1234567890!@#$%^"
civ="87654321"
	

cstr = encrypt(cstr,ckey,civ)
? "Cipher text : " + cstr
? "Plain  text : " + decrypt(cstr,ckey,civ)



