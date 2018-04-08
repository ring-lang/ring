#####################################
# Application  : Ring Lessons
# Author        : Azzeddine Remmal            
# Date           : 09.01.2018                  
####################################



aFiles = dir("b:/ring/developers/arabic/mahmoud")

for aFile in aFiles 
	if right(aFile[1],5) = ".ring"
		? "File : " + aFile[1]
		? read(aFile[1])
	ok
next 
