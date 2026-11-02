# The substr() replace with strings that contain char(0)

func main

	cStr = "a" + char(0) + "b"

	? "Test 1: cOld is found"
	showSize(substr(cStr, "b", "c"), 3)

	? "Test 2: cOld is not found"
	showSize(substr(cStr, "x", "y"), 3)

	? "Test 3: cOld is not found (not case sensitive)"
	showSize(substr(cStr, "X", "y", True), 3)

	? "Test 4: Binary data, replace a byte that is not used"
	cData = char(1) + char(0) + char(2) + char(0) + char(3) + char(4)
	showSize(substr(cData, char(255), ""), 6)

	? "Done"

func showSize cResult, nExpected

	? "Size: " + len(cResult) + " (expected " + nExpected + ")"
