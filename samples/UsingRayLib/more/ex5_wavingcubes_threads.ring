#===================================================================#
# Based on Original Sample from RayLib (https://www.raylib.com/)
# Ported to RingRayLib by Ring Team  
# Uses Threads from RingLibuv 
# 2020, Ilir Liburn <iliribur@gmail.com>
#===================================================================#

load "raylib.ring"
load "stdlib.ring"
load "libuv.ring"

numBlocks = 15
numThreads = 2 // including main thread, min = 1, max = 2 due to race conditions 

SetTraceLogLevel(LOG_NONE)

qub = pow(numBlocks, 3)
data = list(numThreads, qub)

for j = 1 to numThreads
	for k = 1 to qub
		data[j][k] = [Vec3(), Vec3(), BLACK]
	next
next
	
color = Vec3()
Vec3SetY(color,0.75)
Vec3SetZ(color,0.9)

colors = []
for c = 0 to 359
	Vec3SetX(color, c)
	Add(colors, ColorFromHSV_2(color))
next

INT_SIZE = len(int2bytes(0))

pr = space(INT_SIZE)
parent = varptr(:pr, :uv_sem_t)
uv_sem_init(parent, 0)

ch = space(INT_SIZE)
child = varptr(:ch, :uv_sem_t)
uv_sem_init(child, 0)

mt = space(INT_SIZE)
mute = varptr(:mt, :uv_mutex_t)
uv_mutex_init(mute)

for t = 2 to numThreads
	thread = new_uv_thread_t()
	cCall = uv_callback(thread,:thread,"thread("+t+")")
	uv_thread_create_2(thread,cCall,thread)
next

screenWidth = 800
screenHeight = 450

InitWindow(screenWidth, screenHeight, "Waving Cubes")

camera = Camera3D( 0.0, 20.0, 0.0,
		   0.0, 0.0, 0.0,
		   0.0, 1.0, 0.0, 
		   75.0, 0 )

cam = camera.data()

SetTargetFPS(60)

while !WindowShouldClose()

	cameraTime = GetTime()*0.3

	setCamera3DPosX(cam,cos(cameraTime)*40.0)
	setCamera3DPosZ(cam,sin(cameraTime)*40.0)

	BeginDrawing()

	ClearBackground_2(RAYWHITE)

	BeginMode3D_2(cam)

	DrawGrid(10, 5.0)

	for i = 1 to qub
		DrawCubeV_2(data[1][i][1], data[1][i][2], data[1][i][3])
	next

	EndMode3D()

	DrawFPS(10, 10)

	EndDrawing()

	if uv_sem_trywait(child) = 0
		uv_sem_post(parent)
		uv_mutex_lock(mute)
		uv_mutex_unlock(mute)
	ok

end

uv_mutex_destroy(mute)
uv_sem_destroy(child)
uv_sem_destroy(parent)

CloseWindow()
Shutdown()

func thread i

	cnt = numBlocks - 1
	while true
		time = GetTime()
		scale = (2.0 + sin(time)) * 0.7
		v = 1
		for x = 0 to cnt 
			for y = 0 to cnt	
				for z = 0 to cnt
					blockScale = (x + y + z) / 30.0
					scatter = sin(blockScale*20.0 + (time*4.0))
					Vec3SetX(data[i][v][1], (x - numBlocks/2.0)*(scale*3.0) + scatter)
					Vec3SetY(data[i][v][1], (y - numBlocks/2.0)*(scale*2.0) + scatter)
					Vec3SetZ(data[i][v][1], (z - numBlocks/2.0)*(scale*3.0) + scatter)
					size = (2.4 - scale)*blockScale
					Vec3SetX(data[i][v][2], size)
					Vec3SetY(data[i][v][2], size)
					Vec3SetZ(data[i][v][2], size)
					data[i][v][3] = colors[((x + y + z)*18.0)%360 + 1]
					v++
				next
			next
		next
		uv_mutex_lock(mute)
		uv_sem_post(child)
		uv_sem_wait(parent)
		swap(data, 1, i)
		uv_mutex_unlock(mute)
	end
