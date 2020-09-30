
func main
	deleteAllFiles("Folder3")
end


func deleteAllFiles(path)
	all = dir(path)
	for x=1 to len(all)
		Remove(path + "/" + all[x][1]  )
	next
end

