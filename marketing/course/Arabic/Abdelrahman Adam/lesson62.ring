/*  
 **      Application : Ring Lessons
 **      name         : Abdelrahman Adam
 **      Date          :  22/12/2017 
*/ 
#======================================================

myFiles = dir("E:\ComputerApp\Ring1.6\Lesson7\")
aList = []
for aFile	in	myFiles
		if right(afile[1],5) = ".ring"	
			aList + aFile[1]
		ok
next

#Sort
aList = sort(aList)

# print file as list
x = 1
for afile in aList		
			?"("+ x+ ")" + aFile
			x++
next

# get the file
give nFile
nFile=0+ nFile
if	nfile < len(aList) 
	? read(aList[nFile]) 
ok
