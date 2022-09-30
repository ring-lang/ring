#=====================================#
# Random User Application	
# Version for the Console (Colors)
# 2022, Mahmoud Fayed
#=====================================#

load "internetlib.ring"
load "jsonlib.ring"
load "consolecolors.ring"

C_FILENAME = "UserPhoto.jpg"

cData= download("https://randomuser.me/api")
	
aList= JSON2List(cData)
		
cFirstName = aList[:Results][1][:name][:first]
cLastName  = aList[:Results][1][:name][:last]
cEmail     = aList[:Results][1][:email]
cGender    = aList[:Results][1][:gender]
cImageFile = aList[:Results][1][:picture][:large]

write(C_FILENAME,download(cImageFile))

cc_print( CC_FG_BLACK|CC_BG_CYAN, "Name  : ") 
cc_print( CC_FG_WHITE|CC_BG_BLUE, " " + cFirstName + " " + cLastName + " " + nl)
cc_print( CC_FG_BLACK|CC_BG_CYAN, "Email : ") 
cc_print( CC_FG_WHITE|CC_BG_BLUE, " " + cEmail + " " + nl)
cc_print( CC_FG_BLACK|CC_BG_CYAN, "Gender: ") 
cc_print( CC_FG_WHITE|CC_BG_BLUE, " " + cGender + " " + nl)

system(C_FILENAME)
	
