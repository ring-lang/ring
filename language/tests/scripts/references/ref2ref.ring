# Author: Ilir Liburn
# Updated by Fayed

cnd = 0
tmp = [:tmp]

tmp2 = test(ref(ref(tmp)))

if !cnd ? refcount(tmp) ok
if !cnd ? refcount(tmp2) ok

tmp[1] = :tmp2
tmp2 = [tmp]

if !cnd ? refcount(tmp) ok
if !cnd ? refcount(tmp2) ok

tmp2 = test(ref(ref(tmp2[1])))

if !cnd ? refcount(tmp) ok
if !cnd ? refcount(tmp2) ok


func test x
	return x