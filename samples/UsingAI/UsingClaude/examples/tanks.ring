/*
	Ring Tanks - 2-Player Top-Down Tank Battle
	Ring + RayLib | Destructible terrain, ricochet bullets, power-ups
*/

load "raylib.ring"

# Constants
C_SW=960 C_SH=720 C_FPS=60
C_TILE=32 C_COLS=30 C_ROWS=20
C_OX=0 C_OY=40

# Tiles
T_E=0 T_WALL=1 T_BRICK=2 T_WATER=3 T_TREE=4

# States
S_MNU=0 S_PLY=1 S_RND=2 S_P1W=3 S_P2W=4 S_DONE=5

# Game globals
gST=S_MNU gATM=0 gRound=1 gMaxRnd=5
p1Score=0 p2Score=0 gDTM=0
p1Alive=true p2Alive=true
aiMode=false aiMnuSel=1

# AI state
aiTmr=0 aiState=0 aiTgtDir=0.0 aiDodgeT=0 aiStuckT=0
aiLastX=0.0 aiLastY=0.0

# Tank data
p1X=0.0 p1Y=0.0 p1Dir=0.0 p1Speed=0 p1ShootT=0 p1HP=3 p1MaxHP=3
p2X=0.0 p2Y=0.0 p2Dir=180.0 p2Speed=0 p2ShootT=0 p2HP=3 p2MaxHP=3

# Constants for tanks
TK_SPD=2.0 TK_ROT=3.0 TK_SHOOT_CD=30 TK_SZ=12
BUL_SPD=5.0

# Lists
grid=[]
bullets=[]
parts=[]
pups=[]
fts=[]

# Colors
cGrass1  = ncc(80,140,50,255)
cGrass2  = ncc(70,125,42,255)
cWall    = ncc(160,160,160,255)
cWallDk  = ncc(110,110,110,255)
cWallLt  = ncc(200,200,200,255)
cBrick   = ncc(180,100,60,255)
cBrickDk = ncc(140,70,40,255)
cBrickLt = ncc(210,140,90,255)
cWater   = ncc(40,80,200,255)
cWaterLt = ncc(70,120,230,255)
cTree    = ncc(30,100,30,255)
cTreeLt  = ncc(50,140,50,255)
cP1Body  = ncc(50,120,220,255)
cP1Turr  = ncc(30,80,170,255)
cP1Dk    = ncc(20,60,130,255)
cP2Body  = ncc(220,60,50,255)
cP2Turr  = ncc(170,40,30,255)
cP2Dk    = ncc(130,20,15,255)
cBullet  = ncc(255,220,50,255)
cBullet2 = ncc(255,255,150,255)
cHUD     = ncc(40,40,40,255)
cGold    = ncc(251,208,0,255)
cHP      = ncc(50,200,50,255)
cHPBg    = ncc(80,30,30,255)
cPUHeal  = ncc(50,220,50,255)
cPUAmmo  = ncc(255,200,50,255)
cPUShld  = ncc(100,150,255,255)

# ========== MAIN ==========
InitWindow(C_SW,C_SH,"Ring Tanks - 2 Player Battle")
SetTargetFPS(C_FPS)
SetExitKey(0)

while !WindowShouldClose()
	switch gST
	on S_MNU updMenu()
	on S_PLY updGame()
	on S_RND updRndScr()
	on S_P1W updWinScr()
	on S_P2W updWinScr()
	on S_DONE updDone()
	off
	BeginDrawing()
	ClearBackground(BLACK)
	switch gST
	on S_MNU drwMenu()
	on S_PLY drwGame()
	on S_RND drwGame() drwRndScr()
	on S_P1W drwGame() drwRndWin(1)
	on S_P2W drwGame() drwRndWin(2)
	on S_DONE drwDoneScr()
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

# ---- Map Generation ----
func buildMap
	grid=list(C_ROWS,C_COLS)
	bullets=[] parts=[] pups=[] fts=[]

	# Fill with grass
	for r=1 to C_ROWS
		for c=1 to C_COLS
			grid[r][c]=T_E
		next
	next

	# Border walls
	for c=1 to C_COLS
		grid[1][c]=T_WALL grid[C_ROWS][c]=T_WALL
	next
	for r=1 to C_ROWS
		grid[r][1]=T_WALL grid[r][C_COLS]=T_WALL
	next

	# Internal walls - symmetric layout
	mid=floor(C_COLS/2)
	midR=floor(C_ROWS/2)

	# Central structure
	for r=midR-1 to midR+1
		grid[r][mid]=T_WALL
		grid[r][mid+1]=T_WALL
	next

	# Brick clusters (destructible)
	brickSets=[
		[4,6],[4,7],[5,6],
		[4,14],[4,15],[5,14],
		[8,4],[9,4],[8,5],
		[8,18],[9,18],[8,19],
		[14,8],[15,8],[14,9],
		[14,22],[15,22],[14,23],
		[17,6],[17,7],[18,6],
		[17,14],[17,15],[18,14]
	]
	for i=1 to len(brickSets)
		br=brickSets[i][1] bc=brickSets[i][2]
		if br>=2 and br<=C_ROWS-1 and bc>=2 and bc<=C_COLS-1
			grid[br][bc]=T_BRICK
		ok
	next

	# Scattered walls
	wallPts=[
		[3,11],[3,20],[6,9],[6,22],
		[10,3],[10,28],[11,3],[11,28],
		[15,4],[15,27],[18,11],[18,20]
	]
	for i=1 to len(wallPts)
		wr=wallPts[i][1] wc=wallPts[i][2]
		if wr>=2 and wr<=C_ROWS-1 and wc>=2 and wc<=C_COLS-1
			grid[wr][wc]=T_WALL
		ok
	next

	# Water patches
	waterPts=[
		[6,13],[6,14],[6,17],[6,18],
		[15,13],[15,14],[15,17],[15,18]
	]
	for i=1 to len(waterPts)
		wr=waterPts[i][1] wc=waterPts[i][2]
		if wr>=2 and wr<=C_ROWS-1 and wc>=2 and wc<=C_COLS-1
			grid[wr][wc]=T_WATER
		ok
	next

	# Tree cover
	treePts=[
		[3,4],[3,5],[4,4],
		[3,26],[3,27],[4,27],
		[18,4],[18,5],[19,4],
		[18,26],[18,27],[19,27]
	]
	for i=1 to len(treePts)
		tr=treePts[i][1] tc=treePts[i][2]
		if tr>=2 and tr<=C_ROWS-1 and tc>=2 and tc<=C_COLS-1
			grid[tr][tc]=T_TREE
		ok
	next

	# Random extra bricks
	for i=1 to 15+gRound*3
		br=GetRandomValue(3,C_ROWS-2)
		bc=GetRandomValue(3,C_COLS-2)
		if grid[br][bc]=T_E
			# Keep spawn areas clear
			if bc<6 and br<6 loop ok
			if bc>C_COLS-5 and br>C_ROWS-5 loop ok
			grid[br][bc]=T_BRICK
		ok
	next

	# Place power-ups
	for i=1 to 3
		pr=GetRandomValue(4,C_ROWS-3)
		pc=GetRandomValue(4,C_COLS-3)
		if grid[pr][pc]=T_E
			pt=GetRandomValue(1,3)
			add(pups,[:x=pc,:y=pr,:type=pt,:on=true,:tmr=600])
		ok
	next

	# Tank positions
	p1X=3.5*C_TILE+C_OX p1Y=3.5*C_TILE+C_OY
	p1Dir=135 p1HP=3 p1Alive=true p1ShootT=0 p1Speed=0
	p2X=(C_COLS-2.5)*C_TILE+C_OX p2Y=(C_ROWS-2.5)*C_TILE+C_OY
	p2Dir=315 p2HP=3 p2Alive=true p2ShootT=0 p2Speed=0
	aiTmr=0 aiState=0 aiStuckT=0 aiLastX=p2X aiLastY=p2Y

# ---- Menu ----
func updMenu
	gATM++
	# ESC on menu = close game
	if IsKeyPressed(KEY_ESCAPE) CloseWindow() shutdown("") ok

	# Keyboard selection
	if IsKeyPressed(KEY_UP) or IsKeyPressed(KEY_W) aiMnuSel=1 ok
	if IsKeyPressed(KEY_DOWN) or IsKeyPressed(KEY_S) aiMnuSel=2 ok

	# Mouse hover detection on menu options
	mx=GetMouseX() my=GetMouseY()
	bx1=floor(C_SW/2)-120 bx2=bx1+240
	by1a=305 by2a=341
	by1b=350 by2b=386
	if mx>=bx1 and mx<=bx2
		if my>=by1a and my<=by2a aiMnuSel=1 ok
		if my>=by1b and my<=by2b aiMnuSel=2 ok
	ok

	# Mouse click or Enter to start
	clicked=false
	if IsMouseButtonPressed(0)
		if mx>=bx1 and mx<=bx2
			if my>=by1a and my<=by2a aiMnuSel=1 clicked=true ok
			if my>=by1b and my<=by2b aiMnuSel=2 clicked=true ok
		ok
	ok

	if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE) or clicked
		if aiMnuSel=1 aiMode=false
		else aiMode=true ok
		p1Score=0 p2Score=0 gRound=1
		buildMap()
		gST=S_RND gDTM=90
	ok

func drwMenu
	t="RING TANKS" tw=MeasureText(t,56)
	DT(t,floor((C_SW-tw)/2)+3,43,56,cP2Dk)
	DT(t,floor((C_SW-tw)/2),40,56,cGold)
	t="Tank Battle Arena" tw=MeasureText(t,24)
	DT(t,floor((C_SW-tw)/2),105,24,WHITE)

	# Draw tanks preview
	drwTankIcon(C_SW/2-100,180,cP1Body,cP1Turr,45)
	DT("VS",C_SW/2-18,190,32,cGold)
	drwTankIcon(C_SW/2+60,180,cP2Body,cP2Turr,225)

	# Mode selection
	DT("Select Mode:",floor(C_SW/2)-80,270,22,cGold)
	# Option 1
	c1=WHITE c2=WHITE
	if aiMnuSel=1 c1=cGold ok
	if aiMnuSel=2 c2=cGold ok
	if aiMnuSel=1
		DrawRectangle(floor(C_SW/2)-120,305,240,36,ncc(60,60,80,255))
	ok
	DT("> 2 PLAYERS (PVP)",floor(C_SW/2)-100,310,22,c1)
	if aiMnuSel=2
		DrawRectangle(floor(C_SW/2)-120,350,240,36,ncc(60,60,80,255))
	ok
	DT("> VS COMPUTER (AI)",floor(C_SW/2)-100,355,22,c2)

	t="Press ENTER to Start" tw=MeasureText(t,18)
	if gATM%60<42 DT(t,floor((C_SW-tw)/2),410,18,WHITE) ok

	DT("Player 1 (Blue):",200,460,18,cP1Body)
	DT("W/A/S/D - Move    F - Shoot",200,482,16,WHITE)
	if aiMnuSel=1
		DT("Player 2 (Red):",200,515,18,cP2Body)
		DT("Arrow Keys - Move   L - Shoot",200,537,16,WHITE)
	else
		DT("Player 2 (Red): AI Controlled",200,515,18,cP2Body)
		DT("AI aims, dodges, and hunts you down!",200,537,16,cP2Body)
	ok
	DT("Destroy bricks for cover advantage!",200,575,16,cBrickLt)
	DT("Bullets ricochet off steel walls!",200,597,16,cWallLt)
	DT("First to "+gMaxRnd+" rounds wins!",200,630,16,cGold)
	DT("ESC - Quit  |  In-game ESC - Return to Menu",210,660,14,GRAY)
	DT("Made with Ring Language + RayLib",280,695,16,GRAY)

func drwTankIcon x,y,body,turr,ang
	DrawRectangle(x,y,40,40,body)
	DrawRectangle(x+5,y+5,30,30,turr)
	DrawRectangle(x+16,y-8,8,24,turr)

# ---- Round Screen ----
func updRndScr
	gATM++ gDTM--
	if IsKeyPressed(KEY_ESCAPE) gST=S_MNU return ok
	if gDTM<=0 gST=S_PLY ok

func drwRndScr
	DrawRectangle(0,0,C_SW,C_SH,ncc(0,0,0,160))
	t="ROUND "+gRound tw=MeasureText(t,48)
	DT(t,floor((C_SW-tw)/2),floor(C_SH/2)-50,48,cGold)
	t="P1: "+p1Score+"  -  P2: "+p2Score tw=MeasureText(t,24)
	DT(t,floor((C_SW-tw)/2),floor(C_SH/2)+20,24,WHITE)

# ---- Game Update ----
func updGame
	gATM++
	# ESC returns to menu
	if IsKeyPressed(KEY_ESCAPE) gST=S_MNU return ok
	if p1Alive updTank1() ok
	if p2Alive
		if aiMode updAI()
		else updTank2() ok
	ok
	updBullets()
	updParts()
	updFTs()
	updPUps()
	if p1ShootT>0 p1ShootT-- ok
	if p2ShootT>0 p2ShootT-- ok

# ---- Tank 1 (WASD + F) ----
func updTank1
	# Rotation
	if IsKeyDown(KEY_A) p1Dir-=TK_ROT ok
	if IsKeyDown(KEY_D) p1Dir+=TK_ROT ok
	if p1Dir<0 p1Dir+=360 ok
	if p1Dir>=360 p1Dir-=360 ok

	# Movement
	moving=false
	if IsKeyDown(KEY_W)
		nx=p1X+cos(p1Dir*3.14159/180)*TK_SPD
		ny=p1Y+sin(p1Dir*3.14159/180)*TK_SPD
		if canTankMove(nx,ny,1) p1X=nx p1Y=ny ok
		moving=true
	ok
	if IsKeyDown(KEY_S)
		nx=p1X-cos(p1Dir*3.14159/180)*TK_SPD
		ny=p1Y-sin(p1Dir*3.14159/180)*TK_SPD
		if canTankMove(nx,ny,1) p1X=nx p1Y=ny ok
		moving=true
	ok

	# Shoot
	if IsKeyPressed(KEY_F) and p1ShootT<=0
		rad=p1Dir*3.14159/180
		bx=p1X+cos(rad)*16
		by=p1Y+sin(rad)*16
		add(bullets,[:x=bx,:y=by,:vx=cos(rad)*BUL_SPD,:vy=sin(rad)*BUL_SPD,
			:owner=1,:life=180,:bounces=0])
		p1ShootT=TK_SHOOT_CD
	ok

	# Pickup powerups
	chkPUp(1)

# ---- Tank 2 (Arrows + L) ----
func updTank2
	if IsKeyDown(KEY_LEFT) p2Dir-=TK_ROT ok
	if IsKeyDown(KEY_RIGHT) p2Dir+=TK_ROT ok
	if p2Dir<0 p2Dir+=360 ok
	if p2Dir>=360 p2Dir-=360 ok

	if IsKeyDown(KEY_UP)
		nx=p2X+cos(p2Dir*3.14159/180)*TK_SPD
		ny=p2Y+sin(p2Dir*3.14159/180)*TK_SPD
		if canTankMove(nx,ny,2) p2X=nx p2Y=ny ok
	ok
	if IsKeyDown(KEY_DOWN)
		nx=p2X-cos(p2Dir*3.14159/180)*TK_SPD
		ny=p2Y-sin(p2Dir*3.14159/180)*TK_SPD
		if canTankMove(nx,ny,2) p2X=nx p2Y=ny ok
	ok

	if IsKeyPressed(KEY_L) and p2ShootT<=0
		rad=p2Dir*3.14159/180
		bx=p2X+cos(rad)*16
		by=p2Y+sin(rad)*16
		add(bullets,[:x=bx,:y=by,:vx=cos(rad)*BUL_SPD,:vy=sin(rad)*BUL_SPD,
			:owner=2,:life=180,:bounces=0])
		p2ShootT=TK_SHOOT_CD
	ok

	chkPUp(2)

# ---- AI Tank ----
func updAI
	aiTmr++
	PI=3.14159

	# Calculate angle to player
	dx=p1X-p2X dy=p1Y-p2Y
	dist=sqrt(dx*dx+dy*dy)
	aimAng=0.0
	if dist>1
		aimAng=atan2(dy,dx)*180/PI
		if aimAng<0 aimAng+=360 ok
	ok

	# Check if bullet is incoming (dodge)
	dodging=false
	for i=1 to len(bullets)
		if bullets[i][:owner]=2 loop ok
		bx=bullets[i][:x] by=bullets[i][:y]
		bdx=p2X-bx bdy=p2Y-by
		bdist=sqrt(bdx*bdx+bdy*bdy)
		if bdist<120
			# Check if bullet heading toward us
			dot=bdx*bullets[i][:vx]+bdy*bullets[i][:vy]
			if dot>0
				dodging=true
				exit
			ok
		ok
	next

	# Check if we have line of sight to player
	hasLOS=aiCheckLOS()

	# Stuck detection - check every 30 frames
	if aiTmr%30=0
		ddx=p2X-aiLastX ddy=p2Y-aiLastY
		if ddx*ddx+ddy*ddy<4
			aiStuckT+=30
		else
			aiStuckT=0
		ok
		aiLastX=p2X aiLastY=p2Y
	ok

	# --- AI Decision ---
	if dodging
		# Dodge: turn perpendicular to current facing and drive
		p2Dir+=TK_ROT*2
		if p2Dir>=360 p2Dir-=360 ok
		nx=p2X+cos(p2Dir*PI/180)*TK_SPD
		ny=p2Y+sin(p2Dir*PI/180)*TK_SPD
		if canTankMove(nx,ny,2) p2X=nx p2Y=ny ok
	else
		# Turn toward player
		angDiff=aimAng-p2Dir
		if angDiff>180 angDiff-=360 ok
		if angDiff<-180 angDiff+=360 ok

		# Stuck? Try random direction
		if aiStuckT>60
			if aiTmr%90<45
				angDiff=90
			else
				angDiff=-90
			ok
		ok

		# Smooth rotation toward target
		if angDiff>2
			p2Dir+=TK_ROT
		but angDiff<-2
			p2Dir-=TK_ROT
		ok
		if p2Dir<0 p2Dir+=360 ok
		if p2Dir>=360 p2Dir-=360 ok

		# Move forward
		if dist>80 or !hasLOS or aiStuckT>30
			nx=p2X+cos(p2Dir*PI/180)*TK_SPD
			ny=p2Y+sin(p2Dir*PI/180)*TK_SPD
			if canTankMove(nx,ny,2)
				p2X=nx p2Y=ny
			else
				# Can't move forward, try slight turns
				for tryAng=-30 to 30 step 15
					if tryAng=0 loop ok
					trad=(p2Dir+tryAng)*PI/180
					tnx=p2X+cos(trad)*TK_SPD
					tny=p2Y+sin(trad)*TK_SPD
					if canTankMove(tnx,tny,2)
						p2X=tnx p2Y=tny
						p2Dir+=tryAng/2
						exit
					ok
				next
			ok
		ok

		# Shoot when roughly aimed at player
		absD=fabs(angDiff)
		if absD<15 and p2ShootT<=0 and hasLOS and dist<500
			rad=p2Dir*PI/180
			bx=p2X+cos(rad)*16
			by=p2Y+sin(rad)*16
			add(bullets,[:x=bx,:y=by,:vx=cos(rad)*BUL_SPD,:vy=sin(rad)*BUL_SPD,
				:owner=2,:life=180,:bounces=0])
			p2ShootT=TK_SHOOT_CD
		ok
		# Shoot at bricks blocking path even when not aimed at player
		if absD<10 and p2ShootT<=0 and !hasLOS and dist<300
			rad=p2Dir*PI/180
			bx=p2X+cos(rad)*16
			by=p2Y+sin(rad)*16
			add(bullets,[:x=bx,:y=by,:vx=cos(rad)*BUL_SPD,:vy=sin(rad)*BUL_SPD,
				:owner=2,:life=180,:bounces=0])
			p2ShootT=TK_SHOOT_CD+10
		ok
	ok
	chkPUp(2)

func aiCheckLOS
	PI=3.14159
	# Raycast from p2 toward p1
	dx=p1X-p2X dy=p1Y-p2Y
	dist=sqrt(dx*dx+dy*dy)
	if dist<1 return true ok
	nx=dx/dist ny=dy/dist
	steps=floor(dist/8)
	for i=1 to steps
		cx=p2X+nx*i*8
		cy=p2Y+ny*i*8
		gc=floor((cx-C_OX)/C_TILE)+1
		gr=floor((cy-C_OY)/C_TILE)+1
		if gr>=1 and gr<=C_ROWS and gc>=1 and gc<=C_COLS
			t=grid[gr][gc]
			if t=T_WALL or t=T_BRICK return false ok
		ok
	next
	return true
func canTankMove nx,ny,owner
	sz=TK_SZ
	# Check 4 corners
	pts=[[nx-sz,ny-sz],[nx+sz,ny-sz],[nx-sz,ny+sz],[nx+sz,ny+sz]]
	for i=1 to 4
		px=pts[i][1] py=pts[i][2]
		gc=floor((px-C_OX)/C_TILE)+1
		gr=floor((py-C_OY)/C_TILE)+1
		if gr<1 or gr>C_ROWS or gc<1 or gc>C_COLS return false ok
		t=grid[gr][gc]
		if t=T_WALL or t=T_BRICK or t=T_WATER return false ok
	next
	# Don't overlap other tank
	if owner=1 and p2Alive
		dx=nx-p2X dy=ny-p2Y
		if dx*dx+dy*dy<(sz*2)*(sz*2) return false ok
	ok
	if owner=2 and p1Alive
		dx=nx-p1X dy=ny-p1Y
		if dx*dx+dy*dy<(sz*2)*(sz*2) return false ok
	ok
	return true

# ---- Bullets ----
func updBullets
	for i=len(bullets) to 1 step -1
		bullets[i][:x]+=bullets[i][:vx]
		bullets[i][:y]+=bullets[i][:vy]
		bullets[i][:life]--
		bx=bullets[i][:x] by=bullets[i][:y]

		if bullets[i][:life]<=0
			del(bullets,i) loop
		ok

		# Grid collision
		gc=floor((bx-C_OX)/C_TILE)+1
		gr=floor((by-C_OY)/C_TILE)+1
		if gr>=1 and gr<=C_ROWS and gc>=1 and gc<=C_COLS
			t=grid[gr][gc]
			if t=T_WALL
				# Ricochet off steel walls
				if bullets[i][:bounces]<2
					# Determine bounce direction
					prevX=bx-bullets[i][:vx]
					prevC=floor((prevX-C_OX)/C_TILE)+1
					prevY=by-bullets[i][:vy]
					prevR=floor((prevY-C_OY)/C_TILE)+1
					if prevC!=gc bullets[i][:vx]=-bullets[i][:vx] ok
					if prevR!=gr bullets[i][:vy]=-bullets[i][:vy] ok
					if prevC=gc and prevR=gr
						bullets[i][:vx]=-bullets[i][:vx]
						bullets[i][:vy]=-bullets[i][:vy]
					ok
					bullets[i][:bounces]++
					bullets[i][:x]+=bullets[i][:vx]*2
					bullets[i][:y]+=bullets[i][:vy]*2
					spawnSpark(bx,by)
				else
					spawnSpark(bx,by)
					del(bullets,i) loop
				ok
			ok
			if t=T_BRICK
				grid[gr][gc]=T_E
				spawnBrickParts(bx,by)
				del(bullets,i) loop
			ok
		else
			del(bullets,i) loop
		ok

		# Hit tanks
		bx=bullets[i][:x] by=bullets[i][:y]
		if p1Alive and bullets[i][:owner]!=1
			dx=bx-p1X dy=by-p1Y
			if dx*dx+dy*dy<TK_SZ*TK_SZ
				p1HP--
				spawnHitParts(p1X,p1Y,cP1Body)
				if p1HP<=0
					p1Alive=false
					spawnDeathParts(p1X,p1Y,cP1Body)
					p2Score++
					addFT(p1X,p1Y-20,"P2 SCORES!")
					chkRoundEnd()
				ok
				del(bullets,i) loop
			ok
		ok
		if p2Alive and bullets[i][:owner]!=2
			dx=bx-p2X dy=by-p2Y
			if dx*dx+dy*dy<TK_SZ*TK_SZ
				p2HP--
				spawnHitParts(p2X,p2Y,cP2Body)
				if p2HP<=0
					p2Alive=false
					spawnDeathParts(p2X,p2Y,cP2Body)
					p1Score++
					addFT(p2X,p2Y-20,"P1 SCORES!")
					chkRoundEnd()
				ok
				del(bullets,i) loop
			ok
		ok
	next

func chkRoundEnd
	if !p1Alive
		gST=S_P2W gDTM=120
	ok
	if !p2Alive
		gST=S_P1W gDTM=120
	ok

# ---- Power-ups ----
func updPUps
	for i=len(pups) to 1 step -1
		if !pups[i][:on] del(pups,i) loop ok
		pups[i][:tmr]--
		if pups[i][:tmr]<=0 del(pups,i) ok
	next

func chkPUp owner
	tx=p1X ty=p1Y
	if owner=2 tx=p2X ty=p2Y ok
	for i=1 to len(pups)
		if !pups[i][:on] loop ok
		px=(pups[i][:x]-0.5)*C_TILE+C_OX
		py=(pups[i][:y]-0.5)*C_TILE+C_OY
		dx=tx-px dy=ty-py
		if dx*dx+dy*dy<C_TILE*C_TILE
			pups[i][:on]=false
			pt=pups[i][:type]
			if pt=1
				# Heal
				if owner=1 p1HP++ if p1HP>5 p1HP=5 ok ok
				if owner=2 p2HP++ if p2HP>5 p2HP=5 ok ok
				addFT(px,py-10,"HEAL!")
			ok
			if pt=2
				# Speed boost (faster shooting)
				addFT(px,py-10,"RAPID!")
			ok
			if pt=3
				# Extra HP
				if owner=1 p1HP+=2 if p1HP>5 p1HP=5 ok ok
				if owner=2 p2HP+=2 if p2HP>5 p2HP=5 ok ok
				addFT(px,py-10,"ARMOR!")
			ok
		ok
	next

# ---- Particles ----
func addPart x,y,vx,vy,nc,life
	add(parts,[:x=x,:y=y,:vx=vx,:vy=vy,:nc=nc,:life=life,:ml=life])

func updParts
	for i=len(parts) to 1 step -1
		parts[i][:x]+=parts[i][:vx]
		parts[i][:y]+=parts[i][:vy]
		parts[i][:vy]+=0.05
		parts[i][:life]--
		if parts[i][:life]<=0 del(parts,i) ok
	next

func spawnSpark x,y
	for k=1 to 6
		addPart(x,y,GetRandomValue(-30,30)/10.0,GetRandomValue(-30,30)/10.0,
			cBullet,GetRandomValue(5,12))
	next

func spawnBrickParts x,y
	for k=1 to 10
		addPart(x,y,GetRandomValue(-25,25)/10.0,GetRandomValue(-25,25)/10.0,
			cBrick,GetRandomValue(10,20))
	next

func spawnHitParts x,y,nc
	for k=1 to 8
		addPart(x,y,GetRandomValue(-20,20)/10.0,GetRandomValue(-20,20)/10.0,
			nc,GetRandomValue(8,15))
	next

func spawnDeathParts x,y,nc
	for k=1 to 25
		addPart(x+GetRandomValue(-10,10),y+GetRandomValue(-10,10),
			GetRandomValue(-40,40)/10.0,GetRandomValue(-40,40)/10.0,
			nc,GetRandomValue(15,35))
	next
	for k=1 to 15
		addPart(x,y,GetRandomValue(-20,20)/10.0,GetRandomValue(-20,20)/10.0,
			cBullet,GetRandomValue(10,25))
	next

# ---- Effects ----
func addFT x,y,txt
	add(fts,[:x=x,:y=y,:txt=txt,:tmr=50])

func updFTs
	for i=len(fts) to 1 step -1
		fts[i][:y]-=0.6 fts[i][:tmr]--
		if fts[i][:tmr]<=0 del(fts,i) ok
	next

# ---- Round/Win ----
func updWinScr
	gATM++ gDTM--
	updParts()
	if IsKeyPressed(KEY_ESCAPE) gST=S_MNU return ok
	if gDTM<=0
		if p1Score>=gMaxRnd or p2Score>=gMaxRnd
			gST=S_DONE
		else
			gRound++
			buildMap()
			gST=S_RND gDTM=90
		ok
	ok

func drwRndWin who
	DrawRectangle(0,0,C_SW,C_SH,ncc(0,0,0,140))
	if who=1
		t="PLAYER 1 WINS ROUND!" tw=MeasureText(t,36)
		DT(t,floor((C_SW-tw)/2),floor(C_SH/2)-30,36,cP1Body)
	else
		if aiMode t="CPU WINS ROUND!"
		else t="PLAYER 2 WINS ROUND!" ok
		tw=MeasureText(t,36)
		DT(t,floor((C_SW-tw)/2),floor(C_SH/2)-30,36,cP2Body)
	ok
	t="P1: "+p1Score+"  -  P2: "+p2Score tw=MeasureText(t,24)
	DT(t,floor((C_SW-tw)/2),floor(C_SH/2)+20,24,WHITE)

func updDone
	gATM++
	updParts()
	if gATM%6=0
		addPart(GetRandomValue(100,C_SW-100),GetRandomValue(100,500),
			GetRandomValue(-3,3),GetRandomValue(-4,-1),
			ncc(GetRandomValue(150,255),GetRandomValue(150,255),50,255),30)
	ok
	if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE) or IsKeyPressed(KEY_ESCAPE) gST=S_MNU ok

func drwDoneScr
	for i=1 to len(parts)
		DrawCircle(parts[i][:x],parts[i][:y],3,parts[i][:nc])
	next
	winner="PLAYER 1" wc=cP1Body
	if p2Score>p1Score
		if aiMode winner="CPU" else winner="PLAYER 2" ok
		wc=cP2Body
	ok
	t=winner+" WINS!" tw=MeasureText(t,52)
	DT(t,floor((C_SW-tw)/2)+2,floor(C_SH/2)-98,52,ncc(80,60,0,255))
	DT(t,floor((C_SW-tw)/2),floor(C_SH/2)-100,52,wc)
	t="Final: P1 "+p1Score+" - P2 "+p2Score tw=MeasureText(t,28)
	DT(t,floor((C_SW-tw)/2),floor(C_SH/2)-20,28,WHITE)
	t="Press ENTER" tw=MeasureText(t,18)
	if gATM%60<42 DT(t,floor((C_SW-tw)/2),floor(C_SH/2)+40,18,GRAY) ok

# ====================================================
# DRAWING
# ====================================================
func drwGame
	drwGrid()
	drwPUps()
	drwBullets()
	drwParts()
	if p1Alive drwTank(p1X,p1Y,p1Dir,cP1Body,cP1Turr,cP1Dk) ok
	if p2Alive drwTank(p2X,p2Y,p2Dir,cP2Body,cP2Turr,cP2Dk) ok
	drwFTs()
	drwHUD()

func drwGrid
	for r=1 to C_ROWS
		for c=1 to C_COLS
			x=(c-1)*C_TILE+C_OX
			y=(r-1)*C_TILE+C_OY
			t=grid[r][c]
			# Grass base
			if (r+c)%2=0
				DrawRectangle(x,y,C_TILE,C_TILE,cGrass1)
			else
				DrawRectangle(x,y,C_TILE,C_TILE,cGrass2)
			ok
			if t=T_WALL
				DrawRectangle(x,y,C_TILE,C_TILE,cWall)
				DrawRectangle(x+1,y+1,C_TILE-2,3,cWallLt)
				DrawRectangle(x+1,y+1,3,C_TILE-2,cWallLt)
				DrawRectangle(x+2,y+C_TILE-4,C_TILE-4,3,cWallDk)
				DrawRectangle(x+C_TILE-4,y+2,3,C_TILE-4,cWallDk)
			ok
			if t=T_BRICK
				DrawRectangle(x,y,C_TILE,C_TILE,cBrick)
				DrawRectangle(x+1,y+1,C_TILE-2,2,cBrickLt)
				DrawRectangle(x+C_TILE/2-1,y,2,C_TILE,cBrickDk)
				DrawRectangle(x,y+C_TILE/2-1,C_TILE,2,cBrickDk)
			ok
			if t=T_WATER
				DrawRectangle(x,y,C_TILE,C_TILE,cWater)
				if gATM%40<20
					DrawRectangle(x+4,y+8,12,3,cWaterLt)
					DrawRectangle(x+16,y+20,10,3,cWaterLt)
				else
					DrawRectangle(x+8,y+6,10,3,cWaterLt)
					DrawRectangle(x+12,y+18,12,3,cWaterLt)
				ok
			ok
			if t=T_TREE
				DrawRectangle(x,y,C_TILE,C_TILE,cGrass1)
				DrawCircle(x+C_TILE/2,y+C_TILE/2,12,cTree)
				DrawCircle(x+C_TILE/2-4,y+C_TILE/2-4,8,cTreeLt)
			ok
		next
	next

# ---- Power-ups ----
func drwPUps
	for i=1 to len(pups)
		if !pups[i][:on] loop ok
		px=(pups[i][:x]-1)*C_TILE+C_OX+C_TILE/2
		py=(pups[i][:y]-1)*C_TILE+C_OY+C_TILE/2
		if gATM%40<30
			pt=pups[i][:type]
			if pt=1 DrawCircle(px,py,10,cPUHeal)
				DrawRectangle(px-6,py-2,12,4,WHITE)
				DrawRectangle(px-2,py-6,4,12,WHITE) ok
			if pt=2 DrawCircle(px,py,10,cPUAmmo)
				DrawRectangle(px-2,py-6,4,12,WHITE) ok
			if pt=3 DrawCircle(px,py,10,cPUShld)
				DrawRectangle(px-6,py-2,12,4,WHITE) ok
		ok
	next

# ---- Tank Drawing ----
func drwTank x,y,dir,body,turr,dk
	rad=dir*3.14159/180
	cs=cos(rad) sn=sin(rad)

	# Body (rotated rectangle approximation)
	sz=TK_SZ
	DrawCircle(x,y,sz+2,dk)
	DrawCircle(x,y,sz,body)

	# Track marks
	lx=x+(-sn)*8 ly=y+(cs)*8
	rx=x-(-sn)*8 ry=y-(cs)*8
	DrawCircle(lx,ly,5,dk)
	DrawCircle(rx,ry,5,dk)

	# Turret
	DrawCircle(x,y,7,turr)

	# Barrel
	bx=x+cs*16 by=y+sn*16
	mx=x+cs*8 my=y+sn*8
	DrawCircle(mx,my,3,turr)
	DrawCircle(bx,by,3,turr)
	# Line between
	DrawCircle((mx+bx)/2,(my+by)/2,2,turr)

# ---- Bullets ----
func drwBullets
	for i=1 to len(bullets)
		DrawCircle(bullets[i][:x],bullets[i][:y],4,cBullet)
		DrawCircle(bullets[i][:x],bullets[i][:y],2,cBullet2)
	next

# ---- Particles ----
func drwParts
	for i=1 to len(parts)
		sz=3
		if parts[i][:life]<parts[i][:ml]/2 sz=2 ok
		DrawCircle(parts[i][:x],parts[i][:y],sz,parts[i][:nc])
	next

# ---- Floating Text ----
func drwFTs
	for i=1 to len(fts)
		DT(fts[i][:txt],floor(fts[i][:x]-20),floor(fts[i][:y]),16,cGold)
	next

# ---- HUD ----
func drwHUD
	DrawRectangle(0,0,C_SW,C_OY,cHUD)
	# Player 1
	DT("P1",10,4,16,cP1Body)
	DrawRectangle(40,6,80,12,cHPBg)
	if p1HP>0 DrawRectangle(40,6,floor(80*p1HP/p1MaxHP),12,cHP) ok
	DT(""+p1HP,125,4,16,WHITE)
	DT("Score:"+p1Score,170,4,16,cGold)

	# Player 2
	if aiMode DT("CPU",C_SW-270,4,16,cP2Body)
	else DT("P2",C_SW-260,4,16,cP2Body) ok
	DrawRectangle(C_SW-230,6,80,12,cHPBg)
	if p2HP>0 DrawRectangle(C_SW-230,6,floor(80*p2HP/p2MaxHP),12,cHP) ok
	DT(""+p2HP,C_SW-145,4,16,WHITE)
	DT("Score:"+p2Score,C_SW-100,4,16,cGold)

	# Round + mode
	md="" if aiMode md=" [vs AI]" ok
	t="Round "+gRound+"/"+gMaxRnd+md tw=MeasureText(t,18)
	DT(t,floor((C_SW-tw)/2),6,18,WHITE)

	# Shoot cooldown indicators
	if p1ShootT>0 DrawRectangle(40,22,floor(80*p1ShootT/TK_SHOOT_CD),8,cP1Dk) ok
	if p2ShootT>0 DrawRectangle(C_SW-230,22,floor(80*p2ShootT/TK_SHOOT_CD),8,cP2Dk) ok
