import time

def fib(n):
    if n <= 2:
        return 1
    return fib(n - 1) + fib(n - 2)

# Start the clock
t1 = time.time()

# Call the Fibonacci function
print(fib(30))

# Stop the clock
t2 = time.time()

# Print the elapsed time
print(t2 - t1)

