? "Declare optional functions"
optionalFunc(:one)
optionalFunc(:two)
optionalFunc(:three)

? "Call optional functions"
one() two() three()

? "Print list of optional functions"
? RingOptionalFunctions

? "Define optional functions"
eval(`
func one   ? "Message from one() function"
func two   ? "Message from two() function"
func three ? "Message from three() function"
`)

? "Call optional functions"
one() two() three()