/*
	Application	: Hash Functions
	Author		: Ahmed Mohamed
	Date		: 2019/10/24
*/

load "openssllib.ring"


# md5() sha1() sha256() sha384() sha512()

# MD = Message Digest
# SHA = Secure Hash Algorithm

see "Enter Message : " give cMessage
? "md5 		= " + md5(cMessage)
? "sha1 	= " + sha1(cMessage)
? "sha256 	= " + sha256(cMessage)
? "sha512 	= " + sha512(cMessage)
