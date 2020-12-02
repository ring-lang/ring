load "db.ring"
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

if trim(aPageVars["cookie_login_user"]) != "" and trim(aPageVars['cookie_login_pass']) != ''
	if check_user_pass_normal(aPageVars["cookie_login_user"], aPageVars['cookie_login_pass'])
		aPageVars['is_login'] = True 
	else 
		aPageVars['is_login'] = False
	ok 
else
	aPageVars['is_login'] = False
ok


func MyVal(text)
	return substr(text, "'", "")

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

func getPage(htmlPageName, vars)
	cTempTop    = template("base/top.html", vars)
	cTempNav    = template("base/nav.html", vars)
	cTemp       = template(htmlPageName, vars)
	cTempFooter = template("base/footer.html", vars)
	cTempBottom = template("base/bottom.html", vars)

	strAll  = cTempTop
	strAll += cTempNav
	strAll += cTemp
	strAll += cTempFooter
	strAll += cTempBottom
	return strAll


func get_err()
	my_err = '
		<h3 class="alert alert-danger" id="lblErr"></h3>
		<script>
			var xhr = new XMLHttpRequest();
			xhr.open("GET", "err.ring");
			
			xhr.onreadystatechange = function () {
				var DONE = 4; 
				var OK = 200; 
				if (xhr.readyState === DONE) {
					window.lblErr.innerHTML = xhr.responseText;
					if(xhr.responseText==""){
						window.lblErr.style.display="none";
					}
				}
			};
			
			xhr.send(null);
		</script>
				'
	return my_err;






class hassounaPage from Page

	StartHtml()	

	Func starthtml 
		cStart = "Content-type: text/html" + nl + nl

	Func Print
		WebPrint( cCookies + GetHTMLStart() + cOutput )

	Func redirect(pageName)
		script( scriptredirection(pageName) )

	Func cookie_longtime(key, value)
		cCookies += get_cookie_longtime(key, value)

	Func cookie_del(key)
		cCookies += get_cookie_del(key)

	Func add_err(err)
		cookie_longtime("err", err )

	Func del_err()
		cookie_del("err")

	Func login(user, pass)
		if check_user_pass(user, pass)
			cookie("cookie_login_user", user)
			cookie("cookie_login_pass", sha256(pass))
			return true
		else
			return false
		ok 

	Func login_long(user, pass)
		if check_user_pass(user, pass)
			cookie_longtime("cookie_login_user", user)
			cookie_longtime("cookie_login_pass", sha256(pass))
			return true
		else
			return false
		ok 

	Func is_login()
		if trim(aPageVars["cookie_login_user"]) != "" and trim(aPageVars['cookie_login_pass']) != '' 
			if check_user_pass_normal(aPageVars["cookie_login_user"], aPageVars['cookie_login_pass'])
				return true
			else 
				return false
			ok 
		else
			return false
		ok

	Func logout()
		cookie_del("cookie_login_user")
		cookie_del("cookie_login_pass")





