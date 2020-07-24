load "guilib.ring"

new QApp {
	w = new QWidget() {
		setWindowTitle("Play Gif")
		resize(500,332)
		movie1 = new QMovie(w) {
			setFilename("test.gif")
		}
		new QLabel(w) {
			setMovie(movie1)
		}
		movie1.start()
		show()
	}
	exec()
}
