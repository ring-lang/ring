load "jsonlib.ring"

str = `{ 
    "stuff": {
        "onetype": [
            {"id":1,"name":"John Doe"},
            {"id":2,"name":"Don Joeh"}
        ],
        "othertype": {"id":2,"company":"ACME"}
    }, 
    "otherstuff": {
        "thing": [[1,42],[2,2],[3,3]]
     }
}`

a = json2list(str)
? list2json(a)
