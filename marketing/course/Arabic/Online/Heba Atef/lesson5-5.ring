/*
 * Application : loop (for, while)
 * Author      : heba atef
 * Date        : 25.12.2017
*/

for x=1 to 10 
if x=3 
?"three"
loop 
ok 
?x 
if x=7 
exit 
ok
next

#=============
x=1 
while  x<10  
?x  
x++
end

x=1 
while true  ?"welcome"  
x++
if x=10 
exit
ok 
end



#==================================
#do again 
x=1
do 
?"hello"
again x>10
#=============
try    
1/0  
catch  
?"error" 
done 
