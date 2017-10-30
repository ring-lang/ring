# Purpose : Prepare the httpd.conf file based on the current Ring Path
# Author  : Mahmoud Fayed <msfclipper@yahoo.com>
# Date    : 2017.10.30

load "stdlib.ring"

# Use the Default Settings
	if isMainSourceFile() 
		new ServerPrepare { 
			PrepareConfigurationFile() 
			RunServer()
		}
	ok

class ServerPrepare 

	cExeFolder  	 = substr(exefolder(),"\","/")
	cRingFolder 	 = substr(cExeFolder,"/bin","")
	cServerPath 	 = cRingFolder+"libdepwin/Apache2.2"
	cApplicationPath = cRingFolder+"ringlibs/weblib"

	func PrepareConfigurationFile

		cFile = read(cServerPath+"/ring/httpd.conf.template")
		cFile = substr(cFile,"#{SERVERPATH}",cServerPath)
		cFile = substr(cFile,"#{APPLICATIONPATH}",cApplicationPath)
		write(cServerPath+"/conf/httpd.conf",cFile)

	func GetRingFolder

		return cRingFolder

	func SetApplicationPath cPath

		cApplicationPath = cPath

	func GetApplicationPath cPath

		return cApplicationPath

	func SetServerPath cPath

		cServerPath = cPath

	func GetServerPath

		return cServerPath

	func RunServer

		system("start " + cServerPath + "/bin/httpd.exe")
	
