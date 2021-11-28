/*  
 **      Application : Condition
 **      Author      : Abdelrahman Adam
 **      Date        : 21/12/2017 
*/ 
#======================================================

#test31
# while     for      if
#Condition
x = 10
if x = 5
		? "five"
but x = 7
		? "seven"
but x = 9
		? "nine"
else
		? "another Number !"
ok
#======================================================


if x = 5
		? "five"
elseif x = 7
		? "seven"
elseif x = 9
		? "nine"

else
		? "another Number !"
end

#======================================================
if x = 5	{
		? "five"
elseif x = 7
		? "seven"
elseif x= 9
		? "nine"

else
		? "another Number !"
}
#======================================================
#For style one
for x = 1 to 10
		? x
next

for x = 1 to 10 step 2
		? x
next

for x = 10 to 1 step -1
		? x
next
#======================================================
#For style Two
for x = 1 to 10
		? x
end

for x = 1 to 10 step 2
		? x
end

for x = 10 to 1 step -1
		? x
end
#======================================================
#For style three
for x = 1 to 10	{
		? x
}

for x = 1 to 10 step 2	{
		? x
}

for x = 10 to 1 step -1	{
		? x
}
