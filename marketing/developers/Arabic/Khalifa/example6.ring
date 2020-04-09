/*
    Application: using stdlib
    Author     : Ahmed Khalifa
    Date       : 2017.12.10
*/
  
load "stdlib.ring"
print("Hello, World!\nWelcome to my first app!\nwhat is your name?\n")

name = getstring()
print("Hello #{name}\n") 

print("what is your age?\n")
age = getnumber()
print("Age : #{age}")
