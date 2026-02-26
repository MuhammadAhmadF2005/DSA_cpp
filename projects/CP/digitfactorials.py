import math


def digitfactorials():
    total_sum = 0
    f = [math.factorial(i) for i in range(10)]
    
    for i in range(10, 2540161):
        # Calculate sum of factorials of digits
        digit_sum = sum(f[int(d)] for d in str(i))
        
        if digit_sum == i:
            total_sum += i
            
    return total_sum

print(digitfactorials())