load "fastpro.ring"

aList = list(10,2)

updateColumn(aList,:serial,1,0)
updateColumn(aList,:serial,2,100)
? aList
? copy("*",20)

updateColumn(aList,:pow,1,2)
? aList
? copy("*",20)

updateColumn(aList,:rem,2,10)
? aList
? copy("*",20)
