load "stdlibcore.ring"
# 1 ---> File
	? getpathtype(exefilename())
# 2 ---> Folder
	? getpathtype(justfilepath(exefilename()))
# 0 ---> Doesn't exist
	? getpathtype("somethingdoesnotexit")
# 1 ---> Folder exist
	? direxists(justfilepath(exefilename()))
# 0 ---> Folder does not exist
	? direxists("somethingdoesnotexit")