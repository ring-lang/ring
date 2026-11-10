/*
In Ring
(1) An expression can be used as a statement
(2) Some expressions could be simple (Number/String/List) literal
(3) In Ring no semicolon or new line is required between statements
(4) (Number/String/List) literals could be written next to each other
*/

? 10		# Number
? "Message"	# String
? [1,2,3]	# List

# Mixing without operators means starting new statements

? 10 20		# prints 10     
? "one" "two"	# prints one    
? [1,2][3,4]	# prints 1 2    
? 10 "ignore"	# prints 10     
? "only" 10	# prints only   
? 4 [1,2,3]	# prints 4      
? [1,2,3] "fun" # prints 1 2 3  
? [1,2,3] 10	# prints 1 2 3  
? 10[1]		# prints 10     
? "test"[1]	# prints test   
? [1,2,3][1]	# prints 1 2 3  

# So getting a letter from a string literal like "test"[1] is not supported
# Also getting an item from a list literal like [1,2,3][1] is not supported
# This is different from many other programming languages
# But enable us to mix these literal in one line inside braces
# So Ring can be used to process records written as Language literals 

cStr = "test"  ? cStr[1]    # t
? "test"[1]                 # test   ([1] is a separate, discarded statement)

new Record {
	"User Name"	"Salary"	"Years"		"Active"	
	"User1"		1500 		[2025,2026]	True
	"User2"		2400 		[2024,2025]	False
	"User3"		3300 		[2023,2024]	True
}

class Record

	aRows = []  aRow = []

	func braceExprEval vValue
		aRow + vValue

	func braceNewLine
		if len(aRow)  aRows + aRow  aRow = []  ok

	func braceEnd
		for aRow in aRows ? aRow[1] + " : " + aRow[2] next

