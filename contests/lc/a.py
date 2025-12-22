from math import prod

class Solution:
    def checkDivisibility(self, n: int) -> bool:
        ds = sum(map(int, list(str(n))))
        dp = prod(map(int, list(str(n))))
        return n % (ds+dp) == 0

print(Solution().checkDivisibility(99))

'''
class Solution {
public:
    bool checkDivisibility(int n) {
        string s = to_string(n);
        int dig_sum = 0;
        int dig_prod = 1;
        for (char c : s) {
            int digit = c - '0';
            dig_sum += digit;
            dig_prod *= digit;
        }
        return n % (dig_sum + dig_prod) == 0;
    }
};
'''