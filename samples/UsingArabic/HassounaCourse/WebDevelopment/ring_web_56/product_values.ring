load "hassounapgdb.ring"
load "stdlib.ring"
load "libsdl.ring"

password ="123456"
database = "mycoffeedb_ring"
port = "5433"

file_text = Read('products.txt')
stmt_s    = split(file_text, ";")

for x in stmt_s

	if trim(x) != ""
		see run('insert into product values(' + x + ')')
		sdl_delay(3000)
	ok

next
