/*
	Application : Ring Lessons
	Author      : Salwa Abdrabu
*/

aFiles = dir("C:\RingTest")

for aFile in aFiles 

if right(aFile[1],5) = ".ring"
	? "File :" + aFile[1]
	? "===================="
	? read(aFile[1])
ok

next
