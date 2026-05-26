/*
**  Dave the Fighter - Camera Control
**  Functions: dave_updateCamera
*/

func dave_updateCamera
    // Center camera on player
    cx = px * CELL_SZ
    cy = py * CELL_SZ

    if camMode = CAM_SIDE
        cam.position.x = cx
        cam.position.y = cy + 4.0
        cam.position.z = 18.0
        cam.target.x = cx
        cam.target.y = cy
        cam.target.z = 0.0
        cam.up.x = 0
        cam.up.y = 1
        cam.up.z = 0
    ok
    if camMode = CAM_ANGLE
        cam.position.x = cx - 5.0
        cam.position.y = cy + 10.0
        cam.position.z = 14.0
        cam.target.x = cx + 2.0
        cam.target.y = cy
        cam.target.z = 0.0
        cam.up.x = 0
        cam.up.y = 1
        cam.up.z = 0
    ok
    if camMode = CAM_TOP
        cam.position.x = cx
        cam.position.y = cy + 20.0
        cam.position.z = 0.5
        cam.target.x = cx
        cam.target.y = cy
        cam.target.z = 0.0
        cam.up.x = 0
        cam.up.y = 0
        cam.up.z = -1
    ok
