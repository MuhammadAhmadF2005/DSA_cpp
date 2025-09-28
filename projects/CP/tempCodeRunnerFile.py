def sum_proper_divisors(n: int) -> int:
    """Return sum of proper divisors of n (excluding n itself)."""
    if n <= 1:
        return 0
    
    total = 1
    sqrt_n = int(n**0.5)
    
    for i in range(2, sqrt_n + 1):
        if n % i == 0:
            total += i
            if i != n // i:  # avoid double-counting squares
                total += n // i
    
    return total


def generate_abundant_numbers(limit: int = 28123):
    """Generate all abundant numbers up to a given limit."""
    return [n for n in range(12, limit + 1) if sum_proper_divisors(n) > n]


def non_abundant_sum(limit: int = 28123):
    abundants = generate_abundant_numbers(limit)
    can_be_written = [False] * (limit + 1)

    # Mark all numbers that can be written as sum of 2 abundant numbers
    for i in range(len(abundants)):
        for j in range(i, len(abundants)):
            s = abundants[i] + abundants[j]
            if s <= limit:
                can_be_written[s] = True
            else:
                break

    # Sum numbers that cannot be written as such sums
    ans = sum(i for i in range(1, limit + 1) if not can_be_written[i])
    return ans


# Run
print("Answer:", non_abundant_sum())
