? "Welcome"
try
	rec()
catch
	? "Avoid runtime error: " + cCatchError
done

? "Count from 1 to 10"

for t=1 to 10 ? t next

? "Bye"

func rec
	return "" + rec()	