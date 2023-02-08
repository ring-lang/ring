# Power 1 - Health
# Power 2 - Fire
# Power 3 - Shield

class Power
	position type powerAmount deathTimer = 0 imageTex collider w h

	func init powerAmount, type, pos
		this.type = type
		this.powerAmount = powerAmount

		setPowerImage()

		position = pos

		collider = new Collider {
			x = this.position.x
			y = this.position.y
			w = this.w
			h = this.h
		}

		return self

	func draw
		DrawTexture(imageTex, position.x, position.y, WHITE)
		deathTimer += getFrameTime()
	# Function to destroy the power after time amount
	func tryToDestroy
		if deathTimer >= 5 return True ok
		return False

	func activate
	# Function to set power image using a type
	func setPowerImage
		path = ""
		switch type
			on 1 path = "Assets/pill_blue.png"
			on 2 path = "Assets/bold_silver.png"
			on 3 path = "Assets/shield_silver.png"
		off
		image = resources.image(path)
		ImageResize(image, image.width * 1.5, image.height * 1.5)
		w = image.width * 2
		h = image.height * 2
		imageTex = resources.texture(image)
