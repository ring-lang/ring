" Ring Highlight In Vim Editor 
" Author Programmer-Om <omar.contact.mail@gmail.com>

syntax clear

" Ring keywords
syntax keyword RingLangKeyword again and but bye call case catch class def do done else elseif end exit for from func get give if import in load loop new next not off ok on or other package private put return see step switch to try while endfunc endclass endpackage endif endfor endwhile endswitch endtry function endfunction break continue
highlight link RingLangKeyword Keyword


syntax keyword RingLangBuiltInFunctions acos add adddays asin assert atan atan2 attributes binarysearch bytes2double bytes2float bytes2int ceil cfunctions char chdir checkoverflow classes classname clearerr clock clockspersecond closelib copy cos cosh currentdir date dec decimals del diffdays dir direxists double2bytes eval exefilename exefolder exp fabs fclose feof ferror fexists fflush fgetc fgetpos fgets filename find float2bytes floor fopen fputc fputs fread freopen fseek fsetpos ftell functions fwrite getarch getattribute getchar getfilesize getnumber getpathtype getpointer getptr getstring globals hex hex2str importpackage input insert int2bytes intvalue isalnum isalpha isandroid isattribute iscfunction isclass iscntrl isdigit isfreebsd isfunction isglobal isgraph islinux islist islocal islower ismacosx ismethod ismsdos isnull isnumber isobject ispackage ispackageclass ispointer isprint isprivateattribute isprivatemethod ispunct isspace isstring isunix isupper iswindows iswindows64 isxdigit left len lines list list2str loadlib locals log log10 lower max memcpy memorycopy mergemethods methods min murmur3hash newlist nofprocessors nothing nullpointer nullptr number obj2ptr object2pointer objectid optionalfunc packageclasses packagename packages parentclassname perror pointer2object pointer2string pointercompare pow prevfilename print print2str ptr2obj ptr2str ptrcmp puts raise random randomize read ref reference refcount remove rename reverse rewind right ring_give ring_see ring_state_delete ring_state_filetokens ring_state_findvar ring_state_init ring_state_main ring_state_mainfile ring_state_new ring_state_newvar ring_state_resume ring_state_runcode ring_state_runcodeatins ring_state_runfile ring_state_runobjectfile ring_state_scannererror ring_state_setvar ring_state_stringtokens ringvm_callfunc ringvm_calllist ringvm_cfunctionslist ringvm_classeslist ringvm_codelist ringvm_evalinscope ringvm_fileslist ringvm_functionslist ringvm_genarray ringvm_give ringvm_hideerrormsg ringvm_info ringvm_ismempool ringvm_memorylist ringvm_packageslist ringvm_passerror ringvm_runcode ringvm_scopescount ringvm_see ringvm_settrace ringvm_tracedata ringvm_traceevent ringvm_tracefunc setattribute setpointer setptr shutdown sin sinh sort space sqrt srandom str2hex str2hexcstyle str2list strcmp string substr swap sysget sysset syssleep system sysunset tan tanh tempfile tempname time timelist trim type ungetc unsigned upper uptime variablepointer varptr version windowsnl write
highlight RingLangBuiltInFunctions ctermfg=Red guifg=#FF6666


syntax keyword RingLangScannerCommands ChangeRingKeyword ChangeRingOperator DisableHashComments EnableHashComments LoadSyntax
highlight RingLangScannerCommands ctermfg=Green guifg=#00FF00

" Variables

syntax match RingLangVars /\<[a-zA-Z_][a-zA-Z_0-9$]*\>\|\[=!<>]/ 
highlight link RingLangVars Identifier

" Comments
syntax match RingLangComment "#.*"
syntax match RingLangComment "//.*"
highlight RingLangComment ctermfg=Gray guifg=#D3D3D3

syntax region RingLangMultiLineComment start="/\*" end="\*/"
highlight RingLangMultiLineComment ctermfg=Gray

" Strings
syntax match RingLangString /".*"/
highlight link RingLangString String

