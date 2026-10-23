from typing import *
from collections import *
from heapq import *
from bisect import *
from itertools import *
from math import *
from functools import *

class Solution:
    def concatWithReverse(self, nums: list[int]) -> list[int]:        
        return nums + nums[::-1]

s = Solution()
nums = [1,2,3]
# nums = [1]
# nums = [5,1]
print(s.concatWithReverse(nums))