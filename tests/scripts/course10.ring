# By : Ahmad Samir
/*
in this example there are some names are stored in the system
the user will enter any name if the entered name is from our list (namelist)
"Found" message will shown
if the user enter another names which not stored in the list
"Not Found" message will shown
after that message "continue ? (y/n) 
if the user need to search about another name he should press any key except "n"
if "n" is pressed the application will exit .
 */

namelist = ["ahmad","ali","mahmoud","ramy","samir"]
while true
	see "Enter the name " +NL 
             give name
             if find(namelist,name) 
		see "Found"+NL
	else 
		see"Not Found"+NL
	ok
	see "continue ? (y/n)" give decision
	
	if decision="n" 
		exit
	ok
end
