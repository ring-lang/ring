x=10

if x=10 ? :yes else ? :no ok
if x=11 ? :yes else ? :no ok

? is(x=10,:yes,:no)
? is(x=11,:yes,:no)

mmm(x=10, 'see "yes" + nl', 'see "no" + nl')
mmm(x=11, 'see "yes" + nl', 'see "no" + nl')

func is cond,r1,r2
	if cond return r1 ok	
	return r2

func mmm cond,c1,c2
	if cond return eval(c1) ok
	return eval(c2)