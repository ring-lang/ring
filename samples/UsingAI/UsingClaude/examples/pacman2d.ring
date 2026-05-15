/*
	Ring Pac - Classic Pac-Man Arcade Game
	Ring + RayLib | Maze, Ghost AI, Pellets, Power-ups
*/

load "raylib.ring"

# Constants
C_SW=672 C_SH=800 C_TILE=24 C_FPS=60
C_COLS=28 C_ROWS=31
C_OX=0 C_OY=72

# States
S_MNU=0 S_PLY=1 S_DIE=2 S_OVR=3 S_WIN=4 S_RDY=5

# Tiles
T_E=0 T_W=1 T_DOT=2 T_PWR=3 T_GATE=4

# Ghost modes
GM_CHASE=0 GM_SCATTER=1 GM_FRIGHT=2 GM_EATEN=3

# Directions
D_NONE=0 D_UP=1 D_DOWN=2 D_LEFT=3 D_RIGHT=4

# Game state - all globals
pX=14 pY=24 pDir=D_LEFT pNxt=D_LEFT
gST=S_MNU gSCR=0 gLIV=3
gATM=0 gDOTS=0 gTDOT=0 gDTM=0
gFRT=0 gLVL=1 gRDTM=0
pMouth=0 pMTM=0
gFRTKL=0 gFRSC=200

# Ghost list and level grid
ghosts=[]
lvl=[]
fts=[]
pMoveT=0 pMoveSpd=14

# Classic 28x31 maze
mazeStr=[
"WWWWWWWWWWWWWWWWWWWWWWWWWWWW",
"W............WW............W",
"W.WWWW.WWWWW.WW.WWWWW.WWWW.W",
"WoWWWW.WWWWW.WW.WWWWW.WWWWoW",
"W.WWWW.WWWWW.WW.WWWWW.WWWW.W",
"W..........................W",
"W.WWWW.WW.WWWWWWWW.WW.WWWW.W",
"W.WWWW.WW.WWWWWWWW.WW.WWWW.W",
"W......WW....WW....WW......W",
"WWWWWW.WWWWW.WW.WWWWW.WWWWWW",
"eeeeeW.WWWWW.WW.WWWWW.Weeeee",
"eeeeeW.WW..........WW.Weeeee",
"eeeeeW.WW.WWW--WWW.WW.Weeeee",
"WWWWWW.WW.WeeeeeeW.WW.WWWWWW",
"ee........WeeeeeeW........ee",
"WWWWWW.WW.WeeeeeeW.WW.WWWWWW",
"eeeeeW.WW.WWWWWWWW.WW.Weeeee",
"eeeeeW.WW..........WW.Weeeee",
"eeeeeW.WW.WWWWWWWW.WW.Weeeee",
"WWWWWW.WW.WWWWWWWW.WW.WWWWWW",
"W............WW............W",
"W.WWWW.WWWWW.WW.WWWWW.WWWW.W",
"W.WWWW.WWWWW.WW.WWWWW.WWWW.W",
"Wo..WW................WW..oW",
"WWW.WW.WW.WWWWWWWW.WW.WW.WWW",
"WWW.WW.WW.WWWWWWWW.WW.WW.WWW",
"W......WW....WW....WW......W",
"W.WWWWWWWWWW.WW.WWWWWWWWWW.W",
"W.WWWWWWWWWW.WW.WWWWWWWWWW.W",
"W..........................W",
"WWWWWWWWWWWWWWWWWWWWWWWWWWWW"
]

# Colors
cWall    = ncc(33,33,255,255)
cDot     = ncc(255,183,174,255)
cPwr     = ncc(255,183,174,255)
cPacYel  = ncc(255,255,0,255)
cPacDk   = ncc(200,200,0,255)
cGRed    = ncc(255,0,0,255)
cGPink   = ncc(255,184,255,255)
cGCyan   = ncc(0,255,255,255)
cGOrange = ncc(255,184,82,255)
cGFright = ncc(33,33,255,255)
cGFrWht  = ncc(255,255,255,255)
cGEyes   = ncc(255,255,255,255)
cGPupil  = ncc(33,33,255,255)
cGate    = ncc(255,184,174,255)
cBG      = ncc(0,0,0,255)
cOverlay = ncc(0,0,0,180)
cGold    = ncc(251,208,0,255)
cRdy     = ncc(255,255,0,255)

# ========== MAIN ==========
InitWindow(C_SW,C_SH,"Ring Pac - Classic Pac-Man Arcade")
SetTargetFPS(C_FPS)
buildMaze()

while !WindowShouldClose()
	switch gST
	on S_MNU updMenu()
	on S_RDY updReady()
	on S_PLY updGame()
	on S_DIE updDie()
	on S_OVR updOver()
	on S_WIN updWin()
	off
	BeginDrawing()
	ClearBackground(cBG)
	switch gST
	on S_MNU drwMenu()
	on S_RDY drwGame() drwReady()
	on S_PLY drwGame()
	on S_DIE drwGame() drwDieOvr()
	on S_OVR drwOverScr()
	on S_WIN drwWinScr()
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

# ---- Maze Building ----
func buildMaze
	lvl=list(C_ROWS,C_COLS)
	gTDOT=0
	for r=1 to C_ROWS
		row=mazeStr[r]
		for c=1 to C_COLS
			ch=substr(row,c,1)
			if ch="W" lvl[r][c]=T_W
			but ch="." lvl[r][c]=T_DOT gTDOT++
			but ch="o" lvl[r][c]=T_PWR gTDOT++
			but ch="-" lvl[r][c]=T_GATE
			else lvl[r][c]=T_E ok
		next
	next

func resetGame
	buildMaze()
	gDOTS=0 gFRT=0
	resetPositions()

func resetPositions
	pX=14 pY=24 pDir=D_LEFT pNxt=D_LEFT
	pMouth=0 pMTM=0 gFRTKL=0 gFRSC=200
	pMoveT=0
	ghosts=[]
	# Blinky - starts outside
	add(ghosts,[:x=14,:y=12,:dir=D_LEFT,:mode=GM_CHASE,
		:tx=0,:ty=0,:sx=26,:sy=1,
		:inhouse=false,:rtmr=0,:spd=0,:moved=0])
	# Pinky - in house
	add(ghosts,[:x=14,:y=15,:dir=D_UP,:mode=GM_CHASE,
		:tx=0,:ty=0,:sx=3,:sy=1,
		:inhouse=true,:rtmr=60,:spd=0,:moved=0])
	# Inky - in house
	add(ghosts,[:x=12,:y=15,:dir=D_UP,:mode=GM_CHASE,
		:tx=0,:ty=0,:sx=26,:sy=30,
		:inhouse=true,:rtmr=120,:spd=0,:moved=0])
	# Clyde - in house
	add(ghosts,[:x=16,:y=15,:dir=D_UP,:mode=GM_CHASE,
		:tx=0,:ty=0,:sx=1,:sy=30,
		:inhouse=true,:rtmr=180,:spd=0,:moved=0])

# ---- Menu ----
func updMenu
	gATM++
	if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE)
		gLIV=3 gSCR=0 gLVL=1
		resetGame()
		gST=S_RDY gRDTM=120
	ok

func drwMenu
	ClearBackground(BLACK)
	t="RING PAC" tw=MeasureText(t,64)
	DT(t,floor((C_SW-tw)/2)+3,83,64,cPacDk)
	DT(t,floor((C_SW-tw)/2),80,64,cPacYel)
	t="Classic Maze Arcade" tw=MeasureText(t,22)
	DT(t,floor((C_SW-tw)/2),155,22,cGold)
	DrawCircle(C_SW/2-80,260,20,cPacYel)
	DrawCircle(C_SW/2-20,260,16,cGRed)
	DrawCircle(C_SW/2+20,260,16,cGPink)
	DrawCircle(C_SW/2+60,260,16,cGCyan)
	DrawCircle(C_SW/2+100,260,16,cGOrange)
	for i=0 to 12
		DrawCircle(C_SW/2-120+i*20,320,3,cDot)
	next
	t="Press ENTER to Start" tw=MeasureText(t,20)
	if gATM%60<42 DT(t,floor((C_SW-tw)/2),400,20,WHITE) ok
	DT("Controls:",240,460,18,cGold)
	DT("Arrow Keys / WASD - Move",240,485,16,WHITE)
	DT("Eat all dots to clear the level!",240,510,16,cDot)
	DT("Power pellets let you eat ghosts!",240,535,16,cPwr)
	DT("Made with Ring Language + RayLib",210,760,16,GRAY)

# ---- Ready ----
func updReady
	gATM++
	gRDTM--
	if gRDTM<=0 gST=S_PLY ok

func drwReady
	t="READY!" tw=MeasureText(t,28)
	DT(t,floor((C_SW-tw)/2),C_OY+17*C_TILE,28,cRdy)

# ---- Game Update ----
func updGame
	gATM++
	pMTM++
	if pMTM>4
		pMTM=0 pMouth++
		if pMouth>2 pMouth=0 ok
	ok
	if gFRT>0
		gFRT--
		if gFRT<=0
			for i=1 to len(ghosts)
				if ghosts[i][:mode]=GM_FRIGHT
					ghosts[i][:mode]=GM_CHASE
				ok
			next
			gFRTKL=0 gFRSC=200
		ok
	ok
	updPac()
	for i=1 to len(ghosts)
		updGhost(i)
	next
	updFTs()
	if gDOTS>=gTDOT gST=S_WIN ok

# ---- Pac-Man Movement ----
func updPac
	if IsKeyDown(KEY_LEFT) or IsKeyDown(KEY_A) pNxt=D_LEFT ok
	if IsKeyDown(KEY_RIGHT) or IsKeyDown(KEY_D) pNxt=D_RIGHT ok
	if IsKeyDown(KEY_UP) or IsKeyDown(KEY_W) pNxt=D_UP ok
	if IsKeyDown(KEY_DOWN) or IsKeyDown(KEY_S) pNxt=D_DOWN ok

	# Movement timer - only move every pMoveSpd frames
	pMoveT++
	if pMoveT<pMoveSpd return ok
	pMoveT=0

	# Try desired direction
	nx=pX ny=pY
	switch pNxt
	on D_LEFT  nx=pX-1
	on D_RIGHT nx=pX+1
	on D_UP    ny=pY-1
	on D_DOWN  ny=pY+1
	off
	if nx<1 nx=C_COLS ok
	if nx>C_COLS nx=1 ok
	if canMove(nx,ny)
		pDir=pNxt
		pX=nx pY=ny
	else
		# Continue current direction
		nx=pX ny=pY
		switch pDir
		on D_LEFT  nx=pX-1
		on D_RIGHT nx=pX+1
		on D_UP    ny=pY-1
		on D_DOWN  ny=pY+1
		off
		if nx<1 nx=C_COLS ok
		if nx>C_COLS nx=1 ok
		if canMove(nx,ny)
			pX=nx pY=ny
		ok
	ok
	# Eat dots
	if pY>=1 and pY<=C_ROWS and pX>=1 and pX<=C_COLS
		t=lvl[pY][pX]
		if t=T_DOT
			lvl[pY][pX]=T_E
			gDOTS++ gSCR+=10
		ok
		if t=T_PWR
			lvl[pY][pX]=T_E
			gDOTS++ gSCR+=50
			gFRT=360
			gFRTKL=0 gFRSC=200
			for i=1 to len(ghosts)
				if ghosts[i][:mode]!=GM_EATEN and !ghosts[i][:inhouse]
					ghosts[i][:mode]=GM_FRIGHT
					ghosts[i][:dir]=oppDir(ghosts[i][:dir])
				ok
			next
		ok
	ok
	# Ghost collision
	for i=1 to len(ghosts)
		if ghosts[i][:x]=pX and ghosts[i][:y]=pY
			if ghosts[i][:mode]=GM_FRIGHT
				ghosts[i][:mode]=GM_EATEN
				gFRTKL++
				sc=gFRSC
				gSCR+=sc
				addFT((pX-1)*C_TILE+C_OX,(pY-1)*C_TILE+C_OY,""+sc)
				gFRSC=gFRSC*2
			but ghosts[i][:mode]=GM_CHASE or ghosts[i][:mode]=GM_SCATTER
				pDie() return
			ok
		ok
	next

func canMove col,row
	if row<1 or row>C_ROWS return false ok
	if col<1 or col>C_COLS return true ok
	t=lvl[row][col]
	if t=T_W or t=T_GATE return false ok
	return true

func canMoveGhost col,row,isEaten
	if row<1 or row>C_ROWS return false ok
	if col<1 or col>C_COLS return true ok
	t=lvl[row][col]
	if t=T_W return false ok
	if t=T_GATE and isEaten return true ok
	if t=T_GATE return false ok
	return true

func oppDir d
	if d=D_UP return D_DOWN ok
	if d=D_DOWN return D_UP ok
	if d=D_LEFT return D_RIGHT ok
	if d=D_RIGHT return D_LEFT ok
	return D_NONE

# ---- Ghost AI ----
func updGhost idx
	gx=ghosts[idx][:x] gy=ghosts[idx][:y]
	gm=ghosts[idx][:mode]

	# Release from house
	if ghosts[idx][:inhouse]
		ghosts[idx][:rtmr]--
		if ghosts[idx][:rtmr]<=0
			ghosts[idx][:inhouse]=false
			ghosts[idx][:x]=14 ghosts[idx][:y]=12
			ghosts[idx][:dir]=D_LEFT
		ok
		return
	ok

	# Speed control - higher = slower
	ghosts[idx][:moved]++
	spd=18
	if gm=GM_FRIGHT spd=28 ok
	if gm=GM_EATEN spd=8 ok
	if ghosts[idx][:moved]<spd return ok
	ghosts[idx][:moved]=0

	# Set target
	if gm=GM_CHASE
		calcChaseTarget(idx)
	but gm=GM_SCATTER
		ghosts[idx][:tx]=ghosts[idx][:sx]
		ghosts[idx][:ty]=ghosts[idx][:sy]
	but gm=GM_FRIGHT
		ghosts[idx][:tx]=GetRandomValue(1,C_COLS)
		ghosts[idx][:ty]=GetRandomValue(1,C_ROWS)
	but gm=GM_EATEN
		ghosts[idx][:tx]=14 ghosts[idx][:ty]=12
		if gx=14 and gy=12
			ghosts[idx][:mode]=GM_CHASE
			return
		ok
	ok

	# Choose best direction
	isEaten=(gm=GM_EATEN)
	curDir=ghosts[idx][:dir]
	bestDir=curDir
	bestDist=999999
	dirs=[D_UP,D_LEFT,D_DOWN,D_RIGHT]

	for d=1 to 4
		dd=dirs[d]
		if dd=oppDir(curDir) loop ok
		nx=gx ny=gy
		if dd=D_UP ny=gy-1 ok
		if dd=D_DOWN ny=gy+1 ok
		if dd=D_LEFT nx=gx-1 ok
		if dd=D_RIGHT nx=gx+1 ok
		if nx<1 nx=C_COLS ok
		if nx>C_COLS nx=1 ok
		if canMoveGhost(nx,ny,isEaten)
			dx=nx-ghosts[idx][:tx]
			dy=ny-ghosts[idx][:ty]
			dist=dx*dx+dy*dy
			if dist<bestDist
				bestDist=dist bestDir=dd
			ok
		ok
	next

	ghosts[idx][:dir]=bestDir
	nx=gx ny=gy
	if bestDir=D_UP ny=gy-1 ok
	if bestDir=D_DOWN ny=gy+1 ok
	if bestDir=D_LEFT nx=gx-1 ok
	if bestDir=D_RIGHT nx=gx+1 ok
	if nx<1 nx=C_COLS ok
	if nx>C_COLS nx=1 ok
	if canMoveGhost(nx,ny,isEaten)
		ghosts[idx][:x]=nx ghosts[idx][:y]=ny
	ok

	# Collision after move
	if ghosts[idx][:x]=pX and ghosts[idx][:y]=pY
		if gm=GM_FRIGHT
			ghosts[idx][:mode]=GM_EATEN
			gFRTKL++
			sc=gFRSC
			gSCR+=sc
			addFT((pX-1)*C_TILE+C_OX,(pY-1)*C_TILE+C_OY,""+sc)
			gFRSC=gFRSC*2
		but gm=GM_CHASE or gm=GM_SCATTER
			pDie()
		ok
	ok

func calcChaseTarget idx
	if idx=1
		# Blinky: directly target Pac-Man
		ghosts[idx][:tx]=pX ghosts[idx][:ty]=pY
	ok
	if idx=2
		# Pinky: 4 tiles ahead
		tx=pX ty=pY
		if pDir=D_UP ty=pY-4 ok
		if pDir=D_DOWN ty=pY+4 ok
		if pDir=D_LEFT tx=pX-4 ok
		if pDir=D_RIGHT tx=pX+4 ok
		ghosts[idx][:tx]=tx ghosts[idx][:ty]=ty
	ok
	if idx=3
		# Inky: uses Blinky
		tx=pX ty=pY
		if pDir=D_UP ty=pY-2 ok
		if pDir=D_DOWN ty=pY+2 ok
		if pDir=D_LEFT tx=pX-2 ok
		if pDir=D_RIGHT tx=pX+2 ok
		bx=ghosts[1][:x] by=ghosts[1][:y]
		ghosts[idx][:tx]=tx+(tx-bx)
		ghosts[idx][:ty]=ty+(ty-by)
	ok
	if idx=4
		# Clyde: chase far, scatter close
		dx=ghosts[idx][:x]-pX dy=ghosts[idx][:y]-pY
		dist=dx*dx+dy*dy
		if dist>64
			ghosts[idx][:tx]=pX ghosts[idx][:ty]=pY
		else
			ghosts[idx][:tx]=ghosts[idx][:sx]
			ghosts[idx][:ty]=ghosts[idx][:sy]
		ok
	ok

# ---- Effects ----
func addFT x,y,txt
	add(fts,[:x=x,:y=y,:txt=txt,:tmr=45])

func updFTs
	for i=len(fts) to 1 step -1
		fts[i][:y]-=0.5 fts[i][:tmr]--
		if fts[i][:tmr]<=0 del(fts,i) ok
	next

# ---- States ----
func pDie
	gLIV-- gDTM=90 gST=S_DIE

func updDie
	gATM++ gDTM--
	if gDTM<=0
		if gLIV<=0 gST=S_OVR
		else
			resetPositions()
			gST=S_RDY gRDTM=90
		ok
	ok

func updOver
	gATM++
	if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE) gST=S_MNU ok

func updWin
	gATM++
	if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE)
		gLVL++
		resetGame()
		gST=S_RDY gRDTM=120
	ok

# ====================================================
# DRAWING
# ====================================================
func drwGame
	drwMaze()
	drwGhosts()
	drwPac()
	for i=1 to len(fts)
		DT(fts[i][:txt],floor(fts[i][:x]),floor(fts[i][:y]),14,cPacYel)
	next
	drwHUD()

# ---- Maze ----
func drwMaze
	for r=1 to C_ROWS
		for c=1 to C_COLS
			x=(c-1)*C_TILE+C_OX
			y=(r-1)*C_TILE+C_OY
			t=lvl[r][c]
			if t=T_W drwWall(x,y,r,c) ok
			if t=T_DOT DrawCircle(x+C_TILE/2,y+C_TILE/2,2,cDot) ok
			if t=T_PWR
				if gATM%30<20
					DrawCircle(x+C_TILE/2,y+C_TILE/2,6,cPwr)
				ok
			ok
			if t=T_GATE DrawRectangle(x,y+C_TILE/2-2,C_TILE,4,cGate) ok
		next
	next

func drwWall x,y,wr,wc
	DrawRectangle(x+1,y+1,C_TILE-2,C_TILE-2,cWall)
	if wr>1 and lvl[wr-1][wc]=T_W DrawRectangle(x+1,y,C_TILE-2,2,cWall) ok
	if wr<C_ROWS and lvl[wr+1][wc]=T_W DrawRectangle(x+1,y+C_TILE-2,C_TILE-2,2,cWall) ok
	if wc>1 and lvl[wr][wc-1]=T_W DrawRectangle(x,y+1,2,C_TILE-2,cWall) ok
	if wc<C_COLS and lvl[wr][wc+1]=T_W DrawRectangle(x+C_TILE-2,y+1,2,C_TILE-2,cWall) ok
	DrawRectangle(x+3,y+3,C_TILE-6,C_TILE-6,cBG)

# ---- Pac-Man ----
func drwPac
	if pX<1 or pX>C_COLS or pY<1 or pY>C_ROWS return ok
	x=(pX-1)*C_TILE+C_OX+C_TILE/2
	y=(pY-1)*C_TILE+C_OY+C_TILE/2
	rd=C_TILE/2-2

	if gST=S_DIE
		prog=gDTM
		if prog>60 DrawCircle(x,y,rd,cPacYel)
		else
			pr=rd*prog/60
			if pr>1 DrawCircle(x,y,pr,cPacYel) ok
		ok
		return
	ok

	DrawCircle(x,y,rd,cPacYel)

	# Mouth cutout
	if pMouth=1
		switch pDir
		on D_RIGHT triDraw(x,y,x+rd+2,y+4,x+rd+2,y-4,cBG)
		on D_LEFT  triDraw(x,y,x-rd-2,y-4,x-rd-2,y+4,cBG)
		on D_UP    triDraw(x,y,x+4,y-rd-2,x-4,y-rd-2,cBG)
		on D_DOWN  triDraw(x,y,x-4,y+rd+2,x+4,y+rd+2,cBG)
		off
	ok
	if pMouth=2
		switch pDir
		on D_RIGHT triDraw(x,y,x+rd+2,y+rd,x+rd+2,y-rd,cBG)
		on D_LEFT  triDraw(x,y,x-rd-2,y-rd,x-rd-2,y+rd,cBG)
		on D_UP    triDraw(x,y,x+rd,y-rd-2,x-rd,y-rd-2,cBG)
		on D_DOWN  triDraw(x,y,x-rd,y+rd+2,x+rd,y+rd+2,cBG)
		off
	ok

func triDraw x1,y1,x2,y2,x3,y3,col
	v1=new Vector2 v1.x=x1 v1.y=y1
	v2=new Vector2 v2.x=x2 v2.y=y2
	v3=new Vector2 v3.x=x3 v3.y=y3
	DrawTriangle(v1,v2,v3,col)

# ---- Ghosts ----
func drwGhosts
	for i=1 to len(ghosts)
		gx=(ghosts[i][:x]-1)*C_TILE+C_OX
		gy=(ghosts[i][:y]-1)*C_TILE+C_OY
		gm=ghosts[i][:mode]

		if ghosts[i][:inhouse]
			gc=ghostColor(i)
			drwGBody(gx,gy,gc)
			drwGEyes(gx,gy,ghosts[i][:dir])
			loop
		ok

		if gm=GM_EATEN
			drwGEyes(gx,gy,ghosts[i][:dir])
		but gm=GM_FRIGHT
			if gFRT<120 and gFRT%20<10
				drwGBody(gx,gy,cGFrWht)
			else
				drwGBody(gx,gy,cGFright)
			ok
			DrawRectangle(gx+6,gy+8,3,3,WHITE)
			DrawRectangle(gx+15,gy+8,3,3,WHITE)
			DrawRectangle(gx+4,gy+14,16,2,WHITE)
		else
			gc=ghostColor(i)
			drwGBody(gx,gy,gc)
			drwGEyes(gx,gy,ghosts[i][:dir])
		ok
	next

func ghostColor idx
	if idx=1 return cGRed ok
	if idx=2 return cGPink ok
	if idx=3 return cGCyan ok
	if idx=4 return cGOrange ok
	return cGRed

func drwGBody x,y,col
	DrawCircle(x+C_TILE/2,y+C_TILE/2,C_TILE/2-1,col)
	DrawRectangle(x+1,y+C_TILE/2,C_TILE-2,C_TILE/2-1,col)
	for w=0 to 2
		wx=x+2+w*8
		DrawRectangle(wx,y+C_TILE-4,6,4,col)
	next

func drwGEyes x,y,dir
	DrawRectangle(x+5,y+6,5,6,cGEyes)
	DrawRectangle(x+14,y+6,5,6,cGEyes)
	px1=x+6 py1=y+8 px2=x+15 py2=y+8
	if dir=D_LEFT px1=x+5 px2=x+14 ok
	if dir=D_RIGHT px1=x+7 px2=x+16 ok
	if dir=D_UP py1=y+6 py2=y+6 ok
	if dir=D_DOWN py1=y+9 py2=y+9 ok
	DrawRectangle(px1,py1,3,3,cGPupil)
	DrawRectangle(px2,py2,3,3,cGPupil)

# ---- HUD ----
func drwHUD
	DT("SCORE",10,10,16,WHITE)
	DT(""+gSCR,10,30,24,WHITE)
	DT("LEVEL",floor(C_SW/2)-30,10,16,WHITE)
	DT(""+gLVL,floor(C_SW/2)-10,30,24,cGold)
	DT("LIVES",C_SW-120,10,16,WHITE)
	for i=1 to gLIV
		DrawCircle(C_SW-110+(i-1)*26,42,9,cPacYel)
	next
	rem=gTDOT-gDOTS
	DT("DOTS:"+rem,floor(C_SW/2)+80,30,14,cDot)

# ---- Overlays ----
func drwDieOvr
	DrawRectangle(0,0,C_SW,C_SH,cOverlay)
	if gLIV>0
		t="CAUGHT!" tw=MeasureText(t,40)
		DT(t,floor((C_SW-tw)/2),floor(C_SH/2)-20,40,cGRed)
	ok

func drwOverScr
	ClearBackground(BLACK)
	t="GAME OVER" tw=MeasureText(t,52)
	DT(t,floor((C_SW-tw)/2)+2,floor(C_SH/2)-58,52,cPacDk)
	DT(t,floor((C_SW-tw)/2),floor(C_SH/2)-60,52,cPacYel)
	t="Score: "+gSCR tw=MeasureText(t,24)
	DT(t,floor((C_SW-tw)/2),floor(C_SH/2)+10,24,WHITE)
	t="Level: "+gLVL tw=MeasureText(t,20)
	DT(t,floor((C_SW-tw)/2),floor(C_SH/2)+45,20,cGold)
	t="Press ENTER" tw=MeasureText(t,18)
	if gATM%60<42 DT(t,floor((C_SW-tw)/2),floor(C_SH/2)+90,18,GRAY) ok

func drwWinScr
	ClearBackground(BLACK)
	t="LEVEL CLEAR!" tw=MeasureText(t,42)
	DT(t,floor((C_SW-tw)/2)+2,floor(C_SH/2)-58,42,cPacDk)
	DT(t,floor((C_SW-tw)/2),floor(C_SH/2)-60,42,cPacYel)
	t="Score: "+gSCR tw=MeasureText(t,26)
	DT(t,floor((C_SW-tw)/2),floor(C_SH/2),26,WHITE)
	t="Press ENTER for Level "+(gLVL+1) tw=MeasureText(t,18)
	if gATM%60<42 DT(t,floor((C_SW-tw)/2),floor(C_SH/2)+50,18,cGold) ok
