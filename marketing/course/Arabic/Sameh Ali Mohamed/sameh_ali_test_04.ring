#application>>  :using stdlib (version 5)
#author      >>  :sameh ali 
#date       >>  :2/02/2018


load "stdlib.ring"  

print("hello,world!\nWelcome to my first application!\nWhat is your name?\n")

name = getstring()

print("hello #{name}")
