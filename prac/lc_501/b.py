from typing import *
from collections import *
from heapq import *
from bisect import *
from itertools import *
from math import *
from functools import *
import re

class Solution:
    def countWordOccurrences(self, chunks: list[str], queries: list[str]) -> list[int]:
        s = "".join(chunks)
        cnt = Counter()

        n = len(s)
        i = 0

        while i < n:
            if not s[i].islower():
                i += 1
                continue

            w = []

            while i < n:
                if s[i].islower():
                    w.append(s[i])

                elif (
                    s[i] == '-'
                    and i > 0 and i + 1 < n
                    and s[i - 1].islower()
                    and s[i + 1].islower()
                ):
                    w.append('-')

                else:
                    break

                i += 1

            cnt["".join(w)] += 1

        return [cnt[q] for q in queries]

s = Solution()
chunks = ["a--b a-","-c"]
queries = ["a","b","c"]
chunks = ["hello"]
queries = ["hello","ell"]
chunks = ["m  cq-i "]
queries = ["m","cq-i","nm"]
print(s.countWordOccurrences(chunks, queries))