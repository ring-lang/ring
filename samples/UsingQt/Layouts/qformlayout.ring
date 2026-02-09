load "guilib.ring"

new QApp { 

	win = new QWidget() { 

		setWindowTitle("QFormLayout Demo")
		resize(500, 400)

		layout = new QFormLayout()

		txtName = new QLineEdit(win) { 
			setPlaceholderText("Enter your name...")
		}
		lblName = new QLabel(win) { setText("Name:")}
		layout.addRow(lblName, txtName)

		txtBio = new QTextEdit(win) { 
			setPlaceholderText("Write a short bio...")
			setMaximumHeight(100)
		}
		lblBio = new QLabel(win) { setText("Bio:")}
		layout.addRow(lblBio, txtBio)

		txtNotes = new QPlainTextEdit(win) { 
			setPlaceholderText("Add any notes here...")
			setMaximumHeight(100)
		}
		lblNotes = new QLabel(win) { setText("Notes:")}
		layout.addRow(lblNotes, txtNotes)

		setLayout(layout)

		show()
	}

	exec()

}
