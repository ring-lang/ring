======================================================
The WebLib Library for the Ring programming langauge 
CGI-Library (written in Ring)
http://ring-lang.net/
======================================================

To learn see the chapter 
	Web Development (CGI Library) 
	in Ring 1.0 documentation
	http://ring-lang.sourceforge.net/doc/web.html

Note: you will need to add .ring as cgi-script in your webserver
	https://httpd.apache.org/docs/2.2/howto/cgi.html

(1) Library files
	weblib.ring
	datalib.ring

(2) Examples as in documentation
	from ex1.ring to ex30.ring

(3) You will find the database in
	Database\mahdb.sql
	Open MySQL Workbench and import!

(4) Complete demo
	index.ring and other *.ring files

(5) The PDF Sample uses wkhtmltopdf.exe for converting from html to pdf
	You can download from http://wkhtmltopdf.org/
	
(6) You can test the scripts from the command line using test.bat
	where you can modify the request method (post/get) and set
	the query string.
	