# Gold Magic 800 3D Game
# 2018, Etqan Company

func ShowErrorMessage cText 

	al_show_native_message_box(NULL,"Gold Magic 800","Error",cText,NULL,ALLEGRO_MESSAGEBOX_ERROR)

func CheckFatalError oPointer,cMessage

	if  ISNULL(oPointer)
		ShowErrorMessage(cMessage)
		al_exit()
	ok



