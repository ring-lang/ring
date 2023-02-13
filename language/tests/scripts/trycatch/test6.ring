# Nested Try/Catch - Three Levels

try
	1/0
catch
	? :test1

	try
		1/0
	catch
		? :test2
		try
			1/0
		catch
			? :test3
			? :aftertest3
		done
		? :aftertest2
	done

	? :aftertest1

done