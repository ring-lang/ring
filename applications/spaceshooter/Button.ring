class Button
	position collider imageTex imageTex2 text = "Button" w = 200 h = 40
	cFunction
	func init file1, file2
		image = resources.Image(file1)
		ImageResize(image, image.width * 2, image.height * 2)
		imageTex = resources.texture(image)
		image2 = resources.image(file2)
		ImageResize(image2, image2.width * 2, image2.height * 2)
		imageTex2 = resources.texture(image2)

		w = image.width
		h = image.height
		
		position = new Vector2(50, 50)
		collider = new Collider {
			x = this.position.x
			y = this.position.y
			w = this.w
			h = this.h	
		}
		return self

	func draw parent
		if not checkMouseHover()
			DrawTexture(imageTex, position.x, position.y, WHITE)
		else
			DrawTexture(imageTex2, position.x, position.y, WHITE)
		ok		
		DrawText(text, position.x + w * 0.40, position.y + h * 0.3, 32, RED)
		
		updateCollider()
		checkMouseClick(parent)
		
	func checkMouseClick parent

		if IsMouseButtonPressed(MOUSE_LEFT_BUTTON)
			pos = getMousePosition()
			if collider.intersectWithPoint(pos.x, pos.y)			
				eval("parent." + cFunction + "()")
			ok
		ok
	func checkMouseHover
		pos = getMousePosition()
		return collider.intersectWithPoint(pos.x, pos.y)

	func updateCollider
		collider {
			x = this.position.x
			y = this.position.y
			w = this.w
			h = this.h	
		}
