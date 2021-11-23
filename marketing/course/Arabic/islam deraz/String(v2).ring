/*
          Application        :Variables (strings version 2)
          Author             :Islam Deraz
          Date               :2018.02.02
          Application Number :1
*/ 
# Variable types (string, number, list, object, c object)

? exefilename()  # ring.exe (console) - ringw.exe(GUI)

# Binary Data (memory - bytes (8-bit) )
# cpu - memory word - 32bit (4 bytes) (4*8 bits)

# memory ( Data - Code )

# binary data   -----> usage (8-bit)
# text              -----> 7-bit

# file (text or binary)
# text (*.txt)
# binary (*.exe, *.jpg, etc)

? read("test 9.ring")

mystring = read(exefilename())     # OR write  -----> write("myfile1.exe", read(exefilename()))

write("myfile.exe", mystring)

? "Done"

// ? mystring
