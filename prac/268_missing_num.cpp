/*
OJ: https://leetcode.com/problems/missing-number/
Time:
Space:
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    /*
    int missingNumber(vector<int>& nums) {
        int n = nums.size(), missing;
        sort(nums.begin(), nums.end());

        for (int i = 0;i < n;i++) {
            if (nums[i] != i) {
                missing = i;
                break;
            }
            if(nums[i] == n-1){
                missing = nums[i]+1;
                break;
            }
        }
        return missing;
    }*/
    int missingNumber(vector<int>& nums) {
        int n = nums.size(), nsum = n*(n+1)/2;
        for(int x: nums)
            nsum -= x;
        return nsum;
    }
};

int main() {
    Solution sol;
    vector<int> v = {0, 1};
    cout << sol.missingNumber(v) << endl;
    return 0;
}