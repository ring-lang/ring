Load "libsdl.ring"
Load "opengl21lib.ring"

SDL_Init(SDL_INIT_EVERYTHING)
win = SDL_CreateWindow("Hello World!", 100, 100, 640, 480, SDL_WINDOW_OPENGL)
mainContext = SDL_GL_CreateContext(WIN)
SDL_GL_SetSwapInterval(1)

# OpenGL Code

  glEnable(GL_DEPTH_TEST)

  //  Clear screen and Z-buffer
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT)

  // Reset transformations
  glLoadIdentity()

  // Rotate when user changes rotate_x and rotate_y
  glRotatef( 40, 1.0, 0.0, 0.0 )
  glRotatef( 40, 0.0, 1.0, 0.0 )

  //Multi-colored side - FRONT
  glBegin(GL_POLYGON)

  glColor3f( 1.0, 0.0, 0.0 )     glVertex3f(  0.5, -0.5, -0.5 )      # P1 is red
  glColor3f( 0.0, 1.0, 0.0 )     glVertex3f(  0.5,  0.5, -0.5 )      # P2 is green
  glColor3f( 0.0, 0.0, 1.0 )     glVertex3f( -0.5,  0.5, -0.5 )      # P3 is blue
  glColor3f( 1.0, 0.0, 1.0 )     glVertex3f( -0.5, -0.5, -0.5 )      # P4 is purple

  glEnd()

  // White side - BACK
  glBegin(GL_POLYGON)
  glColor3f(   1.0,  1.0, 1.0 )
  glVertex3f(  0.5, -0.5, 0.5 )
  glVertex3f(  0.5,  0.5, 0.5 )
  glVertex3f( -0.5,  0.5, 0.5 )
  glVertex3f( -0.5, -0.5, 0.5 )
  glEnd()

  // Purple side - RIGHT
  glBegin(GL_POLYGON)
  glColor3f(  1.0,  0.0,  1.0 )
  glVertex3f( 0.5, -0.5, -0.5 )
  glVertex3f( 0.5,  0.5, -0.5 )
  glVertex3f( 0.5,  0.5,  0.5 )
  glVertex3f( 0.5, -0.5,  0.5 )
  glEnd()

  // Green side - LEFT
  glBegin(GL_POLYGON)
  glColor3f(   0.0,  1.0,  0.0 )
  glVertex3f( -0.5, -0.5,  0.5 )
  glVertex3f( -0.5,  0.5,  0.5 )
  glVertex3f( -0.5,  0.5, -0.5 )
  glVertex3f( -0.5, -0.5, -0.5 )
  glEnd()

  // Blue side - TOP
  glBegin(GL_POLYGON)
  glColor3f(   0.0,  0.0,  1.0 )
  glVertex3f(  0.5,  0.5,  0.5 )
  glVertex3f(  0.5,  0.5, -0.5 )
  glVertex3f( -0.5,  0.5, -0.5 )
  glVertex3f( -0.5,  0.5,  0.5 )
  glEnd()

  // Red side - BOTTOM
  glBegin(GL_POLYGON)
  glColor3f(   1.0,  0.0,  0.0 )
  glVertex3f(  0.5, -0.5, -0.5 )
  glVertex3f(  0.5, -0.5,  0.5 )
  glVertex3f( -0.5, -0.5,  0.5 )
  glVertex3f( -0.5, -0.5, -0.5 )
  glEnd()

  glFlush()

SDL_GL_SwapWindow(win)
SDL_Delay(2000)
SDL_DestroyWindow(win)
SDL_Quit()
