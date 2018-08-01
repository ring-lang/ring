# The Ring Notepad Application (RNote)
# Author : Mahmoud Fayed <msfclipper@yahoo.com>

# Load Standard Libraries
	load "guilib.ring"
	load "stdlib.ring"

# Load Ring Notepad Files 
	load "rnotebase.ring"
	load "rnotecontroller.ring"
	load "rnoteview.ring"
	load "rnotemode.ring"
	load "rnotestyle.ring"
	load "rnoteautocomplete.ring"
	load "rnotelists.ring"
	load "rnotefind.ring"
	load "rnotegoto.ring"
	load "rnotesettings.ring"
	load "rnotefindinfiles.ring"
	load "rnotehelp.ring"

# Merge Classes 
	mergemethods(:RNoteController,:RNoteView)
	mergemethods(:RNoteController,:RNoteMode)
	mergemethods(:RNoteController,:RNoteStyle)
	mergemethods(:RNoteController,:RNoteAutoComplete)	
	mergemethods(:RNoteController,:RNoteLists)
	mergemethods(:RNoteController,:RNoteFind)
	mergemethods(:RNoteController,:RNoteGoto)
	mergemethods(:RNoteController,:RNoteSettings)
	mergemethods(:RNoteController,:RNoteFindInFiles)
	mergemethods(:RNoteController,:RNoteHelp)

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
