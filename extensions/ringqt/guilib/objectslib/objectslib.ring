load "objects.ring"

func open_object cObject
	open_window(cObject)
	return last_object()

func last_object
	return last_window()

func CreateObject cClass,oParent
	open_object(cClass)
	last_object().init(oParent)
	return last_object()

class ObjectControllerParent from WindowsControllerBase
