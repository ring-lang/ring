? :start
try
	? :beforetestfunc
	x = test()
	? :aftertestfunc
	? x
catch
done
? :end

func test
	? :beforeloop
	for t=1 to 10 step "mm"
		? t
	next
	? :afterloop