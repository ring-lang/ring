/*
	name	:	Darsh Adam
	Lesson	:	دروس رينج
	Date 	:	23/12/2017
*/

#=====================================================
			# Ring Lessons 
#=====================================================

# Hash

load "openssllib.ring"
 
? "Enter message :" give cstr
? "MD5 = " +md5(cstr)
? "Sha1 =" + sha1(cstr)
? "sha256 =" + sha256(cstr)
? "sha512 =" + sha512(cstr)

