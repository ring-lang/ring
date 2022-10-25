# Create the list 
mylist = 1:5

# Create pointer to the list
x = object2pointer(mylist)

# Add items to the list
mylist + "welcome"

# print the list items
y = pointer2object(x)

? y