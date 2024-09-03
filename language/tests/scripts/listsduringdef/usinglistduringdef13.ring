n1=10
n2=20
n1= mymin([n1,n2])
? n1
? "========="
n1=10
n2=20
n1= min([n1,n2])
? n1

func mymin v
	? type(v)
	? v
	? type(v[1])
	? type(v[2])
	? "***"
	return min(v)