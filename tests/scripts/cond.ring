see "welcome" + nl
if test(0,1) = 1
	see "nice"+nl
else
	see "bad"+nl
ok

if test(1,1) = 1
	see "nice"+nl
else
	see "bad"+nl
ok

if (test(1,1)) = 1
	see "nice"+nl
else
	see "bad"+nl
ok


func test x,y
	return x+y