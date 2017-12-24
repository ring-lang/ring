/*

   	Application         :List functions()
   	author                :Mahmoud Rabie 
	Date                   :2017/12/24  
*/

#===============================================================
aList  = 1:10
? alist
del(alist,5) 

? alist

alist + "Egypt"
alist + "KSA"
alist + "France"

? "Egypt position : "  +find(alist,"Egypt")
alist = [
          ["Mohammed"     ,100],
          ["Mahmoud"        ,200],
          ["Ahmed"            ,300],
          ["Ibrahim"            ,400]

]
? alist[find(alist,"Mohammed",1)] [2]
? alist[find(alist,"Ahmed",1)] [2]
