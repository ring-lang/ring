# The Ring Standard Library
# Common Functions and classes for applications
# 2016, Mahmoud Fayed <msfclipper@yahoo.com>

if filename() = sysargv[2]
	eval("Load 'stdfunctions.ring'")
	eval("Load 'stdbase.ring'")
	file_class_test()
ok

func file_class_test
	
	ofile = new file

	See "Test the file Class Methods" + nl

Class file 

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

	Func fopen cFileName,cMode
		return std_fopen(cFileName,cMode)

	Func fclose filehandle
		std_fclose(filehandle)

	Func fflush filehandle
		std_fflush(filehandle)

	Func freopen cFileName,cMode,FileHandle
		return std_freopen(cFileName,cMode,FileHandle)

	Func tempfile
		return std_tempfile()

	Func fseek filehandle,noffset,nwhence
		return std_fseek(filehandle,noffset,nwhence)

	Func ftell filehandle
		return std_fteel(filehandle)

	Func rewind filehandle
		return std_rewind(filehandle)

	Func fgetpos filehandle
		return std_fgetpos(filehandle)

	Func fsetpos filehandle,poshandle
		std_fsetpos(filehandle,poshandle)

	Func clearerr filehandle
		std_clearerr(filehandle)

	Func feof filehandle
		return std_feof(filehandle)

	Func ferror filehandle
		return std_ferror(filehandle)

	Func perror cErrorMessage
		std_perror(cErrorMessage)

	Func fgetc filehandle
		return std_fgetc(filehandle)

	Func fgets filehandle,nsize
		return std_fgets(filehandle,nsize)

	Func fputc filehandle,cchar
		std_fputc(filehandle,cchar)

	Func fputs filehandle,cStr
		fputs(filehandle,cStr)

	Func ungetc filehandle,cchar
		std_ungetc(filehandle,cchar)

	Func fread filehandle,nsize
		return std_fread(filehandle,nsize)

	Func fwrite filehandle,cString
		std_fwrite(filehandle,cString)

	Func fexists cFileName
		return std_fexists(cFileName)
