load "mysqllib.ring"

cText1 = "Hello World"
cText2 = "Hello 'World'"
display_strings()

con = mysql_init()
? "Connect to database..." 
mysql_connect(con, "localhost", "root", "root","mahdb")

? "Escape string..." 
cText1 = mysql_escape_string(con,cText1)
cText2 = mysql_escape_string(con,cText2)
display_strings()

? "Close database..." 
mysql_close(con)

func display_strings
	? "String: " + cText1
	? "Size  : " + len(cText1)
	? "String: " + cText2
	? "Size  : " + len(cText2)