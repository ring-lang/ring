load "internetlib.ring"

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
