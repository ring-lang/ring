# The Ring Natural Library
# 2017, Mahmoud Fayed <msfclipper@yahoo.com>

load "mylanguage.ring"

MyLanguage {
	SetOperators("()")
	RunString("
	Here we will play and will try something
	that looks like Lisp Syntax
	(count  (count 1 5)  (count 20 15))
	Just for fun!
	")
}
