#===========================#
# Random User Application	 
# Version using Classes
# 2022, Mahmoud Fayed
#===========================#

load "internetlib.ring"
load "jsonlib.ring"
load "lightguilib.ring"

oApp = new QApp {
	styleFusionBlack()
	openObject(:RandomUser)
	exec()
}

class RandomUser from ObjectsParent

	cFirstName cLastName cEmail
	cGender    cImageFile 

	win = new QWidget() {

		setWindowTitle("Random User Data")
		setWinIcon(win, "images/appicon.png")
		resize(400,370)

		oPhotoLabel = new MyLabel(win) 
		oNameLabel = new MyLabel(win) 
		oEmailLabel = new MyLabel(win)

		oNewUserDataButton = new MyButton(win) {
			setText("New User Data")
			setClickEvent(Method(:GetUserData))
		}
		oCloseButton = new MyButton(win) {
			setText("Close Application")
			setClickEvent(Method(:CloseApplication))
		}

		oLayout = new QVBoxLayout() {
			addWidget(oPhotoLabel)
			addWidget(oNameLabel)
			addWidget(oEmailLabel)
			addWidget(oNewUserDataButton)
			addWidget(oCloseButton)
		}

		this.getUserData()

		setLayout(oLayout)
		show()

	}

	func getUserData 
	
		DownloadUserData()		
		DisplayTheData()
		StyleBasedOnGender()
		DisplayThePhoto()

	func DownloadUserData

		cData= download("https://randomuser.me/api")
	
		aList= JSON2List(cData)
		
		cFirstName = aList[:Results][1][:name][:first]
		cLastName  = aList[:Results][1][:name][:last]
		cEmail     = aList[:Results][1][:email]
		cGender    = aList[:Results][1][:gender]
		cImageFile = aList[:Results][1][:picture][:large]

	func DisplayTheData

		oNameLabel.setText(cFirstName + " " + cLastName)
		oEmailLabel.setText("Email: " + cEmail)

	func DisplayThePhoto

		write("UserPhoto.jpg",download(cImageFile))
	
		oPixmap = new QPixMap("UserPhoto.jpg")
		oPhotoLabel { 
			resize(oPixmap.width(),oPixmap.height())
			setpixmap(oPixmap)
		}

	func StyleBasedOnGender

		cBackColor = "" 
		if cGender = "female" cBackColor = "purple" ok
		win.setStylesheet("background-color: " + cBackColor)

	func CloseApplication 

		oApp.Quit()

class MyLabel from QLabel 

	func init oParent

		Super.init(oParent)

		setAlignment(Qt_AlignHCenter | Qt_AlignVCenter)
		setStyleSheet("font-size: 14pt;")

		return self

class MyButton from QPushButton

	func init oParent

		Super.init(oParent)

		setStyleSheet("font-size: 12pt;")
		setMinimumHeight(50)

		return self
