/*
	Ring Kong - Classic Arcade Platformer
	Ring + RayLib | Inspired by classic barrel-jumping arcade games
	Single-screen levels, ladders, rolling barrels, rescue the princess!
*/

load "raylib.ring"

# Constants
C_SW=800 C_SH=600 C_FPS=60
C_GRAV=0.4 C_MAXF=8
C_SPD=2.5 C_CLIMB=2.0 C_JMP=-9.0
C_BARREL_SPD=2.5
C_TILE=40
C_COLS=20 C_ROWS=15

# States
S_MNU=0 S_PLY=1 S_DIE=2 S_WIN=3 S_OVR=4 S_LVLW=5

# Tile types
T_E=0 T_PLAT=1 T_LAD=2 T_LADPLAT=3

# Game data indices
GX=1 GY=2 GVX=3 GVY=4 GW=5 GH=6 GDIR=7
GGND=8 GCLIMB=9 GLIV=10 GSCR=11 GFRM=12 GFTM=13
GST=14 GLVL=15 GDTM=16 GATM=17 GJMP=18
GBTM=19 GBINT=20 GJBF=21

g=list(21)
g[GX]=60 g[GY]=0 g[GVX]=0 g[GVY]=0
g[GW]=24 g[GH]=32 g[GDIR]=1 g[GGND]=false
g[GCLIMB]=false g[GLIV]=3 g[GSCR]=0
g[GFRM]=0 g[GFTM]=0 g[GST]=S_MNU g[GLVL]=1
g[GDTM]=0 g[GATM]=0 g[GJMP]=false
g[GBTM]=0 g[GBINT]=90 g[GJBF]=0

# Global lists
lvl=[] barrels=[] rivets=[]

# Princess position
prinX=0 prinY=0
# Kong position
kongX=0 kongY=0
# Hammer
hamX=0 hamY=0 hamOn=false hamActive=false hamTimer=0

# Colors
cBrown   = cc(180,80,20,255)
cLBrown  = cc(220,140,80,255)
cDBrown  = cc(120,50,10,255)
cRed     = cc(229,37,33,255)
cDRed    = cc(160,20,20,255)
cBlue    = cc(60,60,220,255)
cSkin    = cc(252,160,68,255)
cShoe    = cc(107,66,12,255)
cGold    = cc(251,208,0,255)
cDGold   = cc(200,160,0,255)
cPink    = cc(255,150,180,255)
cLPink   = cc(255,200,220,255)
cGreen   = cc(0,180,0,255)
cDGreen  = cc(0,120,0,255)
cOrange  = cc(230,130,30,255)
cDOrange = cc(180,90,10,255)
cGray    = cc(160,160,160,255)
cDGray   = cc(100,100,100,255)
cLadder  = cc(120,200,255,255)
cLadDk   = cc(80,150,200,255)
cHUD     = cc(0,0,0,180)
cOverlay = cc(0,0,0,170)
cBarrel1 = cc(180,100,40,255)
cBarrel2 = cc(140,70,20,255)
cBarrel3 = cc(220,150,70,255)
cRivet   = cc(255,100,100,255)
cRivetOff= cc(100,60,60,255)
cSky     = cc(20,20,60,255)

# ========== MAIN LOOP ==========
InitWindow(C_SW,C_SH,"Ring Kong - Classic Arcade Platformer")
SetTargetFPS(C_FPS)
buildLvl(g,1)

while !WindowShouldClose()
	switch g[GST]
	on S_MNU  updMenu(g)
	on S_PLY  updGame(g)
	on S_DIE  updDie(g)
	on S_WIN  updWin(g)
	on S_OVR  updOver(g)
	on S_LVLW updLvlW(g)
	off

	BeginDrawing()
	ClearBackground(cSky)
	switch g[GST]
	on S_MNU  drwMenu(g)
	on S_PLY  drwGame(g)
	on S_DIE  drwGame(g) drwDieOvr(g)
	on S_WIN  drwWinScr(g)
	on S_OVR  drwOverScr(g)
	on S_LVLW drwGame(g) drwLvlW(g)
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

# ---- Level Building ----
func buildLvl g,num
	barrels=[] rivets=[]
	g[GCLIMB]=false g[GJMP]=false g[GBTM]=0
	hamActive=false hamOn=false hamTimer=0
	lvl=list(C_ROWS,C_COLS)
	for r=1 to C_ROWS for c=1 to C_COLS lvl[r][c]=T_E next next

	switch num
	on 1 bldL1(g)
	on 2 bldL2(g)
	on 3 bldL3(g)
	off

func bldL1 g
	g[GBINT]=90
	# Platform 1 (bottom) - slight slope
	for c=1 to C_COLS
		lvl[C_ROWS][c]=T_PLAT
	next
	# Platform 2
	for c=1 to 18
		lvl[C_ROWS-3][c]=T_PLAT
	next
	# Platform 3
	for c=3 to C_COLS
		lvl[C_ROWS-6][c]=T_PLAT
	next
	# Platform 4
	for c=1 to 18
		lvl[C_ROWS-9][c]=T_PLAT
	next
	# Top platform (Kong + Princess)
	for c=3 to 10
		lvl[3][c]=T_PLAT
	next

	# Ladders between platforms
	for r=C_ROWS-3 to C_ROWS-1 lvl[r][16]=T_LAD next
	lvl[C_ROWS-3][16]=T_LADPLAT

	for r=C_ROWS-6 to C_ROWS-4 lvl[r][5]=T_LAD next
	lvl[C_ROWS-6][5]=T_LADPLAT

	for r=C_ROWS-9 to C_ROWS-7 lvl[r][16]=T_LAD next
	lvl[C_ROWS-9][16]=T_LADPLAT

	for r=3 to C_ROWS-10 lvl[r][8]=T_LAD next
	lvl[3][8]=T_LADPLAT

	# Broken ladders (shorter, partial)
	for r=C_ROWS-2 to C_ROWS-1 lvl[r][8]=T_LAD next
	for r=C_ROWS-5 to C_ROWS-4 lvl[r][12]=T_LAD next
	for r=C_ROWS-8 to C_ROWS-7 lvl[r][4]=T_LAD next

	# Player start
	g[GX]=60 g[GY]=(C_ROWS-2)*C_TILE

	# Kong position
	kongX=3*C_TILE kongY=1*C_TILE

	# Princess position
	prinX=7*C_TILE prinY=1*C_TILE+4

	# Hammer pickup
	hamX=12*C_TILE hamY=(C_ROWS-4)*C_TILE-16 hamOn=true

func bldL2 g
	g[GBINT]=70
	for c=1 to C_COLS lvl[C_ROWS][c]=T_PLAT next
	for c=2 to 19 lvl[C_ROWS-3][c]=T_PLAT next
	for c=1 to 18 lvl[C_ROWS-6][c]=T_PLAT next
	for c=3 to C_COLS lvl[C_ROWS-9][c]=T_PLAT next
	for c=1 to 16 lvl[C_ROWS-12][c]=T_PLAT next
	for c=4 to 10 lvl[2][c]=T_PLAT next

	for r=C_ROWS-3 to C_ROWS-1 lvl[r][17]=T_LAD next
	lvl[C_ROWS-3][17]=T_LADPLAT
	for r=C_ROWS-6 to C_ROWS-4 lvl[r][4]=T_LAD next
	lvl[C_ROWS-6][4]=T_LADPLAT
	for r=C_ROWS-9 to C_ROWS-7 lvl[r][15]=T_LAD next
	lvl[C_ROWS-9][15]=T_LADPLAT
	for r=C_ROWS-12 to C_ROWS-10 lvl[r][6]=T_LAD next
	lvl[C_ROWS-12][6]=T_LADPLAT
	for r=2 to C_ROWS-13 lvl[r][8]=T_LAD next
	lvl[2][8]=T_LADPLAT

	for r=C_ROWS-2 to C_ROWS-1 lvl[r][9]=T_LAD next
	for r=C_ROWS-5 to C_ROWS-4 lvl[r][11]=T_LAD next
	for r=C_ROWS-8 to C_ROWS-7 lvl[r][8]=T_LAD next

	g[GX]=60 g[GY]=(C_ROWS-2)*C_TILE
	kongX=4*C_TILE kongY=0*C_TILE
	prinX=7*C_TILE prinY=0*C_TILE+4
	hamX=14*C_TILE hamY=(C_ROWS-7)*C_TILE-16 hamOn=true

func bldL3 g
	g[GBINT]=55
	for c=1 to C_COLS lvl[C_ROWS][c]=T_PLAT next
	for c=1 to 17 lvl[C_ROWS-2][c]=T_PLAT next
	for c=4 to C_COLS lvl[C_ROWS-5][c]=T_PLAT next
	for c=1 to 17 lvl[C_ROWS-7][c]=T_PLAT next
	for c=4 to C_COLS lvl[C_ROWS-9][c]=T_PLAT next
	for c=1 to 16 lvl[C_ROWS-11][c]=T_PLAT next
	for c=4 to 11 lvl[2][c]=T_PLAT next

	for r=C_ROWS-2 to C_ROWS-1 lvl[r][15]=T_LAD next
	lvl[C_ROWS-2][15]=T_LADPLAT
	for r=C_ROWS-5 to C_ROWS-3 lvl[r][6]=T_LAD next
	lvl[C_ROWS-5][6]=T_LADPLAT
	for r=C_ROWS-7 to C_ROWS-6 lvl[r][16]=T_LAD next
	lvl[C_ROWS-7][16]=T_LADPLAT
	for r=C_ROWS-9 to C_ROWS-8 lvl[r][5]=T_LAD next
	lvl[C_ROWS-9][5]=T_LADPLAT
	for r=C_ROWS-11 to C_ROWS-10 lvl[r][14]=T_LAD next
	lvl[C_ROWS-11][14]=T_LADPLAT
	for r=2 to C_ROWS-12 lvl[r][7]=T_LAD next
	lvl[2][7]=T_LADPLAT

	for r=C_ROWS-4 to C_ROWS-3 lvl[r][10]=T_LAD next
	for r=C_ROWS-8 to C_ROWS-8 lvl[r][10]=T_LAD next

	g[GX]=60 g[GY]=(C_ROWS-2)*C_TILE
	kongX=4*C_TILE kongY=0*C_TILE
	prinX=7*C_TILE prinY=0*C_TILE+4
	hamX=8*C_TILE hamY=(C_ROWS-3)*C_TILE-16 hamOn=true

# ---- Menu ----
func updMenu g
	g[GATM]++
	if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE)
		g[GST]=S_PLY g[GLIV]=3 g[GSCR]=0 g[GLVL]=1
		buildLvl(g,1)
	ok

func drwMenu g
	ClearBackground(BLACK)
	t="RING KONG" tw=MeasureText(t,64)
	DT(t,floor((C_SW-tw)/2)+3,73,64,cDRed)
	DT(t,floor((C_SW-tw)/2),70,64,cRed)
	t="A Classic Arcade Game" tw=MeasureText(t,22)
	DT(t,floor((C_SW-tw)/2),145,22,cGold)

	# Draw Kong
	drwKong(C_SW/2-40,200,g)
	# Draw Princess
	drwPrincess(C_SW/2+30,210,g)

	t="Press ENTER or SPACE to Start" tw=MeasureText(t,20)
	if g[GATM]%60<42 DT(t,floor((C_SW-tw)/2),360,20,WHITE) ok

	DT("Controls:",250,420,20,cGold)
	DT("Arrow Keys / WASD  -  Move & Climb",250,448,16,WHITE)
	DT("Space / Up / W     -  Jump",250,468,16,WHITE)
	DT("Climb ladders to reach the top!",250,498,16,cLadder)
	DT("Avoid barrels! Grab the hammer!",250,518,16,cOrange)
	DT("Made with Ring Language + RayLib",240,570,16,GRAY)

# ---- Game Update ----
func updGame g
	g[GATM]++
	if g[GJBF]>0 g[GJBF]-- ok
	updPlayer(g)
	updBarrels(g)
	updHammer(g)
	chkBarrelCol(g)
	chkWin(g)
	# Spawn barrels
	g[GBTM]++
	if g[GBTM]>=g[GBINT]
		g[GBTM]=0
		spawnBarrel(g)
	ok

func spawnBarrel g
	bx=kongX+30
	by=kongY+40
	add(barrels, [:x=bx,:y=by,:vx=C_BARREL_SPD,:vy=0,:onlad=false,:frame=0,:ft=0,:falling=false])

# ---- Player ----
func updPlayer g
	ml=IsKeyDown(KEY_LEFT) or IsKeyDown(KEY_A)
	mr=IsKeyDown(KEY_RIGHT) or IsKeyDown(KEY_D)
	mu=IsKeyDown(KEY_UP) or IsKeyDown(KEY_W)
	md=IsKeyDown(KEY_DOWN) or IsKeyDown(KEY_S)
	# Jump only with SPACE (not Up - Up is for climb)
	jkP=IsKeyPressed(KEY_SPACE)

	if jkP g[GJBF]=6 ok

	px=g[GX] py=g[GY] pw=g[GW] ph=g[GH]

	# Check if on ladder - use wider detection (check 3 points across player width)
	onLadder=false
	ladAbove=false
	for xoff=4 to pw-4 step 8
		pcol=floor((px+xoff)/C_TILE)+1
		if pcol>=1 and pcol<=C_COLS
			prowFeet=floor((py+ph)/C_TILE)+1
			prowMid=floor((py+ph/2)/C_TILE)+1
			prowTop=floor(py/C_TILE)+1
			if prowMid>=1 and prowMid<=C_ROWS
				t=lvl[prowMid][pcol]
				if t=T_LAD or t=T_LADPLAT onLadder=true ok
			ok
			if prowFeet>=1 and prowFeet<=C_ROWS
				t=lvl[prowFeet][pcol]
				if t=T_LAD or t=T_LADPLAT onLadder=true ok
			ok
			# Check one row below feet too (for starting climb from platform)
			prowBelow=prowFeet+1
			if prowBelow>=1 and prowBelow<=C_ROWS
				t=lvl[prowBelow][pcol]
				if t=T_LAD or t=T_LADPLAT onLadder=true ok
			ok
			if prowTop>=1 and prowTop<=C_ROWS
				t=lvl[prowTop][pcol]
				if t=T_LAD or t=T_LADPLAT ladAbove=true ok
			ok
		ok
	next

	# Find closest ladder column for snapping
	bestLadCol=0
	bestDist=999
	for xoff=0 to pw step 4
		tc=floor((px+xoff)/C_TILE)+1
		if tc>=1 and tc<=C_COLS
			for rr=floor(py/C_TILE)+1 to floor((py+ph)/C_TILE)+2
				if rr>=1 and rr<=C_ROWS
					tt=lvl[rr][tc]
					if tt=T_LAD or tt=T_LADPLAT
						cx=(tc-1)*C_TILE+C_TILE/2
						dist=fabs(px+pw/2-cx)
						if dist<bestDist
							bestDist=dist bestLadCol=tc
						ok
					ok
				ok
			next
		ok
	next

	# Climbing
	if g[GCLIMB]
		g[GVX]=0 g[GVY]=0
		if mu and (onLadder or ladAbove)
			g[GY]-=C_CLIMB
			g[GFTM]++
			if g[GFTM]>8
				g[GFTM]=0 g[GFRM]++
				if g[GFRM]>1 g[GFRM]=0 ok
			ok
		but md and onLadder
			g[GY]+=C_CLIMB
			g[GFTM]++
			if g[GFTM]>8
				g[GFTM]=0 g[GFRM]++
				if g[GFRM]>1 g[GFRM]=0 ok
			ok
		ok
		if ml g[GX]-=C_SPD g[GDIR]=-1 g[GCLIMB]=false ok
		if mr g[GX]+=C_SPD g[GDIR]=1 g[GCLIMB]=false ok
		if !onLadder and !ladAbove g[GCLIMB]=false ok
		# Snap to platform when reaching top
		prow2=floor((g[GY]+ph)/C_TILE)+1
		pcol2=floor((g[GX]+pw/2)/C_TILE)+1
		if prow2>=1 and prow2<=C_ROWS and pcol2>=1 and pcol2<=C_COLS
			t2=lvl[prow2][pcol2]
			if t2=T_PLAT or t2=T_LADPLAT
				g[GY]=(prow2-1)*C_TILE-ph
				g[GGND]=true
				if !mu and !md g[GCLIMB]=false ok
			ok
		ok
	else
		# Normal movement
		if ml g[GVX]=-C_SPD g[GDIR]=-1
		but mr g[GVX]=C_SPD g[GDIR]=1
		else g[GVX]=0 ok

		# Start climbing UP - prioritize over jump
		if mu and (onLadder or ladAbove) and g[GGND]
			g[GCLIMB]=true
			if bestLadCol>0
				g[GX]=(bestLadCol-1)*C_TILE+(C_TILE-pw)/2
			ok
			g[GVY]=0 g[GGND]=false g[GJBF]=0
		ok
		# Start climbing DOWN
		if md and onLadder
			g[GCLIMB]=true
			if bestLadCol>0
				g[GX]=(bestLadCol-1)*C_TILE+(C_TILE-pw)/2
			ok
			g[GVY]=0
		ok

		# Jump
		if g[GJBF]>0 and g[GGND] and !g[GCLIMB]
			g[GVY]=C_JMP g[GGND]=false g[GJBF]=0 g[GJMP]=true
		ok

		if !g[GGND] and !g[GCLIMB]
			g[GVY]+=C_GRAV
			if g[GVY]>C_MAXF g[GVY]=C_MAXF ok
		ok

		g[GX]+=g[GVX]
		g[GY]+=g[GVY]

		# Anim
		if g[GVX]!=0 and g[GGND]
			g[GFTM]++
			if g[GFTM]>6
				g[GFTM]=0 g[GFRM]++
				if g[GFRM]>3 g[GFRM]=0 ok
			ok
		else
			if g[GGND] g[GFRM]=0 ok
		ok

		# Platform collision
		g[GGND]=false
		px=g[GX] py=g[GY]
		# Check below feet
		feetRow=floor((py+ph)/C_TILE)+1
		if feetRow>=1 and feetRow<=C_ROWS
			lc=floor(px/C_TILE)+1
			rc=floor((px+pw-1)/C_TILE)+1
			for c=lc to rc
				if c>=1 and c<=C_COLS
					t=lvl[feetRow][c]
					if t=T_PLAT or t=T_LADPLAT
						if g[GVY]>=0
							platY=(feetRow-1)*C_TILE
							if py+ph>=platY and py+ph<=platY+8
								g[GY]=platY-ph
								g[GVY]=0 g[GGND]=true
								if g[GJMP]
									g[GJMP]=false g[GSCR]+=100
								ok
							ok
						ok
					ok
				ok
			next
		ok
	ok

	# Boundaries
	if g[GX]<0 g[GX]=0 ok
	if g[GX]>C_SW-pw g[GX]=C_SW-pw ok
	if g[GY]>C_SH+50 pDie(g) ok

	# Hammer pickup
	if hamOn and !hamActive
		if rOvr(px,py,pw,ph,hamX,hamY,20,20)
			hamOn=false hamActive=true hamTimer=480
			g[GSCR]+=500
		ok
	ok

# ---- Barrels ----
func updBarrels g
	for i=len(barrels) to 1 step -1
		b=barrels[i]
		bx=b[:x] by=b[:y] bvx=b[:vx]

		# Animate
		b[:ft]++
		if b[:ft]>6
			b[:ft]=0 b[:frame]++
			if b[:frame]>3 b[:frame]=0 ok
		ok

		# Check if on ladder - random chance to go down
		bcol=floor((bx+16)/C_TILE)+1
		brow=floor((by+32)/C_TILE)+1

		if !b[:falling] and !b[:onlad]
			if bcol>=1 and bcol<=C_COLS and brow>=1 and brow<=C_ROWS
				t=lvl[brow][bcol]
				if (t=T_LAD or t=T_LADPLAT) and GetRandomValue(1,100)<15
					b[:onlad]=true b[:vx]=0
				ok
			ok
		ok

		if b[:onlad]
			by+=2.5
			b[:y]=by
			brow2=floor((by+32)/C_TILE)+1
			if brow2>=1 and brow2<=C_ROWS and bcol>=1 and bcol<=C_COLS
				t2=lvl[brow2][bcol]
				if t2=T_PLAT
					b[:y]=(brow2-1)*C_TILE-32
					b[:onlad]=false
					if bvx>0 b[:vx]=-C_BARREL_SPD
					else b[:vx]=C_BARREL_SPD ok
				ok
			ok
			if brow2>C_ROWS b[:onlad]=false ok
		else
			# Gravity
			b[:vy]+=C_GRAV
			if b[:vy]>C_MAXF b[:vy]=C_MAXF ok
			bx+=b[:vx]
			by+=b[:vy]
			b[:x]=bx b[:y]=by

			# Platform check
			frow=floor((by+32)/C_TILE)+1
			if frow>=1 and frow<=C_ROWS
				fcol=floor((bx+16)/C_TILE)+1
				if fcol>=1 and fcol<=C_COLS
					t=lvl[frow][fcol]
					if t=T_PLAT or t=T_LADPLAT
						platY=(frow-1)*C_TILE
						if by+32>=platY and by+32<=platY+10
							b[:y]=platY-32 b[:vy]=0
							b[:falling]=false
						ok
					ok
				ok
			ok

			# Bounce off walls
			if bx<0 b[:x]=0 b[:vx]=-b[:vx] ok
			if bx>C_SW-32 b[:x]=C_SW-32 b[:vx]=-b[:vx] ok
		ok

		barrels[i]=b

		# Remove if off screen
		if b[:y]>C_SH+40 del(barrels,i) ok
	next

# ---- Hammer ----
func updHammer g
	if hamActive
		hamTimer--
		if hamTimer<=0 hamActive=false ok
	ok

# ---- Barrel Collision ----
func chkBarrelCol g
	px=g[GX] py=g[GY] pw=g[GW] ph=g[GH]
	for i=len(barrels) to 1 step -1
		bx=barrels[i][:x] by=barrels[i][:y]
		if rOvr(px,py,pw,ph,bx+4,by+4,24,28)
			if hamActive
				del(barrels,i)
				g[GSCR]+=300
			else
				pDie(g)
				return
			ok
		ok
		# Score for jumping over barrel
		if g[GJMP] and !g[GGND]
			if py+ph<by+16 and py+ph>by-20
				if px+pw>bx and px<bx+32
					g[GSCR]+=100
				ok
			ok
		ok
	next

# ---- Win Check ----
func chkWin g
	px=g[GX] py=g[GY] pw=g[GW] ph=g[GH]
	if rOvr(px,py,pw,ph,prinX,prinY,28,36)
		g[GSCR]+=2000
		if g[GLVL]<3
			g[GST]=S_LVLW g[GDTM]=120
		else
			g[GST]=S_WIN
		ok
	ok

func pDie g
	g[GLIV]-- g[GDTM]=90 g[GST]=S_DIE

# ---- States ----
func updDie g
	g[GATM]++
	g[GDTM]--
	if g[GDTM]<=0
		if g[GLIV]<=0 g[GST]=S_OVR
		else g[GST]=S_PLY buildLvl(g,g[GLVL]) ok
	ok

func updOver g
	g[GATM]++
	if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE) g[GST]=S_MNU ok

func updWin g
	g[GATM]++
	if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE) g[GST]=S_MNU ok

func updLvlW g
	g[GATM]++
	g[GDTM]--
	if g[GDTM]<=0
		g[GLVL]++
		buildLvl(g,g[GLVL])
		g[GST]=S_PLY
	ok

# ====================================================
# DRAWING
# ====================================================
func drwGame g
	# Draw tiles
	for r=1 to C_ROWS
		for c=1 to C_COLS
			t=lvl[r][c]
			x=(c-1)*C_TILE y=(r-1)*C_TILE
			if t=T_PLAT drwPlat(x,y) ok
			if t=T_LAD drwLadder(x,y) ok
			if t=T_LADPLAT
				drwPlat(x,y)
				drwLadder(x,y)
			ok
		next
	next
	# Kong
	drwKong(kongX,kongY,g)
	# Princess
	drwPrincess(prinX,prinY,g)
	# Hammer pickup
	if hamOn drwHammerPU(hamX,hamY,g) ok
	# Barrels
	for i=1 to len(barrels)
		drwBarrel(barrels[i][:x],barrels[i][:y],barrels[i][:frame])
	next
	# Player
	drwPlayer(g)
	# HUD
	drwHUD(g)

# ---- Platforms ----
func drwPlat x,y
	DrawRectangle(x,y,C_TILE,10,cRed)
	DrawRectangle(x,y+2,C_TILE,6,cDRed)
	DrawRectangle(x+1,y,C_TILE-2,3,cRed)

# ---- Ladders ----
func drwLadder x,y
	# Two rails
	DrawRectangle(x+8,y,4,C_TILE,cLadder)
	DrawRectangle(x+28,y,4,C_TILE,cLadder)
	# Rungs
	DrawRectangle(x+8,y+8,24,3,cLadDk)
	DrawRectangle(x+8,y+24,24,3,cLadDk)

# ---- Player ----
func drwPlayer g
	x=g[GX] y=g[GY] dir=g[GDIR] frame=g[GFRM]
	# Hammer effect
	if hamActive
		if g[GATM]%20<10
			# Hammer swung up
			if dir=1
				DrawRectangle(x+20,y-16,6,20,cShoe)
				DrawRectangle(x+16,y-20,14,8,cGray)
			else
				DrawRectangle(x-4,y-16,6,20,cShoe)
				DrawRectangle(x-8,y-20,14,8,cGray)
			ok
		else
			# Hammer to side
			if dir=1
				DrawRectangle(x+22,y+4,20,4,cShoe)
				DrawRectangle(x+38,y,8,12,cGray)
			else
				DrawRectangle(x-18,y+4,20,4,cShoe)
				DrawRectangle(x-22,y,8,12,cGray)
			ok
		ok
	ok

	if g[GCLIMB]
		# Climbing sprite
		DrawRectangle(x+4,y,16,6,cRed)
		DrawRectangle(x+6,y+6,12,8,cSkin)
		DrawRectangle(x+4,y+14,16,10,cRed)
		DrawRectangle(x+6,y+20,12,4,cBlue)
		if frame=0
			DrawRectangle(x+2,y+24,8,8,cBlue)
			DrawRectangle(x+14,y+24,8,8,cBlue)
		else
			DrawRectangle(x,y+24,8,8,cBlue)
			DrawRectangle(x+16,y+24,8,8,cBlue)
		ok
	but !g[GGND]
		# Jump sprite
		DrawRectangle(x+2,y,20,6,cRed)
		DrawRectangle(x+4,y+6,16,8,cSkin)
		if dir=1 DrawRectangle(x+14,y+8,4,3,BLACK)
		else DrawRectangle(x+6,y+8,4,3,BLACK) ok
		DrawRectangle(x+2,y+14,20,8,cRed)
		DrawRectangle(x+4,y+18,16,4,cBlue)
		DrawRectangle(x,y+22,8,6,cBlue)
		DrawRectangle(x+16,y+22,8,6,cBlue)
		DrawRectangle(x-2,y+28,10,4,cShoe)
		DrawRectangle(x+16,y+28,10,4,cShoe)
	else
		# Walking sprite
		DrawRectangle(x+2,y,20,6,cRed)
		DrawRectangle(x+4,y+6,16,8,cSkin)
		if dir=1 DrawRectangle(x+14,y+8,4,3,BLACK)
		else DrawRectangle(x+6,y+8,4,3,BLACK) ok
		DrawRectangle(x+6,y+12,10,2,cShoe)
		DrawRectangle(x+2,y+14,20,8,cRed)
		DrawRectangle(x+4,y+18,16,4,cBlue)
		if frame=0 or frame=2
			DrawRectangle(x+4,y+24,8,4,cBlue)
			DrawRectangle(x+12,y+24,8,4,cBlue)
			DrawRectangle(x+2,y+28,10,4,cShoe)
			DrawRectangle(x+12,y+28,10,4,cShoe)
		but frame=1
			DrawRectangle(x,y+24,8,4,cBlue)
			DrawRectangle(x+16,y+24,8,4,cBlue)
			DrawRectangle(x-2,y+28,10,4,cShoe)
			DrawRectangle(x+16,y+28,10,4,cShoe)
		but frame=3
			DrawRectangle(x+6,y+24,8,4,cBlue)
			DrawRectangle(x+10,y+24,8,4,cBlue)
			DrawRectangle(x+4,y+28,10,4,cShoe)
			DrawRectangle(x+10,y+28,10,4,cShoe)
		ok
	ok

# ---- Kong ----
func drwKong x,y,g
	# Body
	DrawRectangle(x,y+10,60,40,cBrown)
	DrawRectangle(x+5,y+15,50,30,cDBrown)
	# Head
	DrawRectangle(x+10,y-5,40,22,cBrown)
	DrawRectangle(x+15,y,30,15,cDBrown)
	# Eyes
	DrawRectangle(x+18,y+2,8,8,WHITE)
	DrawRectangle(x+34,y+2,8,8,WHITE)
	DrawRectangle(x+20,y+4,5,5,BLACK)
	DrawRectangle(x+36,y+4,5,5,BLACK)
	# Mouth
	DrawRectangle(x+20,y+12,20,4,cDRed)
	# Arms
	if g[GATM]%60<30
		DrawRectangle(x-15,y+15,18,10,cBrown)
		DrawRectangle(x+57,y+15,18,10,cBrown)
	else
		DrawRectangle(x-15,y+20,18,10,cBrown)
		DrawRectangle(x+57,y+20,18,10,cBrown)
	ok
	# Legs
	DrawRectangle(x+8,y+48,16,12,cBrown)
	DrawRectangle(x+36,y+48,16,12,cBrown)

# ---- Princess ----
func drwPrincess x,y,g
	# Dress
	DrawRectangle(x+4,y+14,20,22,cPink)
	DrawRectangle(x+2,y+28,24,8,cPink)
	# Head
	DrawRectangle(x+6,y,16,14,cSkin)
	# Hair
	DrawRectangle(x+4,y-4,20,8,cGold)
	DrawRectangle(x+2,y+2,4,6,cGold)
	DrawRectangle(x+22,y+2,4,6,cGold)
	# Crown
	DrawRectangle(x+8,y-8,12,6,cGold)
	DrawRectangle(x+6,y-10,4,4,cGold)
	DrawRectangle(x+12,y-12,4,4,cGold)
	DrawRectangle(x+18,y-10,4,4,cGold)
	# Eyes
	DrawRectangle(x+9,y+4,3,3,BLACK)
	DrawRectangle(x+16,y+4,3,3,BLACK)
	# Help text
	if g[GATM]%90<60
		DT("HELP!",x-6,y-26,12,WHITE)
	ok

# ---- Hammer Pickup ----
func drwHammerPU x,y,g
	if g[GATM]%30<20
		DrawRectangle(x+6,y,4,16,cShoe)
		DrawRectangle(x+2,y-2,12,6,cGray)
		DrawRectangle(x+3,y-1,10,4,cDGray)
	ok

# ---- Barrel ----
func drwBarrel x,y,frame
	DrawRectangle(x+2,y+2,28,28,cBarrel1)
	DrawRectangle(x+4,y+4,24,24,cBarrel2)
	# Bands
	if frame=0 or frame=2
		DrawRectangle(x+2,y+8,28,3,cBarrel3)
		DrawRectangle(x+2,y+20,28,3,cBarrel3)
		DrawRectangle(x+14,y+2,4,28,cBarrel3)
	but frame=1 or frame=3
		DrawRectangle(x+8,y+2,3,28,cBarrel3)
		DrawRectangle(x+20,y+2,3,28,cBarrel3)
		DrawRectangle(x+2,y+14,28,4,cBarrel3)
	ok

# ---- HUD ----
func drwHUD g
	DrawRectangle(0,0,C_SW,36,cHUD)
	DT("SCORE",20,3,12,WHITE)
	DT(""+g[GSCR],20,17,18,WHITE)
	DT("LEVEL",floor(C_SW/2)-40,3,12,WHITE)
	DT(""+g[GLVL],floor(C_SW/2)-30,17,18,cGold)
	DT("LIVES",C_SW-120,3,12,WHITE)
	for i=1 to g[GLIV]
		DrawRectangle(C_SW-120+(i-1)*22,17,14,10,cRed)
		DrawRectangle(C_SW-118+(i-1)*22,19,10,8,cSkin)
	next
	if hamActive
		hs=floor(hamTimer/60)
		DT("HAMMER:"+hs+"s",C_SW-260,10,16,cGold)
	ok

# ---- Overlays ----
func drwDieOvr g
	DrawRectangle(0,0,C_SW,C_SH,cOverlay)
	if g[GLIV]>0
		t="Oops!" tw=MeasureText(t,44)
		DT(t,floor((C_SW-tw)/2)+2,floor(C_SH/2)-38,44,cDRed)
		DT(t,floor((C_SW-tw)/2),floor(C_SH/2)-40,44,WHITE)
		t="Lives: "+g[GLIV] tw=MeasureText(t,24)
		DT(t,floor((C_SW-tw)/2),floor(C_SH/2)+10,24,WHITE)
	ok

func drwOverScr g
	ClearBackground(BLACK)
	t="GAME OVER" tw=MeasureText(t,52)
	DT(t,floor((C_SW-tw)/2)+2,floor(C_SH/2)-58,52,cDRed)
	DT(t,floor((C_SW-tw)/2),floor(C_SH/2)-60,52,cRed)
	t="Final Score: "+g[GSCR] tw=MeasureText(t,24)
	DT(t,floor((C_SW-tw)/2),floor(C_SH/2)+10,24,WHITE)
	t="Press ENTER" tw=MeasureText(t,18)
	if g[GATM]%60<42 DT(t,floor((C_SW-tw)/2),floor(C_SH/2)+60,18,GRAY) ok

func drwLvlW g
	DrawRectangle(0,0,C_SW,C_SH,cOverlay)
	t="LEVEL COMPLETE!" tw=MeasureText(t,42)
	DT(t,floor((C_SW-tw)/2)+2,floor(C_SH/2)-38,42,cDGold)
	DT(t,floor((C_SW-tw)/2),floor(C_SH/2)-40,42,cGold)
	t="Score: "+g[GSCR] tw=MeasureText(t,26)
	DT(t,floor((C_SW-tw)/2),floor(C_SH/2)+20,26,WHITE)

func drwWinScr g
	ClearBackground(BLACK)
	t="CONGRATULATIONS!" tw=MeasureText(t,42)
	DT(t,floor((C_SW-tw)/2)+2,82,42,cDGold)
	DT(t,floor((C_SW-tw)/2),80,42,cGold)
	t="You Rescued the Princess!" tw=MeasureText(t,26)
	DT(t,floor((C_SW-tw)/2),160,26,cPink)
	# Draw hero and princess
	drwPlayer2(C_SW/2-40,250)
	drwPrincess(C_SW/2+10,248,g)
	# Heart
	if g[GATM]%40<30
		DrawCircle(C_SW/2-4,235,8,cRed)
		DrawCircle(C_SW/2+8,235,8,cRed)
		v1=new Vector2 v1.x=C_SW/2-12 v1.y=238
		v2=new Vector2 v2.x=C_SW/2+16 v2.y=238
		v3=new Vector2 v3.x=C_SW/2+2 v3.y=252
		DrawTriangle(v1,v2,v3,cRed)
	ok
	t="Final Score: "+g[GSCR] tw=MeasureText(t,30)
	DT(t,floor((C_SW-tw)/2),340,30,cGold)
	t="Press ENTER to Play Again" tw=MeasureText(t,18)
	if g[GATM]%60<42 DT(t,floor((C_SW-tw)/2),420,18,GRAY) ok
	DT("Made with Ring Language + RayLib",240,570,16,GRAY)

# Static player for win screen
func drwPlayer2 x,y
	DrawRectangle(x+2,y,20,6,cRed)
	DrawRectangle(x+4,y+6,16,8,cSkin)
	DrawRectangle(x+14,y+8,4,3,BLACK)
	DrawRectangle(x+6,y+12,10,2,cShoe)
	DrawRectangle(x+2,y+14,20,8,cRed)
	DrawRectangle(x+4,y+18,16,4,cBlue)
	DrawRectangle(x+4,y+24,8,4,cBlue)
	DrawRectangle(x+12,y+24,8,4,cBlue)
	DrawRectangle(x+2,y+28,10,4,cShoe)
	DrawRectangle(x+12,y+28,10,4,cShoe)

# ---- Utility ----
func isSld t
	if t=T_PLAT or t=T_LADPLAT return true ok
	return false

func rOvr x1,y1,w1,h1,x2,y2,w2,h2
	if x1+w1<=x2 return false ok
	if x2+w2<=x1 return false ok
	if y1+h1<=y2 return false ok
	if y2+h2<=y1 return false ok
	return true

func fabs v
	if v<0 return -v ok
	return v
