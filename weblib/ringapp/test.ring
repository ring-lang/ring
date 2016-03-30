#!b:\ring\bin\ring.exe -cgi
Load "weblib.ring"

func main
webpage() {
  text("hello world")

  for x = 1 to 10
  button {
    texT(string(x))
    onclick = "alert('"+x+"')"
  }
  next
}
