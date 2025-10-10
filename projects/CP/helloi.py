def isPrime(n):
    if n < 2:
        return False
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            return False
    return True


max_primes = 0
product = 0

for a in range(-999, 1000):
    for b in range(-1000, 1001):
        n = 0
        while True:
            val = n**2 + a*n + b
            if not isPrime(val):
                break
            n += 1

        if n > max_primes:
            max_primes = n
            product = a * b

print(product)


