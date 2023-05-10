# Author: Ilir Liburn
# Updated by Fayed
# 	* Added (return self) in init method
# 	* Changed (func len) to (func mylen)
	
load "stdlibcore.ring"

import out

func main

	str = ["test"]
	? len(str[1])
	? 'for c = 1 to len(str[1]) step 1'
	for c in str[1] step 1
		? c
	next

	? "for s = 1 to len(substr(str[1], s))"
	for s = 1 to len(substr(str[1], s))
		? str[1][s]
	next

	? "for h = 1 to len(hybrid)"
	hybrid = new Hybrid(str)
	for h = 1 to len(hybrid[1])
		? hybrid[1][h]
	next

	? "for i = 1 to len(lst[1])"
		lst = [[0, 1, 2, 3]]
		for i = 1 to mylen(lst[1])
			? lst[1][i]
		next
	? "------------------"
	? lst[1][2]

func mylen x

	? "lening..."
	new Hybrid(x) { size = len(self) }
	return size

package Out

class Hybrid

	data

	func init val 

		data = val
		return self

        func operator cOperator,Para

		switch cOperator
			on "len"
				return len(data)
			on "[]"
				return &data[Para]
		off

