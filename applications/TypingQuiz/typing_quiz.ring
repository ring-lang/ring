# Typing Quiz Game using raylib
# Author: Ahmad Zakaria (zaka7024@gmail.com)
# Date: 8/2020

Load "stdlib.ring"
load "raylib.ring"

screenWidth  = 800
screenHeight = 400

func main

InitWindow(screenWidth, screenHeight, "raylib [core] example - keyboard input")
SetTargetFPS(60)

if iswindows()
	system("cls")
ok

# quiz chars
chars = [['j', 'f'], ['c', 'k'], ['d', 'k'], ['e', 'o']]

# select quiz chars
k = random(len(chars) - 1) + 1
CHAR_ONE = chars[k][1]
CHAR_TWO = chars[k][2]

sentanceLength = random(39) + 1

# generate quiz text
text = generateString(sentanceLength, chars[k])

# game variables
letters = ""
started = False
lastKey = 0
error = 0
currentCharIndex = 1
timer = 0
keys = [:j = KEY_J, :f = KEY_F, :c = KEY_C, :e = KEY_E, :o = KEY_O,
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

	DrawText("Type this sentance with out looking at your keyboard", 10, 10, 26, RED)
	DrawText("TIME: " + timer, 500, 50, 26, RED)
	DrawText("SENTANCE:", 10, 50, 26, RED)
	DrawText("ERRORS: " + error, 300, 45, 26, RED)
	DrawText("Press R To Restart", 280, 300, 25, BLUE)
	DrawText(text, 10, 100, 35, RED)

	# Check if the user click the sentance chars
	if IsKeyReleased(CHAR_ONE_KEY)
		letters = letters + CHAR_ONE
		lastKey = CHAR_ONE_KEY
	elseif IsKeyReleased(CHAR_TWO_KEY)
		letters = letters + CHAR_TWO
		lastKey = CHAR_TWO_KEY
	elseif IsKeyReleased(KEY_SPACE)
		letters = letters + " " 
		lastKey = KEY_SPACE ok

	# Restart the game
	if IsKeyReleased(KEY_R)
		# load game variables
		k = random(len(chars) - 1) + 1
		CHAR_ONE = chars[k][1]
		CHAR_TWO = chars[k][2]
		CHAR_ONE_KEY = keys[CHAR_ONE]
		CHAR_TWO_KEY = keys[CHAR_TWO]
		text = generateString(20, chars[K])
		sentanceLength = random(39) + 1
		letters = ""
		started = False
		lastKey = 0
		error = 0
		currentCharIndex = 1
		timer = 0
	ok
	
	# Check if the user click at least one key
	if lastKey != 0
		started = true
	ok
	
	# Checking for error mechanism
	if len(letters) > 0 and len(letters) <= len(text)
		if lastKey != 0 and lower(char(lastKey)) != nextChar
			error++
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
		DrawText(letters, 10, 140, 35, RED)
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

# Function to generate string using a list of chars
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
