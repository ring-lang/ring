#!ring -cgi

Load "weblib.ring"
Load "datalib.ring"
Load "openssllib.ring"
Load "ex25_users.ring"

Import System.Web

oUser = new UsersModel
oUser.Connect()
lResult = oUser.FindWith("username",aPageVars["username"])
new page {
	if lResult
		if sha256(aPagevars["password"]+oUser.Salt) = oUser.pwhash
			text ("Correct Password!")
			aPageVars["sessionid"] = str2hex(randbytes(32))
			oUser.UpdateColumn("sessionid",aPageVars["sessionid"])
			cookie("sessionid",aPageVars["sessionid"])
		else
			text ("Bad password!")
		ok
	else
		text("Bad User Name!")
	ok
}
oUser.Disconnect()
