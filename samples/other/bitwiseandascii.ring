s = list(2)
s[1]= ASCII('x') 
s[2]= ASCII('y')
? "s1,s2 " + s[1] + "," + s[2]
s[1]  ^= ASCII('a')
s[2]  ^= ASCII('b')
? "s1,s2 " + s[1] + "," + s[2]
