# ============================================================
#  Surface Plot:  z = sin(x) * cos(y)
#  X range: -2*PI  to  +2*PI
#  Y range: -2*PI  to  +2*PI
#  Uses: opengl21lib.ring  and  freeglut.ring
#  Bert Mariani with Claude AI
#  2026-04-06
# ============================================================

Load "opengl21lib.ring"
Load "freeglut.ring"

# ---------- CONSTANTS ---------------------------------------
PI      = 3.14159265358979
TWO_PI  = 2.0 * PI

# ---------- GRID RESOLUTION ---------------------------------
STEPS   = 80          # number of divisions along each axis
SCALE   = 1.0         # XY spread scale (world units per PI)
ZSCALE  = 0.9         # vertical exaggeration

# ---------- GLOBALS -----------------------------------------
rotX    = 30.0
rotY    = 225.0
lastX   = 0
lastY   = 0
isDrag  = 0
winW    = 900
winH    = 900

# ---------- PRECOMPUTE SURFACE ------------------------------
# z[i][j] for i,j in 0..STEPS (STEPS+1 rows/cols)
surfZ   = list(STEPS+1)

for i = 1 to STEPS+1
    surfZ[i] = list(STEPS+1)
	
    for j = 1 to STEPS+1
        x = -TWO_PI + (i-1) * (4.0*PI / STEPS)
        y = -TWO_PI + (j-1) * (4.0*PI / STEPS)
        surfZ[i][j] = sin(x) * cos(y)
    next
	
next

# ---------- GLUT SETUP --------------------------------------

glutInit()
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH)
glutInitWindowSize(winW, winH)
glutInitWindowPosition(100, 60)
glutCreateWindow("Z = sin(x)*cos(y) | Range: -2PI to +2PI | Animated | Drag to Rotate |")

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
    glTranslatef(0.0, 0.0, -7.0)
    glRotatef(rotX, 1.0, 0.0, 0.0)
    glRotatef(rotY, 0.0, 1.0, 0.0)

    drawAxes()
    drawSurface()
    drawGridLines()

    glutSwapBuffers()

# ---------- IDLE (auto-rotate) ------------------------------
Func idle()
    rotY += 0.20
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

# ---------- KEYBOARD  27=ESCAPE -----------------------------
Func keyboard()
    kv = glutEventKey()
    if kv = 27   glutDestroyWindow(glutGetWindow())   ok

# ---------- COLOUR MAP  (blue -> cyan -> green -> yellow -> red) --
Func heightColor(z)
    # z is in [-1, +1]; map to t in [0,1]
    t = (z + 1.0) * 0.5
	
    if t < 0.0   t = 0.0   ok
    if t > 1.0   t = 1.0   ok

    if t < 0.25
        s = t / 0.25
        glColor3f(0.0,       s,       1.0)         # blue -> cyan
    elseif t < 0.5
        s = (t - 0.25) / 0.25
        glColor3f(0.0,       1.0,     1.0 - s)     # cyan -> green
    elseif t < 0.75
        s = (t - 0.50) / 0.25
        glColor3f(s,         1.0,     0.0)         # green -> yellow
    else
        s = (t - 0.75) / 0.25
        glColor3f(1.0,       1.0 - s, 0.0)         # yellow -> red
    ok

# ---------- DRAW FILLED SURFACE (quad strips per row) -------
Func drawSurface()
    for i = 1 to STEPS
        glBegin(GL_TRIANGLE_STRIP)
		
        for j = 1 to STEPS+1
            # vertex (i, j)
            x0 = -TWO_PI + (i-1) * (4.0*PI / STEPS)
            x1 = -TWO_PI +  i    * (4.0*PI / STEPS)
            y  = -TWO_PI + (j-1) * (4.0*PI / STEPS)

            z0 = surfZ[i  ][j]
            z1 = surfZ[i+1][j]

            wx0 = x0 * SCALE / PI
            wx1 = x1 * SCALE / PI
            wy  = y  * SCALE / PI

            heightColor(z0)
            glVertex3f(wx0, z0 * ZSCALE, wy)

            heightColor(z1)
            glVertex3f(wx1, z1 * ZSCALE, wy)
        next
		
        glEnd()
    next

# ---------- DRAW WIREFRAME GRID LINES (denser) --------------
Func drawGridLines()
    glColor3f(0.15, 0.18, 0.28)
    step = 4     # draw a grid line every 4 STEPS

    # lines along X direction
    j = 1
	
    while j <= STEPS+1
        glBegin(GL_LINE_STRIP)
        
		for i = 1 to STEPS+1
            x = -TWO_PI + (i-1) * (4.0*PI / STEPS)
            y = -TWO_PI + (j-1) * (4.0*PI / STEPS)
            z = surfZ[i][j]
			
            glVertex3f(x*SCALE/PI, z*ZSCALE, y*SCALE/PI)
        next
		
        glEnd()
        j += step
    end

    # lines along Y direction
    i = 1
    while i <= STEPS+1
        glBegin(GL_LINE_STRIP)
		
        for j = 1 to STEPS+1
            x = -TWO_PI + (i-1) * (4.0*PI / STEPS)
            y = -TWO_PI + (j-1) * (4.0*PI / STEPS)
            z = surfZ[i][j]
            glVertex3f(x*SCALE/PI, z*ZSCALE, y*SCALE/PI)
        next
		
        glEnd()
        i += step
    end

# ---------- DRAW X / Y / Z AXES  ----------------------------
Func drawAxes()
    glLineWidth(2.0)
    LEN = 2.3

    # X axis – red
    glColor3f(1.0, 0.25, 0.25)
    glBegin(GL_LINES)
        glVertex3f(-LEN, 0.0, 0.0)
        glVertex3f( LEN, 0.0, 0.0)
    glEnd()

    # Y axis (vertical / Z in world) – green
    glColor3f(0.25, 1.0, 0.40)
    glBegin(GL_LINES)
        glVertex3f(0.0, -LEN*ZSCALE, 0.0)
        glVertex3f(0.0,  LEN*ZSCALE, 0.0)
    glEnd()

    # Z axis (depth) – blue
    glColor3f(0.35, 0.55, 1.0)
    glBegin(GL_LINES)
        glVertex3f(0.0, 0.0, -LEN)
        glVertex3f(0.0, 0.0,  LEN)
    glEnd()

    glLineWidth(1.0)

# ==================================
