# The Ring Standard Library
# Common Functions and classes for applications
# 2016, Mahmoud Fayed <msfclipper@yahoo.com>

# Standard Functions Wrapper
# To be called from classes contains methods with the same name

Func std_upper x
	return upper(x)

Func std_lower x
	return lower(x)

Func std_left cStr,x
	return left(cStr,x)

Func std_right cStr,x
	return right(cStr,x)

Func std_lines cStr
	return lines(cStr)

Func std_trim cStr
	return trim(cStr)

Func std_copy cStr,nCount
	return copy(cStr,nCount)

Func std_strcmp cStr1,cStr2
	return strcmp(cStr1,cStr2)

Func std_str2list cStr
	return str2list(cStr)

Func std_list2str aList
	return list2str(aList)

Func std_getsubstr cStr,nPos1,nPos2
	return substr(cStr,nPos1,nPos2)

Func std_getsubstrfrom cStr,nPos1
	return substr(cStr,nPos1)
	
Func std_substrpos cStr,cSubStr
	return substr(cStr,cSubStr)

Func std_substrreplace cStr,cSubStr1,cSubStr2
	return substr(cStr,cSubStr1,cSubStr2)

Func std_substrreplace_notcasesensitive cStr,cSubStr1,cSubStr2
	return substr(cStr,cSubStr1,cSubStr2,true)

Func std_add aList,vValue
	Add(aList , vValue)

Func std_del aList,nIndex
	Del(aList,nIndex)

Func std_find aList,vValue
	return Find(aList,vValue)

Func std_findincolumn aList,nCol,vValue
	return Find(aList,nCol,vValue)

Func std_sort aList
	return sort(aList)

Func std_reverse aList
	return reverse(aList)

Func std_insert aList,nIndex,Item
	Insert(aList,nIndex,Item)

Func std_sin x
	return sin(x)

Func std_cos x
	return cos(x)

Func std_tan x
	return tan(x)

Func std_asin x
	return asin(x)

Func std_acos x
	return acos(x)

Func std_atan x
	return atan(x)

Func std_atan2 x,y
	return atan2(x,y)

Func std_sinh x
	return sinh(x)

Func std_cosh x
	return cosh(x)

Func std_tanh x
	return tanh(x)

Func std_exp x
	return exp(x)

Func std_log x
	return log(x)

Func std_log10 x
	return log10(x)

Func std_ceil x
	return ceil(x)

Func std_floor x
	return floor(x)

Func std_fabs x
	return fabs(x)

Func std_pow x,y
	return pow(x,y)

Func std_sqrt x
	return sqrt(x)

Func std_random x
	return random(x)

Func std_unsigned n1,n2,c
	return unsigned(n1,n2,c)

Func std_decimals x
	return decimals(x)

Func std_clock
	return clock()

Func std_time
	return time()

Func std_date
	return date()

Func std_timelist
	return timelist()

Func std_adddays cDate,nDays
	return adddays(cDate,nDays)

Func std_diffdays cdate1,cdate2
	return diffdays(cdate1,cdate2)

Func std_read cFileName
	return read(cFileName)

Func std_write cFileName,cStr
	write(cFileName,cStr)

Func std_dir cFolderPath
	return dir(cFolderPath)

Func std_rename cOld,cNew
	rename(cOld,cNew)

Func std_remove cFileName
	remove(cFileName)

Func std_fopen cFileName,cMode
	return fopen(cFileName,cMode)

Func std_fclose filehandle
	fclose(filehandle)

Func fflush filehandle
	fflush(filehandle)

Func std_freopen cFileName,cMode,FileHandle
	return freopen(cFileName,cMode,FileHandle)

Func std_tempfile
	return tempfile()

Func std_fseek filehandle,noffset,nwhence
	return fseek(filehandle,noffset,nwhence)

Func std_ftell filehandle
	return fteel(filehandle)

Func std_rewind filehandle
	return rewind(filehandle)

Func std_fgetpos filehandle
	return fgetpos(filehandle)

Func std_fsetpos filehandle,poshandle
	fsetpos(filehandle,poshandle)

Func std_clearerr filehandle
	clearerr(filehandle)

Func std_feof filehandle
	return feof(filehandle)

Func std_ferror filehandle
	return ferror(filehandle)

Func std_perror cErrorMessage
	perror(cErrorMessage)

Func std_fgetc filehandle
	return fgetc(filehandle)

Func std_fgets filehandle,nsize
	return fgets(filehandle,nsize)

Func std_fputc filehandle,cchar
	fputc(filehandle,cchar)

Func std_fputs filehandle,cStr
	fputs(filehandle,cStr)

Func std_ungetc filehandle,cchar
	ungetc(filehandle,cchar)

Func std_fread filehandle,nsize
	return fread(filehandle,nsize)

Func std_fwrite filehandle,cString
	fwrite(filehandle,cString)

Func std_fexists cFileName
	return fexists(cFileName)

Func std_system cCommand
	system(cCommand)

Func std_get cVariable
	return get(cVariable)

Func std_ismsdos
	return ismsdos()

Func std_iswindows
	return iswindows()

Func std_iswindows64
	return iswindows64()

Func std_isunix
	return isunix()

Func std_ismacosx
	return ismacosx()

Func std_islinux
	return islinux()

Func std_isfreebsd
	return isfreebsd()

Func std_isandroid
	return isandroid()

Func std_windowsnl
	return windowsnl()

Func std_sysargv
	return sysargv

Func std_eval cCode
	return eval(cCode)

Func std_raise cError
	raise(cError)

Func std_assert cCondition
	assert(cCondition)

Func std_isstring vValue
	return isstring(vValue)

Func strd_isnumber vValue
	return isnumber(vValue)

Func std_islist vValue
	return islist(vValue)

Func std_type vValue
	return type(vValue)

Func std_isnull vValue
	return isnull(vValue)

Func std_isalnum vValue
	return isalnum(vValue)

Func std_isalpha vValue
	return isalpha(vValue)

Func std_iscntrl vValue
	return iscntrl(vValue)

Func std_isdigit vValue
	return isdigit(vValue)

Func std_isgraph vValue
	return isgraph(vValue)

Func std_islower vValue
	return islower(vValue)

Func std_isprint vValue
	return isprint(vValue)

Func std_ispunct vValue
	return ispunct(vValue)

Func std_isspace vValue
	return isspace(vValue)
