from typing import *
from collections import *
from heapq import *
from bisect import *
from itertools import *
from math import *
from functools import *

class Solution:
    def findDegrees(self, matrix: list[list[int]]) -> list[int]:
        n = len(matrix)
        ans = [0] * n
        
        for i in range(n):
            ans[i] = sum(matrix[i])
        
        return ans

s = Solution()
# m = [[0,1,1],[1,0,1],[1,1,0]]
m = [[0,1,0],[1,0,0],[0,0,0]]
print(s.findDegrees(m))