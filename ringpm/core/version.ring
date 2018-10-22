/*
	Title :	The Ring Package Manager 
	Date  : 2018.10.19
	Author: Mahmoud Fayed <msfclipper@yahoo.com>
*/

func CheckRingVersion aPackageInfo
	# 1.0	1.1	.... 	1.8 1.9 1.10
	# 1.8 < 1.9 
	# 1.9 < 1.10
	if ProcessVersion(version()) >= ProcessVersion(aPackageInfo[:ringversion])
		 return True ok 
	return False 

func ProcessVersion cVersion
	// 	1.9		---->  001009
	//	1.10		---->  001010
	//	1.9 	<	1.10	----> Ring Output (False)
	//	001009	<	001010	----> Ring Output (True)
	# "1.9"	---> ["1","9"]
	aVersion = Split(cVersion,".")		# List of Numbers 
	# 1.9 ---> [ "001" , "009"]
		for cNumber in aVersion
			nSize = len(cNumber)
			if nSize < C_VERSIONSECTIONSIZE 
				cNumber = Copy("0",C_VERSIONSECTIONSIZE-nSize) + cNumber 
			ok
		next 
	cVersion = List2Str(aVersion)	# [ "001" , "009"] ---> "001" + nl + "009"
	cVersion = substr(cVersion,nl,"")
	return 0+cVersion		# "001009" ---> 1009 
