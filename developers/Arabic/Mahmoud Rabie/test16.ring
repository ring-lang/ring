/*

   	Application    :(Lists) - version4
   	author         :Mahmoud Rabie 
	Date           :2017/12/11  
*/

#===============================================================
aList =[]
while  True 
               see " 
		        (1) Add Number 
		        (2) Sum Numbers 
		        (3) Exit 
                 " give   coption
                   Switch coption 
	            on "1"   see "Enter Number : "   give cNumber  aList +cNumber
                               on "2"   nSum =0   for  nNum in aList  nSum = nSum + nNum next
	                         ? "Sum : "  + nSum  
                               on "3" bye 
	            other ? "Bad Option!" 
             off
end
 

 

