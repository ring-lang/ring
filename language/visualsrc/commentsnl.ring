/*
** A simple script that add a new line after copyright comments
** 2024, Mahmoud Fayed
*/

load "stdlibcore.ring"

func main

	# Prepare the source files directory

		cDir = CurrentDir()
		cDir = substr(cDir,"\visualsrc","")

	# Get header (*.h) and source (*.c) files

		aList  = listAllFiles(cDir+"\src","*.c")
		aList2 = listAllFiles(cDir+"\include","*.h")

	# Merge the two lists (Requires at least Ring 1.20)

		Add(aList,aList2,True)

	# Process the Files 

		for cFile in aList

			# Ignore the vmoop.c file
				if substr(cFile,"vmoop") loop ok

			# Read the file and convert it to a List
				cData = read(cFile)
				aDataList = Str2List(cData)

			# Check if we need to add a new line
				if len(trim(aDataList[2])) != 0
					insert(aDataList,1,"")
					? "Add new line to file: " + cFile
					cData = List2Str(aDataList)
					cData = substr(cData,nl,WindowsNL())
					write(cFile,cData+WindowsNL())
				ok

		next