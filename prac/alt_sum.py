from typing import *
from collections import *
from heapq import *
from bisect import *
from itertools import *
from math import *
from functools import *

class Solution:
    def alternatingSum(self, nums: List[int]) -> int:
        alt_sum = 0
        for i, x in enumerate(nums):
            if i &  1:
                alt_sum -= x
            else:
                alt_sum += x
        return alt_sum
    
nums = [1,3,5,7]
print(Solution().alternatingSum(nums))