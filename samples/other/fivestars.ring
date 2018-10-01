load "stdlib.ring"
a = copy("*",5)
for b=5 to 1 step -1
	sleep(1)
	switch b
	on 4
		? "*"
	on 2
		? " *"
	other
		? a
	off
next
