Load "gamelib.ring"
Load "gameengine.ring"

oResources = new Resources

Func Main
	New Game 
	{
		Image 
		{
			LoadFile("images\back3.jpg")
			x = 0
			y = 0
			nPoint = -370
			nDirection = 2
		}
		Image 
		{
			LoadFile("images\back5.jpg")
			x = 400 y =400 width=100 height=100
			lAnimate=false lMove=True lScaled=True
		}
		for g = 1 to 100
			Image 
			{
				LoadFile("images\back3.jpg")
				x = g y =g width=100 height=100
				lAnimate=true lScaled=True
				nDirection = 3	nStep=1
			}
		next
	}
