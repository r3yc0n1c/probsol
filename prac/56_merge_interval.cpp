/*
OJ: https://leetcode.com/problems/merge-intervals/description/
Time: O(n)
Space: O(1)
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <set>
#include <unordered_set>
#include <map>
using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        
        vector<vector<int>> mergedIntervals = { intervals[0] };
        vector<int> curr;

        for(int i=1;i < n;i++) {
            curr = mergedIntervals.back();
            if(intervals[i][0] <= curr[1]){
                curr[1] = max(curr[1], intervals[i][1]);
                mergedIntervals.back() = curr;
            }
            else{
                mergedIntervals.push_back(intervals[i]);
            }
        }
        return mergedIntervals;
    }
};

int main() {
    vector<vector<int>> v = {{1,3},{2,6},{8,10},{15,18}};
    Solution s;

    for(auto x: s.merge(v)){
        cout << x[0] << " " << x[1]  << endl;
    }
    return 0;
}