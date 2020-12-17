load "weblib.ring"
load "stdlib.ring"

cUploadFolder = '/uploads/'
cUploadPath = currentdir() + cUploadFolder

func isFound(elName)
	found = false
	for x in aPageVars
		if find(x,elName)
			found = true
			exit
		ok
	next
	return found

func upload(obj, cFile)
	if aPageVars[cFile] != char(13)
		file_name = obj.getFileName(aPageVars,cFile)
		cFileName = cUploadPath + file_name
		write(cFileName, aPageVars[cFile])
		system('chmod a+x ' + cFileName)
		return cUploadFolder + file_name
	ok
