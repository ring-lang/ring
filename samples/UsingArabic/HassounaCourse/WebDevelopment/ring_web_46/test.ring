load "hassounapgdb.ring"

port     = "5433"
password = "123456"
database = "my_test"

//x = run("create database my_test")
//x = run("create table emp(id int primary key, name varchar(90) )")
//see x
/*
for x=1 to 10
	id = auto_num("emp","id")
	see run("insert into emp values(" + id + ",'Test Name " + id + "')")
	see nl
next 
*/
/*
tbl = get_data("select * from emp")
for x in tbl
	see x['name'] + nl
next
*/
