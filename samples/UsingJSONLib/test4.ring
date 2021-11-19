load "jsonlib.ring"

cJSON = `{
  "firstName": "John",
  "lastName": "Smith", 
  "age": 20,
  "address": {
    "streetAddress": "21 2nd Street",
    "city": "New York",
    "state": "NY",
    "postalCode": "10021"
  },
  "phoneNumbers": [
    { "type": "home", "number": "212 555-1234" },
    { "type": "fax", "number": "646 555-4567" }
  ]
}`

func main

	oTokens = new RingTokens {
		fromString(cJson)
		aList = GetTokens()
	}

	aList = JsonTokens2RingTokens(aList)

	oTokens.printTokensList(aList)
	? copy("*",40)

	cCode = RingTokens2Code(aList)

	? cCode
	eval("aTempList = " + cCode)

	? List2Code(aTempList)

