from typing import *
from collections import *
from heapq import *
from bisect import *
from itertools import *
from math import *
from functools import *

class Solution:
    def minCost(self, nums: list[int], queries: list[list[int]]) -> list[int]:
        n = len(nums)
        
        forward = [0] * (n-1)
        backward = [0] * n
        
        for i in range(n-1):
            left = nums[i] - nums[i-1] if i > 0 else float("inf")
            right = nums[i+1] - nums[i]
            
            if right < left:
                forward[i] = 1
            else:
                forward[i] = right
        
        for i in range(1, n):
            left = nums[i] - nums[i-1]
            right = nums[i+1] - nums[i] if i < n-1 else float("inf")
            
            if left <= right:
                backward[i] = 1
            else:
                backward[i] = left
        
        pf = [0] * n
        for i in range(n-1):
            pf[i+1] = pf[i] + forward[i]
        
        pb = [0] * n
        for i in range(1, n):
            pb[i] = pb[i-1] + backward[i]
        
        ans = []
        
        for l, r in queries:
            if l < r:
                ans.append(pf[r] - pf[l])
            else:
                ans.append(pb[l] - pb[r])
        
        return ans
    

s = Solution()
nums = [-5,-2,3]
queries = [[0,2],[2,0],[1,2]]

nums = [0,2,3,9]
queries = [[3,0],[1,2],[2,0]]

print(s.minCost(nums, queries))