cStr = "test"

? "Using ? substr(cStr,100)"
try
	? substr(cStr, 100)
catch
	? cCatchError
done

? "Using ? substr(cStr,-1)"
try
	? substr(cStr, -1)
catch
	? cCatchError
done

? :done