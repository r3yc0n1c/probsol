from typing import *
from collections import *
from heapq import *
from bisect import *
from itertools import *
from math import *
from functools import *

class Solution:
    def sumOfPrimesInRange(self, n: int) -> int:
        r = int(str(n)[::-1])
        l = min(n, r)
        h = max(n, r)

        sieve = [True] * (h + 1)
        sieve[0] = False
        sieve[1] = False

        p = 2
        while p * p <= h:
            if sieve[p]:
                for m in range(p * p, h + 1, p):
                    sieve[m] = False
            p += 1
        
        ans = 0

        for num in range(l, h + 1):
            if sieve[num]:
                ans += num

        return ans

s = Solution()
n = 13
n = 10
n = 8
print(s.sumOfPrimesInRange(n))