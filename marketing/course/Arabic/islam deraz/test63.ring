/*
          Application        :Ring Lessons
          Author             :Islam Deraz
          Date               :2018.03.13
*/

? iswindows()
? islinux()
? ismacosx()
? ismsdos()
? isandroid()

cDir = currentdir()
? cDir
chdir("c:\ring")
? currentdir()
chdir(cDir)
? currentdir()
