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

TypeHints_Packages = Packages()
for TypeHints_Package in TypeHints_Packages {
	ccode = "import " + TypeHints_Package
	see ccode + nl
	eval(ccode)
	see :after + nl
}

TypeHints_Classes = Classes()
for TypeHints_Class in TypeHints_Classes {
	if not substr(TypeHints_Class,".") {
		eval( TypeHints_Class + " = :" + TypeHints_Class )
	}
}
