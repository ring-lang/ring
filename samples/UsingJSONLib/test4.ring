load "jsonlib.ring"

cJSON =`
{
	"name": "Ring",
	"year": 2016,
	"license": "MIT",
	"other": null,
	"more": true
}
`

func main

	aList = JSON2List(cJSON)
	? "Name    : " + aList[:name]
	? "Year    : " + aList[:year]
	? "License : " + aList[:License]
	? "Other   : " + aList[:other]
	? "More    : " + aList[:more]