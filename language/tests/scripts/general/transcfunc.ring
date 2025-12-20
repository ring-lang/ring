ringvm_translatecfunction("len","length")
ringvm_translatecfunction("length","mylength")

cStr = "welcome"

? len(cStr)
? length(cStr)
? mylength(cStr)

Try
	ringvm_translatecfunction("anyname","newname")
Catch
	? "Pass Error"
	? cCatchError
Done