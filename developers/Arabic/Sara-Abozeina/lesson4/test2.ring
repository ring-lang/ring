/*
**	Application : files & timelist()
**	Author 	  : Sara Abozeina
**	Date		  :2017.12.18	
*/


if clock()	
		t=clock()	
		if  clock()-t <=clockspersecond()
	
			savedtime=timelist()[5]
			fh=fopen("file1.txt", "r+")
			strings=fread(fh,50)
			fh=freopen("file2.txt", "r+",fh)
			fwrite(fh,strings)
			fh=freopen("file1.txt", "w+",fh)
			fwrite(fh,savedtime)	
			fclose(fh)
		ok
		? "the last  time, the file was  opened /run : " 
		? strings	
ok
