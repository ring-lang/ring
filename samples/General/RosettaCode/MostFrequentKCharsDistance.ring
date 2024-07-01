# Project : Most frequent k chars distance
# Date    : 2018/02/16
# Author : Gal Zsolt (~ CalmoSoft ~)
# Email   : <calmosoft@gmail.com>
 
str1 = "LCLYTHIGRNIYYGSYLYSETWNTGIMLLLITMATAFMGYVLPWGQMSFWGATVITNLFSAIPYIGTNLV"
str2 = "EWIWGGFSVDKATLNRFFAFHFILPFTMVALAGVHLTFLHETGSNNPLGLTSDSDKIPFHPYYTIKDFLG"
see "Str1 = " + str1 + nl
see "Str2 = " + str2 + nl
 
MostFreqKHashing(str1,"str1")
MostFreqKHashing(str2,"str2")
 
func MostFreqKHashing(str3,strp)
        chr = list(26,2)
        for n = 1 to 26
             str = char(n+64)
             cstr = count(str3,str)
             chr[n][1] = str
             chr[n][2] = cstr
        next
        chr = sort(chr,2)
        chr = reverse(chr)
        see "MostFreqKHashing(" + strp + ",2) = "
        see chr[1][1] + chr[1][2] + chr[2][1] + chr[2][2] + nl
 
func count(cString,dString)
       sum = 0
       while substr(cString,dString) > 0
               sum++
               cString = substr(cString,substr(cString,dString)+len(string(sum)))
       end
       return sum
 
/*
Output:

Str1 = LCLYTHIGRNIYYGSYLYSETWNTGIMLLLITMATAFMGYVLPWGQMSFWGATVITNLFSAIPYIGTNLV
Str2 = EWIWGGFSVDKATLNRFFAFHFILPFTMVALAGVHLTFLHETGSNNPLGLTSDSDKIPFHPYYTIKDFLG
MostFreqKHashing(str1,2) = L9T8
MostFreqKHashing(str2,2) = F9L8

*/
