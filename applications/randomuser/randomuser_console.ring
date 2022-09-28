#=====================================#
# Random User Application	
# Another version for the Console 
# 2022, Mahmoud Fayed
#=====================================#

load "internetlib.ring"
load "jsonlib.ring"

cData= download("https://randomuser.me/api")
	
aList= JSON2List(cData)
		
cFirstName = aList[:Results][1][:name][:first]
cLastName  = aList[:Results][1][:name][:last]
cEmail     = aList[:Results][1][:email]
cGender    = aList[:Results][1][:gender]
cImageFile = aList[:Results][1][:picture][:large]

write("UserPhoto.jpg",download(cImageFile))

? "Name  : " + cFirstName + " " + cLastName
? "Email : " + cEmail
? "Gender: " + cGender

system("UserPhoto.jpg")
	
