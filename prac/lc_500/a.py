from typing import *
from collections import *
from heapq import *
from bisect import *
from itertools import *
from math import *
from functools import *

class Solution:
    def countOppositeParity(self, nums: list[int]) -> list[int]:
        n = len(nums)
        ans = []
        for i in range(n):
            score = 0
            for j in range(i+1, n):
                par_i = nums[i] & 1
                par_j = nums[j] & 1
                if par_i != par_j:
                    score += 1
            ans.append(score)
        return ans

s = Solution()
nums = [1,2,3,4]
# nums = [1]
# nums = [5,1]
print(s.countOppositeParity(nums))