/*
++  app   : variables_lists2
++  author: mhmd elabsawy
*/
#--------------------------------------------------------------
loadsyntax s.ring
l = [1,2,3,
     'a','b','c',
     ['mahmoud','mohamed','omar'],[54,45],[1,0]]
out l 
 out 'order: '+l[3]
out nl 
 out 'order: '+l[7][1][1] 
out nl
? 'count: '+len(l[7])
