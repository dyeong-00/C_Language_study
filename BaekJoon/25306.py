# 연속 XOR

def xor(n):
    if n % 4 == 0:
        return n
    elif n % 4 == 1:
        return n ^ (n-1)
    elif n % 4 == 2:
        return n ^ (n-1) ^ (n-2)
    else:
        return 0


A, B = map(int, input().split())
a = xor(A-1)
b = xor(B)
print(a^b)
