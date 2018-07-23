# Project    ------> Files (*.ring)
# Program    ------> Statements
# Statements ------> Keywords + Expressions

see "Hello, World"   //see -> Keyword   //Hello -> Expression

see "Welcome" + nl   //New Line   
? "Hello"            //New Line 

? "One" + Tab + "Two" + Tab + "Three"   //Tab //Tab = char(9)
? ""
for x=1 to 10 
	see cr  //Carriage Return
	see x
next
? ""	
# ----------------------------------------------
/*
 *Note That : nl, tab & cr are variables. This Means That We Can
 *Change There Values.
*/
# Change Tab Value
Tab = char(9) + char(9)
? "One" + Tab + "Two" + Tab + "Three"   //Tab = char(9) + char(9)
 
# Change nl Value
/*
 *nl is not recognized in window text files so we can redefine
 *it to be suitable for windows systems.
*/
nl = windowsnl() //windowsnl() -> nl function in windows
                 //windowsnl() -> char(16) + char(10)
cString = "Hello" + nl + "How Are You"
write("test.txt", cString) //write string in test.txt text file
system("notepad test.txt") //system -> execute system instructions
