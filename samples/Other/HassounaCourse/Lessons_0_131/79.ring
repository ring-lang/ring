
func main

	for x=1 to 10
		deleteFolder("My Folder " + x)
	next

	//deleteFolder("New folder")
end



func deleteFolder(path)
	System(     'rmdir "' + path + '" '     )
end

