func CreateSubFolders cFileName 
	# Remove the file name - Keep the PATH 
		cPath = JustFilePath(cFileName)
		# Support for Windows, Linux, macOS
			cPath = substr(cPath,"\","/")
		aFolders = Split(cPath,"/")
		# Create Folder and sub folders 
			for cFolder in aFolders 
				OSCreateOpenFolder(cFolder)
			next 
