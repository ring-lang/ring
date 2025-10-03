# Shared by Max in Ring Group

load "stdlib.ring"
load "jsonlib.ring"

st2 = `{
    "item": [
        [
            1,
            2,
            3
        ],
        1,
        2,
        3
    ]
}`


alist = JSON2List(st2)

ajsonStr = List2JSON(aList) 

? ajsonStr

? list2code(alist)

