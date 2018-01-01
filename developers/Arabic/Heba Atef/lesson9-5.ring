/*            application :encrypt,decrypt
                 author : heba atef
                  date :1.1.2018
*/
load "openssllib.ring"

see " enter a string : " give cstr 



list = 0:15   ckey=""  for x in list ckey += char(x) next 
list = 1:8     civ =""  for x in list civ += char(x) next 


cstr = encrypt(cstr,ckey,civ)




see "cipher text : " + cstr + nl +





"plain text : " + decrypt(cstr,ckey,civ) +nl
