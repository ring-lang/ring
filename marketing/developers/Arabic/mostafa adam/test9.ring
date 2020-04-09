/*
	name 		: Mostafa Abdullah Adam 
	App 		: Test 9 ( variables " string" v . 2   ) 
	Date 		: 2017-12-11 
*/ 

# Variables types 

# Variables types ( str , num , list , obj , c obj )
? exefilename()

/* 
	bytes = 8 bit 
	memory word = if ( 32 bit ) == 4*8 bit 
	binary data use 8 bit 
	text use 7 bit
	text 	 ---> *.text , * . doc 
	binary	 ---> *.exe , * jpg .... etc
*/

? read("text9.ring")
mystring = read(exefilename())
// ? mystring
write("myfile.exe", mystring)
write("myfile2.exe",read(exefilename()))

#see read(exefilename())
// مجرد بجرب طريقة تانية 
