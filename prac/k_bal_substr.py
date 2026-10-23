from typing import *
from collections import *
from heapq import *
from bisect import *
from itertools import *
from math import *
from functools import *

class Solution:
    def removeSubstring(self, s: str, k: int) -> str:
        p = '(' * k + ')' * k
        while True:
            _s = s.replace(p, '')
            if _s == s:
                return s
            s = _s


# class Solution:
#     def removeSubstring(self, s: str, k: int) -> str:
#         stack = []
#         for c in s:
#             stack.append(c)
#             if len(stack) >= 2 * k:
#                 if all(stack[-2*k + i] == '(' for i in range(k)) and all(stack[-k + i] == ')' for i in range(k)):
#                     del stack[-2*k:]
#         return ''.join(stack)