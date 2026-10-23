from typing import *
from collections import *
from heapq import *
from bisect import *
from itertools import *
from math import *
from functools import *

class Solution:
    def firstStableIndex(self, nums: list[int], k: int) -> int:
        n = len(nums)
        for i in range(n):
            in_score = max(nums[0:i+1]) - min(nums[i:n])
            if in_score <= k:
                return i
        return -1

s = Solution()
# nums = [5,0,1,4]
nums = [3,2,1]
k = 1
print(s.firstStableIndex(nums, k))