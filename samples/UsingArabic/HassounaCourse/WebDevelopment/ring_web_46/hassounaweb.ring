load "weblib.ring"
load "stdlib.ring"
/*
	//if isNameFound('btn1')
	//fileUrl = upload_with_name(self, 'file1', '915.jpg')
	//fileUrl = upload(self, 'file1' )
	//cCookies += get_cookie_longtime('lang','ring')
	//cCookies += get_cookie_del('name')
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

func get_cookie_longtime(key, value)
	ex = 'Mon, 09 Mar ' + ( number(timelist()[19])+1 ) + ' 08:13:24 GMT'
	return "Set-Cookie: " + key + "=" + value + "; expires=" + ex + ";" + nl

func get_cookie_del(key)
	ex = 'Mon, 09 Mar ' + ( number(timelist()[19])-1 ) + ' 08:13:24 GMT'
	return "Set-Cookie: " + key + "=0; expires=" + ex + ";" + nl

class hassounaPage from Page

	StartHtml()	

	Func starthtml 
		cStart = "Content-type: text/html" + nl + nl

	Func Print
		WebPrint( cCookies + GetHTMLStart() + cOutput )

