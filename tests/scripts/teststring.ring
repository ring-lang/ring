see copy("***hello***",3) + nl # print ***hello******hello******hello***

cMsg = "     Welcome      "
see trim(cMsg) + nl			# print Welcome

see Right("Hello World!",6) + nl # print World!

see left("Hello World!",5) + nl # print Hello

# convert the first letter to UPPER case

See "Enter your name : " give cName
cName[1] = upper(cName[1])
see "Hello " + cName + nl

# print user name letter by letter (each letter in new line)

See "Hello, Enter your name : " give cName
for x in cName
        see nl + x
next

cStr = "Welcome To The Ring Programming Language"
see cStr + nl + upper(cStr) + nl + lower(cStr)