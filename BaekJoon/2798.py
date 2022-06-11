# 블랙잭

N, M = map(int, input().split())
card = list(map(int, input().split()))
ans = 0

for i in range(0, N-2):
    for j in range(i+1, N-1):
        for k in range(j+1, N):
            n = card[i] + card[j] + card[k]
            if n > ans and n <= M:
                ans = n
print(ans)
