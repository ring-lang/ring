load "objects.ring"

func open_object cObject
	open_window(cObject)
	return last_object()

func last_object
	return last_window()

func CreateObject cClass,oParent
	# Save the current object 
		cCurrentObject = $RingQt_objname
	open_object(cClass)
	last_object().init(oParent)
	# Restore the current object - used by Method() function
		$RingQt_objname = cCurrentObject
	return last_object()

class ObjectControllerParent from ObjectsParent
