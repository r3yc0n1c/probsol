from typing import *
from collections import *
from heapq import *
from bisect import *
from itertools import *
from math import *
from functools import *


class Solution:
    def longestSubsequence(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 0: 
            return 0
        x = 0
        all_zero = True
        for n in nums:
            x ^= n
            if n != 0:
                all_zero = False
        if x != 0:
            return len(nums)
        elif all_zero or len(nums) == 1:
            return 0
        else:
            return len(nums) - 1

nums = [1,2,3]
print(Solution().longestSubsequence(nums))