from typing import *
from collections import *
from heapq import *
from bisect import *
from itertools import *
from math import *
from functools import *


class Solution:
    def smallestIndex(self, nums: List[int]) -> int:
        for i, n in enumerate(nums):
            s = 0
            t = n
            while t:
                d = t % 10
                s += d
                t //= 10
            if i == s:
                return i
        return -1


nums = [1,3,2]
nums = [1,10,11]
nums = [1,2,3]

s = Solution()
res = s.smallestIndex(nums)
print(res)