Load "libsdl.ring"
Load "opengl21lib.ring"

SDL_Init(SDL_INIT_EVERYTHING)
win = SDL_CreateWindow("Hello World!", 100, 100, 640, 480, SDL_WINDOW_OPENGL)
mainContext = SDL_GL_CreateContext(WIN)
SDL_GL_SetSwapInterval(1)
# OpenGL Code
                w = 800 h = 600
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

                glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)
                glLoadIdentity()
                glTranslatef(0.0,0.0,-5.0)

                glRotatef(40,1.0,0.0,0.0)
                glRotatef(40,0.0,1.0,0.0)
                glRotatef(10,0.0,0.0,1.0)

                glBegin(GL_QUADS)
                        // Front Face
                        glTexCoord2f(0.0, 0.0) glVertex3f(-1.0, -1.0,  1.0)
                        glTexCoord2f(1.0, 0.0) glVertex3f( 1.0, -1.0,  1.0)
                        glTexCoord2f(1.0, 1.0) glVertex3f( 1.0,  1.0,  1.0)
                        glTexCoord2f(0.0, 1.0) glVertex3f(-1.0,  1.0,  1.0)
                        // Back Face
                        glTexCoord2f(1.0, 0.0) glVertex3f(-1.0, -1.0, -1.0)
                        glTexCoord2f(1.0, 1.0) glVertex3f(-1.0,  1.0, -1.0)
                        glTexCoord2f(0.0, 1.0) glVertex3f( 1.0,  1.0, -1.0)
                        glTexCoord2f(0.0, 0.0) glVertex3f( 1.0, -1.0, -1.0)
                        // Top Face
                        glTexCoord2f(0.0, 1.0) glVertex3f(-1.0,  1.0, -1.0)
                        glTexCoord2f(0.0, 0.0) glVertex3f(-1.0,  1.0,  1.0)
                        glTexCoord2f(1.0, 0.0) glVertex3f( 1.0,  1.0,  1.0)
                        glTexCoord2f(1.0, 1.0) glVertex3f( 1.0,  1.0, -1.0)
                        // Bottom Face
                        glTexCoord2f(1.0, 1.0) glVertex3f(-1.0, -1.0, -1.0)
                        glTexCoord2f(0.0, 1.0) glVertex3f( 1.0, -1.0, -1.0)
                        glTexCoord2f(0.0, 0.0) glVertex3f( 1.0, -1.0,  1.0)
                        glTexCoord2f(1.0, 0.0) glVertex3f(-1.0, -1.0,  1.0)
                        // Right face
                        glTexCoord2f(1.0, 0.0) glVertex3f( 1.0, -1.0, -1.0)
                        glTexCoord2f(1.0, 1.0) glVertex3f( 1.0,  1.0, -1.0)
                        glTexCoord2f(0.0, 1.0) glVertex3f( 1.0,  1.0,  1.0)
                        glTexCoord2f(0.0, 0.0) glVertex3f( 1.0, -1.0,  1.0)
                        // Left Face
                        glTexCoord2f(0.0, 0.0) glVertex3f(-1.0, -1.0, -1.0)
                        glTexCoord2f(1.0, 0.0) glVertex3f(-1.0, -1.0,  1.0)
                        glTexCoord2f(1.0, 1.0) glVertex3f(-1.0,  1.0,  1.0)
                        glTexCoord2f(0.0, 1.0) glVertex3f(-1.0,  1.0, -1.0)
                glEnd()

SDL_GL_SwapWindow(win)
SDL_Delay(2000)
SDL_DestroyWindow(win)
SDL_Quit()
