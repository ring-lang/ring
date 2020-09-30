
func createFolder(path)
	System(    'mkdir "' + path + '" '    )
end

func deleteFolder(path)
	System(     'rmdir "' + path + '" '     )
end

func getRandom(min, max)
	randNum = Random(  max - min  ) + min
	return randNum
end

func deleteAllFiles(path)
	all = dir(path)
	for x=1 to len(all)
		Remove(path + "/" + all[x][1]  )
	next
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

func avg(numbers)
	av = sum(numbers) / len(numbers)
	return av
end

func sum(numbers)
	if type(numbers)="LIST"
		s = 0
		for x=1 to len(numbers)
			if type(numbers[x])!="NUMBER"
				see "Error: Please Use Number Only" + nl
			else
				s += numbers[x]
			ok
		next
		return s
	else
		see "Please Send LIST Only" + nl
	ok
end

func isNumberList(numberList)
	for x=1 to len(numberList)
		if Type( numberList[x] ) != "NUMBER"
			return false
		ok
	next
	return true
end

func isStringList(stringList)
	for x=1 to len(stringList)
		if Type( stringList[x] ) != "STRING"
			return false
		ok
	next
	return true
end


class myNote{

	func init(myPath){
		path = myPath + ".txt"
	}

	func addLine(line){
		f = fOpen(path , "a")
		fPuts( f , line + nl)
	}

	private
	path
}

