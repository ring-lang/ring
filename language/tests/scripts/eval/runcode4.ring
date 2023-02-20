do
	try
		? :Before
		eval("1/0")
		? :after
	catch
		? :wow
	done
again false	# Change this to True & Check Memory Usage