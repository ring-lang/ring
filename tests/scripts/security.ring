While true
	See nl+"Code:> " give cCode
	Try
		eval(cCode)
	Catch
		See cCatchError
	Done
End

Func System cCmd
	See "Sorry, You Can't use the system() function!"+nl
