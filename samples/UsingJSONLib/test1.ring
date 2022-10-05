load "jsonlib.ring"

func main

	cJSON = read("sample.json")

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