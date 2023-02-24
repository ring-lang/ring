cClassName = "myclass2"
myobj = new from cClassName

cClassName = "myclass"
myobj = new from cClassName

cClassName = ""
try
	myobj = new from cClassName
catch
	? cCatchError
done

cClassName = "Test"
try
	myobj = new from cClassName
catch
	? cCatchError
done

cClassName = 123
try
	myobj = new from cClassName
catch
	? cCatchError
done

try
	myobj = new from cClassName2
catch
	? cCatchError
done


class myclass
	? :hello
class myclass2
	? :wow