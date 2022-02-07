load "cjson.ring"

json = cJSON_Parse( read("sample.json") )

? "***********************"
aList = cJSON_ToRingList(json)
? "***********************"
? aList["firstName"]
? aList["lastName"]
? aList["age"]
? "***********************"
? len(aList["address"])
? aList["address"]
? "***********************"
? aList["address"]["postalcode"]
? aList["address"]["streetaddress"]
? aList["address"]["state"]
? aList["address"]["city"]
? "***********************"
? len(aList["phonenumbers"])
? "***********************"
? len(aList["phonenumbers"][1])
? aList["phonenumbers"][1]
? "***********************"
? len(aList["phonenumbers"][2])
? aList["phonenumbers"][2]
? "***********************"
? len(aList["phonenumbers"][3])
? aList["phonenumbers"][3]
? "*********************"
? aList["phonenumbers"][3]["type"]
? aList["phonenumbers"][3]["number"]
