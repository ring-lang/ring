# Application  : Qt Class Converter
# Author       : Majdi Sobain <MajdiSobain@gmail.com>

load "app\QtClassConverterController.ring"

import System.GUI

new App {
	StyleFusion()
	open_window(:QtClassConverterController)
	Last_window().PrepareMainWindow()
	exec()
}
