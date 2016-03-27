See "Testing file functions" + nl

See "open file" + nl
fp = fopen("tests\s65.nova","r")

See "flush" + nl
fflush(fp)

See "reopen" + nl
fp = freopen("tests\s78.nova","r",fp)
See "close file" + nl
fclose(fp)

see "temp file" + nl
fp = tempfile()
fclose(fp)

see "temp name" + nl
see tempname() + nl

remove("tests\mytest1.txt")
write("tests\test1.txt","hello")
rename("tests\test1.txt","tests\mytest2.txt")

see "print file" + nl
fp = fopen("tests\file.nova","r")
r = fgetc(fp)
while isstring(r)
	see r
	r = fgetc(fp)
end
fclose(fp)

see nl+"print line from the file" + nl
fp = fopen("tests\file.nova","r")
r = fgets(fp,100)
see r
fclose(fp)

fp = fopen("tests\myfile.txt","rw+")
fseek(fp,0,2) # goto end of file
fputc(fp,"t")
fputc(fp,"e")
fputc(fp,"s")
fputc(fp,"t")
fputs(fp,"test2")
fclose(fp)
see "print file" + nl
see read("tests\myfile.txt")

fp = fopen("tests\myfile.txt","r")
see "testing ungetc() " + nl
for x = 1 to 3
	r =  fgetc(fp)
	see r + nl
	ungetc(fp,r)
next
fclose(fp)

see "testing fread() " + nl
fp = fopen("ring.exe","r")
r = fread(fp,100)
see r + nl
fclose(fp)

see "testing fwrite() " + nl
fp = fopen("tests\myfile.txt","wb")
fwrite(fp,r)
fclose(fp)
