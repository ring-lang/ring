# The Ring Notepad Application (RNote)
# Author : Mahmoud Fayed <msfclipper@yahoo.com>

# Load Standard Libraries
	load "guilib.ring"
	load "stdlibcore.ring"
	load "openssllib.ring"

# Load Ring Notepad Files 
	load "rnotefiles.ring"

# Load the Form Designer 
	load "../formdesigner/formdesigner.ring"

# Load the Web Server - ServerPrepare Class
	load "../libdepwin/Apache2.2/ring/prepare.ring"

# Load the Find in files application 
	load "../findinfiles/findinfilesController.ring"

	if isMainSourceFile() 
		# Create the Ring Notepad Object
			Open_WindowNoShow(:RNoteController)
	ok
