do
	try
		? :Before
		eval(" ? :start eval('1/0')   ? :end")
		? :after
	catch
		? :wow
	done
again false	# Change this to True & Check Memory Usage