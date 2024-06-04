/*
OJ: https://leetcode.com/problems/insert-interval/description/
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
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size(), i = 0;
        vector<vector<int>> mergedIntervals;

        while(i < n && newInterval[0] > intervals[i][1]){
            mergedIntervals.push_back(intervals[i++]);
        }

        while(i < n && newInterval[1] >= intervals[i][0]){
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }

        mergedIntervals.push_back(newInterval);

        while(i<n){
            mergedIntervals.push_back(intervals[i++]);
        }

        return mergedIntervals;
    }
};

int main() {
    vector<vector<int>> v = {{1, 5}}; //{{1,2},{3,5},{6,7},{8,10},{12,16}};
    vector<int> ni = {1, 7}; //{4,8};
    Solution s;

    for(auto x: s.insert(v, ni)){
        cout << x[0] << " " << x[1]  << endl;
    }
    return 0;
}