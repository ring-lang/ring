/*
**     App:variables(list)
**     Author:Asmaa Samir
**     Date: 21-12-2017
*/
#==========================================================
#how to write variables names:
#Number -->write 'n' in the 1st
#string -->write 'c' in the 1st (character)
#list --> write 'a' in teh 1st (array of multiple type)
alist=[]
while True
   see " Select Option:

         (1)Add Numbers
         (2)Sum Numbers 
         (3)Exit
       "
     give cOption
     switch cOption
           on "1"
               ? "Enter Number of Numbers:"
               give cNum
               cNum=0+cNum
               while cNum>len(alist)
                    ? "Enter Number:"
                    give cNumber
                    alist=alist+cNumber
                    
               end
               
           on "2"
               nsum=0
               
               for nNum in alist
                   nsum=nsum+nNum
               next
               ? "sum =" + nsum 
          on "3"
                # bye
                shutdown()
          other ? "Bad Option"
     off 


end           
   # give nOption
   # nOption=0+nOption

