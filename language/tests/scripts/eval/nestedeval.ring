? :start
try
	cCode = " eval(' 
		? :wow
		eval(cCode)
	') "

	eval(cCode)
catch
	? "We have limits!"
done
? :end