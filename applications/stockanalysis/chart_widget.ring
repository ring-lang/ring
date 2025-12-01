# Author: Azzeddine Remmal

load "guilib.ring"

qpainter_antialiasing = 1
qt_solidpattern = 1
qt_dotline = 1

class StockChart from QLabel
    
    aPortfolioData = []
    aQQQData = []
    
    func init(parent)
        super.init(parent)
        return this

    func setData(aPort, aQQQ)
        aPortfolioData = aPort
        aQQQData = aQQQ
        draw()
        
    func draw
        # Capture dimensions and data locally to avoid scope issues inside QPainter block
        w = this.width()
        h = this.height()
        aPort = aPortfolioData
        aQ = aQQQData
        
        if w < 10 or h < 10 return ok
        
        p1 = new qpicture()
        
        p = new qpainter() {
            begin(p1)
            setRenderHint(QPainter_Antialiasing, true)
            
            # Background
            fillRect(0, 0, w, h, new QBrush() { setStyle(Qt_SolidPattern) setColor(new QColor() { setRGB(40, 40, 40, 255) }) })
            
            if len(aPort) < 2
                setPen(new QPen() { setColor(new QColor() { setRGB(255, 255, 255, 255) }) })
                drawText(10, 20, "No Data to Display")
                endpaint()
            else
                pad = 40
                
                # Find Min/Max
                minVal = 1000
                maxVal = -1000
                
                for v in aPort 
                    if v < minVal minVal = v ok
                    if v > maxVal maxVal = v ok
                next
                for v in aQ 
                    if v < minVal minVal = v ok
                    if v > maxVal maxVal = v ok
                next
                
                range = maxVal - minVal
                if range = 0 range = 1 ok
                
                # Draw Grid (Detailed)
                gridPen = new QPen() { 
                    setColor(new QColor() { setRGB(70, 70, 70, 255) }) 
                    setStyle(Qt_DotLine) 
                }
                setPen(gridPen)
                
                # Horizontal lines
                nSteps = 10
                for i = 0 to nSteps
                    y = pad + (i * (h - 2*pad) / nSteps)
                    drawLine(pad, y, w - pad, y)
                next
                
                # Vertical lines
                for i = 0 to nSteps
                    x = pad + (i * (w - 2*pad) / nSteps)
                    drawLine(x, pad, x, h - pad)
                next

                # Draw Axes
                axisPen = new QPen() { setColor(new QColor() { setRGB(200, 200, 200, 255) }) setWidth(2) }
                setPen(axisPen)
                drawLine(pad, pad, pad, h - pad)
                drawLine(pad, h - pad, w - pad, h - pad)
                
                # Zero Line
                y1 = h - pad - (1.0 - minVal) * (h - 2*pad) / range
                if y1 >= pad and y1 <= h - pad
                    setPen(new QPen() { setColor(new QColor() { setRGB(150, 150, 150, 255) }) })
                    drawLine(pad, y1, w - pad, y1)
                ok
                
                # Draw QQQ (Red)
                setPen(new QPen() { setColor(new QColor() { setRGB(255, 80, 80, 255) }) setWidth(2) })
                nCount = len(aQ)
                for i = 1 to nCount - 1
                    x1 = pad + (i - 1) * (w - 2*pad) / (nCount - 1)
                    y1 = h - pad - (aQ[i] - minVal) * (h - 2*pad) / range
                    
                    x2 = pad + (i) * (w - 2*pad) / (nCount - 1)
                    y2 = h - pad - (aQ[i+1] - minVal) * (h - 2*pad) / range
                    
                    drawLine(x1, y1, x2, y2)
                next
                
                # Draw Portfolio (Green)
                setPen(new QPen() { setColor(new QColor() { setRGB(80, 255, 80, 255) }) setWidth(3) })
                nCount = len(aPort)
                for i = 1 to nCount - 1
                    x1 = pad + (i - 1) * (w - 2*pad) / (nCount - 1)
                    y1 = h - pad - (aPort[i] - minVal) * (h - 2*pad) / range
                    
                    x2 = pad + (i) * (w - 2*pad) / (nCount - 1)
                    y2 = h - pad - (aPort[i+1] - minVal) * (h - 2*pad) / range
                    
                    drawLine(x1, y1, x2, y2)
                next
                
                # Legend
                setPen(new QPen() { setColor(new QColor() { setRGB(255, 255, 255, 255) }) })
                drawText(w - 150, 30, "--- Portfolio (Green)")
                drawText(w - 150, 50, "--- QQQ (Red)")
                
                endpaint()
            ok
        }
        
        setPicture(p1)
        show()