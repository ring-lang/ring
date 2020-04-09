/*
**     App:variables(list)
**     Author:Asmaa Samir
**     Date: 21-12-2017
*/
#==========================================================
#add element to empty list
mylist = []

#1st method add()
add(mylist,"one")
? mylist

#2nd method +
mylist + "two"
? mylist

/* we use + operator in :
1- concatenation between multiple strings str1 + str2.
2- summation between multiple numbers num1 + num2
3- convert string to number 0+str2 , if use num other than 0 
     the str2 will be converted to number type and the o/p will be concatenated
4- convert number to string   ""+num2
5- add item to list (add string,number,list)
