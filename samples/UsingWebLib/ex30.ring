#!ring -cgi

Load "weblib.ring"
Load "datalib.ring"
Load "ex25_users.ring"

Import System.Web

oUser = new UsersModel
oUser.Connect()
lResult = oUser.FindWith("sessionid",aPageVars["sessionid"])
new page {
	if lResult
		text("User Name : " + oUser.username )
	else
		text("Please Login First!")
	ok			
}
oUser.Disconnect()

