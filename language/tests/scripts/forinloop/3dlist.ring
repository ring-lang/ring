# Author: Ilir Liburn

# Create a new empty 1D list (dimension 1)
list_1d = list(2)

# Add sublists (dimension 2) to the list_1d using a for loop
for i in 1:2 {
    # Create a new empty 2D list (dimension 2) and add it to the list_1d
    list_2d = list(3)
    # Add sublists (dimension 3) to the list_2d using a nested for loop
    for j in 1:3 {
        # Create a new empty 3D list (dimension 3) and add it to the list_2d
        list_3d = list(4)
        # Fill the list_3d with elements using another nested for loop
        for k in 1:4

            # Calculate the element value based on indices i, j, and k
            element = (i - 1) * 24 + (j - 1) * 8 + k
            ? element
            # Add the element to the list_3d
            list_3d[k] = element
        next
        list_2d[j] = list_3d
    }
    list_1d[i] = list_2d
}

# Print out all elements within the list_1d using nested for...in loops
? len(list_1d)
for x in list_1d {
    for y in x {
	for z in y {
            see "Element: " + z + nl
        }
    }
}
