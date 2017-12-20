# بسم الله الرحمن الرحيم
// this is Lesson7 -  thanks to Mr.MAHMOUD FAYED
/*
  Application:  functions: dir()
  Author     :  S.BOURROU
  Date       :  18.12.2017  
*/

myfile = dir("E:\ring\developers\arabic\S.Bourrou") # file path

for afile in myFile 
	if right(afile[1],5) = ".ring"
	? "File:" + afile[1]
	? read(afile[1])
	ok
next 

	

