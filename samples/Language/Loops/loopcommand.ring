#========================================================================#
# Loop Command example
# Using (Loop) inside (For, For-In, While & Do-Again) loops
# The command always jump to the section that starts the loop
#========================================================================#

? :start
for t=1 to 10 
	loop
	? :test
next
? :end

? :start
aList = 1:10
for item in aList
	loop
	? :test
next
? :end

? :start
x=1
while x<10
	x++
	loop
	? :test
end
? :end

? :start
x=0
do
	x++
	if x > 10 exit ok

	? "Value: " + x
	loop
	? :test
again x<1
? :end

#========================================================================#
/*
	Output:
		start
		end
		start
		end
		start
		end
		start
		Value: 1
		Value: 2
		Value: 3
		Value: 4
		Value: 5
		Value: 6
		Value: 7
		Value: 8
		Value: 9
		Value: 10
		end
*/
#========================================================================#