load "objects.ring"

func open_object cObject
	open_window(cObject)
	return last_object()

func last_object
	return last_window()

class ObjectControllerParent from WindowsControllerBase
