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
		nRed = dec(cR)
		nGreen = dec(cG)
		nBlue = dec(cB)
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

	cHex = lower(hex(n))
	if len(cHex) = 1
		cHex = "0" + cHex
	ok
	return cHex

func callQML cExpr

	oRoot = oQuick.rootObject()
	oCtx = oQuick.rootContext()
	oExpr = new QQmlExpression(oCtx, oRoot, cExpr)
	return oExpr.evaluate()
