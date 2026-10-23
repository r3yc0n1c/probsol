from typing import List

class Solution:
    def maxSubarrays(self, n: int, conflictingPairs: List[List[int]]) -> int:
        for x in conflictingPairs:
            x.sort()
        
        conflictingPairs.sort()

        i = len(conflictingPairs)-1
        a = b = n + 1
        s = 0
        d = [0]*(n+2)

        for l in range(n, 0, -1):
            while i>= 0 and conflictingPairs[i][0] == l:
                r = conflictingPairs[i][1]
                if r<a:
                    a, b = r, a
                elif r<b:
                    b = r
                i -= 1

            s += a
            d[a] += b-a
        base = n*(n+1)//2
        max_diff = max(d[r]for _, r in conflictingPairs)
        return s-base+max_diff