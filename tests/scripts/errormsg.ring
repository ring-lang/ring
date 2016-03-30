x = 1

try
	test()
catch
	see "great catch!" +nl
done

try
	raise("bad")
catch
	see "good catch" + nl
done

try
	1 /0
catch
	see "nice catch" + nl
done

# raise("nice error")


#raise("bad")
assert(x=1)
assert(x=1)
assert(x=2)

func test
	see "welcome to my function!" + nl
	1/0
