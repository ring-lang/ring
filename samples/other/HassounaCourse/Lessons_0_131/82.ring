
func main
	deleteAllFolders("Folder2")
end


func deleteAllFolders(path)
	all = dir(path)
	for x=1 to len(all)
		if all[x][2]=1
			deleteAllFiles(path + "/" + all[x][1])
			deleteFolder(path + "/" + all[x][1])
		ok
	next
end

func deleteFolder(path)
	System(     'rmdir "' + path + '" '     )
end

func deleteAllFiles(path)
	all = dir(path)
	for x=1 to len(all)
		Remove(path + "/" + all[x][1]  )
	next
end
