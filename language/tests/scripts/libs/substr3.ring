cStr = "test"

? 'Using ? substr(cStr,"", "nice")'

try
	? substr(cStr,"", "nice")
catch
	? cCatchError
done
