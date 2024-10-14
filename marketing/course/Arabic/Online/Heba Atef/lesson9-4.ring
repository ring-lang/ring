/*            application : # function
                 author : heba atef
                  date :1.1.2018
*/
load "openssllib.ring"

cstr = read(exefilename())
see "size  : " + len(cstr)          + nl +
 
"md5 : " + md5(cstr)               + nl +

"sha1 : " +sha1(cstr)               +nl +

"sha256 : " +sha256(cstr)          +nl +
"sha224 : " +sha224(cstr)          +nl 
