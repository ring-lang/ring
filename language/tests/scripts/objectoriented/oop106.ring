# Written by Max in Ring Group
# Updated by Fayed

str = "myclass"

try
	a = new from str
catch
	see "Catch!" + nl + cCatchError + nl
done

? "hallo welt"

try
	a = new myclass2
catch
	see "Catch!" + nl + cCatchError + nl
done

? "hallo welt"

class myclass from c1


endclass

class myclass2 from c2


endclass