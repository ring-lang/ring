# The Stars Example 
# From NeHe website : http://nehe.gamedev.net/
# Converted to Ring by Mahmoud Fayed <msfclipper@yahoo.com>
# This version of the example uses Lists for storing the data

load "gamelib.ring"
load "opengl21lib.ring"

al_init()
al_init_font_addon()
al_init_ttf_addon()
al_init_image_addon()

al_set_new_display_flags(ALLEGRO_OPENGL) 
display = al_create_display(800,600)
al_set_Window_title(display,"Stars")
al_clear_to_color(al_map_rgb(0,0,255))


bitmap = al_load_bitmap("star.bmp")
texture = al_get_opengl_texture(bitmap)
 
xrot = 0.0
yrot = 0.0
zrot = 0.0

num 	= 50
zoom	= -15.0
tilt	= 90.0 
twinkle	= 0
spin 	= 0

star = []
for t = 1 to num
	star + [ 0,0,0,0,0 ]
next

w = 800 h=600
ratio =  w / h

glViewport(0, 0, w, h)
glMatrixMode(GL_PROJECTION)
glLoadIdentity()

gluPerspective(45,ratio,1,100)
glMatrixMode(GL_MODELVIEW)
glLoadIdentity()

glEnable(GL_TEXTURE_2D)							
glShadeModel(GL_SMOOTH)							
glClearColor(0.0, 0.0, 0.0, 0.5)
glClearDepth(1.0)			
glEnable(GL_DEPTH_TEST)	
glEnable(GL_CULL_FACE)		
glDepthFunc(GL_LEQUAL)
glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST)


glBlendFunc(GL_SRC_ALPHA,GL_ONE)	// Set The Blending Function For Translucency
glEnable(GL_BLEND)

for nloop = 1 to num
	star[nloop][1]	=	0.0
	star[nloop][2]	=	(nloop/num)*5.0
	star[nloop][3]	= 	random(255)
	star[nloop][4]	= 	random(255)
	star[nloop][5]	= 	random(255)
next


nFPS  = 0
t1 = clock()

event_queue = al_create_event_queue()
al_register_event_source(event_queue, al_get_display_event_source(display))
ev = al_new_allegro_event()
timeout = al_new_allegro_timeout()
al_init_timeout(timeout, 0.01)

while true
        al_wait_for_event_until(event_queue, ev, timeout)
        switch al_get_allegro_event_type(ev)
        on ALLEGRO_EVENT_DISPLAY_CLOSE
                exit
	off
	DrawScene()
	al_flip_display()
	calcfps()
end

al_destroy_display(display)


func DrawScene

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)	// Clear The Screen And The Depth Buffer
	glBindTexture(GL_TEXTURE_2D, texture)			// Select Our Texture
	
	for nloop=1 to num

		glLoadIdentity()								// Reset The View Before We Draw Each Star
		glTranslatef(0.0,0.0,zoom)			// Zoom Into The Screen (Using The Value In 'zoom')
		glRotatef(tilt,1.0,0.0,0.0)			// Tilt The View (Using The Value In 'tilt')
		glRotatef(star[nloop][1],0.0,1.0,0.0)		// Rotate To The Current Stars Angle
		glTranslatef(star[nloop][2],0.0,0.0)		// Move Forward On The X Plane
		glRotatef(-star[nloop][1],0.0,1.0,0.0)		// Cancel The Current Stars Angle
		glRotatef(-tilt,1.0,0.0,0.0)			// Cancel The Screen Tilt
		
		if twinkle
			glColor4ub(star[(num-nloop)-1][3],star[(num-nloop)-1][4],
					star[(num-nloop)-1][5],255)
			glBegin(GL_QUADS)
				glTexCoord2f(0.0, 0.0) glVertex3f(-1.0,-1.0, 0.0)
				glTexCoord2f(1.0, 0.0) glVertex3f( 1.0,-1.0, 0.0)
				glTexCoord2f(1.0, 1.0) glVertex3f( 1.0, 1.0, 0.0)
				glTexCoord2f(0.0, 1.0) glVertex3f(-1.0, 1.0, 0.0)
			glEnd()
		ok
	
		glRotatef(spin,0.0,0.0,1.0)
		glColor4ub(star[nloop][3],star[nloop][4],star[nloop][5],255)
		glBegin(GL_QUADS)
			glTexCoord2f(0.0, 0.0) glVertex3f(-1.0,-1.0, 0.0)
			glTexCoord2f(1.0, 0.0) glVertex3f( 1.0,-1.0, 0.0)
			glTexCoord2f(1.0, 1.0) glVertex3f( 1.0, 1.0, 0.0)
			glTexCoord2f(0.0, 1.0) glVertex3f(-1.0, 1.0, 0.0)
		glEnd()
	
		spin += 0.01
		star[nloop][1] += nloop/num
		star[nloop][2] -= 0.01
		if (star[nloop][2]<0.0)
			star[nloop][2] += 5.0
			star[nloop][3] = random(255)
			star[nloop][4] = random(255)
			star[nloop][5] = random(255)
		ok

	next


func calcfps
	nFPs++
	if clock() - t1 > clockspersecond()
		t1 = clock()
		? "FPS : " + nFPS 
		nFPS = 0
	ok

