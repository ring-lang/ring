/*
          Application        :Conversion between lists & strings
          Author             :Islam Deraz
          Date               :2018.02.14
          Application Number :7
*/ 
#variable Types (string, number, list, object, c object)

alist =[ :one, :two, :three, :four, :five ]

? alist
? len(alist)

cstring= list2str(alist)
? len(cstring)
? cstring


alist1= str2list(cstring)
? len(alist1)
