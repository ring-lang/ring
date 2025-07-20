load "jsonlib.ring"
str = `{"fruits": [], "mix": "error empty array"}`

a = json2list(str)
j = list2json(a)

? j

a2= json2list(j)
? len(a2)
? len(a2[1])
? a2[1]
? len(a2[2])
? a2[2]
