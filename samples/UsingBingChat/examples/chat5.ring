#================================================#
# Author: Bing Chat 
# Questions by Fayed
# Note: It's not the perfect code (It just works!)
#================================================#

# Declare an empty list to store the numbers
numbers = []

# Loop 5 times to get 5 numbers from the user
for i = 1 to 5
    # Ask the user to enter a number
    see "Enter number " + i + ": "
    # Get input from keyboard and convert it to a number
    give x
    x = number(x)
    # Add the number to the list
    add(numbers,x)
next

# Print all of the numbers in one line
see "The numbers are: "
for n in numbers
    see n + " "
next

# Print a new line character for readability
see nl

# Declare variables for minimum, maximum and average values and assign them to zero
min = max = avg = 0 

# Loop through each number in the list
for n in numbers
    # If it is smaller than min or min is zero, assign it to min 
    if n < min or min = 0 
        min = n 
    end
    
    # If it is larger than max or max is zero, assign it to max 
    if n > max or max = 0 
        max = n 
    end
    
    # Add it to avg 
    avg += n 
next

# Divide avg by 5 to get the average value 
avg /= 5 

# Print the report with minimum, maximum and average values 
see "The minimum value is: " + min + nl 
see "The maximum value is: " + max + nl 
see "The average value is: " + avg + nl 