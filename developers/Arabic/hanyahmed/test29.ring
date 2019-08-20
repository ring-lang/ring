# variables types 
/*
*application     c object
*auther            : Hany Ibrahim Ahmed
*Date              : 21/12/2017
*/
# variables types (string,number,list,object,c object)
# libraries (ring,c,c++)
# web--> ....ring
# GUI--> ....c++,qtframework,ringqt+ring classes
# functions--> c,(pointer)

fb=fopen("test29.ring","r")
for x= 1 to 5 ?fgets(fb,100)next
?fb
fclose(fb)
