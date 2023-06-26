# The Ring Notepad Application (RNote)
# Author : Mahmoud Fayed <msfclipper@yahoo.com>

# Load Ring Notepad Files 
	load "rnotebase.ring"
	load "rnotecontroller.ring"
	load "rnotemainwindow.ring"
	load "rnotefilestabs.ring"
	load "rnotemode.ring"
	load "rnotestyle.ring"
	load "rnoteautocomplete.ring"
	load "rnotelists.ring"
	load "rnotefind.ring"
	load "rnotegoto.ring"
	load "rnotetabwidth.ring"
	load "rnotesettings.ring"
	load "rnoteactivefolder.ring"
	load "rnoteactivefile.ring"
	load "rnotefindinfiles.ring"
	load "rnotewebbrowser.ring"
	load "rnotefilemenu.ring"
	load "rnoteeditmenu.ring"
	load "rnoteviewmenu.ring"
	load "rnoteprogrammenu.ring"
	load "rnotetools.ring"
	load "rnotedistribute.ring"
	load "rnotehelp.ring"
	load "rnotemainfiletoolbar.ring"
	load "rnoteoutputwindow.ring"
	load "rnoteformdesigner.ring"
	load "rnotetreeviewevents.ring"
	load "rnoteeditorevents.ring"
	load "rnoterun.ring"
	load "rnoteinserttext.ring"
	load "rnoteselectfile.ring"

# Merge Classes 
	for cClass in [
		:RNoteMainWindow,
		:RNoteFilesTabs,
		:RNoteMode,
		:RNoteStyle,
		:RNoteAutoComplete,
		:RNoteLists,
		:RNoteFind,
		:RNoteGoto,
		:RNoteTabWidth,
		:RNoteSettings,
		:RNoteActiveFolder,
		:RNoteActiveFile,
		:RNoteFindInFiles,
		:RNoteWebBrowser,
		:RNoteFileMenu,
		:RNoteEditMenu,
		:RNoteViewMenu,
		:RNoteProgramMenu,
		:RNoteTools,
		:RNoteDistribute,
		:RNoteHelp,
		:RNoteMainFileToolbar,
		:RNoteOutputWindow,
		:RNoteFormDesigner,
		:RNoteTreeViewEvents,
		:RNoteEditorEvents,
		:RNoteRun,
		:RNoteInsertText,
		:RNoteSelectFile
	]
			mergemethods(:RNoteController,cClass)
	next
