import time

# Define the size
size = 100_000

# Create a list with the specified size
aList = [0] * size

# Start the clock
t1 = time.time()

# Fill the list
for t in range(0, size):
    aList[t] = t

# Stop the clock
t2 = time.time()

# Print the elapsed time
print(t2 - t1)
