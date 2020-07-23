# Load the library (It will be loaded in custom global scope by weblib/weblib.ring)
	load "/../../libraries/weblib/weblib.ring"

# Get a copy from the required global variables
	aPageVars 		= GetaPageVars()
	htmlcssattributes 	= Gethtmlcssattributes()
	aObjsAttributes 	= GetaObjsAttributes()
