? copy("=",50)
inputStr = ["", "   ", "2", "333", ".55", "tttTTT", "4444 444k", "nice", "66666"]
for t = 1 to len(inputStr)
	word = inputStr[t]
	for x = 1 to len(word)
		for y = x+1 to len(word)
			if word[x] != word[y]
				char = word[y]
				? "Input = "+"'"+word+"'"+", length = "+len(word)
				? " First difference at position "+y+", character = "+"'"+char+"'"
				for z in 1:10
					for k = 1 to 10
						exit 5
					next 
				next 
			ok 
		next 
	next 
	? "Input = "+"'"+word+"'"+", length = "+len(word)
	? "  All characters are the same."
next 
? "end of part 1"
? copy("=",50)

for t = 1 to len(inputStr)
	word = inputStr[t]
	for x = 1 to len(word)
		for y = x+1 to len(word)
			if word[x] != word[y]
				char = word[y]
				? "Input = "+"'"+word+"'"+", length = "+len(word)
				? " First difference at position "+y+", character = "+"'"+char+"'"
				for z in 1:10
					for k = 1 to 10
						loop 5
					next 
				next 
			ok 
		next 
	next 
	? "Input = "+"'"+word+"'"+", length = "+len(word)
	? "  All characters are the same."
next 
? "end of part 2"
? copy("=",50)
