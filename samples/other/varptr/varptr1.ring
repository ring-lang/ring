# Create new variable as Number
	r = 10
# Print the variable 
	? r + nl
# Create a pointer to the variable 
	p1= varptr("r","int")
# Print the Pointer List
	? p1
# Change the Pointer Type (Like a Cast)
	p1[2] = "GLuint"
# Print the Pointer List
	? p1

