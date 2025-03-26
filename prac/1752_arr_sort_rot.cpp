/*
OJ: https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/description/
Time:
Space:
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size(), c=0;
        for(int i=0;i<n;i++){
            if(nums[i] > nums[(i+1)%n])
             c++;
        }
        return c<=1;
    }
};

int main() {
    Solution sol;
    vector<int> v = { 3,4,5,1,2 };
    cout << sol.check(v) << endl;
    return 0;
}