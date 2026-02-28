# Author: Gal Zsolt (CalmoSoft)
load "guilib.ring"

new qApp {
    win = new qWidget() {
        setWindowTitle("Yin-Yang - CalmoSoft")
        resize(400, 400)
        label = new qLabel(win) {
            resize(400, 400)
            
            # Create the image
            image = new qPixmap2(400, 400)
            color_gray = new qColor() { setRgb(200,200,200,255) }
            image.fill(color_gray)
            
            p1 = new qPainter()
            p1.begin(image)
            p1.setRenderHint(1, true)

            # Colors and brushes defined individually
            white = new qColor() { setRgb(255,255,255,255) }
            black = new qColor() { setRgb(0,0,0,255) }
            wBrush = new qBrush() { setStyle(1) setColor(white) }
            bBrush = new qBrush() { setStyle(1) setColor(black) }

            # 1. Base circles (using drawChord with 5 parameters instead of drawPie)
            p1.setBrush(wBrush)
            p1.drawChord(50, 50, 300, 300, 90 * 16, 180 * 16)
            p1.setBrush(bBrush)
            p1.drawChord(50, 50, 300, 300, 270 * 16, 180 * 16)

            # 2. Middle circles (forming the S-shape)
            p1.setBrush(bBrush)
            p1.drawEllipse(125, 50, 150, 150)
            p1.setBrush(wBrush)
            p1.drawEllipse(125, 200, 150, 150)

            # 3. Small dots (the "eyes")
            p1.setBrush(wBrush)
            p1.drawEllipse(185, 110, 30, 30)
            p1.setBrush(bBrush)
            p1.drawEllipse(185, 260, 30, 30)

            p1.endpaint()
            setPixmap(image)
        }
        show()
    }
    exec()
}