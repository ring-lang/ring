load "fastpro.ring"

aList = [
        1:3,
        4:6,
        7:9
]

# Starting from row 1 to row 2, set each value to 100
updateList(aList,:set,:manyrows,1,2,100)
# Starting from row 2 to row 3, multiply each value by 10
updateList(aList,:mul,:manyrows,2,3,10)

? aList