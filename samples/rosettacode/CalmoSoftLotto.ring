/*
 +---------------------------------------------------------------------------------------------------------
 +     Program Name : Lotto program
 +     Date         : 2017.08.13.
 +     Author       : Gal Zsolt (~ CalmoSoft ~) 
 +     Email        : calmosoft@gmail.com
 +---------------------------------------------------------------------------------------------------------
*/
max = 49
num = 6
lotto = list(max)
choices = list(num)
for i = 1 to max
    lotto[i] = i
next 
for choice = 1 to num
    r = random(max) + 1
    choices[choice] = lotto[r]
    lotto[r] = lotto[max]
    max = max - 1
next
choices = sort(choices)
see choices + nl
