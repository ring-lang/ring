? copy("=",10)
x=10
do 
	x--
	do 
		if x=9 loop 2 ok 
		x--
	again x > 2
	? "x = " + x
	? :here
again x > 1
? copy("=",10)

x=10
do 
	x--
	? :one
	do
		? :two
		do 
			? :three
			do 
				? :four
				do 
					? :five
					exit 5
				again x > 5
			again x > 4
		again x > 3
	again  x > 2
again x > 1
? copy("=",10)

x=10
do 
	x--
	? :one
	do 
		? :two
		do 
			? :three
			do 
				? :four
				do 
					? :five
					if x = 0 exit 5 ok
					? copy("*",20) + " x = " + x
					loop 5
				again x > 5
			again x > 4
		again x > 3
	again x > 2
again x > 1
? copy("=",10)


? :done 