
func main

	for x=1 to 10
		createFolder("My Folder " + x)
	next

	//createFolder("My")
	//createFolder("My Folder")
end


func createFolder(path)
	System(    'mkdir "' + path + '" '    )
end


