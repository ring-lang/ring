func main
        aList = [1,2,3,4,5]     # create list, local in function main
        myfunc(aList)           # call function, pass list by reference
        see aList               # print 1 2 3 4 5 6 7 8 9 10

func myfunc list
        list + [6,7,8,9,10]
