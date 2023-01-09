# Author: Ilir Liburn

y = new Temp
referer(y)

y { t = :t } # We expect error here!

z = ref(y)
referer(z)

func referer x
	? refcount(x)
	? type(x)
	? x
	x = 0	# Destroy the object from a function

class Temp
	t