/*
**	Application : string&objects&files
**	Author 	  : Sara Abozeina
**	Date		  :2017.12.18	
*/



new file{
		name="file.txt"
		mode="r+"
		nchars=10
		open()
}


new file{
		name="file1.txt"
		mode="r+"
		nchars=5
		open()
}

class file
	name  mode	nchars
	func open
		fh=fopen(name,mode)
			cString=fread(fh,50)
			?left(cString,nchars)
			?right(cString,nchars)						
		fclose(fh)
	
