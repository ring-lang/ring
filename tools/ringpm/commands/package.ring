/*
	Title :	The Ring Package Manager 
	Date  : 2018.11.29
	Author: Mahmoud Fayed <msfclipper@yahoo.com>
*/

func CreatePackageInTheCurrentFolder
	? "Create package in the current folder"
	cDir = CurrentDir()
	# Get List of Files in the current folder 
		new ListOfFiles {
			aFiles	= ListAllFiles(cDir,"")
		}
	# Remove the folder path from the file name
		for item in aFiles 
			item = substr(item,"\","/")
			item = substr(item,substr(cDir,"\","/")+"/","")
		next 
	# Create the Package Files 	
		new PackageCreator {
			for item in aFiles 
				if item != "package.ring" and not find(aPackageFiles,item) and left(item,4) != ".git"
					aPackageFiles + item 
				ok
			next 
			CreatePackageFiles(cDir)
		}
	
	
