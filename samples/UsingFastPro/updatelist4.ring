load "fastpro.ring"

aList = 1:5

updateList(aList,:set,:items,1000)
updateList(aList,:mul,:items,2)
? aList