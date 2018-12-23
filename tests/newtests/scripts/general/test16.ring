path = "c:\ringlang\anyfolder"      #This is an invalid path

if DExists(path)

see 'correct path' + nl

else see " invalid path" + nl

ok


func DExists path
	try 
		dir(path)
	catch
		return 0
	done
	return 1
