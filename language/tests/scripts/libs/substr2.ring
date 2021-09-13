cStr = "test"

? "Using ? substr(cStr,100, 1)"
try
	? substr(cStr,100, 1)
catch
	? cCatchError
done

? "Using substr(cStr, -1, 4)"
try
	substr(cStr, -1, 4)
catch
	? cCatchError
done

? "Using substr(cStr, 1, 1000)"
try
	substr(cStr, 1, 1000)
catch
	? cCatchError
done


? "Using substr(cStr, 1, -1)"
try
	substr(cStr, 1, -1)
catch
	? cCatchError
done

? :done