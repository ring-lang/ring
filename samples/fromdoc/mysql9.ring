func main

        con = mysql_init()

        see "Connect" + nl
        if mysql_connect(con, "localhost", "root", "root","mahdb") = 0
                system_error(con) ok

        see "Drop table" + nl
        if mysql_query(con, "DROP TABLE IF EXISTS Employee2")
                system_error(con) ok

        see "Create table" + nl
        if mysql_query(con, "CREATE TABLE Employee2(Id INT, Name TEXT, Salary INT)")
                system_error(con) ok

        see "Insert data" + nl
        if mysql_query(con, "INSERT INTO Employee2 VALUES(1,'Mahmoud',15000)")
                system_error(con) ok

        if mysql_query(con, "INSERT INTO Employee2 VALUES(2,'Samir',16000)")
                system_error(con) ok

        if mysql_query(con, "INSERT INTO Employee2 VALUES(3,'Fayed',17000)")
                system_error(con) ok

        mysql_autocommit(con,False)
        mysql_query(con, "INSERT INTO Employee2 VALUES(4,'Ahmed',5000)")
        mysql_query(con, "INSERT INTO Employee2 VALUES(5,'Ibrahim',50000)")
        mysql_query(con, "INSERT INTO Employee2 VALUES(6,'Mohammed',50000)")
        See "Save transaction (y/n) " give nChoice
        if upper(nChoice) = "Y"
                mysql_commit(con)
        else
                mysql_rollback(con)
        ok

        see "Close connection" + nl
        mysql_close(con)

func system_error con

        see mysql_error(con)
        mysql_close(con)
        bye
