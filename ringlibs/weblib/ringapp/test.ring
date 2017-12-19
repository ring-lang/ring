#!ring -cgi

Load "weblib.ring"

webpage() {
  text("hello world")
  for x = 1 to 10
  button {
    text(string(x))
    onclick = "alert(''"+x+"'')"
  }
  next
}
