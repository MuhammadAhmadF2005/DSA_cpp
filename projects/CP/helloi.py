def cycle_length(n):
    remainders = {}
    remainder = 1 % n
    position = 0

    while remainder != 0 and remainder not in remainders:
        remainders[remainder] = position
        remainder = (remainder * 10) % n
        position += 1

    if remainder == 0:
        return 0  # terminates, no cycle
    else:
        return position - remainders[remainder]

max_len = 0
max_d = 1
for d in range(2, 1000):
    val = cycle_length(d)
    if val > max_len:
        max_len = val
        max_d = d

print(max_d)
