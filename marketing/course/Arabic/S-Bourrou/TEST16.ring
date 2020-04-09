# بسم الله الرحمن الرحيم
// this is Lesson3 -  thanks to Mr.MAHMOUD Fayed
 /*###########################################################*/
 /*       Application: Simple Ring App (Variables :lists V3 ) */
 /*       Author     :  S.BOURROU                             */
 /*       Date       :  11.12.2017                            */
 /*###########################################################*/

 aList = [] // list to store numbers

 while true 
     
      see "
         (1) add Number  
         (2) sum Numbers 
         (3) exit 

          " 
      give  cOption 
      switch cOption 
         on "1" see " Enter number " give cNumber  aList+cNumber
         on "2" nSum=0 for nNum in aList nSum = nSum+nNum next
          ? "Sum =" + nSum 
         on "3" shutdown() # or bye

      other ? " Bad Option !"			
      off

 end
