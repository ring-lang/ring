/*
	Title :	The Ring Package Manager 
	Date  : 2018.10.19
	Author: Mahmoud Fayed <msfclipper@yahoo.com>
*/

# Load Global Libraries 
	load "stdlibcore.ring"

# Load Application Files 
	load "packages.ring"
	load "globals.ring"

if isMainSourceFile()
	TestProcessVersion()
ok

func TestProcessVersion
	? 1.9 > 1.10			# 1 (True)
	? ProcessVersion("1.9")		# "1.9" --> "001009"   -->  1009
	? ProcessVersion("1.10")	# "1.10" ---> "001010" -->  1010
	? ProcessVersion("1.9") > ProcessVersion("1.10")	# 0 (False)

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

func GetMajorVersionNumber cVersion
	nPos = substr(cVersion,".")
	if nPos 
		cVersion = left(cVersion,nPos-1)
	ok
	return 0 + cVersion 

func GetMajorVersionText cVersion
	# Before version 1.0.0 ---> We return the package version 
	# From version 1.0.0 < 2.0.0 ---> We return empty string 
	# From 2.0.0 ---> We return the major version (v2, v3, etc)
	nMajor = GetMajorVersionNumber(cVersion)
	if nMajor = 0
		return "v"+cVersion
	but nMajor = 1 
		return 
	else 
		return "v"+nMajor
	ok

func IsCompatible cVersion1,cVersion2
	if cVersion1 != cVersion2
		if GetMajorVersionNumber(cVersion1) = 0 or
			GetMajorVersionNumber(cVersion1) != GetMajorVersionNumber(cVersion2)
			return False
		else 
			return True
		ok
	ok
	return True
