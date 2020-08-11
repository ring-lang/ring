#==============================================================================#
# Sample: Decimals Count
# Author: Gal Zsolt & Mansour Ayouni 
#==============================================================================#

# Testing the function
	decimals(2)		# Unsensitive to the default setting of decimals
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
			raise("Acceeding the maximum number of 9 decimals!")
		ok
	end
