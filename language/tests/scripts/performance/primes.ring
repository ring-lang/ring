# Posted by Clement in Ring Group

// Measures how long it takes to compute the total count of primes under LIMIT
// Output: Found 78498 primes under 1000000 in x.xx seconds

func main() {

    LIMIT = 1_000_000

    start_time = clock()
    prime_count = count_primes(LIMIT)
    end_time = (clock() - start_time) / 1000

    print("Found #{prime_count} primes under #{LIMIT} in #{end_time} seconds.")

}

func is_prime(n) {
    if n < 2 
        return false; ok
    if n = 2
        return true; ok
    if n % 2 = 0
        return false; ok
    
    nMax = floor(sqrt(n))
    for i = 3 to nMax step 2 {
        if n % i = 0
            return false
        ok
    }
    return true
}

func count_primes(limit) {
    count = 0
    nMax  = limit - 1
    for i = 2 to nMax {
        if is_prime(i)
            count++
        ok
    }
    return count
}