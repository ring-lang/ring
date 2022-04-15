m = 1
while m < 3
for t=1 to 10
	? t
	if t=3 
		? :three
	endif
endfor
m++
endwhile

try
	? 1/0
catch
	? :good
endtry

number = 1
switch number
	case 1
		? :one
	case 2
		? :two
	case 3
		? :three
endswitch

aList = 10:15
for t in aList
	? t
endfor