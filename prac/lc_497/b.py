from typing import *
from collections import *
from heapq import *
from bisect import *
from itertools import *
from math import *
from functools import *

class Solution:
    def internalAngles(self, sides: list[int]) -> list[float]:
        a, b, c = sides

        if a+b <= c or b+c <= a or c+a <= b:
            return []
        
        A = degrees(acos((b*b + c*c - a*a) / (2*b*c)))
        B = degrees(acos((a*a + c*c - b*b) / (2*a*c)))
        C = degrees(acos((a*a + b*b - c*c) / (2*a*b)))
        
        angles = [A, B, C]
        angles.sort()
        
        return angles
        
s = Solution()
# sides = [3,4,5]
sides = [2,4,2]
print(s.internalAngles(sides))