see "Hello, World!"

func ringvm_see cText
	ring_see("I can play with the string before displaying it" + nl)
	ring_see("I can convert it :D" + nl)	
	ring_see("Original Text: " + cText + nl)
	if cText = "Hello, World!"
		# Convert it from English to Hindi
		cText = "नमस्ते दुनिया!"
	ok
	ring_see("Converted To (Hindi): " + cText + nl)
