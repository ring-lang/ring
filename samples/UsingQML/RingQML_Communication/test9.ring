/*
	RingQt Sample: Chat Interface with Ring <--> QML Communication
	Demonstrates:
		- QML provides modern chat bubble UI
		- User types message, QML sends text to Ring
		- Ring processes the message and generates a reply
		- Ring pushes both user message and reply to QML
		- Supports commands: /help /time /date /clear /about /calc
		- Dynamic scrollable list with styled message bubbles
*/

load "guilib.ring"
load "lib/ringcode.ring"

cUserName = "You"
cBotName = "RingBot"

new qApp {

	w = new qWidget() {

		setWindowTitle("Ring/QML Chat")
		resize(650, 600)
		move(100, 100)

		oQuick = new qQuickWidget(w) {
			engine().AddImportPath(exefolder() + "qml")
		}

		# Ring --> QML: Set title
		oContext = oQuick.rootContext()
		oContext.setContextProperty("appTitle",
			new QVariantString("Ring Chat"))

		# Load QML
		oQuick {
			setSource(AppURL("qml/chat.qml"))
			setResizeMode(1)
		}

		# QML --> Ring: Send message
		new RingCode(oQuick, "btnSend", "onSendMessage()")

		# Welcome message
		addBotMessage("Hello! I am RingBot, powered by Ring + QML.")
		addBotMessage("Type /help to see what I can do!")

		oLayout = new qVBoxLayout() {
			AddWidget(oQuick)
		}

		setLayout(oLayout)
		show()
	}

	exec()
}

# --- Handle incoming message from QML ---

func onSendMessage

	# Read the message from QML
	oRoot = oQuick.rootObject()
	oProp = new QQmlProperty(oRoot, "statusMsg")
	cMsg = oProp.read().toString()

	if trim(cMsg) = "" return ok

	# Clear input
	callQML("clearInput()")

	# Add user message to chat
	addUserMessage(cMsg)

	# Process and reply
	cReply = processMessage(cMsg)
	addBotMessage(cReply)

# --- Message processing ---

func processMessage cMsg

	cMsg = trim(cMsg)
	cLower = lower(cMsg)

	# Commands
	if left(cLower, 1) = "/"
		return processCommand(cLower)
	ok

	# Greetings
	if cLower = "hi" or cLower = "hello" or cLower = "hey"
		aGreetings = [
			"Hey there! How can I help you?",
			"Hello! Nice to chat with you!",
			"Hi! What would you like to talk about?",
			"Hey! Ready to help!"
		]
		return aGreetings[random(len(aGreetings) - 1) + 1]
	ok

	# Questions
	if right(cMsg, 1) = "?"
		aReplies = [
			"That is a great question! Let me think...",
			"Interesting question! I would say it depends.",
			"Good question! What do you think?",
			"Hmm, I am not sure. Try asking in a different way!"
		]
		return aReplies[random(len(aReplies) - 1) + 1]
	ok

	# Thank you
	if substr(cLower, "thank") or substr(cLower, "thanks")
		return "You are welcome! Happy to help!"
	ok

	# Bye
	if cLower = "bye" or cLower = "goodbye" or substr(cLower, "see you")
		return "Goodbye! Have a great day!"
	ok

	# Ring language
	if substr(cLower, "ring")
		return "Ring is an amazing programming language! " +
			"You are using Ring " + version() + " right now."
	ok

	# Default - echo with fun response
	aDefault = [
		"You said: " + cMsg + " - Tell me more!",
		"Interesting! " + cMsg + " - I like that.",
		"I hear you! Anything else on your mind?",
		"Got it: " + cMsg + " - What else?",
		"Nice! Let us keep chatting!"
	]
	return aDefault[random(len(aDefault) - 1) + 1]

# --- Commands ---

func processCommand cCmd

	if cCmd = "/help"
		return "Available commands:" + char(10) +
			"/help - Show this help" + char(10) +
			"/time - Show current time" + char(10) +
			"/date - Show current date" + char(10) +
			"/about - About RingBot" + char(10) +
			"/calc 2+3 - Simple calculator" + char(10) +
			"/upper text - Convert to uppercase" + char(10) +
			"/lower TEXT - Convert to lowercase" + char(10) +
			"/reverse text - Reverse a string" + char(10) +
			"/len text - Count characters" + char(10) +
			"/clear - Clear chat history"
	ok

	if cCmd = "/time"
		oTime = new QTime()
		oTime = oTime.currentTime()
		nH = oTime.hour()
		nM = oTime.minute()
		nS = oTime.second()
		if nH < 10  cH = "0" + nH  else  cH = "" + nH  ok
		if nM < 10  cM = "0" + nM  else  cM = "" + nM  ok
		if nS < 10  cS = "0" + nS  else  cS = "" + nS  ok
		return "Current time: " + cH + ":" + cM + ":" + cS
	ok

	if cCmd = "/date"
		return "Current date: " + date()
	ok

	if cCmd = "/about"
		return "RingBot v1.0" + char(10) +
			"Built with Ring " + version() + char(10) +
			"Using RingQt + QML" + char(10) +
			"A demo of Ring <--> QML communication"
	ok

	if cCmd = "/clear"
		callQML("clearMessages()")
		addBotMessage("Chat cleared! Fresh start.")
		return ""
	ok

	if left(cCmd, 6) = "/calc "
		cExpr = substr(cCmd, 7)
		try
			nResult = eval("return " + cExpr)
			return "" + cExpr + " = " + nResult
		catch
			return "Could not calculate that. Try: /calc 2+3"
		done
	ok

	if left(cCmd, 7) = "/upper "
		return upper(substr(cCmd, 8))
	ok

	if left(cCmd, 7) = "/lower "
		return lower(substr(cCmd, 8))
	ok

	if left(cCmd, 9) = "/reverse "
		cText = substr(cCmd, 10)
		cResult = ""
		for x = len(cText) to 1 step -1
			cResult += cText[x]
		next
		return cResult
	ok

	if left(cCmd, 5) = "/len "
		cText = substr(cCmd, 6)
		return "Length: " + len(cText) + " characters"
	ok

	return "Unknown command. Type /help to see available commands."

# --- Helper functions ---

func addUserMessage cMsg

	cMsg = escapeQuotes(cMsg)
	cTime = getTimeStr()
	callQML("addMessage('" + cUserName + "', '" + cMsg +
		"', '" + cTime + "', true)")

func addBotMessage cMsg

	if cMsg = "" return ok
	cMsg = escapeQuotes(cMsg)
	cTime = getTimeStr()
	callQML("addMessage('" + cBotName + "', '" + cMsg +
		"', '" + cTime + "', false)")

func getTimeStr

	oTime = new QTime()
	oTime = oTime.currentTime()
	nH = oTime.hour()
	nM = oTime.minute()
	if nH < 10  cH = "0" + nH  else  cH = "" + nH  ok
	if nM < 10  cM = "0" + nM  else  cM = "" + nM  ok
	return cH + ":" + cM

func escapeQuotes cText

	cText = substr(cText, "'", " ")
	cText = substr(cText, '"', " ")
	cText = substr(cText, char(10), " ")
	cText = substr(cText, char(13), " ")
	return cText

func callQML cExpr

	oRoot = oQuick.rootObject()
	oCtx = oQuick.rootContext()
	oExpr = new QQmlExpression(oCtx, oRoot, cExpr)
	return oExpr.evaluate()
