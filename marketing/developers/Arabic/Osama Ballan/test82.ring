/*
**	Application	: Ring lessons - Download() - Sendemail() .
**	Author		: Osama Ballan .
**	Date			: 2018 - 01 - 13 .
*/
load "internetlib.ring"

cStr= download("http://doublesvsoop.sourceforge.net/")
see cStr
write("download.txt",cStr)
# *******************
See "Send email..." + nl
sendemail("smtp://smtp.gmail.com:587",
        "email@gmail.com",
        "password",
        "email@gmail.com",
        "somebody@yahoo.com",
        "somebodyelse@yahoo.com",
        "Sending email from Ring",
        "Hello
         How are you?
         Are you fine?
         Thank you!
         Greetings,
         Mahmoud")
see "Done.." + nl












