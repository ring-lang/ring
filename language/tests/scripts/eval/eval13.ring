for t=1 to 10
	try
		eval("1/0")
	catch
		? cCatchError
	done
next

for t=1 to 10
	try
		eval('1 / "0"')
	catch
		? :what
	done
next