# Author: xmey1994 in Ring Group
# Updated by Fayed

load "jsonlib.ring"

st2 = `{
  "fruits": [
    "apple",
    "banana",
    "orange",
    "kiwi"
  ]
}`

a = json2list(st2)

? list2json(a)

? nl+copy("=",20)
? "Fruits: "
? copy("=",20)
? a[:fruits]