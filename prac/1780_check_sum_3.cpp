/*
OJ: https://leetcode.com/problems/check-if-number-is-a-sum-of-powers-of-three/description/
Time:
Space:
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkPowersOfThree(int n) {
        int i=0;
        while(n) {
            int d = n%3;
            if(d != 0 && d!=1)
                return false;
            n /= 3;
            cout << i++ << " " << n << ",";
        }
        return true;
    }
};

int main() {
    Solution sol;
    cout << sol.checkPowersOfThree(27) << endl;
    return 0;
}