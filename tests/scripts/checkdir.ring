see isdir("b:\mahmoud\apps\ring") + nl
see isdir("b:\mahmoud\apps\ring2") + nl
func isdir cDir
	try
		dir(cDir)
		return true
	catch
		return false
	done