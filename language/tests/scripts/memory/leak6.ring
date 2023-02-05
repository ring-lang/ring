? "Memory: " + ringvm_ismempool()
for t=1 to 500000
	ref([1,2,3,4,5])
end
? "Memory: " + ringvm_ismempool()