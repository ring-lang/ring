# Author: Ilir Liburn
# Updated by Fayed (Converted to a Performance test)

str = copy("hello world ",100000)

t = clock()

i = 1
j = len(str)

while i < j
        c = str[i]
        str[i] = str[j]
        str[j] = c
        i++
        j--
end

# Time is around 400ms on my Computer
if (clock()-t)/ClocksPerSecond() < 1
	? "Fast"
else
	? "Slow"
ok

t = clock()

j = len(str)
e = j/2 			// use ceil(j/2) to stop at middle character

for l in str
        s = l
        l = str[j]
        str[j] = s
        if e >= j-- exit ok
next

# Time is around 400ms on my Computer
if (clock()-t)/ClocksPerSecond() < 1
	? "Fast"
else
	? "Slow"
ok
