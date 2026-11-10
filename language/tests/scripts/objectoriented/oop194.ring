/*
	Negative numbers and missing data in records written as Ring literals

	Inside braces, literals can be written next to each other:
		"User1"  1500  [2025,2026]  True
	Each literal is a separate statement, and braceExprEval() receives it.

	But - and + are also binary operators, so:
		1500 -200	is ONE expression (1500 - 200 = 1300)
	The value -200 is lost silently.

	This sample shows the trap, then the ways to write it correctly:
		(1) Parentheses		1500 (-200)
		(2) Comma		1500, -200
		(3) Zero minus		1500 0-200
	Then it shows how to mark missing data using NULL,
	and how to check the row length to catch forgotten values.
*/

? "=== The trap: 1500 -200 is subtraction ==="
new ShowValues { "User1"  1500 -200 }		# User1 | 1300
new ShowValues { "User1"  1500 +200 }		# User1 | 1700
new ShowValues { "User1" +"Admin" }		# User1Admin

? nl + "=== (1) Parentheses ==="
new ShowValues { "User1"  1500 (-200) }		# User1 | 1500 | -200

? nl + "=== (2) Comma ends the statement ==="
new ShowValues { "User1"  1500, -200 }		# User1 | 1500 | -200
new ShowValues { "User1"  1500, +200 }		# User1 | 1500 | 200
new ShowValues { "User1", +"Admin" }		# User1 | Admin

? nl + "=== (3) Zero minus (works, but reads like math) ==="
new ShowValues { "User1"  1500 0-200 }		# User1 | 1500 | -200

? nl + "=== Comma after identifiers like True/NULL ==="
# Without the comma, True [2025,2026] means indexing True
new ShowValues { "User1"  True, [2025,2026] }	# User1 | 1 | [2025,2026]

? nl + "=== Records: negative values, NULL, and a row-length check ==="
new Records {
	"User Name"	"Salary"	"Bonus"		"Years"
	"User1"		1500		(-200)		[2025,2026]
	"User2"		2400,		-150		[2024,2025]
	"User3",	NULL,		300		[2023,2024]
	"User4"		3300		[2022,2023]			# Missing value
	"User5"		1800		0-50		[2021,2022]
}

#=================================================
# Converts any value to a printable string
#=================================================

func valueToString vValue

	if isList(vValue)
		cOut = "["
		for x = 1 to len(vValue)
			if x > 1 cOut += "," ok
			cOut += valueToString(vValue[x])
		next
		return cOut + "]"
	but isString(vValue)
		if vValue = NULL return "NULL" ok
		return vValue
	ok
	return "" + vValue

#=================================================
# Shows the values of one brace as a single line
#=================================================

class ShowValues

	aValues = []

	func braceExprEval vValue
		aValues + vValue

	func braceEnd
		cLine = ""
		for vValue in aValues
			if cLine != "" cLine += " | " ok
			cLine += valueToString(vValue)
		next
		? cLine

#=======================================================================
# Collects each line as a row, checks its length, then prints a table
#=======================================================================

class Records

	aRows = []
	aRow  = []

	func braceExprEval vValue

		aRow + vValue

	func braceNewLine

		if len(aRow) = 0 return ok
		if len(aRows) > 0 and len(aRow) != len(aRows[1])
			? "Warning: row " + len(aRows) + " has " + len(aRow) +
			  " values, expected " + len(aRows[1]) +
			  " (use NULL for missing data)"
		ok
		aRows + aRow
		aRow = []

	func braceEnd

		? ""
		for aRow in aRows
			cLine = ""
			for vValue in aRow
				cLine += left(valueToString(vValue) + copy(" ",14), 14)
			next
			? cLine
		next
