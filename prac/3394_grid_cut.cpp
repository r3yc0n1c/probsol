/*
OJ: https://leetcode.com/problems/check-if-grid-can-be-cut-into-sections/description
Time:
Space:
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkValidCuts(int n, vector<vector<int>>& rectangles) {
        vector<pair<int, int>> x, y;
        
        for (int i = 0; i < rectangles.size(); i++) {
            x.push_back({ rectangles[i][0], rectangles[i][2] });
            y.push_back({ rectangles[i][1], rectangles[i][3] });
        }
        
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());

        int c1 = 0, c2 = 0, val = x[0].second, val1 = y[0].second;
        
        for (int i = 1;i < x.size();i++) {
            if (x[i].first == val)c1++;
            val = max(x[i].second, val);
        }
        
        for (int i = 1;i < x.size();i++) {
            if (y[i].first == val1)c2++;
            val1 = max(y[i].second, val1);
        }
        
        if (c1 >= 2 || c2 >= 2) return true;
        
        return false;
    }
};

int main() {
    Solution sol;
    vector<int> v = { 1, 2, 3 };
    cout << sol.hello(v) << endl;
    return 0;
}