aRecords = [] 

func main

while true

see "
===========
 Main Menu
===========
[1] Add new record
[2] Edit record
[3] Find record
[4] Delete record
[5] Show all records
[6] Records count
[7] Exit
===========
" give x
see nl

	if x = 1 sys_add()
	but x = 2 sys_edit()
	but x = 3 sys_find()
	but x = 4 sys_delete()
	but x = 5 sys_show()
	but x = 6 sys_count()
	but x = 7 bye
	else see "not correct option!" + nl
	ok

end

func sys_add
	see "Name    : " give cName
	see "Country : " give cCountry
	see "Age     : " give nAge
	add(aRecords,[cName,cCountry,nAge])

func sys_edit
	see " Name : " give cName
	for x = 1 to len(aRecords)
		if aRecords[x][1] = cName
			see "Name    : " give aRecords[x][1]
			see "Country : " give aRecords[x][2]
			see "age     : " give aRecords[x][3]
			return
		ok
	next
	see "Record not found!" + nl

func sys_find
	see "Name     : " give cName
	for x = 1 to len(aRecords)
		if aRecords[x][1] = cName
			see "Country : " + aRecords[x][2] + nl
			see "Age     : " + aRecords[x][3] + nl
			return
		ok
	next
	see "Record not found!" + nl

func sys_delete
	see "Name     : " give cName
	for x = 1 to len(aRecords)
		if aRecords[x][1] = cName
			del(aRecords,x)
			see "Record deleted!" + nl
			return
		ok
	next
	see "Record not found!" + nl


func sys_show
	for x = 1 to len(aRecords)
		see "Record number : " + x + nl
		see aRecords[x]
	next

func sys_count
	see "Records count : " + len(aRecords) + nl

