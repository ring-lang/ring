load "fastpro.ring"

# Store [ [1,2,3], [4,5,6], [7,8,9] ] in aList
aList = [ 1:3,
          4:6,
          7:9 ]

updateList(aList,:set,:col,1,100)
updateList(aList,:mul,:col,2,10)
updateList(aList,:div,:col,3,3)

? aList