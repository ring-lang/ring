/*
	Ring Mario - Classic Platformer
	Ring + RayLib | Statements -> Functions
	Colors use built-in constants + custom Color objects (no GetColor)
*/

load "raylib.ring"

# Constants
C_SW=800 C_SH=600 C_TILE=40
C_GRAV=0.5 C_MAXF=12
C_SPD=3.5 C_RSPD=5.5 C_JMP=-12.0 C_BJMP=-13.0

# Tiles
T_E=0 T_GND=1 T_BRK=2 T_Q=3 T_BLK=4
T_PTL=5 T_PTR=6 T_PBL=7 T_PBR=8
T_FP=9 T_FT=10 T_GTOP=11

# States & Types
S_MNU=0 S_PLY=1 S_DIE=2 S_OVR=3 S_LW=4 S_WIN=5
EN_G=1 EN_K=2 PW_M=1 PW_S=2

# Game data indices
GX=1 GY=2 GVX=3 GVY=4 GW=5 GH=6 GBIG=7 GSTR=8
GSTM=9 GDIR=10 GGND=11 GLIV=12 GSCR=13 GCN=14
GFRM=15 GFTM=16 GDCK=17 GINV=18 GCAM=19
GLW=20 GLH=21 GLVL=22 GMLV=23 GST=24
GDTM=25 GLCT=26 GFLG=27 GQBF=28 GQBT=29 GATM=30 GJBF=31

g=list(31)
g[GX]=120 g[GY]=0 g[GVX]=0 g[GVY]=0
g[GW]=28 g[GH]=36 g[GBIG]=false g[GSTR]=false
g[GSTM]=0 g[GDIR]=1 g[GGND]=false g[GLIV]=3
g[GSCR]=0 g[GCN]=0 g[GFRM]=0 g[GFTM]=0
g[GDCK]=false g[GINV]=0 g[GCAM]=0
g[GLW]=0 g[GLH]=15 g[GLVL]=1 g[GMLV]=3
g[GST]=S_MNU g[GDTM]=0 g[GLCT]=0
g[GFLG]=false g[GQBF]=0 g[GQBT]=0 g[GATM]=0 g[GJBF]=0

# Global lists
lvl=[] ens=[] cns=[] pws=[] pts=[] fts=[] bks=[]

# Pre-cache custom colors (using new Color object)
cBrown   = cc(200,76,12,255)
cLBrown  = cc(232,160,96,255)
cDBrown  = cc(138,48,0,255)
cBrkLn   = cc(144,64,32,255)
cGrass1  = cc(0,184,0,255)
cGrass2  = cc(92,228,48,255)
cGreen   = cc(0,168,0,255)
cDGreen  = cc(0,120,0,255)
cLGreen  = cc(0,208,0,255)
cGold    = cc(251,208,0,255)
cDGold   = cc(224,144,0,255)
cQBord   = cc(156,96,0,255)
cRed     = cc(229,37,33,255)
cDRed    = cc(128,0,0,255)
cBlue    = cc(60,60,220,255)
cSkin    = cc(252,160,68,255)
cShoe    = cc(107,66,12,255)
cPipe1   = cc(0,168,0,255)
cPipe2   = cc(0,208,0,255)
cPipe3   = cc(0,96,0,255)
cBlk1    = cc(136,104,72,255)
cBlk2    = cc(96,64,32,255)
cBlk3    = cc(160,136,104,255)
cCloudLt = cc(238,238,238,255)
cHillC   = cc(72,160,48,255)
cGndDk   = cc(160,64,16,255)
cPoleC   = cc(170,170,170,255)
cPoleLt  = cc(204,204,204,255)
cHUD     = cc(0,0,0,170)
cOverlay = cc(0,0,0,170)
cOverlay2= cc(0,0,0,119)
cStarYel = cc(255,255,136,255)
cFlagGrn = cc(0,204,0,255)

# ========== MAIN LOOP ==========
InitWindow(C_SW,C_SH,"Ring Mario - Classic Platformer")
SetTargetFPS(60)
buildLvl(g,1)

while !WindowShouldClose()
	switch g[GST]
	on S_MNU updMenu(g)
	on S_PLY updGame(g)
	on S_DIE updDie(g)
	on S_OVR updOver(g)
	on S_LW  updLW(g)
	on S_WIN updWinS(g)
	off

	BeginDrawing()
	ClearBackground(cc(92,148,252,255))
	switch g[GST]
	on S_MNU drwMenu(g)
	on S_PLY drwGame(g)
	on S_DIE drwGame(g) drwDieOvr(g)
	on S_OVR drwOver(g)
	on S_LW  drwGame(g) drwLW(g)
	on S_WIN drwWinS(g)
	off
	EndDrawing()
end
CloseWindow()

# ====================================================
# FUNCTIONS
# ====================================================

# Color helper - creates Color object
func cc r,g,b,a
	c = new Color
	c.r=r c.g=g c.b=b c.a=a
	return c

# DrawText wrapper - converts Color object to C pointer
func DT text,x,y,sz,color
	drawtext(text,x,y,sz,GPData(color))

# ---- Level Building ----
func buildLvl g, num
	ens=[] cns=[] pws=[] pts=[] fts=[] bks=[]
	g[GX]=120 g[GY]=0 g[GVX]=0 g[GVY]=0
	g[GCAM]=0 g[GGND]=false g[GFLG]=false g[GLVL]=num
	switch num
	on 1 bldL1(g) on 2 bldL2(g) on 3 bldL3(g) off
	g[GY]=(g[GLH]-3)*C_TILE

func bldL1 g
	w=200 h=g[GLH] g[GLW]=w
	lvl=list(h,w)
	for r=1 to h for c=1 to w lvl[r][c]=T_E next next
	for c=1 to w lvl[h][c]=T_GND lvl[h-1][c]=T_GTOP next
	for c=70 to 73 lvl[h][c]=T_E lvl[h-1][c]=T_E next
	for c=120 to 123 lvl[h][c]=T_E lvl[h-1][c]=T_E next
	lvl[h-5][12]=T_Q
	lvl[h-5][17]=T_BRK lvl[h-5][18]=T_Q lvl[h-5][19]=T_BRK
	lvl[h-5][20]=T_Q lvl[h-5][21]=T_BRK
	lvl[h-9][19]=T_Q
	for c=56 to 63 lvl[h-5][c]=T_BRK next
	lvl[h-5][59]=T_Q lvl[h-5][61]=T_Q
	for step=1 to 4 for s=0 to step-1 lvl[h-2-s][65+step]=T_BLK next next
	for step=1 to 4 for s=0 to step-1 lvl[h-2-s][78-step]=T_BLK next next
	mkPipe(h-3,30,2) mkPipe(h-4,40,3) mkPipe(h-4,48,3)
	for c=82 to 90 lvl[h-5][c]=T_BRK next
	lvl[h-5][85]=T_Q lvl[h-5][87]=T_Q
	for c=92 to 97 lvl[h-9][c]=T_BRK next
	lvl[h-9][94]=T_Q
	for c=102 to 110 lvl[h-5][c]=T_BRK next
	lvl[h-5][105]=T_Q lvl[h-5][107]=T_Q
	for step=1 to 8 for s=0 to step-1 lvl[h-2-s][177+step]=T_BLK next next
	for r=h-10 to h-2 lvl[r][187]=T_FP next
	lvl[h-11][187]=T_FT
	addCn(14,h-7) addCn(15,h-7)
	addCn(57,h-7) addCn(58,h-7) addCn(59,h-7) addCn(60,h-7)
	addCn(83,h-7) addCn(85,h-7) addCn(87,h-7)
	addCn(104,h-7) addCn(106,h-7) addCn(108,h-7)
	addCn(71,h-5) addCn(72,h-5)
	addEn(24,h-3,EN_G) addEn(36,h-3,EN_G) addEn(44,h-3,EN_G)
	addEn(54,h-3,EN_G) addEn(55,h-3,EN_G) addEn(82,h-3,EN_K)
	addEn(97,h-3,EN_G) addEn(98,h-3,EN_G) addEn(112,h-3,EN_G)
	addEn(132,h-3,EN_K) addEn(162,h-3,EN_G) addEn(164,h-3,EN_G)

func bldL2 g
	w=180 h=g[GLH] g[GLW]=w
	lvl=list(h,w) for r=1 to h for c=1 to w lvl[r][c]=T_E next next
	for c=1 to w lvl[h][c]=T_GND lvl[h-1][c]=T_GTOP next
	for c=32 to 35 lvl[h][c]=T_E lvl[h-1][c]=T_E next
	for c=58 to 62 lvl[h][c]=T_E lvl[h-1][c]=T_E next
	for c=92 to 97 lvl[h][c]=T_E lvl[h-1][c]=T_E next
	for c=122 to 126 lvl[h][c]=T_E lvl[h-1][c]=T_E next
	for c=15 to 20 lvl[h-5][c]=T_BRK next
	lvl[h-5][17]=T_Q lvl[h-5][19]=T_Q
	for c=25 to 28 lvl[h-8][c]=T_BRK next
	for c=36 to 42 lvl[h-5][c]=T_BRK next
	lvl[h-5][39]=T_Q
	for c=46 to 50 lvl[h-7][c]=T_BRK next
	lvl[h-7][48]=T_Q
	for c=63 to 68 lvl[h-4][c]=T_BRK next
	for c=72 to 78 lvl[h-6][c]=T_BRK next
	lvl[h-6][75]=T_Q
	for c=102 to 110 lvl[h-5][c]=T_BRK next
	lvl[h-5][105]=T_Q lvl[h-5][107]=T_Q
	mkPipe(h-3,52,2) mkPipe(h-3,87,2)
	# Stepping blocks before the pipe at 87
	for s=0 to 0 lvl[h-2-s][84]=T_BLK next
	for s=0 to 1 lvl[h-2-s][85]=T_BLK next
	for step=1 to 9 for s=0 to step-1 lvl[h-2-s][157+step]=T_BLK next next
	for r=h-11 to h-2 lvl[r][170]=T_FP next
	lvl[h-12][170]=T_FT
	for c=16 to 19 addCn(c,h-7) next
	for c=63 to 67 addCn(c,h-6) next
	for c=103 to 109 addCn(c,h-7) next
	addEn(20,h-3,EN_G) addEn(28,h-3,EN_G) addEn(42,h-3,EN_K)
	addEn(50,h-3,EN_G) addEn(68,h-3,EN_G) addEn(70,h-3,EN_G)
	addEn(82,h-3,EN_K) addEn(102,h-3,EN_G) addEn(112,h-3,EN_G)
	addEn(114,h-3,EN_G) addEn(142,h-3,EN_K) addEn(152,h-3,EN_G)

func bldL3 g
	w=220 h=g[GLH] g[GLW]=w
	lvl=list(h,w) for r=1 to h for c=1 to w lvl[r][c]=T_E next next
	for c=1 to w lvl[h][c]=T_GND lvl[h-1][c]=T_GTOP next
	for c=28 to 32 lvl[h][c]=T_E lvl[h-1][c]=T_E next
	for c=53 to 58 lvl[h][c]=T_E lvl[h-1][c]=T_E next
	for c=78 to 84 lvl[h][c]=T_E lvl[h-1][c]=T_E next
	for c=112 to 118 lvl[h][c]=T_E lvl[h-1][c]=T_E next
	for c=148 to 153 lvl[h][c]=T_E lvl[h-1][c]=T_E next
	for c=10 to 18 lvl[h-5][c]=T_BRK next
	lvl[h-5][13]=T_Q lvl[h-5][15]=T_Q
	for c=22 to 25 lvl[h-8][c]=T_BRK next
	lvl[h-8][23]=T_Q
	for c=36 to 46 lvl[h-5][c]=T_BRK next
	lvl[h-5][39]=T_Q lvl[h-5][41]=T_Q lvl[h-5][43]=T_Q
	for c=59 to 63 lvl[h-4][c]=T_BLK next
	for c=65 to 71 lvl[h-7][c]=T_BRK next
	lvl[h-7][68]=T_Q
	for c=88 to 98 lvl[h-5][c]=T_BRK next
	lvl[h-5][92]=T_Q lvl[h-5][94]=T_Q
	for c=102 to 107 lvl[h-9][c]=T_BRK next
	lvl[h-9][104]=T_Q
	for c=128 to 138 lvl[h-5][c]=T_BRK next
	lvl[h-5][132]=T_Q lvl[h-5][134]=T_Q
	for c=158 to 168 lvl[h-6][c]=T_BRK next
	lvl[h-6][163]=T_Q
	mkPipe(h-3,34,2) mkPipe(h-4,73,3) mkPipe(h-3,143,2)
	# Stepping blocks before pipe at 143
	for s=0 to 0 lvl[h-2-s][140]=T_BLK next
	for s=0 to 1 lvl[h-2-s][141]=T_BLK next
	for step=1 to 10 for s=0 to step-1 lvl[h-2-s][192+step]=T_BLK next next
	for r=h-12 to h-2 lvl[r][207]=T_FP next
	lvl[h-13][207]=T_FT
	for c=11 to 17 addCn(c,h-7) next
	for c=37 to 45 addCn(c,h-7) next
	for c=89 to 97 addCn(c,h-7) next
	for c=129 to 137 addCn(c,h-7) next
	addEn(17,h-3,EN_G) addEn(22,h-3,EN_G) addEn(32,h-3,EN_K)
	addEn(42,h-3,EN_G) addEn(44,h-3,EN_G) addEn(63,h-3,EN_G)
	addEn(68,h-3,EN_K) addEn(88,h-3,EN_G) addEn(91,h-3,EN_G)
	addEn(93,h-3,EN_G) addEn(108,h-3,EN_K) addEn(122,h-3,EN_G)
	addEn(128,h-3,EN_G) addEn(133,h-3,EN_K) addEn(158,h-3,EN_G)
	addEn(163,h-3,EN_G) addEn(173,h-3,EN_K) addEn(183,h-3,EN_G)

func mkPipe topR,col,ht
	lvl[topR][col]=T_PTL lvl[topR][col+1]=T_PTR
	for r=topR+1 to topR+ht-1
		lvl[r][col]=T_PBL lvl[r][col+1]=T_PBR
	next

# ---- Object Creators ----
func addEn colN,rowN,type
	add(ens,[:x=colN*C_TILE,:y=rowN*C_TILE,:vx=-1.2,:vy=0,
		:w=32,:h=32,:type=type,:alive=true,
		:frame=0,:ft=0,:st=0,:shell=false,:smov=false])

func addCn colN,rowN
	add(cns,[:x=colN*C_TILE+8,:y=rowN*C_TILE+8,:w=24,:h=24,:got=false,:frame=0,:ft=0])

func addPow x,y,type
	add(pws,[:x=x,:y=y,:vx=2,:vy=-3,:w=28,:h=28,:type=type,:on=true])

func addPt x,y,vx,vy,nc,life
	add(pts,[:x=x,:y=y,:vx=vx,:vy=vy,:nc=nc,:life=life])

func addFT x,y,txt
	add(fts,[:x=x,:y=y,:txt=txt,:tmr=60])

func addBB x,y
	for i=1 to 4
		add(bks,[:x=x+10,:y=y+10,:vx=-3+GetRandomValue(0,6),
			:vy=-8+GetRandomValue(0,3),:life=40])
	next

# ---- Menu ----
func updMenu g
	g[GATM]++
	if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE)
		g[GST]=S_PLY g[GLIV]=3 g[GSCR]=0 g[GCN]=0
		g[GBIG]=false g[GSTR]=false
		buildLvl(g,1)
	ok

func drwMenu g
	ClearBackground(BLACK)
	t="RING MARIO" tw=MeasureText(t,64)
	DT(t,floor((C_SW-tw)/2)+3,103,64,cDRed)
	DT(t,floor((C_SW-tw)/2),100,64,cRed)
	t="A Classic Platformer" tw=MeasureText(t,22)
	DT(t,floor((C_SW-tw)/2),175,22,cGold)
	drwMario(C_SW/2-14,250,1,false,false,0,false,g)
	t="Press ENTER or SPACE to Start" tw=MeasureText(t,20)
	if g[GATM]%60<42 DT(t,floor((C_SW-tw)/2),360,20,WHITE) ok
	DT("Controls:",220,420,20,cGold)
	DT("Arrow Keys / WASD  -  Move & Jump",220,448,16,WHITE)
	DT("Shift              -  Run",220,468,16,WHITE)
	DT("Down / S           -  Duck (when big)",220,488,16,WHITE)
	DT("Made with Ring Language + RayLib",230,565,16,GRAY)

# ---- Game Update ----
func updGame g
	g[GATM]++
	g[GQBT]++
	if g[GQBT]>15
		g[GQBT]=0 g[GQBF]++
		if g[GQBF]>3 g[GQBF]=0 ok
	ok
	if g[GJBF]>0 g[GJBF]-- ok
	updPlayer(g) updEns(g) updCns(g) updPws(g)
	updPts() updFTs() updBBs() gameCamUpd(g)
	if g[GSTR]
		g[GSTM]--
		if g[GSTM]<=0 g[GSTR]=false ok
	ok
	if g[GINV]>0 g[GINV]-- ok
	if g[GY]>g[GLH]*C_TILE+100 pDie(g) ok

# ---- Player ----
func updPlayer g
	if g[GFLG] return ok
	ml=IsKeyDown(KEY_LEFT) or IsKeyDown(KEY_A)
	mr=IsKeyDown(KEY_RIGHT) or IsKeyDown(KEY_D)
	jkP=IsKeyPressed(KEY_SPACE) or IsKeyPressed(KEY_UP) or IsKeyPressed(KEY_W)
	jkD=IsKeyDown(KEY_SPACE) or IsKeyDown(KEY_UP) or IsKeyDown(KEY_W)
	dk=IsKeyDown(KEY_DOWN) or IsKeyDown(KEY_S)
	run=IsKeyDown(KEY_LEFT_SHIFT) or IsKeyDown(KEY_RIGHT_SHIFT)
	if jkP g[GJBF]=8 ok
	if g[GBIG] and dk and g[GGND]
		g[GDCK]=true g[GH]=28
	else
		if g[GDCK] g[GDCK]=false g[GH]=52 ok
	ok
	spd=C_SPD if run spd=C_RSPD ok
	if ml and !g[GDCK]      g[GVX]=-spd g[GDIR]=-1
	but mr and !g[GDCK]     g[GVX]=spd  g[GDIR]=1
	else                     g[GVX]=0 ok
	if g[GJBF]>0 and g[GGND]
		if g[GBIG] g[GVY]=C_BJMP else g[GVY]=C_JMP ok
		g[GGND]=false g[GJBF]=0
	ok
	if !jkD and g[GVY]<-2 g[GVY]=g[GVY]*0.92 ok
	g[GVY]+=C_GRAV if g[GVY]>C_MAXF g[GVY]=C_MAXF ok
	if g[GVX]!=0 and g[GGND]
		g[GFTM]++
		if g[GFTM]>5
			g[GFTM]=0 g[GFRM]++
			if g[GFRM]>2 g[GFRM]=0 ok
		ok
	else
		if !g[GGND] g[GFRM]=3 else g[GFRM]=0 ok
	ok
	g[GX]+=g[GVX] resH(g)
	g[GY]+=g[GVY] resV(g)
	if g[GBIG] and !g[GDCK]  g[GH]=52 g[GW]=30
	but g[GBIG] and g[GDCK]  g[GH]=28 g[GW]=30
	else                      g[GH]=36 g[GW]=28 ok
	if g[GX]<0 g[GX]=0 ok

# ---- Collision ----
func resH g
	px=g[GX] py=g[GY] pw=g[GW] ph=g[GH]
	sc=floor(px/C_TILE)+1 ec=floor((px+pw-1)/C_TILE)+1
	sr=floor(py/C_TILE)+1 er=floor((py+ph-1)/C_TILE)+1
	for r=sr to er for c=sc to ec
		if r>=1 and r<=g[GLH] and c>=1 and c<=g[GLW]
			if isSld(lvl[r][c])
				tx=(c-1)*C_TILE
				if rOvr(px,py,pw,ph,tx,(r-1)*C_TILE,C_TILE,C_TILE)
					if g[GVX]>0 g[GX]=tx-pw but g[GVX]<0 g[GX]=tx+C_TILE ok
					g[GVX]=0 return
				ok
			ok
		ok
	next next

func resV g
	px=g[GX] py=g[GY] pw=g[GW] ph=g[GH]
	sc=floor(px/C_TILE)+1 ec=floor((px+pw-1)/C_TILE)+1
	sr=floor(py/C_TILE)+1 er=floor((py+ph-1)/C_TILE)+1
	g[GGND]=false
	for r=sr to er for c=sc to ec
		if r>=1 and r<=g[GLH] and c>=1 and c<=g[GLW]
			if isSld(lvl[r][c])
				ty=(r-1)*C_TILE
				if rOvr(px,py,pw,ph,(c-1)*C_TILE,ty,C_TILE,C_TILE)
					if g[GVY]>0 g[GY]=ty-ph g[GVY]=0 g[GGND]=true
					but g[GVY]<0 g[GY]=ty+C_TILE g[GVY]=1 hitBlk(g,r,c) ok
					return
				ok
			ok
		ok
	next next
	# Flag
	sc=floor(g[GX]/C_TILE)+1 ec=floor((g[GX]+g[GW]-1)/C_TILE)+1
	sr=floor(g[GY]/C_TILE)+1 er=floor((g[GY]+g[GH]-1)/C_TILE)+1
	for r=sr to er for c=sc to ec
		if r>=1 and r<=g[GLH] and c>=1 and c<=g[GLW]
			t=lvl[r][c]
			if (t=T_FP or t=T_FT) and !g[GFLG]
				g[GFLG]=true g[GSCR]+=5000 g[GLCT]=150 g[GST]=S_LW
				addFT(g[GX],g[GY]-20,"5000")
			ok
		ok
	next next

func hitBlk g,row,col
	t=lvl[row][col]
	if t=T_Q
		lvl[row][col]=T_BLK
		if (col%5=2) and !g[GBIG]
			addPow((col-1)*C_TILE+5,(row-2)*C_TILE,PW_M)
		but (col%7=3) and g[GBIG]
			addPow((col-1)*C_TILE+5,(row-2)*C_TILE,PW_S)
		else
			g[GCN]++ g[GSCR]+=200
			addFT((col-1)*C_TILE,(row-2)*C_TILE,"200")
			for i=1 to 5
				addPt((col-1)*C_TILE+20,(row-1)*C_TILE,
					GetRandomValue(-2,2),GetRandomValue(-5,-2),cGold,20)
			next
		ok
	ok
	if t=T_BRK
		if g[GBIG]
			lvl[row][col]=T_E g[GSCR]+=50
			addBB((col-1)*C_TILE,(row-1)*C_TILE)
		else
			addPt((col-1)*C_TILE+20,(row-1)*C_TILE,0,-3,cBrown,10)
		ok
		for i=1 to len(ens)
			if ens[i][:alive]
				bx=(col-1)*C_TILE by=(row-1)*C_TILE
				if ens[i][:x]+ens[i][:w]>bx and ens[i][:x]<bx+C_TILE and
				   ens[i][:y]+ens[i][:h]>=by-2 and ens[i][:y]+ens[i][:h]<=by+2
					ens[i][:alive]=false g[GSCR]+=100
					addFT(ens[i][:x],ens[i][:y]-20,"100")
				ok
			ok
		next
	ok

# ---- Enemies ----
func updEns g
	h=g[GLH]
	for i=1 to len(ens)
		if !ens[i][:alive]
			if ens[i][:st]>0 ens[i][:st]-- ok loop
		ok
		if ens[i][:x]<g[GCAM]-200 or ens[i][:x]>g[GCAM]+C_SW+400 loop ok
		ens[i][:vy]+=C_GRAV
		if ens[i][:vy]>C_MAXF ens[i][:vy]=C_MAXF ok
		if ens[i][:shell] and !ens[i][:smov]
			# still
		else ens[i][:x]+=ens[i][:vx] ok
		ens[i][:y]+=ens[i][:vy]
		ens[i][:ft]++
		if ens[i][:ft]>12 ens[i][:ft]=0 ens[i][:frame]=1-ens[i][:frame] ok
		ex=ens[i][:x] ey=ens[i][:y] ew=ens[i][:w] eh=ens[i][:h]
		fr=floor((ey+eh)/C_TILE)+1
		lc=floor(ex/C_TILE)+1 rc=floor((ex+ew-1)/C_TILE)+1
		for c=lc to rc
			if fr>=1 and fr<=h and c>=1 and c<=g[GLW]
				if isSld(lvl[fr][c])
					ens[i][:y]=(fr-1)*C_TILE-eh ens[i][:vy]=0
				ok
			ok
		next
		if ens[i][:vx]>0 xc=floor((ex+ew)/C_TILE)+1
		else xc=floor(ex/C_TILE)+1 ok
		mr=floor((ey+eh/2)/C_TILE)+1
		if mr>=1 and mr<=h and xc>=1 and xc<=g[GLW]
			if isSld(lvl[mr][xc]) ens[i][:vx]=-ens[i][:vx] ok
		ok
		if ey>h*C_TILE+100 ens[i][:alive]=false ok
		if ens[i][:shell] and ens[i][:smov]
			for j=1 to len(ens)
				if j!=i and ens[j][:alive]
					if rOvr(ex,ey,ew,eh,ens[j][:x],ens[j][:y],ens[j][:w],ens[j][:h])
						ens[j][:alive]=false ens[j][:st]=0
						g[GSCR]+=200 addFT(ens[j][:x],ens[j][:y]-20,"200")
					ok
				ok
			next
		ok
		chkPEC(g,i)
	next

func chkPEC g,idx
	if !ens[idx][:alive] return ok
	px=g[GX] py=g[GY] pw=g[GW] ph=g[GH]
	ex=ens[idx][:x] ey=ens[idx][:y] ew=ens[idx][:w] eh=ens[idx][:h]
	if !rOvr(px,py,pw,ph,ex,ey,ew,eh) return ok
	if g[GSTR]
		ens[idx][:alive]=false g[GSCR]+=200
		addFT(ex,ey-20,"200") return ok
	if g[GVY]>0 and py+ph-10<ey+eh/2
		if ens[idx][:type]=EN_G
			ens[idx][:alive]=false ens[idx][:st]=30
			g[GSCR]+=100 addFT(ex,ey-20,"100")
		but ens[idx][:type]=EN_K
			if ens[idx][:shell]
				if ens[idx][:smov] ens[idx][:smov]=false ens[idx][:vx]=0
				else
					ens[idx][:smov]=true
					if px+pw/2<ex+ew/2 ens[idx][:vx]=6 else ens[idx][:vx]=-6 ok
				ok
			else
				ens[idx][:shell]=true ens[idx][:smov]=false
				ens[idx][:vx]=0 ens[idx][:h]=22
				g[GSCR]+=100 addFT(ex,ey-20,"100")
			ok
		ok
		g[GVY]=-8 return
	ok
	if ens[idx][:type]=EN_K and ens[idx][:shell] and !ens[idx][:smov]
		ens[idx][:smov]=true
		if px+pw/2<ex+ew/2 ens[idx][:vx]=6 else ens[idx][:vx]=-6 ok
		return
	ok
	if g[GINV]<=0
		if g[GBIG] g[GBIG]=false g[GH]=36 g[GINV]=90
		else pDie(g) ok
	ok

func pDie g
	g[GLIV]-- g[GDTM]=100 g[GST]=S_DIE

# ---- Coins ----
func updCns g
	for i=1 to len(cns)
		if cns[i][:got] loop ok
		cns[i][:ft]++
		if cns[i][:ft]>8 cns[i][:ft]=0 cns[i][:frame]++
			if cns[i][:frame]>3 cns[i][:frame]=0 ok
		ok
		if rOvr(g[GX],g[GY],g[GW],g[GH],cns[i][:x],cns[i][:y],cns[i][:w],cns[i][:h])
			cns[i][:got]=true g[GCN]++ g[GSCR]+=200
			addFT(cns[i][:x],cns[i][:y]-20,"200")
			for j=1 to 4
				addPt(cns[i][:x]+12,cns[i][:y]+12,
					GetRandomValue(-2,2),GetRandomValue(-3,-1),cGold,15) next
			if g[GCN]%100=0 g[GLIV]++ addFT(g[GX],g[GY]-40,"1UP!") ok
		ok
	next

# ---- Power-ups ----
func updPws g
	for i=1 to len(pws)
		if !pws[i][:on] loop ok
		pws[i][:vy]+=C_GRAV
		if pws[i][:vy]>C_MAXF pws[i][:vy]=C_MAXF ok
		pws[i][:x]+=pws[i][:vx] pws[i][:y]+=pws[i][:vy]
		px=pws[i][:x] py=pws[i][:y] pw=pws[i][:w] ph=pws[i][:h]
		fr=floor((py+ph)/C_TILE)+1
		lc=floor(px/C_TILE)+1 rc=floor((px+pw-1)/C_TILE)+1
		for c=lc to rc
			if fr>=1 and fr<=g[GLH] and c>=1 and c<=g[GLW]
				if isSld(lvl[fr][c])
					pws[i][:y]=(fr-1)*C_TILE-ph pws[i][:vy]=0
				ok
			ok
		next
		if pws[i][:vx]>0 xc=floor((px+pw)/C_TILE)+1
		else xc=floor(px/C_TILE)+1 ok
		mr=floor((py+ph/2)/C_TILE)+1
		if mr>=1 and mr<=g[GLH] and xc>=1 and xc<=g[GLW]
			if isSld(lvl[mr][xc])
				pws[i][:vx]=-pws[i][:vx]
			ok
		ok
		if rOvr(g[GX],g[GY],g[GW],g[GH],px,py,pw,ph)
			pws[i][:on]=false
			if pws[i][:type]=PW_M
				if !g[GBIG] g[GBIG]=true g[GH]=52 g[GY]-=16 ok
				g[GSCR]+=1000 addFT(px,py-20,"1000")
			but pws[i][:type]=PW_S
				g[GSTR]=true g[GSTM]=480 g[GSCR]+=1000
				addFT(px,py-20,"STAR!") ok
		ok
		if py>g[GLH]*C_TILE+100 pws[i][:on]=false ok
	next

# ---- Effects ----
func updPts
	for i=len(pts) to 1 step -1
		pts[i][:x]+=pts[i][:vx] pts[i][:y]+=pts[i][:vy]
		pts[i][:vy]+=0.2 pts[i][:life]--
		if pts[i][:life]<=0 del(pts,i) ok
	next

func updFTs
	for i=len(fts) to 1 step -1
		fts[i][:y]-=1.5 fts[i][:tmr]--
		if fts[i][:tmr]<=0 del(fts,i) ok
	next

func updBBs
	for i=len(bks) to 1 step -1
		bks[i][:x]+=bks[i][:vx] bks[i][:y]+=bks[i][:vy]
		bks[i][:vy]+=0.5 bks[i][:life]--
		if bks[i][:life]<=0 del(bks,i) ok
	next

func gameCamUpd g
	g[GCAM]=g[GX]-floor(C_SW/3)
	if g[GCAM]<0 g[GCAM]=0 ok
	mx=g[GLW]*C_TILE-C_SW if mx<0 mx=0 ok
	if g[GCAM]>mx g[GCAM]=mx ok

# ---- States ----
func updDie g
	g[GDTM]--
	if g[GDTM]<=0
		if g[GLIV]<=0 g[GST]=S_OVR
		else
			g[GST]=S_PLY g[GSTR]=false buildLvl(g,g[GLVL])
		ok
	ok

func updOver g
	g[GATM]++
	if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE) g[GST]=S_MNU ok

func updLW g
	g[GLCT]--
	if g[GLCT]<=0
		if g[GLVL]<g[GMLV] buildLvl(g,g[GLVL]+1) g[GST]=S_PLY
		else
			g[GST]=S_WIN
		ok
	ok

func updWinS g
	g[GATM]++
	if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE) g[GST]=S_MNU ok

# ====================================================
# DRAWING
# ====================================================
func drwGame g
	cx=g[GCAM]
	drwBG(g)
	# Tiles
	sc=floor(cx/C_TILE) ec=sc+(C_SW/C_TILE)+2
	for r=1 to g[GLH]
		for c=sc to ec
			col=c+1
			if col>=1 and col<=g[GLW]
				t=lvl[r][col]
				if t!=T_E drwTile(t,(col-1)*C_TILE-cx,(r-1)*C_TILE,g) ok
			ok
		next
	next
	# Coins
	for i=1 to len(cns)
		if cns[i][:got] loop ok
		dx=cns[i][:x]-cx
		if dx>-C_TILE and dx<C_SW+C_TILE drwCoin(dx,cns[i][:y],cns[i][:frame]) ok
	next
	# Power-ups
	for i=1 to len(pws)
		if !pws[i][:on] loop ok
		dx=pws[i][:x]-cx
		if dx>-C_TILE and dx<C_SW+C_TILE
			if pws[i][:type]=PW_M drwMush(dx,pws[i][:y])
			but pws[i][:type]=PW_S drwStar(dx,pws[i][:y],g) ok
		ok
	next
	# Enemies
	for i=1 to len(ens)
		dx=ens[i][:x]-cx
		if dx>-100 and dx<C_SW+100
			if ens[i][:alive]
				if ens[i][:type]=EN_G drwGmba(dx,ens[i][:y],ens[i][:frame])
				but ens[i][:type]=EN_K
					if ens[i][:shell] drwShl(dx,ens[i][:y])
					else
						drwKpa(dx,ens[i][:y],ens[i][:frame])
					ok
				ok
			else
				if ens[i][:st]>0 drwSqsh(dx,ens[i][:y]+ens[i][:h]-8,ens[i][:type]) ok
			ok
		ok
	next
	# Broken bricks
	for i=1 to len(bks)
		DrawRectangle(bks[i][:x]-cx,bks[i][:y],10,10,cBrown)
		DrawRectangle(bks[i][:x]-cx+1,bks[i][:y]+1,8,8,cLBrown)
	next
	# Particles
	for i=1 to len(pts)
		DrawCircle(pts[i][:x]-cx,pts[i][:y],3,pts[i][:nc])
	next
	# Player
	if g[GINV]>0 and g[GINV]%6<3
		# blink
	else drwMario(g[GX]-cx,g[GY],g[GDIR],g[GBIG],g[GSTR],g[GFRM],g[GDCK],g) ok
	# Floating texts
	for i=1 to len(fts)
		DT(fts[i][:txt],fts[i][:x]-cx,fts[i][:y],18,WHITE)
	next
	drwHUD(g)

# ---- Background ----
func drwBG g
	cx=g[GCAM]
	gndY=(g[GLH]-2)*C_TILE
	# Clouds
	co=cx*0.2
	for i=0 to 10
		x=i*260-(co%260)  y=50+(i%3)*35
		DrawCircle(x+15,y+8,10,cCloudLt)
		DrawCircle(x+30,y+4,13,WHITE)
		DrawCircle(x+45,y+8,10,cCloudLt)
		DrawRectangle(x+8,y+8,40,10,WHITE)
	next
	# Hills
	ho=cx*0.15
	for i=0 to 8
		x=i*350-(ho%350) sz=35+(i%3)*15
		for j=0 to sz
			w=sz*2-j*2
			if w>0 DrawRectangle(x-sz+j,gndY-j,w,2,cHillC) ok
		next
	next
	# Bushes
	bo=cx*0.4
	for i=0 to 14
		x=i*200-(bo%200)
		DrawCircle(x,gndY,10,cDGreen)
		DrawCircle(x+18,gndY-2,13,cGreen)
		DrawCircle(x+36,gndY,10,cDGreen)
	next

# ---- Tile Drawing (all using pre-cached colors) ----
func drwTile t,x,y,g
	switch t
	on T_GTOP
		DrawRectangle(x,y,C_TILE,C_TILE,cBrown)
		DrawRectangle(x+1,y+8,C_TILE-2,C_TILE-8,cGndDk)
		DrawRectangle(x,y,C_TILE,5,cGrass1)
		DrawRectangle(x,y+4,C_TILE,4,cGrass2)
	on T_GND
		DrawRectangle(x,y,C_TILE,C_TILE,cDBrown)
		DrawRectangle(x+1,y+1,C_TILE-2,C_TILE-2,cGndDk)
		DrawLine(x,y+C_TILE/2,x+C_TILE,y+C_TILE/2,cDBrown)
		DrawLine(x+C_TILE/2,y,x+C_TILE/2,y+C_TILE,cDBrown)
	on T_BRK
		DrawRectangle(x,y,C_TILE,C_TILE,cBrown)
		DrawRectangle(x+1,y+1,C_TILE-2,C_TILE-2,cLBrown)
		DrawLine(x,y+C_TILE/2,x+C_TILE,y+C_TILE/2,cBrkLn)
		DrawLine(x+C_TILE/2,y,x+C_TILE/2,y+C_TILE/2,cBrkLn)
		DrawLine(x+C_TILE/4,y+C_TILE/2,x+C_TILE/4,y+C_TILE,cBrkLn)
		DrawLine(x+3*C_TILE/4,y+C_TILE/2,x+3*C_TILE/4,y+C_TILE,cBrkLn)
		DrawRectangleLines(x,y,C_TILE,C_TILE,cBrkLn)
	on T_Q
		DrawRectangle(x,y,C_TILE,C_TILE,cDGold)
		DrawRectangle(x+2,y+2,C_TILE-4,C_TILE-4,cGold)
		DrawRectangle(x+4,y+4,C_TILE-8,C_TILE-8,cDGold)
		DrawRectangleLines(x,y,C_TILE,C_TILE,cQBord)
		qy=y+5
		if g[GQBF]=1 qy=y+3 but g[GQBF]=3 qy=y+7 ok
		DT("?",x+13,qy+1,24,cQBord)
		DT("?",x+12,qy,24,WHITE)
	on T_BLK
		DrawRectangle(x,y,C_TILE,C_TILE,cBlk1)
		DrawRectangle(x+2,y+2,C_TILE-4,C_TILE-4,cBlk3)
		DrawRectangleLines(x,y,C_TILE,C_TILE,cBlk2)
	on T_PTL
		DrawRectangle(x-4,y,C_TILE+4,C_TILE,cPipe1)
		DrawRectangle(x-4,y,C_TILE+4,6,cPipe2)
		DrawRectangle(x-4,y,6,C_TILE,cPipe2)
	on T_PTR
		DrawRectangle(x,y,C_TILE+4,C_TILE,cPipe1)
		DrawRectangle(x,y,C_TILE+4,6,cPipe2)
		DrawRectangle(x+C_TILE-2,y,6,C_TILE,cPipe3)
	on T_PBL
		DrawRectangle(x,y,C_TILE,C_TILE,cPipe1)
		DrawRectangle(x,y,6,C_TILE,cPipe2)
	on T_PBR
		DrawRectangle(x,y,C_TILE,C_TILE,cPipe1)
		DrawRectangle(x+C_TILE-6,y,6,C_TILE,cPipe3)
	on T_FP
		DrawRectangle(x+17,y,6,C_TILE,cPoleC)
		DrawRectangle(x+17,y,2,C_TILE,cPoleLt)
	on T_FT
		DrawRectangle(x+17,y,6,C_TILE,cPoleC)
		DrawCircle(x+20,y+5,7,cGreen)
		v1=new Vector2 v1.x=x+17 v1.y=y+8
		v2=new Vector2 v2.x=x-6  v2.y=y+18
		v3=new Vector2 v3.x=x+17 v3.y=y+28
		DrawTriangle(v1,v2,v3,cFlagGrn)
	off

# ---- Mario Sprite ----
func drwMario x,y,dir,big,star,frame,duck,g
	if star
		starC = [cRed,cGold,cGreen,WHITE]
		idx = floor(g[GATM]/3) % 4
		bc = starC[idx+1]
		idx2 = (idx+1) % 4
		hc = starC[idx2+1]
	else
		bc=cRed hc=cRed
	ok
	sk=cSkin ov=cBlue sh=cShoe

	if big and !duck
		DrawRectangle(x+2,y,26,8,hc)
		DrawRectangle(x+4,y+8,22,12,sk)
		if dir=1 DrawRectangle(x+20,y+10,4,4,BLACK)
		else DrawRectangle(x+6,y+10,4,4,BLACK) ok
		DrawRectangle(x+8,y+16,14,3,sh)
		DrawRectangle(x+2,y+20,26,14,bc)
		DrawRectangle(x+4,y+28,22,8,ov)
		DrawRectangle(x+6,y+28,18,3,cGold)
		if frame=0 or frame=2
			DrawRectangle(x+4,y+36,10,10,ov) DrawRectangle(x+16,y+36,10,10,ov)
			DrawRectangle(x+2,y+46,12,6,sh) DrawRectangle(x+16,y+46,12,6,sh)
		but frame=1
			DrawRectangle(x,y+36,10,10,ov) DrawRectangle(x+20,y+36,10,10,ov)
			DrawRectangle(x-2,y+46,12,6,sh) DrawRectangle(x+20,y+46,12,6,sh)
		but frame=3
			DrawRectangle(x,y+36,10,10,ov) DrawRectangle(x+20,y+32,10,10,ov)
			DrawRectangle(x-2,y+46,12,6,sh) DrawRectangle(x+20,y+42,12,6,sh)
		ok
	but big and duck
		DrawRectangle(x+2,y,26,8,hc)
		DrawRectangle(x+4,y+6,22,10,sk)
		if dir=1 DrawRectangle(x+20,y+8,4,4,BLACK)
		else DrawRectangle(x+6,y+8,4,4,BLACK) ok
		DrawRectangle(x+2,y+14,26,14,bc)
	else
		DrawRectangle(x+2,y,24,7,hc)
		DrawRectangle(x+4,y+7,20,10,sk)
		if dir=1 DrawRectangle(x+18,y+9,4,3,BLACK)
		else DrawRectangle(x+6,y+9,4,3,BLACK) ok
		DrawRectangle(x+7,y+14,14,2,sh)
		DrawRectangle(x+2,y+17,24,8,bc)
		DrawRectangle(x+4,y+22,20,4,ov)
		if frame=0 or frame=2
			DrawRectangle(x+4,y+26,8,6,ov) DrawRectangle(x+16,y+26,8,6,ov)
			DrawRectangle(x+2,y+32,10,4,sh) DrawRectangle(x+16,y+32,10,4,sh)
		but frame=1
			DrawRectangle(x+1,y+26,8,6,ov) DrawRectangle(x+19,y+26,8,6,ov)
			DrawRectangle(x-1,y+32,10,4,sh) DrawRectangle(x+19,y+32,10,4,sh)
		but frame=3
			DrawRectangle(x+1,y+26,8,6,ov) DrawRectangle(x+19,y+23,8,6,ov)
			DrawRectangle(x-1,y+32,10,4,sh) DrawRectangle(x+19,y+29,10,4,sh)
		ok
	ok

# ---- Enemy Sprites ----
func drwGmba x,y,frame
	DrawCircle(x+16,y+10,14,cBrown)
	DrawRectangle(x+2,y+10,28,16,cBrown)
	DrawRectangle(x+5,y+5,6,7,WHITE) DrawRectangle(x+21,y+5,6,7,WHITE)
	DrawRectangle(x+7,y+7,4,5,BLACK) DrawRectangle(x+23,y+7,4,5,BLACK)
	DrawLine(x+4,y+3,x+12,y+6,BLACK) DrawLine(x+28,y+3,x+20,y+6,BLACK)
	if frame=0
		DrawRectangle(x-1,y+24,11,8,cDBrown) DrawRectangle(x+22,y+24,11,8,cDBrown)
	else
		DrawRectangle(x+3,y+24,11,8,cDBrown) DrawRectangle(x+18,y+24,11,8,cDBrown) ok

func drwKpa x,y,frame
	DrawCircle(x+16,y+12,14,cGreen)
	DrawRectangle(x+3,y+10,26,16,cGreen)
	DrawCircle(x+16,y+14,8,cGold)
	DrawCircle(x+8,y+5,8,cSkin)
	DrawRectangle(x+2,y+1,5,5,WHITE) DrawRectangle(x+3,y+2,3,3,BLACK)
	if frame=0
		DrawRectangle(x+3,y+26,10,6,cSkin) DrawRectangle(x+19,y+26,10,6,cSkin)
	else
		DrawRectangle(x+1,y+26,10,6,cSkin) DrawRectangle(x+21,y+26,10,6,cSkin) ok

func drwShl x,y
	DrawCircle(x+16,y+12,14,cGreen) DrawCircle(x+16,y+12,8,cGold)

func drwSqsh x,y,type
	if type=EN_G
		DrawRectangle(x,y,32,6,cBrown)
		DrawRectangle(x+4,y+1,5,3,WHITE) DrawRectangle(x+21,y+1,5,3,WHITE) ok

# ---- Item Sprites ----
func drwCoin x,y,frame
	aw=[22,14,6,14] w=aw[frame+1] o=(22-w)/2
	DrawRectangle(x+o,y,w,22,cGold)
	if w>8
		DrawRectangle(x+o+2,y+2,w-4,18,cDGold)
		if w>12 DT("$",x+o+w/2-5,y+2,16,cGold) ok
	ok

func drwMush x,y
	DrawCircle(x+14,y+8,12,cRed)
	DrawRectangle(x+3,y+8,22,18,cSkin)
	DrawCircle(x+7,y+5,4,WHITE) DrawCircle(x+21,y+5,4,WHITE) DrawCircle(x+14,y+1,3,WHITE)
	DrawRectangle(x+8,y+14,4,4,BLACK) DrawRectangle(x+18,y+14,4,4,BLACK)

func drwStar x,y,g
	col=cGold
	if g[GATM]%8<4 col=cStarYel ok
	cx=x+14 cy=y+14
	DrawCircle(cx,cy,11,col)
	v1=new Vector2 v1.x=cx   v1.y=cy-15
	v2=new Vector2 v2.x=cx-6 v2.y=cy-4
	v3=new Vector2 v3.x=cx+6 v3.y=cy-4
	DrawTriangle(v1,v2,v3,col)
	v1=new Vector2 v1.x=cx   v1.y=cy+15
	v2=new Vector2 v2.x=cx-6 v2.y=cy+4
	v3=new Vector2 v3.x=cx+6 v3.y=cy+4
	DrawTriangle(v1,v2,v3,col)
	v1=new Vector2 v1.x=cx-15 v1.y=cy
	v2=new Vector2 v2.x=cx-4  v2.y=cy-6
	v3=new Vector2 v3.x=cx-4  v3.y=cy+6
	DrawTriangle(v1,v2,v3,col)
	v1=new Vector2 v1.x=cx+15 v1.y=cy
	v2=new Vector2 v2.x=cx+4  v2.y=cy-6
	v3=new Vector2 v3.x=cx+4  v3.y=cy+6
	DrawTriangle(v1,v2,v3,col)
	DrawRectangle(x+8,y+13,3,3,BLACK) DrawRectangle(x+18,y+13,3,3,BLACK)

# ---- HUD ----
func drwHUD g
	DrawRectangle(0,0,C_SW,38,cHUD)
	DT("MARIO",20,3,12,WHITE)
	DT(""+g[GSCR],20,17,18,WHITE)
	DrawRectangle(215,8,16,16,cGold)
	DT("$",218,8,14,cDGold)
	DT("x"+g[GCN],236,10,16,WHITE)
	DT("WORLD",370,3,12,WHITE)
	DT("1-"+g[GLVL],378,17,18,WHITE)
	DT("LIVES",540,3,12,WHITE)
	for i=1 to g[GLIV]
		DrawRectangle(540+(i-1)*20,17,14,10,cRed)
		DrawRectangle(542+(i-1)*20,19,10,8,cSkin) next
	if g[GBIG] DT("[BIG]",700,5,12,cRed) ok
	if g[GSTR]
		s=floor(g[GSTM]/60) DT("*"+s+"s",700,20,12,cGold) ok

# ---- Overlays ----
func drwDieOvr g
	DrawRectangle(0,0,C_SW,C_SH,cOverlay)
	if g[GLIV]>0
		t="Oops!" w=MeasureText(t,44)
		DT(t,floor((C_SW-w)/2)+2,floor(C_SH/2)-38,44,cDRed)
		DT(t,floor((C_SW-w)/2),floor(C_SH/2)-40,44,WHITE)
		drwMario(C_SW/2-14,floor(C_SH/2)+10,1,false,false,0,false,g)
		DT("x "+g[GLIV],C_SW/2+20,floor(C_SH/2)+18,28,WHITE) ok

func drwOver g
	ClearBackground(BLACK)
	t="GAME OVER" w=MeasureText(t,52)
	DT(t,floor((C_SW-w)/2)+2,floor(C_SH/2)-58,52,cDRed)
	DT(t,floor((C_SW-w)/2),floor(C_SH/2)-60,52,cRed)
	t="Score: "+g[GSCR] w=MeasureText(t,24)
	DT(t,floor((C_SW-w)/2),floor(C_SH/2)+10,24,WHITE)
	t="Press ENTER" w=MeasureText(t,18)
	if g[GATM]%60<42 DT(t,floor((C_SW-w)/2),floor(C_SH/2)+60,18,GRAY) ok

func drwLW g
	DrawRectangle(0,0,C_SW,C_SH,cOverlay2)
	t="LEVEL COMPLETE!" w=MeasureText(t,42)
	DT(t,floor((C_SW-w)/2)+2,floor(C_SH/2)-38,42,cQBord)
	DT(t,floor((C_SW-w)/2),floor(C_SH/2)-40,42,cGold)
	t="Score: "+g[GSCR] w=MeasureText(t,26)
	DT(t,floor((C_SW-w)/2),floor(C_SH/2)+20,26,WHITE)

func drwWinS g
	ClearBackground(BLACK)
	t="CONGRATULATIONS!" w=MeasureText(t,42)
	DT(t,floor((C_SW-w)/2)+2,122,42,cQBord)
	DT(t,floor((C_SW-w)/2),120,42,cGold)
	t="You Saved the Mushroom Kingdom!" w=MeasureText(t,22)
	DT(t,floor((C_SW-w)/2),200,22,WHITE)
	drwMario(C_SW/2-15,270,1,true,false,0,false,g)
	t="Final Score: "+g[GSCR] w=MeasureText(t,30)
	DT(t,floor((C_SW-w)/2),380,30,cRed)
	t="Coins: "+g[GCN] w=MeasureText(t,22)
	DT(t,floor((C_SW-w)/2),420,22,cGold)
	t="Press ENTER to Play Again" w=MeasureText(t,18)
	if g[GATM]%60<42 DT(t,floor((C_SW-w)/2),490,18,GRAY) ok
	DT("Made with Ring Language + RayLib",230,565,16,GRAY)

# ---- Utility ----
func isSld t
	if t=T_GND or t=T_GTOP or t=T_BRK or t=T_Q or t=T_BLK or
	   t=T_PTL or t=T_PTR or t=T_PBL or t=T_PBR
		return true ok
	return false

func rOvr x1,y1,w1,h1,x2,y2,w2,h2
	if x1+w1<=x2 return false ok
	if x2+w2<=x1 return false ok
	if y1+h1<=y2 return false ok
	if y2+h2<=y1 return false ok
	return true
