## app    : variables_lists4
## author : mhmd elabsawy
#-----------------------------------------------------------------
loadsyntax s.ring 
l = []               # see = out , give = input.
 while true
        
          out "
                    1-add number 
                    2-sum numbers
                    3-exit
             " input coption
               switch coption
                on '1' out 'enter number: ' input cx   l+cx
                on '2' nsum = 0 for nnum in l nsum=nsum+nnum next
                       ? 'sum is: '+nsum
                on '3' bye
other ? 'are you joking!'
off
end
                   















