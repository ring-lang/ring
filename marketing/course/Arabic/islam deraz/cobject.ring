/*
          Application        :C Object
          Author             :Islam Deraz
          Date               :2018.02.16
          Application Number :13
*/ 
#variable Types (string, number, list, object, c object)

# Ring (compiler + VM) + libraries(GUI, Games, Web, etc)

# libraries (Ring--- c--- c++)

# Web--> Ring 
# GUI--> C++ (Qt + RingQt) + Ring classes
# Functions--> C (pointer)

fp = fopen("object.ring", "r")
for x = 1 to 5 ? fgets(fp,100) next
fclose(fp)

? fp
? type(fp)
