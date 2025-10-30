def sieve(limit):
    is_prime = [True] * (limit + 1)
    is_prime[0] = is_prime[1] = False
    for i in range(2, int(limit**0.5) + 1):
        if is_prime[i]:
            for j in range(i*i, limit+1, i):
                is_prime[j] = False
    return is_prime

#Precompute primes up to 1 million
limit = 10**6
is_prime = sieve(limit)

def isPrime(n):
    if n < 2:
        return False
    if n <= limit:
        return is_prime[n]
#fallback for rare large values
    for i in range(2, int(n**0.5)+1):
        if n % i == 0:
            return False
    return True

max_primes = 0
product = 0

b_values = [b for b in range(2, 1000) if is_prime[b]]  # b must be prime

for a in range(-999, 1000, 2):  # odd a values
    for b in b_values:
        n = 0
        while True:
            val = n**2 + a*n + b
            if val < 2 or not isPrime(val):
                break
            n += 1
        if n > max_primes:
            max_primes = n
            product = a * b

print(max_primes, product)
