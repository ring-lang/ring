# This sample is written by Ilir Liburn 
# Related to this pull request : https://github.com/ring-lang/ring/pull/959

rec()

func rec
	return "" + rec()	# Using "" wil lead to StackOverFlow
				# Without "" - We will get (Out of Memory)