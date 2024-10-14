# variables types 
/*
 * Application       : C Object
 * Author            : Hany Ibrahim Ahmed
 * Date              : 21/12/2017
 */
# Variables types (string, number, list, object, c object)
# Libraries (ring, c, c++)
# Web--> ....ring
# GUI--> ....C++, Qt Framework, RingQt + Ring classes
# Functions--> C, (pointer)

fb = fopen("test29.ring","r")
for x= 1 to 5 ? fgets(fb, 100) next
? fb
fclose(fb)
