/*
**	Application Name : system file;
**	Author           : Ahmed Elskaan;
**	Date             : 2017-12-18;		
*/

? iswindows()
? islinux()
? ismacosx()
? iswindows64()

mainDir =  currentdir()
chdir("c:\ring")
? currentdir()
chdir(mainDir)
? currentdir()

