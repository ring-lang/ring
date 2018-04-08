load"openssllib.ring"

? "hi" give cmsg

? md5(cmsg)

? sha256(cmsg)



cstr= read (exefilename())

?   "size   " + len(cstr) +nl + 
"md5 "+  md5(cstr) +nl +sha512(cstr)

func main 


while true 
	? "enter expression " give cexpr
	if lower(trim(cexpr))= "exit"
		exit
	ok
try
 	?eval(cexpr)
catch 
	?"error"
done
end
