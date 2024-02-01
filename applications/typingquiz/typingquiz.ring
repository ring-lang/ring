# Typing Quiz Game using raylib
# Author: Ahmad Zakaria (zaka7024@gmail.com)
# Date: 8/2020

Load "stdlibcore.ring"
Load "raylib.ring"

screenWidth  = 800
screenHeight = 400

func main

InitWindow(screenWidth, screenHeight, "Typing Quiz")
windowIcon = LoadImage("icon.png")
SetWindowIcon(windowIcon)
SetTargetFPS(60)

# quiz characters
chars = [['j', 'f'], ['c', 'k'], ['d', 'k'], ['e', 'o']]

# select quiz chars
k = random(len(chars) - 1) + 1
CHAR_ONE = chars[k][1]
CHAR_TWO = chars[k][2]

sentenceLength = random(20) + 20

# generate quiz text
text = generateString(sentenceLength, chars[k])

# game variables
textSize = 0
if len(text) >= 30 textSize = 25 else textSize = 35 ok
letters 		= ""
started 		= False
lastKey 		= 0
error 			= 0
errorMap		= []
currentCharIndex 	= 1
timer 			= 0
errorMap		= []
keys 			= [:j = KEY_J, :f = KEY_F, :c = KEY_C, :e = KEY_E, :o = KEY_O,
	 			:k = KEY_K, :d = KEY_D]

CHAR_ONE_KEY = keys[CHAR_ONE]
CHAR_TWO_KEY = keys[CHAR_TWO]

# Main game loop
while !WindowShouldClose()
	BeginDrawing()
	
	# Game UI
	if started
		timer += GetFrameTime()
	ok

	DrawText("Type this sentence with out looking at your keyboard", 10, 10, 26, RED)
	DrawText("TIME: " + timer, 500, 50, 26, RED)
	DrawText("SENTENCE:", 10, 50, 26, RED)
	DrawText("ERRORS: " + error, 300, 45, 26, RED)
	DrawText("Press R To Restart", 280, 300, 25, BLUE)
	DrawText(text, 10, 100, textSize, RED)

	# Check if the user click the sentence characters
	if IsKeyReleased(CHAR_ONE_KEY)
		letters = letters + CHAR_ONE
		lastKey = CHAR_ONE_KEY
	elseif IsKeyReleased(CHAR_TWO_KEY)
		letters = letters + CHAR_TWO
		lastKey = CHAR_TWO_KEY
	elseif IsKeyReleased(KEY_SPACE)
		letters = letters + " " 
		lastKey = KEY_SPACE
	elseif IsKeyDown(KEY_BACKSPACE)
		letters = left(letters, len(letters) - 1)

		if currentCharIndex > 1
			currentCharIndex--
		ok
		
		for i = len(errorMap) to 1 step -1
			if errorMap[i] > len(letters)
					error--
					del(errorMap, i)
			ok
		next
		sleep(0.1)
	ok
	# Restart the game
	if IsKeyReleased(KEY_R)
		# load game variables
		k = random(len(chars) - 1) + 1
		CHAR_ONE = chars[k][1]
		CHAR_TWO = chars[k][2]
		CHAR_ONE_KEY = keys[CHAR_ONE]
		CHAR_TWO_KEY = keys[CHAR_TWO]
		sentenceLength = 40
		text = generateString(sentenceLength, chars[K])
		letters = ""
		started = False
		lastKey = 0
		error = 0
		currentCharIndex = 1
		timer = 0
		if len(text) >= 30 textSize = 25 else textSize = 35 ok
	ok
	
	# Check if the user click at least one key
	if lastKey != 0
		started = true
	ok
	
	# Checking for error mechanism
	if len(letters) > 0 and len(letters) <= len(text)
		if lastKey != 0 and lower(char(lastKey)) != nextChar
			error++
			errorMap + len(letters)
		ok
	
		if lastKey != 0
			currentCharIndex++
			lastKey = 0
		ok
		
		if currentCharIndex <= len(text)
			nextChar = text[currentCharIndex]
		else 
			nextChar = text[currentCharIndex - 1]
		ok

	else 
		nextChar = text[1] 
		ok

	# Game UI
	if isnull(letters)
		DrawText("Start typing...", 10, 140, 35, GRAY)
	else
		DrawText(letters, 10, 140, textSize, RED)
	ok
	
	# Check if the game ends 
	if len(letters) >= len(text)
		started = False

		if text = letters
			DrawText("YOU WIN", screenWidth / 2 - 80, 259, 35, RED)
		else
			DrawText("YOU LOSE", screenWidth / 2 - 80, 259, 35, RED) ok
	ok
	
        ClearBackground(RAYWHITE)
	EndDrawing()
end

CloseWindow()
unloadImage(windowIcon)

# Function to generate string using a list of characters
func generateString length, letters
	text = ""
	stringLength = random(4) + 1
	for i = 1 to length
		rand = random(len(letters) - 1) + 1
		text = text + letters[rand]
		stringLength--

		if i < length and stringLength < 0
			text = text  + " "
			stringLength = random(4) + 1
		ok
	next

	return text
