# The Ring Standard Library
# Type Hints Library
# 2017, Mahmoud Fayed <msfclipper@yahoo.com>


# Define Types Hints

# Low Level Types
char 		= :char 
unsigned 	= :unsigned
signed 		= :signed 
int 		= :int 
short 		= :short 
long 		= :long 
float 		= :float 
double 		= :double 
void 		= :void 

# High Level Types 
string 		= :string 
list 		= :list 
number 		= :number 
object		= :object

# Other 
public		= :public 
static		= :static 
abstract	= :abstract 
protected	= :protected
override	= :override 

# Add User Types (Define Application Classes As Types)
# We use the eval() function two times 
# because we must execute the (import) commands before calling the Classes() function

# Import Packages
	cCode = ""
	TypeHints_Packages = Packages()
	for TypeHints_Package in TypeHints_Packages {
		ccode += "import " + TypeHints_Package + nl
	}
	eval(cCode)

# Defines classes as types 	
	cCode = ""
	TypeHints_Classes = Classes()
	for TypeHints_Class in TypeHints_Classes {
		if not substr(TypeHints_Class,".") {
			cCode += TypeHints_Class + " = :" + TypeHints_Class + nl
		}
	}
	eval(ccode)
	
