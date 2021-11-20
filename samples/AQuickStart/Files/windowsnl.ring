cStr = read("input.txt")

if iswindows()
        cStr = substr(cStr,windowsnl(),nl)
ok

aList = str2list(cStr)
# to do - list items processing using "for in"
cStr = list2str(aList)

if iswindows()
        cStr = substr(cStr,nl,windowsnl())
ok

write("output.txt",cStr)
