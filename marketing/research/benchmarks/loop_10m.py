import time

# Start the clock
t1 = time.time()

# Run the loop
for t in range(1, 10_000_001):
    pass

# Stop the clock
t2 = time.time()

# Print the elapsed time
print("Time: " + str(t2 - t1))
