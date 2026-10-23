from typing import *
from collections import *
from heapq import *
from bisect import *
from itertools import *
from math import *
from functools import *


class Solution:
    def longestBalanced(self, s: str) -> int:        
        n = len(s)
        t1 = s.count('1')
        t0 = n - t1
        
        pref = [0] * (n + 1)
        for i in range(n):
            pref[i + 1] = pref[i] + (1 if s[i] == '1' else -1)

        def f(k, cap):
            if cap < 0: return 0
            ans, off = 0, n + 2
            pos = [deque() for _ in range(2 * n + 5)]
            pos[pref[0] + off].append(0)
            
            for r in range(1, n + 1):
                t = pref[r] - k
                dq = pos[t + off]
                while dq and dq[0] < r - cap:
                    dq.popleft()
                if dq:
                    ans = max(ans, r - dq[0])
                pos[pref[r] + off].append(r)
            return ans

        max_len = f(0, n)
        max_len = max(max_len, f(2, 2 * t0))
        max_len = max(max_len, f(-2, 2 * t1))
        return max_len


sol = Solution()
s = "100001"
s = "111"
s = "01111100"
s = "100001" # expectted 4
# s = "0010" # expectted 2
# s = "01111100" # 6
print(sol.longestBalanced(s))