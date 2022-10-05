? "One"
if []
	? "NOT NULL"
ok

? "Two"
if ! []
	? "What"
ok

? "Three"

if NULL = []
	? "What!"
ok

? "Four"

if NULL != []
	? "Great!"
ok

? "Done"