/*
**	Application    : Ring Lessons
**	Author 	       : Samer Hammadi
**	Date           : 17/12/2017
*/
#================================================================

? iswindows()
? islinux()
? ismacosx()
? isandroid()
? iswindows64()

cDir = currentdir()
? cDir
chdir("c:\ring")
? currentdir()
chdir(cDir)
? currentdir()
