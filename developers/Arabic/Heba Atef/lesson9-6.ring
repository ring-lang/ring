/*            application :encrypt,decrypt
                 author : heba atef
                  date :1.1.2018
*/
load "openssllib.ring"

see " enter a string : " give cstr 



ckey="my password"  
 civ ="my iv" 


cstr = encrypt(cstr,ckey,civ)

see "cipher text : " + cstr + nl +
"plain text : " + decrypt(cstr,ckey,civ) + nl


