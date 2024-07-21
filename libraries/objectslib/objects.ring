/*
**	Project : Objects Library
**	File Purpose :  Functions to manage a group of objects 
**	Date : 2016.11.22
**	Author :  Mahmoud Fayed <msfclipper@yahoo.com>
*/


# List of objects (Windows/Forms)
	$RingQt_ObjectsList = []	# Contains sub lists [object ID , Object]

# The Object ID Counter
	$RingQt_ObjectID = 0

# Variable used for Windows/Forms object name - used for setting events 
	$RingQt_ObjName = ""

# The next constants for the Objects List
	C_RINGQT_OBJECTSLIST_ID 	= 1
	C_RINGQT_OBJECTSLIST_OBJECT 	= 2

# Ring Version 

	C_RINGVERSION = Number(Version())

# Better API without _ in function names

	func OpenWindow cClass
		return Open_Window( cClass )
	
	func OpenWindowInPackages cClass,aPackages
		return Open_WindowInPackages( cClass,aPackages )
	
	func OpenWindowNoShow cClass
		return Open_WindowNoShow( cClass )
	
	func OpenWindowAndLink cClass,oParent 
		return Open_WindowAndLink( cClass,oParent )

	func OpenWindowNoShowAndLink cClass,oParent 
		return Open_WindowNoShowAndLink( cClass,oParent )
	
	func LastWindow 
		return Last_Window() 
	
	func LastWindowID 
		return Last_WindowID() 
	
	func GetWindowPos nID
		return Get_Window_Pos( nID )

	func GetWindowByID nID 
		return Get_Window_ByID(nID)
	
/*
	The next function create new object, add the object to the $RingQt_ObjectsList
	Then set $RingQt_ObjName to the object in the $RingQt_ObjectsList
	Then call the start() method
*/

func Open_Window cClass
	cRingQt_ObjName = $RingQt_ObjName	# Save the current Object
	$RingQt_ObjectID++
	$RingQt_ObjectsList + [$RingQt_ObjectID,""]	
	$RingQt_ObjName = "$RingQt_ObjectsList[Get_Window_Pos("+$RingQt_ObjectID+")]" +
			 "[C_RINGQT_OBJECTSLIST_OBJECT]"


	cCode = ""
	if packagename() != NULL {
		cCode += "import " + packagename()  + nl
		cCode += "import System.GUI" + nl
	}
	cCode += $RingQt_ObjName + " = new " + cClass + nl + 
		"if isMethod(" + $RingQt_ObjName + ",:start)" + nl +
		  $RingQt_ObjName + ".start()" + nl + "ok"
	eval(cCode)	
	
	if cRingQt_ObjName != NULL {
		$RingQt_ObjName = cRingQt_ObjName	# Restore the current Object
	}

/*
	The next function is the same as Open_Window()
	But takes an extra list that determine the packages 
	To import before opening the window.
*/

func Open_WindowInPackages cClass,aPackages
	cRingQt_ObjName = $RingQt_ObjName	# Save the current Object
	$RingQt_ObjectID++
	$RingQt_ObjectsList + [$RingQt_ObjectID,""]	
	$RingQt_ObjName = "$RingQt_ObjectsList[Get_Window_Pos("+$RingQt_ObjectID+")]" +
			 "[C_RINGQT_OBJECTSLIST_OBJECT]"

	cCode = ""
	if packagename() != NULL {
		cCode += "import " + packagename()  + nl
		cCode += "import System.GUI" + nl
	}
	for cPackage in aPackages {
		cCode += "import " + cPackage  + nl
	}
	cCode += $RingQt_ObjName + " = new " + cClass + nl + 
		  $RingQt_ObjName + ".start()"
	eval(cCode)	
	
	if cRingQt_ObjName != NULL {
		$RingQt_ObjName = cRingQt_ObjName	# Restore the current Object
	}


/*
	The next function create new object, add the object to the $RingQt_ObjectsList
	Then set $RingQt_ObjName to the object in the $RingQt_ObjectsList
*/

func Open_WindowNoShow cClass
	cRingQt_ObjName = $RingQt_ObjName	# Save the current Object
	$RingQt_ObjectID++
	$RingQt_ObjectsList + [$RingQt_ObjectID,""]	
	$RingQt_ObjName = "$RingQt_ObjectsList[Get_Window_Pos("+$RingQt_ObjectID+")]" +
			 "[C_RINGQT_OBJECTSLIST_OBJECT]"

	cCode = ""
	if packagename() != NULL {
		cCode += "import " + packagename()  + nl
		cCode += "import System.GUI" + nl
	}
	cCode += $RingQt_ObjName + " = new " + cClass 
	eval(cCode)	
	
	$RingQt_ObjName = cRingQt_ObjName	# Restore the current Object


/*
	The next functions create new object, add the object to the $RingQt_ObjectsList
	Then set $RingQt_ObjName to the object in the $RingQt_ObjectsList
	Then call the start() method
	The function link between the parent window and the child window
	And define methods automatically to use the windows from each other
*/

func Open_WindowAndLink cClass,oParent
	Open_Window(cClass)
	LinkOpenedWindow(cClass,oParent)

func Open_WindowNoShowAndLink cClass,oParent
	Open_WindowNoShow(cClass)
	LinkOpenedWindow(cClass,oParent)

func LinkOpenedWindow cClass,oParent
	cClass = lower(cClass)
	cParentClass = classname(oParent)
	if  ( right(cClass,10) != "controller" ) or 
		( right(cParentClass,10) != "controller" )
		raise("Error in Open_WindowAndLink() the classes names must end with 'controller'")
	ok

	cClassNameWithoutController = substr(cClass,"controller","")
	cParentClassNameWithoutController = substr(cParentClass,"controller","")
	cCode = ""
	if packagename() != NULL {
		cCode += "import " + packagename()  + nl
		cCode += "import System.GUI" + nl
	}
	cCode += `
		# Let the parent know about the child
		if not isattribute(oParent,"n#{f1}ID")
			AddAttribute(oParent,"n#{f1}ID")
		ok
		oParent.n#{f1}ID = last_windowID()
		if not ismethod(oParent,"Is#{f1}")
			AddMethod(oParent,"Is#{f1}", func {
				return n#{f1}ID
			})
		ok
		if not ismethod(oParent,"#{f1}") 
			AddMethod(oParent,"#{f1}", func {
				return GetObjectByID(n#{f1}ID)
			})
		ok
		# Let the child know about the parent
		if not isattribute(last_window(),"n#{f2}ID")
			AddAttribute(last_window(),"n#{f2}ID")
		ok
		last_window().n#{f2}ID = oParent.ObjectID()
		if not ismethod(last_window(),"Is#{f2}")
			AddMethod(last_window(),"Is#{f2}", func {
				return n#{f2}ID
			})
		ok
		if not ismethod(last_window(),"#{f2}") 
			AddMethod(last_window(),"#{f2}", func {
				return GetObjectByID(n#{f2}ID)
			})
		ok
	`
	cCode = SubStr(cCode,"#{f1}",cClassNameWithoutController)
	cCode = SubStr(cCode,"#{f2}",cParentClassNameWithoutController)
	eval(cCode)
	


/*
	The next function return the last window created
*/

func Last_Window
	return $RingQt_ObjectsList[len($RingQt_ObjectsList)][C_RINGQT_OBJECTSLIST_OBJECT]

/*
	The next function return the ID of the last window created
*/

func Last_WindowID
	return $RingQt_ObjectsList[len($RingQt_ObjectsList)][C_RINGQT_OBJECTSLIST_ID]

/*
	The next function for using in GUI controls events
*/

func Method cMethod
	cMethod = Trim(cMethod)
	if right(cMethod,1) != ")" {
		cMethod += "()"
	}
	if $RingQt_objname != NULL {
		return $RingQt_objname+"."+cMethod
	}

/*
	The next function get the Window ID
	Then search in the Objects List to find the Window Item Position
*/

func Get_Window_Pos nID
	return find($RingQt_ObjectsList,nID,C_RINGQT_OBJECTSLIST_ID)

/*
	Return the window object using the Window ID
*/

func Get_Window_ByID nID
	nPos = Get_Window_Pos(nID)
	return $RingQt_ObjectsList[nPos][C_RINGQT_OBJECTSLIST_OBJECT]

/*
	The next class is the parent class for Windows/Forms Classes
	Don't Use this class directly!
	When you create a new class, just use from WindowsControllerParent
	When you close the window just use Super.Close()
*/

class ObjectsParent

	RingQt_nID = $RingQt_ObjectID

	RingQt_nParentID=0		# Parent Object ID 

	func Method cMethod 
		cMethod = Trim(cMethod)
		if right(cMethod,1) != ")" {
			cMethod += "()"
		}
		cRingQt_ObjName = "$RingQt_ObjectsList[Get_Window_Pos("+RingQt_nID+")]" +
			 "[C_RINGQT_OBJECTSLIST_OBJECT]"
		return cRingQt_objname+"."+cMethod

	func Me
		return GetObjectByID(RingQt_nID)

	func setParentObject oParent
		RingQt_nParentID = oParent.ObjectID()

	func Parent
		return GetObjectByID(RingQt_nParentID)

	func IsParent
		return RingQt_nParentID

	func GetObjectByID nID
		return Get_Window_ByID(nID)

	func ObjectID
		return RingQt_nID

	func Close
		nPos = Get_Window_Pos(RingQt_nID)
		del($RingQt_ObjectsList,nPos)
