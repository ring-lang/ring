# We Can Use Semicolon In Ring Language
See "Welcome" + nl ;
See "Enter Number1 : " Give Number1
See "Enter Number2 : " Give Number2
See "Sum1 = " + number1 + number2 + nl
/* 
 Result :
   Welcome
   Enter Number1 : 5
   Enter Number2 : 3
   Sum = 53
*/

/*
 Note: That + Here Is A Concatenation Operator Not Plus Operator.
 If You Want To Make Summation, Split Statement 
*/
See "Sum2 = " See number1 + number2 + nl
/* 
 Result :
   Welcome
   Enter Number1 : 5
   Enter Number2 : 3
   Sum = 53
   Sum = 53		
*/

/* Note: That It Still Not The Desired Result Because,
   Give Receive Data From User Then Put It In A String Variable.
   To Solve This Problem, Convert String Variables To Numbers
*/
Number1 = number(number1)
Number2 = number(number2)
See "Sum3 = " See number1 + number2 + nl
/* 
 Result :
   Welcome
   Enter Number1 : 5
   Enter Number2 : 3
   Sum1 = 53
   Sum2 = 53
   Sum3 = 8		
*/		
