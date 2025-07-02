/*

	Return list item by reference from functions 
	Works if the list is a global list or belongs to the object state

	This feature was added to the Ring language for specific use case

	* To be used by the Operator() method to return list items by reference

	This sample is about a different use-case (The item belongs to a global list)

	This feature is revised & improved in Ring 1.23

	Syntax:
		Return & <expr>  # where expr result is a list item (global/ObjState)

	Note: This feature return item as reference but doesn't create a reference
              i.e. No reference counting in this operation (It's not required)

	We can assign a value to this item reference from the caller

	Passing this returned item reference from the caller to another function 
	will be pass the item by value

	Assigning this item reference to another variable/list item will create another value

	When we use:  
		return & test()		
	This will return item reference if test() does this in the first place

	If (return &) is used with <expr> which is not a list item
	Then & will do nothing (i.e. Ring will pass the error)

*/

? "Hello"			# Hello

aList = 1:10

test() = 10			# test() will return aList[1] by reference 

? aList[1]			# 10

try
	test2() = 10		# test2() return a value (not item reference)
catch
	? cCatchError		# print error message (Variable is required)
end

test3(test())			# while test() return item reference, test3() will get item value
				# i.e. the returned item reference is for direct usage 
				# Not for passing by reference 
				# test3() will print 1000

? aList[1]			# 10

try
	test4(test()) = 600
catch
	? cCatchError		# print error message (Variable is required)
done

? aList[1]			# 10

what = [ test() ]		# what = [10]

? what[1]			# 10
what[1] = 20			
? what[1]			# 20
? aList[1]			# 10

aList[1] = test()		
? aList[1]			# 10

test() = test() + 2		# aList[1] = aList[1] + 2	
? aList[1]			# 12

test() = test() * 2		# aList[1] = 12 * 2
? aList[1]			# 24

? test5()

try
	test5() = 1000
catch
	? cCatchError		# print error message (Variable is required)
done

? test5()			# 24 (aList[1] as item value)

? test6()			# 24 (aList[1] as item ref)

test6() = 120			# aList[1] = 120

? aList[1]			# 120

? test8()			# 100

try
	test8() = 1000
catch
	? cCatchError		# print error message (Variable is required)
done

? "Thanks!"

func test
	return & aList[1]	# return item in global list (return item ref)

func test2
	vlist  = 1:10
	return & vList[1]	# return item in local list (return value, i.e. not item ref)

func test3 v
	v = 1000		# set value for local variable 	
	? v			# print value (1000)

func test4 v
	return v		# return local variable (not item ref)

func test5
	return test()

func test6
	return & test()		# return item reference if test() does

func test7
	return 100

func test8
	return & test7()