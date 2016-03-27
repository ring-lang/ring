see "wow" + test() + test2()

bye

for x = 1 to 10
	see x
	see nl
	for y = 1 to 10
		see y
		if y = 3  exit 2 ok
	next
next


bye

x = 1
while x < 100000
	x = x + 1
end


see test() + test2()
see nl
see sum(20,30)
see nl
see fact(5)
good()

func test 
	return "test"

func test2
	return "test2"

func sum x,y
	return x+y

func fact x if x = 1 return 1 else return x * fact(x-1) ok

func good for x = 1 to 10 see x see nl next 