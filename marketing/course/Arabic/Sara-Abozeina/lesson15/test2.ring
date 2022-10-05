/*
**	Application:functional programming
**	Author	   :Sara Abozeina
**	Date       :2018.01.02
*/
###############
/*
anonymous function with paras
*/
###############
load"stdlib.ring"

f1=func {?"Hello world!"}
callfunc(f1)
f2=func {

}
callfunc(f2)

f3=func x,y {?"see the simple syntax! that is the code" 
		?x+y
}
	
call f3(3,5)

f4=func cFileName {alist=File2List(cFileName) 
			for x=1 to len(alist)
				?alist[x]
			next
			list2file(alist,"newfile.txt")

}
call f4(filename())

func callfunc f
	call f()
