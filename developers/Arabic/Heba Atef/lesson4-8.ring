/*       app:substr(),list functions
          author:heba atef
          date:26.12.2017
*/


cstring="welcome to the ring programming language(ring)"
?cstring
?substr(cstring,16,4)
?substr(cstring,"ring")
?substr(cstring,"ring"," *******heba*****",true)

alist=1:10
?alist
del(alist,5)
?alist
alist+"egypt"
alist+"ksa"
alist+"france"
?"egypt position:"+find(alist,"egypt")
alist=[
["mahmoud",100]
["ahmed",200]
["mohamed",300]
["ibrahim",400]
]
?alist[find(alist,"mohamed",1)][2]
