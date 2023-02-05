aList = [1,2,3,4,5]

? "Memory: " + ringvm_ismempool()
for t=1 to 500000
	ref(aList) = [5,6,7]
end
? "Memory: " + ringvm_ismempool()