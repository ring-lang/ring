# Purpose : Prepare the httpd.conf file based on the current Ring Path
# Author  : Mahmoud Fayed <msfclipper@yahoo.com>
# Date    : 2017.10.30

load "stdlib.ring"

if isMainSourceFile() 
	new ServerPrepare { start() }
ok

class ServerPrepare 
	func Start
		cExeFolder = substr(exefolder(),"\","/")
		cRingFolder = substr(cExeFolder,"/bin","")
		cFile = read("httpd.conf.template")
		cFile = substr(cFile,"#{SERVERPATH}",cRingFolder+"libdepwin/Apache2.2")
		cFile = substr(cFile,"#{APPLICATIONPATH}",cRingFolder+"ringlibs/weblib")
		write("../conf/httpd.conf",cFile)

	

