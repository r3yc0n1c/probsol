from collections import Counter
from math import comb
from typing import *

class Solution:
    def countTrapezoids(self, points: List[List[int]]) -> int:
        MOD = 10**9+7
        yc = Counter()
        for x, y in points:
            yc[y] += 1

        valid_y = []
        c2s = []
        for y, count in yc.items():
            if count >= 2:
                valid_y.append(y)
                c2s.append(comb(count, 2))

        tht = 0
        prefix_sum = 0
        for c2 in c2s:
            tht = (tht + prefix_sum * c2) % MOD
            prefix_sum = (prefix_sum + c2) % MOD

        return tht
