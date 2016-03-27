see "Test Left()" + nl

cStr = "Welcome to my new programming language"
see left(cStr,10) + nl
if left(cStr,10) = "Welcome to"
	see "True" + nl
else
	see "False" + nl
ok
see "Size : " see len(left(cStr,10)) see nl

see "Test Right()" + nl

see right(cStr,8) + nl
if right(cStr,8) = "language"
	see "True" + nl
else
	see "False" + nl
ok
see "Size : " see len(right(cStr,8)) see nl

See "Test Trim()" + nl

cStr = "         Welcome              "
see cStr + nl
see "Size : " + len(cStr) + nl
see trim(cStr) + nl
see "Size : " + len(trim(cStr)) + nl

see "Test Copy()" + nl

cStr = "Word "
see cStr + nl
see "Size : " see len(cStr) see nl
see copy(cStr,5) + nl
see "Size : " see len(copy(cStr,5)) see nl

see "Test substr(cStr,5)" + nl
cStr = "1234567890"
see cStr + nl
see "Size : " see len(cStr) see nl
see substr(cStr,5) + nl
see "Size : " see len(substr(cStr,5)) see nl

SEE "Test substr(cStr,'456')" + nl
see substr(cStr,"456") see nl
see substr(cStr,"Mahmoud") see nl

see "Test substr(cStr,3,5)" + nl
cStr = "Welcome to my new programming language - yes new language"
see cStr + nl
see substr(cStr,3,5) + nl
see "Size : " + len(substr(cStr,3,5)) + nl

see "Test substr(cStr,'new','great')" + nl
see substr(cStr,"new","great") + nl
cStr = substr(cStr,"new","great") 
see "Test substr(cStr,'great','NeW')" + nl
see substr(cStr,"great","NeW") + nl
cStr = substr(cStr,"great","NeW") 
see substr(cStr,"new","great") + nl
see "Test substr(cStr,'new','great',True)" + nl
see substr(cStr,"new","great",True) + nl

see " A : " + asci("z") 