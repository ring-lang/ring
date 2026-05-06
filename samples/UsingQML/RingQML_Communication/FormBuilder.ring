/*
	RingQt Sample: Form Builder with Ring <--> QML Communication
	Demonstrates:
		- Ring defines form fields (text, dropdown, checkbox, textarea)
		- Ring pushes field definitions to QML via QQmlExpression
		- QML dynamically creates UI components using Qt.createQmlObject()
		- User fills the form in QML
		- On Submit, QML collects all values and Ring reads them back
		- Ring processes and displays the submitted data
*/

load "guilib.ring"
load "lib/easyqml.ring"

new qApp {

	w = new qWidget() {

		setWindowTitle("Ring/QML Form Builder")
		resize(650, 620)
		move(100, 100)

		oQuick = new qQuickWidget(w) {
			engine().AddImportPath(exefolder() + "qml")
		}

		# Ring --> QML: Set title and subtitle
		oContext = oQuick.rootContext()
		oContext.setContextProperty("appTitle",
			new QVariantString("Ring Form Builder"))
		oContext.setContextProperty("appSubtitle",
			new QVariantString("Form defined in Ring, rendered in QML"))

		# Load QML
		oQuick {
			setSource(AppURL("qml/formbuilder.qml"))
			setResizeMode(1)
		}

		# QML --> Ring: Submit and Clear actions
		new RingCode(oQuick, "btnSubmit", "onSubmit()")
		new RingCode(oQuick, "btnClear", "onClear()")

		# Build the form from Ring
		buildForm()

		oLayout = new qVBoxLayout() {
			AddWidget(oQuick)
		}

		setLayout(oLayout)
		show()
	}

	exec()
}

# --- Ring defines the form structure ---

func buildForm

	callQML("clearForm()")

	# Personal Information section
	callQML("addSeparator('Personal Information')")
	callQML("addTextField('name', 'Full Name', 'Enter your name')")
	callQML("addTextField('email', 'Email Address', 'user@example.com')")
	callQML("addTextField('phone', 'Phone Number', '+1234567890')")

	# Preferences section
	callQML("addSeparator('Preferences')")
	callQML("addDropdown('language', 'Preferred Language', 'English,Arabic,French,Spanish,German')")
	callQML("addDropdown('theme', 'Theme', 'Dark,Light,Auto')")

	# Options section
	callQML("addSeparator('Options')")
	callQML("addCheckbox('newsletter', 'Subscribe to newsletter')")
	callQML("addCheckbox('notifications', 'Enable notifications')")
	callQML("addCheckbox('terms', 'I agree to the terms and conditions')")

	# Additional section
	callQML("addSeparator('Additional')")
	callQML("addTextArea('comments', 'Comments', 'Write your comments here...')")

	callQML("updateStatus('Form ready - fill in the fields and click Submit')")

# --- Handle form submission ---

func onSubmit

	# Read collected form data from QML
	oRoot = oQuick.rootObject()
	oProp = new QQmlProperty(oRoot, "formData")
	cData = oProp.read().toString()

	if cData = ""
		callQML("updateStatus('Please fill in the form')")
		return
	ok

	# Parse the form data (format: field1=value1|field2=value2|...)
	aFields = str2list(substr(cData, "|", nl))

	# Build a summary
	cSummary = "Form Submitted! "
	nFilled = 0

	for cField in aFields
		nPos = substr(cField, "=")
		if nPos > 0
			cName = left(cField, nPos - 1)
			cValue = substr(cField, nPos + 1)
			if cValue != "" and cValue != "false"
				nFilled++
			ok
		ok
	next

	cSummary += "(" + nFilled + " fields filled)"

	# Show results in a message box
	showResults(aFields)

	callQML("updateStatus('" + cSummary + "')")

func showResults aFields

	cMsg = "Form Results:" + nl + nl

	for cField in aFields
		nPos = substr(cField, "=")
		if nPos > 0
			cName = left(cField, nPos - 1)
			cValue = substr(cField, nPos + 1)

			# Format field name nicely
			switch cName
				on "name"          cLabel = "Full Name"
				on "email"         cLabel = "Email"
				on "phone"         cLabel = "Phone"
				on "language"      cLabel = "Language"
				on "theme"         cLabel = "Theme"
				on "newsletter"    cLabel = "Newsletter"
				on "notifications" cLabel = "Notifications"
				on "terms"         cLabel = "Terms Agreed"
				on "comments"      cLabel = "Comments"
				other              cLabel = cName
			off

			# Format value
			if cValue = "true"
				cValue = "Yes"
			but cValue = "false"
				cValue = "No"
			but cValue = ""
				cValue = "(empty)"
			ok

			cMsg += cLabel + ": " + cValue + nl
		ok
	next

	new QMessageBox(w) {
		setWindowTitle("Form Results")
		setText(cMsg)
		show()
	}

# --- Handle form clear ---

func onClear

	callQML("resetForm()")
	callQML("updateStatus('Form cleared')")

# --- Helper ---

func callQML cExpr

	oRoot = oQuick.rootObject()
	oCtx = oQuick.rootContext()
	oExpr = new QQmlExpression(oCtx, oRoot, cExpr)
	return oExpr.evaluate()
