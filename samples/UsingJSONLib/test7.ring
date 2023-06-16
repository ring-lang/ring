load "jsonlib.ring"
str = `{
  "fruits": [
    "apple",
    "banana",
    "orange",
    "kiwi"
  ],
  "numbers": [
    100,200,300
  ],
  "mix": [
    "mystring",
    10, [
      "good"
    ]
  ]
}`

a = json2list(str)
? list2json(a)