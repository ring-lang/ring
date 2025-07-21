# Author: Bert Mariani

load "jsonlib.ring"

# JSON data
jsonData = '[{"exdate": "2025-07-03","paydate": "2025-07-31","amount": "1.40","desc": "unconfirmed"},{"exdate": "2025-01-06","paydate": "2025-01-31","amount": "1.25","desc": ""},{"exdate": "2024-07-05","paydate": "2024-07-31","amount": "1.15","desc": ""}]'


aList = json2list(jsonData)
? "===== jsonData 2 aList ===== "
? aList

myjson = list2json(aList)
? "===== aList 2 myjason ===== "
? myjson

aList2 = json2list(myjson)
? "===== myjson 2 aList2 ===== "
? aList2

myjson2 = list2json(aList2)
? "===== aList2 2 myjason2 ===== "
? myjson2


