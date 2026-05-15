/*
	Ring Bomber - Bomberman Style Arcade Game
	Ring + RayLib | Grid movement, bombs, chain reactions, power-ups
*/

load "raylib.ring"

# Constants
C_SW=768 C_SH=672 C_TILE=48 C_FPS=60
C_COLS=15 C_ROWS=11
C_OX=12 C_OY=60

# States
S_MNU=0 S_PLY=1 S_DIE=2 S_OVR=3 S_WIN=4 S_LVLC=5

# Tiles
T_E=0 T_WALL=1 T_BRICK=2

# Powerup types
PU_BOMB=1 PU_FLAME=2 PU_SPEED=3 PU_KICK=4

# Game state - all globals
pX=1 pY=1 pDir=0 pFrm=0 pFTM=0
pBMax=1 pFlame=1 pSpeed=8 pKick=false
gST=S_MNU gSCR=0 gLIV=3
gATM=0 gDTM=0 gLVL=1
pMoveT=0

# Grid, bombs, explosions, enemies, powerups
grid=[]
bombs=[]
expls=[]
enemies=[]
pups=[]
fts=[]

# Colors
cGrass1  = ncc(60,150,50,255)
cGrass2  = ncc(50,130,42,255)
cWall    = ncc(140,140,140,255)
cWallDk  = ncc(100,100,100,255)
cWallLt  = ncc(180,180,180,255)
cBrick   = ncc(180,100,60,255)
cBrickDk = ncc(140,70,40,255)
cBrickLt = ncc(210,140,90,255)
cBombBlk = ncc(30,30,30,255)
cBombDk  = ncc(60,60,60,255)
cFuse    = ncc(255,200,50,255)
cExplC   = ncc(255,100,20,255)
cExplM   = ncc(255,200,50,255)
cExplO   = ncc(255,255,150,255)
cPlayer  = ncc(255,255,255,255)
cPHelm   = ncc(80,80,255,255)
cPBody   = ncc(255,255,255,255)
cPFeet   = ncc(40,40,40,255)
cPFace   = ncc(255,200,150,255)
cEnemy1  = ncc(220,60,60,255)
cEnemy2  = ncc(180,40,180,255)
cPUBomb  = ncc(30,30,30,255)
cPUFlame = ncc(255,100,20,255)
cPUSpeed = ncc(60,60,255,255)
cPUKick  = ncc(60,200,60,255)
cHUD     = ncc(60,60,60,255)
cOverlay = ncc(0,0,0,180)
cGold    = ncc(251,208,0,255)

# ========== MAIN ==========
InitWindow(C_SW,C_SH,"Ring Bomber - Bomberman Style Arcade")
SetTargetFPS(C_FPS)

while !WindowShouldClose()
	switch gST
	on S_MNU updMenu()
	on S_PLY updGame()
	on S_DIE updDie()
	on S_OVR updOver()
	on S_WIN updWin()
	on S_LVLC updLvlC()
	off
	BeginDrawing()
	ClearBackground(BLACK)
	switch gST
	on S_MNU drwMenu()
	on S_PLY drwGame()
	on S_DIE drwGame() drwDieOvr()
	on S_OVR drwOverScr()
	on S_WIN drwWinScr()
	on S_LVLC drwGame() drwLvlC()
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

# ---- Level Building ----
func buildLevel num
	grid=list(C_ROWS,C_COLS)
	bombs=[] expls=[] enemies=[] pups=[] fts=[]
	pX=1 pY=1 pDir=0 pMoveT=0

	# Fill grid
	for r=1 to C_ROWS
		for c=1 to C_COLS
			if r%2=0 and c%2=0
				grid[r][c]=T_WALL
			else
				grid[r][c]=T_E
			ok
		next
	next

	# Place bricks randomly
	brickCount=25+num*5
	placed=0
	while placed<brickCount
		br=GetRandomValue(1,C_ROWS)
		bc=GetRandomValue(1,C_COLS)
		if grid[br][bc]=T_E
			# Keep starting area clear
			if (br<=2 and bc<=2) loop ok
			# Keep at least one path
			grid[br][bc]=T_BRICK
			placed++
		ok
	end

	# Place enemies
	enCount=3+num*2
	if enCount>12 enCount=12 ok
	placed=0
	while placed<enCount
		er=GetRandomValue(1,C_ROWS)
		ec=GetRandomValue(1,C_COLS)
		if grid[er][ec]=T_E and (er>3 or ec>3)
			etype=1
			if GetRandomValue(1,100)>70 etype=2 ok
			add(enemies,[:x=ec,:y=er,:dir=GetRandomValue(1,4),
				:alive=true,:type=etype,:moveT=0,
				:spd=20-num*2,:frm=0,:ftm=0])
			if enemies[len(enemies)][:spd]<8 enemies[len(enemies)][:spd]=8 ok
			placed++
		ok
	end

	# Place powerups under bricks
	puCount=3+num
	if puCount>8 puCount=8 ok
	placed=0
	while placed<puCount
		pr=GetRandomValue(1,C_ROWS)
		pc=GetRandomValue(1,C_COLS)
		if grid[pr][pc]=T_BRICK
			pt=GetRandomValue(1,4)
			add(pups,[:x=pc,:y=pr,:type=pt,:on=true,:vis=false])
			placed++
		ok
	end

# ---- Menu ----
func updMenu
	gATM++
	if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE)
		gLIV=3 gSCR=0 gLVL=1
		pBMax=1 pFlame=1 pSpeed=8 pKick=false
		buildLevel(1)
		gST=S_PLY
	ok

func drwMenu
	ClearBackground(ncc(20,60,20,255))
	t="RING BOMBER" tw=MeasureText(t,56)
	DT(t,floor((C_SW-tw)/2)+3,73,56,ncc(180,60,20,255))
	DT(t,floor((C_SW-tw)/2),70,56,ncc(255,150,50,255))
	t="Bomberman Style Arcade" tw=MeasureText(t,22)
	DT(t,floor((C_SW-tw)/2),140,22,cGold)

	# Draw player icon
	dx=C_SW/2-24 dy=220
	DrawRectangle(dx+12,dy,24,12,cPHelm)
	DrawRectangle(dx+14,dy+12,20,8,cPFace)
	DrawRectangle(dx+10,dy+20,28,16,cPBody)
	DrawRectangle(dx+12,dy+36,10,8,cPFeet)
	DrawRectangle(dx+26,dy+36,10,8,cPFeet)
	# Draw bomb
	DrawCircle(dx+60,dy+30,14,cBombBlk)
	DrawRectangle(dx+58,dy+10,4,12,cFuse)

	t="Press ENTER to Start" tw=MeasureText(t,20)
	if gATM%60<42 DT(t,floor((C_SW-tw)/2),340,20,WHITE) ok
	DT("Controls:",260,400,18,cGold)
	DT("Arrow Keys / WASD - Move",260,425,16,WHITE)
	DT("Space / X        - Place Bomb",260,445,16,WHITE)
	DT("Destroy bricks to find power-ups!",260,480,16,cExplM)
	DT("Defeat all enemies to clear level!",260,500,16,cEnemy1)
	DT("Made with Ring Language + RayLib",220,630,16,GRAY)

# ---- Game Update ----
func updGame
	gATM++
	updPlayer()
	updBombs()
	updExpls()
	updEnemies()
	updFTs()
	chkWin()

# ---- Player ----
func updPlayer
	# Buffered input
	nd=0
	if IsKeyDown(KEY_LEFT) or IsKeyDown(KEY_A) nd=3 ok
	if IsKeyDown(KEY_RIGHT) or IsKeyDown(KEY_D) nd=4 ok
	if IsKeyDown(KEY_UP) or IsKeyDown(KEY_W) nd=1 ok
	if IsKeyDown(KEY_DOWN) or IsKeyDown(KEY_S) nd=2 ok
	if nd>0 pDir=nd ok

	# Movement timer
	pMoveT++
	if pMoveT>=pSpeed and nd>0
		pMoveT=0
		nx=pX ny=pY
		if nd=1 ny=pY-1 ok
		if nd=2 ny=pY+1 ok
		if nd=3 nx=pX-1 ok
		if nd=4 nx=pX+1 ok
		if nx>=1 and nx<=C_COLS and ny>=1 and ny<=C_ROWS
			if grid[ny][nx]=T_E
				# Check no bomb at destination
				blocked=false
				for i=1 to len(bombs)
					if bombs[i][:x]=nx and bombs[i][:y]=ny blocked=true ok
				next
				if !blocked
					pX=nx pY=ny
					pFTM++
					if pFTM>4
						pFTM=0 pFrm++
						if pFrm>3 pFrm=0 ok
					ok
				ok
			ok
		ok
	ok

	# Place bomb
	if IsKeyPressed(KEY_SPACE) or IsKeyPressed(KEY_X)
		placeBomb()
	ok

	# Pickup powerups
	for i=1 to len(pups)
		if pups[i][:on] and pups[i][:vis]
			if pups[i][:x]=pX and pups[i][:y]=pY
				pups[i][:on]=false
				switch pups[i][:type]
				on PU_BOMB
					pBMax++
					addFT((pX-1)*C_TILE+C_OX,(pY-1)*C_TILE+C_OY,"BOMB+")
				on PU_FLAME
					pFlame++
					addFT((pX-1)*C_TILE+C_OX,(pY-1)*C_TILE+C_OY,"FIRE+")
				on PU_SPEED
					pSpeed-=2
					if pSpeed<3 pSpeed=3 ok
					addFT((pX-1)*C_TILE+C_OX,(pY-1)*C_TILE+C_OY,"SPEED+")
				on PU_KICK
					pKick=true
					addFT((pX-1)*C_TILE+C_OX,(pY-1)*C_TILE+C_OY,"KICK!")
				off
				gSCR+=100
			ok
		ok
	next

	# Check if standing in explosion
	for i=1 to len(expls)
		if expls[i][:x]=pX and expls[i][:y]=pY
			pDie() return
		ok
	next

func placeBomb
	# Count active bombs
	cnt=0
	for i=1 to len(bombs)
		if !bombs[i][:exploded] cnt++ ok
	next
	if cnt>=pBMax return ok
	# Check not already a bomb here
	for i=1 to len(bombs)
		if bombs[i][:x]=pX and bombs[i][:y]=pY return ok
	next
	add(bombs,[:x=pX,:y=pY,:tmr=180,:flame=pFlame,:exploded=false,:chain=false])

# ---- Bombs ----
func updBombs
	for i=len(bombs) to 1 step -1
		if bombs[i][:exploded] loop ok
		bombs[i][:tmr]--
		if bombs[i][:tmr]<=0
			explodeBomb(i)
		ok
	next
	# Clean up exploded bombs
	for i=len(bombs) to 1 step -1
		if bombs[i][:exploded] del(bombs,i) ok
	next

func explodeBomb idx
	bx=bombs[idx][:x] by=bombs[idx][:y]
	fl=bombs[idx][:flame]
	bombs[idx][:exploded]=true

	# Center explosion
	addExpl(bx,by)

	# Four directions
	dirs=[[0,-1],[0,1],[-1,0],[1,0]]
	for d=1 to 4
		dx=dirs[d][1] dy=dirs[d][2]
		for dist=1 to fl
			ex=bx+dx*dist ey=by+dy*dist
			if ex<1 or ex>C_COLS or ey<1 or ey>C_ROWS exit ok
			t=grid[ey][ex]
			if t=T_WALL exit ok
			if t=T_BRICK
				grid[ey][ex]=T_E
				addExpl(ex,ey)
				gSCR+=10
				# Reveal powerup
				for p=1 to len(pups)
					if pups[p][:x]=ex and pups[p][:y]=ey
						pups[p][:vis]=true
					ok
				next
				exit
			ok
			addExpl(ex,ey)
			# Chain reaction - detonate other bombs
			for b=1 to len(bombs)
				if !bombs[b][:exploded]
					if bombs[b][:x]=ex and bombs[b][:y]=ey
						explodeBomb(b)
					ok
				ok
			next
		next
	next

func addExpl ex,ey
	# Don't duplicate
	for i=1 to len(expls)
		if expls[i][:x]=ex and expls[i][:y]=ey return ok
	next
	add(expls,[:x=ex,:y=ey,:tmr=30])

# ---- Explosions ----
func updExpls
	for i=len(expls) to 1 step -1
		expls[i][:tmr]--
		# Kill enemies in explosion
		for e=1 to len(enemies)
			if enemies[e][:alive]
				if enemies[e][:x]=expls[i][:x] and enemies[e][:y]=expls[i][:y]
					enemies[e][:alive]=false
					if enemies[e][:type]=1 gSCR+=200
					else gSCR+=400 ok
					addFT((enemies[e][:x]-1)*C_TILE+C_OX,
						(enemies[e][:y]-1)*C_TILE+C_OY,
						""+gSCR)
				ok
			ok
		next
		if expls[i][:tmr]<=0 del(expls,i) ok
	next

# ---- Enemies ----
func updEnemies
	for i=1 to len(enemies)
		if !enemies[i][:alive] loop ok
		enemies[i][:moveT]++
		enemies[i][:ftm]++
		if enemies[i][:ftm]>8
			enemies[i][:ftm]=0 enemies[i][:frm]=1-enemies[i][:frm]
		ok
		espd=enemies[i][:spd]
		if enemies[i][:type]=2 espd=floor(espd*0.7) ok
		if enemies[i][:moveT]<espd loop ok
		enemies[i][:moveT]=0

		ex=enemies[i][:x] ey=enemies[i][:y]
		ed=enemies[i][:dir]

		# Type 2 chases player sometimes
		if enemies[i][:type]=2 and GetRandomValue(1,100)<30
			if pX<ex ed=3
			but pX>ex ed=4
			but pY<ey ed=1
			but pY>ey ed=2 ok
		ok

		# Try move in current direction
		nx=ex ny=ey
		if ed=1 ny=ey-1 ok
		if ed=2 ny=ey+1 ok
		if ed=3 nx=ex-1 ok
		if ed=4 nx=ex+1 ok

		canGo=false
		if nx>=1 and nx<=C_COLS and ny>=1 and ny<=C_ROWS
			if grid[ny][nx]=T_E
				# Check no bomb
				bblk=false
				for b=1 to len(bombs)
					if bombs[b][:x]=nx and bombs[b][:y]=ny bblk=true ok
				next
				if !bblk canGo=true ok
			ok
		ok

		if canGo
			enemies[i][:x]=nx enemies[i][:y]=ny
			enemies[i][:dir]=ed
		else
			# Pick random new direction
			enemies[i][:dir]=GetRandomValue(1,4)
		ok

		# Kill player on touch
		if enemies[i][:x]=pX and enemies[i][:y]=pY
			pDie()
		ok
	next

# ---- Effects ----
func addFT x,y,txt
	add(fts,[:x=x,:y=y,:txt=txt,:tmr=45])

func updFTs
	for i=len(fts) to 1 step -1
		fts[i][:y]-=0.5 fts[i][:tmr]--
		if fts[i][:tmr]<=0 del(fts,i) ok
	next

# ---- Win/Die ----
func chkWin
	alive=0
	for i=1 to len(enemies)
		if enemies[i][:alive] alive++ ok
	next
	if alive=0
		gST=S_LVLC gDTM=120 gSCR+=1000
	ok

func pDie
	gLIV-- gDTM=90 gST=S_DIE

func updDie
	gATM++ gDTM--
	if gDTM<=0
		if gLIV<=0 gST=S_OVR
		else
			buildLevel(gLVL)
			gST=S_PLY
		ok
	ok

func updOver
	gATM++
	if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE) gST=S_MNU ok

func updLvlC
	gATM++ gDTM--
	if gDTM<=0
		gLVL++
		buildLevel(gLVL)
		gST=S_PLY
	ok

func updWin
	gATM++
	if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE) gST=S_MNU ok

# ====================================================
# DRAWING
# ====================================================
func drwGame
	drwGrid()
	drwPUps()
	drwBombs()
	drwExpls()
	drwEnemies()
	drwPlayer()
	drwFTs()
	drwHUD()

# ---- Grid ----
func drwGrid
	for r=1 to C_ROWS
		for c=1 to C_COLS
			x=(c-1)*C_TILE+C_OX
			y=(r-1)*C_TILE+C_OY
			# Grass checkerboard
			if (r+c)%2=0
				DrawRectangle(x,y,C_TILE,C_TILE,cGrass1)
			else
				DrawRectangle(x,y,C_TILE,C_TILE,cGrass2)
			ok
			t=grid[r][c]
			if t=T_WALL
				DrawRectangle(x+1,y+1,C_TILE-2,C_TILE-2,cWall)
				DrawRectangle(x+2,y+2,C_TILE-4,3,cWallLt)
				DrawRectangle(x+2,y+2,3,C_TILE-4,cWallLt)
				DrawRectangle(x+3,y+C_TILE-5,C_TILE-6,3,cWallDk)
				DrawRectangle(x+C_TILE-5,y+3,3,C_TILE-6,cWallDk)
			ok
			if t=T_BRICK
				DrawRectangle(x+1,y+1,C_TILE-2,C_TILE-2,cBrick)
				# Brick pattern
				DrawRectangle(x+2,y+2,C_TILE-4,2,cBrickLt)
				DrawRectangle(x+2,y+2,2,C_TILE-4,cBrickLt)
				DrawRectangle(x+C_TILE/2-1,y+1,2,C_TILE-2,cBrickDk)
				DrawRectangle(x+1,y+C_TILE/2-1,C_TILE-2,2,cBrickDk)
				DrawRectangle(x+C_TILE/4,y+C_TILE/4,C_TILE/2,C_TILE/2,cBrick)
			ok
		next
	next

# ---- Powerups ----
func drwPUps
	for i=1 to len(pups)
		if !pups[i][:on] or !pups[i][:vis] loop ok
		x=(pups[i][:x]-1)*C_TILE+C_OX
		y=(pups[i][:y]-1)*C_TILE+C_OY
		pt=pups[i][:type]
		# Background
		DrawRectangle(x+8,y+8,C_TILE-16,C_TILE-16,WHITE)
		if gATM%40<30
			switch pt
			on PU_BOMB
				DrawCircle(x+C_TILE/2,y+C_TILE/2+2,8,cPUBomb)
				DrawRectangle(x+C_TILE/2-1,y+10,2,6,cFuse)
			on PU_FLAME
				DrawRectangle(x+C_TILE/2-4,y+12,8,24,cPUFlame)
				DrawRectangle(x+12,y+C_TILE/2-4,24,8,cPUFlame)
			on PU_SPEED
				# Arrow shape
				DrawRectangle(x+14,y+10,4,28,cPUSpeed)
				triDraw2(x+C_TILE/2,y+8,x+10,y+20,x+C_TILE-10,y+20,cPUSpeed)
			on PU_KICK
				DrawRectangle(x+14,y+12,6,20,cPUKick)
				DrawRectangle(x+20,y+26,12,6,cPUKick)
			off
		ok
	next

func triDraw2 x1,y1,x2,y2,x3,y3,col
	v1=new Vector2 v1.x=x1 v1.y=y1
	v2=new Vector2 v2.x=x2 v2.y=y2
	v3=new Vector2 v3.x=x3 v3.y=y3
	DrawTriangle(v1,v2,v3,col)

# ---- Bombs ----
func drwBombs
	for i=1 to len(bombs)
		if bombs[i][:exploded] loop ok
		x=(bombs[i][:x]-1)*C_TILE+C_OX
		y=(bombs[i][:y]-1)*C_TILE+C_OY
		# Pulsing bomb
		pulse=sin(gATM*0.15)*3
		sz=14+pulse
		DrawCircle(x+C_TILE/2,y+C_TILE/2+2,sz,cBombBlk)
		DrawCircle(x+C_TILE/2-3,y+C_TILE/2-2,sz/3,cBombDk)
		# Fuse
		if gATM%20<14
			DrawRectangle(x+C_TILE/2-1,y+6,3,10,cFuse)
			DrawCircle(x+C_TILE/2,y+6,3,cExplM)
		ok
		# Timer indicator
		if bombs[i][:tmr]<60
			if gATM%10<5
				DrawCircle(x+C_TILE/2,y+C_TILE/2,sz+4,cExplC)
				DrawCircle(x+C_TILE/2,y+C_TILE/2,sz,cBombBlk)
			ok
		ok
	next

# ---- Explosions ----
func drwExpls
	for i=1 to len(expls)
		x=(expls[i][:x]-1)*C_TILE+C_OX
		y=(expls[i][:y]-1)*C_TILE+C_OY
		t=expls[i][:tmr]
		# Animated explosion
		if t>20
			DrawRectangle(x+2,y+2,C_TILE-4,C_TILE-4,cExplC)
			DrawRectangle(x+8,y+8,C_TILE-16,C_TILE-16,cExplM)
		but t>10
			DrawRectangle(x+4,y+4,C_TILE-8,C_TILE-8,cExplM)
			DrawRectangle(x+10,y+10,C_TILE-20,C_TILE-20,cExplO)
		else
			DrawRectangle(x+8,y+8,C_TILE-16,C_TILE-16,cExplO)
		ok
	next

# ---- Enemies ----
func drwEnemies
	for i=1 to len(enemies)
		if !enemies[i][:alive] loop ok
		x=(enemies[i][:x]-1)*C_TILE+C_OX
		y=(enemies[i][:y]-1)*C_TILE+C_OY
		frm=enemies[i][:frm]
		if enemies[i][:type]=1
			# Balloon enemy
			DrawCircle(x+C_TILE/2,y+C_TILE/2-2,16,cEnemy1)
			DrawCircle(x+C_TILE/2,y+C_TILE/2-2,12,ncc(240,100,100,255))
			# Eyes
			DrawRectangle(x+16,y+16,5,5,WHITE)
			DrawRectangle(x+27,y+16,5,5,WHITE)
			DrawRectangle(x+17,y+18,3,3,BLACK)
			DrawRectangle(x+28,y+18,3,3,BLACK)
			# Feet
			if frm=0
				DrawRectangle(x+14,y+34,8,6,cEnemy1)
				DrawRectangle(x+26,y+34,8,6,cEnemy1)
			else
				DrawRectangle(x+12,y+34,8,6,cEnemy1)
				DrawRectangle(x+28,y+34,8,6,cEnemy1)
			ok
		else
			# Purple ghost enemy
			DrawRectangle(x+8,y+6,32,28,cEnemy2)
			DrawCircle(x+C_TILE/2,y+12,16,cEnemy2)
			DrawRectangle(x+14,y+14,5,5,WHITE)
			DrawRectangle(x+27,y+14,5,5,WHITE)
			DrawRectangle(x+15,y+16,3,3,BLACK)
			DrawRectangle(x+28,y+16,3,3,BLACK)
			# Wavy bottom
			if frm=0
				for w=0 to 3
					DrawRectangle(x+8+w*8,y+30,6,8,cEnemy2)
				next
			else
				for w=0 to 3
					DrawRectangle(x+10+w*8,y+30,6,8,cEnemy2)
				next
			ok
		ok
	next

# ---- Player ----
func drwPlayer
	x=(pX-1)*C_TILE+C_OX
	y=(pY-1)*C_TILE+C_OY
	# Helmet
	DrawRectangle(x+12,y+4,24,14,cPHelm)
	DrawRectangle(x+14,y+2,20,6,cPHelm)
	# Face
	DrawRectangle(x+14,y+14,20,10,cPFace)
	# Eyes
	if pDir=3
		DrawRectangle(x+15,y+16,4,4,BLACK)
		DrawRectangle(x+23,y+16,4,4,BLACK)
	but pDir=4
		DrawRectangle(x+21,y+16,4,4,BLACK)
		DrawRectangle(x+29,y+16,4,4,BLACK)
	else
		DrawRectangle(x+17,y+16,4,4,BLACK)
		DrawRectangle(x+27,y+16,4,4,BLACK)
	ok
	# Body
	DrawRectangle(x+10,y+24,28,14,cPBody)
	DrawRectangle(x+12,y+24,24,14,cPHelm)
	# Belt
	DrawRectangle(x+10,y+32,28,3,cGold)
	# Feet
	if pFrm=0 or pFrm=2
		DrawRectangle(x+12,y+38,10,8,cPFeet)
		DrawRectangle(x+26,y+38,10,8,cPFeet)
	but pFrm=1
		DrawRectangle(x+8,y+38,10,8,cPFeet)
		DrawRectangle(x+30,y+38,10,8,cPFeet)
	but pFrm=3
		DrawRectangle(x+14,y+38,10,8,cPFeet)
		DrawRectangle(x+24,y+38,10,8,cPFeet)
	ok

# ---- Floating Texts ----
func drwFTs
	for i=1 to len(fts)
		DT(fts[i][:txt],floor(fts[i][:x]),floor(fts[i][:y]),14,cGold)
	next

# ---- HUD ----
func drwHUD
	DrawRectangle(0,0,C_SW,C_OY,cHUD)
	DT("SCORE",15,5,14,WHITE)
	DT(""+gSCR,15,22,22,WHITE)
	DT("LEVEL",floor(C_SW/2)-30,5,14,WHITE)
	DT(""+gLVL,floor(C_SW/2)-10,22,22,cGold)
	DT("LIVES",C_SW-130,5,14,WHITE)
	for i=1 to gLIV
		DrawCircle(C_SW-120+(i-1)*24,36,8,cPHelm)
	next
	# Power-up indicators
	pu_x=180
	DT("B:"+pBMax,pu_x,8,14,cFuse)
	DT("F:"+pFlame,pu_x+50,8,14,cExplC)
	s_str="S:"+pSpeed
	DT(s_str,pu_x+110,8,14,cPUSpeed)
	if pKick DT("KICK",pu_x+170,8,14,cPUKick) ok

	# Enemy count
	alive=0
	for i=1 to len(enemies)
		if enemies[i][:alive] alive++ ok
	next
	DT("Enemies:"+alive,pu_x,36,14,cEnemy1)

# ---- Overlays ----
func drwDieOvr
	DrawRectangle(0,0,C_SW,C_SH,cOverlay)
	if gLIV>0
		t="BOMBED!" tw=MeasureText(t,44)
		DT(t,floor((C_SW-tw)/2),floor(C_SH/2)-20,44,cExplC)
	ok

func drwLvlC
	DrawRectangle(0,0,C_SW,C_SH,cOverlay)
	t="LEVEL CLEAR!" tw=MeasureText(t,42)
	DT(t,floor((C_SW-tw)/2)+2,floor(C_SH/2)-38,42,ncc(200,160,0,255))
	DT(t,floor((C_SW-tw)/2),floor(C_SH/2)-40,42,cGold)
	t="Score: "+gSCR tw=MeasureText(t,26)
	DT(t,floor((C_SW-tw)/2),floor(C_SH/2)+20,26,WHITE)

func drwOverScr
	ClearBackground(BLACK)
	t="GAME OVER" tw=MeasureText(t,52)
	DT(t,floor((C_SW-tw)/2)+2,floor(C_SH/2)-58,52,ncc(180,60,20,255))
	DT(t,floor((C_SW-tw)/2),floor(C_SH/2)-60,52,cExplC)
	t="Score: "+gSCR tw=MeasureText(t,24)
	DT(t,floor((C_SW-tw)/2),floor(C_SH/2)+10,24,WHITE)
	t="Press ENTER" tw=MeasureText(t,18)
	if gATM%60<42 DT(t,floor((C_SW-tw)/2),floor(C_SH/2)+60,18,GRAY) ok

func drwWinScr
	ClearBackground(BLACK)
	t="CONGRATULATIONS!" tw=MeasureText(t,42)
	DT(t,floor((C_SW-tw)/2)+2,floor(C_SH/2)-58,42,ncc(200,160,0,255))
	DT(t,floor((C_SW-tw)/2),floor(C_SH/2)-60,42,cGold)
	t="Final Score: "+gSCR tw=MeasureText(t,26)
	DT(t,floor((C_SW-tw)/2),floor(C_SH/2),26,WHITE)
	t="Press ENTER" tw=MeasureText(t,18)
	if gATM%60<42 DT(t,floor((C_SW-tw)/2),floor(C_SH/2)+60,18,GRAY) ok
