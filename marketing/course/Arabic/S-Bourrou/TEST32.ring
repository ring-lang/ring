# بسم الله الرحمن الرحيم
// this is Lesson5 -  thanks to Mr.MAHMOUD Fayed
/*
  Application:  Control Structures 
  Author     :  S.BOURROU
  Date       :  16.12.2017  
*/

aList = [:A,:B,:C]
for  item in aList 
     ? item
     switch item
     on :A item=1 # or case:A 
     on :B item=2
     on :C item=3
     other item=0 # or else 
off next # or end
? aList

# other style :
aList = [:A,:B,:C]
for  item in aList {
     ? item
     switch item {
     on :A item=1 # or case :A 
     on :B item=2
     on :C item=3
     other item=0 # or else 
    
        } 
 }
? aList
