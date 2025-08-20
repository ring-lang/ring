# Reference count overflow (List Item)

aList = []

nMax   = 8388608
aList2 = list(nMax)

fp = fopen(filename(),"r")

# fp is a list of 3 items that wraps a C pointer
# The first item is a C pointer
# Ring uses Reference Counting for the first item

for m=1 to nMax
	aList2 + fp
next
