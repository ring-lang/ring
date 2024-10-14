# variables types 
/*
 * Application       : variables lists ver3
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

? alist [:name]
? alist [:job]
? alist [:country]

if alist [:city] = null alist [:city] = "Cairo" ok

? alist
