/*
OJ: https://leetcode.com/problems/count-total-number-of-colored-cells/description/
Time:
Space:
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long coloredCells(int n) {
        return (n * (n-1)*2) + 1;
    }
};

int main() {
    Solution sol;
    vector<int> v = { 1, 2, 3 };
    cout << sol.coloredCells(4) << endl;
    return 0;
}