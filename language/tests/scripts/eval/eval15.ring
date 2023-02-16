code = [
	"? 'Hello, World!'",
	"for t=1 to 10 ? t if t=3 ? :three ok next",
	"class point x y z",
	"new point { x=10 y=20 z=30 ? self} ",
	"new point { x=10 y=20 z=30 ? self  ",
	"? 'After syntax error'",
	"for t=1 to 10 ? t if t=3 ? :three ok next",
	"new point { x=10 y=20 z=30 ? self} ",
	"new point { x=10 y=20 z=30 ? self} ",
	"new point { x=10 y=20 z=30 ? self} ",
	"new point { x=10 y=20 z=30 ? self} ",
	"func test ? 'Hello from test'",
	"test() test() test() test()",
	"test",
	"? 'After error'",
	"test()",
	"new point { x=1000 y=2000 z=3000 ? self} ",
	"? :done"
]
for command in Code
	try
		eval(command)
	catch
		? cCatchError
	done
next