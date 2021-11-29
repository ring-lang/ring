# RingSQLite

load "sqlitelib.ring"



OSQLITE=SQLITE_init()
SQLITE_open(OSQLITE,"MYTEST.DB")

SQL="
CREATE TABLE company ( 
	 ID INT	PRIMARY 	KEY 	NOT NULL,  	
	 NAME		TEXT 	NOT NULL,  
	 AGE		INT 	NOT NLL); 
"

SQLITe_execute(OSQLITE,SQL)

 

SQLITe_execute(OSQLITE,"INSERT INTO  company (ID,NAME,AGE)  
	 VALUE (0,'AHMED',19),   
  	 VALUE (1,'AHMD',19);
")


aRESULT=SQLITE_execute(OSQLITE,"SELECT *  FROM COMAPNY ")

FOR X IN aRESULT 
	FOR t IN X 
		? t[2]+nl
? x
	next

NEXT 
see copy("*",50 )+nl
for x in aRESULT
	? x["name"]+nl
next

sqlite_close(OSQLITE)
