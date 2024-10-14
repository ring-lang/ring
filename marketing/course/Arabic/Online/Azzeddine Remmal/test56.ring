
#####################################
# Application  :  Clock
# Author        : Azzeddine Remmal            
# Date           : 08.01.2018                  
####################################

t1 = clock()	

for x = 1 to 1000000
next 

? (clock() - t1)/ clockspersecond()
