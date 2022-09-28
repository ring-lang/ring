#===========================#
# Random User Application	 
# 2022, Mahmoud Fayed
#===========================#

load "internetlib.ring"
load "jsonlib.ring"
load "guilib.ring"

new RandomUser

class RandomUser

	cFirstName cLastName cEmail
	cGender    cImageFile 

	oApp = new QApp {
	
		styleFusionBlack()
	
		win = new QWidget() {

			setWindowTitle("Random User Data")
			resize(600,600)

			oPhotoLabel = new QLabel(win) {
				move(100,100)
			}

			oNameLabel = new QLabel(win) { move(100,300) }
			oEmailLabel = new QLabel(win) { move(100,330) }
			oGenderLabel = new QLabel(win) { move(100,360) }

			this.getUserData()
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

