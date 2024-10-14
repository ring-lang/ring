# app name: lists_v4
# author  : mhmd elabsawy
#-----------------------------------------------------------------
alist = [
         :one,
         :two  ]
? 'size: '+ len(alist)
cstring = list2str(alist)
? 'size: '+ len(cstring)
blist = str2list(cstring)
?'size: '+ len(blist)
