/*
	Application	: System Functions
	Author		: Ahmed Mohamed
	Date		: 2019/10/16
*/

? iswindows()
? islinux()
? ismacosx()
? ismsdos()
? iswindows64()
? isandroid()

cDir = currentdir()
? cDir
chdir("C:\ring")
? currentdir()
chdir(cDir)
? currentdir()
		
