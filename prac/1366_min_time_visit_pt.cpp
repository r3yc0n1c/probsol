/*
OJ: https://leetcode.com/problems/minimum-time-visiting-all-points/description/
Time:
Space:
Concept: Chebyshev distance
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n=points.size(), time = 0, x1, y1, x2, y2, k=0;
        x1 = points[0][0], y1 = points[0][1];

        for(int i=1;i<n; i++){
            x2 = points[i][0], y2 = points[i][1];
            time += max(abs(x2-x1), abs(y2-y1));
            x1 = x2; 
            y1 = y2;
        }
        return time;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> v = { {1,1},{3,4},{-1,0} };
    cout << sol.minTimeToVisitAllPoints(v) << endl;
    return 0;
}