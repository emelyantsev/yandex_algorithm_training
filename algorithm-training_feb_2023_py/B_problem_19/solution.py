import heapq

N = int(input())

h = []

for i in range(N):

    line = list(map(int, input().split()))

    if line[0] == 0:
        val = line[1]
        heapq.heappush(h, -val)
    else:

        assert len(h) > 0
        print(-h[0])
        heapq.heappop(h)