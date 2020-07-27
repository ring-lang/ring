# Create new variables (Numbers)
	x = 10
	y = 20
	z = 30
# Print the variables
	? x + nl + y + nl + z + nl
# Convert to string (Stream of bytes)
	cStr = Int2Bytes(x) + Int2Bytes(y) + Int2Bytes(z)
# Create a pointer to the variable 
	p1= varptr(:cStr,"int")
# Print the Pointer List
	? p1

