class ShotPower from Power
	func activate player
		player.setFireDamageAmount(20)
		playPowerSound()

	func playPowerSound
		playSound(Sounds[:laser1])
