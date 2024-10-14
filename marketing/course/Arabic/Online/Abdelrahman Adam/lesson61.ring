/*  
 **      Application : Ring  Lessons
 **      Author      : Abdelrahman Adam
 **      Date        :  22/12/2017 
*/ 
#======================================================

myFiles = dir("E:\ComputerApp\Ring1.6\Lesson7\")

for aFile	in	myFiles
		if right(afile[1],5) = ".ring"	
			? "file : " + aFile[1]
			? read(aFile[1])
			? "///////////////////////////"
		ok
next
