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

Func std_find2 aList,vValue,nColumn
	return Find(aList,vValue,nColumn)

Func std_find3 aList,vValue,nColumn,cAttribute
	return Find(aList,vValue,nColumn,cAttribute)

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
	return ftell(filehandle)

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
	return sysget(cVariable)

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

Func std_filename
	return filename()
	
Func std_eval cCode
	return eval(cCode)

Func std_raise cError
	raise(cError)

Func std_assert cCondition
	assert(cCondition)

Func std_isstring vValue
	return isstring(vValue)

Func std_isnumber vValue
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

Func std_isupper vValue
	return isupper(vValue)

Func std_isxdigit vValue
	return isxdigit(vValue)

Func std_number vValue
	return number(vValue)

Func std_string vValue
	return string(vValue)

Func std_ascii vValue
	return ascii(vValue)

Func std_char vValue
	return char(vValue)

Func std_hex vValue
	return hex(vValue)

Func std_dec vValue
	return dec(vValue)

Func std_str2hex vValue
	return str2hex(vValue)

Func std_hex2str vValue
	return hex2str(vValue)

Func std_odbc_init
	return odbc_init()

Func std_odbc_drivers oODBC
	return odbc_drivers(oODBC)

Func std_odbc_datasources oODBC
	return odbc_datasources(oODBC)

Func std_odbc_close oODBC
	return odbc_close(oODBC)

Func std_odbc_connect oODBC,cConString
	return odbc_connect(oODBC,cConString)

Func std_odbc_disconnect oODBC
	return odbc_disconnect(oODBC)

Func std_odbc_execute oODBC,cSQL
	return odbc_execute(oODBC,cSQL)

Func std_odbc_colcount oODBC
	return odbc_colcount(oODBC)

Func std_odbc_fetch oODBC
	return odbc_fetch(oODBC)

Func std_odbc_getdata oODBC,nCol
	return odbc_getdata(oODBC,nCol)

Func std_odbc_tables oODBC
	return odbc_tables(oODBC)

Func std_odbc_columns oODBC,cTableName
	return odbc_columns(oODBC,cTableName)

Func std_odbc_autocommit oODBC,lStatus
	return odbc_autocommit(oODBC,lStatus)

Func std_odbc_commit oODBC
	return odbc_commit(oODBC)

Func std_odbc_rollback oODBC
	return odbc_rollback(oODBC)

Func std_mysql_info
	return mysql_info()

Func std_mysql_init
	return mysql_init()

Func std_mysql_error oMySQL
	return mysql_error(oMySQL)

Func std_mysql_connect oMySQL,cServer,cUser,cPass,cDatabase
	return mysql_connect(oMySQL,cServer,cUser,cPass,cDatabase)

Func std_mysql_close oMySQL	
	return mysql_close(oMySQL)

Func std_mysql_query oMySQL,cQuery
	return mysql_query(oMySQL,cQuery)

Func std_mysql_insert_id
	return mysql_insert_id()

Func std_mysql_result oMySQL
	return mysql_result(oMySQL)

Func std_mysql_next_result oMySQL
	return mysql_next_result(oMySQL)

Func std_mysql_columns oMySQL
	return mysql_columns(oMySQL)

Func std_mysql_result2 oMySQL
	return mysql_result2(oMySQL)

Func std_mysql_escape_string oMySQL,cStr
	return mysql_escapse_string(oMySQL,cStr)

Func std_mysql_autocommit oMySQL,lStatus
	return mysql_autocommit(oMySQL,lStatus)

Func std_mysql_commit oMySQL
	return mysql_commit(oMySQL)

Func std_mysql_rollback oMySQL
	return mysql_rollback(oMySQL)

Func std_md5 cString
	return md5(cString)

Func std_sha1 cString
	return sha1(cString)

Func std_sha256 cString
	return sha256(cString)

Func std_sha512 cString
	return sha512(cString)

Func std_sha384 cString
	return sha384(cString)

Func std_sha224 cString
	return sha224(cString)

Func std_encrypt cString,cKey,cIV
	return encrypt(cString,cKey,cIV)

Func std_decrypt cString,cKey,cIV
	return decrypt(cString,cKey,cIV)

Func std_randbytes nSize
	return randbytes(nSize)

Func std_download cURL
	return download(cURL)

Func std_sendemail cSMTPServer,cEmail,cPassword,cSender,cReceiver,cCC,cTitle,cContent
	sendemail(cSMTPServer,cEmail,cPassword,cSender,cReceiver,cCC,cTitle,cContent)

Func std_swap aList,nItem1,nItem2
	swap(aList,nItem1,nItem2)
