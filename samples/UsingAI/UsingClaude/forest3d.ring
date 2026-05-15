/*
	Beautiful 3D Forest Explorer
	Using Ring Language + RayLib
	
	Controls:
	  WASD / Arrow Keys - Move around
	  Mouse            - Look around
	  Space            - Move up
	  Left Shift       - Move down
	  ESC              - Exit
*/

load "raylib.ring"

# ============================================
# Configuration
# ============================================
SCREEN_WIDTH  = 1200
SCREEN_HEIGHT = 700
TREE_COUNT    = 120
ROCK_COUNT    = 25
BUSH_COUNT    = 40
FLOWER_COUNT  = 80
MUSHROOM_COUNT = 20
FOREST_RADIUS = 70

# ============================================
# Initialize Window
# ============================================
InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Ring 3D Forest Explorer")
SetTargetFPS(60)

# ============================================
# Camera Setup (First Person)
# ============================================
camera = Camera3D(
	0.0, 2.0, 0.0,       # Position - eye level
	10.0, 2.0, 10.0,     # Target
	0.0, 1.0, 0.0,       # Up
	65.0,                 # FOV
	CAMERA_PERSPECTIVE
)

# ============================================
# Color Definitions
# ============================================
colSky        = Color(135, 206, 235, 255)
colGround     = Color(45, 90, 30, 255)
colTrunkBrown = Color(92, 58, 30, 255)
colTrunkOak   = Color(107, 66, 38, 255)
colBirchTrunk = Color(232, 220, 200, 255)
colBirchMark  = Color(74, 74, 74, 255)
colSun        = Color(255, 248, 220, 255)
colMushroomCap  = Color(204, 51, 51, 255)
colMushroomStem = Color(245, 240, 224, 255)
colStem       = Color(45, 138, 45, 255)
colHudBg      = Color(0, 0, 0, 120)
colHudText    = Color(204, 255, 204, 255)
colHorizon    = Color(26, 61, 15, 255)
colRay        = Color(255, 255, 200, 30)

# ============================================
# Generate Random Forest Data
# ============================================

# --- Trees ---
aTreeX     = []
aTreeZ     = []
aTreeH     = []
aTreeR     = []
aTrunkR    = []
aTreeType  = []
aTreeGreen = []

for i = 1 to TREE_COUNT
	angle  = randomFloat() * 2 * 3.14159
	dist   = 6 + randomFloat() * (FOREST_RADIUS - 6)
	aTreeX + cos(angle) * dist
	aTreeZ + sin(angle) * dist
	aTreeH + 4.0 + randomFloat() * 6.0
	aTreeR + 1.5 + randomFloat() * 2.5
	aTrunkR + 0.15 + randomFloat() * 0.25
	aTreeType + (random(2) + 1)
	aTreeGreen + (30 + random(50))
next

# --- Rocks ---
aRockX = []   aRockZ = []   aRockS = []   aRockGray = []
for i = 1 to ROCK_COUNT
	angle = randomFloat() * 2 * 3.14159
	dist  = 4 + randomFloat() * (FOREST_RADIUS - 4)
	aRockX + cos(angle) * dist
	aRockZ + sin(angle) * dist
	aRockS + 0.3 + randomFloat() * 0.8
	aRockGray + (90 + random(60))
next

# --- Bushes ---
aBushX = []   aBushZ = []   aBushS = []   aBushGreen = []
for i = 1 to BUSH_COUNT
	angle = randomFloat() * 2 * 3.14159
	dist  = 3 + randomFloat() * (FOREST_RADIUS - 3)
	aBushX + cos(angle) * dist
	aBushZ + sin(angle) * dist
	aBushS + 0.4 + randomFloat() * 0.6
	aBushGreen + (35 + random(50))
next

# --- Flowers ---
aFlowerX = []  aFlowerZ = []  aFlowerC = []
for i = 1 to FLOWER_COUNT
	angle = randomFloat() * 2 * 3.14159
	dist  = 3 + randomFloat() * (FOREST_RADIUS - 3)
	aFlowerX + cos(angle) * dist
	aFlowerZ + sin(angle) * dist
	aFlowerC + (random(4) + 1)
next

# --- Mushrooms ---
aMushroomX = []  aMushroomZ = []  aMushroomS = []
for i = 1 to MUSHROOM_COUNT
	angle = randomFloat() * 2 * 3.14159
	dist  = 5 + randomFloat() * (FOREST_RADIUS - 5)
	aMushroomX + cos(angle) * dist
	aMushroomZ + sin(angle) * dist
	aMushroomS + 0.1 + randomFloat() * 0.2
next

# --- Horizon Trees ---
aHorizonX = []  aHorizonZ = []  aHorizonH = []
for i = 1 to 36
	angle = i * (2 * 3.14159 / 36)
	aHorizonX + cos(angle) * (FOREST_RADIUS + 15)
	aHorizonZ + sin(angle) * (FOREST_RADIUS + 15)
	aHorizonH + (8 + random(5))
next
colFlower1 = Color(255, 80, 80, 255)
colFlower2 = Color(255, 220, 50, 255)
colFlower3 = Color(200, 100, 255, 255)
colFlower4 = Color(255, 180, 200, 255)
colFlower5 = Color(255, 255, 255, 255)

# ============================================
# Main Loop
# ============================================
while !WindowShouldClose()

	UpdateCamera(camera, CAMERA_FIRST_PERSON)

	BeginDrawing()

		ClearBackground(colSky)

		BeginMode3D(camera)

			# ---------- Ground Plane ----------
			DrawPlane(
				Vector3(0, 0, 0),
				Vector2(FOREST_RADIUS * 2.5, FOREST_RADIUS * 2.5),
				colGround
			)

			# ---------- Draw Trees ----------
			for i = 1 to TREE_COUNT
				tx = aTreeX[i]
				tz = aTreeZ[i]
				th = aTreeH[i]
				fr = aTreeR[i]
				tr = aTrunkR[i]
				tt = aTreeType[i]
				gr = aTreeGreen[i]

				switch tt
				on 1
					# Pine Tree - trunk + single cone
					DrawCylinder(
						Vector3(tx, 0, tz),
						tr, tr * 0.8, th * 0.4,
						6, colTrunkBrown
					)
					DrawCylinder(
						Vector3(tx, th * 0.2, tz),
						0.01, fr * 1.0, th * 0.7,
						6, Color(20, gr, 15, 255)
					)

				on 2
					# Oak Tree
					DrawCylinder(
						Vector3(tx, 0, tz),
						tr * 1.3, tr, th * 0.5,
						6, colTrunkOak
					)
					DrawSphere(
						Vector3(tx, th * 0.55, tz),
						fr * 1.1,
						Color(25, gr, 20, 255)
					)
					DrawSphere(
						Vector3(tx + fr * 0.3, th * 0.5, tz + fr * 0.2),
						fr * 0.7,
						Color(30, gr + 10, 25, 255)
					)

				on 3
					# Birch Tree
					DrawCylinder(
						Vector3(tx, 0, tz),
						tr * 0.8, tr * 0.6, th * 0.6,
						6, colBirchTrunk
					)
					DrawCylinder(
						Vector3(tx, th * 0.15, tz),
						tr * 0.82, tr * 0.82, 0.1,
						6, colBirchMark
					)
					DrawCylinder(
						Vector3(tx, th * 0.35, tz),
						tr * 0.72, tr * 0.72, 0.08,
						6, colBirchMark
					)
					DrawSphere(
						Vector3(tx, th * 0.6, tz),
						fr * 0.9,
						Color(50, gr + 20, 30, 230)
					)
				off

			next

			# ---------- Draw Rocks ----------
			for i = 1 to ROCK_COUNT
				s = aRockS[i]
				g = aRockGray[i]
				DrawCube(
					Vector3(aRockX[i], s * 0.4, aRockZ[i]),
					s * 1.2, s * 0.8, s,
					Color(g, g - 10, g - 15, 255)
				)
			next

			# ---------- Draw Bushes ----------
			for i = 1 to BUSH_COUNT
				s = aBushS[i]
				gr = aBushGreen[i]
				DrawSphere(
					Vector3(aBushX[i], s * 0.5, aBushZ[i]),
					s,
					Color(20, gr, 15, 255)
				)
				DrawSphere(
					Vector3(aBushX[i] + s * 0.3, s * 0.4, aBushZ[i] - s * 0.2),
					s * 0.7,
					Color(25, gr + 10, 20, 255)
				)
			next

			# ---------- Draw Flowers ----------
			for i = 1 to FLOWER_COUNT
				fx = aFlowerX[i]
				fz = aFlowerZ[i]
				fc = aFlowerC[i]

				DrawCylinder(
					Vector3(fx, 0, fz),
					0.02, 0.02, 0.3,
					4, colStem
				)

				if fc = 1  flowerCol = colFlower1
				but fc = 2  flowerCol = colFlower2
				but fc = 3  flowerCol = colFlower3
				but fc = 4  flowerCol = colFlower4
				else  flowerCol = colFlower5
				ok

				DrawSphere(
					Vector3(fx, 0.32, fz),
					0.06,
					flowerCol
				)
			next

			# ---------- Draw Mushrooms ----------
			for i = 1 to MUSHROOM_COUNT
				mx = aMushroomX[i]
				mz = aMushroomZ[i]
				ms = aMushroomS[i]

				DrawCylinder(
					Vector3(mx, 0, mz),
					ms * 0.3, ms * 0.4, ms * 1.5,
					5, colMushroomStem
				)
				DrawCylinder(
					Vector3(mx, ms * 1.5, mz),
					0.01, ms * 1.2, ms * 0.6,
					6, colMushroomCap
				)
				DrawSphere(
					Vector3(mx + ms * 0.3, ms * 1.7, mz),
					ms * 0.15,
					Color(255, 255, 255, 255)
				)
			next

			# ---------- Distant Tree Line (horizon) ----------
			for i = 1 to 36
				h = aHorizonH[i]
				DrawCylinder(
					Vector3(aHorizonX[i], 0.1, aHorizonZ[i]),
					h * 0.4, 0.01, h,
					6, colHorizon
				)
			next

			# ---------- Sun ----------
			DrawSphere(
				Vector3(50, 60, -40),
				5.0,
				colSun
			)

		EndMode3D()

		# ---------- HUD Overlay ----------
		c = Color(0, 0, 0, 120)
		DrawRectangle(10, 10, 320, 100, c)
		c = Color(255, 255, 255, 255)
		DrawText("Ring 3D Forest Explorer", 20, 18, 22, GPData(c))
		c = Color(204, 255, 204, 255)
		DrawText("WASD / Arrows - Move", 20, 45, 16, GPData(c))
		c = Color(204, 255, 204, 255)
		DrawText("Mouse - Look | ESC - Exit", 20, 65, 16, GPData(c))
		c = Color(204, 255, 204, 255)
		DrawText("Space - Up | Shift - Down", 20, 85, 16, GPData(c))

		DrawFPS(SCREEN_WIDTH - 100, 10)

	EndDrawing()

end

CloseWindow()

# ============================================
# Helper: random float between 0 and 1
# ============================================
func randomFloat
	return random(10000) / 10000
