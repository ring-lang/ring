cPath = "c:\"     

result = DExists(cPath)
see "i am here 3" + nl
see "result "  
see result

if result

	see 'correct cPath' + nl

else 
	see " invalid cPath" + nl

ok


func DExists cPath

	BadcPath = 1

	try

		dir(cPath)

	catch

		badcPath = 0

	done

	return badcpath