class Collider
	x y w h
	# Function to check if a point intersect with a rectangle
	func intersectWithPoint x, y
		if x >= this.x and x <= (this.x + w) and y >= this.y and y <= (this.y + h)
			return True
		ok
		return False
