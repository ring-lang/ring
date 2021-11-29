# variables types 
/*
 * Application       : list functions
 * Author            : Hany Ibrahim Ahmed
 * Date              : 20/12/2017
 */
# variables types (string, number, list, object, c object)

alist = 1:10
? alist

del(alist,5)
? alist

alist + "EGYPT"
alist + "KSA"
alist + "FRANCE"
? "Egypt position:" + find(alist,"EGYPT")

alist= [
    ["mohamed",100],
    ["mohmoud",200],
    ["ahmed",300],
    ["ibrahim",400]
]
? alist[find(alist,"mohamed",1)][2]
? alist[find(alist,"ahmed",1)][2]
