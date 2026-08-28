# Author: Bert Mariani 
# Date:   2026/08/27
# rewrite: MatrixTransformChart -- draws 2D linear/reflection transforms
#          (unit square + transformed square + the two basis-vector dots)
#          in the "Performance Chart" QLabel area.
#
# USAGE
# -----
#   oChart = new MatrixTransformChart(win)
#   oChart.setPoints( aE1, aE2, cTitle )
#
#     aE1, aE2 : the MATRIX-TRANSFORMED coordinates of the two standard
#                basis vectors, i.e. the two dots to plot --
#                   aE1 = A * [1,0]      (image of e1)
#                   aE2 = A * [0,1]      (image of e2)
#                Each is a 2-item array [ x, y ].
#     cTitle   : optional heading text, e.g. "Reflection through the x1-axis"
#
# The class draws:
#   - the x1 (horizontal) / x2 (vertical) axes with arrowheads
#   - the ORIGINAL unit square (light blue) -- corners 0, e1, e1+e2, e2
#     using the untransformed basis [1,0] / [0,1] -- line-filled with
#     HORIZONTAL hatch lines
#   - the TRANSFORMED square (red outline) -- corners 0, aE1, aE1+aE2, aE2
#     -- line-filled by running those SAME horizontal reference lines
#     through the transform, so the fill direction naturally follows
#     whatever the transform actually does (e.g. a vertical shear turns
#     horizontal lines diagonal; a x2=x1 reflection turns them vertical)
#   - the two dots at aE1 / aE2, each labeled with its column-vector value

load "guilib.ring"

qpainter_antialiasing = 1
qt_solidpattern = 1

###-------------------------------
### Colours, Pens, Brushes actually used by this chart

colorBlack       = new qcolor() { setrgb(  0,  0,  0,255) }  // axis text / vector labels
colorWhite       = new qcolor() { setrgb(255,255,255,255) }  // background
colorSquareLine  = new qcolor() { setrgb( 70,150,220,255) }  // blue outline  -- original (Before) unit square
colorReflectLine = new qcolor() { setrgb(200, 40, 40,255) }  // red outline   -- transformed (After) square
colorSquareFill  = new qcolor() { setrgb(160,205,240,255) }  // lighter blue  -- Before hatch lines
colorReflectFill = new qcolor() { setrgb(235,150,150,255) }  // lighter red   -- After hatch lines
colorDotE1       = new qcolor() { setrgb(220,120,  0,255) }  // orange dot    -- e1
colorDotE2       = new qcolor() { setrgb(  0,120,220,255) }  // blue dot      -- e2
colorAxis        = new qcolor() { setrgb(  0,  0,  0,255) }  // axis lines

penBlack     = new qpen() { setcolor(colorBlack)        setwidth(1) }
penAxis      = new qpen() { setcolor(colorAxis)         setwidth(2) }
penSquare    = new qpen() { setcolor(colorSquareLine)   setwidth(2) }
penReflect   = new qpen() { setcolor(colorReflectLine)  setwidth(2) }
penSquareFill  = new qpen() { setcolor(colorSquareFill)   setwidth(1) }
penReflectFill = new qpen() { setcolor(colorReflectFill)  setwidth(1) }

brushBack    = new qbrush() { setstyle(1)  setcolor (colorWhite)}    // Background
brushDotE1   = new qbrush() { setstyle(1)  setcolor (colorDotE1)}
brushDotE2   = new qbrush() { setstyle(1)  setcolor (colorDotE2)}

brushLegendBefore = new qbrush() { setstyle(1)  setcolor (colorSquareLine)}    // legend swatch -- Before
brushLegendAfter  = new qbrush() { setstyle(1)  setcolor (colorReflectLine)}   // legend swatch -- After

// ======================================================================

class MatrixTransformChart from QLabel

    # --- Data sent in from caller: the two transformed basis-vector dots
    aE1     = [1, 0]      // image of e1 = A * [1,0]
    aE2     = [0, 1]      // image of e2 = A * [0,1]
    cTitle  = ""          // heading, e.g. "Reflection through the x1-axis"
    cMatrix = ""          // optional "Standard Matrix" text, e.g. "[1 0 / 0 -1]"

    # ================================
    Func init(parent)
        super.init(parent)
        return this

    # ================================
    # Called by the app whenever a new transform should be displayed.
    #   aNewE1 / aNewE2 : [x, y] arrays -- the transformed dot coordinates
    #   cNewTitle       : optional title text
    #   cNewMatrix      : optional "standard matrix" text
	
    Func setPoints(aNewE1, aNewE2, cNewTitle, cNewMatrix)
        aE1 = aNewE1
        aE2 = aNewE2
        if isString(cNewTitle)   cTitle  = cNewTitle   ok
        if isString(cNewMatrix)  cMatrix = cNewMatrix  ok

        Draw()   // ===>>> DRAW

    # ================================
    Func Draw
        w = this.width()
        h = this.height()

        if w < 10 or h < 10 return ok

        e1x = aE1[1]   e1y = aE1[2]
        e2x = aE2[1]   e2y = aE2[2]

        # Class attributes must be copied to plain locals here -- bare
        # references inside the nested "new qpainter() { ... }" block
        # below resolve against THAT object's scope, not this method's,
        # so cTitle/cMatrix (self attributes) would read as uninitialized.
		
        cTitleLocal  = cTitle
        cMatrixLocal = cMatrix

        p1 = new qpicture()

        p = new qpainter() {
            begin(p1)
            setRenderHint(QPainter_Antialiasing, true)

            #--- Background
            fillRect(0, 0, w, h, brushBack)

            pad = 60   // room for axis labels + the Before/After legend

            #--- Work out a common (square-pixel) scale that fits both
            #    the original unit square and the transformed square,
            #    plus a little breathing room around the outermost points.
			
            aXs = [0, 1, 1, 0, e1x, e2x, e1x + e2x]
            aYs = [0, 0, 1, 1, e1y, e2y, e1y + e2y]

            minX = 0   maxX = 0
            minY = 0   maxY = 0
            for v in aXs
                if v < minX minX = v ok
                if v > maxX maxX = v ok
            next
            for v in aYs
                if v < minY minY = v ok
                if v > maxY maxY = v ok
            next

            #--- Margin so points/labels never touch the frame
            margin = 0.6
            minX -= margin   maxX += margin
            minY -= margin   maxY += margin

            rangeX = maxX - minX   if rangeX = 0  rangeX = 1  ok
            rangeY = maxY - minY   if rangeY = 0  rangeY = 1  ok

            scaleX = (w - 2*pad) / rangeX
            scaleY = (h - 2*pad) / rangeY
            scale  = scaleX
            if scaleY < scale  scale = scaleY  ok

            #--- Origin in pixel space (0,0 in math coords)
            ox = pad - minX * scale
            oy = h - pad + minY * scale

            #--- Local coord ==> pixel helpers -------------------------
            # (defined inline below since Ring class methods can't easily
            #  be called mid-QPainter-block; simple arithmetic instead)

            #============================================================
            #  AXES  (x1 horizontal, x2 vertical) with arrowheads
            #============================================================
            setPen(penAxis)

            # x1 axis (horizontal, y = 0)
            axisY0 = oy - 0 * scale
            drawLine(pad, axisY0, w - pad, axisY0)
            
			# arrowhead at right end
            drawLine(w - pad, axisY0, w - pad - 8, axisY0 - 4)
            drawLine(w - pad, axisY0, w - pad - 8, axisY0 + 4)

            # x2 axis (vertical, x = 0)
            axisX0 = ox + 0 * scale
            drawLine(axisX0, h - pad, axisX0, pad)
            
			# arrowhead at top end
            drawLine(axisX0, pad, axisX0 - 4, pad + 8)
            drawLine(axisX0, pad, axisX0 + 4, pad + 8)

            setFont(new qfont("Arial", 11, 75, 0))
            drawText(w - pad - 6, axisY0 - 10, "x1")
            drawText(axisX0 + 8,  pad + 12,    "x2")

            #============================================================
            #  ORIGINAL unit square: corners 0, [1,0], [1,1], [0,1]
            #============================================================
            setPen(penSquare)

            sqX1 = ox + 0 * scale   sqY1 = oy - 0 * scale
            sqX2 = ox + 1 * scale   sqY2 = oy - 0 * scale
            sqX3 = ox + 1 * scale   sqY3 = oy - 1 * scale
            sqX4 = ox + 0 * scale   sqY4 = oy - 1 * scale

            drawLine(sqX1, sqY1, sqX2, sqY2)
            drawLine(sqX2, sqY2, sqX3, sqY3)
            drawLine(sqX3, sqY3, sqX4, sqY4)
            drawLine(sqX4, sqY4, sqX1, sqY1)

            #============================================================
            #  TRANSFORMED square: corners 0, aE1, aE1+aE2, aE2
            #============================================================
            setPen(penReflect)

            rx1 = ox + 0 * scale         ry1 = oy - 0 * scale
            rx2 = ox + e1x * scale       ry2 = oy - e1y * scale
            rx3 = ox + (e1x+e2x)*scale   ry3 = oy - (e1y+e2y)*scale
            rx4 = ox + e2x * scale       ry4 = oy - e2y * scale

            drawLine(rx1, ry1, rx2, ry2)
            drawLine(rx2, ry2, rx3, ry3)
            drawLine(rx3, ry3, rx4, ry4)
            drawLine(rx4, ry4, rx1, ry1)

            #============================================================
            #  LINE-FILL (hatching)
            #  Before is always plain horizontal lines across the unit
            #  square. After reuses those SAME reference lines but runs
            #  each one through the transform -- point (x,y) maps to
            #  x*e1 + y*e2 (that's exactly what aE1/aE2 already encode),
            #  so the fill direction automatically matches the transform
            #  instead of needing a separate direction picked per case.
            #============================================================
            nFillLines = 9   // interior lines only -- edges are already the outline

            setPen(penSquareFill)
            for i = 1 to nFillLines
                fy = i / (nFillLines + 1)

                bx1 = ox + 0 * scale   by1 = oy - fy * scale
                bx2 = ox + 1 * scale   by2 = oy - fy * scale
                drawLine(bx1, by1, bx2, by2)
            next

            setPen(penReflectFill)
            for i = 1 to nFillLines
                fy = i / (nFillLines + 1)

                # Transform the line's two endpoints, (0,fy) and (1,fy),
                # through the same map that produced aE1/aE2.
				
                tx1 = 0*e1x + fy*e2x   ty1 = 0*e1y + fy*e2y
                tx2 = 1*e1x + fy*e2x   ty2 = 1*e1y + fy*e2y

                gx1 = ox + tx1 * scale   gy1 = oy - ty1 * scale
                gx2 = ox + tx2 * scale   gy2 = oy - ty2 * scale
                drawLine(gx1, gy1, gx2, gy2)
            next

            #============================================================
            #  DOTS -- the two transformed basis vectors (sent to Draw)
            #============================================================
            dotR = 4   // half-size of the dot square, in pixels

            # e1 dot (orange)
            px1 = ox + e1x * scale
            py1 = oy - e1y * scale
            fillRect(px1 - dotR, py1 - dotR, dotR*2, dotR*2, brushDotE1)

            # e2 dot (blue)
            px2 = ox + e2x * scale
            py2 = oy - e2y * scale
            fillRect(px2 - dotR, py2 - dotR, dotR*2, dotR*2, brushDotE2)

            #--- Column-vector style labels next to each dot ------------
            setPen(penBlack)
            setFont(new qfont("Arial", 9, 50, 0))

            drawText(px1 +  8, py1 - 10, "["+ e1x +"]")
            drawText(px1 +  8, py1 + 4,  "["+ e1y +"]")
            drawText(px1 + 24, py1 - 3,  "e1")

            drawText(px2 +  8, py2 - 10, "["+ e2x +"]")
            drawText(px2 +  8, py2 + 4,  "["+ e2y +"]")
            drawText(px2 + 24, py2 - 3,  "e2")

            #============================================================
            #  Title / matrix text at the top
            #============================================================
            setPen(penBlack)
            setFont(new qfont("Arial", 11, 75, 0))
            if cTitleLocal != ""
                drawText(pad, 18, cTitleLocal)
            ok

            setFont(new qfont("Arial", 10, 50, 0))
            if cMatrixLocal != ""
                drawText(pad, 34, "Standard Matrix: " + cMatrixLocal)
            ok

            #--- Before / After legend -----------------------------------
            # Needed because some transforms (e.g. reflection through the
            # line x2 = x1) map the unit square exactly onto itself, so
            # the Before and After outlines/hatching land on top of each
            # other -- the legend is the only way to tell them apart then.
			
            setFont(new qfont("Arial", 9, 50, 0))

            fillRect(pad, 44, 10, 10, brushLegendBefore)
            drawText(pad + 14, 53, "Before")

            fillRect(pad + 70, 44, 10, 10, brushLegendAfter)
            drawText(pad + 84, 53, "After")

            endpaint()
        }

        setPicture(p1)
        show()

# ============================
