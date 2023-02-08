load "Ship.ring"
load "PlayerFire.ring"

class PlayerShip from Ship
	fireDamageAmount 	= 12
	oldDamageAmount  	= fireDamageAmount
	powerShotActive  	= False
	powerShieldActive 	= False
 	_powerTimer	 	= 0

	func move
		timer += getFrameTime()
		if powerShotActive or powerShieldActive updatePowerTimer() ok

		if IsKeyDown(KEY_LEFT) and position.x >= 60
			position.x -= speed
		ok

		if IsKeyDown(KEY_RIGHT) and position.x + w + 80 <= screenWidth
			position.x += speed
		ok

		if IsKeyDown(KEY_UP) and position.y - w/2 >= 0
			position.Y -= speed
		ok

		if IsKeyDown(KEY_DOWN) and position.y + w <= screenHeight
			position.Y += speed
		ok

		if IsKeyDown(KEY_SPACE) and timer >= timeBetweenShots
			shot()
		ok

		drawShield()

	func shot
		firePosition = position
		firePosition.x = firePosition.x + w / 2 - 5

		imagePath = ''
		if powerShotActive
			imagePath = "Assets/laserGreen.png"
		else
			imagePath = "Assets/laserBlue.png"
		ok
		

		gameObjects + 
		new PlayerFire(firePosition, imagePath,
		 sounds[:laser1], 0, fireDamageAmount)

		timer = 0

	func initTimer
		timeBetweenShots = 0.15
		timer = timeBetweenShots		

	func incrementHealth amount
		if health + amount >= 100
			health = 100
		else
			health += amount
		ok

	func setFireDamageAmount amount
		powerShotActive = True
		fireDamageAmount = amount

	func returnFireDamageAmount
		fireDamageAmount = oldDamageAmount

	func updatePowerTimer
		_powerTimer += getFrameTime()
		if _powerTimer >= 5
			returnFireDamageAmount()
			powerShotActive = False
			powerShieldActive = False
			_powerTimer = 0
		ok

		if powerShieldActive 
			DrawText("SHIELD: " + ceil(5 - _powerTimer),
 				screenWidth * 0.8, screenHeight * 0.9, 20, GRAY)
		
		elseif powerShotActive		
			DrawText("MEGA SHOT: " + ceil(5 - _powerTimer),
 				screenWidth * 0.8, screenHeight * 0.9, 20, GRAY)
		ok


	func activeTheShield
		powerShieldActive = True
	# Function to draw a shield
	func drawShield
		if powerShieldActive
			image = resources.image("Assets/shield1.png")
			tex = resources.texture(image)
			DrawTexture(tex, position.x - 10, position.y - 10, WHITE)
		ok

