/*
          Application        :Ring Lessons
          Author             :Islam Deraz
          Date               :2018.03.13
*/

# eval() 	----> execute ring code stored in a string

? " welcome to the Ring language"
while true
	see "Code:> " give cCode
	try 
		eval(cCode)
	catch
		? "ERROR! "
	end
	? ""
end
