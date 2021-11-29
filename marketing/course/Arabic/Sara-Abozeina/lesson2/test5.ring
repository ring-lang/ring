/*
**	Application 	: Choose number and enter it by keyboard-stdlib
**	Author		: Sara Abozeina
**	Date			: 2017.12.16
*/

load "stdlib.ring"
print("please , Enter your name ")
cName=getstring()
print("please , Enter number from list \n [0,1,2]\n")
nId=getnumber()
nId=0+nId

if random(2)=nId
	print("Good Luck ,\t#{cName}")
else
	print("sorry , bad luck")
ok


