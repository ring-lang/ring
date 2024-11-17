import time

def Fibonacci(n):
    if n == 0:
        return 0
    if n == 1:
        return 1
    aFibRes = {0: 0, 1: 1}
    if n > 1:
        for t in range(2, n + 1):
            aFibRes[t] = aFibRes[t - 1] + aFibRes[t - 2]
        return aFibRes[n]


# Start the clock
t1 = time.time()

# Call the Fibonacci function
print(Fibonacci(500))

# Stop the clock
t2 = time.time()

# Print the elapsed time
print(t2 - t1)

