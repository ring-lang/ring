#===============================================================#
# Based on sample from : https://github.com/megamarc/Tilengine  #
#===============================================================#

M_PI = 3.14159265

sintable = list(360)
costable = list(360)

func BuildSinTable
	for c=1 to 360
		sintable[c] = sin(c*M_PI/180)*256
		costable[c] = cos(c*M_PI/180)*256
	next

func CalcSin angle, factor

	if angle > 359
		angle = angle % 360
	ok

	val = sintable[angle+1]*factor >> 8

	return val

func CalcCos angle, factor

	if angle > 359
		angle = angle%360
	ok

	val = costable[angle+1]*factor >> 8

	return val
