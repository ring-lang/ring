nOutput = true
try
	aList = dir("C:\what")
catch
	nOutput = false
done
see "Output : " + nOutput