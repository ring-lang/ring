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

func upload_with_name(obj, cFile, fileName)
	if aPageVars[cFile] != char(13)
		file_name = fileName
		cFileName = cUploadPath + file_name
		write(cFileName, aPageVars[cFile])
		system('chmod a+x ' + cFileName)
		return cUploadFolder + file_name
	ok

func upload(obj, cFile)
	return upload_with_name(obj, cFile, obj.getFileName(aPageVars,cFile))

