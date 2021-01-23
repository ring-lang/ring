name = "Test"
call name()

name = "test"
call name()

name = "test2"
call name()

name = :test3
call name()

name = :mysum
call name(3,4)

func test ? "hello from test"

func test2 ? "hello from test2"

func test3 ? "hello from test3"

func mysum x,y ? x+y
