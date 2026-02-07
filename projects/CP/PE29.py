digit_powers = [d**5 for d in range(10)]

# Upper bound: 6 * 9^5 = 354294
UPPER_BOUND = 6 * digit_powers[9]

result = 0

for n in range(10, UPPER_BOUND + 1):
    temp = n
    power_sum = 0

    while temp > 0:
        power_sum += digit_powers[temp % 10]
        temp //= 10

    if power_sum == n:
        result += n

print(result)
