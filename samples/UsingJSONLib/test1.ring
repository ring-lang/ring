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

	aList = Json2List(cJSON)
	? aList[:FirstName]
	? aList[:LastName]
	? aList[:Age]
	? aList[:Address]
	? aList[:Address][:StreetAddress]
	? aList[:Address][:city]
	? aList[:Address][:state]
	? aList[:Address][:postalcode]
	? aList[:phoneNumbers]
	? aList[:phoneNumbers][1][:Type]
	? aList[:phoneNumbers][1][:Number]
	? aList[:phoneNumbers][2][:Type]
	? aList[:phoneNumbers][2][:Number]