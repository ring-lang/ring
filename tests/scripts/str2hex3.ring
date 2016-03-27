cString = read("tests\mahmoud.jpg")
c = str2hex(cString)
see "size : " +len(c) + nl
r = hex2str(c)
see "size : " +len(r) + nl

if r = cString
	see "True" + nl
else
	See "false" + nl
ok

write("tests\good.jpg",r)


v = str2hex("mahmoud samir fayed")
see v + nl
r = hex2str(v)
see r + nl

a = char(150) 
see "asci:" see asci(a) see nl
see "Size:"+ len(a) + nl
see "letter:" see a see nl
v = str2hex(a)
see "hex:" see v see nl
see "asci:" see asci(a) see nl
see "letter:" see a see nl
see "hex:" see hex(asci(a)) see nl
see "dec:" see dec(hex(asci(a))) see nl
see "letter:" see char(dec(hex(asci(a)))) see nl

r = hex2str(v)
see r + nl
see asci(r) + nl