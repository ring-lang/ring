T1= CLOCK()
 

AFILEs= DIR("F:\ring\ring\omar selim")
for afile in afiles 
	? afile[1]
next
 
?  iswindows64()
? islinux()
? currentdir()
chdir("F:\ring\ring\omar selim")
? currentdir()
FOR X=1 TO 10000

NEXT  

? (CLOCK() -T1)/CLOckspersecond()

MYNUMBER=33


? TYPE (MYNUMBER)
? ISNUMBER(MYNUMBER)

?CHAR(99)
? ASCii("K")

FOR X=1 TO  255
	? " X= " + X + "="+ CHAR(X)
NEXT


? SIN(90)

? RANdom(100)
