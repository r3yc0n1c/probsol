/*
OJ: https://leetcode.com/problems/non-overlapping-intervals/description/
Time: 
Space: 
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b){
        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int n = intervals.size(), c = 1, end = intervals[0][1];

        for(int i=0;i<n;i++){
            if(intervals[i][0] >= end){
                c++;
                end = intervals[i][1];
            }
        }
        return n-c;
    }
};

int main() {
    vector<vector<int>> v = {{1,2},{2,3},{3,4},{1,3}};
    Solution s;
    cout << s.eraseOverlapIntervals(v)  << endl;
    return 0;
}