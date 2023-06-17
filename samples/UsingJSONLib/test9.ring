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
      "one",
      "two",
      "three",
      1000,
      2000,
      3000,
      "four",
      "five"
    ]
  ]
}`

a = json2list(str)
? list2json(a)