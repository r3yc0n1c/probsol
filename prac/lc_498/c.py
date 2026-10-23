from typing import *
from collections import *
from heapq import *
from bisect import *
from itertools import *
from math import *
from functools import *

'''
class Solution:
    def colorGrid(self, n: int, m: int, sources: List[List[int]]) -> List[List[int]]:
        g = [[0] * m for _ in range(n)]
        t = [[float('inf')] * m for _ in range(n)]
        
        q = deque()
        
        for r, c, color in sources:
            g[r][c] = color
            t[r][c] = 0
            q.append((r, c))
        
        dirs = [(1,0), (-1,0), (0,1), (0,-1)]
        
        while q:
            r, c = q.popleft()
            
            for dr, dc in dirs:
                nr, nc = r + dr, c + dc
                if 0 <= nr < n and 0 <= nc < m:
                    
                    if t[nr][nc] > t[r][c] + 1:
                        t[nr][nc] = t[r][c] + 1
                        g[nr][nc] = g[r][c]
                        q.append((nr, nc))
                    
                    elif t[nr][nc] == t[r][c] + 1:
                        if g[nr][nc] < g[r][c]:
                            g[nr][nc] = g[r][c]
        
        return g
'''

class Solution:
    def colorGrid(self, n: int, m: int, sources: List[List[int]]) -> List[List[int]]:
        grid = [[0] * m for _ in range(n)]
        q = deque()
        
        for r, c, color in sources:
            grid[r][c] = color
            q.append((r, c))
        
        dirs = [(1,0), (-1,0), (0,1), (0,-1)]
        
        while q:
            next_updates = defaultdict(int)
            
            for _ in range(len(q)):
                r, c = q.popleft()
                
                for dr, dc in dirs:
                    nr, nc = r + dr, c + dc
                    
                    if 0 <= nr < n and 0 <= nc < m and grid[nr][nc] == 0:
                        next_updates[(nr, nc)] = max(next_updates[(nr, nc)], grid[r][c])
            
            for (r, c), color in next_updates.items():
                grid[r][c] = color
                q.append((r, c))
        
        return grid


s = Solution()

n = 3
m = 3
sources = [[0,0,1],[2,2,2]]

n = 3
m = 3
sources = [[0,1,3],[1,1,5]]

n = 2
m = 2
sources = [[1,1,5]]

res = s.colorGrid(n, m, sources)
for row in res:
    print(row)