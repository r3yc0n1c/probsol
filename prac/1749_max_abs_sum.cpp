/*
OJ: https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray/description/
Time:
Space:
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n = nums.size(), maxSum, maxEnd, minEnd;
        maxSum = maxEnd = minEnd = 0;

        for(int i=0;i<n;i++){
            maxEnd = max(maxEnd + nums[i], nums[i]);
            minEnd = min(minEnd + nums[i], nums[i]);
            // maxSum = max(maxSum, maxEnd);
        }
        cout << maxEnd << " " << minEnd << endl;
        return abs(maxEnd - minEnd);
    }
};

int main() {
    Solution sol;
    vector<int> v = { 1,-3,2,3,-4 };
    cout << sol.maxAbsoluteSum(v) << endl;
    return 0;
}