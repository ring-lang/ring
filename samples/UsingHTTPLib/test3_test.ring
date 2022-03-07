load "internetlib.ring"

func main
	while true
		? download("localhost:8080/one")
		? download("localhost:8080/two")
	end