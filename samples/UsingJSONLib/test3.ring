load "jsonlib.ring"

func main

	cJSON = read("sample.json")
	aList = JSON2List(cJSON)
	? List2JSON(aList)