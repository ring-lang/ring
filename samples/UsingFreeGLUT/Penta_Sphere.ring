# ============================================================
#  Dodecahedron Sphere  -  Ghost Wireframe Sphere
#  12 pentagonal faces - all 5-sided panels
#  20 vertices, 30 edges - mathematically exact
#  Uses: opengl21lib.ring  and  freeglut.ring
#  Bert Mariani with Claude AI
#  2026-04-05
# ============================================================

Load "opengl21lib.ring"
Load "freeglut.ring"

# ---------- CONSTANTS ---------------------------------------
PI   = 3.14159265358979
GRAD = 0.055
RRAD = 0.015

# ---------- GLOBALS -----------------------------------------
rotX   = 20.0
rotY   = 30.0
lastX  = 0
lastY  = 0
isDrag = 0
winW   = 800
winH   = 800

# ---------- DODECAHEDRON VERTICES ---------------------------
# Golden ratio
phi = (1.0 + sqrt(5.0)) / 2.0
p   = phi
ip  = 1.0 / phi

# Exact 20 vertices of regular dodecahedron
verts = []

# 8 cube vertices (+-1, +-1, +-1)
verts + [ 1,  1,  1]   # 1
verts + [ 1,  1, -1]   # 2
verts + [ 1, -1,  1]   # 3
verts + [ 1, -1, -1]   # 4
verts + [-1,  1,  1]   # 5
verts + [-1,  1, -1]   # 6
verts + [-1, -1,  1]   # 7
verts + [-1, -1, -1]   # 8

# 4 vertices (0, +-phi, +-1/phi)
verts + [ 0,  p,  ip]  # 9
verts + [ 0,  p, -ip]  # 10
verts + [ 0, -p,  ip]  # 11
verts + [ 0, -p, -ip]  # 12

# 4 vertices (+-1/phi, 0, +-phi)
verts + [ ip,  0,  p]  # 13
verts + [ ip,  0, -p]  # 14
verts + [-ip,  0,  p]  # 15
verts + [-ip,  0, -p]  # 16

# 4 vertices (+-phi, +-1/phi, 0)
verts + [ p,  ip,  0]  # 17
verts + [ p, -ip,  0]  # 18
verts + [-p,  ip,  0]  # 19
verts + [-p, -ip,  0]  # 20

# normalize all to unit sphere
for i = 1 to len(verts)
    v = verts[i]
    L = sqrt(v[1]*v[1] + v[2]*v[2] + v[3]*v[3])
    verts[i] = [v[1]/L, v[2]/L, v[3]/L]
next

# ---------- 12 EXACT PENTAGONAL FACES -----------------------
# Each face lists 5 vertex indices in order around the pentagon
# Verified: each vertex appears in exactly 3 faces
# Each edge appears in exactly 2 faces

faces = [
    [ 1,  9, 10,  2, 17],   # top-front-right
    [ 1, 17, 18,  3, 13],   # right-front
    [ 1, 13, 15,  5,  9],   # front-top
    [ 2, 10,  6, 16, 14],   # top-back-right
    [ 2, 14,  4, 18, 17],   # right-back
    [ 3, 18,  4, 12, 11],   # bottom-right
    [ 3, 11,  7, 15, 13],   # front-bottom
    [ 4, 14, 16,  8, 12],   # back-bottom-right
    [ 5, 15,  7, 20, 19],   # front-left
    [ 5, 19,  6, 10,  9],   # top-left
    [ 6, 19, 20,  8, 16],   # back-left
    [ 7, 11, 12,  8, 20]    # bottom
]

# ---------- DERIVE EDGES FROM FACES -------------------------
edges = []
for f in faces
    for i = 1 to 5
        a = f[i]
		
        if i < 5
            b = f[i+1]
        else
            b = f[1]
        ok
		
        ea = a   eb = b
        if ea > eb   tmp=ea  ea=eb  eb=tmp  ok
        found = 0
		
        for e in edges
            if e[1]=ea and e[2]=eb   found=1   ok
        next
		
        if found = 0   edges + [ea, eb]   ok
    next
next

# ---------- GLUT SETUP --------------------------------------
glutInit()
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH)
glutInitWindowSize(winW, winH)
glutInitWindowPosition(100, 100)
glutCreateWindow("Dodecahedron - 12 Pentagons - Use Mouse to Rotate")

glClearColor(0.04, 0.06, 0.12, 1.0)
glEnable(GL_DEPTH_TEST)
glShadeModel(GL_SMOOTH)

glutDisplayFunc(:displaycode)
glutReshapeFunc(:reshape)
glutKeyboardFunc(:keyboard)
glutMouseFunc(:mouse)
glutMotionFunc(:motion)
glutIdleFunc(:idle)

glutMainLoop()

# ---------- DISPLAY -----------------------------------------
Func displaycode()
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)
    glLoadIdentity()
    glTranslatef(0.0, 0.0, -4.0)
    glRotatef(rotX, 1.0, 0.0, 0.0)
    glRotatef(rotY, 0.0, 1.0, 0.0)

    drawGhostSphere()

    glColor3f(0.45, 0.65, 0.90)
    for e in edges
        va = verts[e[1]]   vb = verts[e[2]]
        drawRod(va[1],va[2],va[3], vb[1],vb[2],vb[3])
    next

    glColor3f(0.65, 0.82, 0.97)
	
    for i = 1 to len(verts)
        v = verts[i]
        drawSphere(v[1], v[2], v[3], GRAD)
    next

    glutSwapBuffers()

# ---------- IDLE --------------------------------------------
Func idle()
    rotY += 0.30
    if rotY >= 360.0   rotY -= 360.0   ok
    glutPostRedisplay()

# ---------- MOUSE -------------------------------------------
Func mouse()
    btn = glutEventButton()
    mst = glutEventState()
    mx  = glutEventX()
    my  = glutEventY()
	
    if btn = GLUT_LEFT_BUTTON
        if mst = GLUT_DOWN
            isDrag = 1   lastX = mx   lastY = my
            glutIdleFunc(0)
        else
            isDrag = 0
            glutIdleFunc(:idle)
        ok
    ok

# ---------- MOTION ------------------------------------------
Func motion()
    mx = glutEventX()
    my = glutEventY()
	
    if isDrag
        rotY += (mx - lastX) * 0.5
        rotX += (my - lastY) * 0.5
        lastX = mx   lastY = my
        glutPostRedisplay()
    ok

# ---------- RESHAPE -----------------------------------------
Func reshape()
    rw = glutEventWidth()
    rh = glutEventHeight()
    if rh = 0   rh = 1   ok
    glViewport(0, 0, rw, rh)
    glMatrixMode(GL_PROJECTION)
    glLoadIdentity()
    gluPerspective(42.0, rw/rh, 0.1, 100.0)
    glMatrixMode(GL_MODELVIEW)

# ---------- KEYBOARD  27=ESCAPE -----------------------------
Func keyboard()
    kv = glutEventKey()
    if kv = 27   glutDestroyWindow(glutGetWindow())   ok

# ---------- DRAW SPHERE -------------------------------------
Func drawSphere(cx, cy, cz, sr)
    stk = 16   slc = 16
    glPushMatrix()
    glTranslatef(cx, cy, cz)
	
    for si = 0 to stk-1
        lt0 = PI * (-0.5 +  si      / stk)
        lt1 = PI * (-0.5 + (si+1.0) / stk)
        sz0 = sin(lt0)   sz1 = sin(lt1)
        zr0 = cos(lt0)   zr1 = cos(lt1)
        glBegin(GL_TRIANGLE_STRIP)
		
        for sj = 0 to slc
            lng = 2.0 * PI * sj / slc
            lx = cos(lng)   ly = sin(lng)
            glVertex3f(sr*lx*zr0, sr*ly*zr0, sr*sz0)
            glVertex3f(sr*lx*zr1, sr*ly*zr1, sr*sz1)
        next
		
        glEnd()
    next
	
    glPopMatrix()

# ---------- DRAW ROD ----------------------------------------
Func drawRod(ax, ay, az, bx, by, bz)
    ddx = bx-ax   ddy = by-ay   ddz = bz-az
    fLen = sqrt(ddx*ddx + ddy*ddy + ddz*ddz)
    if fLen < 0.0001   return   ok
	
    ux  = ddx/fLen     uy  = ddy/fLen     uz  = ddz/fLen
    sax = ax+ux*GRAD   say = ay+uy*GRAD   saz = az+uz*GRAD
    sbx = bx-ux*GRAD   sby = by-uy*GRAD   sbz = bz-uz*GRAD
    rdx = sbx-sax      rdy = sby-say      rdz = sbz-saz
	
    rLen = sqrt(rdx*rdx + rdy*rdy + rdz*rdz)
    if rLen < 0.0001   return   ok
    crx = -uy   cry = ux   crz = 0.0
    crl = sqrt(crx*crx + cry*cry)
    dtz = uz
	
    if dtz >  1.0   dtz =  1.0   ok
    if dtz < -1.0   dtz = -1.0   ok
	
    ang = acos(dtz) * 180.0 / PI
    glPushMatrix()
    glTranslatef(sax, say, saz)
    if crl > 0.0001
        glRotatef(ang, crx/crl, cry/crl, crz/crl)
    else
        if dtz < 0.0   glRotatef(180.0, 1.0, 0.0, 0.0)   ok
    ok
    glBegin(GL_TRIANGLE_STRIP)
	
    for rj = 0 to 6
        ra  = 2.0 * PI * rj / 6
        rnx = cos(ra)   rny = sin(ra)
        glVertex3f(RRAD*rnx, RRAD*rny, 0.0)
        glVertex3f(RRAD*rnx, RRAD*rny, rLen)
    next
	
    glEnd()
    glPopMatrix()

# ---------- GHOST WIREFRAME SPHERE --------------------------
Func drawGhostSphere()
    glColor3f(0.18, 0.30, 0.58)
    glLineWidth(1.0)
    stacks = 18   slices = 18
	
    for i = 0 to stacks
        lat = PI * (-0.5 + i / stacks)
        glBegin(GL_LINE_LOOP)
		
        for j = 0 to slices - 1
            lng = 2.0 * PI * j / slices
            glVertex3f(cos(lat)*cos(lng), sin(lat), cos(lat)*sin(lng))
        next
		
        glEnd()
    next
	
    for j = 0 to slices - 1
        lng = 2.0 * PI * j / slices
        glBegin(GL_LINE_STRIP)
		
        for i = 0 to stacks
            lat = PI * (-0.5 + i / stacks)
            glVertex3f(cos(lat)*cos(lng), sin(lat), cos(lat)*sin(lng))
        next
		
        glEnd()
    next
	
# ==============================
