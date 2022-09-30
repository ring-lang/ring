#========================================#
# Random User Application
# Version using QtWebEngineView 
# 2022, Mahmoud Fayed
#========================================#

load "internetlib.ring"
load "jsonlib.ring"
load "guilib.ring"

# Global Variables 
	cFirstName = ""
	cLastName  = ""
	cEmail     = ""
	cGender    = ""
	cImageFile = ""
	
# Constants 
	C_TEMPLATEFILE = "template/qtwebview_template.html"
	C_INDEXFILE    = "template/index.html"
	C_INDEXFILEURL = "file:///"+substr(currentdir(),"\","/")+"/template/index.html"

oApp = new QApp {

	styleFusion()

	win = new QWidget() {

		setWindowTitle("Random User Data - Using QtWeb")
		setWinIcon(win, "images/appicon.png")
		setStyleSheet("background-color: White")
		resize(500,400)

		oWebView = new QWebView(win) 

		oNewUserDataButton = new QPushButton(win) {
			setButtonStyle(self)
			setText("New User Data")
			setClickEvent("GetUserData()")
		}
		oCloseButton = new QPushButton(win) {
			setButtonStyle(self)
			setText("Close Application")
			setClickEvent("CloseApplication()")
		}

		oLayout = new QVBoxLayout() {
			addWidget(oWebView)
			addWidget(oNewUserDataButton)
			addWidget(oCloseButton)
		}

		setLayout(oLayout)
		show()

	}

	GetUserData()

	exec()
}

func setButtonStyle oButton

	oButton {
		setStyleSheet("font-size: 12pt;")
		setMinimumHeight(50)
	}

func GetUserData

	cData= download("https://randomuser.me/api")
	
	aList= JSON2List(cData)
		
	cFirstName = aList[:Results][1][:name][:first]
	cLastName  = aList[:Results][1][:name][:last]
	cEmail     = aList[:Results][1][:email]
	cGender    = aList[:Results][1][:gender]
	cImageFile = aList[:Results][1][:picture][:large]

	write("template/UserPhoto.jpg",download(cImageFile))

	cHTML = read(C_TEMPLATEFILE)
	cHTML = substr(cHTML,"{{UserName}}",cFirstName + " " + cLastName)
	cHTML = substr(cHTML,"{{Email}}",cEmail)
	cHTML = substr(cHTML,"{{Gender}}",cGender)
	write(C_INDEXFILE, cHTML)
	
	oWebView.loadpage(new qurl(C_INDEXFILEURL))

func CloseApplication 

	win.close()
	oApp.Quit()
