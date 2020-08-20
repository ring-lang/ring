myhash = [
	:name = "Mahmoud"
]

if myhash[:name] != NULL
	? "Name : " + myhash[:name]
ok

if myhash[:address] != NULL
	? "Address : " + myhash[:address]
else 
	? "Sorry, We don't know the address!"
ok
