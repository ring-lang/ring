# The Ring Standard Library
# Common Functions and classes for applications
# 2016, Mahmoud Fayed <msfclipper@yahoo.com>

Load "stdfunctions.ring"
Load "stdbase.ring"
Load "stdlibcore.ring"

if IsMainSourceFile() 
	file_class_test()
ok

func file_class_test
	
	ofile = new file

	See "Test the file Class Methods" + nl
	see ofile.read(filename())

	see nl
	ofile.open(filename(),"r")
	see ofile.gets(100) + nl
	ofile.close()

Class file 

	filehandle 

	Func read cFileName
		return std_read(cFileName)

	Func write cFileName,cStr
		std_write(cFileName,cStr)

	Func dir cFolderPath
		return std_dir(cFolderPath)

	Func rename cOld,cNew
		std_rename(cOld,cNew)

	Func remove cFileName
		std_remove(cFileName)

	Func open cFileName,cMode
		filehandle = std_fopen(cFileName,cMode)
		return filehandle

	Func close  
		std_fclose(filehandle)

	Func flush  
		std_fflush(filehandle)

	Func reopen cFileName,cMode 
		return std_freopen(cFileName,cMode,FileHandle)

	Func tempfile
		return std_tempfile()

	Func seek noffset,nwhence
		return std_fseek(filehandle,noffset,nwhence)

	Func tell 
		return std_ftell(filehandle)

	Func rewind 
		return std_rewind(filehandle)

	Func getpos  
		return std_fgetpos(filehandle)

	Func setpos poshandle
		std_fsetpos(filehandle,poshandle)

	Func clearerr 
		std_clearerr(filehandle)

	Func eof  
		return std_feof(filehandle)

	Func error  
		return std_ferror(filehandle)

	Func perror cErrorMessage
		std_perror(cErrorMessage)

	Func getc  
		return std_fgetc(filehandle)

	Func gets nsize
		return std_fgets(filehandle,nsize)

	Func putc cchar
		std_fputc(filehandle,cchar)

	Func puts cStr
		std_fputs(filehandle,cStr)

	Func ungetc cchar
		std_ungetc(filehandle,cchar)

	Func fread nsize
		return std_fread(filehandle,nsize)

	Func fwrite cString
		std_fwrite(filehandle,cString)

	Func exists cFileName
		return std_fexists(cFileName)
