? :here1
? eval("y=10")
? :here2
x = eval("")
? x
? type(x)
? :here3
x = eval("            ")
? x
? :here4
x = eval("func f")
? x
? :here5
x = eval("return 20")
? x
? :here6
x = eval("10 return 50")
? x
? :here7
x = eval("y=10 # return 20")
? :here8
x = eval("y=10 return 20")
? :here9
x = eval("return")
? x
? :here10
x = eval("return [1,2,3]")
? x
? :here11
x = eval("return 1:5")
? x
? :here12
x = eval("return 'good'")
? x
? :here13
x = eval("return new lang class lang name=:ring")
? x
? :here14
x = eval("10")
? x
? :here15
y = eval("return 20")
? y
? :here16
z = eval("t=2024 return 16")
? z
? t