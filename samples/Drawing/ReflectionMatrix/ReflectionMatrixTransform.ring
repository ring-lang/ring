// Reflection Matrix --- Flips Images about an Axis
// Matrix Transform A = Tx
// Author: Bert Mariani 
// Date:   2026/08/27
// -----------------------------------------------

load "guilib.ring"
Load "stdlibcore.ring"
Load "MatrixLib.ring"

load "ReflectionMatrixTransformChart.ring"
# --------------------------


# --------------------------

# Global Objects
 win           = null
 oChartWidget  = null
 txtLog        = null
 comboInterval = null
 comboRange    = null
 newDate       = null
 
 btnRun        = null
 btnExport     = null
 btnBrowse     = null
 txtTickerFile = null
App            = null

# ADD for Any Widget Field to make it Accessible to Later function
### comboTopTen     = null  // <<<<<
comboReflection = null  // <<<<< Transform picker (Tables 1, 2, 3, 4 -- Reflections,
                        //       Contractions/Expansions, Shears, Projections)
txtK            = null  // <<<<< "k" value used by the parametrized transforms
                        //       (contraction/expansion, shear) -- can be + or -



oSplashLabel = null     // Splash image shown at startup in right panel

//=================================================================
// TABLE 1/2/3/4 -- Reflections, Contractions/Expansions, Shears,
// and Projections. Index matches comboReflection's item order
// (1-based, Ring arrays).  { cTitle, cType }
//
// cType drives GetTransformMatrix() below:
//   "reflect_x1" / "reflect_x2" / "reflect_x2x1" / "reflect_x2negx1" / "reflect_origin"
//       -- Table 1, fixed matrices, no "k" involved
//   "hscale" / "vscale"   -- Table 2, Horizontal/Vertical contraction & expansion,
//                            matrix built from "k" (0 < k < 1 contracts, k > 1 expands;
//                            k may also be negative to flip + scale)
//   "hshear" / "vshear"   -- Table 3, Horizontal/Vertical shear, matrix built from "k"
//                            (k < 0 and k > 0 both valid -- shear direction)
//   "proj_x1" / "proj_x2" -- Table 4, fixed matrices, no "k" involved
//
// NOTE: this MUST be assigned here, as true global top-level code
// BEFORE "func main" -- func main runs App.exec(), which blocks for
// the entire life of the GUI, so any bare assignment placed AFTER
// func main (but before the next Func) is actually still part of
// main()'s own body/scope and would never be seen by RunReflection().
//=================================================================

aTransformTable = [
    [ "Reflection through the x1-axis",                "reflect_x1"      ],
    [ "Reflection through the x2-axis",                "reflect_x2"      ],
    [ "Reflection through the line x2 = x1",           "reflect_x2x1"    ],
    [ "Reflection through the line x2 = -x1",          "reflect_x2negx1" ],
    [ "Reflection through the origin",                 "reflect_origin"  ],
    [ "Horizontal contraction/expansion (k)",          "hscale"          ],
    [ "Vertical contraction/expansion (k)",            "vscale"          ],
    [ "Horizontal shear (k)",                          "hshear"          ],
    [ "Vertical shear (k)",                            "vshear"          ],
    [ "Horizontal contraction/expansion  [k = 2, positive]",   "hscale_k2"    ],
    [ "Horizontal contraction/expansion  [k = -2, negative]",  "hscale_kneg2" ],
    [ "Vertical contraction/expansion  [k = 2, positive]",     "vscale_k2"    ],
    [ "Vertical contraction/expansion  [k = -2, negative]",    "vscale_kneg2" ],
    [ "Horizontal shear  [k = 2]",                             "hshear_k2"    ],
    [ "Horizontal shear  [k = 0.5]",                           "hshear_k05"   ],
    [ "Vertical shear  [k = 2]",                               "vshear_k2"    ],
    [ "Vertical shear  [k = 0.5]",                             "vshear_k05"   ],
    [ "Projection onto the x1-axis",                   "proj_x1"         ],
    [ "Projection onto the x2-axis",                   "proj_x2"         ]
]



# =========================================

// There are 19 predefined QColor objects: 
// white, black, red, darkRed, green, darkGreen, blue, darkBlue, cyan, darkCyan, 
// magenta, darkMagenta, yellow, darkYellow, gray, darkGray, lightGray, color0 


# Constants for Styling
C_STYLE_DARK = "
    QWidget {
        background-color: #2b2b2b;
        color: #000000 ;             // #ffffff;
        font-family: 'Segoe UI', sans-serif;
        font-size: 17px;
    }
    QPushButton {
        background-color: #007acc;
        border: none;
        padding: 8px 16px;
        border-radius: 4px;
        color: white;
        font-weight: bold;
    }
    QPushButton:hover {
        background-color: #005999;
    }
    QPushButton:pressed {
        background-color: #004080;
    }
    QLineEdit, QComboBox {
        background-color: #3c3c3c;
        border: 1px solid #555;
        padding: 4px;
        border-radius: 3px;
        color: white;
    }
    QFrame {
        border: 1px solid #555;
        border-radius: 5px;
        margin-top: 10px;
        padding: 5px;
        background-color: #333;
    }
    QLabel {
        font-weight: bold;
        color: #cccccc;
    }
"

# =====================================
# =====================================

func main
    App = new QApp
        
      
    win = new QWidget() {
        setWinIcon(self,"appicon.png")
        setWindowTitle("Reflection Matrix - Rotate about an Axis")
        resize(1400, 850)
        setStyleSheet(C_STYLE_DARK)

        # --- Layouts ---
        mainLayout     = new QVBoxLayout()
        controlsLayout = new QHBoxLayout()
        contentLayout  = new QHBoxLayout()

	    ###-----------------------------------
        ### Font Type and Size
            
        oFont = new qfont('Segoe UI',16,0,0)
        setfont(oFont)
		
        # --- Controls Section ---
        groupControls = new QFrame( win,0) {
            setFrameShape(QFrame_StyledPanel)
            setMaximumHeight(160)       // Tall enough for 2 rows + scroll list
            setSizePolicy(1, 0)         // Horizontal=Expanding, Vertical=Fixed
            
            # Main layout for the frame (Vertical - holds Row1 and Row2)
            frameLayout = new QVBoxLayout() {
                setContentsMargins(4, 2, 4, 2)   // Tight top/bottom margins
                setSpacing(2)
						

                # ---- ROW 1: Dollars + Debug ----
                row1Layout = new QHBoxLayout() {

					//-------------------------
					// --- CurrentDate

					addWidget(new QLabel(win){setText(" Date: " )})
				    newDate = new QLineEdit(win) {
                        setText("  "+ Date() +"  "+ Time())         // Fill in with Current Date-Time  15/05/2026 09:30
                        setFixedWidth(130)                      
                    }
                    addWidget(newDate)
										
					//--------------------------
                    # Stretch to push items to the left
                    addStretch(1)
                }
                addLayout(row1Layout)

                # --------------------------------------
                # ---- ROW 2: All original controls ----
                controlsLayoutInner = new QHBoxLayout() {
                                                              
                    
                                        
                    # -----------------------
                    # Transform picker (Tables 1-4: Reflections, Contractions/
                    # Expansions, Shears, Projections)
					
                    addWidget(new QLabel(win){setText(" Transform: ")})
                    comboReflection = new QComboBox(win){
                            abcList = ["X1-axis", "X2-axis", "Line X2 = X1", "Line X2 = -X1", "Origin",
                                       "H-contract/expand (k)", "V-contract/expand (k)",
                                       "H-shear (k)", "V-shear (k)",
                                       "H-contract/expand (k=2, +)", "H-contract/expand (k=-2, -)",
                                       "V-contract/expand (k=2, +)", "V-contract/expand (k=-2, -)",
                                       "H-shear (k=2)", "H-shear (k=0.5)",
                                       "V-shear (k=2)", "V-shear (k=0.5)",
                                       "Project onto X1-axis", "Project onto X2-axis"]
                        for x in abcList additem(x,0) next
                        }
                    addWidget(comboReflection)

                    # "k" value -- used only by the 4 parametrized transforms
                    # (H/V contraction-expansion, H/V shear). Can be + or -.
					
                    addWidget(new QLabel(win){setText(" K: ")})
                    txtK = new QLineEdit(win){setText("2") setFixedWidth(45)}
                    addWidget(txtK)

                    # Run Quotes Button
                    btnQuotes = new QPushButton(win){setText("Run Reflection")}
                    btnQuotes.setStyleSheet("background-color: cyan;")
                    btnQuotes.setClickEvent("RunReflection()")
                    addWidget(btnQuotes)

                   
                    //-------------------
                    //------------------                

                    # Stretch to push items to the left (matches row1Layout)
                    addStretch(1)
                }
                addLayout(controlsLayoutInner)
            }
            setLayout(frameLayout)
        }

        # --- Content Section ---
       
        # Left: Data/Log
        groupData = new QFrame(win,0) {
            setFrameShape(QFrame_StyledPanel)
            frameLayout = new QVBoxLayout() {
                lblTitle = new QLabel(win) {
                    setText("Analysis Log")
                    setStyleSheet("color: #007acc; font-weight: bold;font-size: 14px;")
                }
                addWidget(lblTitle)

                txtLog = new QTextEdit(win){setReadOnly(true)setStyleSheet("font-size: 13px; font-family: Consolas, 'Courier New', monospace;")setText("Ready to start...")}
				txtLog.append("Date: "+ Date() +"  "+ Time() )
                //App.processEvents() # Keep UI responsive
				
                addWidget(txtLog)
            }
            setLayout(frameLayout)
        }

        # Right: Chart Area
        groupChart = new QFrame(win, 0) {
            setFrameShape(QFrame_StyledPanel)
            frameLayout = new QVBoxLayout() {
                lblTitle = new QLabel(win) {
                    setText("Performance Chart")
                    setStyleSheet("color: #007acc; font-weight: bold; font-size: 14px;")
                    setMaximumHeight(40)
                }
                addWidget(lblTitle)

                oChartWidget = new MatrixTransformChart( win)
                oChartWidget.hide()   // Hidden until a transform is drawn (see RunReflection / RunTransformTest)
                addWidget(oChartWidget)

                # Splash image shown at startup — capped to natural image size (373x576)
                oSplashLabel = new QLabel(win) {
                    splashPixmap = new QPixmap("Images-Reflection.png")
                    scaledPixmap = splashPixmap.scaled(373, 576, 1, 1)  // natural size, KeepAspectRatio=1, SmoothTransform=1
                    setPixmap(scaledPixmap)
                    setAlignment(132)   // Qt::AlignHCenter | Qt::AlignVCenter
                    setScaledContents(false)
                    setMaximumSize(373, 576)
                }
                addWidget(oSplashLabel)
            }
            setLayout(frameLayout)
        }

        # --- Add widgets to layouts 16px
        controlsLayout.addWidget(groupControls)

        // --- Overview content (Log + Chart) — no tab widget, no stat cards ---
        overviewWrap = new QWidget()
        overviewV    = new QVBoxLayout() {
            setContentsMargins(0, 0, 0, 0)
        }

    existingH = new QHBoxLayout()
    existingH.addWidget(groupData)
    existingH.addWidget(groupChart)
    existingH.setStretch(0, 1)
    existingH.setStretch(1, 2)

    existingWrap = new QWidget()
    existingWrap.setLayout(existingH)
    overviewV.addWidget(existingWrap)

        overviewWrap.setLayout(overviewV)
        contentLayout.addWidget(overviewWrap)

        mainLayout.addLayout(controlsLayout)
        mainLayout.addLayout(contentLayout)
        mainLayout.setStretch(0, 0)    // Controls row: do NOT stretch
        mainLayout.setStretch(1, 1)    // Content area: takes all remaining space

        setLayout(mainLayout)

        # Chart is drawn on demand -- click "RunReflection" to run the
        # Reflection-through-x1 test (see RunReflection() / RunTransformTest()
        # below). Drawing here, before the window is shown, would give
        # oChartWidget an unreliable width()/height().

        show()
    }

    App.exec()
 

//=================================================================
// RunReflection() -- handler for the "RunReflection" button (btnQuotes).
// Reads the selected transform from comboReflection (and, for the
// parametrized transforms, the "k" value from txtK), looks it up in
// aTransformTable, builds the matrix, and runs it. By this point the
// window is fully shown, so oChartWidget has a real width()/height().
//=================================================================

Func RunReflection()
    nSel = comboReflection.currentIndex() + 1    // Qt is 0-based, Ring arrays are 1-based
    if nSel < 1 or nSel > len(aTransformTable)
        nSel = 1
    ok

    aRow   = aTransformTable[nSel]
    cTitle = aRow[1]
    cType  = aRow[2]

    # "k" only matters for the 4 parametrized transforms, but we always
    # read it (harmless / ignored otherwise) -- defaults to 0 if not numeric.
    k = 0
    if txtK != null  k = number(txtK.text())  ok

    aMatrix = GetTransformMatrix(cType, k)

    # Show the actual k used in the title for the parametrized transforms
    if cType = "hscale" or cType = "vscale" or cType = "hshear" or cType = "vshear"
        cTitle = cTitle + "   [k = " + NumStr(k) + "]"
    ok

    cMatrixText = BuildMatrixText(aMatrix)

    if txtLog != null
        txtLog.append("")
        txtLog.append("RunReflection clicked -- " + cTitle)
    ok

    RunTransformTest(aMatrix, cTitle, cMatrixText)
Return

//-----------------------------------------------------------------
// GetTransformMatrix(cType, k) -- builds the 2x2 standard matrix for
// the selected transform. Tables 1 & 4 ignore k (fixed matrices);
// Tables 2 & 3 build the matrix from k (k may be + or -).
//-----------------------------------------------------------------

Func GetTransformMatrix(cType, k)
    if cType = "reflect_x1"        return [[ 1, 0], [ 0,-1]] ok   // Table 1
    if cType = "reflect_x2"        return [[-1, 0], [ 0, 1]] ok   // Table 1
    if cType = "reflect_x2x1"      return [[ 0, 1], [ 1, 0]] ok   // Table 1
    if cType = "reflect_x2negx1"   return [[ 0,-1], [-1, 0]] ok   // Table 1
    if cType = "reflect_origin"    return [[-1, 0], [ 0,-1]] ok   // Table 1
    if cType = "hscale"            return [[ k, 0], [ 0, 1]] ok   // Table 2: Horizontal contraction/expansion
    if cType = "vscale"            return [[ 1, 0], [ 0, k]] ok   // Table 2: Vertical contraction/expansion
    if cType = "hshear"            return [[ 1, k], [ 0, 1]] ok   // Table 3: Horizontal shear
    if cType = "vshear"            return [[ 1, 0], [ k, 1]] ok   // Table 3: Vertical shear

    # --- Fixed-preset cases (ignore the "k:" input box -- k is baked in) ---
    if cType = "hscale_k2"         return [[ 2, 0], [ 0, 1]] ok   // Table 2: Horizontal, k positive
    if cType = "hscale_kneg2"      return [[-2, 0], [ 0, 1]] ok   // Table 2: Horizontal, k negative
    if cType = "vscale_k2"         return [[ 1, 0], [ 0, 2]] ok   // Table 2: Vertical, k positive
    if cType = "vscale_kneg2"      return [[ 1, 0], [ 0,-2]] ok   // Table 2: Vertical, k negative
    if cType = "hshear_k2"         return [[ 1, 2  ], [ 0, 1]] ok // Table 3: Horizontal shear, k = 2
    if cType = "hshear_k05"        return [[ 1, 0.5], [ 0, 1]] ok // Table 3: Horizontal shear, k = 0.5
    if cType = "vshear_k2"         return [[ 1, 0], [ 2,   1]] ok // Table 3: Vertical shear, k = 2
    if cType = "vshear_k05"        return [[ 1, 0], [ 0.5, 1]] ok // Table 3: Vertical shear, k = 0.5

    if cType = "proj_x1"           return [[ 1, 0], [ 0, 0]] ok   // Table 4: Projection onto x1-axis
    if cType = "proj_x2"           return [[ 0, 0], [ 0, 1]] ok   // Table 4: Projection onto x2-axis
Return [[1,0],[0,1]]   // fallback: identity

//-----------------------------------------------------------------
// BuildMatrixText(aM) -- "[ a  b / c  d ]" display string for any
// 2x2 matrix (replaces the old per-row hardcoded matrix-text column).
//-----------------------------------------------------------------

Func BuildMatrixText(aM)
Return "[" + NumStr(aM[1][1]) + " " + NumStr(aM[1][2]) + " / " +
             NumStr(aM[2][1]) + " " + NumStr(aM[2][2]) + "]"

//=================================================================
// RunTransformTest(aMatrix, cTitle, cMatrixText)
// (generalized from the original RunReflectionX1Test / Test-ReflectionX1.ring)
//
//   aMatrix     : 2x2 standard matrix, e.g. [[1,0],[0,-1]] or [[2,0],[0,1]]
//   cTitle      : heading, e.g. "Reflection through the x1-axis"
//   cMatrixText : display text for the matrix, e.g. "[1 0 / 0 -1]"
//
// Logs the BEFORE matrix (standard basis e1/e2), the TRANSFORM
// (aMatrix), and the AFTER matrix (transformed e1'/e2') to the
// Analysis Log, then draws the transform into oChartWidget.
//=================================================================

Func RunTransformTest(aMatrix, cTitle, cMatrixText)

    # --- BEFORE: standard basis vectors ---
    aE1Before = [1, 0]
    aE2Before = [0, 1]

    # --- Apply the transform ---
    aE1 = MatrixTimesVector(aMatrix, aE1Before)
    aE2 = MatrixTimesVector(aMatrix, aE2Before)

    # --- Log TRANSFORM / BEFORE / AFTER to the Analysis Log, with the
    #     "e1/e2" bracket values lined up vertically between Before and
    #     After (equal-width prefixes, equal-width "e1 "/"e1'" labels,
    #     and a common numeric column width -- see PadRight()/PadLeft()/
    #     NumStr() below). Unlike plain reflections, k-driven transforms
    #     (contraction/expansion, shear) can produce any real number, not
    #     just -1/0/1, so the column width is computed fresh each run. ---
    if txtLog != null
        cLabelBefore = PadRight("Before (standard basis):", 25) + "  "
        cLabelAfter  = PadRight("After (A * e1, A * e2):",  25) + "  "

        # Widest formatted number across all 8 values this run -> common width
        nW = 1
        for v in [aE1Before[1], aE1Before[2], aE2Before[1], aE2Before[2],
                   aE1[1], aE1[2], aE2[1], aE2[2]]
            nLen = len(NumStr(v))
            if nLen > nW  nW = nLen  ok
        next

        cE1Before = "e1 " + " = [" + PadLeft(NumStr(aE1Before[1]),nW) + ", " + PadLeft(NumStr(aE1Before[2]),nW) + "]"
        cE2Before = "e2 " + " = [" + PadLeft(NumStr(aE2Before[1]),nW) + ", " + PadLeft(NumStr(aE2Before[2]),nW) + "]"
        cE1After  = "e1'" + " = [" + PadLeft(NumStr(aE1[1]),nW)       + ", " + PadLeft(NumStr(aE1[2]),nW)       + "]"
        cE2After  = "e2'" + " = [" + PadLeft(NumStr(aE2[1]),nW)       + ", " + PadLeft(NumStr(aE2[2]),nW)       + "]"

        txtLog.append("---- " + cTitle + " ----")
        txtLog.append("Transform (Standard Matrix A):  " + cMatrixText)
        txtLog.append(cLabelBefore + cE1Before + "   " + cE2Before)
        txtLog.append(cLabelAfter  + cE1After  + "   " + cE2After)
    ok

    # --- Sanity check: e1' must equal column 1 of A, e2' must equal column 2 of A ---
    AssertLogEqual(aE1[1], aMatrix[1][1], "e1.x")
    AssertLogEqual(aE1[2], aMatrix[2][1], "e1.y")
    AssertLogEqual(aE2[1], aMatrix[1][2], "e2.x")
    AssertLogEqual(aE2[2], aMatrix[2][2], "e2.y")

    if oSplashLabel != null  oSplashLabel.hide()  ok
    oChartWidget.show()
    oChartWidget.setPoints( aE1, aE2, cTitle, cMatrixText )

Return

//-----------------------------------------------------------------
// 2x2 matrix * 2-vector  -->  [x, y]

Func MatrixTimesVector(aM, aV)
    x = aM[1][1] * aV[1] + aM[1][2] * aV[2]
    y = aM[2][1] * aV[1] + aM[2][2] * aV[2]
Return [x, y]

//-----------------------------------------------------------------
// Pads a string on the right with spaces up to nWidth chars (no-op
// if already >= nWidth). Used to make the "Before"/"After" prefixes
// the same width so their "e1/e2" values line up in the Analysis Log.

Func PadRight(cStr, nWidth)
    while len(cStr) < nWidth
        cStr += " "
    end
Return cStr

//-----------------------------------------------------------------
// Right-justifies a string to nWidth chars by adding leading spaces
// (no-op if already >= nWidth). Used to line up numeric columns like
// [ 1,  0] / [-1,  0] / [ 2.5, 0] regardless of digit count/sign.

Func PadLeft(cStr, nWidth)
    while len(cStr) < nWidth
        cStr = " " + cStr
    end
Return cStr

//-----------------------------------------------------------------
// Converts a number to a clean display string -- trims a trailing
// ".000000"-style artifact down to a plain integer, but keeps real
// decimals (e.g. a fractional "k" like 2.5) intact. Needed because
# the parametrized transforms (contraction/expansion, shear) can
# produce any real number, not just -1/0/1.

Func NumStr(n)
    cStr = "" + n
    if substr(cStr, ".") > 0
        while right(cStr, 1) = "0"
            cStr = left(cStr, len(cStr) - 1)
        end
        if right(cStr, 1) = "."
            cStr = left(cStr, len(cStr) - 1)
        ok
    ok
Return cStr

//-----------------------------------------------------------------
// Sanity-check helper -- logs to the Analysis Log panel ONLY when a
// check fails, so a normal (passing) run stays quiet/readable.

Func AssertLogEqual(nActual, nExpected, cLabel)
    if txtLog = null  return  ok
    if nActual != nExpected
        txtLog.append("FAIL: " + cLabel + "  (expected " + nExpected + ", got " + nActual + ")")
    ok
Return

//=================================================================
