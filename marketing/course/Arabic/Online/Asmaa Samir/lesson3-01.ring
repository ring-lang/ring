/*
     Application : variables(strings) - version2
     Author        : Asmaa Samir
     Date           : 18-12-2017
*/

/*
  Compiler and virtual machine are found in exe file called ring.exe
  I can Get this file using exefilename() function
  each app(code)has its .exe file , say my current file will called lesson3-01.exe
  ring.exe  will work in case of console(command window) will appear first then application will work after that
  ringw.exe will work in case GUI (Run GUI application)
*/
?exefilename()
/*
32bit CPU --> Its memory word = 4 byte(4*8)bit
64bit CPU --> Its memory word = 8 byte(8*8)bit
--------------------
file is saved in memory (binary or text)where 
binary data use all 8 bits but 
text data use only 7 bit
text files such as .txt
binary files such as .exe,.jpg,.png,.....
so exefilename() Function read current .exe file(as binary data) 
and save it in string then display its content
---------------------------
string is used to define (character, array of characters, MultiLine Array, Binary Data , NULL)
"" =NULL="NULL" in Ring, we can initialize string with null, mystr=""
---------------------------
isNULL() is used to know if this variable is null or not
if true --> output is 1
if false--> output is 0
-------------------------------
we can not used uninitialized variable in ring.

*/

?  read(`lesson3-01.ring`)  # display content of current file
mystr = read(exefilename())
? mystr
write(`myfile.exe`, mystr)
? "Done"
isnull(mystr)
