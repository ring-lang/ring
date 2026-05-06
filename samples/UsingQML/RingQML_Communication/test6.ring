/*
	RingQt Sample: Color Picker with Ring <--> QML Communication
	Demonstrates:
		- QML sliders send values to Ring on every drag
		- Ring computes hex color and updates QML preview
		- QML preset colors call Ring to parse and update all sliders
		- Real-time frequent updates between Ring and QML
*/

load "guilib.ring"
load "lib/ringcode.ring"

nRed = 128
nGreen = 128
nBlue = 128

new qApp {

	w = new qWidget() {

		setWindowTitle("Ring/QML Color Picker")
		resize(650, 500)
		move(100, 100)

		oQuick = new qQuickWidget(w) {
			engine().AddImportPath(exefolder() + "qml")
		}

		# Ring --> QML: Set title
		oContext = oQuick.rootContext()
		oContext.setContextProperty("appTitle",
			new QVariantString("Ring Color Picker"))

		# Load QML
		oQuick {
			setSource(AppURL("qml/colorpicker.qml"))
			setResizeMode(1)
		}

		# QML --> Ring: Slider changes and presets
		new RingCode(oQuick, "btnRed", "onRedChanged()")
		new RingCode(oQuick, "btnGreen", "onGreenChanged()")
		new RingCode(oQuick, "btnBlue", "onBlueChanged()")
		new RingCode(oQuick, "btnPreset", "onPreset()")

		# Set initial color
		updateQMLColor()

		oLayout = new qVBoxLayout() {
			AddWidget(oQuick)
		}

		setLayout(oLayout)
		show()
	}

	exec()
}

# --- Slider change handlers ---

func onRedChanged

	nRed = getSliderValue()
	updateQMLColor()

func onGreenChanged

	nGreen = getSliderValue()
	updateQMLColor()

func onBlueChanged

	nBlue = getSliderValue()
	updateQMLColor()

# --- Preset color handler ---

func onPreset

	# Read hex color from QML statusMsg
	oRoot = oQuick.rootObject()
	oProp = new QQmlProperty(oRoot, "statusMsg")
	cHex = oProp.read().toString()

	# Parse hex color to RGB - e.g. "#e74c3c"
	if left(cHex, 1) = "#" and len(cHex) = 7
		cR = substr(cHex, 2, 2)
		cG = substr(cHex, 4, 2)
		cB = substr(cHex, 6, 2)
		nRed = hex2dec(cR)
		nGreen = hex2dec(cG)
		nBlue = hex2dec(cB)
		updateQMLColor()
	ok

# --- Helper functions ---

func getSliderValue

	oRoot = oQuick.rootObject()
	oProp = new QQmlProperty(oRoot, "statusMsg")
	return 0 + oProp.read().toString()

func updateQMLColor

	cHex = rgb2hex(nRed, nGreen, nBlue)
	callQML("updateColor('" + cHex + "', " +
		nRed + ", " + nGreen + ", " + nBlue + ")")
	callQML("updateStatus('Color: " + cHex +
		"  RGB(" + nRed + ", " + nGreen + ", " + nBlue + ")')")

func rgb2hex nR, nG, nB

	return "#" + dec2hex2(nR) + dec2hex2(nG) + dec2hex2(nB)

func dec2hex2 n

	cHex = ""
	cChars = "0123456789abcdef"
	if n = 0 return "00" ok
	while n > 0
		nRem = n % 16
		cHex = substr(cChars, nRem + 1, 1) + cHex
		n = floor(n / 16)
	end
	if len(cHex) = 1
		cHex = "0" + cHex
	ok
	return cHex

func hex2dec cHex

	cHex = upper(trim(cHex))
	nResult = 0
	for x = 1 to len(cHex)
		c = cHex[x]
		nResult = nResult * 16
		switch c
			on "0" nResult += 0
			on "1" nResult += 1
			on "2" nResult += 2
			on "3" nResult += 3
			on "4" nResult += 4
			on "5" nResult += 5
			on "6" nResult += 6
			on "7" nResult += 7
			on "8" nResult += 8
			on "9" nResult += 9
			on "A" nResult += 10
			on "B" nResult += 11
			on "C" nResult += 12
			on "D" nResult += 13
			on "E" nResult += 14
			on "F" nResult += 15
		off
	next
	return nResult

func callQML cExpr

	oRoot = oQuick.rootObject()
	oCtx = oQuick.rootContext()
	oExpr = new QQmlExpression(oCtx, oRoot, cExpr)
	return oExpr.evaluate()