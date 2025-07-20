load "jsonlib.ring"
str = `["one","two","three"]`

a = json2list(str)
? a
myjson = list2json(a)
? myjson

? json2list(myjson)
