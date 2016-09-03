See "Hello
	Wait 3 seconds...
"
# Wait 1 second
t = clock()
while clock() - t <= clockspersecond()*3 end
See "Bye"