/*
++  Application : strings_null
++  Author      : mhmd elabsawy

*/
##===============================================================##

c1 = ''
c2 = ""
c3 = null
c4 = ``
#c5 = :      ### gives syntax error
C6 = 'null' ### lower case null inside "" is not null
c7 = 'NULL'
? isnull(c1)
? isnull(c2)
? isnull(c3)
? isnull(c4)
? isnull(c6)
? isnull(c7)
