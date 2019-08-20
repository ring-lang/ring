/*                 application:(clock) 
                    author:heba atef 
       */
t1 = clock()

for x=1 to 1000000 
next 
? (clock() - t1 )/clockspersecond()
