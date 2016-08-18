#Programmer : Abdelrahman Omar

mylist=[random(10),random(50),random(7)]
while true
	see "guess number" give number
	number = 0+number
	if find (mylist,number)
		see "you win"+nl
	else 
		see "try again"+nl
	ok

	see "continue (y/n) ?" give cont
	if cont = "n"
		exit
	ok
end
see mylist
