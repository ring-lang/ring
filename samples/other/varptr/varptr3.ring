# Create new variable (Numbers)
	x = 10
# Print the variables
	? x + nl
# Convert to string (Stream of bytes)
	cStr = Int2Bytes(x)
# Create a pointer to the variable 
	p1= varptr(:cStr,"GLuint")
# Print the Pointer List
	? p1

