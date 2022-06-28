# 가운데룰 말해요
# 최소힙 사용

import heapq
import sys

N = int(sys.stdin.readline())
heap1 = [] # 최대힙
heap2 = [] # 최소힙

for i in range(0, N):
    num = int(sys.stdin.readline())
    if len(heap1) == len(heap2):
        heapq.heappush(heap1, -num)
    else:
        heapq.heappush(heap2, num)
    if heap2 and (-heap1[0] > heap2[0]):
        l = heapq.heappop(heap1)
        r = heapq.heappop(heap2)
        heapq.heappush(heap1, -r)
        heapq.heappush(heap2, -l)
    print(-heap1[0])
