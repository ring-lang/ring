/*
          Application        :Test31
          Author             :Islam Deraz
          Date               :2018.02.28
          Application Number :2
*/

# control structures

for x=1 to 10
	for y=1 to 10
		? "x= " + x + " y= " +y
		if x=3 and y=5
		       exit 2
		ok
	next
next

? "done"

# condition (and or not)
# condition (&& || !   )

x=10
y=20

if x=10 and y=10
	? "first"
ok

if x=10 or y=10
	? "second"
ok

