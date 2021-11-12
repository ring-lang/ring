#------------------------------------------------------------------------------
# These are two functions made to extract the integer and decimal parts
# from a number: integerPart(n) and decimalPart(n,nRound)
#
# Note that you need to specify the round of the number you
# provide to decimalpar() function to protect the number against
# the active round defined by decimals() function.
#
# To get the active round, you use the getActiveRound() function.
#
# The logic used by these functions for extracting the integer and
# the decimal parts is not mathematical, but based on walking throw
# the number as a string and finding the "." separator.
#
# Written by: Mansour Ayouni (kalidianow@gmail.com) - Aug, 12th. 2020.
#----------------------------------------------------------------------------
? getActiveRound() # Gives 2 by default

n = 123456789.12345

? integerPart(n)	# Gives 123456789
? getActiveRound()	# Gives 0, because the integerPart has set the active round to 0

? n	# Gives only the integer part of n (123456789), because the round has been set to 0
? decimalPart(n,5)	# Now, we pass the n value but by specifying 5 as number of decimals
			# Then we get 0.12345

? getActiveRound()	# Actually, the active round has been set to 5

// NB: In all code you would write, you should get the active round before you do anything
// so you are not surprised when they have changed elsewhere.

func integerPart(nNumber)
	// Transforming the number to a string
	str = "" + nNumber

	// Walking through the string, from left to right, harvesting
	// the characters until we confront "."
	cTemp = ""
	for c in str
		if c = "." exit ok
		cTemp += c
	next

	// Transforming the resulting string to a number
	nRes = 0 + cTemp
	// Setting the active round to 0
	decimals(0)

	return nRes

func decimalPart(nNumber,nRound)
	// Same logic as for integerpart() but start walking at the "." separator + 1
	decimals(nRound)
	str = "" +nNumber
	cTemp = "0."

	nSepPos = 0

	// Getting the position of "." separator + 1
	for i=1 to len(str)
		if str[i] = "."
			nSepPos = i
			exit
		ok
	next

	if nSepPos = 0
		// There is no decimal part
		raise("Number with no decimal part !")
	else
		for i= nSepPos+1 to len(str)
			cTemp += str[i]
		next
		
		nRes = 0 + cTemp
		decimals(len(cTemp)-2)
		return nRes
	ok

func getActiveRound()
	nTemp = 12.1	# Any number but should contain decimals
	str = "" + nTemp
	
	nSepPos = len(str)

	// Getting the position of "." separator + 1
	for i=1 to len(str)
		if str[i] = "."
			nSepPos = i
			exit
		ok
	next

	nActiveRound = len(str) - nSepPos
	return nActiveRound
	
