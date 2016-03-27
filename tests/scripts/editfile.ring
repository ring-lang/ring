for fn in ["ReadMe.txt", "ReadMe2.txt"]
     fp = fopen(fn,"r")
	if getFileSize(fp) != 0
	     str = fread(fp,getFileSize(fp)) 
	     str = substr(str, "Greetings", "Hello")
	
	     fclose(fp)

	     fp = fopen(fn,"w")
	     fwrite(fp, str)
	ok
     fclose(fp)
next

func getFileSize fp
       C_FILESTART = 0
       C_FILEEND = 2
       fseek(fp,0,C_FILEEND)
       nFileSize = ftell(fp)
       fseek(fp,0,C_FILESTART)
       return nFileSize