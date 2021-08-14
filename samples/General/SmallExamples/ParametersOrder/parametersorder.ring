func main
	showDetails("Ali",38,true)  // ==> "Hello Ali,Your Age Is 38, You Are Available For Hire" 
	showDetails(38,"Ali",true)  // ==> "Hello Ali,Your Age Is 38, You Are Available For Hire"
	showDetails(true,38,"Ali")  // ==> "Hello Ali,Your Age Is 38, You Are Available For Hire"
	showDetails(false,"Ali",38) // ==> "Hello Ali,Your Age Is 38, You Are not Available For Hire"

func showDetails p1,p2,p3
	cName=NULL nAge=NULL lStatus=NULL
	cName = iff( isString(p1), p1, cName )	
	cName = iff( isString(p2), p2, cName )	
	cName = iff( isString(p3), p3, cName )	
	lStatus = iff( isBool(p1), p1, lStatus )	
	lStatus = iff( isBool(p2), p2, lStatus )		
	lStatus = iff( isBool(p3), p3, lStatus )		
	nAge = iff( isAge(p1), p1, nAge )	
	nAge = iff( isAge(p2), p2, nAge )	
	nAge = iff( isAge(p3), p3, nAge )	
	see "Hello " + cName + ",Your Age Is " + nAge + ", You Are " 
	if not lStatus see "not" ok
	? " Available For Hire"

func isAge nValue
	return isNumber(nValue) and nValue > 1 

func isBool nValue
	return isNumber(nValue) and (nValue=0 or nValue=1)

func iff lTest,vTrue,vFalse
	if lTest return vTrue ok return vFalse