func WebAssemblyUpload cFileType,cCode
	oTempDialog = new QFileDialog(NULL) 
	QFileDialog_getopenFileContent(oTempDialog.pObject,cFileType,cCode)

func WebAssemblyDownload cFileName,cStr
	oTempBytes 	= new QByteArray()
	oTempBytes.append_2(cStr,len(cStr))
	oTempDialog = new QFileDialog(NULL) 
	QFileDialog_SaveFileContent(oTempDialog.pObject,oTempBytes.pObject,cFileName)

func WebAssemblyUploadedFileName
	return QFileDialog_FileContentList()[1]

func WebAssemblyUploadedFileContent
	return QFileDialog_FileContentList()[2]
