# This script is not longer needed!
# The file dbtables/db.sql already insert the products data
# We keep this file in the project as a little database example 

load "db.ring"
load "stdlib.ring"

pg_password = "sa"
pg_database = "mycoffeedb_ring"
pg_port     = "5432"

file_text = Read('products.txt')
stmt_s    = split(file_text, ";")

for x in stmt_s

	if trim(x) != ""
		see run('insert into product values(' + x + ')')
	ok

next
