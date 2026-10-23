from typing import *
from collections import *
from heapq import *
from bisect import *
from itertools import *
from math import *
from functools import *

class Solution:
    def minArraySum(self, nums: list[int]) -> int:
        freq = Counter(nums)
        mx = max(nums)

        smallest = list(range(mx + 1))

        # sieve-like propagation
        for x in sorted(freq):
            for y in range(x * 2, mx + 1, x):
                if y in freq:
                    smallest[y] = min(smallest[y], x)

        ans = 0

        for x, f in freq.items():
            ans += smallest[x] * f

        return ans

s = Solution()
nums = [3,6,2]
nums = [4,2,8,3]
print(s.minArraySum(nums))