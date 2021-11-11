#==============================================================================#
# Sample: Decimals Count
# Author: Gal Zsolt & Mansour Ayouni 
#==============================================================================#

# Alert: Sometimes this method will not return the correct output
#	 This happens because of the environment 
#	 And is limited by the limits of computer representation of
#	 floating point numbers
#	 Example: n = 3.1234567 # *** should be: 7  but delivers: 8

func main
	# Testing the function
	decimals(2)		# Insensitive to the default setting of decimals
	n = 5.1945
	? NbrOfDecimals(n)	# Gives 4

func NbrOfDecimals(n)
	nTemp = 1
	nNbrOfDecimals = 0      
	while True
		if nNbrOfDecimals < 9
			nNbrOfDecimals++
			nTemp *= 10
			nTemp1 = n * nTemp - ceil( n * nTemp )
			if nTemp1 = 0
				return nNbrOfDecimals
			ok
		else
			raise("Acceding the maximum number of 9 decimals!")
		ok
	end
