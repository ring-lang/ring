/*
          Application        :Ring Lessons
          Author             :Islam Deraz
          Date               :2018.03.15
*/

load "openssllib.ring"

# md5() sha1() sha224() sha256() sha384() sha512()

# MD    = Message Digest
# SHA	= Secure Hash Algorithm

? "Enter Message: " give cmsg
? "MD5		= " + md5(cmsg)
? "sha1		= " + sha1(cmsg)
? "sha224	= " + sha224(cmsg)
? "sha384	= " + sha384(cmsg)

