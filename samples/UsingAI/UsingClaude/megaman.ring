/*
	Ring Man - Mega Man Style Side-Scroller
	Ring + RayLib | Shooting, Boss Fights, Selectable Stages
*/

load "raylib.ring"

# Constants
C_SW=800 C_SH=600 C_TILE=32 C_FPS=60
C_GRAV=0.5 C_MAXF=10 C_SPD=3.0 C_JMP=-10.5
C_BSPD=7.0 C_MAXBUL=5

# States
S_MNU=0 S_SEL=1 S_PLY=2 S_DIE=3 S_OVR=4 S_BOSS=5 S_BDIE=6 S_WIN=7 S_STGC=8

# Tiles
T_E=0 T_SLD=1 T_SPK=2 T_PLAT=3 T_LADDER=4

# Entity types
EN_WALK=1 EN_FLY=2 EN_TURRET=3 EN_SHOOT=4

# Game data
GX=1 GY=2 GVX=3 GVY=4 GW=5 GH=6 GDIR=7 GGND=8
GLIV=9 GSCR=10 GFRM=11 GFTM=12 GST=13 GDTM=14
GATM=15 GJBF=16 GHP=17 GHPMAX=18 GCAM=19
GSTG=20 GINV=21 GSHTT=22 GBHP=23 GBHPM=24
GBST=25 GBATM=26 GBFRM=27 GBDIR=28 GBPAT=29
GFLSH=30 GBNAM=31

g=list(31)
g[GX]=60 g[GY]=0 g[GW]=24 g[GH]=32
g[GDIR]=1 g[GGND]=false g[GLIV]=3
g[GSCR]=0 g[GST]=S_MNU g[GDTM]=0 g[GATM]=0 g[GJBF]=0
g[GHP]=28 g[GHPMAX]=28 g[GCAM]=0
g[GSTG]=0 g[GINV]=0 g[GSHTT]=0
g[GBHP]=0 g[GBHPM]=40 g[GBST]=0 g[GBATM]=0
g[GBFRM]=0 g[GBDIR]=-1 g[GBPAT]=0 g[GFLSH]=0 g[GBNAM]=0

# Globals
lvl=[] ens=[] bullets=[] ebuls=[] pups=[] pts=[] fts=[] bks=[]
lvlW=0 lvlH=0
bossX=0 bossY=0 bossVX=0 bossVY=0 bossW=48 bossH=48

# Stage data: names
stgNames=["FIRE","ICE","ELEC","WIND"]
stgCleared=[false,false,false,false]
stgBossNames=["FLAME MAN","FROST MAN","VOLT MAN","GALE MAN"]

# Colors
cBlue    = cc(0,120,248,255)
cDBlue   = cc(0,80,168,255)
cLBlue   = cc(60,180,255,255)
cCyan    = cc(0,220,240,255)
cSkin    = cc(252,180,108,255)
cRed     = cc(229,37,33,255)
cDRed    = cc(160,20,20,255)
cOrange  = cc(240,140,40,255)
cDOrange = cc(200,100,20,255)
cYellow  = cc(251,208,0,255)
cGreen   = cc(0,180,0,255)
cDGreen  = cc(0,120,0,255)
cPurple  = cc(140,60,200,255)
cDPurple = cc(100,30,160,255)
cGray    = cc(160,160,160,255)
cDGray   = cc(100,100,100,255)
cLGray   = cc(200,200,200,255)
cBrown   = cc(160,82,45,255)
cDBrown  = cc(100,50,25,255)
cHUD     = cc(0,0,0,200)
cOverlay = cc(0,0,0,180)
cHPGreen = cc(0,200,0,255)
cHPRed   = cc(200,0,0,255)
cBullet  = cc(255,255,100,255)
cSpike   = cc(220,220,220,255)

# Stage-specific colors (set per stage)
cStgBG1  = cc(20,20,60,255)
cStgBG2  = cc(40,40,80,255)
cStgTile = cc(100,100,120,255)
cStgTile2= cc(80,80,100,255)
cStgPlat = cc(120,120,140,255)
cBossClr = cc(229,37,33,255)
cBossClr2= cc(160,20,20,255)

# ========== MAIN ==========
InitWindow(C_SW,C_SH,"Ring Man - Mega Man Style Platformer")
SetTargetFPS(C_FPS)

while !WindowShouldClose()
	switch g[GST]
	on S_MNU  updMenu(g)
	on S_SEL  updSelect(g)
	on S_PLY  updGame(g)
	on S_BOSS updBoss(g)
	on S_DIE  updDie(g)
	on S_OVR  updOver(g)
	on S_BDIE updBDie(g)
	on S_STGC updStgC(g)
	on S_WIN  updWin(g)
	off
	BeginDrawing()
	ClearBackground(cStgBG1)
	switch g[GST]
	on S_MNU  drwMenu(g)
	on S_SEL  drwSelect(g)
	on S_PLY  drwGame(g)
	on S_BOSS drwGame(g) drwBossHP(g)
	on S_DIE  drwGame(g) drwDieOvr(g)
	on S_OVR  drwOverScr(g)
	on S_BDIE drwGame(g) drwBDieEff(g)
	on S_STGC drwStgCScr(g)
	on S_WIN  drwWinScr(g)
	off
	EndDrawing()
end
CloseWindow()

# ====================================================
# FUNCTIONS
# ====================================================
func cc r,g,b,a
	c=new Color c.r=r c.g=g c.b=b c.a=a
	return c

func DT text,x,y,sz,color
	drawtext(text,x,y,sz,GPData(color))

func fabs v
	if v<0 return -v ok
	return v

# ---- Stage Colors ----
func setStgColors stg
	switch stg
	on 1 # Fire
		cStgBG1=cc(40,10,10,255) cStgBG2=cc(80,20,20,255)
		cStgTile=cc(140,60,30,255) cStgTile2=cc(100,40,20,255)
		cStgPlat=cc(160,80,40,255)
		cBossClr=cc(255,80,0,255) cBossClr2=cc(200,40,0,255)
	on 2 # Ice
		cStgBG1=cc(10,20,50,255) cStgBG2=cc(20,40,80,255)
		cStgTile=cc(140,180,220,255) cStgTile2=cc(100,140,180,255)
		cStgPlat=cc(160,200,240,255)
		cBossClr=cc(100,180,255,255) cBossClr2=cc(60,120,200,255)
	on 3 # Electric
		cStgBG1=cc(20,20,40,255) cStgBG2=cc(40,40,60,255)
		cStgTile=cc(80,80,120,255) cStgTile2=cc(60,60,100,255)
		cStgPlat=cc(100,100,140,255)
		cBossClr=cc(255,255,0,255) cBossClr2=cc(200,200,0,255)
	on 4 # Wind
		cStgBG1=cc(20,40,20,255) cStgBG2=cc(40,60,40,255)
		cStgTile=cc(80,140,80,255) cStgTile2=cc(60,110,60,255)
		cStgPlat=cc(100,160,100,255)
		cBossClr=cc(100,220,100,255) cBossClr2=cc(60,160,60,255)
	off

# ---- Level Building ----
func buildStage g, stg
	setStgColors(stg)
	ens=[] bullets=[] ebuls=[] pups=[] pts=[] fts=[] bks=[]
	g[GCAM]=0 g[GGND]=false g[GINV]=0 g[GSHTT]=0
	g[GHP]=g[GHPMAX] g[GSTG]=stg
	g[GBST]=0 g[GBATM]=0 g[GFLSH]=0

	switch stg
	on 1 bldFire(g)
	on 2 bldIce(g)
	on 3 bldElec(g)
	on 4 bldWind(g)
	off
	g[GY]=(lvlH-3)*C_TILE

func bldFire g
	lvlW=120 lvlH=19
	lvl=list(lvlH,lvlW)
	for r=1 to lvlH for c=1 to lvlW lvl[r][c]=T_E next next
	# Ground
	for c=1 to lvlW lvl[lvlH][c]=T_SLD lvl[lvlH-1][c]=T_SLD next
	# Gaps (narrow - 3 tiles max)
	for c=15 to 17 lvl[lvlH][c]=T_E lvl[lvlH-1][c]=T_E next
	for c=35 to 37 lvl[lvlH][c]=T_E lvl[lvlH-1][c]=T_E next
	for c=35 to 37 lvl[lvlH][c]=T_SPK next
	for c=55 to 57 lvl[lvlH][c]=T_E lvl[lvlH-1][c]=T_E next
	for c=80 to 82 lvl[lvlH][c]=T_E lvl[lvlH-1][c]=T_E next
	for c=80 to 82 lvl[lvlH][c]=T_SPK next
	# Platforms - connected flow, max 4 tile gaps, stepping heights
	for c=14 to 19 lvl[lvlH-4][c]=T_PLAT next
	for c=22 to 28 lvl[lvlH-4][c]=T_SLD next
	for c=30 to 35 lvl[lvlH-6][c]=T_PLAT next
	for c=38 to 44 lvl[lvlH-4][c]=T_SLD next
	for c=46 to 52 lvl[lvlH-5][c]=T_PLAT next
	for c=53 to 58 lvl[lvlH-4][c]=T_PLAT next
	for c=60 to 68 lvl[lvlH-5][c]=T_SLD next
	for c=70 to 76 lvl[lvlH-4][c]=T_PLAT next
	for c=78 to 84 lvl[lvlH-5][c]=T_SLD next
	for c=86 to 92 lvl[lvlH-4][c]=T_PLAT next
	for c=94 to 100 lvl[lvlH-4][c]=T_PLAT next
	# Walls
	for r=lvlH-6 to lvlH-2 lvl[r][69]=T_SLD next
	# Boss room (end)
	for r=1 to lvlH lvl[r][lvlW]=T_SLD lvl[r][lvlW-1]=T_SLD next
	for r=1 to lvlH-2 lvl[r][104]=T_SLD next
	# Enemies
	addEn(10,lvlH-3,EN_WALK) addEn(20,lvlH-3,EN_WALK)
	addEn(25,lvlH-6,EN_WALK)
	addEn(42,lvlH-7,EN_WALK)
	addEn(50,lvlH-9,EN_FLY) addEn(56,lvlH-6,EN_WALK)
	addEn(65,lvlH-8,EN_TURRET) addEn(76,lvlH-6,EN_SHOOT)
	addEn(88,lvlH-7,EN_WALK) addEn(92,lvlH-3,EN_WALK)
	addEn(97,lvlH-6,EN_FLY)
	# Power-ups
	addPUp(24,lvlH-6,1) addPUp(64,lvlH-8,2) addPUp(96,lvlH-6,1)
	# Player start
	g[GX]=60 g[GY]=(lvlH-3)*C_TILE

func bldIce g
	lvlW=110 lvlH=19
	lvl=list(lvlH,lvlW)
	for r=1 to lvlH for c=1 to lvlW lvl[r][c]=T_E next next
	for c=1 to lvlW lvl[lvlH][c]=T_SLD lvl[lvlH-1][c]=T_SLD next
	for c=18 to 20 lvl[lvlH][c]=T_E lvl[lvlH-1][c]=T_E next
	for c=42 to 44 lvl[lvlH][c]=T_E lvl[lvlH-1][c]=T_E next
	for c=42 to 44 lvl[lvlH][c]=T_SPK next
	for c=65 to 67 lvl[lvlH][c]=T_E lvl[lvlH-1][c]=T_E next
	# Platforms - stepping, max 3-4 gap
	for c=16 to 22 lvl[lvlH-4][c]=T_PLAT next
	for c=24 to 30 lvl[lvlH-5][c]=T_SLD next
	for c=32 to 38 lvl[lvlH-4][c]=T_PLAT next
	for c=40 to 45 lvl[lvlH-5][c]=T_PLAT next
	for c=47 to 53 lvl[lvlH-4][c]=T_SLD next
	for c=55 to 60 lvl[lvlH-5][c]=T_PLAT next
	for c=62 to 68 lvl[lvlH-4][c]=T_PLAT next
	for c=70 to 76 lvl[lvlH-5][c]=T_SLD next
	for c=78 to 84 lvl[lvlH-4][c]=T_PLAT next
	for c=86 to 90 lvl[lvlH-4][c]=T_PLAT next
	for r=1 to lvlH lvl[r][lvlW]=T_SLD lvl[r][lvlW-1]=T_SLD next
	for r=1 to lvlH-2 lvl[r][95]=T_SLD next
	addEn(12,lvlH-3,EN_WALK) addEn(28,lvlH-8,EN_WALK)
	addEn(36,lvlH-6,EN_SHOOT) addEn(48,lvlH-7,EN_FLY)
	addEn(55,lvlH-9,EN_TURRET) addEn(63,lvlH-6,EN_WALK)
	addEn(74,lvlH-8,EN_WALK) addEn(78,lvlH-8,EN_SHOOT)
	addEn(86,lvlH-6,EN_FLY)
	addPUp(27,lvlH-8,1) addPUp(54,lvlH-9,2) addPUp(85,lvlH-6,1)
	g[GX]=60 g[GY]=(lvlH-3)*C_TILE

func bldElec g
	lvlW=115 lvlH=19
	lvl=list(lvlH,lvlW)
	for r=1 to lvlH for c=1 to lvlW lvl[r][c]=T_E next next
	for c=1 to lvlW lvl[lvlH][c]=T_SLD lvl[lvlH-1][c]=T_SLD next
	for c=20 to 22 lvl[lvlH][c]=T_E lvl[lvlH-1][c]=T_E next
	for c=50 to 52 lvl[lvlH][c]=T_E lvl[lvlH-1][c]=T_E next
	for c=50 to 52 lvl[lvlH][c]=T_SPK next
	for c=75 to 77 lvl[lvlH][c]=T_E lvl[lvlH-1][c]=T_E next
	for c=12 to 18 lvl[lvlH-4][c]=T_PLAT next
	for c=20 to 26 lvl[lvlH-4][c]=T_PLAT next
	for c=28 to 35 lvl[lvlH-5][c]=T_SLD next
	for c=37 to 43 lvl[lvlH-4][c]=T_PLAT next
	for c=45 to 50 lvl[lvlH-5][c]=T_PLAT next
	for c=52 to 58 lvl[lvlH-4][c]=T_SLD next
	for c=60 to 66 lvl[lvlH-5][c]=T_PLAT next
	for c=68 to 74 lvl[lvlH-4][c]=T_PLAT next
	for c=76 to 82 lvl[lvlH-4][c]=T_SLD next
	for c=84 to 90 lvl[lvlH-5][c]=T_PLAT next
	for c=92 to 96 lvl[lvlH-4][c]=T_PLAT next
	for r=1 to lvlH lvl[r][lvlW]=T_SLD lvl[r][lvlW-1]=T_SLD next
	for r=1 to lvlH-2 lvl[r][100]=T_SLD next
	addEn(10,lvlH-3,EN_WALK) addEn(14,lvlH-7,EN_FLY)
	addEn(30,lvlH-8,EN_TURRET) addEn(40,lvlH-6,EN_WALK)
	addEn(46,lvlH-9,EN_SHOOT) addEn(57,lvlH-7,EN_WALK)
	addEn(66,lvlH-9,EN_FLY) addEn(76,lvlH-6,EN_WALK)
	addEn(85,lvlH-8,EN_TURRET) addEn(90,lvlH-3,EN_SHOOT)
	addPUp(13,lvlH-7,1) addPUp(56,lvlH-7,2) addPUp(84,lvlH-8,1)
	g[GX]=60 g[GY]=(lvlH-3)*C_TILE

func bldWind g
	lvlW=125 lvlH=19
	lvl=list(lvlH,lvlW)
	for r=1 to lvlH for c=1 to lvlW lvl[r][c]=T_E next next
	for c=1 to lvlW lvl[lvlH][c]=T_SLD lvl[lvlH-1][c]=T_SLD next
	for c=22 to 24 lvl[lvlH][c]=T_E lvl[lvlH-1][c]=T_E next
	for c=48 to 50 lvl[lvlH][c]=T_E lvl[lvlH-1][c]=T_E next
	for c=72 to 74 lvl[lvlH][c]=T_E lvl[lvlH-1][c]=T_E next
	for c=72 to 74 lvl[lvlH][c]=T_SPK next
	for c=95 to 97 lvl[lvlH][c]=T_E lvl[lvlH-1][c]=T_E next
	for c=10 to 16 lvl[lvlH-4][c]=T_PLAT next
	for c=18 to 24 lvl[lvlH-4][c]=T_PLAT next
	for c=26 to 33 lvl[lvlH-5][c]=T_SLD next
	for c=35 to 41 lvl[lvlH-4][c]=T_PLAT next
	for c=43 to 49 lvl[lvlH-5][c]=T_PLAT next
	for c=51 to 57 lvl[lvlH-4][c]=T_SLD next
	for c=59 to 65 lvl[lvlH-5][c]=T_PLAT next
	for c=67 to 73 lvl[lvlH-4][c]=T_PLAT next
	for c=75 to 82 lvl[lvlH-5][c]=T_SLD next
	for c=84 to 90 lvl[lvlH-4][c]=T_PLAT next
	for c=92 to 98 lvl[lvlH-4][c]=T_PLAT next
	for c=100 to 108 lvl[lvlH-5][c]=T_PLAT next
	for r=1 to lvlH lvl[r][lvlW]=T_SLD lvl[r][lvlW-1]=T_SLD next
	for r=1 to lvlH-2 lvl[r][112]=T_SLD next
	addEn(8,lvlH-3,EN_WALK) addEn(22,lvlH-8,EN_FLY)
	addEn(33,lvlH-7,EN_WALK) addEn(36,lvlH-7,EN_SHOOT)
	addEn(44,lvlH-9,EN_TURRET) addEn(54,lvlH-6,EN_WALK)
	addEn(63,lvlH-8,EN_FLY) addEn(67,lvlH-8,EN_SHOOT)
	addEn(82,lvlH-9,EN_TURRET) addEn(86,lvlH-9,EN_WALK)
	addEn(94,lvlH-6,EN_WALK) addEn(104,lvlH-8,EN_FLY)
	addPUp(32,lvlH-7,1) addPUp(62,lvlH-8,2)
	addPUp(93,lvlH-6,1) addPUp(103,lvlH-8,2)
	g[GX]=60 g[GY]=(lvlH-3)*C_TILE

# ---- Object Creators ----
func addEn col,row,type
	spd=1.5
	if type=EN_FLY spd=1.0 ok
	if type=EN_TURRET spd=0 ok
	if type=EN_SHOOT spd=0.8 ok
	add(ens,[:x=col*C_TILE,:y=row*C_TILE,:vx=-spd,:vy=0,
		:w=28,:h=28,:type=type,:hp=3,:alive=true,
		:frame=0,:ft=0,:stmr=0,:fltY=row*C_TILE,:fltA=0])

func addPUp col,row,type
	# type 1=health, 2=extra life
	add(pups,[:x=col*C_TILE,:y=row*C_TILE,:w=20,:h=20,:type=type,:on=true])

func addPt x,y,vx,vy,nc,life
	add(pts,[:x=x,:y=y,:vx=vx,:vy=vy,:nc=nc,:life=life])

func addFT x,y,txt
	add(fts,[:x=x,:y=y,:txt=txt,:tmr=50])

# ---- Boss Setup ----
func setupBoss g, stg
	g[GST]=S_BOSS
	bossX=(lvlW-6)*C_TILE
	bossY=(lvlH-4)*C_TILE
	bossVX=-2 bossVY=0
	g[GBHP]=g[GBHPM]
	g[GBST]=1 g[GBATM]=0 g[GBPAT]=0
	g[GBNAM]=stg
	g[GBDIR]=-1

# ---- Menu ----
func updMenu g
	g[GATM]++
	if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE)
		g[GST]=S_SEL g[GLIV]=3 g[GSCR]=0 g[GHP]=g[GHPMAX]
		for i=1 to 4 stgCleared[i]=false next
	ok

func drwMenu g
	ClearBackground(BLACK)
	t="RING MAN" tw=MeasureText(t,64)
	DT(t,floor((C_SW-tw)/2)+3,63,64,cDBlue)
	DT(t,floor((C_SW-tw)/2),60,64,cLBlue)
	t="Mega Man Style Action" tw=MeasureText(t,22)
	DT(t,floor((C_SW-tw)/2),135,22,cYellow)
	# Draw hero
	drwHero(C_SW/2-12,220,1,0,g)
	t="Press ENTER to Start" tw=MeasureText(t,20)
	if g[GATM]%60<42 DT(t,floor((C_SW-tw)/2),340,20,WHITE) ok
	DT("Controls:",280,400,18,cYellow)
	DT("Arrow / WASD - Move",280,425,16,WHITE)
	DT("Space        - Jump",280,445,16,WHITE)
	DT("X / J        - Shoot",280,465,16,WHITE)
	DT("4 Stages + Boss Fights!",280,500,16,cCyan)
	DT("Made with Ring Language + RayLib",240,570,16,GRAY)

# ---- Stage Select ----
func updSelect g
	g[GATM]++
	if IsKeyPressed(KEY_ONE) or IsKeyPressed(KEY_KP_1) selStg(g,1) ok
	if IsKeyPressed(KEY_TWO) or IsKeyPressed(KEY_KP_2) selStg(g,2) ok
	if IsKeyPressed(KEY_THREE) or IsKeyPressed(KEY_KP_3) selStg(g,3) ok
	if IsKeyPressed(KEY_FOUR) or IsKeyPressed(KEY_KP_4) selStg(g,4) ok

func selStg g,num
	if stgCleared[num] return ok
	buildStage(g,num)
	g[GST]=S_PLY

func drwSelect g
	ClearBackground(cc(10,10,30,255))
	t="SELECT STAGE" tw=MeasureText(t,42)
	DT(t,floor((C_SW-tw)/2),40,42,cLBlue)
	# 4 stage boxes in 2x2 grid
	for i=1 to 4
		if i<=2 bx=150+(i-1)*280 by=130
		else bx=150+(i-3)*280 by=320 ok
		if stgCleared[i]
			DrawRectangle(bx,by,200,140,cDGray)
			DrawRectangleLines(bx,by,200,140,cGray)
			DT("CLEARED",bx+55,by+55,20,cGreen)
		else
			switch i
			on 1 bc=cc(200,60,20,255)
			on 2 bc=cc(40,100,200,255)
			on 3 bc=cc(200,200,40,255)
			on 4 bc=cc(40,180,60,255)
			off
			DrawRectangle(bx,by,200,140,bc)
			DrawRectangleLines(bx,by,200,140,WHITE)
			DT(""+i,bx+90,by+15,36,WHITE)
			DT(stgNames[i],bx+65,by+60,28,WHITE)
			DT(stgBossNames[i],bx+40,by+100,18,cYellow)
		ok
	next
	DT("Press 1-4 to select stage",260,510,18,cGray)
	cleared=0
	for i=1 to 4 if stgCleared[i] cleared++ ok next
	if cleared=4
		DT("ALL STAGES CLEARED!",260,540,20,cYellow)
	ok

# ---- Game Update ----
func updGame g
	g[GATM]++
	if g[GJBF]>0 g[GJBF]-- ok
	if g[GSHTT]>0 g[GSHTT]-- ok
	if g[GINV]>0 g[GINV]-- ok
	if g[GFLSH]>0 g[GFLSH]-- ok
	updPlayer(g)
	updBullets(g)
	updEBuls(g)
	updEns(g)
	updPUps(g)
	updPts()
	updFTs()
	gameCamUpd(g)
	# Check enter boss room
	if g[GX]>=(lvlW-8)*C_TILE and g[GBST]=0
		setupBoss(g,g[GSTG])
	ok
	if g[GY]>lvlH*C_TILE+50 pDie(g) ok

# ---- Boss Update ----
func updBoss g
	g[GATM]++
	if g[GJBF]>0 g[GJBF]-- ok
	if g[GSHTT]>0 g[GSHTT]-- ok
	if g[GINV]>0 g[GINV]-- ok
	if g[GFLSH]>0 g[GFLSH]-- ok
	updPlayer(g)
	updBullets(g)
	updEBuls(g)
	updPts()
	updFTs()
	gameCamUpd(g)
	# Boss AI
	g[GBATM]++
	updBossAI(g)
	chkBossBulCol(g)
	chkBossPlCol(g)
	if g[GY]>lvlH*C_TILE+50 pDie(g) ok

func updBossAI g
	# Movement pattern
	g[GBPAT]++
	# Jump periodically
	if g[GBPAT]%120=0
		bossVY=-8
	ok
	# Move toward player
	if g[GX]+g[GW]/2<bossX+bossW/2
		bossVX=-1.8 g[GBDIR]=-1
	else
		bossVX=1.8 g[GBDIR]=1
	ok
	# Reverse sometimes
	if g[GBPAT]%90<20 bossVX=-bossVX ok
	# Gravity
	bossVY+=C_GRAV
	if bossVY>C_MAXF bossVY=C_MAXF ok
	bossX+=bossVX bossY+=bossVY
	# Floor
	frow=floor((bossY+bossH)/C_TILE)+1
	if frow>=1 and frow<=lvlH
		lc=floor(bossX/C_TILE)+1 rc=floor((bossX+bossW-1)/C_TILE)+1
		for c=lc to rc
			if c>=1 and c<=lvlW
				if lvl[frow][c]=T_SLD
					bossY=(frow-1)*C_TILE-bossH bossVY=0
				ok
			ok
		next
	ok
	# Walls
	if bossX<(lvlW-10)*C_TILE bossX=(lvlW-10)*C_TILE ok
	if bossX+bossW>(lvlW-1)*C_TILE bossX=(lvlW-1)*C_TILE-bossW ok
	# Shoot
	if g[GBATM]%45=0
		dir=1
		if g[GX]<bossX dir=-1 ok
		add(ebuls,[:x=bossX+bossW/2,:y=bossY+20,:vx=5*dir,:vy=0,:life=200,:big=true])
	ok
	# Stage-specific attacks
	if g[GSTG]=1 and g[GBATM]%90=0
		# Fire spread
		for a=-2 to 2
			add(ebuls,[:x=bossX+bossW/2,:y=bossY+10,:vx=3*a,:vy=-4,:life=80,:big=false])
		next
	ok
	if g[GSTG]=3 and g[GBATM]%60=0
		# Electric bolts
		add(ebuls,[:x=bossX+bossW/2,:y=bossY,:vx=0,:vy=-6,:life=100,:big=true])
	ok

func chkBossBulCol g
	for i=len(bullets) to 1 step -1
		bx=bullets[i][:x] by=bullets[i][:y]
		if rOvr(bx-4,by-4,8,8,bossX,bossY,bossW,bossH)
			del(bullets,i)
			g[GBHP]-=2
			g[GFLSH]=6
			for j=1 to 3
				addPt(bx,by,GetRandomValue(-3,3),GetRandomValue(-3,1),cBossClr,15)
			next
			if g[GBHP]<=0
				g[GST]=S_BDIE g[GDTM]=120
				g[GSCR]+=5000
			ok
		ok
	next

func chkBossPlCol g
	if g[GINV]>0 return ok
	if rOvr(g[GX],g[GY],g[GW],g[GH],bossX,bossY,bossW,bossH)
		g[GHP]-=4
		g[GINV]=60
		if g[GHP]<=0 pDie(g) ok
	ok

# ---- Player ----
func updPlayer g
	ml=IsKeyDown(KEY_LEFT) or IsKeyDown(KEY_A)
	mr=IsKeyDown(KEY_RIGHT) or IsKeyDown(KEY_D)
	jkP=IsKeyPressed(KEY_SPACE) or IsKeyPressed(KEY_W) or IsKeyPressed(KEY_UP)
	sht=IsKeyPressed(KEY_X) or IsKeyPressed(KEY_J)

	if jkP g[GJBF]=6 ok

	if ml g[GVX]=-C_SPD g[GDIR]=-1
	but mr g[GVX]=C_SPD g[GDIR]=1
	else g[GVX]=0 ok

	if g[GJBF]>0 and g[GGND]
		g[GVY]=C_JMP g[GGND]=false g[GJBF]=0
	ok
	g[GVY]+=C_GRAV
	if g[GVY]>C_MAXF g[GVY]=C_MAXF ok

	# Anim
	if g[GVX]!=0 and g[GGND]
		g[GFTM]++
		if g[GFTM]>5
			g[GFTM]=0 g[GFRM]++
			if g[GFRM]>3 g[GFRM]=0 ok
		ok
	else
		if g[GGND] g[GFRM]=0 ok
	ok

	g[GX]+=g[GVX] resH(g)
	g[GY]+=g[GVY] resV(g)
	if g[GX]<g[GCAM] g[GX]=g[GCAM] ok

	# Shoot
	if sht and g[GSHTT]<=0 and len(bullets)<C_MAXBUL
		bx=g[GX]+g[GW]/2
		if g[GDIR]=1 bx=g[GX]+g[GW] ok
		if g[GDIR]=-1 bx=g[GX]-4 ok
		add(bullets,[:x=bx,:y=g[GY]+12,:vx=C_BSPD*g[GDIR],:vy=0,:life=60])
		g[GSHTT]=10
	ok

# ---- Collision ----
func resH g
	px=g[GX] py=g[GY] pw=g[GW] ph=g[GH]
	sc=floor(px/C_TILE)+1 ec=floor((px+pw-1)/C_TILE)+1
	sr=floor(py/C_TILE)+1 er=floor((py+ph-1)/C_TILE)+1
	for r=sr to er
		for c=sc to ec
			if r>=1 and r<=lvlH and c>=1 and c<=lvlW
				if lvl[r][c]=T_SLD
					tx=(c-1)*C_TILE
					if rOvr(px,py,pw,ph,tx,(r-1)*C_TILE,C_TILE,C_TILE)
						if g[GVX]>0 g[GX]=tx-pw
						but g[GVX]<0 g[GX]=tx+C_TILE
						ok
						g[GVX]=0 return
					ok
				ok
			ok
		next
	next

func resV g
	px=g[GX] py=g[GY] pw=g[GW] ph=g[GH]
	sc=floor(px/C_TILE)+1 ec=floor((px+pw-1)/C_TILE)+1
	sr=floor(py/C_TILE)+1 er=floor((py+ph-1)/C_TILE)+1
	g[GGND]=false
	for r=sr to er
		for c=sc to ec
			if r>=1 and r<=lvlH and c>=1 and c<=lvlW
				t=lvl[r][c]
				if t=T_SLD or (t=T_PLAT and g[GVY]>0)
					ty=(r-1)*C_TILE
					if t=T_PLAT
						if py+ph>=ty and py+ph<=ty+8 and g[GVY]>=0
							g[GY]=ty-ph g[GVY]=0 g[GGND]=true
							return
						ok
					else
						if rOvr(px,py,pw,ph,(c-1)*C_TILE,ty,C_TILE,C_TILE)
							if g[GVY]>0
								g[GY]=ty-ph g[GVY]=0 g[GGND]=true
							but g[GVY]<0
								g[GY]=ty+C_TILE g[GVY]=1
							ok
							return
						ok
					ok
				ok
				if t=T_SPK
					if rOvr(px,py,pw,ph,(c-1)*C_TILE,(r-1)*C_TILE+16,C_TILE,16)
						pDie(g) return
					ok
				ok
			ok
		next
	next

# ---- Bullets ----
func updBullets g
	for i=len(bullets) to 1 step -1
		bullets[i][:x]+=bullets[i][:vx]
		bullets[i][:y]+=bullets[i][:vy]
		bullets[i][:life]--
		bx=bullets[i][:x] by=bullets[i][:y]
		# Wall check
		bc=floor(bx/C_TILE)+1 br=floor(by/C_TILE)+1
		hit=false
		if bc>=1 and bc<=lvlW and br>=1 and br<=lvlH
			if lvl[br][bc]=T_SLD hit=true ok
		ok
		if hit or bullets[i][:life]<=0 or bx<g[GCAM]-50 or bx>g[GCAM]+C_SW+50
			if hit
				for j=1 to 3
					addPt(bx,by,GetRandomValue(-2,2),GetRandomValue(-2,1),cBullet,10)
				next
			ok
			del(bullets,i)
		else
			# Enemy hit check
			for j=len(ens) to 1 step -1
				if ens[j][:alive]
					if rOvr(bx-4,by-4,8,8,ens[j][:x],ens[j][:y],ens[j][:w],ens[j][:h])
						ens[j][:hp]-=1
						del(bullets,i)
						if ens[j][:hp]<=0
							ens[j][:alive]=false
							g[GSCR]+=200
							addFT(ens[j][:x],ens[j][:y]-10,"200")
							for k=1 to 5
								addPt(ens[j][:x]+14,ens[j][:y]+14,
									GetRandomValue(-3,3),GetRandomValue(-4,0),cYellow,20)
							next
						else
							for k=1 to 2
								addPt(bx,by,GetRandomValue(-2,2),GetRandomValue(-2,1),WHITE,8)
							next
						ok
						exit
					ok
				ok
			next
		ok
	next

func updEBuls g
	for i=len(ebuls) to 1 step -1
		ebuls[i][:x]+=ebuls[i][:vx]
		ebuls[i][:y]+=ebuls[i][:vy]
		if !ebuls[i][:big] ebuls[i][:vy]+=0.15 ok
		ebuls[i][:life]--
		bx=ebuls[i][:x] by=ebuls[i][:y]
		if ebuls[i][:life]<=0 or bx<g[GCAM]-100 or bx>g[GCAM]+C_SW+100 or by>C_SH+50
			del(ebuls,i)
		else
			if g[GINV]<=0
				if rOvr(g[GX],g[GY],g[GW],g[GH],bx-6,by-6,12,12)
					g[GHP]-=3
					g[GINV]=45
					del(ebuls,i)
					if g[GHP]<=0 pDie(g) ok
				ok
			ok
		ok
	next

# ---- Enemies ----
func updEns g
	for i=1 to len(ens)
		if !ens[i][:alive] loop ok
		ex=ens[i][:x] ey=ens[i][:y]
		if ex<g[GCAM]-200 or ex>g[GCAM]+C_SW+300 loop ok

		ens[i][:ft]++
		if ens[i][:ft]>10
			ens[i][:ft]=0 ens[i][:frame]=1-ens[i][:frame]
		ok

		et=ens[i][:type]
		if et=EN_WALK
			ens[i][:x]+=ens[i][:vx]
			ens[i][:vy]+=C_GRAV
			if ens[i][:vy]>C_MAXF ens[i][:vy]=C_MAXF ok
			ens[i][:y]+=ens[i][:vy]
			# Floor
			frow=floor((ens[i][:y]+ens[i][:h])/C_TILE)+1
			if frow>=1 and frow<=lvlH
				ec=floor((ens[i][:x]+14)/C_TILE)+1
				if ec>=1 and ec<=lvlW
					if lvl[frow][ec]=T_SLD
						ens[i][:y]=(frow-1)*C_TILE-ens[i][:h]
						ens[i][:vy]=0
					ok
				ok
			ok
			# Wall
			if ens[i][:vx]>0 wc=floor((ens[i][:x]+ens[i][:w])/C_TILE)+1
			else wc=floor(ens[i][:x]/C_TILE)+1 ok
			wr=floor((ens[i][:y]+14)/C_TILE)+1
			if wc>=1 and wc<=lvlW and wr>=1 and wr<=lvlH
				if lvl[wr][wc]=T_SLD ens[i][:vx]=-ens[i][:vx] ok
			ok
		ok
		if et=EN_FLY
			ens[i][:fltA]+=0.03
			ens[i][:y]=ens[i][:fltY]+sin(ens[i][:fltA])*30
			ens[i][:x]+=ens[i][:vx]
			if ens[i][:x]<(floor(ex/C_TILE)-8)*C_TILE ens[i][:vx]=-ens[i][:vx] ok
			if ens[i][:x]>(floor(ex/C_TILE)+8)*C_TILE ens[i][:vx]=-ens[i][:vx] ok
		ok
		if et=EN_TURRET
			ens[i][:stmr]++
			if ens[i][:stmr]>=80
				ens[i][:stmr]=0
				dir=1
				if g[GX]<ens[i][:x] dir=-1 ok
				add(ebuls,[:x=ens[i][:x]+14,:y=ens[i][:y]+10,:vx=4*dir,:vy=0,:life=120,:big=false])
			ok
		ok
		if et=EN_SHOOT
			ens[i][:x]+=ens[i][:vx]
			ens[i][:vy]+=C_GRAV
			if ens[i][:vy]>C_MAXF ens[i][:vy]=C_MAXF ok
			ens[i][:y]+=ens[i][:vy]
			frow=floor((ens[i][:y]+ens[i][:h])/C_TILE)+1
			if frow>=1 and frow<=lvlH
				ec=floor((ens[i][:x]+14)/C_TILE)+1
				if ec>=1 and ec<=lvlW
					if lvl[frow][ec]=T_SLD
						ens[i][:y]=(frow-1)*C_TILE-ens[i][:h]
						ens[i][:vy]=0
					ok
				ok
			ok
			if ens[i][:vx]>0 wc=floor((ens[i][:x]+ens[i][:w])/C_TILE)+1
			else wc=floor(ens[i][:x]/C_TILE)+1 ok
			wr=floor((ens[i][:y]+14)/C_TILE)+1
			if wc>=1 and wc<=lvlW and wr>=1 and wr<=lvlH
				if lvl[wr][wc]=T_SLD ens[i][:vx]=-ens[i][:vx] ok
			ok
			ens[i][:stmr]++
			if ens[i][:stmr]>=100
				ens[i][:stmr]=0
				dir=1
				if g[GX]<ens[i][:x] dir=-1 ok
				add(ebuls,[:x=ens[i][:x]+14,:y=ens[i][:y]+10,:vx=4*dir,:vy=-1,:life=100,:big=false])
			ok
		ok
		# Player touch damage
		if g[GINV]<=0
			if rOvr(g[GX],g[GY],g[GW],g[GH],ens[i][:x],ens[i][:y],ens[i][:w],ens[i][:h])
				g[GHP]-=3
				g[GINV]=45
				if g[GHP]<=0 pDie(g) ok
			ok
		ok
	next

# ---- Power-ups ----
func updPUps g
	for i=1 to len(pups)
		if !pups[i][:on] loop ok
		if rOvr(g[GX],g[GY],g[GW],g[GH],pups[i][:x],pups[i][:y],pups[i][:w],pups[i][:h])
			pups[i][:on]=false
			if pups[i][:type]=1
				g[GHP]+=10
				if g[GHP]>g[GHPMAX] g[GHP]=g[GHPMAX] ok
				addFT(pups[i][:x],pups[i][:y]-10,"HP+")
			but pups[i][:type]=2
				g[GLIV]++
				addFT(pups[i][:x],pups[i][:y]-10,"1UP!")
			ok
			g[GSCR]+=100
		ok
	next

# ---- Effects ----
func updPts
	for i=len(pts) to 1 step -1
		pts[i][:x]+=pts[i][:vx] pts[i][:y]+=pts[i][:vy]
		pts[i][:vy]+=0.15 pts[i][:life]--
		if pts[i][:life]<=0 del(pts,i) ok
	next

func updFTs
	for i=len(fts) to 1 step -1
		fts[i][:y]-=1 fts[i][:tmr]--
		if fts[i][:tmr]<=0 del(fts,i) ok
	next

# ---- Camera ----
func gameCamUpd g
	g[GCAM]=g[GX]-C_SW/3
	if g[GCAM]<0 g[GCAM]=0 ok
	mx=lvlW*C_TILE-C_SW
	if mx<0 mx=0 ok
	if g[GCAM]>mx g[GCAM]=mx ok

# ---- States ----
func pDie g
	g[GLIV]-- g[GDTM]=90 g[GST]=S_DIE

func updDie g
	g[GATM]++ g[GDTM]--
	if g[GDTM]<=0
		if g[GLIV]<=0 g[GST]=S_OVR
		else g[GST]=S_PLY buildStage(g,g[GSTG]) ok
	ok

func updOver g
	g[GATM]++
	if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE) g[GST]=S_MNU ok

func updBDie g
	g[GATM]++ g[GDTM]--
	if g[GDTM]>0
		# Explosion particles
		if g[GDTM]%4=0
			for k=1 to 6
				addPt(bossX+GetRandomValue(0,bossW),bossY+GetRandomValue(0,bossH),
					GetRandomValue(-4,4),GetRandomValue(-5,1),cBossClr,25)
			next
		ok
	else
		stgCleared[g[GSTG]]=true
		g[GST]=S_STGC g[GDTM]=120
		# Check all cleared
	ok

func updStgC g
	g[GATM]++ g[GDTM]--
	if g[GDTM]<=0
		cleared=0
		for i=1 to 4 if stgCleared[i] cleared++ ok next
		if cleared>=4 g[GST]=S_WIN
		else g[GST]=S_SEL ok
	ok

func updWin g
	g[GATM]++
	if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE) g[GST]=S_MNU ok

# ====================================================
# DRAWING
# ====================================================
func drwGame g
	cx=g[GCAM]
	# BG
	drwBG(g)
	# Tiles
	sc=floor(cx/C_TILE) ec=sc+(C_SW/C_TILE)+2
	for r=1 to lvlH
		for c=sc to ec
			col=c+1
			if col>=1 and col<=lvlW
				t=lvl[r][col]
				if t!=T_E
					drwTile(t,(col-1)*C_TILE-cx,(r-1)*C_TILE)
				ok
			ok
		next
	next
	# Power-ups
	for i=1 to len(pups)
		if !pups[i][:on] loop ok
		dx=pups[i][:x]-cx
		if dx>-40 and dx<C_SW+40
			drwPUp(dx,pups[i][:y],pups[i][:type],g)
		ok
	next
	# Enemies
	for i=1 to len(ens)
		if !ens[i][:alive] loop ok
		dx=ens[i][:x]-cx
		if dx>-60 and dx<C_SW+60
			drwEnemy(dx,ens[i][:y],ens[i][:type],ens[i][:frame],g)
		ok
	next
	# Boss
	if g[GST]=S_BOSS or g[GST]=S_BDIE
		drwBossSprite(bossX-cx,bossY,g)
	ok
	# Bullets
	for i=1 to len(bullets)
		bx=bullets[i][:x]-cx by=bullets[i][:y]
		DrawRectangle(bx-4,by-4,8,8,cBullet)
		DrawRectangle(bx-2,by-2,4,4,WHITE)
	next
	# Enemy bullets
	for i=1 to len(ebuls)
		bx=ebuls[i][:x]-cx by=ebuls[i][:y]
		if ebuls[i][:big]
			DrawCircle(bx,by,6,cBossClr)
			DrawCircle(bx,by,3,WHITE)
		else
			DrawCircle(bx,by,4,cOrange)
			DrawCircle(bx,by,2,cYellow)
		ok
	next
	# Particles
	for i=1 to len(pts)
		DrawCircle(pts[i][:x]-cx,pts[i][:y],3,pts[i][:nc])
	next
	# Player
	if g[GINV]>0 and g[GINV]%6<3
		# blink
	else
		drwHero(g[GX]-cx,g[GY],g[GDIR],g[GFRM],g)
	ok
	# Floating texts
	for i=1 to len(fts)
		DT(fts[i][:txt],floor(fts[i][:x]-cx),floor(fts[i][:y]),16,WHITE)
	next
	drwHUD(g)

# ---- Background ----
func drwBG g
	cx=g[GCAM]
	# Stars / background elements
	co=cx*0.1
	for i=0 to 30
		sx=i*120-(co%120)+50
		sy=60+(i*37)%400
		sz=1+(i%3)
		DrawCircle(sx,sy,sz,cDGray)
	next

# ---- Tiles ----
func drwTile t,x,y
	if t=T_SLD
		DrawRectangle(x,y,C_TILE,C_TILE,cStgTile)
		DrawRectangle(x+1,y+1,C_TILE-2,C_TILE-2,cStgTile2)
		DrawRectangle(x+2,y+2,C_TILE-4,2,cStgTile)
		DrawRectangleLines(x,y,C_TILE,C_TILE,cStgBG2)
	ok
	if t=T_PLAT
		DrawRectangle(x,y,C_TILE,8,cStgPlat)
		DrawRectangle(x+1,y+1,C_TILE-2,3,cStgTile)
		DrawRectangleLines(x,y,C_TILE,8,cStgBG2)
	ok
	if t=T_SPK
		# Spikes
		for s=0 to 3
			sx=x+s*8
			v1=new Vector2 v1.x=sx+4 v1.y=y
			v2=new Vector2 v2.x=sx   v2.y=y+C_TILE
			v3=new Vector2 v3.x=sx+8 v3.y=y+C_TILE
			DrawTriangle(v1,v2,v3,cSpike)
		next
	ok

# ---- Hero Sprite ----
func drwHero x,y,dir,frame,g
	# Helmet
	DrawRectangle(x+2,y,20,10,cBlue)
	DrawRectangle(x+4,y+2,16,6,cDBlue)
	# Face
	DrawRectangle(x+4,y+10,16,8,cSkin)
	if dir=1 DrawRectangle(x+14,y+12,4,3,BLACK)
	else DrawRectangle(x+6,y+12,4,3,BLACK) ok
	# Body
	DrawRectangle(x+2,y+18,20,8,cBlue)
	DrawRectangle(x+4,y+18,16,8,cDBlue)
	# Arm cannon side
	if g[GSHTT]>5
		if dir=1
			DrawRectangle(x+20,y+18,8,6,cLBlue)
			DrawRectangle(x+24,y+17,6,8,cBlue)
		else
			DrawRectangle(x-4,y+18,8,6,cLBlue)
			DrawRectangle(x-6,y+17,6,8,cBlue)
		ok
	else
		if dir=1 DrawRectangle(x+18,y+18,6,6,cBlue)
		else DrawRectangle(x,y+18,6,6,cBlue) ok
	ok
	# Legs
	if frame=0 or frame=2
		DrawRectangle(x+4,y+26,8,4,cBlue)
		DrawRectangle(x+12,y+26,8,4,cBlue)
		DrawRectangle(x+2,y+30,10,2,cDBlue)
		DrawRectangle(x+12,y+30,10,2,cDBlue)
	but frame=1
		DrawRectangle(x+1,y+26,8,4,cBlue)
		DrawRectangle(x+15,y+26,8,4,cBlue)
		DrawRectangle(x-1,y+30,10,2,cDBlue)
		DrawRectangle(x+15,y+30,10,2,cDBlue)
	but frame=3
		DrawRectangle(x+6,y+26,8,4,cBlue)
		DrawRectangle(x+10,y+26,8,4,cBlue)
		DrawRectangle(x+4,y+30,10,2,cDBlue)
		DrawRectangle(x+10,y+30,10,2,cDBlue)
	ok

# ---- Enemy Sprites ----
func drwEnemy x,y,type,frame,g
	if type=EN_WALK
		DrawRectangle(x+2,y+2,24,10,cRed)
		DrawRectangle(x+4,y+12,20,10,cDRed)
		DrawRectangle(x+8,y+4,4,4,WHITE) DrawRectangle(x+16,y+4,4,4,WHITE)
		DrawRectangle(x+9,y+5,2,2,BLACK) DrawRectangle(x+17,y+5,2,2,BLACK)
		if frame=0
			DrawRectangle(x+2,y+22,10,6,cDRed) DrawRectangle(x+16,y+22,10,6,cDRed)
		else
			DrawRectangle(x+4,y+22,10,6,cDRed) DrawRectangle(x+14,y+22,10,6,cDRed)
		ok
	ok
	if type=EN_FLY
		DrawRectangle(x+4,y+6,20,16,cPurple)
		DrawRectangle(x+6,y+8,16,12,cDPurple)
		DrawRectangle(x+8,y+10,4,4,WHITE) DrawRectangle(x+16,y+10,4,4,WHITE)
		# Wings
		if frame=0
			DrawRectangle(x-4,y,10,6,cPurple) DrawRectangle(x+22,y,10,6,cPurple)
		else
			DrawRectangle(x-4,y+4,10,6,cPurple) DrawRectangle(x+22,y+4,10,6,cPurple)
		ok
	ok
	if type=EN_TURRET
		DrawRectangle(x+4,y+8,20,20,cGray)
		DrawRectangle(x+6,y+10,16,16,cDGray)
		# Barrel
		if g[GX]-g[GCAM]>x
			DrawRectangle(x+20,y+14,10,6,cGray)
		else
			DrawRectangle(x-2,y+14,10,6,cGray)
		ok
		DrawRectangle(x+10,y+12,8,4,cRed)
	ok
	if type=EN_SHOOT
		DrawRectangle(x+2,y+2,24,12,cOrange)
		DrawRectangle(x+4,y+14,20,10,cDOrange)
		DrawRectangle(x+6,y+4,4,4,WHITE) DrawRectangle(x+18,y+4,4,4,WHITE)
		DrawRectangle(x+7,y+5,2,2,BLACK) DrawRectangle(x+19,y+5,2,2,BLACK)
		DrawRectangle(x+10,y+10,8,4,cYellow)
		if frame=0
			DrawRectangle(x+2,y+24,10,4,cDOrange) DrawRectangle(x+16,y+24,10,4,cDOrange)
		else
			DrawRectangle(x+4,y+24,10,4,cDOrange) DrawRectangle(x+14,y+24,10,4,cDOrange)
		ok
	ok

# ---- Boss Sprite ----
func drwBossSprite x,y,g
	if g[GFLSH]>0 and g[GFLSH]%2=0 return ok
	# Body
	DrawRectangle(x+4,y+8,40,30,cBossClr)
	DrawRectangle(x+8,y+12,32,22,cBossClr2)
	# Head
	DrawRectangle(x+8,y-4,32,16,cBossClr)
	DrawRectangle(x+12,y,24,8,cBossClr2)
	# Eyes
	DrawRectangle(x+14,y+2,8,6,WHITE) DrawRectangle(x+28,y+2,8,6,WHITE)
	if g[GBDIR]=-1
		DrawRectangle(x+14,y+3,4,4,BLACK) DrawRectangle(x+28,y+3,4,4,BLACK)
	else
		DrawRectangle(x+18,y+3,4,4,BLACK) DrawRectangle(x+32,y+3,4,4,BLACK)
	ok
	# Stage specific details
	switch g[GSTG]
	on 1 # Flame
		DrawRectangle(x+12,y-10,6,8,cOrange) DrawRectangle(x+22,y-12,6,10,cYellow)
		DrawRectangle(x+30,y-10,6,8,cOrange)
	on 2 # Ice
		DrawRectangle(x+10,y-8,8,6,cCyan) DrawRectangle(x+30,y-8,8,6,cCyan)
	on 3 # Electric
		DrawRectangle(x+8,y-6,4,10,cYellow) DrawRectangle(x+20,y-8,4,12,cYellow)
		DrawRectangle(x+36,y-6,4,10,cYellow)
	on 4 # Wind
		DrawRectangle(x-4,y+10,8,4,cGreen) DrawRectangle(x+44,y+10,8,4,cGreen)
		DrawRectangle(x-6,y+20,10,4,cGreen) DrawRectangle(x+44,y+20,10,4,cGreen)
	off
	# Legs
	DrawRectangle(x+10,y+38,12,10,cBossClr) DrawRectangle(x+28,y+38,12,10,cBossClr)

# ---- Power-up Drawing ----
func drwPUp x,y,type,g
	if type=1
		# Health capsule
		if g[GATM]%30<20
			DrawRectangle(x+2,y+2,16,16,cHPGreen)
			DrawRectangle(x+7,y+4,6,12,WHITE)
			DrawRectangle(x+4,y+7,12,6,WHITE)
		ok
	but type=2
		# Extra life
		if g[GATM]%30<20
			DrawRectangle(x+2,y+2,16,16,cLBlue)
			DT("1",x+5,y+2,14,WHITE)
		ok
	ok

# ---- HUD ----
func drwHUD g
	DrawRectangle(0,0,C_SW,40,cHUD)
	# HP bar
	DT("HP",10,5,12,WHITE)
	DrawRectangle(35,5,152,14,cDGray)
	hpw=floor(150*g[GHP]/g[GHPMAX])
	if hpw<0 hpw=0 ok
	hpc=cHPGreen
	if g[GHP]<g[GHPMAX]/3 hpc=cHPRed ok
	DrawRectangle(36,6,hpw,12,hpc)
	# Score
	DT("SCORE:"+g[GSCR],220,5,14,WHITE)
	# Stage
	if g[GSTG]>0 and g[GSTG]<=4
		DT(stgNames[g[GSTG]],420,5,14,cYellow)
	ok
	# Lives
	DT("LIVES",C_SW-120,5,12,WHITE)
	for i=1 to g[GLIV]
		DrawRectangle(C_SW-120+(i-1)*18,20,12,12,cBlue)
	next
	DT("X:Shoot",550,24,12,cGray)

func drwBossHP g
	# Boss HP bar at top
	DT("BOSS",10,28,10,cRed)
	DrawRectangle(50,28,202,10,cDGray)
	bhw=floor(200*g[GBHP]/g[GBHPM])
	if bhw<0 bhw=0 ok
	DrawRectangle(51,29,bhw,8,cRed)

# ---- Overlays ----
func drwDieOvr g
	DrawRectangle(0,0,C_SW,C_SH,cOverlay)
	if g[GLIV]>0
		t="DESTROYED!" tw=MeasureText(t,40)
		DT(t,floor((C_SW-tw)/2)+2,floor(C_SH/2)-38,40,cDRed)
		DT(t,floor((C_SW-tw)/2),floor(C_SH/2)-40,40,WHITE)
		t="Lives: "+g[GLIV] tw=MeasureText(t,22)
		DT(t,floor((C_SW-tw)/2),floor(C_SH/2)+10,22,WHITE)
	ok

func drwOverScr g
	ClearBackground(BLACK)
	t="GAME OVER" tw=MeasureText(t,52)
	DT(t,floor((C_SW-tw)/2)+2,floor(C_SH/2)-58,52,cDRed)
	DT(t,floor((C_SW-tw)/2),floor(C_SH/2)-60,52,cRed)
	t="Score: "+g[GSCR] tw=MeasureText(t,24)
	DT(t,floor((C_SW-tw)/2),floor(C_SH/2)+10,24,WHITE)
	t="Press ENTER" tw=MeasureText(t,18)
	if g[GATM]%60<42 DT(t,floor((C_SW-tw)/2),floor(C_SH/2)+60,18,GRAY) ok

func drwBDieEff g
	DrawRectangle(0,0,C_SW,C_SH,cc(0,0,0,80))
	t="BOSS DEFEATED!" tw=MeasureText(t,36)
	if g[GDTM]<80
		DT(t,floor((C_SW-tw)/2),floor(C_SH/2)-20,36,cYellow)
	ok

func drwStgCScr g
	ClearBackground(BLACK)
	t="STAGE CLEAR!" tw=MeasureText(t,42)
	DT(t,floor((C_SW-tw)/2)+2,floor(C_SH/2)-58,42,cDBlue)
	DT(t,floor((C_SW-tw)/2),floor(C_SH/2)-60,42,cLBlue)
	if g[GSTG]>=1 and g[GSTG]<=4
		t=stgBossNames[g[GSTG]]+" defeated!" tw=MeasureText(t,22)
		DT(t,floor((C_SW-tw)/2),floor(C_SH/2),22,cYellow)
	ok
	t="Score: "+g[GSCR] tw=MeasureText(t,24)
	DT(t,floor((C_SW-tw)/2),floor(C_SH/2)+40,24,WHITE)

func drwWinScr g
	ClearBackground(BLACK)
	t="CONGRATULATIONS!" tw=MeasureText(t,42)
	DT(t,floor((C_SW-tw)/2)+2,72,42,cDBlue)
	DT(t,floor((C_SW-tw)/2),70,42,cLBlue)
	t="All Robot Masters Defeated!" tw=MeasureText(t,24)
	DT(t,floor((C_SW-tw)/2),140,24,cYellow)
	drwHero(C_SW/2-12,220,1,0,g)
	t="Final Score: "+g[GSCR] tw=MeasureText(t,30)
	DT(t,floor((C_SW-tw)/2),320,30,cCyan)
	t="Press ENTER to Play Again" tw=MeasureText(t,18)
	if g[GATM]%60<42 DT(t,floor((C_SW-tw)/2),420,18,GRAY) ok
	DT("Made with Ring Language + RayLib",240,570,16,GRAY)

# ---- Utility ----
func rOvr x1,y1,w1,h1,x2,y2,w2,h2
	if x1+w1<=x2 return false ok
	if x2+w2<=x1 return false ok
	if y1+h1<=y2 return false ok
	if y2+h2<=y1 return false ok
	return true
