see "Testing DIR() " + nl
mylist = dir(CurrentDir())
for x in mylist
        if x[2]
                see "Directory : " + x[1] + nl
        else
                see "File : " + x[1] + nl
        ok
next
see "Files count : " + len(mylist)
