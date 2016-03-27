cPath = "C:\Users\Mahmoud\Desktop\js\bootstrap"
aFiles = Dir(cPath)
aFiles2 = []
for x in aFiles
	if  right(x[1],5) = ".html"
		aFiles2 + x[1]
	ok
next

#see aFiles2

aRes = []

for x in aFiles2
	see "I am here 0 " + nl
	v1 = cPath+"\"+x
	see "I am here -1 " + nl
	see "Read File : " 
	see v1
	write("testread.txt",v1)
	v2 = read(v1)
	see "I am here -2 " + nl
	cStr = lower(v2)
	see "I am here 1 " + nl
	nPos = substr(cStr,"data-")
	see "I am here 2 " + nl
	while nPos > 0
		cStr = substr(cStr,nPos)
		nPos2 = substr(cStr,"=")
		cNew =  left(cStr,nPos2-1)
		if find(aRes,cNew) = 0
			aRes + cNew
		ok
		cStr = substr(cStr,nPos2)
		nPos = substr(cStr,"data-")
	end
	see "I am here 3 " + nl
next

see aRes