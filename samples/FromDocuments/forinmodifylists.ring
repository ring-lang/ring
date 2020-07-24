aList = 1:5     # create list contains numbers from 1 to 5
# replace list numbers with strings
for x in aList
        switch x
        on 1  x = "one"
        on 2  x = "two"
        on 3  x = "three"
        on 4  x = "four"
        on 5  x = "five"
        off
next
see aList       # print the list items
