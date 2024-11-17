CLEAR
SET DECIMALS TO 3
t1=seconds()
for t=1 to 100000000 
    test() 
next
t2 = seconds()
? t2-t1

function test() 
RETURN 0