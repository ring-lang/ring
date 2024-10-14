/*
          Application        :Ring Lessons
          Author             :Islam Deraz
          Date               :2018.03.13
*/

# eval() 	----> execute ring code stored in a string

func main

while true
	? "Enter Expression: " give cExpr

	if lower(trim(cExpr)) = "exit"
		exit
	ok
	? eval("return " + cExpr)
end
