load "EnemyFire.ring"

class EnemyShip from Ship
	deathTimer 	= 1
	speed 		= 5
	type		= 0
	damageAmount	= 2

	func move
		position.y += speed
		drawHealth()
		timer += getFrameTime()
		shot()
		if checkOutSide()
			deathTimer  -= getFrameTime()
		ok
	func shot
		if timer >= timeBetweenShots
			timer = 0
			firePosition = position
			firePosition.x = firePosition.x + w / 2 + 5
			firePosition.y = firePosition.y + h / 2
			gameObjects + new EnemyFire(firePosition,
		 "Assets/laserRed.png", sounds[:laser2], type, damageAmount){
				speed = -speed
				timeBetweenShots = 2
				rotation = 180
			}			
		ok
	# Function to check if the enemy ship is outside the screen
	func checkOutSide
		if position.y > screenHeight return True ok
		return False

	func tryToDestroy
		if deathTimer <= 0
			return True
		ok
		return False

	func drawHealth
		DrawText("" + health, position.x + w + 10, position.y - 10, 20, GRAY)		

	
				




