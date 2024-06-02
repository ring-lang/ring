? :start

value = NumOrZero("mm")
? value

value = NumOrZero("12")
? value

value = NumOrZero(10)
? value

value = NumOrZero("50")
? value

? :done

func NumOrZero cNum
	if isNumber(cNum) return cNum ok
	if isString(cNum) 
		try
			return 0+cNum
		catch
		done 
	ok
	return 0
