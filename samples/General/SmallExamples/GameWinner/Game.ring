#---------------------------------------------#
# Application 	: Anton and Danik Game Winner #
# Author	: Tawfik Yasser Tawfik        #
# Date		: 13-09-2020                  #
#---------------------------------------------# 
? "Welcome to game, Type A if Anton won the game
and type D if Danik won the game"

ca =0 cd = 0
see "Type the results: "
give str 
for x = 1  to len(str) step 1  
	if str[x] = 'A' ca++
	but str[x] = 'D' cd++ 
ok
next

if ca>cd {
? "Anton is the winner"
else if cd>ca
? "Danik is the winner"
else
? "Friendship"}
ok
