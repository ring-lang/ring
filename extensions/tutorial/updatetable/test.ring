load "stdlib.ring"

? "Loading Library"
load "mylib.ring"

? "Calling a C Function"
myfunction()

? "Sum Two Numbers (3,5)"
? SumTwoNumbers(3,5)

? "Say Hello"
SayHello("Mahmoud")

? "Sum List contains numbers from 1 to 10"
aList = 1:10
? SumList(aList)

? "Increment List Items"
? inclist(aList,10)

? "Filter List Items (Items > 15)"
? filterlist(aList,15)

aList = 1:3
? "Replicate list (1:3) three times then print the items (We expect 12 items)"
? replicatelist(aList,3)

? "Create list contains 5 items using C code"
aList = GenerateList(5)
? aList

? "Create List (3,2)"
aList = newList(3,2)
aList[1][1] = "R 1 C 1"
aList[1][2] = "R 1 C 2"
aList[2][1] = "R 2 C 1"
aList[2][2] = "R 2 C 2"
aList[3][1] = "R 3 C 1"
aList[3][2] = "R 3 C 2"
? "Print the List using Ring"
? aList
? "Print the List by calling C Code"
displayList(aList)
? ""

? "Create List (2,2)"
aList = newList(2,2)
? "Update the list using C code - set all cells to 10"
UpdateTable(aList,10)
? "aList[1][1] : " + aList[1][1]
? "aList[1][2] : " + aList[1][2]
? "aList[2][1] : " + aList[2][1]
? "aList[2][2] : " + aList[2][2]

