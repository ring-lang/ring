# The Ring Notepad Application (RNote)
# Author : Mahmoud Fayed <msfclipper@yahoo.com>

# Load Standard Libraries
	load "rnote.ring"
	load "translation/arabic.ring"
	load "../formdesigner/translation/arabic.ring"

# Open the Environment 
	if isMainSourceFile() 
		# Create the Ring Notepad Object
			Open_WindowNoShow(:RNoteController)
	ok
