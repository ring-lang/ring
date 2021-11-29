
see "hello" + nl
?"world"

tab=char(9)+char(9)
? "one" + tab + "two"

for x=1 to 10
	see x +nl
next

xx="hello" + tab+ "world"
write("xx.txt",xx)
system("notepad xx.txt")
x=25

if x=5
	? "right"
but x=25
	? "you are right"
else	
	?"not number"


ok

if x=5
	? "right"
elseif x=25
	? "you are right"
else	
	?"not number"


end





for x=1 to 10 step 2
	? x
next

for x=10 to 1 step -2
	? x
next


for x=1 to 10
	if x=3
		? "three"
		loop
	ok
	? x
	if x=7
		exit
	ok
next




next
 
y=1
while y<10
	? y
	y=y+1
	if y=7
	? "seven"
exit
	ok

end

try 
 1/0
catch 
	? "error not divide zero"

done 
