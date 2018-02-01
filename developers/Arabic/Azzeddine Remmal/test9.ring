
#############################################
# Application : Variables (Strings) - Version2
# Author      : Azzeddine Remmal            
# Date        : 03.01.2018                  
#############################################

# ----------Variable Types (String, Number, List, Object, C Object)

? exefilename()            			# ----------ring.exe (console) - ringw.exe (GUI)



? read("test9.ring")

mystring = read(exefilename())
write("myfile.exe",mystring)
? "Done"

write("myfile2.exe",read(exefilename()))
