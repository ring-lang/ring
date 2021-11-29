/*
 * Application       : Object
 * Author            : Hany Ibrahim Ahmed
 * Date              : 22/12/2017
 */

# variables types (string,number,list,object,c object) 
# Project---->files(*.ring)
# control structures----->while ,for ,if ,do,try,exit.....ver 9
 

for x= 1 to 10 {
	for y= 1 to 10 {
	? "x= " + x + " y= " + y
		if x=3 && y=5 {
		exit 2
		}
	}
}
? "done"

# condition (and   or    not)
# condition (&&   ||   !)

x=10
y=20
if x=10 && y=10 {
? "first"
}
if x=10 || y=10 {
? "second"
}
