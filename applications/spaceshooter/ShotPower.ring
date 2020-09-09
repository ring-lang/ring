class ShotPower from Power
	# Function to triger the mega shot
	func activate player
		player.setFireDamageAmount(20)
		playPowerSound()

	func playPowerSound
		playSound(Sounds[:laser1])
