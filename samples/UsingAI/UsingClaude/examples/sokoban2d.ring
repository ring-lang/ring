/*
	Ring Sokoban - Classic Push-Box Puzzle
	Ring + RayLib | Grid puzzles, undo system, 20 levels
*/

load "raylib.ring"

# Constants
C_SW=720 C_SH=720 C_FPS=60
C_MAXW=20 C_MAXH=16

# Tiles
T_E=0 T_W=1 T_GOAL=2 T_BOX=3 T_BOXG=4 T_PLR=5 T_PLRG=6

# States
S_MNU=0 S_PLY=1 S_WIN=2 S_DONE=3

# Game globals
pX=0 pY=0 gST=S_MNU gATM=0 gLVL=1 gMoves=0 gPush=0
gridW=0 gridH=0 tileSize=48
offX=0 offY=60

# Grid, floor map, undo
grid=[]
floorMap=[]
undoStack=[]
maxUndo=200

# Levels (Sokoban standard notation: #=wall .=goal $=box @=player +=player on goal *=box on goal)
levels=[]

# Level 1 - 2 boxes
add(levels, [
"####",
"# .#",
"#  ###",
"#@$  #",
"#  $ #",
"#  . #",
"######"
])
# Level 2 - 2 boxes
add(levels, [
"######",
"#    #",
"# #@ #",
"# $  #",
"# .$ #",
"#  . #",
"######"
])
# Level 3 - 1 box
add(levels, [
"######",
"#    #",
"# $ @#",
"## # #",
"#  . #",
"#    #",
"######"
])
# Level 4 - 2 boxes
add(levels, [
"#######",
"#  .  #",
"#  $  #",
"#  @  #",
"#  $  #",
"#  .  #",
"#######"
])
# Level 5 - 2 boxes
add(levels, [
" ####",
" #  ##",
" # $ #",
"## $ #",
"# .. #",
"# @  #",
"######"
])
# Level 6 - 3 boxes
add(levels, [
"#######",
"#  .  #",
"#  $  #",
"#  .  #",
"#  $  #",
"# @$  #",
"#  .  #",
"#######"
])
# Level 7 - 2 boxes
add(levels, [
"  ####",
"###  #",
"#  . #",
"# #  #",
"# $$.#",
"# @  #",
"######"
])
# Level 8 - 3 boxes
add(levels, [
"########",
"#  @   #",
"# $$$  #",
"# .#.  #",
"#  .   #",
"########"
])
# Level 9 - 3 boxes
add(levels, [
"#######",
"#     #",
"# # # #",
"#  $  #",
"#.$@$.#",
"#  .  #",
"#######"
])
# Level 10 - 2 boxes
add(levels, [
"########",
"# .  . #",
"# $  $ #",
"###  ###",
"  # @#",
"  ####"
])
# Level 11 - 2 boxes
add(levels, [
"#####",
"#   ##",
"# $  #",
"##.# #",
"#  . #",
"# $@ #",
"#    #",
"######"
])
# Level 12 - 2 boxes
add(levels, [
"#####",
"#   ##",
"#.$  #",
"# .$ #",
"#  @ #",
"######"
])
# Level 13 - 4 boxes
add(levels, [
"#######",
"# . . #",
"# $$  #",
"#  @  #",
"# $$  #",
"# . . #",
"#######"
])
# Level 14 - 2 boxes
add(levels, [
"  #####",
"###   #",
"#   # #",
"# #$  #",
"# . ###",
"##@  #",
" #.$ #",
" #   #",
" #####"
])
# Level 15 - 4 boxes
add(levels, [
" ######",
"##    #",
"# $ $ #",
"# .#. #",
"# $ $ #",
"# .#.@#",
"##    #",
" ######"
])
# Level 16 - 3 boxes
add(levels, [
"#######",
"#  #  #",
"# $   #",
"#. .#$#",
"# $   #",
"#  # .#",
"#@ #  #",
"#######"
])
# Level 17 - 4 boxes
add(levels, [
"########",
"#   #  #",
"# . $  #",
"# .$ @##",
"# .$ ##",
"# .$ #",
"#    #",
"######"
])
# Level 18 - 4 boxes
add(levels, [
"  ######",
"  #    #",
"### ## #",
"# $  $ #",
"#  ..  #",
"# $  $@#",
"# ..   #",
"########"
])
# Level 19 - 4 boxes
add(levels, [
"#######",
"#  .  #",
"# $.$ #",
"#  @  #",
"# $.$ #",
"#  .  #",
"#######"
])
# Level 20 - 4 boxes
add(levels, [
"########",
"#      #",
"# $..$ #",
"#  ##  #",
"# $..$ #",
"#  @   #",
"########"
])

# Colors
cFloor  = ncc(200,190,170,255)
cFloor2 = ncc(190,180,160,255)
cWall   = ncc(90,70,50,255)
cWallLt = ncc(120,100,75,255)
cWallDk = ncc(60,45,30,255)
cBox    = ncc(200,150,50,255)
cBoxDk  = ncc(160,110,30,255)
cBoxLt  = ncc(230,190,90,255)
cBoxG   = ncc(100,200,80,255)
cBoxGDk = ncc(70,160,50,255)
cGoal   = ncc(220,60,60,255)
cGoalLt = ncc(250,100,100,255)
cPlr    = ncc(50,120,220,255)
cPlrDk  = ncc(30,80,170,255)
cPlrLt  = ncc(80,160,255,255)
cPlrFace= ncc(255,210,170,255)
cBG     = ncc(40,35,30,255)
cHUD    = ncc(50,45,38,255)
cGold   = ncc(251,208,0,255)
cStar   = ncc(255,220,80,255)

# ========== MAIN ==========
InitWindow(C_SW,C_SH,"Ring Sokoban - Push Box Puzzles")
SetTargetFPS(C_FPS)

while !WindowShouldClose()
	switch gST
	on S_MNU updMenu()
	on S_PLY updGame()
	on S_WIN updWin()
	on S_DONE updDone()
	off
	BeginDrawing()
	ClearBackground(cBG)
	switch gST
	on S_MNU drwMenu()
	on S_PLY drwGame()
	on S_WIN drwGame() drwWinOvr()
	on S_DONE drwDone()
	off
	EndDrawing()
end
CloseWindow()

# ====================================================
# FUNCTIONS
# ====================================================
func ncc nR,nG,nB,nA
	c=new Color c.r=nR c.g=nG c.b=nB c.a=nA
	return c

func DT text,x,y,sz,color
	drawtext(text,x,y,sz,GPData(color))

# ---- Level Loading ----
func loadLevel num
	if num>len(levels) return ok
	data=levels[num]
	gridH=len(data)
	gridW=0
	for r=1 to gridH
		rlen=len(data[r])
		if rlen>gridW gridW=rlen ok
	next
	if gridW>C_MAXW gridW=C_MAXW ok
	if gridH>C_MAXH gridH=C_MAXH ok

	# Calc tile size and offset
	maxTW=floor((C_SW-40)/gridW)
	maxTH=floor((C_SH-120)/gridH)
	tileSize=maxTW
	if maxTH<tileSize tileSize=maxTH ok
	if tileSize>64 tileSize=64 ok
	if tileSize<24 tileSize=24 ok
	offX=floor((C_SW-gridW*tileSize)/2)
	offY=floor((C_SH-gridH*tileSize)/2)+30

	grid=list(gridH,gridW)
	for r=1 to gridH
		for c=1 to gridW
			grid[r][c]=T_E
		next
	next

	pX=0 pY=0 gMoves=0 gPush=0
	undoStack=[]

	for r=1 to gridH
		row=data[r]
		for c=1 to len(row)
			if c>gridW loop ok
			ch=substr(row,c,1)
			if ch="#" grid[r][c]=T_W
			but ch="." grid[r][c]=T_GOAL
			but ch="$" grid[r][c]=T_BOX
			but ch="*" grid[r][c]=T_BOXG
			but ch="@" grid[r][c]=T_PLR pX=c pY=r
			but ch="+" grid[r][c]=T_PLRG pX=c pY=r
			else grid[r][c]=T_E ok
		next
	next

	# Build floor map: mark every non-wall tile that is reachable
	floorMap=list(gridH,gridW)
	for r=1 to gridH
		for c=1 to gridW
			floorMap[r][c]=0
		next
	next
	# Flood fill from player position
	floodQ=[]
	add(floodQ,[pY,pX])
	floorMap[pY][pX]=1
	while len(floodQ)>0
		cr=floodQ[1][1] cc2=floodQ[1][2]
		del(floodQ,1)
		dirs=[[0,1],[0,-1],[1,0],[-1,0]]
		for d=1 to 4
			nr=cr+dirs[d][1] nc=cc2+dirs[d][2]
			if nr>=1 and nr<=gridH and nc>=1 and nc<=gridW
				if floorMap[nr][nc]=0 and grid[nr][nc]!=T_W
					floorMap[nr][nc]=1
					add(floodQ,[nr,nc])
				ok
			ok
		next
	end

# ---- Undo ----
func saveUndo
	# Save grid state + player pos + moves/push
	state=list(gridH,gridW)
	for r=1 to gridH
		for c=1 to gridW
			state[r][c]=grid[r][c]
		next
	next
	add(undoStack,[:grid=state,:px=pX,:py=pY,:mv=gMoves,:pu=gPush])
	if len(undoStack)>maxUndo del(undoStack,1) ok

func doUndo
	if len(undoStack)=0 return ok
	st=undoStack[len(undoStack)]
	del(undoStack,len(undoStack))
	for r=1 to gridH
		for c=1 to gridW
			grid[r][c]=st[:grid][r][c]
		next
	next
	pX=st[:px] pY=st[:py]
	gMoves=st[:mv] gPush=st[:pu]

# ---- Menu ----
func updMenu
	gATM++
	if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE)
		gLVL=1
		loadLevel(gLVL)
		gST=S_PLY
	ok

func drwMenu
	t="RING SOKOBAN" tw=MeasureText(t,52)
	DT(t,floor((C_SW-tw)/2)+3,63,52,cWallDk)
	DT(t,floor((C_SW-tw)/2),60,52,cGold)
	t="Push Box Puzzles" tw=MeasureText(t,22)
	DT(t,floor((C_SW-tw)/2),125,22,cBoxLt)

	# Preview
	bsz=36
	sx=C_SW/2 sy=240
	# Wall
	DrawRectangle(sx-bsz*2,sy,bsz,bsz,cWall)
	DrawRectangle(sx-bsz*2+2,sy+2,bsz-4,4,cWallLt)
	# Box
	DrawRectangle(sx-bsz/2,sy,bsz,bsz,cBox)
	DrawRectangle(sx-bsz/2+3,sy+3,bsz-6,bsz-6,cBoxDk)
	DrawRectangle(sx-bsz/2+6,sy+6,bsz-12,bsz-12,cBox)
	# Goal
	DrawRectangle(sx+bsz,sy,bsz,bsz,cFloor)
	DrawCircle(sx+bsz+bsz/2,sy+bsz/2,8,cGoal)
	# Player
	DrawRectangle(sx-bsz*2,sy+bsz+10,bsz-4,bsz-4,cPlr)

	DT("Wall      Box      Goal    Player",sx-120,sy+bsz*2+20,14,WHITE)

	t="Press ENTER to Start" tw=MeasureText(t,20)
	if gATM%60<42 DT(t,floor((C_SW-tw)/2),420,20,WHITE) ok
	DT("Controls:",260,470,18,cGold)
	DT("Arrow Keys / WASD - Move & Push",260,495,16,WHITE)
	DT("Z / Backspace    - Undo",260,515,16,WHITE)
	DT("R               - Restart Level",260,535,16,WHITE)
	DT(""+len(levels)+" Handcrafted Puzzles!",260,570,16,cGoalLt)
	DT("Made with Ring Language + RayLib",220,690,16,GRAY)

# ---- Game Update ----
func updGame
	gATM++
	# Input
	dx=0 dy=0
	if IsKeyPressed(KEY_LEFT) or IsKeyPressed(KEY_A) dx=-1 ok
	if IsKeyPressed(KEY_RIGHT) or IsKeyPressed(KEY_D) dx=1 ok
	if IsKeyPressed(KEY_UP) or IsKeyPressed(KEY_W) dy=-1 ok
	if IsKeyPressed(KEY_DOWN) or IsKeyPressed(KEY_S) dy=1 ok

	if dx!=0 or dy!=0
		tryMove(dx,dy)
	ok

	# Undo
	if IsKeyPressed(KEY_Z) or IsKeyPressed(KEY_BACKSPACE)
		doUndo()
	ok

	# Restart
	if IsKeyPressed(KEY_R) loadLevel(gLVL) ok

	# Skip level (debug)
	if IsKeyPressed(KEY_N)
		if gLVL<len(levels) gLVL++ loadLevel(gLVL) ok
	ok

	# Check win
	if chkWin()
		gST=S_WIN gATM=0
	ok

# ---- Movement ----
func tryMove dx,dy
	nx=pX+dx ny=pY+dy
	if nx<1 or nx>gridW or ny<1 or ny>gridH return ok
	target=grid[ny][nx]

	# Wall
	if target=T_W return ok

	# Empty or goal - just move
	if target=T_E or target=T_GOAL
		saveUndo()
		movePlayer(nx,ny)
		gMoves++
		return
	ok

	# Box or box-on-goal - try push
	if target=T_BOX or target=T_BOXG
		bx=nx+dx by=ny+dy
		if bx<1 or bx>gridW or by<1 or by>gridH return ok
		bt=grid[by][bx]
		if bt=T_E or bt=T_GOAL
			saveUndo()
			# Move box
			if bt=T_GOAL
				grid[by][bx]=T_BOXG
			else
				grid[by][bx]=T_BOX
			ok
			# Clear old box position
			if target=T_BOXG
				grid[ny][nx]=T_GOAL
			else
				grid[ny][nx]=T_E
			ok
			movePlayer(nx,ny)
			gMoves++ gPush++
		ok
	ok

func movePlayer nx,ny
	# Clear old position
	old=grid[pY][pX]
	if old=T_PLR grid[pY][pX]=T_E ok
	if old=T_PLRG grid[pY][pX]=T_GOAL ok
	# Set new position
	target=grid[ny][nx]
	if target=T_GOAL
		grid[ny][nx]=T_PLRG
	else
		grid[ny][nx]=T_PLR
	ok
	pX=nx pY=ny

func chkWin
	# Win if no T_BOX exists (all boxes on goals)
	for r=1 to gridH
		for c=1 to gridW
			if grid[r][c]=T_BOX return false ok
		next
	next
	return true

# ---- Win ----
func updWin
	gATM++
	if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE)
		if gLVL>=len(levels)
			gST=S_DONE
		else
			gLVL++
			loadLevel(gLVL)
			gST=S_PLY
		ok
	ok

func drwWinOvr
	DrawRectangle(0,0,C_SW,C_SH,ncc(0,0,0,140))
	# Stars
	for i=1 to 8
		sx=C_SW/2+sin(gATM*0.05+i)*200
		sy=C_SH/2+sin(gATM*0.07+i*2)*100-40
		DrawCircle(sx,sy,3,cStar)
	next
	t="LEVEL CLEAR!" tw=MeasureText(t,42)
	DT(t,floor((C_SW-tw)/2)+2,floor(C_SH/2)-78,42,cWallDk)
	DT(t,floor((C_SW-tw)/2),floor(C_SH/2)-80,42,cGold)
	t="Moves: "+gMoves+"  Pushes: "+gPush tw=MeasureText(t,22)
	DT(t,floor((C_SW-tw)/2),floor(C_SH/2)-20,22,WHITE)
	t="Press ENTER for Level "+(gLVL+1) tw=MeasureText(t,18)
	if gLVL>=len(levels) t="Press ENTER - All Complete!" tw=MeasureText(t,18) ok
	if gATM%60<42 DT(t,floor((C_SW-tw)/2),floor(C_SH/2)+30,18,cGold) ok

# ---- Done ----
func updDone
	gATM++
	if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE) gST=S_MNU ok

func drwDone
	t="CONGRATULATIONS!" tw=MeasureText(t,46)
	DT(t,floor((C_SW-tw)/2)+2,102,46,cWallDk)
	DT(t,floor((C_SW-tw)/2),100,46,cGold)
	t="All "+len(levels)+" Puzzles Solved!" tw=MeasureText(t,28)
	DT(t,floor((C_SW-tw)/2),180,28,cBoxLt)
	# Trophy
	DrawRectangle(C_SW/2-30,260,60,80,cGold)
	DrawRectangle(C_SW/2-20,270,40,60,cStar)
	DrawRectangle(C_SW/2-40,260,80,16,cGold)
	DrawRectangle(C_SW/2-14,340,28,12,cGold)
	DrawRectangle(C_SW/2-24,350,48,10,cGold)
	# Stars
	for i=1 to 12
		sx=C_SW/2+sin(gATM*0.04+i)*240
		sy=300+sin(gATM*0.06+i*2.5)*120
		DrawCircle(sx,sy,3,cStar)
	next
	t="Press ENTER" tw=MeasureText(t,18)
	if gATM%60<42 DT(t,floor((C_SW-tw)/2),420,18,GRAY) ok
	DT("Made with Ring Language + RayLib",220,690,16,GRAY)

# ====================================================
# DRAWING
# ====================================================
func drwGame
	drwHUD()
	drwGrid()

func drwHUD
	DrawRectangle(0,0,C_SW,50,cHUD)
	DT("Level "+gLVL+"/"+len(levels),15,8,20,cGold)
	DT("Moves:"+gMoves,200,8,16,WHITE)
	DT("Pushes:"+gPush,340,8,16,WHITE)
	DT("Z:Undo  R:Restart",C_SW-210,8,14,ncc(160,160,160,255))
	DT("N:Skip",C_SW-210,28,14,ncc(120,120,120,255))

func drwGrid
	ts=tileSize
	for r=1 to gridH
		for c=1 to gridW
			x=offX+(c-1)*ts
			y=offY+(r-1)*ts
			t=grid[r][c]

			# Draw floor for all reachable interior tiles
			if floorMap[r][c]=1
				if (r+c)%2=0
					DrawRectangle(x,y,ts,ts,cFloor)
				else
					DrawRectangle(x,y,ts,ts,cFloor2)
				ok
			ok

			switch t
			on T_W drwWall(x,y,ts)
			on T_GOAL drwGoal(x,y,ts)
			on T_BOX drwBox(x,y,ts,false)
			on T_BOXG drwGoal(x,y,ts) drwBox(x,y,ts,true)
			on T_PLR drwPlayer(x,y,ts)
			on T_PLRG drwGoal(x,y,ts) drwPlayer(x,y,ts)
			off
		next
	next

func drwWall x,y,ts
	DrawRectangle(x,y,ts,ts,cWall)
	DrawRectangle(x+1,y+1,ts-2,3,cWallLt)
	DrawRectangle(x+1,y+1,3,ts-2,cWallLt)
	DrawRectangle(x+2,y+ts-4,ts-4,3,cWallDk)
	DrawRectangle(x+ts-4,y+2,3,ts-4,cWallDk)

func drwGoal x,y,ts
	cx=x+ts/2 cy=y+ts/2
	rs=ts/5
	DrawCircle(cx,cy,rs+2,cGoalLt)
	DrawCircle(cx,cy,rs,cGoal)

func drwBox x,y,ts,onGoal
	m=3
	if onGoal
		DrawRectangle(x+m,y+m,ts-m*2,ts-m*2,cBoxG)
		DrawRectangle(x+m+2,y+m+2,ts-m*2-4,3,ncc(130,230,110,255))
		DrawRectangle(x+m+2,y+m+2,3,ts-m*2-4,ncc(130,230,110,255))
		DrawRectangle(x+m+3,y+ts-m-4,ts-m*2-6,3,cBoxGDk)
		# X mark
		cx=x+ts/2 cy=y+ts/2
		DrawRectangle(cx-ts/5,cy-2,ts*2/5,4,cBoxGDk)
		DrawRectangle(cx-2,cy-ts/5,4,ts*2/5,cBoxGDk)
	else
		DrawRectangle(x+m,y+m,ts-m*2,ts-m*2,cBox)
		DrawRectangle(x+m+2,y+m+2,ts-m*2-4,3,cBoxLt)
		DrawRectangle(x+m+2,y+m+2,3,ts-m*2-4,cBoxLt)
		DrawRectangle(x+m+3,y+ts-m-4,ts-m*2-6,3,cBoxDk)
		DrawRectangle(x+ts-m-4,y+m+3,3,ts-m*2-6,cBoxDk)
		# X mark
		cx=x+ts/2 cy=y+ts/2
		DrawRectangle(cx-ts/5,cy-2,ts*2/5,4,cBoxDk)
		DrawRectangle(cx-2,cy-ts/5,4,ts*2/5,cBoxDk)
	ok

func drwPlayer x,y,ts
	m=4
	# Body
	DrawRectangle(x+m+2,y+ts/3,ts-m*2-4,ts/2,cPlr)
	# Head
	cx=x+ts/2 cy=y+ts/4+2
	DrawCircle(cx,cy,ts/5,cPlr)
	DrawCircle(cx,cy,ts/5-2,cPlrFace)
	# Eyes
	DrawRectangle(cx-4,cy-2,3,3,BLACK)
	DrawRectangle(cx+2,cy-2,3,3,BLACK)
	# Hat
	DrawRectangle(cx-ts/5,cy-ts/5-1,ts*2/5,4,cPlrDk)
	# Feet
	DrawRectangle(x+m+4,y+ts-m-6,ts/3-4,6,cPlrDk)
	DrawRectangle(x+ts-m-ts/3,y+ts-m-6,ts/3-4,6,cPlrDk)
