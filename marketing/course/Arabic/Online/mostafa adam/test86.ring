/*
	name	:	Darsh Adam
	Lesson	:	Ring Lessons.ring
	Date 	:	24/12/2017
*/

#=====================================================
			# Ring Lessons 
#=====================================================

load "odbclib.ring"

# connect/disconnect
# Execute query (SQL)
# Transaction (Commit)
# save / restore binary data (images)

oodbc = odbc_init()
? odbc_drivers(oodbc)
