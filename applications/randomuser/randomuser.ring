#===========================#
# Random User Application	 
# 2022, Mahmoud Fayed
#===========================#

load "internetlib.ring"
load "jsonlib.ring"
load "guilib.ring"

openObject(:RandomUser)

class RandomUser from ObjectsParent

	cFirstName cLastName cEmail
	cGender    cImageFile 

	oApp = new QApp {
	
		styleFusionBlack()
	
		win = new QWidget() {

			setWindowTitle("Random User Data")
			setWinIcon(win, "appicon.png")
			resize(400,400)

			oPhotoLabel = new MyLabel(win) 
			oNameLabel = new MyLabel(win) 
			oEmailLabel = new MyLabel(win)
			oGenderLabel = new MyLabel(win)

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
				addWidget(oGenderLabel)
				addWidget(oNewUserDataButton)
				addWidget(oCloseButton)
			}

			this.getUserData()

			setLayout(oLayout)
			show()

		}
		exec()
	}

	func getUserData 
	
		DownloadUserData()		
		DisplayTheData()
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

		oNameLabel.setText("Name: " + cFirstName + " " + cLastName)
		oEmailLabel.setText("Email: " + cEmail)
		oGenderLabel.setText("Gender: " + cGender)

	func DisplayThePhoto

		write("UserPhoto.jpg",download(cImageFile))
	
		oPixmap = new QPixMap("UserPhoto.jpg")
		oPhotoLabel { 
			resize(oPixmap.width(),oPixmap.height())
			setpixmap(oPixmap)
		}

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
