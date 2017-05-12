# Form/Window Controller - Source Code File

load "texteditView.ring"

if IsMainSourceFile() {
	new qApp {
		StyleFusion()
		open_window(:texteditController)
		exec()
	}
}

class texteditController from windowsControllerParent

	oView = new texteditView
