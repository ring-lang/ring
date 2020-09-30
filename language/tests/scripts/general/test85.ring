
$ObjectsList = [[1,new window] , [2,new window]]
C_OBJECTSLIST_OBJECT = 2

last_window().top = 10
last_window().left = 10
last_window().width = 400
last_window().height = 400
see last_window()

func Last_Window
		nSize = len($ObjectsList)
		if nSize > 0 {
			return $ObjectsList[len($ObjectsList)][C_OBJECTSLIST_OBJECT]
		}

class window
	top left width height