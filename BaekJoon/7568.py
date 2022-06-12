# 덩치

N = int(input())
l = []
ans = []
for i in range(0, N):
    l.append(list(map(int, input().split())))
for i in range(0, N):
    r = 1
    for j in range(0, N):
        if i == j:
            continue
        else:
            if l[i][0] < l[j][0] and l[i][1] < l[j][1]:
                r += 1
            else:
                continue
    ans.append(r)
for i in ans:
    print(i, end=" ")
