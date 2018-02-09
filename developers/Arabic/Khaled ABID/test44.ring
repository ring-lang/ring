/*
	Application	: Course of Essentials (Functions)
	Author		: Khaled ABID
	Date		: 02/01/2018
*/

# Functions - Scope - Pass by value - Pass by refernce

? "Hello All"

x = 10	# global 
def main {
	x = 10
	? "Welcome to the main Function"
	one()
}
def one {
	? x
}
