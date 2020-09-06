class ShieldPower from Power
	func activate player
		player.activeTheShield()
		playPowerSound()
	
	func playPowerSound
		playSound(Sounds[:laser1])
