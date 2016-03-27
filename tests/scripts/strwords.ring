cStr = "
---------- Ice and Fire ------------

fire, in end will world the say Some
ice. in say Some
desire of tasted I've what From
fire. favor who those with hold I

... elided paragraph last ...

Frost Robert -----------------------
"
aList = str2list(cStr)
for x in aList
   x2 = substr(x," ",nl)
   alist2 = str2list(x2)
   aList2 = reverse(aList2)
   for y in aList2 see y + " " next
   see nl
next