/*
	Application 	: Ring Lessons
	Author		: Mahmoud Fayed
	Date		: 2017.12.15
*/

? iswindows()
? islinux()
? ismacosx()
? ismsdos()
? iswindows64()
? isandroid()

cDir = currentdir()
? cDir
chdir("b:\ring")
? currentdir()
chdir(cDir)
? currentdir()
