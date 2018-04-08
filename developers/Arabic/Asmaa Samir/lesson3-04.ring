/*
**     App:variables(list)
**     Author:Asmaa Samir
**     Date: 21-12-2017
*/
#==========================================================
#Ring Lang is not case sensitive
mylist = [
          "one",
          "two",
          "three",
           4,5,6,"seven",
           [8,9,10],
           [11,[12,13,14]], # this element contains list of 2 elements
           ["Egypt" , "KSA," ,"USA"] 
        ]
? mylist[9]
? mylist[9][1]
? mylist[9][2][3]
? mylist[10][1][5]
?len(mylist[9])
?len(mylist)
