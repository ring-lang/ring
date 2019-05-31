load "gameengine.ring"        	

func main          		

	oGame = New Game      	
	{

		title = "Sokoban"

		Map {

			blockwidth  = 60
			blockheight = 60

			aMap = [
				[1,1,1,2,2,2,2,2,1,1,1,1,1,1],
				[1,2,2,2,1,1,1,2,1,1,1,1,1,1],
				[1,2,4,3,5,1,1,2,1,1,1,1,1,1],
				[1,2,2,2,1,5,4,2,1,1,1,1,1,1],
				[1,2,4,2,2,5,1,2,1,1,1,1,1,1],
				[1,2,1,2,1,4,1,2,2,1,1,1,1,1],
				[1,2,5,1,6,5,5,4,2,1,1,1,1,1],
				[1,2,1,1,1,4,1,1,2,1,1,1,1,1],
				[1,2,2,2,2,2,2,2,2,1,1,1,1,1],
				[1,1,1,1,1,1,1,1,1,1,1,1,1,1]
			]
	
			aImages = [
				"images/empty.jpg",
				"images/wall.jpg",
				"images/player.jpg",
				"images/door.jpg",
				"images/box.jpg",
				"images/boxondoor.jpg"
			]
		}
	}         

