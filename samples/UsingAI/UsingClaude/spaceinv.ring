/*
	Ring Invaders - Space Invaders / Galaga Style
	Ring + RayLib | Waves, bullet patterns, shields, particles
*/

load "raylib.ring"

# Constants
C_SW=800 C_SH=700 C_FPS=60

# States
S_MNU=0 S_PLY=1 S_DIE=2 S_OVR=3 S_WIN=4 S_WAVE=5

# Enemy types
EN_BASIC=1 EN_MID=2 EN_TOP=3 EN_BOSS=4

# Game state - all globals
pX=400 pY=640 pW=36 pH=24 pSpeed=5
pShootT=0 pShootSpd=12
gST=S_MNU gSCR=0 gLIV=3
gATM=0 gDTM=0 gWave=1 gMaxWave=8
gShake=0

# Formation
formX=0.0 formY=0.0 formDX=0.6 formDY=0
formDropT=0 formDir=1 formSpeed=0.6

# Lists
bullets=[] ebuls=[] enemies=[] shields=[]
parts=[] fts=[] stars=[]

# Colors
cShipBody = ncc(60,180,255,255)
cShipWing = ncc(40,120,200,255)
cShipCkpt = ncc(200,220,255,255)
cShipFire = ncc(255,150,50,255)
cBullet   = ncc(255,255,100,255)
cBullet2  = ncc(255,255,255,255)
cEBul     = ncc(255,80,80,255)
cEBul2    = ncc(255,180,60,255)
cEnB1     = ncc(120,255,120,255)
cEnB2     = ncc(100,200,100,255)
cEnM1     = ncc(200,200,60,255)
cEnM2     = ncc(180,180,40,255)
cEnT1     = ncc(255,100,100,255)
cEnT2     = ncc(200,60,60,255)
cEnBoss   = ncc(255,60,200,255)
cEnBoss2  = ncc(200,40,150,255)
cShield   = ncc(60,255,60,255)
cShieldD  = ncc(30,150,30,255)
cHUD      = ncc(20,20,40,255)
cOverlay  = ncc(0,0,0,180)
cGold     = ncc(251,208,0,255)
cCyan     = ncc(0,220,240,255)

# ========== MAIN ==========
InitWindow(C_SW,C_SH,"Ring Invaders - Space Shooter")
SetTargetFPS(C_FPS)
initStars()

while !WindowShouldClose()
	switch gST
	on S_MNU updMenu()
	on S_PLY updGame()
	on S_WAVE updWaveScr()
	on S_DIE updDie()
	on S_OVR updOver()
	on S_WIN updWin()
	off
	BeginDrawing()
	ClearBackground(BLACK)
	drwStars()
	switch gST
	on S_MNU drwMenu()
	on S_PLY drwGame()
	on S_WAVE drwGame() drwWaveScr()
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

# ---- Stars ----
func initStars
	stars=[]
	for i=1 to 120
		add(stars,[:x=GetRandomValue(0,C_SW),
			:y=GetRandomValue(0,C_SH),
			:sp=GetRandomValue(1,3),
			:br=GetRandomValue(100,255)])
	next

func drwStars
	for i=1 to len(stars)
		stars[i][:y]+=stars[i][:sp]
		if stars[i][:y]>C_SH
			stars[i][:y]=0 stars[i][:x]=GetRandomValue(0,C_SW)
		ok
		a=stars[i][:br]
		DrawRectangle(stars[i][:x],stars[i][:y],stars[i][:sp],stars[i][:sp],
			ncc(a,a,a,a))
	next

# ---- Wave Builder ----
func buildWave num
	enemies=[] bullets=[] ebuls=[] parts=[] fts=[]
	formX=80 formY=60 formDX=0 formDY=0 formDir=1
	formSpeed=0.4+num*0.1
	if formSpeed>1.8 formSpeed=1.8 ok
	pShootT=0

	# Formation based on wave
	cols=8+floor(num/2)
	if cols>12 cols=12 ok

	# Top row - red (most points)
	for c=1 to cols
		ex=c*50
		add(enemies,[:x=ex,:y=0,:ox=ex,:oy=0,:alive=true,:hp=1,
			:type=EN_TOP,:pts=30,:frm=0,:ftm=0,:shootT=GetRandomValue(60,300)])
	next
	# Middle rows
	rows=2+floor(num/3)
	if rows>4 rows=4 ok
	for r=1 to rows
		for c=1 to cols
			ex=c*50
			ey=r*40
			tp=EN_MID
			if r>2 tp=EN_BASIC ok
			hp=1
			pts=20
			if tp=EN_BASIC pts=10 hp=1 ok
			add(enemies,[:x=ex,:y=ey,:ox=ex,:oy=ey,:alive=true,:hp=hp,
				:type=tp,:pts=pts,:frm=0,:ftm=0,:shootT=GetRandomValue(120,500)])
		next
	next

	# Boss on waves 4,8
	if num%4=0
		bx=cols*25+25
		add(enemies,[:x=bx,:y=-10,:ox=bx,:oy=-10,:alive=true,:hp=8+num,
			:type=EN_BOSS,:pts=500,:frm=0,:ftm=0,:shootT=40])
	ok

	# Build shields
	buildShields()

func buildShields
	shields=[]
	sx=[150,325,500,675]
	for s=1 to 4
		bx=sx[s]
		# Each shield is a set of blocks
		for r=0 to 3
			for c=0 to 5
				# Arch shape - skip top corners and bottom center
				skip=false
				if r=0 and (c=0 or c=5) skip=true ok
				if r=3 and (c=2 or c=3) skip=true ok
				if !skip
					add(shields,[:x=bx+c*8,:y=540+r*8,:hp=3])
				ok
			next
		next
	next

# ---- Menu ----
func updMenu
	gATM++
	if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE)
		gLIV=3 gSCR=0 gWave=1
		pX=400 pSpeed=5 pShootSpd=12
		buildWave(1)
		gST=S_WAVE gDTM=90
	ok

func drwMenu
	t="RING INVADERS" tw=MeasureText(t,56)
	DT(t,floor((C_SW-tw)/2)+3,73,56,ncc(40,120,200,255))
	DT(t,floor((C_SW-tw)/2),70,56,cShipBody)
	t="Space Shooter Arcade" tw=MeasureText(t,22)
	DT(t,floor((C_SW-tw)/2),140,22,cGold)
	# Ship
	drwShip(C_SW/2,260)
	# Enemy samples
	drwEnType(C_SW/2-100,340,EN_TOP,0)
	DT("= 30",C_SW/2-70,342,16,cEnT1)
	drwEnType(C_SW/2-100,375,EN_MID,0)
	DT("= 20",C_SW/2-70,377,16,cEnM1)
	drwEnType(C_SW/2-100,410,EN_BASIC,0)
	DT("= 10",C_SW/2-70,412,16,cEnB1)

	t="Press ENTER to Start" tw=MeasureText(t,20)
	if gATM%60<42 DT(t,floor((C_SW-tw)/2),470,20,WHITE) ok
	DT("Controls:",290,520,18,cGold)
	DT("Arrow Keys / A,D - Move",290,545,16,WHITE)
	DT("Space / X        - Shoot",290,565,16,WHITE)
	DT(""+ gMaxWave +" Waves of Alien Invaders!",290,600,16,cCyan)
	DT("Made with Ring Language + RayLib",240,665,16,GRAY)

# ---- Wave Screen ----
func updWaveScr
	gATM++ gDTM--
	if gDTM<=0 gST=S_PLY ok

func drwWaveScr
	DrawRectangle(0,0,C_SW,C_SH,cOverlay)
	t="WAVE "+gWave tw=MeasureText(t,48)
	DT(t,floor((C_SW-tw)/2),floor(C_SH/2)-30,48,cGold)

# ---- Game Update ----
func updGame
	gATM++
	if gShake>0 gShake-- ok
	if pShootT>0 pShootT-- ok
	updPlayer()
	updFormation()
	updBullets()
	updEBuls()
	updParts()
	updFTs()
	enShoot()
	chkWaveClr()

# ---- Player ----
func updPlayer
	if IsKeyDown(KEY_LEFT) or IsKeyDown(KEY_A)
		pX-=pSpeed
		if pX<20 pX=20 ok
	ok
	if IsKeyDown(KEY_RIGHT) or IsKeyDown(KEY_D)
		pX+=pSpeed
		if pX>C_SW-20 pX=C_SW-20 ok
	ok
	if (IsKeyDown(KEY_SPACE) or IsKeyDown(KEY_X)) and pShootT<=0
		add(bullets,[:x=pX,:y=pY-10,:vy=-8])
		pShootT=pShootSpd
	ok

# ---- Formation Movement ----
func updFormation
	# Move formation
	formX+=formSpeed*formDir

	# Find edges
	minX=9999 maxX=-9999
	alive=0
	for i=1 to len(enemies)
		if !enemies[i][:alive] loop ok
		alive++
		wx=formX+enemies[i][:ox]
		if wx<minX minX=wx ok
		if wx>maxX maxX=wx ok
	next

	if alive=0 return ok

	# Bounce off walls and drop
	if maxX>C_SW-30 or minX<30
		formDir=-formDir
		formY+=12
		# Speed up as fewer enemies remain
		formSpeed+=0.02
	ok

	# Update enemy world positions and animation
	for i=1 to len(enemies)
		if !enemies[i][:alive] loop ok
		enemies[i][:x]=formX+enemies[i][:ox]
		enemies[i][:y]=formY+enemies[i][:oy]
		enemies[i][:ftm]++
		if enemies[i][:ftm]>15
			enemies[i][:ftm]=0
			enemies[i][:frm]=1-enemies[i][:frm]
		ok
	next

	# Check if formation reached shields/player
	if formY+getMaxEY()>pY-30
		pDie()
	ok

func getMaxEY
	my=0
	for i=1 to len(enemies)
		if enemies[i][:alive] and enemies[i][:oy]>my
			my=enemies[i][:oy]
		ok
	next
	return my

# ---- Bullets ----
func updBullets
	for i=len(bullets) to 1 step -1
		bullets[i][:y]+=bullets[i][:vy]
		bx=bullets[i][:x] by=bullets[i][:y]
		if by<-10
			del(bullets,i) loop
		ok
		# Hit enemies
		hit=false
		for e=1 to len(enemies)
			if !enemies[e][:alive] loop ok
			ex=enemies[e][:x] ey=enemies[e][:y]
			ew=28 eh=24
			if enemies[e][:type]=EN_BOSS ew=48 eh=36 ok
			if bx>ex-ew/2 and bx<ex+ew/2 and by>ey-eh/2 and by<ey+eh/2
				enemies[e][:hp]--
				if enemies[e][:hp]<=0
					enemies[e][:alive]=false
					gSCR+=enemies[e][:pts]
					addFT(ex,ey-10,""+enemies[e][:pts])
					spawnDeathParts(ex,ey,enemies[e][:type])
					gShake=5
				else
					# Hit flash particles
					for k=1 to 4
						addPart(ex,ey,GetRandomValue(-2,2),GetRandomValue(-2,2),WHITE,8)
					next
				ok
				hit=true
				exit
			ok
		next
		if hit del(bullets,i) loop ok
		# Hit shields
		for s=len(shields) to 1 step -1
			sx=shields[s][:x] sy=shields[s][:y]
			if bx>sx and bx<sx+8 and by>sy and by<sy+8
				shields[s][:hp]--
				if shields[s][:hp]<=0
					addPart(sx+4,sy+4,0,-1,cShield,10)
					del(shields,s)
				ok
				hit=true
				exit
			ok
		next
		if hit del(bullets,i) ok
	next

func updEBuls
	for i=len(ebuls) to 1 step -1
		ebuls[i][:x]+=ebuls[i][:vx]
		ebuls[i][:y]+=ebuls[i][:vy]
		bx=ebuls[i][:x] by=ebuls[i][:y]
		if by>C_SH+10 or bx<-10 or bx>C_SW+10
			del(ebuls,i) loop
		ok
		# Hit player
		if bx>pX-pW/2 and bx<pX+pW/2 and by>pY-pH/2 and by<pY+pH/2
			pDie()
			del(ebuls,i) loop
		ok
		# Hit shields
		for s=len(shields) to 1 step -1
			sx=shields[s][:x] sy=shields[s][:y]
			if bx>sx and bx<sx+8 and by>sy and by<sy+8
				shields[s][:hp]--
				if shields[s][:hp]<=0
					del(shields,s)
				ok
				del(ebuls,i)
				exit
			ok
		next
	next

# ---- Enemy Shooting ----
func enShoot
	for i=1 to len(enemies)
		if !enemies[i][:alive] loop ok
		enemies[i][:shootT]--
		if enemies[i][:shootT]<=0
			ex=enemies[i][:x] ey=enemies[i][:y]
			et=enemies[i][:type]
			if et=EN_BASIC
				enemies[i][:shootT]=GetRandomValue(180,400)
				add(ebuls,[:x=ex,:y=ey+12,:vx=0,:vy=3])
			ok
			if et=EN_MID
				enemies[i][:shootT]=GetRandomValue(150,350)
				add(ebuls,[:x=ex,:y=ey+12,:vx=0,:vy=3.5])
			ok
			if et=EN_TOP
				enemies[i][:shootT]=GetRandomValue(120,300)
				# Aimed shot
				dx=pX-ex dy=pY-ey
				dist=sqrt(dx*dx+dy*dy)
				if dist<1 dist=1 ok
				spd=3.5
				add(ebuls,[:x=ex,:y=ey+12,:vx=dx/dist*spd,:vy=dy/dist*spd])
			ok
			if et=EN_BOSS
				enemies[i][:shootT]=GetRandomValue(30,60)
				# Spread pattern
				for a=-2 to 2
					add(ebuls,[:x=ex+a*10,:y=ey+20,:vx=a*0.8,:vy=4])
				next
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

func spawnDeathParts ex,ey,etype
	nc=cEnB1
	if etype=EN_MID nc=cEnM1 ok
	if etype=EN_TOP nc=cEnT1 ok
	if etype=EN_BOSS nc=cEnBoss ok
	cnt=12
	if etype=EN_BOSS cnt=30 ok
	for k=1 to cnt
		vx=GetRandomValue(-40,40)/10
		vy=GetRandomValue(-40,10)/10
		addPart(ex+GetRandomValue(-8,8),ey+GetRandomValue(-8,8),
			vx,vy,nc,GetRandomValue(15,30))
	next

# ---- Effects ----
func addFT x,y,txt
	add(fts,[:x=x,:y=y,:txt=txt,:tmr=40])

func updFTs
	for i=len(fts) to 1 step -1
		fts[i][:y]-=0.8 fts[i][:tmr]--
		if fts[i][:tmr]<=0 del(fts,i) ok
	next

# ---- Wave Check ----
func chkWaveClr
	alive=0
	for i=1 to len(enemies)
		if enemies[i][:alive] alive++ ok
	next
	if alive=0
		if gWave>=gMaxWave
			gST=S_WIN
		else
			gWave++
			buildWave(gWave)
			gST=S_WAVE gDTM=90
		ok
	ok

# ---- States ----
func pDie
	gLIV-- gDTM=90 gST=S_DIE
	spawnDeathParts(pX,pY,0)
	gShake=10

func updDie
	gATM++ gDTM--
	updParts()
	if gDTM<=0
		if gLIV<=0 gST=S_OVR
		else
			pX=400 pShootT=0
			bullets=[] ebuls=[]
			gST=S_PLY
		ok
	ok

func updOver
	gATM++
	if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE) gST=S_MNU ok

func updWin
	gATM++
	updParts()
	# Celebration particles
	if gATM%8=0
		addPart(GetRandomValue(100,C_SW-100),GetRandomValue(100,400),
			GetRandomValue(-3,3),GetRandomValue(-4,-1),
			ncc(GetRandomValue(100,255),GetRandomValue(100,255),GetRandomValue(100,255),255),30)
	ok
	if IsKeyPressed(KEY_ENTER) or IsKeyPressed(KEY_SPACE) gST=S_MNU ok

# ====================================================
# DRAWING
# ====================================================
func drwGame
	ox=0 oy=0
	if gShake>0
		ox=GetRandomValue(-2,2) oy=GetRandomValue(-2,2)
	ok
	# Shields
	for i=1 to len(shields)
		sc=cShield
		if shields[i][:hp]=1 sc=cShieldD ok
		DrawRectangle(shields[i][:x]+ox,shields[i][:y]+oy,8,8,sc)
	next
	# Enemies
	for i=1 to len(enemies)
		if !enemies[i][:alive] loop ok
		drwEnType(enemies[i][:x]+ox,enemies[i][:y]+oy,
			enemies[i][:type],enemies[i][:frm])
	next
	# Player bullets
	for i=1 to len(bullets)
		DrawRectangle(bullets[i][:x]-2+ox,bullets[i][:y]-6+oy,4,12,cBullet)
		DrawRectangle(bullets[i][:x]-1+ox,bullets[i][:y]-8+oy,2,8,cBullet2)
	next
	# Enemy bullets
	for i=1 to len(ebuls)
		DrawCircle(ebuls[i][:x]+ox,ebuls[i][:y]+oy,4,cEBul)
		DrawCircle(ebuls[i][:x]+ox,ebuls[i][:y]+oy,2,cEBul2)
	next
	# Particles
	for i=1 to len(parts)
		sz=3
		if parts[i][:life]<parts[i][:ml]/2 sz=2 ok
		DrawCircle(parts[i][:x]+ox,parts[i][:y]+oy,sz,parts[i][:nc])
	next
	# Player
	if gST!=S_DIE
		drwShip(pX+ox,pY+oy)
	ok
	# Floating texts
	for i=1 to len(fts)
		DT(fts[i][:txt],floor(fts[i][:x]-10),floor(fts[i][:y]),16,cGold)
	next
	drwHUD()

# ---- Ship ----
func drwShip x,y
	# Main body
	DrawRectangle(x-6,y-8,12,20,cShipBody)
	# Cockpit
	DrawRectangle(x-4,y-12,8,8,cShipCkpt)
	DrawRectangle(x-2,y-14,4,4,cShipCkpt)
	# Wings
	DrawRectangle(x-18,y,12,8,cShipWing)
	DrawRectangle(x+6,y,12,8,cShipWing)
	DrawRectangle(x-16,y-4,4,8,cShipWing)
	DrawRectangle(x+12,y-4,4,8,cShipWing)
	# Engine glow
	if gATM%4<2
		DrawRectangle(x-4,y+12,8,6,cShipFire)
		DrawRectangle(x-2,y+16,4,4,ncc(255,255,100,255))
	else
		DrawRectangle(x-3,y+12,6,4,cShipFire)
	ok

# ---- Enemy Types ----
func drwEnType x,y,etype,frm
	if etype=EN_BASIC
		DrawRectangle(x-12,y-8,24,16,cEnB1)
		DrawRectangle(x-10,y-6,20,12,cEnB2)
		DrawRectangle(x-6,y-4,4,4,BLACK)
		DrawRectangle(x+2,y-4,4,4,BLACK)
		if frm=0
			DrawRectangle(x-14,y+4,6,6,cEnB1)
			DrawRectangle(x+8,y+4,6,6,cEnB1)
		else
			DrawRectangle(x-14,y+2,6,6,cEnB1)
			DrawRectangle(x+8,y+2,6,6,cEnB1)
		ok
	ok
	if etype=EN_MID
		DrawRectangle(x-14,y-10,28,20,cEnM1)
		DrawRectangle(x-12,y-8,24,16,cEnM2)
		DrawRectangle(x-8,y-6,6,6,BLACK)
		DrawRectangle(x+2,y-6,6,6,BLACK)
		DrawRectangle(x-4,y+2,8,4,cEnM1)
		if frm=0
			DrawRectangle(x-16,y-2,6,10,cEnM1)
			DrawRectangle(x+10,y-2,6,10,cEnM1)
		else
			DrawRectangle(x-16,y+2,6,10,cEnM1)
			DrawRectangle(x+10,y+2,6,10,cEnM1)
		ok
	ok
	if etype=EN_TOP
		DrawRectangle(x-12,y-10,24,20,cEnT1)
		DrawRectangle(x-8,y-12,16,4,cEnT1)
		DrawRectangle(x-10,y-8,20,16,cEnT2)
		DrawRectangle(x-6,y-6,4,4,WHITE)
		DrawRectangle(x+2,y-6,4,4,WHITE)
		DrawRectangle(x-5,y-5,2,2,BLACK)
		DrawRectangle(x+3,y-5,2,2,BLACK)
		if frm=0
			DrawRectangle(x-14,y+4,6,4,cEnT1)
			DrawRectangle(x+8,y+4,6,4,cEnT1)
		else
			DrawRectangle(x-14,y-4,6,4,cEnT1)
			DrawRectangle(x+8,y-4,6,4,cEnT1)
		ok
	ok
	if etype=EN_BOSS
		# Big boss
		DrawRectangle(x-24,y-16,48,32,cEnBoss)
		DrawRectangle(x-20,y-12,40,24,cEnBoss2)
		DrawRectangle(x-14,y-8,8,8,WHITE)
		DrawRectangle(x+6,y-8,8,8,WHITE)
		DrawRectangle(x-12,y-6,4,4,BLACK)
		DrawRectangle(x+8,y-6,4,4,BLACK)
		DrawRectangle(x-8,y+6,16,4,ncc(255,100,100,255))
		# Antennas
		DrawRectangle(x-10,y-20,4,10,cEnBoss)
		DrawRectangle(x+6,y-20,4,10,cEnBoss)
		DrawCircle(x-8,y-22,4,cEnBoss)
		DrawCircle(x+8,y-22,4,cEnBoss)
		if frm=0
			DrawRectangle(x-28,y-4,8,14,cEnBoss)
			DrawRectangle(x+20,y-4,8,14,cEnBoss)
		else
			DrawRectangle(x-28,y+2,8,14,cEnBoss)
			DrawRectangle(x+20,y+2,8,14,cEnBoss)
		ok
	ok

# ---- HUD ----
func drwHUD
	DrawRectangle(0,0,C_SW,36,cHUD)
	DT("SCORE",15,4,12,WHITE)
	DT(""+gSCR,15,18,18,WHITE)
	DT("WAVE "+gWave+"/"+gMaxWave,floor(C_SW/2)-50,8,18,cGold)
	DT("LIVES",C_SW-130,4,12,WHITE)
	for i=1 to gLIV
		DrawRectangle(C_SW-125+(i-1)*22,20,8,10,cShipBody)
		DrawRectangle(C_SW-128+(i-1)*22,24,14,4,cShipWing)
	next
	# Enemy count
	alive=0
	for i=1 to len(enemies)
		if enemies[i][:alive] alive++ ok
	next
	DT("Enemies:"+alive,C_SW/2+80,8,14,cEnT1)

# ---- Overlays ----
func drwDieOvr
	DrawRectangle(0,0,C_SW,C_SH,cOverlay)
	if gLIV>0
		t="DESTROYED!" tw=MeasureText(t,40)
		DT(t,floor((C_SW-tw)/2),floor(C_SH/2)-20,40,cEBul)
	ok

func drwOverScr
	t="GAME OVER" tw=MeasureText(t,52)
	DT(t,floor((C_SW-tw)/2)+2,floor(C_SH/2)-58,52,ncc(150,30,30,255))
	DT(t,floor((C_SW-tw)/2),floor(C_SH/2)-60,52,cEBul)
	t="Score: "+gSCR tw=MeasureText(t,24)
	DT(t,floor((C_SW-tw)/2),floor(C_SH/2)+10,24,WHITE)
	t="Wave: "+gWave tw=MeasureText(t,20)
	DT(t,floor((C_SW-tw)/2),floor(C_SH/2)+45,20,cGold)
	t="Press ENTER" tw=MeasureText(t,18)
	if gATM%60<42 DT(t,floor((C_SW-tw)/2),floor(C_SH/2)+90,18,GRAY) ok

func drwWinScr
	for i=1 to len(parts)
		sz=3
		DrawCircle(parts[i][:x],parts[i][:y],sz,parts[i][:nc])
	next
	t="EARTH IS SAVED!" tw=MeasureText(t,48)
	DT(t,floor((C_SW-tw)/2)+2,floor(C_SH/2)-98,48,ncc(40,120,200,255))
	DT(t,floor((C_SW-tw)/2),floor(C_SH/2)-100,48,cShipBody)
	drwShip(C_SW/2,C_SH/2)
	t="Final Score: "+gSCR tw=MeasureText(t,28)
	DT(t,floor((C_SW-tw)/2),floor(C_SH/2)+50,28,cGold)
	t="Waves Cleared: "+gMaxWave tw=MeasureText(t,20)
	DT(t,floor((C_SW-tw)/2),floor(C_SH/2)+90,20,cCyan)
	t="Press ENTER" tw=MeasureText(t,18)
	if gATM%60<42 DT(t,floor((C_SW-tw)/2),floor(C_SH/2)+140,18,GRAY) ok
	DT("Made with Ring Language + RayLib",240,665,16,GRAY)
