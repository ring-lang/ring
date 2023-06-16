load "jsonlib.ring"

st2 = `{
  "numbers": [
    100,
    200,
    300
  ],
  "mix": [
    "one",
    1,
    "two",
    2,
    "three",
    3
  ]
}`

a = json2list(st2)

? list2json(a)

? nl+copy("=",20)
? "Numbers: "
? copy("=",20)
? a[:numbers]

? nl+copy("=",20)
? "Mix: "
? copy("=",20)
? a[:mix]
