from typing import *
from collections import *
from heapq import *
from bisect import *
from itertools import *
from math import *
from functools import *
from bisect import bisect_right

class Solution:
    # def maxFixedPoints(self, nums: list[int]) -> int:
    #     n = len(nums)

    #     dp = [inf] * (n+1)
    #     dp[0] = -inf

    #     max_fixed = 0

    #     for i, x in enumerate(nums):
    #         if x <= i:
    #             del_b4 = i-x

    #             s = bisect_right(dp, del_b4)
    #             if s <= n:
    #                 dp[s] = min(dp[s], del_b4)
    #                 max_fixed = max(max_fixed, s)

    #     return max_fixed

    def maxFixedPoints(self, nums: list[int]) -> int:
        pairs = []
        for i, val in enumerate(nums):
            if val <= i:
                pairs.append((val, i - val))
        
       
        pairs.sort(key=lambda x: (x[0], -x[1]))
        
        dp = []
        
        for _, slack in pairs:
            idx = bisect_right(dp, slack)
            
            if idx == len(dp):
                dp.append(slack)
            else:
                dp[idx] = slack
                
        return len(dp)

s = Solution()
# nums = [0,2,1]
nums = [3,1,2]      # 2
# nums = [1,0,1,2]    # 3
# nums = [2,0,0]      # 1
# nums = [1,2,2]      # 1


print(s.maxFixedPoints(nums))