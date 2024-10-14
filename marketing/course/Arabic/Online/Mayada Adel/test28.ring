# ------------ Handling Errors ------------
# Style 1
try
	1 / 0
catch 	
	? "error"
done
? "......"
# Style 2
try
	1 / 0
catch 	
	? "error"
end
? "......"
# Style 3
try {
	1 / 0
catch 	
	? "error"
}
? "......"
