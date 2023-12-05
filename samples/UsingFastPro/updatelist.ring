load "fastpro.ring"

aList = [ [1,2,3],
          [4,5,6],
          7:9 ]

# Set the values of the first row to 10
        updateList(aList,:set,:row,1,10)
# Add 10 to each value in the first row
        updateList(aList,:add,:row,1,10)
# Sub 5 from each value in the first row
        updateList(aList,:sub,:row,1,5)
# Multiply each value in the first row by 10
        updateList(aList,:mul,:row,1,10)
# Divide each value in the first row by 2
        updateList(aList,:div,:row,1,2)
# Copy the first row values to the second row
        updateList(aList,:copy,:row,1,2)
# Sum the third row and the second row
# And the result will be in the third row
        updateList(aList,:merge,:row,3,2)

? aList