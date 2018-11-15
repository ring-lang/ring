/*
	Title :	The Ring Package Manager 
	Date  : 2018.11.14
	Author: Mahmoud Fayed <msfclipper@yahoo.com>
*/

func NewPackage cPackageName 
	cCurrentDir = CurrentDir()
	# Create the package folder
		Style("Creating new package: ",:YellowBlack) 
		? cPackagename 
		Style("Creating the package folder",:YellowBlack)
		see nl
		OSCreateOpenFolder(cPackageName)
	# Create the package file
		aPackageInfo = [
			:name 		= "The "+cPackageName+" Package",
			:description	= "Our "+cPackageName+" package using the Ring programming language",
			:folder		= JustFileName(cPackageName),	# if we have local/test1 , will return test1 only
			:developer  	= "YourName",
			:email		= "YourEmail",
			:license	= "MIT License",
			:version	= "0.1.0",
			:ringversion	= version(),
			:files 		= [
				"lib.ring",
				"main.ring"
			],
			:versions	= [
				[:version = "0.1.0" , :branch = "master"]
			],
			:libs		= [
				[:name = "", :version = ""]
			],
			:run		= "ring main.ring"
		] 	
		new List2Code {
			cPackageInfo = "aPackageInfo = " + List2Code(aPackageInfo)
		}
		Style("Writing : ",:YellowBlack) 
		? "package.ring"
		write("package.ring",cPackageInfo)
		Style("Writing : ",:YellowBlack) 
		? "lib.ring"
		write("lib.ring","# The Library File"+WindowsNL()+WindowsNL())
		Style("Writing : ",:YellowBlack) 
		? "main.ring"
		write("main.ring","# The Main File"+WindowsNL()+WindowsNL()+
				'load "lib.ring"'+WindowsNL()+WindowsNL()+
				  "func main"+WindowsNL()+WindowsNL()+
				  Tab + '? "Hello, World!"')
	chdir(cCurrentDir)
	if lDisplayOperationDone
		? "Operation done!"
	ok
