load "Power.ring"

class HealthPower from Power
	# Function to increase player health
	func activate player
		player.incrementHealth(powerAmount)
		playPowerSound()
		
	func playPowerSound
		playSound(Sounds[:laser1])
