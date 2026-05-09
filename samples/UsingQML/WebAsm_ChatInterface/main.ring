/*
	RingQt Sample: Chat Interface with Ring <--> QML Communication
	Uses QQuickView instead of QQuickWidget
	Supports Desktop, Android and WebAssembly
*/

load "guilib.ring"
load "easyqml.ring"
load "functions.ring"

cUserName = "You"
cBotName = "RingBot"

new qApp {

	oQuick = new QQuickView() {
		setTitle("Ring/QML Chat")
		engine().AddImportPath(exefolder() + "qml")
		setSource(AppURL("chat.qml"))
		setResizeMode(1)
		show()
	}

	# Ring --> QML: Set title
	oContext = oQuick.rootContext()
	oContext.setContextProperty("appTitle", new QVariantString("Ring Chat"))

	# QML --> Ring: Send message
	new RingCode(oQuick, "btnSend", "onSendMessage()")

	# Welcome message
	addBotMessage("Hello! I am RingBot, powered by Ring + QML.")
	addBotMessage("Type /help to see what I can do!")

	exec()

}