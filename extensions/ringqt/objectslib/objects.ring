/*
**	Project : RingQt - Objects Library
**	File Purpose :  Objects Functions
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

/*
	The next function create new object, add the object to the $RingQt_ObjectsList
	Then set $RingQt_ObjName to the object in the $RingQt_ObjectsList
	Then call the start() method
*/

func Open_Window cClass
	$RingQt_ObjectID++
	$RingQt_ObjectsList + [$RingQt_ObjectID,""]	
	$RingQt_ObjName = "$RingQt_ObjectsList[Get_Window_Pos("+$RingQt_ObjectID+")]" +
			 "[C_RINGQT_OBJECTSLIST_OBJECT]"
	cCode = $RingQt_ObjName + " = new " + cClass + nl + 
		  $RingQt_ObjName + ".start()"
	eval(cCode)	

/*
	The next function return the last window created
*/

func Last_Window
	return $RingQt_ObjectsList[len($RingQt_ObjectsList)][C_RINGQT_OBJECTSLIST_OBJECT]

/*
	The next function for using in GUI controls events
*/

func Method cMethod
	cMethod = Trim(cMethod)
	if right(cMethod,1) != ")" {
		cMethod += "()"
	}
	return $RingQt_objname+"."+cMethod

/*
	The next function get the Window ID
	Then search in the Objects List to find the Window Item Position
*/

func Get_Window_Pos nID
	return find($RingQt_ObjectsList,nID,C_RINGQT_OBJECTSLIST_ID)

/*
	The next class is the parent class for Windows/Forms Classes
	When you create a new class, just use from WindowsBase
	When you close the window just use Super.Close()
*/

class WindowsControllerBase

	RingQt_nID = $RingQt_ObjectID

	func Close
		nPos = Get_Window_Pos(RingQt_nID)
		del($RingQt_ObjectsList,nPos)

	func ObjectID
		return RingQt_nID

	func GetObjectByID nID
		return $RingQt_ObjectsList[nID][C_RINGQT_OBJECTSLIST_OBJECT]
