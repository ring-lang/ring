func main
	give n
	x = fib(n)
	see n + " Fibonacci is : " + x

func fib nr
	switch nr
	on 0
		return 0

	on 1
		return 1

	on morethanone(nr) = 1
		return (fib(nr-1) + fib(nr-2))

	off

func MoreThanOne n
	if n > 1 return 1 else return 0 ok