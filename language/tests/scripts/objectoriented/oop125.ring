? :before
try
	aList = [1]
	aList[1].nice()
catch
	? cCatchError
done
? :after

? :before
try
	aList = [2]
	aList[1].nice
catch
	? cCatchError
done
? :after

? :before
try
	aList = ["test"]
	aList[1].nice()
catch
	? cCatchError
done
? :after

? :before
try
	aList = ["test2"]
	aList[1].nice
catch
	? cCatchError
done
? :after

? :before
try
	aList = [[]]
	aList[1].nice()
catch
	? cCatchError
done
? :after

? :before
try
	aList = [[]]
	aList[1].nice
catch
	? cCatchError
done
? :after



