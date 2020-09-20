#---------------------------------------------#
# Application 	: Tower of Hanoi              #
# Author	: Tawfik Yasser Tawfik        #
# Date		: 20-09-2020                  #
#---------------------------------------------# 

changeringkeyword see print

moves = 0 // This variable to calculate number of moves

print "Enter number of disks: " Give n
MoveTower(n,'A','C','B')

? "Total number of moves: " + moves

// Function to print the moves
func MoveSingleDisk start,finish
	moves++
	? start + " - > " + finish

// Function to move the disks
func MoveTower num,start,finish,temp
	if num = 1 {
		MoveSingleDisk(start,finish)
	else
	  	MoveTower(num - 1, start, temp, finish)
	        MoveSingleDisk(start, finish)
	        MoveTower(num - 1, temp, finish, start)
	}
	
