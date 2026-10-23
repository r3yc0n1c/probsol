import heapq
from typing import *
from collections import *
from heapq import *
from bisect import *
from itertools import *
from math import *
from functools import *
from bisect import bisect_right

class Solution:
    def minCost(self, n: int, prices: List[int], roads: List[List[int]]) -> List:
        g1 = [[] for _ in range(n)]
        g2 = [[] for _ in range(n)]

        for u, v, c, t in roads:
            g1[u].append((v, c))
            g1[v].append((u, c))

            g2[u].append((v, c * t))
            g2[v].append((u, c * t))

        def dijkstra(src, graph):
            dist = [10**18] * n
            dist[src] = 0

            pq = [(0, src)]

            while pq:
                d, u = heapq.heappop(pq)

                if d > dist[u]:
                    continue

                for v, w in graph[u]:
                    nd = d + w

                    if nd < dist[v]:
                        dist[v] = nd
                        heapq.heappush(pq, (nd, v))

            return dist

        go = [dijkstra(i, g1) for i in range(n)]
        back = [dijkstra(i, g2) for i in range(n)]
        ans = prices[:]

        for i in range(n):
            for j in range(n):
                ans[i] = min(
                    ans[i],
                    go[i][j] + back[j][i] + prices[j]
                )

        return ans

s = Solution()
# nums = [0,2,1]
nums = [3,1,2]      # 2
# nums = [1,0,1,2]    # 3
# nums = [2,0,0]      # 1
# nums = [1,2,2]      # 1


print(s.maxFixedPoints(nums))