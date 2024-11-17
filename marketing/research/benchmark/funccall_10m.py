import time

# Define the test function
def test():
    return 0

# Start the clock
t1 = time.time()

# Run the loop and call the test function
for t in range(1, 10_000_001):
    test()

# Stop the clock
t2 = time.time()

# Print the elapsed time
print(t2 - t1)
