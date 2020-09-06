class Collider
	x y w h

	func intersectWithPoint x, y
		if x >= this.x and x <= (this.x + w) and y >= this.y and y <= (this.y + h)
			return True
		ok
		return False
