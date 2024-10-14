/*

   	Application         :substr()
   	author                :Mahmoud Rabie 
	Date                   :2017/12/24  
*/

#===============================================================
cString = "welcome to the Ring programming language (ring)"

? cString

? substr(cstring, 16,4)
? substr(cString,"Ring")
? substr(cString,"Ring","***Ring***")
         
? substr(cString,"Ring","***Ring***",True)
