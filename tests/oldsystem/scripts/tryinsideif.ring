/*
	Bug ID : 190
	Description : Using try { catch } inside if { } lead to syntax error !
	Status : Fixed
*/

x = 10
if x = 10 {
	try {
		x = 20
	catch
		x = 30
	}
}
put x + nl