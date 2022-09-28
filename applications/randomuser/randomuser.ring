#===========================#
# Random User Application	 
# 2022, Mahmoud Fayed
#===========================#

load "internetlib.ring"
load "jsonlib.ring"
load "guilib.ring"

getUserData()

new QApp {

	styleFusionBlack()

	oPixmap = new QPixMap("UserPhoto.jpg")

	w = new QWidget(){
		setWindowTitle("Random User Data")
		resize(600,600)
		new QLabel(w) {
			move(100,100)
			resize(oPixmap.width(),oPixmap.height())
			setpixmap(oPixmap)
		}
		show()
	}

	exec()
}


func getUserData 

	cData= download("https://randomuser.me/api")

	aList= JSON2List(cData)
	
	cFirstName = aList[:Results][1][:name][:first]
	cLastName  = aList[:Results][1][:name][:last]
	cEmail     = aList[:Results][1][:email]
	cGender    = aList[:Results][1][:gender]
	cImageFile = aList[:Results][1][:picture][:large]
	
	write("UserPhoto.jpg",download(cImageFile))
