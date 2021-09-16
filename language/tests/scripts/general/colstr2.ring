line()
try
	? 'Test: "1" = [ "text 1", 100 ]'
	aList = [
		5,6,7,
		"1" = [ "text 1", 100 ]
	] 
catch
	? cCatchError
done
try
	? 'Test: "1" + [ "text 1", 100 ]'
	aList = [
		5,6,7,
		"1" + [ "text 1", 100 ]
	] 
catch
	? cCatchError
done
try
	? 'Test: "1" - [ "text 1", 100 ]'
	aList = [
		5,6,7,
		"1" - [ "text 1", 100 ]
	] 
catch
	? cCatchError
done
try
	? 'Test: "1" * [ "text 1", 100 ]'
	aList = [
		5,6,7,
		"1" * [ "text 1", 100 ]
	] 
catch
	? cCatchError
done
try
	? 'Test: "1" / [ "text 1", 100 ]'
	aList = [
		5,6,7,
		"1" / [ "text 1", 100 ]
	] 
catch
	? cCatchError
done

line()
? "Print the List"
line()
? aList
line()

func line
	? copy("=",60)