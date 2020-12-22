c1 = 999999999999999
for i = 1 to 13 {
	c1 *= 999999999999999
}

s = string(c1)
? "c1 = " + s
c2 = number(s)
? "c2 = " + c2

? "c2 - c1 = " + (c2 - c1)

str1 = "-2222044646462"
c = Number(str1)
str2 = String (c)

if str1 = str2 {
	? "Strings identical"

else
	? "Strings mismatch!!"
}