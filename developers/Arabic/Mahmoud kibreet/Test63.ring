/*
          Application : Ring Lessons
          Author      : Mahmoud Kibreet
          Date        : 2018.01.28
*/

? iswindows()
? islinux()
? ismacosx()
? ismsdos()
? iswindows64()
? isandroid()

cDir = currentdir()
? cDir
chdir("C:\")
? currentdir()
chdir(cDir)
? currentdir()

