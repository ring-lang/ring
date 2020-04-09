# ------------- Control Structures Part 1 -------------
# -----------  Condition/Loop Statements  -----------
# condition ----> True|False
# ---------------- if statement (Condition) -------------------
# Wax 1
x = 10
if x = 5 
	? "Five"
but x = 7
	? "Seven"
but x = 6
	? "Six"
else 
	? "Another Number"
ok
# Wax 2
x = 5
if x = 5 
	? "Five"
elseif x = 7
	? "Seven"
elseif x = 6
	? "Six"
else 
	? "Another Number"
end
# Wax 3
x = 7
if x = 5 {
	? "Five"
elseif x = 7
	? "Seven"
elseif x = 6
	? "Six"
else 
	? "Another Number"
}
? "========="
# ---------------- For statement (Loop) -------------------
# Style 1
for x = 1 to 10
	? x
next  //Use next or end 
? "........."
for x = 1 to 10 step 2
	? x
next
? ""
for x = 10 to 1 step -1
	? x
next
? "........."
# Style 2
for x = 1 to 10 {
	? x
} 
? "........."
for x = 1 to 10 step 2 {
	? x
}
? ""
for x = 10 to 1 step -1 {
	? x
}
? "........."
aList = [:one, :two, :three]
for item in aList
	? item
	switch item //switch statement (condition) //Style 1
	on :one      item = 1
	on :two      item = 2
	on :three    item = 3
	other        item = 0
	off
next
? aList
? "........."
# Style 3
aList = [:one, :two, :three]
for item in aList
	? item
	switch item //switch statement (condition) //Style 2
	case :one      item = 1
	case :two      item = 2
	case :three    item = 3
	else           item = 0
	end
end
? aList
? "........."
# Style 3
aList = [:one, :two, :three]
for item in aList {
	? item
	switch item { //switch statement (condition) //Style 2
	case :one      item = 1
	case :two      item = 2
	case :three    item = 3
	else           item = 0
	}
}
? aList
