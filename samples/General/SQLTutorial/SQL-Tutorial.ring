// https://www.tutlane.com/tutorial/sqlite/sqlite-transactions-begin-commit-rollback
// Bert Mariani 2020-10-25 update

load "sqlitelib.ring"

MyDB     = "myDataBase.db"
oSQLite  =  null
aDBLines = []

//==================================================================
// Remove existing file so we can start from scratch (delete record 4 Dog)
    Remove(MyDb)

//--------------------------------------------------
// START SQLITE
    oSQLite = sqlite_init() 

//------------------------------------------------------------------
// OPEN FILE for DB ( Will CREATE it if it does NOT EXIST)
    sqlite_open(oSQLite, MyDB)
    

//------------------------------------------------------------------
// To use transaction commands first we need to CREATE TABLE called Emp_Master 
// and INSERT INTO some data VALUES using following queries.
// CREATE A DB TABLE ( Can be combined with INSERT VALUES)

    sql = " CREATE TABLE Emp_Master
            ( emp_id INTEGER PRIMARY KEY AUTOINCREMENT,
              first_name TEXT,
              last_name  TEXT,
              salary     NUMERIC,
              dept_id    INTEGER  );
          " 


    // EXECUTE SQLITE       
    sqlite_execute(oSQLite,sql)
 
//------------------------------------------------------------------ 
// INSERT INTO some data VALUES using following queries.
// Note ID created in mixed order

    sql = " INSERT INTO Emp_Master
            VALUES   
                     (3,'Charlie',  'Czeck',    7766,   3),
                     (4,'Dog',      'Denmark',  5544,   2),
                     (9,'Igloo',    'Italy',    6543,   2),
                     (5,'Easy',     'England',  3322,   3),
                     (7,'George',   'Germany',  1100,   2),
                     (6,'Fox',      'France',   2211,   1),
                     (1,'Able',     'Austria',  9988,   1),
                     (2,'Baker',    'Belgium',  8877,   2),                  
                     (8,'Harry',    'Hungary',  7654,   3);
            "

    // --------------------------
    // EXECUTE SQLITE
       
    sqlite_execute(oSQLite,sql)

//==================================================================

//------------------------------------------------------------------
// DISPLAY ALL Lines in DB

    aDBLines =  sqlite_execute(oSQLite,"SELECT * FROM  Emp_Master")
    DisplayDBLines( aDBLines, "Display Create DB Table with Values --  Was mixed order ")
    
//-------------------------------------------------------------------   
// Now write the query like as shown following to Start a Transaction 
// and Delete records from emp_master Table where dept_id = 3 
// and we will use ROLLBACK command to undo all the changes.    
    
    sql = " BEGIN;
            DELETE FROM Emp_Master WHERE dept_id=3;
            ROLLBACK;
          "
    aDBLines = sqlite_execute(oSQLite,sql)
    aDBLines = sqlite_execute(oSQLite,"SELECT * FROM  Emp_Master")
    DisplayDBLines( aDBLines, "Delete Record 3, then RollBack")
 
//-------------------------------------------------------------------- 
// Now, let's start another Transaction 
// and DELETE records from the Emp_Master Table where emp_id = 1 
// and we use COMMIT command to commit all the changes like as shown below.

    sql = " BEGIN;
            DELETE FROM emp_master WHERE emp_id=4;
            COMMIT;
          "

    sqlite_execute(oSQLite,sql)
    aDBLines = sqlite_execute(oSQLite,"SELECT * FROM  Emp_Master")
    DisplayDBLines( aDBLines, "Delete Record 4, then Commit -- (4,'Dog','Denmark',5544,2)")
    
//--------------------------------------------------------------------    
// Sort is ORDER BY with Column Position  DESC/ASC

    aDBLines = sqlite_execute(oSQLite, "SELECT * FROM  Emp_Master ORDER BY salary ASC")
    DisplayDBLines( aDBLines, "SORT = Order by salary ASC")
    
//--------------------------------------------------------------------     
// Select WHERE  name = George  

    aDBLines = sqlite_execute(oSQLite, "SELECT * FROM  Emp_Master WHERE first_name = 'George' ")
    DisplayDBLines( aDBLines, "SEARCH = Where name = 'George' Show entire line")
    
//--------------------------------------------------------------------     
// Select WHERE  name = Harry  

    aDBLines = sqlite_execute(oSQLite, "SELECT first_name, last_name FROM  Emp_Master WHERE first_name = 'Harry' ")
    DisplayDBLines( aDBLines, "SEARCH = Where name = 'Harry'  Show only first last name")
    

//--------------------------------------------------------------------  
// Select WHERE  name = dept_id = 2  

    aDBLines = sqlite_execute(oSQLite, "SELECT first_name, last_name FROM  Emp_Master WHERE dept_id = 2 ")
    DisplayDBLines( aDBLines, "SEARCH = Where dept_id = 2")    
    
//--------------------------------------------------------------------  
// INSERT INTO Emp_Master  VALUES  (4, 'Jack','Japan', 4567, 3), 

               sqlite_execute(oSQLite, "INSERT INTO Emp_Master  
                                        VALUES  (4, 'Jack','Japan', 4567, 3), 
                                                (10,'King','Kenya', 8765, 2); 
                                        COMMIT; ")
                                        
    aDBLines = sqlite_execute(oSQLite,"SELECT * FROM  Emp_Master")
    DisplayDBLines( aDBLines, "INSERT Line 4 Jack, 10 King")  
    
//==================================================================
// UPDATE Emp_Master SET first_name='Umberto' WHERE emp_id = 9

    sql = "UPDATE Emp_Master SET first_name='Umberto', last_name='Mariani' WHERE emp_id=9; "
    sqlite_execute(oSQLite, sql)

    aDBLines = sqlite_execute(oSQLite,"SELECT * FROM  Emp_Master")
    DisplayDBLines( aDBLines, "UPDATE first_name = 'Umberto' WHERE empd_id = 9") 


//==================================================================
// ALTER TABLE -- ADD COLUMN color TEXT
// SET Column in Each Row to color value

    sqlite_execute(oSQLite, "ALTER TABLE Emp_Master
                             ADD COLUMN color TEXT;
                             COMMIT; ")
                             
    sql = "UPDATE Emp_Master SET color='White'  WHERE emp_id=1;
           UPDATE Emp_Master SET color='Black'  WHERE emp_id=2; 
			  UPDATE Emp_Master SET color='Red'    WHERE emp_id=3;
			  UPDATE Emp_Master SET color='Yellow' WHERE emp_id=4;
			  UPDATE Emp_Master SET color='Orange' WHERE emp_id=5;
			  UPDATE Emp_Master SET color='Green'  WHERE emp_id=6;
			  UPDATE Emp_Master SET color='Blue'   WHERE emp_id=7;
			  UPDATE Emp_Master SET color='Purple' WHERE emp_id=8;
			  UPDATE Emp_Master SET color='Violet' WHERE emp_id=9;
			  UPDATE Emp_Master SET color='Brown'  WHERE emp_id=10; "
    sqlite_execute(oSQLite, sql)
                          
    aDBLines = sqlite_execute(oSQLite,"SELECT * FROM  Emp_Master")
    DisplayDBLines( aDBLines, "Inserted Column = color")
	 
//==================================================================
// DISPLAY DB HEADERS -- Column names and types

   DisplayDBHeaders()
   
   
//==================================================================
// CLOSE SQLITE

    sqlite_close(oSQLite)
    

//==================================================================
//==================================================================


//--------------------------------------------------------------------  
// DISPLAY DB Lines
// aDBLines = Array Result of SQL Command

Func DisplayDBLines( aDBLines, Msg )

    See nl + copy("*",50) +nl
    See Msg +nl
    See nl + "emp_id" +Tab+ "first" +Tab+   "last"  +Tab+ "salary" +Tab+ "dept_id" +nl
    

    
    for Line in aDBLines
        for Field in Line
                See  Field[2] + Tab 
        next
        See nl  ### after each line
    next
    

return

//--------------------------------------------------------------------  
// Display DB Headers, Column names and types

Func DisplayDBHeaders()

    See nl + copy("*",50) +nl
    See "DISPLAY DB Headers, Column names and types: "+nl
    
    //----------------------------
    //aDBheaders = sqlite_execute(oSQLite, "SELECT *         FROM sqlite_master WHERE type='table' AND name = 'Emp_Master' ")
    //aDBheaders = sqlite_execute(oSQLite, "SELECT name, sql FROM sqlite_master WHERE type='table' AND name = 'Emp_Master' ")
      aDBheaders = sqlite_execute(oSQLite, "SELECT sql       FROM sqlite_master WHERE type='table' AND name = 'Emp_Master' ")
  
     See nl
     for Line in aDBheaders
        for Field in Line
                See  Field[2] + Tab 
        next
        See nl  ### after each line
     next
     See nl
    

return

//-------------------------------
/*
 aDBheaders:
 
type
table
name
  Emp_Master
tbl_name
  Emp_Master
rootpage
  2
sql
  CREATE TABLE Emp_Master
            ( emp_id INTEGER PRIMARY KEY AUTOINCREMENT,
              first_name TEXT,
              last_name  TEXT,
              salary     NUMERIC,
              dept_id    INTEGER  )
*/
//--------------------------------------------------------------------  
