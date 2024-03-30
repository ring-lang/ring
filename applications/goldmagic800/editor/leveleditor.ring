# Gold Magic 800 3D Game - Level Editor
# 2018, Etqan Company
# 2018, Mahmoud Fayed <msfclipper@yahoo.com>

load "lightguilib.ring"
load "stdlibcore.ring"
load "editorController.ring"

import System.GUI

new App {
	StyleFusion()
	openWindow(:editorController)
	exec()
}
