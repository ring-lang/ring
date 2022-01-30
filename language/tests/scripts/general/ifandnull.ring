? "First"
str = ""
? str = 0
? 0 = str
? str = 1
? 1 = str
if str
	? "NOT NULL"
ok
if !str
	? "NULL"
ok
? "Second"
lst = []
if lst
	? "NOT NULL"
ok
if !lst
	? "NULL"
ok

if not lst
	? "NULL"
ok