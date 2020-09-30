class ShieldPower from Power
	# Function to triger the shield shot
	func activate player
		player.activeTheShield()
		playPowerSound()
	
	func playPowerSound
		playSound(Sounds[:laser1])
