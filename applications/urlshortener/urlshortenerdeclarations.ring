/*
 * Most/ALL of the application's strings are defined here.
 * These strings define function calls, UI element text, application name,
 * version, database names, file names, etc.  
 */
/*
 * Holds Labels
 */
qlabels = 
[
	:url2short = "URL to shorten:",
	:shorturl = "Shortened URL(s):",
	:apikey = "Google URL Shortener API Key:"
]
/*
 * Holds Menu Labels
 */
menu = 
[
	:help = "Help"
]
/*
 * Holds Actions Labels (within menu)
 */
menuaction = 
[ 
	:about = "About"
]
/*
 * Holds application specific 
 */
app = 
[ 
	:version = "0.2r",
	:windowtitle = "Google URL Shortener",
	:windowicon = "link.png",
	:author = "John Storm",
	:authoremail = "siensystem@gmail.com"
]
/*
 * Holds button/tab actions
 */
bactions = 
[
	/*
	 * Button & Tab
	 */
	:shorten = "Shorten URL",
	/*
	 * Buttons
	 */
	:storekey = "Store Key",
	:clear = "Clear History",
	/*
	 * Tabs
	 */
	:settings = "Settings",
	:history = "History"
]
/*
 * Holds events Function Definitions
 */
events = 
[
	:fshortenurl = "fshortenurl()",
	:fabout = "fabout()",
	:fsetapikey = "fsetapikey()",
	:fclearhistory = "fclearhistory()",
	:fentry = "fresponse()",
	:setloaduicontent = "fsetloaduicontent()"
]
/*
 * Holds table headers
 */
tables =
[
	:headershorturl = "Short URL",
	:headerlongurl = "Long URL"
]
/*
 * The Window size
 */
windowscreen = 
[
	:width = 500, 
	:Height = 300
]
/*
 * Google URL shortener API
 */
api = 
[
	:apiurl = "https://www.googleapis.com/urlshortener/v1/url",
	:keyvar = "?key="
]
/*
 * Parameter sent to the URL Shortener API
 */
apirequestparams = 
[
	:longurlrequest = "longUrl"
]
/*
 * A list of file names used 
 */
filenames =
[
	:apikeyxmlfilename = "GoogleAPIKey.xml",
	:historydbfilename = "GoogleAPIHistory.db",
	:settingsfilename = "AppSettings.xml"
]
/*
 *  A list of XML content strings used for the XML write and read
 */
xmlcontent = 
[
	:namespace = app[:windowtitle],
	/*
	 * For API KEY
	 */
	:start = "APIKey",
	:keyelement = "key",
	
	/*
	 * For Globals
	 */
	:version = "1.0",
	/*
	 * For Settings
	 */
	 :settingsstart = "Settings",
	 :settingselement = "loaduihistory"
]
/*
 * Holds our database table names
 */
dbtable =
[
	:history = "History"
]
/*
 *  A list of DB column names
 */
dbcontent = 
[
	:id = "id",
	:shorturlelement = "shorturl",
	:longurlelement = "longurl"
]
/*
 * API call header options
 */
 apiheaders = 
 [
	:headtype = "Content-Type",
	:headlen = "Content-Length",
	:headua = "User-Agent"
 ]
 /*
  * Header types, for now just json
  */
 apiheadertypes = 
 [
	:json = "application/json"
 ]
 /*
  * Regex
  */
 regularexpression =
 [
	/*
	 * Credit: http://www.regexpal.com/94502
	 */
	:urlregex = "^(?:http(s)?:\/\/)?[\w.-]+(?:\.[\w\.-]+)+[\w\-\._~:/?#[\]@!\$&'\(\)\*\+,;=.]+$"
 ]
 /*
  *  Holds Links
  */
 links =
 [
	:googleapikeyurl = "<a href='https://developers.google.com/apis-explorer/#search/URL%20Shortener%20API/'>URL Shortener API @ Google</a>"
 ]
 /*
  * Holds all statusbar messages
  */
 statusbarmessages = 
 [
	:providekey = "Please specify a Google URL Shortener API key.",
	:done = "Task completed successfully.",
	:urlwarning = "LongURL does not seem to match regex rules! continuing...",
	:urlerror = "LongURL bad request; there seems to be unwanted characters in the request string.",
	:stateready = "Ready since " + time() + "."
 ]
 /*
  * Holds Checkboxes
  */
  checkboxes =
  [
  	:loadhistoption = "Load History to Shortened List"
  ]