? "One"
? [] = NULL
? [] != NULL

? "Two"
? [] = 1
? [] != 1

? "Three"
if test([] = NULL)
	? "What!"
ok

? "Four"
if test([] != NULL)
	? "What!"
ok

? "Five"
if test([] = 1)
	? "What!"
ok

? "Six"
if test([] != 1)
	? "What!"
ok

? "Done"

func test p1
	? p1