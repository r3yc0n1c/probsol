/*
OJ: https://leetcode.com/problems/longest-nice-subarray
Time:
Space:
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size(), largest = 1;

        for (int i = 0; i < n-largest; i++) {
            int k = 1;
            int used = nums[i];
            for (int j = i + 1; j < n; j++) {
                if ((used & nums[j]) == 0) {
                    used |= nums[j];
                    k++;
                }
                else
                    break;
            }
            largest = max(largest, k);
        }

        return largest;
    }
};

int main() {
    Solution sol;
    vector<int> v = { 1,3,8,48,10 };
    cout << sol.hello(v) << endl;
    return 0;
}
