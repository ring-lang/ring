/*
**	Application Name : SQLite;
**	Author           : Ahmed Elskaan;
**	Date             : 2017-12-22;		
*/
load "sqlitelib.ring"

#=======================================
oSqlite = sqlite_init()
sqlite_open(oSqlite, "test.db")
sqlite_execute(oSqlite, "CREATE TABLE company(
	id int PRIMARY KEY NOT NULL,
	name text NOT NULL,
	age int NOT NULL,
 	address CHAR(50),
	salary real);
")
sqlite_execute(oSqlite, " INSERT INTO company (id, name, age, address, salary)
		values(1, 'Mahmoud', 29, 'Jeddah', 20000.00),
		      (2, 'Ahmed', 27, 'Jeddah', 15000.00),
		      (3, 'Mohammed', 31, 'Egypt', 20000.00),
		      (4, 'Ibrahim', 24, 'Egypt ', 65000.00);

")
aResult =  sqlite_execute(oSqlite,"select * from company")
for x in aResult
	for t in x
		? t[2]
	next
next
? copy("*",50)
for x in aResult
        ? x[:name]
next
sqlite_close(oSQLite)

#========
 
