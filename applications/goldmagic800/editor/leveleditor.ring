load "guilib.ring"
load "stdlib.ring"
load "editorController.ring"

import System.GUI

new App {
	StyleFusion()
	open_window(:editorController)
	exec()
}
