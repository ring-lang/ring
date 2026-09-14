? "before"

LoadSyntax "badsyntaxfile.ring"

show "after" + nl

try
	myfunc(5)
catch
	? cCatchError
done

show "done" + nl
