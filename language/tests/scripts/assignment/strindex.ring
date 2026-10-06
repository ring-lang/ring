# Assign list/object to string character (not allowed)

? :start
cStr = "abc"
try
cStr[1] = [1,2,3]
catch
? cCatchError
done
try
cStr[1] = new point
catch
? cCatchError
done
aList = [1,2,3]
try
cStr[1] = aList
catch
? cCatchError
done
pPoint = new Point
try
cStr[1] = pPoint
catch
? cCatchError
done
? :done
class point x y z