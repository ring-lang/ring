/*
**	Application	: getting the path and read &write files
**	Author		: Sara Abozeina
**	Date			: 2017.12.16	
*/

ringexepath=exefilename()
?ringexepath
fringcopy=read(ringexepath)
write("/home/sara/file2.exe",fringcopy)
?exefolder()
fhandle=fopen(exefolder()+"../developers/sara/lesson2/test2.ring","r")
strings=fread(fhandle,100)
?strings




