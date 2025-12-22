import heapq

t = int(input())
while t:
    n, k = map(int, input().split())
    cas = []
    for _ in range(n):
        l, r, real = map(int, input().split())
        cas.append((l, r, real))

    cas.sort()

    i = 0
    curr = k
    heap = []
    while True:
        while i < n and cas[i][0] <= curr:
            l, r, real = cas[i]
            if r >= curr:
                heapq.heappush(heap, (-real, l, r, real))
            i += 1

        while heap:
            neg_real, l, r, real = heapq.heappop(heap)
            if l <= curr <= r:
                curr = real
                break
        else:
            break

    print(curr)
    t-=1
