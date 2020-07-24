x = 77444
y = -12
z = 0
sList = sortList(x, y , z)
see sList + nl

x = 'lions, tigers, and'
y = 'bears, oh my!'
z = '(from the "Wizard of OZ")'
sList = sortList(x, y , z)
see sList + nl

func sortList (x, y, z)
     aList = [x, y, z]
     sList = sort(aList)
     return sList
