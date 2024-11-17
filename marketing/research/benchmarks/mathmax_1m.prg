clear
t1=seconds()
for t=1 to 1000000 
    r=max(t,t*2) 
next
t2 = seconds()
? t2-t1