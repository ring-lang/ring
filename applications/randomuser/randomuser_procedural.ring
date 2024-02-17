#========================================#
# Random User Application
# Version using Procedural Programming	 
# 2022, Mahmoud Fayed
#========================================#

load "internetlib.ring"
load "jsonlib.ring"
load "lightguilib.ring"

cFirstName = ""
cLastName  = ""
cEmail     = ""
cGender    = ""
cImageFile = ""

oApp = new QApp {

	styleFusionBlack()

	win = new QWidget() {

		setWindowTitle("Random User Data")
		setWinIcon(win, "images/appicon.png")
		resize(400,370)

		oPhotoLabel = new QLabel(win) { setLabelStyle(self) }
		oNameLabel = new QLabel(win)  { setLabelStyle(self) }
		oEmailLabel = new QLabel(win) { setLabelStyle(self) }

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
			addWidget(oPhotoLabel)
			addWidget(oNameLabel)
			addWidget(oEmailLabel)
			addWidget(oNewUserDataButton)
			addWidget(oCloseButton)
		}

		setLayout(oLayout)
		show()

	}

	GetUserData()

	exec()
}

func GetUserData

	cData= download("https://randomuser.me/api")
	
	aList= JSON2List(cData)
		
	cFirstName = aList[:Results][1][:name][:first]
	cLastName  = aList[:Results][1][:name][:last]
	cEmail     = aList[:Results][1][:email]
	cGender    = aList[:Results][1][:gender]
	cImageFile = aList[:Results][1][:picture][:large]

	oNameLabel.setText(cFirstName + " " + cLastName)
	oEmailLabel.setText("Email: " + cEmail)

	write("UserPhoto.jpg",download(cImageFile))
	
	oPixmap = new QPixMap("UserPhoto.jpg")
	oPhotoLabel { 
		resize(oPixmap.width(),oPixmap.height())
		setpixmap(oPixmap)
	}

	cBackColor = "" 
	if cGender = "female" cBackColor = "purple" ok
	win.setStylesheet("background-color: " + cBackColor)

func CloseApplication 

	oApp.Quit()


func setLabelStyle oLabel
	oLabel {
		setAlignment(Qt_AlignHCenter | Qt_AlignVCenter)
		setStyleSheet("font-size: 14pt;")
	}

func setButtonStyle oButton
	oButton {
		setStyleSheet("font-size: 12pt;")
		setMinimumHeight(50)
	}

