# variables types 
/*
 * Application       : variables lists ver4
 * Author            : Hany Ibrahim Ahmed
 * Date              : 19/12/2017
 */
# variables types (string, number, list, object, c object)
alist= [
	:name    = "Hany Ibrahim",
	:job     = "Programmer",
	:country = "Egypt",
	:city    = "Alex"
]

? "size" + len(alist)
for aitem in alist
? aitem [2]
next
