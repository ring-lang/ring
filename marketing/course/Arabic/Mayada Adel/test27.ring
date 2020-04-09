# ------------- Control Structures Part 2 -------------
for x = 1 to 10
	if x = 3
		? "Three"
		loop //Equal continue in another languages
	ok
	if x = 7
		exit //Equal break in another languages
	ok
	? x
next
? "........."
# ---------------- while statement (Loop) -------------------
# Style 1
x = 1
while x <10
	? x
	x++
end
? "........."
x = 1
while True
	? "Welcome"
	x++
	if x = 10
		exit
	ok
end
? "........."
x = 1
while 5    //while 5 (or any number except 0) = while True
	? "Welcome"
	x++
	if x = 10
		exit
	ok
end
? ".........."
# Style 2
x = 1
while x <10 {
	? x
	x++
}
? "........."
# ---------------- do again statement (Loop) -------------------
x = 1
do 
	? "Welcome"
again x > 10
