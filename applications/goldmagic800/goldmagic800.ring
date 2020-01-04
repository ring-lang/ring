# Gold Magic 800 3D Game
# 2018, Etqan Company
# 2018, Mahmoud Fayed <msfclipper@yahoo.com>

# Load Libraries

	load "stdlibcore.ring"
	load "gamelib.ring"
	load "opengl21lib.ring"

# Load Files 
	load "gamefiles.ring"

#==============================================================
# To Support MacOS X
	al_run_main()	
	# Called by al_run_main()
	func al_game_start
		# Now we call our main function
			main()		
#==============================================================

func main
	new GameEngine {
		Run()
	}
 
