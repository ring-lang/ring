load "jsonlib.ring"
str = `{"fruits": [], "mix": "error empty array"}`

a = json2list(str)
? list2json(a)