load "weblib.ring"
load "stdlib.ring"
/*
	//if isNameFound('btn1')
	//fileUrl = upload_with_name(self, 'file1', '915.jpg')
	//fileUrl = upload(self, 'file1' )
*/
cUploadFolder = '/uploads/'
cUploadPath = currentdir() + cUploadFolder

func isNameFound(elName)
	found = false
	for x in aPageVars
		if x[1] = elName
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

