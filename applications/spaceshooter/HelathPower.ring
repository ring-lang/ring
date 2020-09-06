load "Power.ring"

class HealthPower from Power

	func activate player
		player.incrementHealth(powerAmount)
		playPowerSound()
		
	func playPowerSound
		playSound(Sounds[:laser1])
