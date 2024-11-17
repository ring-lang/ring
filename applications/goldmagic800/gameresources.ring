# Gold Magic 800 3D Game
# 2018, Etqan Company
# 2018, Mahmoud Fayed <msfclipper@yahoo.com>

class GameResources

	func loadresources

		fontArial26 	= al_load_ttf_font("font/arial.ttf",26,0 )
		CheckFatalError(fontArial26,"Can't load the font file font/arial.ttf - Font Size : 26 ")

		fontArial72 	= al_load_ttf_font("font/arial.ttf",72,0 )
		CheckFatalError(fontArial72,"Can't load the font file font/arial.ttf - Font Size : 72 ")

		fontArial172 	= al_load_ttf_font("font/arial.ttf",172,0 )
		CheckFatalError(fontArial172,"Can't load the font file font/arial.ttf - Font Size : 172 ")

		bitmap 	= al_load_bitmap("images/playback.jpg")
		CheckFatalError(bitmap,"Can't load the image file images/playback.jpg")
		texture = al_get_opengl_texture(bitmap)

		bitmapWinBackground 	= al_load_bitmap("images/winback.jpg")
		CheckFatalError(bitmapWinBackground,"Can't load the image file images/winback.jpg")
		textureWinBackground = al_get_opengl_texture(bitmapWinbackGround)

		bitmapMainMenu	= al_load_bitmap("images/mainmenu.jpg")
		CheckFatalError(bitmapMainMenu,"Can't load the image file images/mainmenu.jpg")
		textureMainMenu = al_get_opengl_texture(bitmapMainMenu)

		bitmapLogo	= al_load_bitmap("images/logo.jpg")
		CheckFatalError(bitmapLogo,"Can't load the image file images/logo.jpg")

		bitmapStoryBackGround	= al_load_bitmap("images/storyback.jpg")
		CheckFatalError(bitmapStoryBackGround,"Can't load the image file images/storyback.jpg")

		bitmapStoryBackGround2	= al_load_bitmap("images/storyback2.jpg")
		CheckFatalError(bitmapStoryBackGround2,"Can't load the image file images/storyback2.jpg")

		bitmapStoryBackGround3	= al_load_bitmap("images/storyback3.jpg")
		CheckFatalError(bitmapStoryBackGround3,"Can't load the image file images/storyback3.jpg")


		bitmapManyGold	= al_load_bitmap("images/manygold.jpg")
		CheckFatalError(bitmapManyGold,"Can't load the image file images/manygold.jpg")

		bitmapTheBox	= al_load_bitmap("images/thebox.jpg")
		CheckFatalError(bitmapTheBox,"Can't load the image file images/thebox.jpg")

		bitmapGameEnv	= al_load_bitmap("images/gameenv.jpg")
		CheckFatalError(bitmapGameEnv,"Can't load the image file images/gameenv.jpg")


		bitmapRemoteControl	= al_load_bitmap("images/remotecontrol.jpg")
		CheckFatalError(bitmapRemoteControl,"Can't load the image file images/remotecontrol.jpg")

		bitmapGameTitle	= al_load_bitmap("images/gametitle.jpg")
		CheckFatalError(bitmapGameTitle,"Can't load the image file images/gametitle.jpg")

		bitmapHowToPlay	= al_load_bitmap("images/howtoplay.jpg")
		CheckFatalError(bitmapHowToPlay,"Can't load the image file images/howtoplay.jpg")


		bitmapGround1 = al_load_bitmap("images/ground1.jpg")
		CheckFatalError(bitmapGround1,"Can't load the image file images/ground1.jpg")
		textureGround1 = al_get_opengl_texture(bitmapGround1)

		bitmapWall2 = al_load_bitmap("images/wall2.jpg")
		CheckFatalError(bitmapWall2,"Can't load the image file images/wall2.jpg")
		textureWall2 = al_get_opengl_texture(bitmapWall2)

		bitmapPlayer = al_load_bitmap("images/player.jpg")
		CheckFatalError(bitmapPlayer,"Can't load the image file images/player.jpg")
		texturePlayer = al_get_opengl_texture(bitmapPlayer)

		bitmapWall4 = al_load_bitmap("images/wall4.jpg")
		CheckFatalError(bitmapWall4,"Can't load the image file images/wall4.jpg")
		textureWall4 = al_get_opengl_texture(bitmapWall4)

		bitmapGround2 = al_load_bitmap("images/ground2.jpg")
		CheckFatalError(bitmapGround2,"Can't load the image file images/ground2.jpg")
		textureGround2 = al_get_opengl_texture(bitmapGround2)

		bitmapWall3 = al_load_bitmap("images/wall3.jpg")
		CheckFatalError(bitmapWall3,"Can't load the image file images/wall3.jpg")
		textureWall3 = al_get_opengl_texture(bitmapWall3)

		bitmapGround3 = al_load_bitmap("images/ground3.jpg")
		CheckFatalError(bitmapGround3,"Can't load the image file images/ground3.jpg")
		textureGround3 = al_get_opengl_texture(bitmapGround3)

		bitmapWall1 = al_load_bitmap("images/wall1.jpg")
		CheckFatalError(bitmapWall1,"Can't load the image file images/wall1.jpg")
		textureWall1 = al_get_opengl_texture(bitmapWall1)

		bitmapGold = al_load_bitmap("images/gold.jpg")
		CheckFatalError(bitmapGold,"Can't load the image file images/gold.jpg")
		textureGold = al_get_opengl_texture(bitmapGold)

		bitmapn1 = al_load_bitmap("images/n1.jpg")
		CheckFatalError(bitmapn1,"Can't load the image file images/n1.jpg")
		texturen1 = al_get_opengl_texture(bitmapn1)
		bitmapn2 = al_load_bitmap("images/n2.jpg")
		CheckFatalError(bitmapn2,"Can't load the image file images/n2.jpg")
		texturen2 = al_get_opengl_texture(bitmapn2)
		bitmapn3 = al_load_bitmap("images/n3.jpg")
		CheckFatalError(bitmapn3,"Can't load the image file images/n3.jpg")
		texturen3 = al_get_opengl_texture(bitmapn3)
		bitmapn4 = al_load_bitmap("images/n4.jpg")
		CheckFatalError(bitmapn4,"Can't load the image file images/n4.jpg")
		texturen4 = al_get_opengl_texture(bitmapn4)
		bitmapn5 = al_load_bitmap("images/n5.jpg")
		CheckFatalError(bitmapn5,"Can't load the image file images/n5.jpg")
		texturen5 = al_get_opengl_texture(bitmapn5)
		bitmapn6 = al_load_bitmap("images/n6.jpg")
		CheckFatalError(bitmapn6,"Can't load the image file images/n6.jpg")
		texturen6 = al_get_opengl_texture(bitmapn6)
		bitmapn7 = al_load_bitmap("images/n7.jpg")
		CheckFatalError(bitmapn7,"Can't load the image file images/n7.jpg")
		texturen7 = al_get_opengl_texture(bitmapn7)
		bitmapn8 = al_load_bitmap("images/n8.jpg")
		CheckFatalError(bitmapn8,"Can't load the image file images/n8.jpg")
		texturen8 = al_get_opengl_texture(bitmapn8)
		bitmapn9 = al_load_bitmap("images/n9.jpg")
		CheckFatalError(bitmapn9,"Can't load the image file images/n9.jpg")
		texturen9 = al_get_opengl_texture(bitmapn9)
		bitmapn10 = al_load_bitmap("images/n10.jpg")
		CheckFatalError(bitmapn10,"Can't load the image file images/n10.jpg")
		texturen10 = al_get_opengl_texture(bitmapn10)
		bitmapn11 = al_load_bitmap("images/n11.jpg")
		CheckFatalError(bitmapn11,"Can't load the image file images/n11.jpg")
		texturen11 = al_get_opengl_texture(bitmapn11)
		bitmapn12 = al_load_bitmap("images/n12.jpg")
		CheckFatalError(bitmapn12,"Can't load the image file images/n12.jpg")
		texturen12 = al_get_opengl_texture(bitmapn12)
		bitmapn13 = al_load_bitmap("images/n13.jpg")
		CheckFatalError(bitmapn13,"Can't load the image file images/n13.jpg")
		texturen13 = al_get_opengl_texture(bitmapn13)
		bitmapn14 = al_load_bitmap("images/n14.jpg")
		CheckFatalError(bitmapn14,"Can't load the image file images/n14.jpg")
		texturen14 = al_get_opengl_texture(bitmapn14)
		bitmapn15 = al_load_bitmap("images/n15.jpg")
		CheckFatalError(bitmapn15,"Can't load the image file images/n15.jpg")
		texturen15 = al_get_opengl_texture(bitmapn15)
		bitmapn16 = al_load_bitmap("images/n16.jpg")
		CheckFatalError(bitmapn16,"Can't load the image file images/n16.jpg")
		texturen16 = al_get_opengl_texture(bitmapn16)


		bitmapnewWall = al_load_bitmap("images/newwall.jpg")
		CheckFatalError(bitmapnewWall,"Can't load the image file images/newwall.jpg")
		texturenewWall = al_get_opengl_texture(bitmapnewWall)

		PlayerTexture		= texturePlayer
		GroundTexture   	= textureGround1
		WallTexture		= textureWall2
		GoldGroundTexture 	= textureGold
		DoorTexture 		= texturen1
		Door2Texture		= texturen2
		Door3Texture		= texturen3
		Door4Texture		= texturen4
		Door5Texture		= texturen5
		Door6Texture		= texturen6
		Door7Texture		= texturen7
		Door8Texture		= texturen8
		Door9Texture		= texturen9
		Door10Texture		= texturen10
		Door11Texture		= texturen11
		Door12Texture		= texturen12
		Door13Texture		= texturen13
		Door14Texture		= texturen14
		Door15Texture		= texturen15
		Door16Texture		= texturen16

	func destroyResources

		Super.DestroyResources()
		oGameSound.Destroy()

		al_destroy_font(fontArial26)
		al_destroy_font(fontArial172)
		al_destroy_font(fontArial72)

		al_destroy_bitmap(bitmap)
		al_destroy_bitmap(bitmapGround1)
		al_destroy_bitmap(bitmapWall2)
		al_destroy_bitmap(bitmapPlayer)
		al_destroy_bitmap(bitmapWall4)
		al_destroy_bitmap(bitmapGround2)
		al_destroy_bitmap(bitmapWall3)
		al_destroy_bitmap(bitmapGround3)

		al_destroy_bitmap(bitmapWall1)

		al_destroy_bitmap(bitmapGold)

		al_destroy_bitmap(bitmapn1)
		al_destroy_bitmap(bitmapn2)
		al_destroy_bitmap(bitmapn3)
		al_destroy_bitmap(bitmapn4)
		al_destroy_bitmap(bitmapn5)
		al_destroy_bitmap(bitmapn6)
		al_destroy_bitmap(bitmapn7)
		al_destroy_bitmap(bitmapn8)
		al_destroy_bitmap(bitmapn9)
		al_destroy_bitmap(bitmapn10)
		al_destroy_bitmap(bitmapn11)
		al_destroy_bitmap(bitmapn12)
		al_destroy_bitmap(bitmapn13)
		al_destroy_bitmap(bitmapn14)
		al_destroy_bitmap(bitmapn15)
		al_destroy_bitmap(bitmapn16)

		al_destroy_bitmap(bitmapNewWall)

		al_destroy_bitmap(bitmapLogo)
		al_destroy_bitmap(bitmapStoryBackGround)
		al_destroy_bitmap(bitmapStoryBackGround2)
		al_destroy_bitmap(bitmapStoryBackGround3)
		al_destroy_bitmap(bitmapManyGold)
		al_destroy_bitmap(bitmapGameEnv)
		al_destroy_bitmap(bitmapTheBox)
		al_destroy_bitmap(bitmapRemoteControl)

		al_destroy_bitmap(bitmapGameTitle)
		al_destroy_bitmap(bitmapHowToPlay)
