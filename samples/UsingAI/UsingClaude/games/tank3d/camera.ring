/*
**  tank3d_camera.ring
**  Camera update and modes
*/

// =============================================================
// Camera Update
// =============================================================

func tank_updateCamera
    cx = GRID_W / 2.0
    cz = GRID_H / 2.0

    if camMode = CAM_TOP
        cam.position.x = cx
        cam.position.y = 38.0
        cam.position.z = cz + 2.0
        cam.target.x = cx
        cam.target.y = 0
        cam.target.z = cz
        cam.fovy = 42
    ok
    if camMode = CAM_ANGLE
        cam.position.x = cx
        cam.position.y = 28.0
        cam.position.z = cz + 20.0
        cam.target.x = cx
        cam.target.y = 0
        cam.target.z = cz
        cam.fovy = 42
    ok
    if camMode = CAM_CLOSE
        // Follow player
        cam.position.x = px
        cam.position.y = 18.0
        cam.position.z = py + 12.0
        cam.target.x = px
        cam.target.y = 0
        cam.target.z = py
        cam.fovy = 42
    ok

    // Apply screen shake
    if shakeTimer > 0
        shakeFactor = shakeTimer / shakeDuration
        shakeAmt = shakeIntensity * shakeFactor
        cam.position.x += (GetRandomValue(-100, 100) / 100.0) * shakeAmt
        cam.position.y += (GetRandomValue(-100, 100) / 100.0) * shakeAmt * 0.5
        cam.position.z += (GetRandomValue(-100, 100) / 100.0) * shakeAmt
    ok
