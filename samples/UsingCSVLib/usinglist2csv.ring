# Posted in Ring Group by Clement
# Updated by Fayed

load "csvlib.ring"

aList = []
add(aList, [1, 'ABC', 'CDE', 'XYZ', 100, 200, "test1"])

add(aList, [2, 'BOB', 'TOP', 'CAR', 1000, 2000, "test2"])

add(aList, ["one","two","three",1,2,3,"four",5])

write("csvdata.txt", list2CSV(aList))

getList = CSV2List(read("csvdata.txt"))

see getList