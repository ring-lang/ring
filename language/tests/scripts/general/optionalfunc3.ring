Add(RingOptionalFunctions, [
	:one,
	:two,
	:three,
	:four,
	:five
], True)

one() two() three() four() five()	# No Error

eval(`
func one   ? 1
func two   ? 2
func three ? 3
func four  ? 4
func five  ? 5
`)

? RingOptionalFunctions			# Print Names

one() two() three() four() five()	# Print Numbers