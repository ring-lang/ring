o = new test
o.state = func {
	see "hello" + nl
}
o {
	call state()
}
class test
	state = ""
