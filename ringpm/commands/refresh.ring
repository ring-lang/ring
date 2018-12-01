/*
	Title :	The Ring Package Manager 
	Date  : 2018.11.20
	Author: Mahmoud Fayed <msfclipper@yahoo.com>
*/

func UpdateTheRegistry
	eval(read("registry/version.ring"))
	aLocalRegistryData =  [
		:nRegistryRev  		= nRegistryRev,
		:cRegistryLastUpdate 	= cRegistryLastUpdate,
		:nPackagesCount 	= nPackagesCount		
	]
	cRemoteVersionFile = download(AddTimeStamp(C_GITHUBUSERCONTENT+
				"ring-lang/ring/master/ringpm/registry/version.ring"))
	if cRemoteVersionFile = "" or
		substr(cRemoteVersionFile,"404") 
		? C_ERROR_CANTDOWNLOADTHEVERSIONFILE
		return 
	ok
	eval(cRemoteVersionFile)
	aRemoteRegistryData =  [
		:nRegistryRev  		= nRegistryRev,
		:cRegistryLastUpdate 	= cRegistryLastUpdate,
		:nPackagesCount 	= nPackagesCount		
	]
	if aLocalRegistryData[:nRegistryRev] = aRemoteRegistryData[:nRegistryRev]
		? "No updates to the Registry, Nothing to do!" 
		? Width("Revision Number",15) 	+ " : " + aRemoteRegistryData[:nRegistryRev]
		? Width("Last Update",15) 	+ " : " + aRemoteRegistryData[:cRegistryLastUpdate]
		? Width("Packages Count" ,15)	+ " : " + aRemoteRegistryData[:nPackagesCount]
		return 
	ok
	cRegistryFile = download(AddTimeStamp(C_GITHUBUSERCONTENT+
				"ring-lang/ring/master/ringpm/registry/registry.ring"))
	if cRegistryFile = "" or
		substr(cRegistryFile,"404") 
		? C_ERROR_CANTDOWNLOADTHEREGISTRYFILE
		return 
	ok
	if isWindows()
		cRegistryFile 		= substr(cRegistryFile,nl,WindowsNL())
		cRemoteVersionFile	= substr(cRemoteVersionFile,nl,WindowsNL())
	ok
	write("registry/registry.ring",cRegistryFile)
	write("registry/version.ring",cRemoteVersionFile)
	? "The Registry is updated from revision " + aLocalRegistryData[:nRegistryRev] + " (" +
		aLocalRegistryData[:cRegistryLastUpdate] + ") " + 
		"to revision " + aRemoteRegistryData[:nRegistryRev] + " (" +
		aRemoteRegistryData[:cRegistryLastUpdate] + ") "
 
