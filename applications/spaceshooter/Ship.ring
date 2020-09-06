class Ship
	position health shipTex w h
	speed 			= 12 
	rotation		= 0
	timeBetweenShots 	= 0.2
	timer 		 	= timeBetweenShots
	collider	
	scale 			= 1
	health			= 100
	type			= 0

	func init type

		this.type = type
		initTimer()

		# Load and set the ship image

		shipImage = loadShipImage()
		if scale = -1
			ImageFlipVertical(shipImage)
		ok
		w = shipImage.width
		h = shipImage.height
		shipTex = LoadTextureFromImage(shipImage)
		UnloadImage(shipImage)
		# Position the ship
		position = new Vector2(screenWidth / 2, screenHeight * 0.8)
	
		collider = new Collider {
			x = this.position.x
			y = this.position.y
			w = this.w
			h = this.h
		}	
			
		return self

	func initTimer	
		timeBetweenShots = 0.2
		timer = timeBetweenShots

	func draw
		move()
		updateCollider()
		loadTex()
		# DrawRectangle(collider.x, collider.y, collider.w,
		# collider.h, GREEN)

	func drawShield
		
	func loadTex
		DrawTextureEx(shipTex, position, rotation, 1, WHITE)
	
	func updateCollider
		collider {
			x = this.position.x	
			y = this.position.y
		}

	func setRotation angle
		rotation = angle

	func setSpeed speed
		this.speed = speed

	func setPosition x, y
		this.position = new Vector2(x, y)

	func setTimeBetweenShots time
		this.timeBetweenShots = time
	
	func checkHealth
		if health <= 0 return True ok
		return False


	func loadShipImage
		switch type
			on 0 return LoadImage("Assets/Ship1.png")
			on 1 return LoadImage("Assets/enemyGreen.png")
			on 2 return LoadImage("Assets/enemyRed.png")
			on 3 return LoadImage("Assets/enemyBlue.png")
			on 4 return LoadImage("Assets/enemyBlack.png")
		end

