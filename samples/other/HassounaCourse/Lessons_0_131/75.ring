
func main
	calc(5,7,"+")
	calc(5,5,"*")
	calc(10,7,"-")
	calc(10,2,"/")
	calc(7,3,"%")
	calc(10,0, "/")
end


func calc (num1, num2, ope)
	r = 0
	if  ope="+"	r=num1+num2  ok
	if  ope="-"	r=num1-num2   ok
	if  ope="*"	r=num1*num2  ok
	if ope="/"
		if num2=0
			num2=1
		ok
		r=num1/num2
	ok
	if ope="%"
		if num2=0
			num2=1
		ok
		r=num1%num2
	ok
	see r + nl
end

