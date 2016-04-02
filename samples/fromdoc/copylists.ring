aList = [
"one","two",
[3,4],
[20,30], ["three",
          "four",
          "five",[100,200,300]
         ]
]

aList2 = aList          # Copy aList to aList2
aList2[5] = "other"     # modify item number five
see aList2[5] + nl      # print other
see aList[5]            # print three four five 100 200 300
