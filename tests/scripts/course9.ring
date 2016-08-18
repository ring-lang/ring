# Author : Abdelraouf mohamed
# sum list items without using a  for loop

Mylist=[]
While true
	see"Enter Number " Give Number
	Mylist+(0+Number)
	see"contine (Y/N)" Give option 
	if option ="n"
		exit 
	ok 
end
see mylist
sum=0
index=1
while index<=len(mylist)
	sum=sum+mylist[index]
	index=index+1
end
see"sum="+sum
