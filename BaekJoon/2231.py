# 분해합

N = int(input())
n = N - (9 * 6)
ans = 0

for i in range(n, N):
    a = i
    j = i
    while(j > 0):
        a += j % 10
        j = int(j/10)
    if a == N:
        ans = i
        break
    else:
        continue
print(ans)
