class Solution:
    def countNoZeroPairs(self, n: int) -> int:
        s = str(n)
        m = len(s)
        digs = [int(s[m - 1 - i]) for i in range(m)]

        nzp = 0

        for la in range(1, m + 1):
            for lb in range(1, m + 1):
                dp = [0, 0]
                dp[0] = 1

                for pos in range(m):
                    ndp = [0, 0]
                    target = digs[pos]

                    a_start = 1 if pos < la else 0
                    a_end = 9 if pos < la else 0
                    b_start = 1 if pos < lb else 0
                    b_end = 9 if pos < lb else 0

                    for carry in range(2):
                        ways = dp[carry]
                        if ways == 0:
                            continue
                        for da in range(a_start, a_end + 1):
                            for db in range(b_start, b_end + 1):
                                ssum = da + db + carry
                                if ssum % 10 == target:
                                    ndp[ssum // 10] += ways
                    dp = ndp
                nzp += dp[0]
        return nzp
