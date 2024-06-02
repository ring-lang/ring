
aList = 1:10

try
	aList[1] += "20"
catch
done

try
	aList[1] += "mm"
catch
done

? aList[1]


x = 100

try
	x += "20"
catch
done

try
	x += "mm"
catch
done

? x