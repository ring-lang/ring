load "jsonlib.ring"

func main

	aList = [
		:name = "Ring",
		:year = 2016
	]

	? List2JSON(aList)

	aList2 = [
				["firstName", "John"],
				["lastName", "Smith"], 
				["age", 20],
				["address",
					[
						["streetAddress", "21 2nd Street"],
						["city", "New York"],
						["state", "NY"],
						["postalCode", "10021"]
					]
				],
				["phoneNumbers", 
					[
						[
							["type", "home"],
							["number", "212 555-1234"]
						],
						[
							["type", "fax"],
							["number", "646 555-4567"]
						]
					]
				]
	]

	? List2JSON(aList2)
