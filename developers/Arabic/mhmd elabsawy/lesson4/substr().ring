# app     : substr()
# author  : mhmd elabsawy
#-----------------------------------------------------------------
c = 'welcome to the ring programing language Ring.'
?substr(c,2,2)
? 'position of ring is: '+ substr(c,'ring')
? 'replace ring by c++'+ substr(c,'ring','c++')
? 'replace ring by c++ not case sensitive'+ substr(c,'ring','c++',true)
