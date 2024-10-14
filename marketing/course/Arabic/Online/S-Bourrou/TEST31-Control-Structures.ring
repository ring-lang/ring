# بسم الله الرحمن الرحيم
// this is Lesson5 -  thanks to Mr.MAHMOUD Fayed
/*
  Application:  Control Structures 
  Author     :  S.BOURROU
  Date       :  16.12.2017  
*/
# In this  example i use : if,else,elseif,but 
load "stdlib.ring"
while true 
Question = "What is the capital of Palestine ?"
? upper(Question) ? " Please Enter correct word :"give Answer
    if Answer = :Jerusalem
    see "Of Course! Correct :) thanks" sleep(5) exit
    but Answer = :القدس 
    see "Right Arabic answer :)"  sleep(3) exit
    but Answer = "elquds"  
    ? "Ok Right !" sleep(3) exit
    elseif answer = :hint  
    ? " Jerusalem is the capital of Palestine , sir !" + nl sleep(5) 

 
    else ?"You Failed!"  ? "Write hint to see the answer"
Ok
  end

# For 
for a = 1 to 10 ? a next 
for a = 1 to 10 step 2 ? a next 
for a = 10 to 1 step -1 ? a next 

# replace next with end
for a = 1 to 10 ? a end 
for a = 1 to 10 step 2 ? a end 
for a = 10 to 1 step -1 ? a end 

#=========  other style
for a = 1 to 10 {
        ? a 
}  
for a = 1 to 10 step 2 {
        ? a 
}
for a = 10 to 1 step -1 {
        ? a
} 
