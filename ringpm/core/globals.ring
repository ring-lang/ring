/*
	Title :	The Ring Package Manager 
	Date  : 2018.10.18
	Author: Mahmoud Fayed <msfclipper@yahoo.com>
*/

# Errors 
	C_ERROR_NOPACKAGENAME			= "Error(1) : No package name!"
	C_ERROR_NOPACKAGEINFO 			= "Error(2) : No package info!"
	C_ERROR_WEDONTHAVETHISPACKAGE		= "Error(3) : We don't have this package"
	C_ERROR_PACKAGEINFOISNOTCORRECT 	= "Error(4) : Package info is not correct"
	C_ERROR_CANTDOWNLOADTHEPACKAGEFILE 	= "Error(5) : Can't download the package file"
	C_ERROR_BADRINGVERSION			= "Error(6) : Bad Ring Version"
	C_ERROR_PACKAGEALREADYEXISTS		= "Error(7) : Package Already Exists"
	C_ERROR_NOUPDATES 			= "Error(8) : No updates for this package"
	C_ERROR_THISPACKAGEISUSEDBYOTHERPACKAGES= "Error(9) : This package is used by other packages"
	C_ERROR_PACKAGENOTFOUND			= "Error(10): Package doesn't exist"
	C_ERROR_CANTWRITETHEFILE		= "Error(11): Can't write the file"
	C_ERROR_CANTGETPACKAGESINFORMATION	= "Error(12): Can't get install packages information"

# Where we will store our pacakge 
	lLocalPackages	   = True 
	cPackagesGitHub    = "https://raw.githubusercontent.com/MahmoudFayed"
	cPackagesLocal     = "b:\ring\ringpm\local"
	if lLocalPackages 
		cPackagesLocations = cPackagesLocal
	else 
		cPackagesLocations = cPackagesGitHub
	ok

# The parameters of our command 	
	aCommand	   = []

# Folders
	cMainPackagesFolder 	= "/packages"
	cPackageURL		= ""

# Version 
	C_VERSIONSECTIONSIZE	= 3

# All Packages Information

	oAllPackagesInfo = new AllPackagesInfo

# Flag for Install Errors 
	lInstallError 	= False 
