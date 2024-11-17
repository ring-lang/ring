import time

# Start the clock
t1 = time.time()

# Run the loop and calculate the max
for t in range(1, 100_000_001):
    r = max(t, t * 2)

# Stop the clock
t2 = time.time()

# Print the elapsed time
print(t2 - t1)
