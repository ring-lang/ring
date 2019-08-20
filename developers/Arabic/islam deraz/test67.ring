/*
          Application        :Ring Lessons
          Author             :Islam Deraz
          Date               :2018.03.13
*/

# eval() 	----> execute ring code stored in a string

? " welcom to the Ring language"
while true
	see " Code:> " give cCode
	eval(cCode)
	? ""
end
