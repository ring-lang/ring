# بسم الله الرحمن الرحيم
// this is Lesson3 -  thanks to Mr.MAHMOUD Fayed
/*
        Application: Simple Ring App ( Variables :Strings V2)
        Author     :  S.BOURROU
        Date       :  10.12.2017  

*/

# in Ring I can use String with Binary Files Directly 
# Cool  ! 

? exefilename() // ring.exe (Console) - ringw.exe(GUI)
? read("TEST9.ring") // read TEST file !   

myString = read(exefilename())
  
write("myfile.exe",myString)
# also :
write("myfile2.exe",read(exefilename()))
? "Done."
   
