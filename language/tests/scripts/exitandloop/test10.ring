? copy("=",10)
x=10
while x > 1
	x--
	while x > 2
		loop 2
	end
	? "x = " + x
	? :here
end
? copy("=",10)

x=10
while x > 1
	x--
	? :one
	while x > 2
		? :two
		while x > 3
			? :three
			while x > 4
				? :four
				while x > 5
					? :five
					exit 5
				end
			end
		end
	end
end
? copy("=",10)


x=10
while x > 1
	x--
	? :one
	while x > 2
		? :two
		while x > 3
			? :three
			while x > 4
				? :four
				if x=5 ? "five (5)" exit 4 ok
				while x > 5
					? :five
					? copy("*",20)
					loop 5
				end
			end
		end
	end
end
? copy("=",10)


? :done 