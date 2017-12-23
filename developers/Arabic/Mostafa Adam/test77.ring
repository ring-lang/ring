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
 


cstr = read(exefilename())

? "Size   =" + len(cstr)
? "Size(Kb)" + (len(cstr)/1024)
? "MD5    =" +md5(cstr)
? "Sha1   =" + sha1(cstr)
? "Sha224 =" + sha224(cstr)
? "Sha384 =" + sha384(cstr)
? "sha256 =" + sha256(cstr)
? "sha512 =" + sha512(cstr)

