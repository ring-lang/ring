new child

class parent
	func test1
		? :test1

	private
		func good
			? :good

class child from parent
	test1()
	good()
	wow()
	? name	# We expect NULL
	private
		name = :child
		? name
		func wow
			? :Wow