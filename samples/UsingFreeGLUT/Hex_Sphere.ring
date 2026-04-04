# ============================================================
#  Hexagon Sphere Icosahedron 
#  Uses: opengl21lib.ring  and  freeglut.ring
#  Dual geodesic: hex/pent edges only, no internal triangles
#  Vertices = bright blue globes, rods = yellow
#  Bert Mariani with Claude AI
#  2026-04-04
# ============================================================

Load "opengl21lib.ring"
Load "freeglut.ring"

# ---------- CONSTANTS ---------------------------------------
PI   = 3.14159265358979
GRAD = 0.038
RRAD = 0.007
FREQ = 3

# ---------- GLOBALS -----------------------------------------
rotX   = 20.0
rotY   = 30.0
lastX  = 0
lastY  = 0
isDrag = 0
winW   = 800
winH   = 800
vList  = []   # triangle mesh vertices
eSet   = []   # triangle mesh edges
fList  = []   # triangle faces
dVerts = []   # dual vertices (face centres)
dEdges = []   # dual edges (hex/pent outline edges only)

# ---------- ICOSAHEDRON -------------------------------------
phi  = (1.0 + sqrt(5.0)) / 2.0
icoV = []
icoV + [-1, phi, 0]   icoV + [ 1, phi, 0]
icoV + [-1,-phi, 0]   icoV + [ 1,-phi, 0]
icoV + [ 0,-1, phi]   icoV + [ 0, 1, phi]
icoV + [ 0,-1,-phi]   icoV + [ 0, 1,-phi]
icoV + [ phi, 0,-1]   icoV + [ phi, 0, 1]
icoV + [-phi, 0,-1]   icoV + [-phi, 0, 1]

for ni = 1 to len(icoV)
    vv = icoV[ni]
    vL = sqrt(vv[1]*vv[1] + vv[2]*vv[2] + vv[3]*vv[3])
    icoV[ni] = [vv[1]/vL, vv[2]/vL, vv[3]/vL]
next

# COMPLETE 20-FACE ICOSAHEDRON - verified correct topology
# All 30 edges appear exactly twice, all 12 vertices have valence 5

icoF = [
    [ 1, 2, 6],[ 1, 2, 8],[ 1, 6,12],[ 1, 8,11],[ 1,11,12],
    [ 2, 6,10],[ 2, 8, 9],[ 2, 9,10],[ 3, 4, 5],[ 3, 4, 7],
    [ 3, 5,12],[ 3, 7,11],[ 3,11,12],[ 4, 5,10],[ 4, 7, 9],
    [ 4, 9,10],[ 5, 6,10],[ 5, 6,12],[ 7, 8, 9],[ 7, 8,11]
]

# ---------- SUBDIVIDE INTO TRIANGLE MESH --------------------
for fc in icoF
    va = icoV[fc[1]]   vb = icoV[fc[2]]   vc = icoV[fc[3]]
    pts = []

    for ri = 0 to FREQ
        row = []
        for ci = 0 to FREQ - ri
            bk = FREQ - ri - ci
            px = (ci*va[1] + ri*vb[1] + bk*vc[1]) / FREQ
            py = (ci*va[2] + ri*vb[2] + bk*vc[2]) / FREQ
            pz = (ci*va[3] + ri*vb[3] + bk*vc[3]) / FREQ
            row + addVert(px, py, pz)
        next
        pts + row
    next

    for ri = 0 to FREQ-1
        for ci = 0 to FREQ-ri-1
            pa = pts[ri+1][ci+1]
            pb = pts[ri+2][ci+1]
            pc = pts[ri+1][ci+2]
            addEdge(pa, pb)   addEdge(pb, pc)   addEdge(pa, pc)
            fList + [pa, pb, pc]

            if ci < FREQ-ri-1
                pd = pts[ri+2][ci+2]
                addEdge(pb, pd)   addEdge(pc, pd)
                fList + [pb, pd, pc]
            ok
        next
    next
next

# ---------- BUILD DUAL VERTICES -----------------------------
for fc in fList
    va = vList[fc[1]]   vb = vList[fc[2]]   vc = vList[fc[3]]
    cx = (va[1]+vb[1]+vc[1]) / 3.0
    cy = (va[2]+vb[2]+vc[2]) / 3.0
    cz = (va[3]+vb[3]+vc[3]) / 3.0
    cL = sqrt(cx*cx + cy*cy + cz*cz)
    dVerts + [cx/cL, cy/cL, cz/cL]
next

# ---------- BUILD DUAL EDGES --------------------------------
# Process each of the 3 edges of every triangle explicitly.
# Use parallel arrays with numeric indexing throughout.
# "|" separator makes keys unambiguous.
# del() after match ensures each edge is paired exactly once.
emKeys  = []
emFaces = []

for fi = 1 to len(fList)
    fc = fList[fi]
    # Extract all 3 vertex-pair edges of this face explicitly
    edgePairs = [ [fc[1],fc[2]], [fc[2],fc[3]], [fc[1],fc[3]] ]
	
    for ei = 1 to 3
        ea = edgePairs[ei][1]
        eb = edgePairs[ei][2]
        if ea > eb   etmp=ea  ea=eb  eb=etmp   ok
        ek = string(ea) + "|" + string(eb)

        fnd = 0
        for mi = 1 to len(emKeys)
            if emKeys[mi] = ek
                addDualEdge(emFaces[mi], fi)
                del(emKeys,  mi)
                del(emFaces, mi)
                fnd = 1
                exit
            ok
        next
		
        if fnd = 0
            emKeys  + ek
            emFaces + fi
        ok
    next
next

# ---------- GLUT SETUP --------------------------------------
glutInit()
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH)
glutInitWindowSize(winW, winH)
glutInitWindowPosition(100, 100)
glutCreateWindow("Hex Sphere - Icosahedron - Animation - Use Mouse to Rotate")

glClearColor(0.05, 0.07, 0.13, 1.0)
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
    glTranslatef(0.0, 0.0, -3.2)
    glRotatef(rotX, 1.0, 0.0, 0.0)
    glRotatef(rotY, 0.0, 1.0, 0.0)

    # YELLOW RODS (dual edges = hex/pent outlines)
    glColor3f(0.9, 0.9, 0.02)

    for de in dEdges
        va = dVerts[de[1]]   vb = dVerts[de[2]]
        drawRod(va[1],va[2],va[3], vb[1],vb[2],vb[3])
    next

    # BRIGHT BLUE VERTEX GLOBES
    glColor3f(0.02, 0.04, 1.00)

    for dv in dVerts
        drawSphere(dv[1], dv[2], dv[3], GRAD)
    next

    glutSwapBuffers()

# ---------- IDLE --------------------------------------------
Func idle()
    rotY += 0.25
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
    gluPerspective(40.0, rw/rh, 0.1, 100.0)
    glMatrixMode(GL_MODELVIEW)

# ---------- KEYBOARD  27=Escape -----------------------------
Func keyboard()
    kv = glutEventKey()
    if kv = 27   glutDestroyWindow(glutGetWindow())   ok

# ---------- ADD TRIANGLE MESH VERTEX ------------------------
Func addVert(px, py, pz)
    vL = sqrt(px*px + py*py + pz*pz)
    if vL > 0.000001
        px = px/vL   py = py/vL   pz = pz/vL
    ok

    for vi = 1 to len(vList)
        vu = vList[vi]
        ddx = vu[1]-px   ddy = vu[2]-py   ddz = vu[3]-pz
        if ddx*ddx + ddy*ddy + ddz*ddz < 0.000001
            return vi
        ok
    next

    vList + [px, py, pz]
    return len(vList)

# ---------- ADD UNIQUE TRIANGLE EDGE ------------------------
Func addEdge(ea, eb)
    if ea > eb   etmp=ea  ea=eb  eb=etmp   ok
	
    for ee in eSet
        if ee[1]=ea and ee[2]=eb   return   ok
    next
    eSet + [ea, eb]

# ---------- ADD UNIQUE DUAL EDGE ----------------------------
Func addDualEdge(ea, eb)
    if ea > eb   etmp=ea  ea=eb  eb=etmp   ok
    for de in dEdges
        if de[1]=ea and de[2]=eb   return   ok
    next
	
    dEdges + [ea, eb]

# ---------- DRAW SPHERE -------------------------------------
Func drawSphere(cx, cy, cz, sr)
    stk = 10   slc = 10
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
            lx  = cos(lng)   ly = sin(lng)
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

    ux  = ddx/fLen     uy = ddy/fLen       uz = ddz/fLen
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

# ============================================================
