/*            application : eval
                 author : heba atef
                  date :30.12.2017
*/
load "openssllib.ring"

# MD = message digest 
# SHA = secure hash algorithm


? "enter message : "  give cmsg 
? " MD5 = " + MD5(cmsg)
? " sha1 = " + sha1(cmsg)
?  " sha256 = " +sha256(cmsg)
