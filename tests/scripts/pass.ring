a = new A
a.x = 1
see a.x  # 1

inc(a)     # 2
see a.x  # 2

replace(a) # 3
see a.x  # 2

see ''

b = 1     # Even integers are objects in Ruby
see b    # 1
inc_var(b) # 2
see b    # 1

func inc_var arg 
  arg = arg + 1
  see arg

func inc arg 
  arg.x = arg.x + 1
  see arg.x

func replace arg 
  arg = new A
  arg.x = 3
  see arg.x

class A
  x

