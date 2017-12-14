/*
   app name: strings_binary
   author  : mhmd elabsawy
*/
#=================================================================#
cbinary = read(exefilename())
? cbinary
c=read('strings_binary.ring')
? c
write('copyofexe.exe',cbinary)
? 'copied'
write('copyofexe.exe',read(exefilename()))
? exefilename()
