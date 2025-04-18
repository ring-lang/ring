/*
**	Application : Ring To Executable 
**	Purpose	    : Convert Ring project source code to executable file 
**		      (Windows, Linux & MacOS X)
**	Author	    : Mahmoud Fayed <msfclipper@yahoo.com>
**	Date	    : 2017.11.06
*/

/*
	Usage

		ring ring2exe.ring filename.ring  [Options]
		This will set filename.ring as input to the program 	

		The next files will be generated 
		filename.ringo	  (The Ring Object File - by Ring Compiler)
		filename.c	  (The C Source code file
				   Contains the ringo file content
				   Will be generated by this program)
		filename_buildvc.bat (Will be executed to build filename.c using Visual C/C++)
		filename_buildgcc.bat (Will be executed to build filename.c using GNU C/C++)
		filename_buildclang.bat (Will be executed to build filename.c using CLang C/C++)
		filename.obj	  (Will be generated by the Visual C/C++ compiler) 
		filename.exe 	  (Will be generated by the Visual C/C++ Linker)
		filename	  (Executable File - On Linux & MacOS X platforms)

	Note
		We can use 
			ring ring2exe.ring ring2exe.ring 
		This will build ring2exe.exe
		We can use ring2exe.exe 

		ring2exe filename.ring 

		Or (Linux & MacOS X)

		./ring2exe filename.ring

	Testing 	
	
		ring2exe test.ring 
		test 

		Or (Linux & MacOS X)

		./ring2exe test.ring 
		./test

	Options

		-keep       	 : Don't delete Temp. Files
		-static     	 : Build Standalone Executable File (Don't use ring.dll/ring.so/ring.dylib)
		-gui        	 : Build GUI Application (Hide the Console Window)
		-dist	    	 : Prepare application for distribution 
		-allruntime 	 : Include all libraries in distribution
		-mobileqt	 : Prepare Qt Project to distribute Ring Application for Mobile 
		-webassemblyqt	 : Prepare Qt Project to distribute Ring Application for Web using WebAssembly 
		-noqt	    	 : Remove RingQt from distribution
		-nolightguilib 	 : Remove RingQt (Light) from distribution
		-noallegro 	 : Remove RingAllegro from distribution
		-noopenssl  	 : Remove RingOpenSSL from distribution
		-nolibcurl  	 : Remove RingLibCurl from distribution
		-nomysql    	 : Remove RingMySQL from distribution
		-noodbc     	 : Remove RingODBC from distribution
		-nosqlite   	 : Remove RingSQLite from distribution
		-nopostgresql  	 : Remove RingPostgreSQL from distribution
		-noopengl   	 : Remove RingOpenGL from distribution
		-nofreeglut 	 : Remove RingFreeGLUT from distribution
		-nolibzip   	 : Remove RingLibZip from distribution
		-noconsolecolors : Remove RingConsoleColors from distribution
		-nomurmurhash    : Remove RingMurmurHash from distribution 
		-nocruntime	 : Remove C Runtime from distribution
		-qt	    	 : Add RingQt to distribution
		-lightguilib	 : Add RingQt (Light) to distribution
		-allegro 	 : Add RingAllegro to distribution
		-openssl  	 : Add RingOpenSSL to distribution
		-libcurl  	 : Add RingLibCurl to distribution
		-mysql    	 : Add RingMySQL to distribution
		-odbc     	 : Add RingODBC to distribution
		-sqlite   	 : Add RingSQLite to distribution
		-postgresql   	 : Add RingPostgreSQL to distribution
		-opengl   	 : Add RingOpenGL to distribution
		-freeglut 	 : Add RingFreeGLUT to distribution
		-libzip   	 : Add RingLibZip to distribution
		-libuv		 : Add RingLibuv to distribution
		-consolecolors   : Add RingConsoleColors to distribution
		-murmurhash	 : Add RingMurmurHash to distribution
		-cruntime	 : Add C Runtime to distribution
*/

load "stdlibcore.ring"

# Load Libraries information
	aLibsInfo = []
	LoadLibrariesInfo()

func LoadLibrariesInfo
	aLibsFiles = ListAllFiles(exefolder()+"/../tools/ring2exe/libs","ring")
	for cLibFile in aLibsFiles 
		eval(read(cLibFile))
		aLibsInfo + aLibrary 
	next 

func Main 
	aPara = sysargv
	aOptions = []
	# Get Options 
		for x = len(aPara) to 1 step -1
			if left(trim(aPara[x]),1) = "-"
				aOptions + lower(trim(aPara[x]))
				del(aPara,x)
			ok
		next
	nParaCount = len(aPara)
	if (nParaCount > 2) or ( nParaCount = 2 and aPara[1] != "ring" )
		cFile = aPara[nParaCount]
		if not fexists(cFile)
			msg("File " + cFile + " doesn't exist!")
			bye
		ok
		msg("Process File : " + cFile)
		chdir(justfilepath(cFile))
		cFile = justfilename(cFile)
		BuildApp(cFile,aOptions)
	else 
		drawline()
		see "Ring2EXE (Convert Ring Application To Executable File)" + nl
		see "2017-2025, Mahmoud Fayed <msfclipper@yahoo.com>" + nl
		see "Usage : ring2exe filename.ring [Options]" + nl
		drawline()
		see RemoveTabs("
		-keep            : Don't delete Temp. Files
		-static          : Don't use ring.dll/ring.so/ring.dylib
		-gui             : Build GUI Application (Hide the Console Window)
		-dist            : Prepare application for distribution 
		-allruntime      : Include all libraries in distribution
		-mobileqt        : Prepare Qt Project for Mobile 
		-webassemblyqt   : Prepare Qt Project for WebAssembly 
		-<library>       : Include <library> in distribution
		-no<library>     : Don't include <library> in distribution ")
		drawline()
	ok

func DrawLine 
	see copy("=",75) + nl

func msg cMsg
	see "Ring2EXE: " + cMsg + nl

func BuildApp cFileName,aOptions
	msg("Start building the application...")
	# Generate the Object File 
		systemSilent('"' + exefolder()+"../bin/ring" + '" ' + cFileName + " -go -norun")
	# Generate the C Source Code File 
		cFile = substr(cFileName,".ring","")
		GenerateCFile(cFile,aOptions)
	# Generate the Batch File 
		cBatch = GenerateBatch(cFile,aOptions)
	# Build the Executable File 
		msg("Build the Executable File...")
		systemSilent(cBatch)
		msg("End of building script...")
	# Prepare Application for distribution
		if find(aOptions,"-dist")
			Distribute(cFile,aOptions)
		else 
			if CheckNoCCompiler(currentdir(),cFile,aOptions)
				if not find(aOptions,"-keep")
					ClearTempFiles(2)
				ok
				EndofBuildingMsg()
				return 
			ok
		ok
		EndofBuildingMsg()
	# Clear Temp Files 	
		if not find(aOptions,"-keep")
			cleartempfiles(1)
		ok

func EndofBuildingMsg
	msg("End of building process...")

func GenerateCFile cFileName,aOptions
	# Display Message
		msg("Generate C source code file...")
	nTime = clock()
	# Convert the Ring Object File to Hex.
		cRingoFile = cFileName+".ringo"
		if not fexists(cRingoFile)
			msg("File " + cRingoFile + " doesn't exist!")
			msg("Check the source code files for compiler errors")
			bye
		ok
		cFile = read(cRingoFile)
		cHex  = str2hexCStyle(cFile)
	fp = fopen(cFileName+".c","w+")
	# Start writing the C source code - Main Function 
	if isWindows() and find(aOptions,"-gui")
		cCode = '#include "windows.h"' 	+ nl +
			'#include "stdio.h"' 	+ nl +
			'#include "stdlib.h"' 	+ nl +
			'#include "conio.h"' 	+ nl +  
			'#include "ring.h"' 	+ nl +  nl +
		'int WINAPI WinMain ( HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd )' + nl +  "{" + nl + nl +
		char(9) + 'int argc;' + nl + char(9) + 'char **argv ;' + nl + 
		char(9) + 'argc = __argc ; ' + nl + char(9) + 'argv = __argv ;' + nl + nl +
		char(9) + 'static const unsigned char bytecode[] = { 
			  '
	else
		cCode = '#include "ring.h"' + nl + nl +
		'int main( int argc, char *argv[])' + nl +  "{" + nl + nl +
		char(9) + 'static const unsigned char bytecode[] = { 
			  '
	ok
	fputs(fp,cCode)
	# Add the Object File Content		
		fputs(fp,cHex)
	fputs(fp, ", EOF" + char(9) + "};"+substr(
	'

	RingState *pRingState ;
	pRingState = ring_state_new();	
	pRingState->nArgc = argc;
	pRingState->pArgv = argv;
	ring_state_runobjectstring(pRingState,(char *) bytecode,"#{f1}");
	ring_state_delete(pRingState);

	return 0;',"#{f1}",cFileName+".ring") + nl + 
	"}")
	fclose(fp)	
	msg("Generation Time : " + ((clock()-nTime)/clockspersecond()) + " seconds...")

func GenerateBatch cFileName,aOptions
	msg("Generate batch|script file...")
	if find(aOptions,"-static")
		return GenerateBatchStatic(cFileName,aOptions)
	else 
		return GenerateBatchDynamic(cFileName,aOptions)
	ok

func GenerateBatchDynamic cFileName,aOptions
	msg("Generate batch|script file for dynamic building...")
	return GenerateBatchGeneral([
		:file = cFileName ,
		:ringlib = [
			:windows = exefolder() + "..\lib\ring.lib" ,
			:linux   = "-L "+exefolder()+"/../lib -lring",
			:macosx	 = exefolder() + "/../lib/libring.dylib"
		]
	],aOptions)	

func GenerateBatchStatic cFileName,aOptions
	msg("Generate batch|script file for static building...")
	return GenerateBatchGeneral([
		:file = cFileName ,
		:ringlib = [
			:windows = exefolder()+"..\lib\ringstatic.lib" ,
			:linux   = "-L "+exefolder()+"/../lib -lringstatic",
			:macosx	 = "-L "+exefolder()+"/../lib -lringstatic"
		]
	],aOptions)


func GenerateBatchGeneral aPara,aOptions
	cFileName = aPara[:file]
	cFile = substr(cFileName," ","_")
	# Generate Windows Batch (Visual C/C++)
		cBuildtarget = getarch()
		if cBuildtarget = "unknown"
			cBuildtarget = "x86"
		ok
		cCode = "setlocal enableextensions enabledelayedexpansion" + nl + 'call "'+exefolder()+'../language/build/locatevc.bat" ' + cBuildtarget + nl +
			"#{f3}" + nl +
			'cl /O2 "#{f1}.c" "#{f2}" #{f4} -I"#{f6}..\language\include" -I"#{f6}../language/src/" /link #{f5}' + nl +
			"endlocal" + nl 
		cCode = substr(cCode,"#{f1}",cFile)
		cCode = substr(cCode,"#{f2}",aPara[:ringlib][:windows])
		# Resource File 
			cResourceFile = cFile + ".rc"
			if fexists(cResourceFile)
				cCode = substr(cCode,"#{f3}","rc " + cResourceFile)
				cCode = substr(cCode,"#{f4}",cFile + ".res")
			else 
				cCode = substr(cCode,"#{f3}","")
				cCode = substr(cCode,"#{f4}","")
			ok
		# GUI Application 
			if find(aOptions,"-gui")
				cCode = substr(cCode,"#{f5}",'advapi32.lib shell32.lib /STACK:8388608 /SUBSYSTEM:WINDOWS,"5.01" ')
			else 
				cCode = substr(cCode,"#{f5}",' /STACK:8388608 /SUBSYSTEM:CONSOLE,"5.01" ')
			ok
		cCode = substr(cCode,"#{f6}",exefolder())
		cWindowsBatch = cFile+"_buildvc.bat"
		write(cWindowsBatch,cCode)
	# Generate Linux Script (GNU C/C++)
		cCode = 'gcc -rdynamic -O2 #{f1}.c -o #{f1} #{f2} -lm -ldl  -I #{f3}/../language/include  '
		cCode = substr(cCode,"#{f1}",cFile)
		cCode = substr(cCode,"#{f2}",aPara[:ringlib][:linux])
		cCode = substr(cCode,"#{f3}",exefolder())
		cLinuxBatch = cFile+"_buildgcc.sh"
		write(cLinuxBatch,cCode)
	# Generate MacOS X Script (CLang C/C++)
		cCode = 'clang -O2 #{f1}.c #{f2} -o #{f1} -lm -ldl  -I #{f3}/../language/include  '
		cCode = substr(cCode,"#{f1}",cFile)
		cCode = substr(cCode,"#{f2}",aPara[:ringlib][:macosx])
		cCode = substr(cCode,"#{f3}",exefolder())
		cMacOSXBatch = cFile+"_buildclang.sh"
		write(cMacOSXBatch,cCode)
	# Return the script/batch file name
		if isWindows()	
			return cWindowsBatch
		but isLinux()
			systemSilent("chmod +x " + cLinuxBatch)
			return "./"+cLinuxBatch
		but isMacosx()
			systemSilent("chmod +x " + cMacOSXBatch)
			return "./"+cMacOSXBatch	
		ok

func ClearTempFiles nPara
	msg("Clear Temp. Files...")
	cTempFile = "cleartemp"
	if not nPara = 1
		# Don't delete *.ringo files (distribution using Ring way)
		cTempFile += "2"
	ok
	if isWindows()
		systemSilent(exefolder()+"/../tools/ring2exe/"+cTempFile+".bat")
	else
		systemSilent(exefolder()+"/../tools/ring2exe/"+cTempFile+".sh")
	ok


func Distribute cFileName,aOptions
	cBaseFolder = currentdir()
	OSCreateOpenFolder(:target)
	if find(aOptions,"-mobileqt")
		# Prepare Application for Mobile (RingQt)
		DistributeForMobileQt(cBaseFolder,cFileName,aOptions)
	but find(aOptions,"-webassemblyqt")
		# Prepare Application for WebAssembly (RingQt)
		DistributeForWebAssemblyQt(cBaseFolder,cFileName,aOptions)
	but isWindows()
		DistributeForWindows(cBaseFolder,cFileName,aOptions)
	but isLinux()
		DistributeForLinux(cBaseFolder,cFileName,aOptions)
	but isMacOSX()
		DistributeForMacOSX(cBaseFolder,cFileName,aOptions)
	ok
	# Delete the executable file
		if isWindows()
			OSDeleteFile(cBaseFolder+"\"+cFileName+".exe")
		ok
	chdir(cBaseFolder)

func DistributeForWindows cBaseFolder,cFileName,aOptions
	# Delete Files 
		OSDeleteFolder("windows")
	OSCreateOpenFolder(:windows)
	# copy the executable file 
		msg("Copy the executable file to target/windows")
		OSCopyFile(cBaseFolder+"\"+cFileName+".exe")
		CheckNoCCompiler(cBaseFolder,cFileName,aOptions)
	# Check ring.dll
		if not find(aOptions,"-static")	
			msg("Copy ring.dll to target/windows")	
			OSCopyFile(exefolder()+"\ring.dll")
		ok
	# Check All Runtime 
		if find(aOptions,"-allruntime")	
			msg("Copy all libraries to target/windows")	
			for aLibrary in aLibsInfo 
				if not find(aOptions,"-no"+aLibrary[:name])
					msg("Copy library files: "+aLibrary[:title])
					if islist(aLibrary[:windowsfolders])
						for cLibFolder in aLibrary[:windowsfolders]
							msg("Copy folder: "+cLibFolder)
							OSCopyFolder(exefolder(),cLibFolder)
						next
					ok
					if islist(aLibrary[:windowsfiles])
						for cLibFile in aLibrary[:windowsfiles]
							msg("Copy file: "+cLibFile)
							custom_OSCopyFile(exefolder(),cLibFile)
						next
					ok
				else 
					msg("Skip library "+aLibrary[:title])
				ok
			next  	
		else	# No -allruntime
			for aLibrary in aLibsInfo 
				if find(aOptions,"-"+aLibrary[:name])
					msg("Add "+aLibrary[:title]+" to target/windows")
					if islist(aLibrary[:windowsfolders])
						for cLibFolder in aLibrary[:windowsfolders]
							msg("Copy folder: "+cLibFolder)
							OSCopyFolder(exefolder(),cLibFolder)
						next
					ok
					if islist(aLibrary[:windowsfiles])
						for cLibFile in aLibrary[:windowsfiles]
							msg("Copy file: "+cLibFile)
							custom_OSCopyFile(exefolder(),cLibFile)
						next
					ok
				ok
			next 				
		ok
	# Copy Files (Images, etc) in Resources File
		CheckQtResourceFile(cBaseFolder,cFileName,aOptions)

func DistributeForLinux cBaseFolder,cFileName,aOptions
	# Delete Files 
		OSDeleteFolder(:linux)
	OSCreateOpenFolder(:linux)
	cLinuxDir = currentdir()
	OSCreateOpenFolder("dist_using_deb_package")
	cDebDir = currentdir() 
	chdir(cLinuxDir)
	OSCreateOpenFolder("dist_using_scripts")
	cDir = currentdir()
	OSCreateOpenFolder(:bin)
	# copy the executable file 
		msg("Copy the executable file to target/linux/bin")
		OSCopyFile(cBaseFolder+"/"+cFileName)
		CheckNoCCompiler(cBaseFolder,cFileName,aOptions)
	# Copy Files (Images, etc) in Resources File
		CheckQtResourceFile(cBaseFolder,cFileName,aOptions)
	chdir(cDir)
	OSCreateOpenFolder(:lib)
	cInstallUbuntu = "sudo apt-get install"
	cInstallFedora = "sudo dnf install"
	cInstallLibs   = ""
	cDebianPackageDependency = ""
	# Check ring.so
		if not find(aOptions,"-static")	
			msg("Copy libring.so to target/linux/lib")	
			OSCopyFile(exefolder()+"/../lib/libring.so")
		ok
		cInstallLibs = InstallLibLinux(cInstallLibs,"libring.so")
	# Check All Runtime 
		if find(aOptions,"-allruntime")	
			msg("Copy all libraries to target/linux/lib")
			OSCopyFile(exefolder()+"/../lib/libring.so")	
			for aLibrary in aLibsInfo 
				if not find(aOptions,"-no"+aLibrary[:name])
					if islist(aLibrary[:linuxfiles])
						for cLibFile in aLibrary[:linuxfiles]
							msg("Copy file: "+cLibFile)
							OSCopyFile(exefolder()+"/../lib/"+cLibFile)					
							cInstallLibs = InstallLibLinux(cInstallLibs,cLibFile)
						next
					ok
					cInstallUbuntu += (" " + aLibrary[:ubuntudep])
					cInstallFedora += (" " + aLibrary[:fedoradep])
					if aLibrary[:ubuntudep] != NULL
						cDebianPackageDependency += (" " + aLibrary[:ubuntudep])			
					ok
				else 
					msg("Skip library "+aLibrary[:title])
				ok
			next  	
		else	# No -allruntime
			for aLibrary in aLibsInfo 
				if find(aOptions,"-"+aLibrary[:name])
					msg("Add "+aLibrary[:title]+" to target/linux/lib")
					if islist(aLibrary[:linuxfiles])
						for cLibFile in aLibrary[:linuxfiles]
							msg("Copy file: "+cLibFile)
							OSCopyFile(exefolder()+"/../lib/"+cLibFile)
							cInstallLibs = InstallLibLinux(cInstallLibs,cLibFile)
						next
					ok
					cInstallUbuntu += (" " + aLibrary[:ubuntudep])
					cInstallFedora += (" " + aLibrary[:fedoradep])					
					if aLibrary[:ubuntudep] != NULL
						cDebianPackageDependency += (" " + aLibrary[:ubuntudep])			
					ok
				ok
			next 				
		ok
	# Script to install the application 
	chdir(cDir)
	if cInstallUbuntu != "sudo apt-get install"
		cInstallUbuntu += (nl+cInstallLibs)
		write("install_ubuntu.sh",cInstallUbuntu)
		SystemSilent("chmod +x install_ubuntu.sh")
	ok
	if cInstallFedora != "sudo dnf install"
		cInstallFedora += (nl+cInstallLibs)
		write("install_fedora.sh",cInstallFedora)	
		SystemSilent("chmod +x install_fedora.sh")
	ok
	# Create the debian package 
	msg("Prepare files to create the Debian package")
	chdir(cDebDir)
	cAppName = substr(cFileName," ","_")
	cBuildDeb = "dpkg-deb --build #{f1}_1.0-1"
	cBuildDeb = substr(cBuildDeb,"#{f1}",cAppName)
	write("builddeb.sh",cBuildDeb)
	SystemSilent("chmod +x builddeb.sh")
	OSCreateOpenFolder(cAppName+"_1.0-1")
	cAppFolder = currentdir()
	OSCreateOpenFolder("DEBIAN")
	cControl = RemoveFirstTabs("
		Package: #{f1}
		Version: 1.0-1
		Section: base
		Priority: optional
		Architecture: amd64
		Depends: #{f2}
		Maintainer: Developer Name <youraccount@email.com>
		Description: Ring Application",2) + nl
	cDebianPackageDependency = trim(cDebianPackageDependency)
	cDebianPackageDependency = substr(cDebianPackageDependency," "," (>=0) ,")
	cDebianPackageDependency += " (>=0) "
	cControl = substr(cControl,"#{f1}",cAppName)
	cControl = substr(cControl,"#{f2}",cDebianPackageDependency)
	write("control",cControl)
	cPostInst = RemoveFirstTabs("
		#!/bin/sh
		cd /usr/local/#{f1}/bin
		./#{f1}
		exit 0
	",2)
	cPostInst = substr(cPostInst,"#{f1}",cAppName)
	write("postinst",cPostInst)
	SystemSilent("chmod +x postinst")
	chdir(cAppFolder)
	OSCreateOpenFolder("usr")
		cUsrFolder = currentdir()
		OSCreateOpenFolder("bin")
		write(cFileName,"/usr/local/"+cAppName+"/bin/"+cFileName+" \$1 \$2 \$3 \$4 \$5 \$6 \$7")
		systemSilent("chmod +x " + cFileName)
		chdir(cUsrFolder)
		OSCreateOpenFolder("lib")
		chdir(cUsrFolder)
		OSCreateOpenFolder("local")
			OSCreateOpenFolder(cAppName)
				OSCreateOpenFolder("bin")
	chdir(cAppFolder)
	systemSilent("cp -a ../../dist_using_scripts/lib/. usr/lib/")
	systemSilent("cp -a ../../dist_using_scripts/bin/. usr/local/"+cAppName+"/bin/")

func InstallLibLinux cInstallLib,cLibFile 
	cCode = "
		if [ -f lib/#{f1} ];
		then
			sudo cp lib/#{f1} /usr/lib
			sudo cp lib/#{f1} /usr/lib64
		fi
	"
	cCode = SubStr(cCode,"#{f1}",cLibFile)
	cCode = RemoveFirstTabs(cCode,2)
	return cInstallLib + cCode

func RemoveFirstTabs cString,nCount
	aList = str2list(cString)
	for item in aList 
		if left(item,nCount) = Copy(char(9),nCount)
			if len(item) > nCount
				item = substr(item,nCount+1)
			ok
		ok
	next
	return list2str(aList)

func DistributeForMacOSX cBaseFolder,cFileName,aOptions
	# Delete Files 
		OSDeleteFolder(:macosx)
	OSCreateOpenFolder(:macosx)
	cDir = currentdir()
	OSCreateOpenFolder(:bin)
	# copy the executable file 
		msg("Copy the executable file to target/macosx/bin")
		OSCopyFile(cBaseFolder+"/"+cFileName)
		CheckNoCCompiler(cBaseFolder,cFileName,aOptions)
	# Copy Files (Images, etc) in Resources File
		CheckQtResourceFile(cBaseFolder,cFileName,aOptions)
	chdir(cDir)
	OSCreateOpenFolder(:lib)
	cInstallmacosx = "brew install -k"
	cInstallLibs   = ""
	# Check ring.dylib
		if not find(aOptions,"-static")	
			msg("Copy libring.dylib to target/macosx/lib")	
			OSCopyFile(exefolder()+"/../lib/libring.dylib")
		ok
		cInstallLibs = InstallLibMacOSX(cInstallLibs,"libring.dylib")
	# Check All Runtime 
		if find(aOptions,"-allruntime")	
			msg("Copy all libraries to target/macosx/lib")
			OSCopyFile(exefolder()+"/../lib/libring.dylib")	
			for aLibrary in aLibsInfo 
				if not find(aOptions,"-no"+aLibrary[:name])
					if islist(aLibrary[:macosxfiles])
						for cLibFile in aLibrary[:macosxfiles]
							OSCopyFile(exefolder()+"/../lib/"+cLibFile)
							cInstallLibs = InstallLibMacOSX(cInstallLibs,cLibFile)
						next
					ok
					cInstallMacOSX += (" " + aLibrary[:macosxdep])
				else 
					msg("Skip library "+aLibrary[:title])
				ok
			next  	
		else	# No -allruntime
			for aLibrary in aLibsInfo 
				if find(aOptions,"-"+aLibrary[:name])
					msg("Add "+aLibrary[:title]+" to target/macosx/lib")
					if islist(aLibrary[:macosxfiles])
						for cLibFile in aLibrary[:macosxfiles]
							OSCopyFile(exefolder()+"/../lib/"+cLibFile)
							cInstallLibs = InstallLibMacOSX(cInstallLibs,cLibFile)
						next
					ok
					cInstallMacOSX += (" " + aLibrary[:macosxdep])
				ok
			next 				
		ok
	# Script to install the application 
	chdir(cDir)
	if cInstallmacosx != "brew install -k"
		cInstallmacosx += (nl+cInstallLibs)
		write("install.sh",cInstallMacOSX)
		SystemSilent("chmod +x install.sh")
	ok

func InstallLibMacOSX cInstallLib,cLibFile 
	cCode = "
		if [ -f lib/#{f1} ];
		then
			cp lib/#{f1} /usr/local/lib
		fi
	"
	cCode = SubStr(cCode,"#{f1}",cLibFile)
	cCode = RemoveFirstTabs(cCode,2)
	return cInstallLib + cCode

func DistributeForMobileQt cBaseFolder,cFileName,aOptions
	msg("Prepare RingQt project to distribute for Mobile")
	# Delete Files 
		OSDeleteFolder(:mobile)
	OSCreateOpenFolder(:mobile)
	OSCreateOpenFolder(:qtproject)
	msg("Copy RingQt for Mobile project files...")
	OSCopyFile(exefolder() + "../extensions/android/ringqt/project/*.*" )
	OSDeleteFile("project.pro.user")
	msg("Prepare the Ring Object (*.ringo) file...")
	OSDeleteFile("ringapp.ring")
	OSDeleteFile("ringapp.ringo")
	cRINGOFile = cBaseFolder+"/"+cFileName+".ringo"
	msg("Get the Ring Object File")
	OSCopyFile(cRINGOFile)
	write("main.cpp",substr(read("main.cpp"),"ringapp.ringo",cFileName+".ringo"))
	write("project.qrc",substr(read("project.qrc"),"ringapp.ringo",cFileName+".ringo"))
	CheckQtResourceFile(cBaseFolder,cFileName,aOptions)
	cMainFile = cBaseFolder+"/"+"main.cpp"
	if fexists(cMainFile)
		msg("We have the Main File : " + cMainFile)
		msg("Copy the Main file to target/mobile/qtproject")
		OSDeleteFile("main.cpp")
		OSCopyFile(cMainFile)
	ok
	msg("Copy Ring and RingQt folders...")
	if isWindows()
		OSCopyFolder(exefolder() + "..\extensions\android\ringqt\project\","ring" )
		OSCopyFolder(exefolder() + "..\extensions\android\ringqt\project\","ringqt" )
	else
		OSCopyFolder(exefolder() + "../extensions/android/ringqt/project/","ring" )
		OSCopyFolder(exefolder() + "../extensions/android/ringqt/project/","ringqt" )
	ok

func DistributeForWebAssemblyQt cBaseFolder,cFileName,aOptions
	msg("Prepare RingQt project to distribute for Web (WebAssembly)")
	# Delete Files 
		OSDeleteFolder(:webassembly)
	OSCreateOpenFolder(:webassembly)
	OSCreateOpenFolder(:qtproject)
	msg("Copy RingQt for WebAssembly project files...")
	OSCopyFile(exefolder() + "../extensions/webassembly/ringqt/project/*.*" )
	OSDeleteFile("project.pro.user")
	msg("Prepare the Ring Object (*.ringo) file...")
	OSDeleteFile("ringapp.ring")
	OSDeleteFile("ringapp.ringo")
	cRINGOFile = cBaseFolder+"/"+cFileName+".ringo"
	msg("Get the Ring Object File")
	OSCopyFile(cRINGOFile)
	write("main.cpp",substr(read("main.cpp"),"ringapp.ringo",cFileName+".ringo"))
	write("project.qrc",substr(read("project.qrc"),"ringapp.ringo",cFileName+".ringo"))
	CheckQtResourceFile(cBaseFolder,cFileName,aOptions)
	cMainFile = cBaseFolder+"/"+"main.cpp"
	if fexists(cMainFile)
		msg("We have the Main File : " + cMainFile)
		msg("Copy the Main file to target/webassembly/qtproject")
		OSDeleteFile("main.cpp")
		OSCopyFile(cMainFile)
	ok
	msg("Copy Ring and RingQt folders...")
	if isWindows()
		OSCopyFolder(exefolder() + "..\extensions\webassembly\ringqt\project\","ring" )
		OSCopyFolder(exefolder() + "..\extensions\webassembly\ringqt\project\","ringqt" )
	else
		OSCopyFolder(exefolder() + "../extensions/webassembly/ringqt/project/","ring" )
		OSCopyFolder(exefolder() + "../extensions/webassembly/ringqt/project/","ringqt" )
	ok

func CheckQtResourceFile cBaseFolder,cFileName,aOptions
	cResourceFile = cBaseFolder+"/"+"project.qrc"
	if fexists(cResourceFile)
		msg("We have Qt Resource File : " + cResourceFile)
		msg("Copy the resource file to the Qt project folder")
		OSDeleteFile("project.qrc")
		OSCopyFile(cResourceFile)
		msg("Copy files added to the Resource file")
		cResourceFileContent = read(cResourceFile)
		aResourceFileContent = str2list(cResourceFileContent)
		aFiles = []
		for cItem in aResourceFileContent
			if substr(cItem,"<file>") and substr(cItem,"</file>")
				cFile = cItem 
				cFile = trim(cFile)
				cFile = substr(cFile,char(9),"")
				cFile = substr(cFile,"<file>","")
				cFile = substr(cFile,"</file>","")
				if right(cFile,5) != "ringo"
					aFiles + cFile
				ok
			ok
		next
		for cFile in aFiles 
			msg("Copy File : " + cFile)
			custom_OSCopyFile(cBaseFolder,cFile)
		next
	ok

func custom_OSCopyFile cBaseFolder,cFile
	cDir = currentdir()
	cFolder = justfilepath(cFile)
	if cFolder != ""
		# Remove last / in the path
		cFolder = left(cFolder,len(cFolder)-1)
		OSCreateOpenFolder(cFolder)
	ok
	OSCopyFile(cBaseFolder+"/"+cFile)
	chdir(cDir)



func CheckNoCCompiler cBaseFolder,cFileName,aOptions 
	# If we don't have a C compiler 
	# We copy ring.exe to be app.exe 
	# Then we change app.ringo to ring.ringo 
	if isWindows()
		cExeFile = cBaseFolder+"\"+cFileName+".exe"
	else 
		cExeFile = cBaseFolder+"/"+cFileName
	ok
	if fexists(cExeFile)
		msg("Executable file is ready!")
		return False
	ok
	if isWindows()
		cRingOFile = cBaseFolder+"\"+cFileName+".ringo"
	else 
		cRingOFile = cBaseFolder+"/"+cFileName+".ringo"
	ok
	if fexists(cRingOFile)
		msg("No Executable, Looks like we don't have a C Compiler!")
	else 
		msg("No Ring Object File!")
		return False
	ok	
	msg("Using the Ring Way to create executable file without a C Compiler!")
	cRingExeFile = exefolder() + "/ring"
	if isWindows() 
		if find(aOptions,"-gui") 
			# use ringw.exe if -gui specified
			cRingExeFile += "w.exe"
		else 
			cRingExeFile += ".exe"
		ok
	ok
	OSCopyFile(cRingExeFile)
	if isWindows()
		if find(aOptions,"-gui") 
			OSRenameFile("ringw.exe",cFileName+".exe")
		else
			OSRenameFile("ring.exe",cFileName+".exe")
		ok
		OSCopyFile(cBaseFolder+"\"+cFileName+".ringo")
	else 
		OSRenameFile("ring",cFileName)
		OSCopyFile(cBaseFolder+"/"+cFileName+".ringo")
	ok
	OSRenameFile(cFileName+".ringo","ring.ringo")
	return True

func removeTabs cStr
	cOutput = ""
	aList = str2list(cStr)
	for item in aList
		if trim(item) = NULL loop ok
		while left(item,1) = tab
			item = substr(item,2)
		end
		cOutput += item + nl
	next
	return cOutput
