x = "welcome"
see x + nl
# [1]  # error : variable is required

# see "welcome"[1]  # error : variable is required

mylist = ["one","two",3]
see mylist[1] + nl + mylist[2] + nl
see mylist[1][1] + nl + mylist[2][3] + nl
see mylist[3] 
see nl

# see mylist[3][1] # error : can't access the list item, object is not list

see mylist[1][1][2] # error can't access the list item, object is not a list